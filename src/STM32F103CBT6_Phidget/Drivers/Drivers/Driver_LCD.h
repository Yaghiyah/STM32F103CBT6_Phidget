#ifndef __LCD_H__
#define __LCD_H__


// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// flags for backlight control
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00


/**
 * SPI Flash Memory Driver for Micron M25P16 Serial Flash Embedded Memory
 */
class LCD
{
	
	public:
		
	    /**
      * Constructor
      *
      * Creates a new instance of this driver.  Before using, you create an instance
      * and send in the unique pins that this chip is connected to.
      *
      * @param _cspin The pin attached to Chip Select
      */
      LCD();  

		 /**
      * De-Constructor
      *
      * Creates a new instance of this driver.  Before using, you create an instance
      * and send in the unique pins that this chip is connected to.
      *
      * @param _cspin The pin attached to Chip Select
      */
      ~LCD();

		 /**
      * De-Constructor
      *
      * Creates a new instance of this driver.  Before using, you create an instance
      * and send in the unique pins that this chip is connected to.
      *
      * @param _cspin The pin attached to Chip Select
      */
      void LCD_Clear(void);  
};

#endif // __LCD_H__
