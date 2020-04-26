class Logger
{

	public:
		static const Enviroment env = DEVELOPMENT;
		static void debug(String str)
		{
			if (env == DEVELOPMENT)
				Serial.println("[Debug] " + str);
		}
};