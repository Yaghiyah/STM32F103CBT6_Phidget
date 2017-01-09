#ifndef __DS1820B__
#define __DS1820B__

/**
 * 
 */
class DS1820B
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
      DS1820B();  

		 /**
      * De-Constructor
      *
      * Creates a new instance of this driver.  Before using, you create an instance
      * and send in the unique pins that this chip is connected to.
      *
      * @param _cspin The pin attached to Chip Select
      */
      ~DS1820B();

};

#endif // __DS1820B__
