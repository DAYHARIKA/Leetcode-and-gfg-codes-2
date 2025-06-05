class Solution {
public:
    void exploreCombinations(
    const string& digits,
    int target,
    vector<string>& expressions,
    int pos,
    long accumulated,
    long previous,
    string currentExpr
) {
    if (pos == digits.size()) {
        if (accumulated == target) {
            expressions.push_back(currentExpr);
        }
        return;
    }

    for (int i = pos; i < digits.size(); ++i) {
        // Avoid numbers with leading zero
        if (i > pos && digits[pos] == '0') break;

        string part = digits.substr(pos, i - pos + 1);
        long num = stol(part);

        if (pos == 0) {
            // First number, initialize
            exploreCombinations(digits, target, expressions, i + 1, num, num, part);
        } else {
            // Try with +
            exploreCombinations(digits, target, expressions, i + 1, accumulated + num, num, currentExpr + "+" + part);
            // Try with -
            exploreCombinations(digits, target, expressions, i + 1, accumulated - num, -num, currentExpr + "-" + part);
            // Try with *
            exploreCombinations(
                digits,
                target,
                expressions,
                i + 1,
                accumulated - previous + (previous * num),
                previous * num,
                currentExpr + "*" + part
            );
        }
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> output;
    exploreCombinations(num, target, output, 0, 0, 0, "");
    return output;
}

};