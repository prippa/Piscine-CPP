#include "libft.hpp"

std::string	getOutputStr(std::string str) {
	if (str.size() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void		ft_getline(std::string & str) {
	if (!(std::getline(std::cin, str)))
		exit(-1);
}
