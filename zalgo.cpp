#include <iostream>
#include <string>
#include <random>

using namespace std;

string zalgo(string text, int intensity) {
    string result = "";
    
    // Mersenne Twister to produce random number
    // Static -> random number engine is produced only once
    static random_device rd;
    static mt19937 generate(rd());
    uniform_int_distribution<> dis(768, 879);

    for (char c : text) {
        result += c; 
        
        for (int j = 0; j < intensity; ++j) {
            int cp = dis(generate);
            
            /*
            A code point in the 768-879 range needs 2 bytes in UTF-8.
            (cp >> 6) and (cp & 0x3F) is equivalent to
            result += (char)(192 + (cp / 64)); 
            result += (char)(128 + (cp % 64)); 
            */
          
            // Byte 1: The "header" for 2-byte characters
            result += (char)(0xC0 | (cp >> 6));
            // Byte 2: The "continuation" byte
            result += (char)(0x80 | (cp & 0x3F));
        }
    }
    return result;
}

int main() {
    cout << zalgo("Zalgo Text", 3);
    return 0;
}
