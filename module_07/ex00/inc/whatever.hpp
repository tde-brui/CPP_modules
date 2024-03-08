template <typename T>

void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
template <typename U>
U max(U a, U b)
{
	return (a > b) ? a : b;
}

template <typename V>
V min(V a, V b)
{
	return (a < b) ? a : b;
}