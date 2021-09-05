fun Run[T](str: T[]) -> T... // Explicitly
{
	// ...
	return Kwo{};
}

fun Run[T, i: int](str: T[]) -> Iterator<T> // Explicitly
{
	// ...
	return Kwo{};
}

fun Run[T](str: T[]) -> Future<T>... // Explicitly
{
	// ...
	return Kwo{};
}

fun Run[T](str: T[]) -> Iterator<Future<T>> // Explicitly
{
	// ...
	return Kwo{};
}

fun Run[T](str: T[]) -> T^... // Explicitly
{
	// ...
	return Kwo{};
}

suspend fun Run[T](T[] str, type) -> Iterator[Future[T]] // Explicitly
{
	// ...
	T^ t = await GetMoney();
	var t = await GetMoney();
	return Kwo{};
}

public fun Run (T[] str, type) -> Future[T]... // Explicitly
{
	// ...
	return Kwo{};
}