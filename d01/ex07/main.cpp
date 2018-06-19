#include <iostream>
#include <fstream>

bool	replaceFirstOccurrence(std::string & s,
	const std::string & toReplace,
	const std::string & replaceWith)
{
    std::size_t pos = s.find(toReplace);
    if (pos == std::string::npos)
		return (false);
    s.replace(pos, toReplace.length(), replaceWith);
	return (true);
}

void	doSomeMagic(std::string const & path,
	std::string const & s1,
	std::string const & s2)
{
	std::string buf;
	std::ofstream ofs;
	std::ifstream ifs;
	char c;

	ifs.open(path);
	if (!ifs.is_open())
	{
		std::cout << "Error with ifs.open file part!" << std::endl;
		exit(-1);
	}
	while (ifs.get(c))
		buf += c;
	ifs.close();

	ofs.open(path);
	if (!ofs.is_open())
	{
		std::cout << "Error with ofs.open file!" << std::endl;
		exit(-1);
	}
	while (replaceFirstOccurrence(buf, s1, s2))
		;
	ofs << buf;
	ofs.close();
}

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Not valid argumants!" << std::endl;
		return (-1);
	}
	std::string path(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	doSomeMagic(path, s1, s2);
	return (0);
}
