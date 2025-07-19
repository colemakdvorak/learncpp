#include <iostream>
#include "02_multifile_sep.h"

// Notes: Wrap-up for multi-file project. Uses functions from 02_multifile_sep to read and sum numbers.

int main(){
    // Calls readNumber twice, sums, then prints result using writeAnswer
    writeAnswer(readNumber() + readNumber());
    return 0;
}
