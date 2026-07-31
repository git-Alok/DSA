class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq_of_char(26,0);
        unsigned int size_of_str = word.size();

        // frequency store
        for(int character=0; character<size_of_str; character++){
           freq_of_char[word[character]-'a']++;
        }

        // sort in decreasing order
        sort(freq_of_char.begin(),freq_of_char.end());
        reverse(freq_of_char.begin(),freq_of_char.end());

        unsigned int min_num_of_pushes = 0;

        for(int i=0;i<8;i++){
            min_num_of_pushes+=(freq_of_char[i]);
        }
        for(int i=8;i<16;i++){
            min_num_of_pushes+=(freq_of_char[i]*2);
        }
        for(int i=16;i<24;i++){
            min_num_of_pushes+=(freq_of_char[i]*3);
        }
        for(int i=24;i<26;i++){
            min_num_of_pushes+=(freq_of_char[i]*4);
        }
return min_num_of_pushes;



    }
};