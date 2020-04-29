class PCom
{
	private:
		static const byte ModeParameter = 0b00;
		static const byte ModeSetReset 	= 0b01;
		static const byte ModeDirect 	= 0b10;
		static const byte ModeStatus 	= 0b11;

		int portRX = 2;
		int portTX = 3;

		byte projectorAddress = 0x1F;

		void sendCommandBytes(byte mode, byte action)
		{
			byte b1 = (this->projectorAddress * 8) + (mode * 2) + 1;
			byte b2 = action;
			byte b3 = 0;
			byte commandBytes[3] = { b1, b2, b3 };

			Logger::debug("Sending P-Com-Command Byte-Array: " + String(b1, BIN) + " " + String(b2, BIN) + " " + String(b3, BIN));

			Serial.write(commandBytes, 3);
		}


	public:

		void turnOn()
		{
			Logger::debug("Projector - Turn On (Out of Standby)");
			this->sendCommandBytes(ModeSetReset, 0x1C);
      		delay(3000);
		}

		void turnOff()
		{
			Logger::debug("Projector - Turn Off (Go in Standby)");
			this->sendCommandBytes(ModeSetReset, 0x1E);
      		delay(2000);
		}

		void resetSystem()
		{
			Logger::debug("Projector - Reset System");
			this->sendCommandBytes(ModeDirect, 0x2C);
      		delay(5000);
		}

		void slideForward()
		{
			Logger::debug("Projector - next Slide");
			this->sendCommandBytes(ModeDirect, 0x00);
		}

		void slideBackward()
		{
			Logger::debug("Projector - previous Slide");
			this->sendCommandBytes(ModeDirect, 0x04);
		}

		void getTrayPosition()
		{
			Logger::debug("Projector - Get Tray Position");
			this->sendCommandBytes(ModeStatus, 0xA0);
		}

		void getKeys()
		{
			Logger::debug("Projector - Get Keys");
			this->sendCommandBytes(ModeStatus, 0xB0);
		}

		void getSystemStatus()
		{
			Logger::debug("Projector - Get System Status");
			this->sendCommandBytes(ModeStatus, 0xC0);
		} 
};