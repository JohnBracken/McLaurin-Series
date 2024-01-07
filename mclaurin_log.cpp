//Script to calculate an exponential or natural log function
//using a McLaurin series.

#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

/* Functions to calculate natural log and exponential functions
using Mclaurin series*/
void McLaurinLog(float, int);
void McLaurinExp(float, int);

//Factorial function
long Factorial(int);

//Mclaurin series natural log function (converges for x between -1 and 1)
void McLaurinLog(float x, int n){

    float mc_val = 0;
    float function_val = log(1+x);
    
    for(int i = 1; i < n; i++){
        mc_val += pow(-1,i+1)*pow(x,i)/i;  
    }
    
    cout << "The value of the original log function is: " << function_val << "\n";
    cout << "The value of the McLaurin series log function is: " << mc_val << "\n";

}


//Mclaurin series exponential function (should work for any value of x)
void McLaurinExp(float x, int n){

    float mc_val = 1;
    float function_val = exp(x);
    
    for(int i = 1; i <= n; i++){
        mc_val += pow(x,i)/Factorial(i);  
    }
    
    cout << "The value of the original exponential function is: " << function_val << "\n";
    cout << "The value of the McLaurin series exponential function is: " << mc_val << "\n";

}

//Function definition to calculate a factorial needed for some power series.
long Factorial(int n){
    long factorial = n;
    for(int i = n - 1; i > 0; i--){
        factorial *= i;
    }
    return factorial;
}

//Main function
int main(){

    bool value_inputs = false;
    bool iter_inputs = false;
    float xval;
    int iter;
      
    //User enters value to evaluate function
    while(!value_inputs){
	
        cout << "Enter a value of x (a number) to evaluate the McLaurin exponentional function: " << "\n";
	if(!(cin >> xval)){
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    cout << "Invalid data input..Try again..." << "\n";
	}
        else{
	   cout << "Looks good, thanks." << "\n";
	   value_inputs = true;
	}
}
    //User enters number of iterations for power series version of the function.
    while(!iter_inputs){
	
        cout << "Enter number of iterations to evaluate the McLaurin exponential function: " << "\n";
	if(!(cin >> iter)){
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    cout << "Invalid number of iterations..Try again..." << "\n";
	}
        else{
	   cout << "Looks good, thanks." << "\n";
	   iter_inputs = true;
	}
}

    //Call McLaurin exponential and natural log series functions
    McLaurinExp(xval, iter);
    McLaurinLog(-0.7,15);
    return 0;
}

