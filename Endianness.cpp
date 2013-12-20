/*
 * A simple program to test endianess of a machine
 * 
 * Big and little endianess summary:
 * 1. Think of memory for each program as a whole big array
 * 2. Each item in this array is "Exactly 1 and only 1 byte"
 * 3. 32 bit memory space grows from 0x0000 to 0xffff  (4Gbytes)
 * 4. 64 bit memory space grows from 0x00000000 to 0xffffffff (2^32 * 4Gbytes)
 * 5. Memory are wrote/read always from Low to High, it is up to the machine to decide how to interpret bits/bytes streams
 * 6. For an integer   "a = 0xabcd ()"  and  char pointer " char *x = (char*)&a "  
 *    - Memory address   0   1   2   3   + offset
 *    - Memory address   x  x+1 x+2 x+3
 *    - little endian  | d | c | b | a |    or  |1101|1100|1011|1010|
         (Intel)    
 *    - Big endian     | a | b | c | d |    or  |1010|1011|1100|1101|
         (Moto)
 * 7. Endianness only concerns how multiple bytes of a data type is stored in memory. If you are access a data type as a whole e.g. an integer, a long, a double, you should never consider endianess. 
 * 8. When transfer data btw machines, only does it became an issue and you can use hton or ntoh to hide the details. 
 * 9. On a single machine, at the conceptual/logical level, especially dealing with bit operations, you should always visualize it naturally as MSB on the left and LSB on the right. 
 */

#include <iostream>
using namespace std;

int main() {
	// your code goes here
    
// ascii   'a' -> 61   'A' -> 41    NULL -> 0     start of heading -> 1
 unsigned   int c = 0x41000061;
    char *ptr;

    ptr = (char*)(&c);
    
    cout << c << endl; 
    cout << "a out first -> little endianess. " << "A out first -> big endianess" << endl; 
    cout << *ptr << endl;   
    cout << *(ptr+3) << "   third line"<< endl; 
	return 0;
}
