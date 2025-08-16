#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char grid[3][3] = {{'1','2','3'},
                   {'4','5','6'},
                   {'7','8','9'}};

void displayBoard() {
    cout << "\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool checkWinner(char p) {
    for(int i=0;i<3;i++) {
        if(grid[i][0]==p && grid[i][1]==p && grid[i][2]==p) return true; // rows
        if(grid[0][i]==p && grid[1][i]==p && grid[2][i]==p) return true; // cols
    }
    if(grid[0][0]==p && grid[1][1]==p && grid[2][2]==p) return true;
    if(grid[0][2]==p && grid[1][1]==p && grid[2][0]==p) return true;
    return false;
}

pair<int,int> randomMove() {
    int r,c;
    do {
        r = rand()%3;
        c = rand()%3;
    } while(grid[r][c]=='X' || grid[r][c]=='O');
    return {r,c};
}

int main() {
    srand(time(0));
    char human='X', comp='O';
    int totalMoves=0;

    while(totalMoves<9) {
        displayBoard();
        int pos;
        cout << "Player " << human << " enter (1-9): ";
        cin >> pos;
        int r=(pos-1)/3, c=(pos-1)%3;

        if(pos>=1 && pos<=9 && grid[r][c]!='X' && grid[r][c]!='O') {
            grid[r][c]=human;
            totalMoves++;

            if(checkWinner(human)) {
                displayBoard();
                cout<<"Player wins!\n";
                return 0;
            }

            if(totalMoves>=9) break;

            auto [cr,cc] = randomMove();
            grid[cr][cc]=comp;
            totalMoves++;
            cout<<"Computer chooses "<<(cr*3+cc+1)<<"\n";

            if(checkWinner(comp)) {
                displayBoard();
                cout<<"Computer wins!\n";
                return 0;
            }
        } else {
            cout<<"Invalid move, try again!\n";
        }
    }

    displayBoard();
    cout<<"Match Draw!\n";
}
