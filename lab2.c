#include <stdio.h>
#include <math.h>
#include <stdbool.h>



// method determines if two arrays are subsets
bool isSubset(int array1[], int array2[]){
	
	int j = 0;
	// double for loop that determines if one value of an array is in another
	for (int i = 0; array2[i] != 0; i++){
		for (j = 0; array1[j] != 0; j++){
			if (array2[i] == array1[j]){
					break;
				}
		}
		// if it returns 0 the program ends
		if (array1[j] == 0) {
			return 0;
		}

	}
		
	return 1;
}


// using my seperate function from last lab
void Seperate(long int num, int sets[]){
	
	int current_index = 0;

       	while(num > 9) {

		int no_zeros = (int)log10((double)num);
                int lastDigit = (int)num/pow(10.0, (double)no_zeros);
		// this variable takes the digit and places it in the array
                sets[current_index] = lastDigit;
		
                num = num - (lastDigit* pow(10.0, (double)no_zeros));
		current_index++;
		// increasing which spot in the  array we are at
		
	}
	// increases the array size by one so we can move to the next array
	sets[current_index] = num;
	sets[current_index + 1] = 0;


	return;

}

// this method is for formatting, it helpes keep the printed arrays looking nice
void printArray(int array[] ){
	printf("Set ");
	// 6 is the max length an array can be
	for(int i = 0; i < 6 ; i++){

        	printf("%d", array[i]);

		if (array[i+1] == 0){
                        break;
                }
		else{
			printf(",");
		}
	}

}


int main(void){
	
	 // open the file
        FILE* fptr = fopen("/public/lab2/sets.txt", "r");
	// creating a 2d array
        int sets[10][6];
        long int num;
        int cur_set_no = 0;
	// moving through the text file and adding the numbers to the array
        while (fscanf(fptr, "%ld", &num) != EOF) {
		// this function seperates those numbers into digits
                Seperate(num, sets[cur_set_no]);
                cur_set_no++;

        }
	// keeping track of how many sets I have
        int no_sets = cur_set_no;
	
	//close the file
        fclose(fptr);
	

	// double for loop to read through the 2d array
	for (int i = 0; i < no_sets; i++)
		for (int j = 0; j < no_sets; j++){
			// this if statement makes it so we dont get repeating arrays comparing eachother
			if (i != j){
			// this if statement compares arrays to eachother and determines if they are subsets
			if (isSubset(sets[i], sets[j])) {
				printArray(sets[j]);
				printf(" is a subset of ");
				printArray(sets[i]);
				printf("\n");
			}

		}

	}
	return 0; 
}

