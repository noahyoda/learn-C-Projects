#include "float.h"
#include "time.h"
#include "windows.h"
#include "stdio.h"


/// @brief updates long double values up to denom
void update_long_double(double *ld, int denom){
    //long double t = 4;
    //ld = &t;

    unsigned int sign = 0;

    for(int i = 3; i <= denom && sizeof(*ld) <= sizeof(double); i+=2){
        *ld = (sign) ? *ld - (4 / i) : *ld + (4 / i);
        sign = (sign) ? 0 : 1;
    }

}

/// @brief main calc function
void calc_pi(){
    // 80 bit 19 decimal places
    double val = 4;
    double* ld_pi = 0;
    // timing variables
    clock_t start, end;
    double cpu_time_used;
    
    long int denominator = 301;
    while(1){
        // run long double test
        start = clock();
        update_long_double(ld_pi, denominator);
        end = clock();
        double sec = (end - start) / CLOCKS_PER_SEC;
        
        printf("pi value (long double): %Lf took %f seconds to calculate\n", *ld_pi, sec);

        // sleep before updating
        Sleep(3000);
        denominator *= 10;
        if(denominator > 100000000){
            break;
        }
    }

}

void get_pi(double *pi, int accuracy){
    unsigned int sign = 0;
    for(double i = 3; i <= 100; i+=2){
        // add accuracy val to pi
        *pi = (sign) ? *pi + 4/i : *pi - 4/i;
        // invert sign
        sign = (sign) ? 0 : 1;
        // print debug lines
        printf("pi: %f\n", *pi);
        printf("i: %f\n", i);
        printf("sign: %u\n", sign);
    }
}


int main(int argc, char **argv){
    calc_pi();
    //double c = 4;
    //double *pi = &c;
    // pass param 1 as int
    //get_pi(pi, (int)argv[1]);
//
    //printf("pi was %f\n", *pi);
    //printf("var was %f\n", c);
    //printf("all stored at 0x%p\n", pi);

    return 0;
}