#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
int main(){
    cout<<endl;
    for (int i = 0; i < 2; i++) {
        cout << string(2 + i*2, ' ');
        for (int j = 0; j < 5; j++)
            cout << setw(2) << char('A' + j);
    }
    cout << endl;
    for (int i = 0; i < 5;i++){
        for(int k = 0;k < 2;k++){
            cout<< setw(2) << i + 1;
            // cout << string(1 + k * 2, ' ');
            for (int j=0;j<5;j++){
                cout << setw(2) << '.';
            }
            cout<<setw(2)<<" ";
        }
        cout<<endl;
    }

    char k;
    char col; int row;
    cin>>k;
    cin >> col >> row;
    cout<<k;
    cout<<endl;
    cout<<col;
    cout<<endl;
    cout<<row;
}