getGnlFiles="true"
makeTests="true"
gnlPath="../get_next_line"
gnlPathIsCustom="false"

function print_help
{
read -r -d '' HELP_TEXT << EOM
DESCRIPTION:
Recupere, modifie et cree les fichiers necessaires a la compilation de test-gnl.

LISTE DES COMMANDES:
<chemin_vers_gnl>         Specifie le chemin vers gnl (le dossier contenant
                          get_next_line.c / get_next_line.h / libft).
                          Ne peut etre specifie qu'une seule fois, autrement une erreur se produit.
--nogetgnl                Ne recupere pas les fichiers du dossier gnl.
--nomake                  N'execute pas make a la fin du script.
-h / --help               Affiche cette page d'aide.
EOM

echo "$HELP_TEXT"
}

function add_extern_c_varh
{
cat "$varh" | sed "/define .*_H/ a\\
\\
extern \"C\" {\\
" > ${varh}.tmp
rm $varh
mv ${varh}.tmp $varh
cat "$varh" | sed "/#endif/ i\\
}\\
\\
" > ${varh}.tmp
rm $varh
mv ${varh}.tmp $varh
}

function del_cpp_keyword_varh
{
	sed -i "" "s/ new,/ newPtr,/g" $varh
	sed -i "" "s/*new,/*newPtr,/g" $varh
	sed -i "" "s/ new)/ newPtr)/g" $varh
	sed -i "" "s/*new)/*newPtr)/g" $varh
	sed -i "" "s/ delete,/ deleteVar,/g" $varh
	sed -i "" "s/*delete,/*deleteVar,/g" $varh
	sed -i "" "s/ delete)/ deleteVar)/g" $varh
	sed -i "" "s/*delete)/*deleteVar)/g" $varh
	sed -i "" "s/false/False/g" $varh
	sed -i "" "s/true/True/g" $varh
}

function add_one_gnl_buf_size
{
cat gnl/get_next_line.h | sed "/get_next_line_1(/ a\\
int				get_next_line_$num(const int fd, char **line);
" > gnl/get_next_line.h.tmp
rm gnl/get_next_line.h
mv gnl/get_next_line.h.tmp gnl/get_next_line.h
}

function add_all_gnl_buf_size
{
	sed -i "" "s/get_next_line(/get_next_line_1(/g" gnl/get_next_line.h
	sed -i "" "s/get_next_line_[0-9]*(/get_next_line_1(/g" gnl/get_next_line.h
	num="2"
	add_one_gnl_buf_size
	num="10"
	add_one_gnl_buf_size
	num="32"
	add_one_gnl_buf_size
	num="100"
	add_one_gnl_buf_size
	num="9999"
	add_one_gnl_buf_size
	num="10000000"
	add_one_gnl_buf_size
}

for param in "$@"; do
	if [[ "$param" =~ ^--.* ]]; then
		if [[ "$param" == "--nogetgnl" ]]; then
			getGnlFiles="false"
		elif [[ "$param" == "--nomake" ]]; then
			makeTests="false"
		elif [[ "$param" == "--help" ]]; then
			print_help
			exit 0
		else
			echo "Erreur: parametre $param inconnu. Utilisez --help pour afficher l'aide."
			exit 0
		fi
	elif [[ "$param" =~ ^-.* ]]; then
		if [[ "$param" == "-h" ]]; then
			print_help
			exit 0
		else
			echo "Erreur: parametre $param inconnu. Utilisez --help pour afficher l'aide."
			exit 0
		fi
	fi
done

for param in "$@"; do
	if [[ ! "$param" =~ ^-.* ]]; then
		if [[ "$gnlPathIsCustom" == "false" ]]; then
			gnlPath="$param"
			gnlPathIsCustom="true"
		else
			echo "Trop d'arguments, le chemin de gnl ne peut etre initialise qu'une fois. Utilisez --help pour afficher l'aide."
			exit 0
		fi
	fi
done

if [[ "$getGnlFiles" == "true" ]]; then
	rm -rf "gnl"
	mkdir "gnl"
	cp "${gnlPath}/get_next_line.c" "${gnlPath}/get_next_line.h" "gnl/"
	cp -R "${gnlPath}/libft" "gnl/"
	make -C gnl/libft
	mkdir "gnl/libft/includes"
	mv "gnl/libft/libft.h" "gnl/libft/includes/"
	sed -i "" "s/libft\/libft\.h/libft.h/g" "gnl/get_next_line.c"
	sed -i "" "s/libft\/libft\.h/libft.h/g" "gnl/get_next_line.h"
	cp change_gnl_buf_size.sh gnl/change_gnl_buf_size.sh
	cp gnl_make_all.sh gnl/gnl_make_all.sh
	cp gnl.makefile gnl/Makefile
	(cd gnl; ./gnl_make_all.sh)
	varh="gnl/libft/includes/libft.h"
	add_extern_c_varh
	del_cpp_keyword_varh
	varh="gnl/get_next_line.h"
	add_extern_c_varh
	del_cpp_keyword_varh
	add_all_gnl_buf_size
fi
if [[ "$makeTests" == "true" ]]; then
	make -j4
fi
