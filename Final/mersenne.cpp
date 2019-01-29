#include "mersenne.h"

//returns the current time in nanoseconds, used to generate a seed
int nano()
{
    struct timespec tm;
    clock_gettime(CLOCK_REALTIME, &tm);
    return tm.tv_nsec;
}

//initializes the array in accordance with the seed
unsigned long createArray(int seed, unsigned long * array)
{	//store value 0 as seed, changing the 32nd bit to 0
	array[0]= seed & 0xffffffffUL;
    for (int i = 1; i < 624; i++) 
        array[i] = (1812433253UL * (array[i-1] ^ (array[i-1] >> 30)) + i); 
}

//Mersenne Twister
unsigned long getRand(int seed)
{
    unsigned long rand;
	//matrix[n] = n * 0x9908b0df for 0 and 1
    static unsigned long matrix[2]={0x0UL, 0x9908b0dfUL};
    static int counter = 625;
	static unsigned long array[624];

    if (counter >= 624) //generate 624 values, once all used, regenerate
	{
        if (counter == 625)   //if createArray has not yet been called
            createArray(seed, array);

        for (int i = 0; i < 227; i++) 
		{	//or 32st bit of i with bits 1-31 of i+1 
            rand = (array[i] & 0x80000000UL) | (array[i+1] & 0x7fffffffUL);
			//get matrix of first bit from value, eor with shifted value
			//eor with values from array of 397-623
            array[i] = array[i+397] ^ (rand >> 1) ^ matrix[rand & 0x1UL];
        }

        for (int i = 227; i < 623; i++) 
		{	//repeat above for 227-623
            rand = (array[i] & 0x80000000UL)|(array[i+1] & 0x7fffffffUL);
			//repeat above with array values for 0-395
            array[i] = array[i+(-227)] ^ (rand >> 1) ^ matrix[rand & 0x1UL];
        }
		//repeat above for remaining array val, looping over to 0
        rand = (array[623] & 0x80000000UL)|(array[0]& 0x7fffffffUL);
		//Do same as above for remaining array value 396
        array[623] = array[396] ^ (rand >> 1) ^ matrix[rand & 0x1UL];
		
		//reset counter
        counter = 0;
    }
  	//select number from the array and increment counter
    rand = array[counter++];

    //temper return value
    rand ^= (rand >> 11);
    rand ^= (rand << 7) & 0x9d2c5680UL;
    rand ^= (rand << 15) & 0xefc60000UL;
    rand ^= (rand >> 18);

    return rand;
}
