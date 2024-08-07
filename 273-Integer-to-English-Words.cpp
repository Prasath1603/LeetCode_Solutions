class Solution {
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four",
                           "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen",
                            "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                            "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion", "Trillion", "Quadrillion", "Quintillion"};

    string helper(int num) {
        if (num == 0)
            return "";
        else if (num < 10)
            return ones[num];
        else if (num < 20)
            return teens[num - 10];
        else if (num < 100)
            return tens[num / 10] + (num % 10 ? " " + ones[num % 10] : "");
        else if (num < 1000)
            return ones[num / 100] + " Hundred" +
                   (num % 100 ? " " + helper(num % 100) : "");
        return "";
    }

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string res;
        int thousand = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                res = helper(num % 1000) +
                      (thousand ? " " + thousands[thousand] : "") +
                      (res.empty() ? "" : " " + res);
            }
            num /= 1000;
            thousand++;
        }
        return res;
    }
};