// Include screen I/O libraries
#include <iostream>
#include <cmath> // library containing the sqrt and pow functions.
using namespace std;

int main(int argc, char const *argv[])
{
    float TPR {0}; // variable that will store the value of the true positive rate entered by the user
    float FPR {0}; // variable that will store the value of the true positive rate entered by the user
    int n{0}; // variable that will store the serial number of the diagnostic test, initially initialized to zero.
    int a{2}; // essential for the infinite iteration of the while loop
    double TS; // variable that will store the test result after calculation
    double TSmax{-1000}; // variable stores the maximum value of the diagnostic tests
    int nmax{0}; // variable stores the serial number of the maximum value of the diagnostic test.
    
    while (a > 1){   // the condition ensures that the while loop iterates infinitely until a condition breaks the loop
        
        cout << "Please enter the diagnostic test's true positive rate: ";
        cin >> TPR; // user enters the value into TPR

        
        if (TPR > 1){ // the loop is executed if the value of TPR is greater than 1
            while (TPR > 1) // loop iterates until the user enters a valid input
            {
                cerr << "Warning: invalid input to true positive rate. Please enter an input <=1: ";
                cin >> TPR;
            }
        }

        if (cin.good() == 0) { // the loop is executed if the value of TPR is not numeric 
            while (cin.good() == 0){ // loop iterates until the user enters a valid input
                cin.clear();
                cin.ignore(100, '\n');
                cerr << "Warning: invalid input to true positive rate. Please enter a numeric input: ";
                cin >> TPR;
            }
        }
    
        cout << "Please enter the diagnostic test's false positive rate: ";
        cin >> FPR;

        if (FPR > 1){ // the loop is executed if the value of FPR is greater than 1
            while (FPR > 1) // loop iterates until the user enters a valid input
            {
                cerr << "Warning: invalid input to false positive rate. Please enter an input <=1: ";
                cin >> FPR;
            }
        }

        if (cin.good() == 0) { // the loop is executed if the value of FPR is not numeric
            while (cin.good() == 0){ // loop iterates until the user enters a valid input
                cin.clear();
                cin.ignore(100, '\n');
                cerr << "Warning: invalid input to false positive rate. Please enter a numeric input: ";
                cin >> FPR;
            }
        }   

        // Either of the 2 variables (TPR or FPR) must have a positive value for the codeblock to be executed
        if ((TPR >= 0) or (FPR >= 0)){ 
            if (TPR < 0){ // the value of TPR is automatically assigned as 0 if the user enters a negative value
                TPR = 0;
            }
                
            if (FPR < 0){  // the value of FPR is automatically assigned as 0 if the user enters a negative value
                FPR = 0;
            } 
            
            TS = 1 - sqrt(pow((1 - TPR), 2) + pow((FPR), 2)); // calculation of the diagnostic test score
        
            n = n+1; //serial number is incremented by one
    
            cout << "The score for the diagnostic test " << n << " is: " << TS << endl; // output after the calculation
            cout << "________________________________________________________________________________________________________________" << endl;

            // In the below codeblock, the maximum value of the variable TS is assigned to TSmax and the value of n is assigned to nmax if TS > TSmax. Note that TSmax has been initialized to -1000 while nmax has been initialized to 0.
            if (TS > TSmax){ 
                TSmax = TS;
                nmax = n;
            }
        }    

        // The loop breaks if the values of both TPR and FPR are negative i.e. the user entered a negative value on both of them.
        if ((TPR < 0) and (FPR < 0)){ 
            break;
        }

        // loop iterates until the condition for breaking is fulfilled
    }
    
    //the codeblock gets executed only if the value of TSmax is greater than -1000.
    if (TSmax > -1000){
    cout << "________________________________________________________________________________________________________________" << endl;
    cout << "Diagnostic test " << nmax << " has the best score of " << TSmax << endl; // final output
    cout << "Exiting Program" << endl;
    }

    //the codeblock gets executed only if the value of TSmax is less than -1000 i.e. the loop broke as both TPR and FPR were less than zero.
    else{
        cout << "________________________________________________________________________________________________________________" << endl;
        cout << "Exiting Program" << endl;
        }

    return 0;
}
