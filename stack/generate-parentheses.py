from typing import List

class Solution:

    def generateParenthesis(self, n: int) -> List[str]:
        open = ['('] * n
        close = []
        res = []

        self.gen_tree("", open, close, res)
        
        return res

    @classmethod
    def gen_tree(cls, current_string, current_open, current_close, res):
        if len(current_open) == 0 and len(current_close) == 0:
            res.append(current_string)
            return

        current_string_copy = current_string
        current_open_copy = current_open.copy()
        current_close_copy = current_close.copy()

        if current_open:
            current_open.pop()
            current_close.append(')')
            current_string += '('
            cls.gen_tree(current_string, current_open, current_close, res)

        if current_close_copy:
            current_close_copy.pop()
            current_string_copy += ')'
            cls.gen_tree(current_string_copy, current_open_copy, current_close_copy, res)

        
if __name__ == "__main__":
    n = 1

    soln = Solution()
    print(soln.generateParenthesis(3))
    print(soln.generateParenthesis(1))

