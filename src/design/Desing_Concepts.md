module Dragon;
plugin "C++" as cpp
plugin "Python" as python
plugin "Java" as java
plugin "C#" as csharp
// 
import Alien, Human;

python.

// object is reference type
public interface IItellect 
{
	public Think() -> Minds[] // public is not nessasery
	{
		String = '''Hello Denis''';
		String = ''Hello Denis'';
		String = """Hello Denis""";
		String = ""Hello Denis"";
		char = 'H'; // UTF-8
	}
	
	public request Think() -> Minds[] // public request
	{
		String = '''Hello Denis''';
		String = ''Hello Denis'';
		String = """Hello Denis""";
		String = ""Hello Denis"";
		char = 'H'; // UTF-8
	}
	
	public response Think() -> Minds[] // public is not nessasery
	{
		String = '''Hello Denis''';
		String = ''Hello Denis'';
		String = """Hello Denis""";
		String = ""Hello Denis"";
		char = 'H'; // UTF-8
	}
	
	action Think() -> Minds[] // public is implicit
	{
		String = '''Hello Denis''';
		String = ''Hello Denis'';
		String = """Hello Denis""";
		String = ""Hello Denis"";
		char = 'H'; // UTF-8, char has variable 
	}
}

callback 

// object is reference type
public class Man inherits Human, Alien implement IItellect {
	public Man() {  }

	int seconds;

	public property Hours -> int
	{
		get { 
			return seconds / 3600; 
			}
		set { 
			seconds = (int)value * 3600; 
			}
	}
	
	public action Run (String[] str) -> Kwo
	{
		Human::run();
		
		var lambda = (String[] str) -> Kwo { // lambda
		
		};
		
		public fun Helper (String[] str) -> Kwo // Sintax OK. It is a local function
		{
			public action Helper2 (String[] str) -> Kwo // Sintax ERROR.
			{
				
			}
		
			public fun Helper2 (String[] str) -> Kwo // Sintax ERROR. Second level.
			{
				
			}
		}
		
		public action Helper (String[] str) -> Kwo // Sintax ERROR. It is not method of the class or struct
		{
			
		}
	}
	
	static
	public action CreateOne (int[] str) -> Kwo
	{
		
	}

	public operator +(Man i, Man k) -> Man  // Sintax OK, wihtou keyword static because meaningless (cannot be non static)
	{

	}
	
	static
	public action Add(Man i, Man k) -> Man  // Sintax OK, the same like public operator +(One i, One k) -> One
	{

	}

	operator +(Man i, int k) -> Man  // Sintax OK
	{

	}
	
	operator +(int k, Man i) -> Man  // Sintax OK
	{

	}
	
	operator +(Man i, Alien k) // Sintax ERROR, should be external function
	{

	}
	
	~Man() {  }
}

operator +(int k, Man i)  // Sintax ERROR, should be internal class function
{

}

operator +(Man i, Man k) // Sintax ERROR, should be internal class function
{
	
}

operator +(Man i, Alien k) // Sintax OK
{
	
}

// struct is value type, stack type
struct Point {
	int i, k;

	public Point() {  }
	
	public action Set(int i, int k) -> int // (Eplicity)
	{
		try {
			int s = *p;
		}
		catch(UnproperPointer e)
		{
		
		}
		return int(1);
	}
	
	public action Set(int i, int k) // Automaticly will be transformed to action Set(int i, int k) -> int (Implicity)
	{
		try {
			int s = *p;
		}
		catch(UnproperPointer e)
		{
		
		}
		return int(1);
	}
	
	public action CalculateDistance(Point k) return int 
	{
		return 1;
	}
	
	private action fgdd(int k, int i) -> int 
	{

	}
	// this is static method
	public operator +(Two t0, Two t1) -> int 
	{
		checked {
			int a = b + c / 2;
		}
		
		unchecked {
			int a = b + c / 2;
		}
	}
	~Point() {  }
}

public fun binarySearch () -> One 
{
	try {
		
	}
	catch()
	{
		
	}
	// explicitly or implicitly
	finally {
		
	}

	return new One();
}

public fun main (String[] str) -> Kwo throw // Free function. Code should be started from here
// Should be like throw if in function
/*
 Inside of the fun compiler will add stack_traces_of_name_function
 stack_functions.push_back("Dragon.main(String[] str)")
*/ 
{
	var k = Kwo();
	// the same as Kwo k = Kwo();
	let k = Kwo();
	// the same as Kwo const k = Kwo();
	
	var t = new Two();
	// the same as Two k = new Two();
	let t = new Two();
	// the same as Two const k = new Two();
	
	using(var file = new File.Open(""))
	{
		// Using resources
	}
	
	try {
		// if main (String[] str) is throw and current fun can throw then stack_functions.front().setLine()
		bla_bla(); 
		// then stack_functions.front().removeLine()
	}
	catch(Exception e)
	{
		
	}
	catch(...) // Means catch(Exception e) {  }.
	{
		e.stack_trace();
	}
	// explicitly or implicitly
	finally {
		
	}

	return new One();
/*
 On the end of function
 stack_functions.pop_back("Dragon.main(String[] str)")
*/ 
}

// Syntax sugar
do
{
	
}
while(m is Man);

// Syntax sugar
do
{
	
}
while(word is in words); // words should provide action findById, another ERROR

// Syntax sugar
while(word is int)
{

}

// Syntax sugar
while(word is Man)
{

}

// Syntax sugar
while(word is in words) // words should provide action findById, another ERROR
{

}

// Syntax sugar
while(word0, word1 are in words) // words should provide action findById, another ERROR
{

}

// Syntax sugar
while(i < 10)
{

}

// Syntax sugar
for(int word of words)
{

}

// Syntax sugar
for(var word of words)
{

}

for(int word : words)
{

}

for(int i = 0; i < 10; ++i)
{

}

// Syntax sugar
for(int i = 0 until i < 10 after step ++i)
{

}
