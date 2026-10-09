class Solution {
public:
    // int minInsertions(string s) {
    //     stack<char> st;
    //     int unpaired = 0;

    //     int idx = 0;
    //     while(idx < s.length()) {
    //         if(s[idx] == '(') {
    //             st.push(s[idx]);
    //             unpaired += 2;
    //         } else {
    //             if(st.size() > 0) {
    //                 st.pop();
    //                 if(s[idx] == ')' && s[idx+1] == ')') {
    //                         unpaired -= 2;
    //                         idx++;
    //                 } else {    // if(s[idx] == ')')
    //                     unpaired--;
    //                 }        
    //             } else {
    //                 if(s[idx] == ')' && s[idx+1] == ')') {
    //                     unpaired++;
    //                     idx++;
    //                 } else {
    //                     unpaired += 2;
    //                 }
    //             }
    //         }
    //         idx++;
    //     }
    //     return unpaired;
    // }


    int minInsertions(string s) {
        int opening = 0, pairing = 0;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                opening++;
            } else {
                if(i+1 < s.length() && s[i+1] == ')') {
                    i++;
                } else {
                    pairing++;
                }

                if(opening > 0) {
                    opening--;
                } else {
                    pairing++;
                }
            }
        }
        pairing += 2 * opening;

        return pairing;
    }
};