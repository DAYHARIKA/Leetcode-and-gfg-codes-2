class Solution {
public:
    vector<string> addOperators(string num, int target) {
    vector<string> results;

    // Internal recursive function to build expressions
    function<void(int, long, long, string)> build = [&](int index, long eval, long last, string expr) {
        if (index == num.size()) {
            if (eval == target) {
                results.push_back(expr);
            }
            return;
        }

        for (int j = index; j < num.size(); ++j) {
            // Prevent numbers like "05", "00" etc.
            if (j > index && num[index] == '0') break;

            string current = num.substr(index, j - index + 1);
            long value = stol(current);

            if (index == 0) {
                // First number, just start the expression
                build(j + 1, value, value, current);
            } else {
                // Addition
                build(j + 1, eval + value, value, expr + '+' + current);
                // Subtraction
                build(j + 1, eval - value, -value, expr + '-' + current);
                // Multiplication (handle precedence)
                build(j + 1, eval - last + last * value, last * value, expr + '*' + current);
            }
        }
    };

    // Start recursion
    build(0, 0, 0, "");
    return results;
}

};