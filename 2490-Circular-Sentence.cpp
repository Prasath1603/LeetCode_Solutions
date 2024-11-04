class Solution {
public:
    bool isCircularSentence(string sentence) {
        bool f1 = false,f2 = false;
        if(sentence.size() <2) return true;
        for(int i = 0 ; i < sentence.size() - 2 ; i++){
            if(sentence[i + 1] == ' '){
                f2 = true;
                if(sentence[i] == sentence[i + 2]){
                    f1 = true;
                    continue;
                }
                else{
                    f1 = false;
                    break;
                }
            }
        }
        if(!f2) return sentence[0] == sentence[sentence.size() - 1] ;
        if(sentence[0] == sentence[sentence.size() - 1]){
            return f1;
        }
        return false;
    }
};