#include "Pony.hpp"

void	ponyOnTheStack(void)
{
	Pony stack_pony;
	
	std::cout << "Pony created in Stack and do some stuff" << std::endl;
}

void	ponyOnTheHeap(void)
{
	Pony *heap_pony = new Pony;
	
	std::cout << "Pony created in Heap and do some stuff" << std::endl;
	delete (heap_pony);
}

int		main(void)
{
	Pony stack_pony;
	Pony *heap_pony = new Pony;

	std::cout << "Pony created in Stack and do some stuff" << std::endl;
	std::cout << "Pony created in Heap and do some stuff" << std::endl;
	ponyOnTheStack();
	ponyOnTheHeap();
	delete (heap_pony);
	return (0);
}
