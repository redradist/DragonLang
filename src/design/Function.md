external fun Run (str: String[]) -> Kwo // Explicitly
{
	// ...
	return new Kwo();
}

internal fun Run (str: String[]) // Implicitly
{
	// ...
	return Kwo{};
}

fun Run (str: String[]) // Implicitly external
{
	// ...
	return Kwo{};
}

fun Run (str: String[?]) -> (int, String) // Explicitly
{
	// ...
	return 1, "Some string";
}

fun Run (str: String[]) -> (int, String) {
	// ...
	return 1, "Some string";
}

fun Run (str: String[]) -> (int, String) {
	// ...
	Run
	return 1, "Some string";
}

fun Run (fun: () -> ?) -> (int, String) {
	// ...
	fun();
	return 1, "Some string";
}