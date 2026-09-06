class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();

        int count =0;

        for(int i=0; i<k; i++){
             if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||s[i]=='u'){
                count++;
                      }         
        }
        int ans = count;
        int st=0; 
        int end = k;


    while(end<n){


    //remove the st character
     if(s[st]=='a' || s[st]=='e' || 
        s[st]=='i' || s[st]=='o' ||
        s[st]=='u'){
                count--;
                      }

    //add new character in the window

   if(s[end]=='a' || s[end]=='e' ||
      s[end]=='i' || s[end]=='o' ||
      s[end]=='u'){
                count++;
                      }

      ans = max(ans, count);
       st++;
       end++;
    }
    return ans;


        }
        
    
};