# 存储左括号和又括号
open_brackets = '([{<'
close_brackets = ')]}>'
# 映射左右括号便于出栈判断
brackets_map = {')': '(', ']': '[', '}': '{', '>': '<'}

# 对于没一行数据，进行如下判定若括号为左括号，加入栈，若括号为右括号，判断是否跟栈尾括号对应，若对应，弹出栈尾元素，若所有括号均正确闭合，则最后栈为空。
for row in rows:
    stack = []
    label = True
    for char in row:
        if char in open_brackets:
            stack.append(char)
        elif char in close_brackets:
            if len(stack) < 1:
                label = False
                break
            elif brackets_map[char] == stack[-1]:
                stack.pop()
            else:
                label = False
                break
        else:
            continue
    if stack != []:
        label = False
    print label
