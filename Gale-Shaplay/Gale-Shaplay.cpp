#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>



bitset<100001> isFree(0);





bool prefers(vvi &mat, int women, int u, int v){  //function returns true if women prefers u over her current engage with v

    for(int i:mat[women]){

        if(i == u) return true;
        if(i == v) return false;

    }return false;
}




vi GaleShaplay(vvi &mat){


    int size = mat.size()>>1;
    vi partnerW(size, -1);
    for(int i = 0; i<size; i++) isFree.set(i);


    while(isFree.count()){


        int freeMan = isFree._Find_first();

        for(int i = 0; i<size && isFree.test(freeMan); ++i){

            int preferedW = mat[freeMan][i];

            if(partnerW[preferedW - size] == -1){  //preferedW is free, so engage her with our freeMan

                partnerW[preferedW - size] = freeMan;
                isFree.flip(freeMan);
                
            }else{

                //preferedW is not free so compete for her with her actual engage
                int comp = partnerW[preferedW - size];

                if(prefers(mat, preferedW, freeMan, comp)){

                    partnerW[preferedW - size] = freeMan;
                    isFree.flip(freeMan);
                    isFree.set(comp);

                }
            }

        }

    }return partnerW;
 
}




int main(){


    int n, likes;      //number of men and women, so 2n total people
    cin>>n;
    vvi mat(n<<1, vi(n));
    for(int i = 0; i<n<<1; ++i){

        for(int j = 0; j<n; ++j){

            cin>>likes;
            mat[i][j] = likes;


        }

    }
    for(int i: GaleShaplay(mat)) cout<<i<<" ";
    cout<<endl;


    return 0;
}

