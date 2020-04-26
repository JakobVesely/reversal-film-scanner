#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class LCD
{
  private:
    Adafruit_SSD1306 display;

  public:
    void init ()
    {
      this->display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
      this->display.clearDisplay();
      this->display.setTextColor(WHITE);
      this->display.setRotation(0);
      this->display.setTextWrap(true);
      this->display.dim(0);
    }

    void displayHeader (String str)
    {
      this->display.setTextSize(0);
      this->display.setCursor(0, 0);
      this->display.println(str);
      this->display.display();
    }

    void displayMessage (String str)
    {
      this->displayClear();
      this->display.setTextSize(2);
      this->display.setCursor(0, 15);
      this->display.print(str);
      this->display.display();
    }

    void displayClear ()
    {
      this->display.clearDisplay();
      this->displayHeader("Dia Scanner");
    }
};