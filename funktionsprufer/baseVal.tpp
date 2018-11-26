template <class T>
baseVal<T>::baseVal(T newVal, std::string newName) : absVal<T>(newVal, newName)
{
	//rien
}

template <class T>
std::string baseVal<T>::valToString()
{
	return std::to_string(this->getVal());
}
