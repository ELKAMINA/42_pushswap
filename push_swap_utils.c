size_t	ft_intlen(int *tab)
{
	size_t size_arr;
    size_t len_ar;

    size_arr = sizeof(tab);
    len_arr = size_arr / sizeof(int);
    return (len_arr);
}