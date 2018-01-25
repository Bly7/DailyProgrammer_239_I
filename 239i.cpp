// Includes
//
// Iostream - C++ default IO library
#include <iostream>
// Vector - C++ default vector library
#include <vector>

// Main function
int main(int argc, char* argv[])
{
	// Number - Int that holds testing number	
	int number = 0;
	
	// While Loop that gets number
	while (number == 0)
	{
		// Output instruction
		std::cout << "Welcome to Game of Threes!" << std::endl;
		std::cout << "You will input a number to start with or 1 to exit," << std::endl;
		std::cout << "then enter -1,0,1 to add to the current number to get it to be divisible by three." << std::endl;
		std::cout << "Do this until you cannot divide by 3 anymore." << std::endl;
		std::cout << "Input Number(1 - INT_MAX): ";

		// Input - Int that holds input number
		int input = 0;

		// Get input
		std::cin >> input;

		// Test for valid input
		//
		// If not return error
		if (input <= 0)
			std::cout << input << " is an invalid input! Try again..." << std::endl;
		// If so set number
		else
			number = input;
	}

	// Stored_Input - Holds successful input variables
	std::vector<int> stored_input;
	
	// Played - Variable that holds whether or not you played the game
	bool played = false;
	
	// While loop that contains game loop
	while (number != 1)
	{
		// Output current state
		std::cout << number << " ";

		// Input - Int that holds input number
		int input = 0;

		// Get input
		std::cin >> input;

		// Test for valid input
		//
		// If so handle it
		if (input >= -2 && input <= 2)
		{
			// Test if correct answer
			// 
			// If so handle input with number
			if ( ((input + number) % 3) == 0)
			{
				number = (input + number) / 3;
				stored_input.push_back(input);
			}
			// If not return error
			else
				std::cout << "Wrong Answer! Try Again..." << std::endl;
		}
		// If not return error
		else
		{
			std::cout << input << " is an invalid input! Try again..." << std::endl;
		}
		
		// If the game is complete set played to true
		if (number == 1)
		{
			played = true;
		}
	}

	// Output closing remarks
	//
	// If you beat the game output the end state
	if (played)
	{
		// Output final number - Should be 1
		std::cout << number << std::endl;
		
		// Sum - will hold sum of input
		int sum = 0;
		
		// Go through stored_input and add up the sum
		for (int i = 0; i < stored_input.size(); i++)
			sum += stored_input[i];
		
		// Output sum
		std::cout << "Sum: " << sum << std::endl;
		
		// If sum zeroes out print congrats
		if (sum == 0)
			std::cout << "Corrent Input!" << std::endl;
		// If not print warning
		else
			std::cout << "Incorrect Input..." << std::endl;
	}
	// If you didn't play the game output goodbye
	else
	{
		std::cout << "Goodbye..." << std::endl;
	}

	// Exit game
	return 0;
}
