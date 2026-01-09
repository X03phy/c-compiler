void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	main(void)
{
	int	num1;
	int	num2;

	num1 = 10;
	num2 = 5;
	
	ft_swap(&num1, &num2);
	printf("a = b : %d \n", num1);
	printf("b = a : %d", num2);
	return (0);
}