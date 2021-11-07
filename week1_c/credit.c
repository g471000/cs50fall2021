#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool isValidCardNumber(long number, int len);
string getCardType(long number, int len);
int luhnFirstStep(long number, int len);
int luhnSecondStep(long number, int sum, int len);
int countCardNumbers(long number);

int main(void){
    long number = get_long("Number: ");
    int len = countCardNumbers(number);
    if(isValidCardNumber(number, len)){
        printf("%s\n", getCardType(number, len));
    } else {
        printf("INVALID\n");
    }
}

bool isValidCardNumber(long number, int len){
    
    return luhnSecondStep(number, luhnFirstStep(number, len), len) % 10 == 0;
}

int luhnFirstStep(long number, int len){
    // Incase that card number digit length is even, divide by 10, so we will get every oddth place number from the left.
    if(len % 2 == 0){
        number /= 10;
    }

    int sum = 0;
    while(number > 0){
        // Divide by 10 and get the remainder, then multiply by 2
        int temp = (number % 10) * 2;

        // To add 2 digits (or 1), divide by 10 to get the first digit then modulus by 10 to get the remainder, and then add to sum
        sum += (temp / 10) + (temp % 10);

        // Divide by 100, to get the next digit to work
        number /= 100;
    }
    return sum;
}

int luhnSecondStep(long number, int sum, int len){
    if(len % 2 == 1){
        number /= 10;
    }
    while(number > 0){
        sum += number % 10;
        number /= 100;
    }
    return sum;
}

string getCardType(long number, int len){
    string card_type = "None";
    int twoDigits = number / pow(10, len - 2);
    int digit_one = twoDigits / 10;
    int digit_two = twoDigits % 10;
    if(len == 15){
        if(digit_one == 3 && (digit_two >= 3 && digit_two <= 7)){
            return "American Express";
        }
    }
    if((digit_one == 5 || digit_one == 2) && (digit_two >= 1 && digit_two <= 5)){
        if(len == 16){
            return "Mastercard";
        }
    } 
    if(len == 13 || len == 16){
        if(digit_one == 4){
            return "VISA";
        }
    }
    if(len == 16 && twoDigits == 35){
        return "JCB";
    }
    if(len == 16 && twoDigits == 60){
        return "Discover";
    }
    return "Unknown";
}

int countCardNumbers(long number){
    int count = 0;
    while(number > 0){
        count++;
        number /= 10;
    }
    return count;
}