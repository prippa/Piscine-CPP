#include <iostream>

struct	Data
{
	std::string s1;
	std::string s2;
	int n;
};

struct	SerializedData
{
	char s1[9];
	char s2[9];
	int n;
};

void	*serialize(void)
{
	SerializedData *randomData = new SerializedData;

	for (int i = 0; i < 8; ++i)
	{
		randomData->s1[i] = 32 + (rand() % 94);
		randomData->s2[i] = 32 + (rand() % 94);
	}

	randomData->s1[8] = 0;
	randomData->s2[8] = 0;
	randomData->n = rand() * ((rand() % 2) ? 1 : -1);
	return (reinterpret_cast<void *>(randomData));
}

Data	*deserialize(void *raw)
{
	SerializedData *serData;

	Data *data = new Data;
	serData = reinterpret_cast<SerializedData *>(raw);
	data->s1 = static_cast<std::string>(serData->s1);
	data->n = serData->n;
	data->s2 = static_cast<std::string>(serData->s2);

	return (data);
}

int		main(void)
{
	srand(time(0));

	void *data_p = serialize();
	Data *data = deserialize(data_p);
	
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;
	
	delete data;
	delete reinterpret_cast<SerializedData *>(data_p);

	return (0);
}
