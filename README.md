# Stock Price Search Program

## Description
This C++ program generates random stock prices, sorts them using merge sort, and allows users to search for specific stock prices using binary search. The program includes a menu-driven interface for user interaction.

## Features
- Generates a user-defined number of stock prices within a specified range (100-200).
- Sorts the stock prices using the merge sort algorithm.
- Displays the sorted stock prices.
- Allows users to search for a specific stock price using binary search.
- Provides user-friendly input validation.

## How to Use
1. Run the program.
2. Enter the number of stock prices to generate.
3. Choose from the menu options:
   - **Option 1**: Display all generated stock prices.
   - **Option 2**: Search for a specific stock price.
   - **Option 3**: Exit the program.
4. If searching for a stock price, the program will indicate whether it exists and how many times it appears.

## Compilation and Execution
To compile the program, use a C++ compiler such as g++:
```sh
 g++ -o stock_search "ACT 3 - Binary Search.cpp"
```
To run the compiled program:
```sh
 ./stock_search
```

## Dependencies
- C++ Standard Library
- Compatible with C++11 or later

## Code Structure
- **StockPrices Class**: Handles stock price generation, sorting, and searching.
- **mergeSort & merge Functions**: Implements merge sort.
- **binarySearch Function**: Searches for a specific stock price using binary search.
- **getValidInteger Function**: Ensures valid integer input from the user.
- **main Function**: Manages the program's menu and user interactions.

## Example Output
```
___________________________
 STOCK PRICE SEARCH MENU
---------------------------

Input the number of stock prices to generate
Enter here : 10

___________________________
 STOCK MANAGEMENT MENU
---------------------------

1. Show the stock prices in the market
2. Search for a specific stock price
3. Exit the program
Enter here : 1

___________________________
 STOCK PRICES MARKETPLACE
---------------------------
102
110
115
123
134
...
```

## License
This project is open-source under the MIT License.

