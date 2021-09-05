public Run(String[] str) // Implicitly
{
	Socket time = new Socket()	// Explicitly
	time  = new Time(); 					// Implicitly, if this variable did not exist, then simular like in Python and C# (dinamic)
	time := new Time()						// Create WeakPtr for programm which can be start without GarbageCollector
	time  = (String[] str) -> { 		// Could be overwrite on lambda, 'cause it is like in Python
		time := time0;
	};
	
	var work = new Work()			// Implicitly
	work = new Time()				// Another will be Compilation error or Runtime error
}
