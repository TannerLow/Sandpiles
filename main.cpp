#include <iostream>

using namespace std;
typedef unsigned long long ull;

class SandPile{
    private:
        //2,1,2  1,0,1  2,1,2
        //   =
        // 2 1 2
        // 1 0 1
        // 2 1 2
        ull pile[3][3] = {{2,1,2},{1,0,1},{2,1,2}}; 
        
    public:
        SandPile(){}
        SandPile(ull arr[3][3]){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    pile[i][j] = arr[i][j];
                }
            }
            //this->topple();
        }
        void display(){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cout << pile[i][j] << " ";
                }
                cout << endl;
            }
        }
        SandPile operator+(const SandPile& sp){
            SandPile newSp;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    newSp.pile[i][j] = this->pile[i][j] + sp.pile[i][j];
                }
            }
            return newSp;
        }
        
        void topple(){
            int count = 0;
            while(!isToppled()){
                count++;
                ull arr[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
                SandPile overflow(arr);
                
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        
                        if(pile[i][j] > 3){
                            if(i - 1 >= 0)
                                overflow.pile[i-1][j]++;
                            if(i + 1 < 3)
                                overflow.pile[i+1][j]++;
                            if(j - 1 >= 0)
                                overflow.pile[i][j-1]++;
                            if(j + 1 < 3)
                                overflow.pile[i][j+1]++;
                        
                            pile[i][j] -= 4;
                        }
                        
                    }
                }
                *this = *this + overflow;
            }
            cout << count << endl;
        }
        
        bool isToppled(){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(pile[i][j] > 3)
                        return false;
                }
            }
            return true;
        }
};

int main(){
    ull arr[3][3] = {{1,2,3},{3,2,1},{1,2,3}};
    SandPile pile1(arr);
    SandPile pile2;
    
    cout << "Pile 1: " << endl;
    pile1.display();
    cout << pile1.isToppled() << endl;
    
    cout << "Pile 2: " << endl;
    pile2.display();
    cout << pile2.isToppled() << endl;
    
    SandPile pile3 = pile1 + pile2;
    cout << "Pile 3: " << endl;
    pile3.display();
    cout << pile3.isToppled() << endl;
    
    pile3.topple();
    cout << "Pile3: " << endl;
    pile3.display();
    cout << pile3.isToppled() << endl;
    
    ull arr1[3][3] = {{999999  , 132541234, 789234  },
                      {41234141, 346345634, 2352546 },
                      {13452345, 223452   , 30789765}};
    SandPile pile4(arr1);
    pile4.topple();
    cout << "Pile 4: " << endl;
    pile4.display();
    
    return 0;
}
