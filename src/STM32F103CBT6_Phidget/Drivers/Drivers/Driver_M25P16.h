#ifndef __M25P16_H__
#define __M25P16_H__

/*

	Support for M25P16 2-Mbyte flash RAM. 

	M25P16 Memory Organization

	The memory is organized as: 

	* 16Mbit = 2,097,152 bytes (8 bits each) 
	* 32 sectors (512 Kbits, 65536 bytes each) 
	* 8192 pages (256 bytes each)

	Each page can be individually programmed (bits are programmed from 1 to 0). The device is 
	sector or bulk erasable (bits are erased from 0 to 1) but not page erasable

*/


/**
 * SPI Flash Memory Driver for Micron M25P16 Serial Flash Embedded Memory
 */

class M25P16
{
    private:        
        char _csPin;
        int spi_speed;
        void ChipSelect(bool mode);
        void SendSingleCommand(char cmd);
    public:

      /**
      * Constructor
      *
      * Creates a new instance of this driver.  Before using, you create an instance
      * and send in the unique pins that this chip is connected to.
      *
      * @param _cspin The pin attached to Chip Select
      */
      M25P16();  

		 /**
      * De-Constructor
      *
      * Creates a new instance of this driver.  Before using, you create an instance
      * and send in the unique pins that this chip is connected to.
      *
      * @param _cspin The pin attached to Chip Select
      */
      ~M25P16();  


      /**
      * ReadPage
      *
      * Creates a new instance of this driver.  Before using, you create an instance
      * and send in the unique pins that this chip is connected to.
      *
      * @param ucBuffer 
      * @param ulReadAddr 
      * @param ulNumByteToRead 
      */
      void ReadPage(unsigned char* ucBuffer, 
                        unsigned long ulReadAddr,
                        unsigned long ulNumByteToRead);
         
      /**
      * WritePage
      *
      * Creates a new instance of this driver.  Before using, you create an instance
      * and send in the unique pins that this chip is connected to.
      *
      * @param ulAddr 
      * @param usValue
      */
      void WritePage(unsigned long address, 
                     unsigned char *data,
                     unsigned short usNumByteToWrite); 
  
      /**
      * ReadID
      *
      * Creates a new instance of this driver.  Before using, you create an instance
      * and send in the unique pins that this chip is connected to.
      *
      * @param ulAddr 
      * @param usValue
      */
      long ReadID();


      /**
      * EraseSector
      
        The Sector Erase (SE) instruction sets to ‘1’ (FFh) all bits inside the chosen sector. Before it 
        can be accepted, a Write Enable (WREN) instruction must previously have been executed. 
        After the Write Enable (WREN) instruction has been decoded, the device sets the Write 
        Enable Latch (WEL).
         
       @param address 
      */
      void EraseSector(unsigned long address);

                         
};   

#endif // __M25P16_H__
	
