

class Solution {
private:
    // Helper function to check if a character is a vowel.
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

public:
    // Function to sort vowels in a string and maintain the original order of non-vowel characters.
    string sortVowels(string s) {
        string t = "";        // Resulting string after sorting vowels.
        string temp = "";     // Temporary string to store vowels from the original string.

        // Step 1: Extract and store vowels from the original string in temporary string 'temp'.
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                temp += s[i];
            }
        }

        // Step 2: Sort the temporary string 'temp' containing vowels.
        sort(temp.begin(), temp.end());

        int j = 0;
        // Step 3: Reconstruct the resulting string 't' by inserting sorted vowels and maintaining the order of non-vowel characters.
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                t += temp[j];
                j++;
            } else {
                t += s[i];
            }
        }

        // Step 4: Return the final sorted string.
        return t;
    }
};

