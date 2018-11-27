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
	rm -r "gnl"
	mkdir "gnl"
	cp "${gnlPath}/get_next_line.c" "${gnlPath}/get_next_line.h" "gnl/"
	cp -R "${gnlPath}/libft" "gnl/"
	make -C gnl/libft
	cp gnl.makefile gnl/Makefile
	make -C gnl
	varh="gnl/libft/includes/libft.h"
	add_extern_c_varh
	del_cpp_keyword_varh
	varh="gnl/get_next_line.h"
	add_extern_c_varh
	del_cpp_keyword_varh
fi
if [[ "$makeTests" == "true" ]]; then
	make -j4
fi
