
#include "pushswap.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	long long depth = ft_atoi(argv[1]);
	char **set;
	set = ft_generate_moves(depth);
}
