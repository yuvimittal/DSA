// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.



class Solution {
public:
    bool isValid(string s) {
        
        string stack;

        for(char c: s){
            if(!stack.empty() && 
            ((c == '}' && stack.back() == '{' ) ||
            ( c == ']' && stack.back() == '[' ) ||
            ( c == ')' && stack.back() == '(' )
             )){
                stack.pop_back();
            }else{
                stack.push_back(c);
            }
        }
        if(stack.empty()){
            return true;
        }

        return false;
    }
};