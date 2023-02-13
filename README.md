# Diagnostic-Test-Analysis
This is a code which analyses the diagnostic test scores entered by the user. The code then displays the best test score, and also displays the best test number.

The code takes two inputs from the user: the True Positive Rate (TPR) and the False Positive Rate (FPR) of a diagnostic test. The TPR represents the proportion of positive cases that are correctly diagnosed, while the FPR represents the proportion of negative cases that are wrongly diagnosed as positive. The code checks the validity of the inputs, ensures that they are numeric and less than or equal to 1.

The code then calculates the diagnostic test score (TS) using the formula: TS = 1 - sqrt(pow((1 - TPR), 2) + pow((FPR), 2)). The program keeps iterating until the user enters negative values for both TPR and FPR. At each iteration, the diagnostic test score is displayed along with the serial number of the test. The maximum value of the diagnostic test scores is recorded and the serial number of the test with the maximum score is displayed in the end.

The program outputs the final results, showing the serial number of the test with the best score and the score itself. If no valid input was given, the program outputs "Exiting Program".
