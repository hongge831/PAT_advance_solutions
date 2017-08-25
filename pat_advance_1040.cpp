    //转自浙大软院某学长
	#include <iostream>  
    #include <string.h>  
    using namespace std;   
    char s[1001];  
    int main() {  
        int i, j, x ,y;  
        while(gets(s)) {  
            int max  = 0;  
            for(i=0; i<strlen(s); i++) {  
                for(j=0; i-j >= 0 && i+j < strlen(s); j++) { //奇数时  
                    if(s[i-j] != s[i+j])  
                        break;  
                    if(j * 2 + 1 > max) {  
                        max = j * 2 + 1;  
                    }  
                }  
                for(j=0; i-j >= 0 && i+j+1 < strlen(s); j++) {//偶数时  
                    if(s[i-j] != s[i+j+1])  
                        break;  
                    if(j * 2 + 2 > max) {  
                        max = j * 2 + 2;  
                    }  
                }  
            }  
            cout<<max<<endl;  
        }  
        return 0;  
    }  