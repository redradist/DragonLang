// object is reference type
public class Man inherits Human, Alien implements IItellect {
	public Man() {  }
	
    public get Name: String {

    }

	public fun Human::Run (String[] str) -> Kwo // Explicitly
	{
		// ...
		return new Kwo();
	}
	
	public fun Run (String[] str) -> auto // Implicitly
	{
		// ...
		return new Kwo();
	}
	
	~Man() {  }
}
