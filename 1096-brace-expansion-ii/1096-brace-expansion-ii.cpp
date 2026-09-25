class Solution {
public:

    string s;
    int i = 0;

    set<string> combine(set<string>& A, set<string>& B) {
        set<string> result;

        for (const string& a : A) {
            for (const string& b : B) {
                result.insert(a + b);
            }
        }

        return result;
    }

    // Expression = Term (, Term)*
    set<string> parseExpression() {

        set<string> result = parseTerm();

        while (i < s.size() && s[i] == ',') {
            i++; // skip ','

            set<string> next = parseTerm();

            result.insert(next.begin(), next.end());
        }

        return result;
    }

    // Term = Factor*
    set<string> parseTerm() {

        set<string> result = {""};

        while (i < s.size() &&
               s[i] != '}' &&
               s[i] != ',') {

            set<string> next = parseFactor();

            result = combine(result, next);
        }

        return result;
    }

    // Factor = letter | { Expression }
    set<string> parseFactor() {

        if (s[i] == '{') {

            i++; // skip '{'

            set<string> result = parseExpression();

            i++; // skip '}'

            return result;
        }

        // lowercase letter
        string str(1, s[i]);

        i++;

        return {str};
    }

    vector<string> braceExpansionII(string expression) {

        s = expression;
        i = 0;

        set<string> result = parseExpression();

        return vector<string>(result.begin(), result.end());
    }
};