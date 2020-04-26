class Camera
{
  private:
    int captureImpuls = 100;
    int focusImpuls = 3000;

    byte focusPort;
    byte capturePort;


  public:

    void init (int focus, int capture)
    {
      this->focusPort = focus;
      this->capturePort = capture;

      pinMode(this->focusPort, OUTPUT);
      pinMode(this->capturePort, OUTPUT);
    }

    void focus ()
    {
      Logger::debug("Camera - Focus");
      digitalWrite(this->focusPort, LOW);
      delay(this->focusImpuls);
    }

    void capture ()
    {
      digitalWrite(this->capturePort, LOW);
      delay(this->captureImpuls);
      Logger::debug("Camera - Capture");
      digitalWrite(this->capturePort, HIGH);
    }
};