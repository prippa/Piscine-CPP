#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "Form.hpp"
# include <fstream>
# define RETRO_TREE "###########################'`################################\n\
###########################  V##'############################\n\
#########################V'  `V  ############################\n\
########################V'      ,############################\n\
#########`#############V      ,A###########################V\n\
########' `###########V      ,###########################V',#\n\
######V'   ###########l      ,####################V~~~~'',###\n\
#####V'    ###########l      ##P' ###########V~~'   ,A#######\n\
#####l      d#########l      V'  ,#######V~'       A#########\n\
#####l      ##########l         ,####V''         ,###########\n\
#####l        `V######l        ,###V'   .....;A##############\n\
#####A,         `######A,     ,##V' ,A#######################\n\
#######A,        `######A,    #V'  A########'''''##########''\n\
##########,,,       `####A,           `#''           '''  ,,,\n\
#############A,                               ,,,     ,######\n\
######################oooo,                 ;####, ,#########\n\
##################P'                   A,   ;#####V##########\n\
#####P'    ''''       ,###             `#,     `V############\n\
##P'                ,d###;              ##,       `V#########\n\
##########A,,   #########A              )##,    ##A,..,ooA###\n\
#############A, Y#########A,            )####, ,#############\n\
###############A ############A,        ,###### ##############\n\
###############################       ,#######V##############\n\
###############################      ,#######################\n\
##############################P    ,d########################\n\
##############################'    d#########################\n\
##############################     ##########################\n\
##############################     ##########################\n\
#############################P     ##########################\n\
#############################'     ##########################\n\
############################P      ##########################\n\
###########################P'     ;##########################\n\
###########################'     ,###########################\n\
##########################       ############################\n\
#########################       ,############################\n\
########################        d###########P'    `Y#########\n\
#######################        ,############        #########\n\
######################        ,#############        #########\n\
#####################        ,##############b.    ,d#########\n\
####################        ,################################\n\
###################         #################################\n\
##################          #######################P'  `V##P'\n\
#######P'     `V#           ###################P'\n\
#####P'                    ,#################P'\n\
###P'                      d##############P''\n\
##P'                       V##############'\n\
#P'                         `V###########'\n\
#'                             `V##P'\n"

class ShrubberyCreationForm : public Form
{
public:
	class CantOpenFile : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	void	execute(Bureaucrat const & obj) const;

	ShrubberyCreationForm	&operator = (ShrubberyCreationForm const & obj);
	ShrubberyCreationForm(ShrubberyCreationForm const & obj);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(void);
	~ShrubberyCreationForm(void);
};

#endif
