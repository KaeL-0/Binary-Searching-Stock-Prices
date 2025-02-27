#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <cmath>

using namespace std;

class StockPrices{
	
	private:
		int size;
		int* arr;
		const int MIN;
		const int MAX;
	
	public: 
	
	StockPrices(int size = 15): MIN(100), MAX(999){
		this->size = size;
		arr = new int[size];
		randomGeneratedStock();
		mergeSort();
		
	}
	
	void randomGeneratedStock(){
		srand(time(0));
		
		int range = MAX - MIN + 1;
		
		for(int i = 0; i < size; i++){
			arr[i] = (rand() % range) + MIN;
		}
		
	}
	
	void mergeSort(int left = 0, int right = -1){
		
		if(right == -1) right  = size - 1;
		
		if(left < right){
			
			int mid = left + (right - left) / 2;
			
			mergeSort(left, mid);
			mergeSort(mid+1, right);
			
			merge(left, mid, right);
		}
	}
	
	void merge(int left, int mid, int right){
		
		int n1 = mid - left + 1;
		int n2 = right - mid;
		
		int* leftArr = new int[n1]; 
		int* rightArr = new int[n2]; 
		
		for(int i = 0; i < n1; i++){
			leftArr[i] = arr[left + i];			
		}
			
		for(int j = 0; j < n2; j++){
			rightArr[j] = arr[mid + 1 + j];
		}
			
		int i = 0, j = 0;
		int k = left;
		
		while(i < n1 &&  j < n2){
			if(leftArr[i] <= rightArr[j]){
				arr[k] = leftArr[i];
				i++;
			}
			else {
				arr[k] = rightArr[j];
				j++;
			}
			k++; 
		}
		
		while(i < n1){
			arr[k] = leftArr[i];
			i++;
			k++;
		}
		
		while(j < n2){
			arr[k] = rightArr[j];
			j++;
			k++;
		}			
	}
	
	void showStocks(){
		
		for(int i = 0; i < size; i++){
			cout << arr[i] << "\n";
		}		
	}
	
void binarySearch(int x) {
    int low = 0;
	int high = size - 1;
    int count = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            count = 1;
            int left = mid - 1;
			int right = mid + 1;

            while (left >= 0 && arr[left] == x) {
                count++;
                left--;
            }
            while (right < size && arr[right] == x) {
                count++;
                right++;
            }
            break;
        }

        if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (count == 0) {
        cout << x << " does not exist in the market\n";
    } else if (count == 1) {
        cout << x << " is present in the market\n";
    } else {
        cout << "There are " << count << " instances of stock price " << x << " in the market\n";
    }
}
	
};

// Function to validate user input
int getValidInteger(string prompt) {
    float value;
    while (true) {
        cout << prompt;
        cin >> value;
        
        if(value < 0 || trunc(value) != value){
            cout << "Invalid input! Please enter an integer number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
		}
		
        if (cin.fail()) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input! Please enter an integer number.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            return value;
        }
    }
}

int main() {
	
	int input;

  /* MENU INTERFACE */
  
	cout << "___________________________\n";
	cout << " STOCK PRICE SEARCH MENU\n";
	cout << "---------------------------\n\n";
	
	cout << "Input the number of stock prices to generate\n";
	input = getValidInteger("Enter here : ");
	
    cout << "\033[2J\033[1;1H";  // ANSI escape sequence for clearing screen
	
	StockPrices myStock(input);
	
	if(input){
	
	while(input){
	
	
	cout << "___________________________\n";
	cout << " STOCK MANAGEMENT MENU\n";
	cout << "---------------------------\n\n";
	
	cout << "1. Show the stock prices in the market\n";
	cout << "2. Search for a specific stock price\n";
	cout << "3. Exit the program\n\n";
	input = getValidInteger("Enter here : ");

	
	switch(input){
		case 1:
			
    		cout << string(100, '\n');  // Simulates clearing screen by pushing old content up
			cout << "___________________________\n";
			cout << " STOCK PRICES MARKETPLACE\n";
			cout << "---------------------------\n\n";			
			myStock.showStocks();
			
			break;
			
		case 2: {
			int search;
			cout << "\033[2J\033[1;1H";  
			
			cout << "___________________________\n";
			cout << " STOCK PRICE SEARCH\n";
			cout << "---------------------------\n\n";			
			search = getValidInteger("Input the stock price : ");
			myStock.binarySearch(search);
			
			break;
		}
		
		case 3:
			input = 0;
			cout << "\033[2J\033[1;1H";  
			cout << "Exiting Program...\n";
			break;
	}
	
}
	
}

	return 0;
}
