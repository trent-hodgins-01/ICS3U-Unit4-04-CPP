// Copyright (c) 2021 Trent Hodgins All rights reserved

// Created by Trent Hodgins
// Created on 10/04/21
// This is a guessing game program
// The user enters in a number between 1 and 100

#include <iostream>
#include <random>

int main() {
    // this function checks to see if the user guessed the correct number
    int loopCounter = 0;
    int answer = 1;
    std::string numberAsString;
    float someRandomNumber;
    int guessedNumber;

    // making the someRandomNumber variable a random number
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 100);
    // [0, 100]
    someRandomNumber = idist(rgen);

    // input, process and output
    while (true) {
        std::cout << "Guess a number between 0 and 100 (integer): ";
        std::cin >> numberAsString;
        std::cout << "" << std::endl;
        try {
            guessedNumber = std::stoi(numberAsString);
            if (guessedNumber == someRandomNumber) {
                std::cout << "You Guessed Correctly!" << std::endl;
                break;
            } else if (guessedNumber > someRandomNumber) {
                std::cout << "Guess lower" << std::endl;
            } else {
                std::cout << "Guess higher" << std::endl;
            }
            } catch (std::invalid_argument) {
                std::cout << "You didn’t enter in a number" << std::endl;
            }
    }

    std::cout << "\nDone." << std::endl;
}
