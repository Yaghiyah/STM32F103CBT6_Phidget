#include <stdio.h>
#include "global.h"
#include "Driver_M25P16.h"


/* flash commands */
#define SPI_WREN            (0x06)  //Set Write Enable Latch
#define SPI_WRDI            (0x04)  //Reset Write Enable Latch
#define SPI_RDID            (0x9F)  //Read Identification
#define SPI_RDSR            (0x05)  //Read Status Register
#define SPI_WRSR            (0x01)  //Write Status Register
#define SPI_READ            (0x03)  //Read data from memory
#define SPI_FAST_READ       (0x0B)  //Read data from memory
#define SPI_PP              (0x02)  //Program Data into memory
#define SPI_SE              (0xD8)  //Erase one sector in memory
#define SPI_BE              (0xC7)  //Erase all memory
#define WIP                  (0x1)	//Check the write in progress bit of the SPI status register
#define WEL                  (0x2)	//Check the write enable bit of the SPI status register

#define PAGE_LENGTH        64     
#define PAGE_SECTOR_SIZE   65536UL   
#define TIMEOUT 5000


void delayMicroseconds(long delay);
void transfer(char b);


M25P16::~M25P16() {}
M25P16::M25P16() {}


void M25P16::ChipSelect(bool mode)
{  
	if(mode == LOW)
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	else if(mode == HIGH) 
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

void M25P16::SendSingleCommand(char cmd)
{	
	ChipSelect(LOW);

  
		
		/* send the data */
		HAL_StatusTypeDef status	= HAL_SPI_Transmit(
																&hspi1, 
															  (uint8_t*)SPI_READ,  
																1, 
																5000);		
	

														
	 /* block and Wait until a SPI send completes */
	 while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY)
	 {
	 
	 }
	

	ChipSelect(HIGH);	  
}


long M25P16::ReadID()
{
    /*uint32_t val;
		uint8_t output[21]= { 0x00 };
		uint8_t input[] = { 0x9F, 0x00, 0x00, 0x00, 0x00, 
															0x00, 0x00, 0x00, 0x00,
															0x00, 0x00, 0x00, 0x00,
															0x00, 0x00, 0x00, 0x00,
														  0x00, 0x00, 0x00, 0x00};
	

      The Read Identification (RDID) instruction allows to read the device identification data:
      
      ● Manufacturer identification (1-Byte)
      ● Device identification (2-Bytes)
      ● WE DONT USE THIS!! A Unique ID code (UID) (17-Bytes, of which 16 available upon customer request) 
    

	 //ChipSelect(HIGH);
		   // SendSingleCommand(SPI_READ);		
    // 1) The SPI_RDID instruction is entered by driving Chip Select (S) Low.
   ChipSelect(LOW);
   //delayMicroseconds(1);       
       
   // Get Manufacture ID (1-Byte)
   //val |= (uint32_t)transfer(SPI_RDID) << 16; 
	 
		
		
	HAL_StatusTypeDef status = HAL_SPI_Transmit(
																&hspi1, 
															  (uint8_t*)input,  
																21, 
																5000);		

		
	/*HAL_StatusTypeDef status = HAL_SPI_TransmitReceive(
																										&hspi1,
																										(uint8_t *)input,
																									  (uint8_t *)output,
																										21,
																										TIMEOUT);
													

														
							
		 while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY)
	 {
	 
	 }
	 

   // We done, disable Chip Select.
   ChipSelect(HIGH);

   return val;  
*/

return 0;
}


void M25P16::EraseSector(unsigned long address)
{         
   unsigned char ucAddrBuffer[3];
   
 
   SendSingleCommand(SPI_WREN);

    // 1) The SPI_RDID instruction is entered by driving Chip Select (S) Low.
   ChipSelect(LOW);
   delayMicroseconds(1);    

   // 2) Sector Erase (SE) instruction
   transfer(SPI_SE); 
   delayMicroseconds(1);  
         
   // 3) Transfer the address(24bit) which data will be read.
   ucAddrBuffer[0] = (unsigned char)(address >> 16);
   ucAddrBuffer[1] = (unsigned char)(address >> 8);
   ucAddrBuffer[2] = (unsigned char)(address >> 0);

   transfer( ucAddrBuffer[0] );  
   transfer( ucAddrBuffer[1] );
   transfer( ucAddrBuffer[2] );
  
   // 4)
   delayMicroseconds(1);  
   ChipSelect(HIGH);
}


void M25P16::ReadPage(unsigned char* ucBuffer, 
                      unsigned long ulReadAddr,
                      unsigned long ulNumByteToRead)
{  
      unsigned char ucAddrBuffer[3];

      // 1) The device is first selected by driving Chip Select (S) Low. 
      ChipSelect(LOW);
      delayMicroseconds(1); 
     
      // 2) The instruction code for the Read. 
      transfer(SPI_READ);
  
      // 3) Transfer the address(24bit) which data will be read.
      ucAddrBuffer[0] = (unsigned char)(ulReadAddr >> 16);
      ucAddrBuffer[1] = (unsigned char)(ulReadAddr >> 8);
      ucAddrBuffer[2] = (unsigned char)(ulReadAddr >> 0);
    
      transfer( ucAddrBuffer[0] );  
      transfer( ucAddrBuffer[1] );
      transfer( ucAddrBuffer[2] );

       // loop through    
      //transfer(&ucBuffer, 255);            

      // 5  Disable chip select.
      delayMicroseconds(1); 
      ChipSelect(HIGH);
}

    
void M25P16::WritePage(unsigned long address, 
                        unsigned char *data,
                        unsigned short usNumByteToWrite)
{	

    unsigned char *pusCurrentData = data;
    unsigned long ulCurrentAddress = address;
    unsigned char ucAddrBuffer[3];

      /* 
        The WRITE ENABLE command sets the write enable latch (WEL) bit.
        The WEL bit must be set before execution of every 
        PROGRAM, ERASE, and WRITE com-mand.
        The WRITE ENABLE command is entered by driving chip select (S#) LOW, sending the
        command code, and then driving S# HIGH.    
      */    
      SendSingleCommand(SPI_WREN);
  
      /*
        The PAGE PROGRAM command allows bytes in the memory to be programmed, which
        means the bits are changed from 1 to 0. Before a PAGE PROGRAM command can be ac-
        cepted a WRITE ENABLE command must be executed. 
        After the WRITE ENABLE command has been decoded, 
        the device sets the write enable latch (WEL) bit.
      */
     
      // 1) The Page Program (PP) instruction is entered by driving Chip Select (S) Low.
      
      ChipSelect(LOW); 
      delayMicroseconds(1); 
  
      // 2) Send "PAGE PROGRAM" Command Instruction.
  	  transfer(SPI_PP);
    
      /*
        3) Send 3-Bytes this presents a 24-bit memory address. 
        
        NOTE: unsigned long variables are extended size variables for number storage, 
        and store 32 bits (4 bytes). A 24-bit Flash Memory Offsets is used to present addresses.
        
        address >> 16 // Send 1-Byte MSB 
        address >> 8  // Send 1-byte MSB
        address       // Send Remaining Byte (should be padding zero's only anyway). (00000000 XXXXXXXX XXXXXXXX XXXXXXXX) 24-BITS 
      */
      ucAddrBuffer[0] = (unsigned char)(ulCurrentAddress >> 16);
      ucAddrBuffer[1] = (unsigned char)(ulCurrentAddress >> 8);
      ucAddrBuffer[2] = (unsigned char)(ulCurrentAddress >> 0);
    
      transfer( ucAddrBuffer[0] );  
      transfer( ucAddrBuffer[1] );
      transfer( ucAddrBuffer[2] );

      // 256 / 8 = 32 (8-Bytes send 32 times)
      for (int i = 0; i < usNumByteToWrite; i++ )
      {
          // 4) Transfer a Data as single Byte transfers.
          transfer(*pusCurrentData++);
      }
      
	    // 5) Send the write disable command	
      SendSingleCommand( SPI_WRDI);    
    
     /*        
        6) Chip Select (S) must be driven High after the eighth bit of the last data byte has been 
        latched in, otherwise the Page Program (PP) instruction is not executed.
     */
     delayMicroseconds(1); 
     ChipSelect(HIGH);


      
}

void delayMicroseconds(long delay)
{
	HAL_Delay(delay);
}

void transfer(char b)
{
	
}
