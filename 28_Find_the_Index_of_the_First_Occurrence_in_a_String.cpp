// Solution 1
class Solution {
    int check_substring(string str1, string str2)
{   int i,j;
    int len1 = str1.length();
    int len2 = str2.length();
 
    for (i = 0; i <= len2 - len1; i++) {
        for (j = 0; j < len1; j++)
            if (str2[i + j] != str1[j])
                break;
 
        if (j == len1)
            return i;
    }
 
    return -1;
}
public:
    int strStr(string haystack, string needle) {
        int position = check_substring(needle, haystack);
        return position;
    }
};

//Solution 2 using find() function in c++:

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);

        return found;
    }
};
