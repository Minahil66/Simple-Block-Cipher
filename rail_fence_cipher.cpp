#include<iostream>
#include<string>
#include<vector>
using namespace std;
class railfence_cipher{
    private:
    int rails;
    string text;
    string flag;
    string result;
    public:
    railfence_cipher(string f, int r, string t): rails(r), text(t), flag(f){}
    void decrypt(){
        int len=text.length();
        vector<int> rail_count(rails,0);
        int rail=0;
        int dir=1;
        for(int i=0;i<len;i++){
            rail_count[rail]++;
            if(rail==0) { dir=1;}
            if(rail==(rails-1)) {dir=-1;}
            rail+=dir;
        }
        int start=0;
        vector<string> rail_arr(rails);
        for(int i=0;i<rails;i++){
            int count=rail_count[i];
            rail_arr[i]+=text.substr(start, count);
            start+=count;
        }
        vector<int> position(rails,0);
        rail=0;
        dir=1;
        for(int i=0;i<len;i++){
        int pos=position[rail];
        result+=rail_arr[rail][pos];
        position[rail]++;
        if(rail==0){ dir=1;}
        if(rail==(rails-1)){dir=-1;}
        rail+=dir;
        }
    }
    string getresult () const{
    return result;
    }
    void encrypt(){
         int len=text.length();
        vector<string> rail_arr(rails);
        int rail=0;
        int dir=1;
        for(int i=0;i<len;i++){
            char ch=text[i];
            rail_arr[rail]+=ch;
            if(rail==0){ dir=1;}
        if(rail==(rails-1)){dir=-1;}
        rail+=dir;
    }
    for(int i=0;i<rails;i++){
        result+=rail_arr[i];
    }
    }
};
int main(){
    railfence_cipher r1("-e", 3, "droptesting");
    r1.encrypt();
    cout<<r1.getresult()<<endl;

        railfence_cipher r2("-d", 3, "dtirpetnosg");
    r2.decrypt();
    cout<<r2.getresult()<<endl;
}