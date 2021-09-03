//
//  main.cpp
//  Q4
//
//  Created by adri mohamad on 16/12/2020.
//  Copyright © 2020 Afiq Husyairi. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
const int SIZE=4;

void displaymenu(int list[SIZE][SIZE]);
void findMaxPri (int list[SIZE][SIZE]);
void findMinSec (int list[SIZE][SIZE]);
void abovePri (int list[SIZE][SIZE]);
void belowPri (int list[SIZE][SIZE]);
void swapCol (int list[SIZE][SIZE]);
void swapRow (int list[SIZE][SIZE]);

int main() {
    
    int input;
    int list[SIZE][SIZE] = {    2,  33, 4,  1,
                                3,  44, 3,  12,
                                56, 7,  8,  86,
                                5,  2,  4,  21  };
    displaymenu(list);
    cin >> input;
    
    while (input!=0){
        
    
    switch(input){
            
        case 1 :    findMaxPri(list);
            break;
        case 2 :    findMinSec(list);
            break;
        case 3 :    abovePri(list);
            break;
        case 4 :    belowPri(list);
            break;
        case 5 :    swapCol(list);
            break;
        case 6 :    swapRow(list);
            break;
    }
        cout << endl;
        displaymenu(list);
        cin >> input;
    }
    
    return 0;
}

void findMaxPri (int list[SIZE][SIZE]){
    
    int max = list[0][0];
    
    for(int i=0; i<SIZE; i++){
       
        if(list[i][i]>max)
            max=list[i][i];
    }
    cout << "The maximum value in primary diagonal is " << max << endl;;
}

void findMinSec (int list[SIZE][SIZE]){
    
    int min = list[0][3];
    for (int i=1; i<SIZE; i++){
        int j=2;
        if (list[i][j]<min)
            min = list[i][j];
        j--;
    }
    cout << "The minimum value in secondary diagonal is " << min << endl;
}

void abovePri (int list[SIZE][SIZE]){
    
    for (int i=0; i<3; i++){
        if (i==0){
            for (int j=1; j<SIZE; j++)
                list[i][j]=0;
        }
        else if (i==1){
            for (int j=2; j<SIZE; j++)
                list[i][j]=0;
        }
        else
            list[i][3] = 0;
    }
    
    for (int i=0; i<SIZE;i++){
        for (int j=0; j<SIZE; j++)
            cout << setw(5) << list[i][j];
        cout << endl;
    }
}

void belowPri (int list[SIZE][SIZE]){
    
    for (int i=1; i<SIZE; i++){
        if (i==1)
            list[i][0]=0;
        else if (i==2){
            for (int j=0; j<2; j++)
                list[i][j]=0;
        }
        else {
            for (int j=0; j<3; j++)
                list[i][j] = 0;
        }
    }
    
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++)
            cout << setw(5) << list[i][j];
        cout << endl;
    }
}

void swapCol (int list[SIZE][SIZE]){
    
    for (int i=0; i<SIZE; i++){
        int temp=list[i][0];
        list[i][0]=list[i][2];
        list[i][2] = temp;
    }
    cout << "After swapping : " << endl;
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++)
            cout << setw(5) << list[i][j];
        cout << endl;
    }
}

void swapRow (int list[SIZE][SIZE]){
    
    for (int i=0; i<SIZE; i++){
        int temp = list[1][i];
        list[1][i] = list[3][i];
        list[3][i] = temp;
    }
    cout << "After swapping : " << endl;
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++)
            cout << setw(5) << list[i][j];
        cout << endl;
    }
}

void displaymenu (int list[SIZE][SIZE]){
    
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++)
            cout << setw(5) << list[i][j];
       cout << endl;
    }
    
    cout << "1 to find the maximum value in the primary diagonal of the array" << endl;
    cout << "2 to find the minimum value in the secondary diagonal of the array" << endl;
    cout << "3 Change the values ABOVE the primary diagonal to be all ZEROs" << endl;
    cout << "4 Change the values BELOW the primary diagonal to be all ZEROs" << endl;
    cout << "5 swap the values of the first column with the values of the third column" << endl;
    cout << "6 swap the values of the second row with the values of the fourth row." << endl;
    cout << "0 to exit" << endl;
    
}



