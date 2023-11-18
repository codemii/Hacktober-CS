// time O(n) | space O(n)
var isValid = function (s) {
  const stack = [];

  const brackets = {
    '(': ')',
    '[': ']',
    '{': '}',
  };

  for (const char of s) {
    if (char in brackets) {
      stack.push(brackets[char]);
    } else if (stack.length && stack[stack.length - 1] === char) {
      stack.pop();
    } else {
      return false;
    }
  }

  return !stack.length;
};
