/*
 * MatchingPair.cpp
 *
 *  Created on: May 6, 2016
 *      Author: gaohan
 */
/* Matching pairs
 * You are given a String, input, comprised of alphabetical letters with varying case.
 * These letters should create pairs with one another, based on case. For example, the letter 'N forms a "matching pair' with the letter 'a', in that order.
 * Rules:
 * 1. The first letter must be upper-case.
 * 2. Every upper-case letter must be followed by its lower-case version or any upper-case letter.
 * 3. When an upper-case letter is followed by its lower-case version, those two letters are considered a "matching pair and can then be disregarded from further match consideration.
 * 4. If any of these rules are broken or a lower-case letter is encountered that does not create a "matching pair' with its nearest un-matched left neighbour, that letter and all following letters are considered "un-matched".
 * Output: Your method should return the zero-based index of the last matching lower-case letter, or -1 if no pairs exist.
 * Limits: 0 < input length < 10,000 characters The optimal method has a running time of O(input length).
 * Sample input #1
 * ABba
 * Sample output #1
 * 3
 */

#include <string>
#include <stack>
using namespace std;

class MatchingPair {
public:
	int matchingpairs(const string& str) {
		if (!isUpperCase(str.at(0)) || str.size() == 0)
			return -1;
		stack<char> stack;
		stack.push(str.at(0));
		int res = 0;
		for (int i = 1; i < str.size(); i++) {
			if (!isUpperCase(str.at(i))) {
				char c = stack.top();
				if (c - 32 == str.at(i)) {
					stack.pop();
					res = i;
				} else
					return res;
			} else {
				stack.push(str.at(i));
			}
		}
		if (stack.empty())
			return str.size() - 1;
		else
			return res;
	}

	bool isUpperCase(char ch) {
		string str = "ABCDEFGHIGKLMNOPQRSTUVWXYZ";
		int pos = str.find(ch);
		if (pos >= 0 && pos < 26)
			return true;
		else
			return false;
	}
};
