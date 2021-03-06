/*
 * Lab1.cpp
 *
 *  Created on: Sep 14, 2016
 * John Pae, Eric Allen. Leighanne Hsu. Lab 1.
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Function Declarations:
void hello(); //Q1
int collaz_calc(int); //Q2
void collaz_set(); //Q2
int sort_by_order(int*,int*,int*); //Q3
bool perfect_number(int, int, int); //Q4
int sort_by_order2(int, int, int); //Q5
void random_array(int *x, int y); //Q6a
void print_array(int *x, int y);  //Q6b
void reverse_array(int *x, int y); //Q7
int min_array(int *x,int y); //Q8
int sum_array(int *x, int y);//Q9
int sort_array(int *array, int x);//Q10
void pass_filter(int *x,int y, int z);//Q11
void make_array(int*** l, int i, int j, int k); //Q12A
void print_array3(int*** l, int i, int j, int k);//Q12B

//Main:
int main(){
	// Creates seed for time but not = anything
	srand(time(NULL));


	//question1
	cout<<"Question 1"<<endl;
	hello();

	//<question 2>
	string input;
	cout<<"Question 2"<<endl;
	cout <<"Please enter the number five, it should tell you that it took five steps:"<< endl;
	cin >> input;
	int number = atoi (input.c_str());
	int count = collaz_calc(number);
	cout <<"Your number reached 1 in: " << count << " steps."<< endl;
	collaz_set();//<\question 2>

	//I WANT TO TEST 3 & 5 two different ways to prove the func. works

	// QUESTION 3
	//random number between 1-100
	int x = rand() % 100 + 1;//Random Number 1
	int y = rand() % 100 + 1;//Random Number 2
	int z = rand() % 100 + 1; //Random Number 3

	cout <<"Question 3"<<endl;
	cout<<"Your three random numbers are: "<< x <<", "<< y <<", "<< z << endl;
	int result = sort_by_order(&z, &y, &x);
	// mixed up x,y,z to show that is has to sort by value from least to greatest
	// and that it recognizes what the smallest value is.
	// Q5 will be alphabetical
	cout<< "The smallest of the 3 numbers is:" <<  result << endl;


	//QUESTION 4
	int i =3;
	cout <<"Question 4"<<endl;
	cout<<"Test Number: "<< i <<"."<<"   Perfect Number: "<<perfect_number(i, 1, 0)<< endl;



	//Question 5 CALL BY REFERENCE
	int x1 = rand() % 100 + 1;//Random Number 1
	int y1 = rand() % 100 + 1;//Random Number 2
	int z1 = rand() % 100 + 1; //Random Number 3
	// x,y,z input in alphabetical order x,y,z to show that is has to sort by value from least to greatest
	// and that it recognizes what the smallest value is regardless of order input into func.

	cout <<"Question 5"<<endl;
	cout<<"Your three random numbers are: "<< x1 <<", "<< y1 <<", "<< z1 << endl;
	int result2 = sort_by_order2(x1, y1, z1); //Call Sort By Order 2
	cout<< "The smallest of the 3 numbers is:" <<  result2 << endl; //Result

	//question 6A
	int size = (rand()%30) + 20;
	int array[size];
	random_array(&array[0], size);

	//Question 6B
	cout<<"Question 6B"<<endl;
	cout<< "Print Array"<<endl;
	print_array(&array[0], size);

	//QUESTION 7

	cout<<"Question 7"<<endl;
	cout<<"Reverse Array"<<endl;
	reverse_array(&array[0], size);


	//QUESTION 8

	cout<<"Question 8"<<endl;
	cout<<"MINIMUM VALUE"<<endl;
	min_array(&array[0],size);


	//QUESTION 9
	cout<<"Question 9"<<endl;
	cout<<"SUM OF VALUES"<<endl;
	int sum1 = sum_array(&array[0], size);
	cout<<sum1<<endl;

	//QUESTION 10
	cout<<"Question 10"<<endl;
	cout<<"Total Count"<<endl;
	int count1 = sort_array(&array[0], size);
	cout<< count1 << endl;


	//QUESTION 11
	int arrayX[15] = {3,2,7,0,4,2,1,6,4,2,9,5,4,2,3};
	int windowX = 5;
	int sizeX = 15;
	cout<<"Question 11"<<endl;
	pass_filter(arrayX ,windowX, sizeX);
	cout<< "Pass Filter"<<endl;
	print_array(arrayX, 15);


	//QUESTION 12
	int length = -1;
	length = (rand()% 5) +2;
	int width = -1;
	width = (rand()% 5) + 2;
	int depth = -1;
	depth = (rand() % 5) +2;

	int*** ll = NULL;
	cout<<"Question 12"<<endl;
	cout<<"Make Array"<<endl;
	make_array(&ll[0], length, width, depth);
	// PROGRAM GETS BROKEN IN make_array
	cout<<"Question 12, Array"<<endl; // doesn't print
	print_array3(&ll[0], length, width, depth);



	return 0;
}

//Project Functions:
void hello()//Question 1
{
	cout <<"!!!Hello World!!!"<< endl;
}

int collaz_calc(int num)//Question 2a
{
	int count = 0;

		while(num != 1){
			if (num % 2 == 0){
				num = num/ 2;
				count++;
			}//if even
			else{
				num = (num*3)+1;
				count++;
			}//if odd
		}//while

		return count;
}

void collaz_set()//Question 2b
{
	string start;
	string end;

	cout <<"PLease enter your starting number (whole number please): "<< endl;
	cin >> start;
	int start_num = atoi(start.c_str());

	cout <<"Now please enter your ending number (whole number please): "<< endl;
	cin >> end;
	int end_num = atoi(end.c_str());

	for (int a = start_num; a <= end_num; a = a+1){
		cout <<"The number "<< a <<" has reached 1 in "<< collaz_calc(a) <<", Collaz is still working"<< endl;
	}//for
}


int sort_by_order(int *num1, int *num2, int *num3)//Question 3
{
	if ((*num1 <= *num2) & (*num2 <= *num3)){
		cout <<"true"<< endl;
		return true;
	}//If no work needs to be done
	if (*num1 > *num2){
		swap(num1,num2);
	}//if greater
	if (*num2 > *num3){
		swap(num2,num3);
	}//if greater
	if (*num1 > *num2){
		swap(num1,num2);
	}//if greater
	return *num1;
	cout << *num1 <<","<< *num2 <<","<< *num3 << endl;
}

bool perfect_number(int num, int test, int sum)//Question 4
{
	if (sum == num){
		cout <<"The number "<< num <<" is a perfect number."<<endl;
		}// if equals
	return true;

	if (test > num/2){
		cout <<"The number "<< num <<" is not a perfect number."<<endl;
		}//if greater
	return false;

	if (num % test == 0){
		sum = sum + test;
	}

	perfect_number(num, test+1, sum);
}

int sort_by_order2(int num1, int num2, int num3)//Question 5
{
	if ((num1 <= num2) & (num2 <= num3)){
		cout <<"true"<< endl;
		return num1;
	}//If no work needs to be done
	if (num1 > num2){
		swap(num1,num2);
	}// if greater
	if (num2 > num3){
		swap(num2,num3);
	}// if greater
	if (num1 > num2){
		swap(num1,num2);
	}// if greater
	return num1;
	cout << num1 <<","<< num2 <<","<< num3 << endl;
}

void random_array(int *arr, int size)//Question 6a
{
	for (int i = 0; i < size; i++){
		int x = rand()%100-50;
		arr[i] = x;
	}//for loop
	return;
}

void print_array(int arr[], int size)//Question 6b

{
	for (int i = 0; i < size; i++){
		cout<< arr[i] << endl;
	}//for loop
	return;
}

void reverse_array(int *array, int size)//Question 7
{
	int start = 0;
	int end = size - 1;
	while (start < end ){
		swap(array[start], array[end]); //reverses
		start++;// increments through
		end--; // deincrements through
	}//while
	print_array(&array[0], size);
	return;
}



// **THIS IS ERIC ALLEN AND JOHN PAE's CODE**


int min_array(int *arr, int size)//Question 8
{
	int curr_min = arr[0];
	for (int i = 1; i < size; i++){
		if (arr[i] < curr_min){
			curr_min = arr[i];
		}//if
	}//for
	cout << curr_min << endl;
	return curr_min;
}

//Question 9
int sum_array(int *arr, int size){
	int sum= arr[size-1];
	if (size-1 > 0){
		sum = sum + sum_array(&arr[0],size-1);
	}// if, end condition.
	return sum;
}
//QUESTION  10
int sort_array(int array[], int length){
	int Num;
	int count = 0;
	for (int i = 0; i < length; i++){
		count +=1;
		//count 1 for comparison i
		for (int j = 1; j < length -1; j++){
			count +=1;
			// count 2 for comparison j
			if(array[j]<array[i]){
				Num = array[i];
				array[i] = array[j];
				array[j] = Num;
				count +=1; //count 3 for comparing j and i
			}//for i
		}//for j
	} //if less

	return count;
}


//QUESTION  11
void pass_filter(int array[],int window, int size){
	if(window %2 == 0){
		window +=1;
	}//if
	int Array2[size];
	for (int i= 0; i < size; i++){
		if (i<window/2){
			array[i]=0;
		}//if
		else if(i >= size-window/2){
			array[i]=0;
		}//else if
		else{
			int sum = 0;
			for (int j=0; j <window; j++){
				if(j<= window/2){
					sum += Array2[i-j];
				}//if
				else{
					sum += Array2[i+j - window/2];

				}//else
				array[i] = sum/window;
			}//for j

		}// else

	}//for i
	return;
}


//QUESTION  12

void make_array(int*** array, int length, int width, int depth){
	//int***l = new int**[length];
	for (int i = 0; i < length; i++) {
		array[i] =  new int* [width];
		for (int j = 0; j < width; j++){
			array[i][j] = new int [depth];
			for (int k = 0; k < depth; k++){
				//array[i][j][k] =  *** l;
				array[i][j][k]= i+j+k;
			}// for k
		}// for j
	}// for i
	return;
}


//Question 12b
void print_array3(int*** array, int length, int width, int depth){
	for (int i = 0; i < length; i++){
		for (int j = 0; j < width; j++){
			for (int k = 0; k < depth; k++){
				cout<< array[i][j][k] <<endl;

			}// for k

		}//for j
	}// for i

	for (int i = 0; i < length; i++) {
		delete [] array[i];

		for (int j = 0; j < width; j++) {
			delete [] array[i][j];

			for (int k = 0; k < depth; k++) {
				//delete [] array[i][j][k];
			}//for k
		}//for j
	}//for i
	delete [] array;

 return;
}


