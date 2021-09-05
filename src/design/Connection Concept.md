
connection Mind2 {
	public async Think() -> future<int>; // Remote action, thread or maybe another computer // server side 
	request Me(int i); // return parameter is not passible // server side 
	request Think(): // return parameter is not passible // server side 
	response Think2(); // return parameter is not passible // client side 
}

// object is reference type 
public class Human implement client Mind
{
	Human()
	{
		
	}
	
	public Think() -> Minds[]
	{
		try {
			char ch = 'r', Think(ch);
			r = Think();
			await r;
			
			await Think();
			
			future<int> r = Think();
			await r;
			
			var r = Think();
			await r;
		}
		catch(AsyncActionFailed fail)
		{
			
		}
		catch(RequestFailed fail)
		{
			
		}
	}
	
	@response
	public Think(Minds mind) // public is not nessasery
	{
		String = '''Hello Denis''';
		String = ''Hello Denis'';
		String = """Hello Denis""";
		String = ""Hello Denis"";
		char = 'H'; // UTF-8
	}
	
	Think() -> Minds[] // public is implicit
	{
		String = '''Hello Denis''';
		String = ''Hello Denis'';
		String = """Hello Denis""";
		String = ""Hello Denis"";
		char = 'H'; // UTF-8, char has variable 
	}
}
