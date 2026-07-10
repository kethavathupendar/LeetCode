class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;

        for (string op : operations){
            if(op == "C"){
                s.pop();
            }
            else if(op == "D"){
              int last = s.top();
               s.push(2*last);
            }
           else  if(op == "+"){
               int last = s.top();
               s.pop();
               int second = s.top();
               s.push(last);
               s.push(last + second);
            }
            else{
                s.push(stoi(op));
            }
        }
        int sum =0;

        while(s.size()>0){
            sum += s.top();
            s.pop();
        }
        return sum;
        
    }
};