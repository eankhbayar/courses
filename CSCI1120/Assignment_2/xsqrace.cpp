// Ankhbayar Enkhtaivan, 1155185142, 1155185142@link.cuhk.edu.hk

#include <iostream>
#include <random>

using namespace std;

int main()
{
    int seed, n;
    cout << "Enter seed and board size: ";
    cin >> seed >> n;

    mt19937 rps(seed), die(seed);          // random number generators
    uniform_int_distribution<> play(1, 3); // random int in [1, 3]
    uniform_int_distribution<> roll(1, 6); // random int in [1, 6]

    int hi = 1, hj = 1, ci = n, cj = 1;
    int game_end_status = 0;
    int round = 1;
    int human_score = 1, computer_score = 1;
    while (game_end_status != 1)
    {
        cout<<"Round "<<round<<":"<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ci==i && cj==j){
                    cout<<"C";
                }else if(hi==i && hj==j){
                    cout<<"H";
                }else if((i==1 || j== 1) || (i==n || j==n) || (i==j) || (i+j==n+1)){
                    cout<<"*";
                }else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }

        // play rock, paper, scissors
        while(true){
            int human_choice, computer_choice;
            cout<<"Choose (1=R, 2=P, 3=S): ";
            cin>>human_choice;
            computer_choice = play(rps);
            string human_choice_str = (human_choice == 1) ? "Rock" : (human_choice == 2) ? "Paper" : "Scissors";
            string computer_choice_str = (computer_choice == 1) ? "Rock" : (computer_choice == 2) ? "Paper" : "Scissors";
            cout<<"Human picks "<<human_choice_str<<"."<<endl;
            cout<<"Computer picks "<<computer_choice_str<<"."<<endl;
            if(human_choice != computer_choice){
                int d = roll(die);
                // human wins
                if((human_choice == 1 && computer_choice == 3) || (human_choice == 2 && computer_choice == 1) || (human_choice == 3 && computer_choice == 2)){
                    cout<<"Human wins and moves "<<d<<" step(s)."<<endl;
                    human_score += d;
                    break;
                }
                // computer wins
                else{
                    cout<<"Computer wins and moves "<<d<<" step(s)."<<endl;
                    computer_score += d;
                    break;
                }
            }else{
                cout<<"Draw!"<<endl;
            }
        }
        // update positions
        if(human_score <= n){
            hi = 1;
            hj = human_score;
        }else if(human_score > n && human_score <= 2*n-2){
            hi = human_score-n+1;
            hj = n - human_score + n;
        }else{
            hi = n;
            hj = human_score-2*n+2;
        }
        if(computer_score <= n){
            ci = n;
            cj = computer_score;
        }else if(computer_score > n && computer_score <= 2*n-2){
            ci = n-computer_score+n;
            cj = n-(computer_score-n);
        }else{
            ci = 1;
            cj = computer_score-2*n+2;
        }

        if(human_score >= 3*n-2){
            game_end_status = 1;
            cout<<"Game over!"<<endl;
            cout<<"Human wins the game!"<<endl;
        }
        if(computer_score >= 3*n-2){
            game_end_status = 1;
            cout<<"Game over!"<<endl;
            cout<<"Computer wins the game!"<<endl;
        }

        round += 1;
    }
}