#define INPUT_BUTTON_LEFT   5
#define INPUT_BUTTON_RIGHT  4

class IOElements
{
  public:

	IOElements()
	{
		pinMode(INPUT_BUTTON_LEFT, INPUT);
		pinMode(INPUT_BUTTON_RIGHT, INPUT);
	}

	static bool getButtonLeft()
	{
		return digitalRead(INPUT_BUTTON_LEFT) == HIGH;
	}

	static bool getButtonRight()
	{
		return digitalRead(INPUT_BUTTON_RIGHT) == HIGH;
	}

};