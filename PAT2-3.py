'''
算术表达式有前缀表示法、中缀表示法和后缀表示法等形式。前缀表达式指二元运算符位于两个运算数之前，例如2+3*(7-4)+8/4的前缀表达式是：+ + 2 * 3 - 7 4 / 8 4。请设计程序计算前缀表达式的结果值。

输入格式说明：

输入在一行内给出不超过30个字符的前缀表达式，只包含+、-、*、\以及运算数，不同对象（运算数、运算符号）之间以空格分隔。

输出格式说明：

输出前缀表达式的运算结果，精确到小数点后1位，或错误信息“ERROR”。

样例输入与输出：

序号	输入	输出
1	
+ + 2 * 3 - 7 4 / 8 4
13.0
2	
/ -25 + * - 2 3 4 / 8 4
12.5
3	
/ 5 + * - 2 3 4 / 8 2
ERROR
4	
+10.23
10.2

'''
import string

expression = raw_input()
elems = expression.split()

class Stack(object):
	"""docstring for Stack"""
	def __init__(self):
		self.s = []

	def push(self, elem):
		self.s.append(elem)

	def pop(self):
		return self.s.pop()

	def isEmpty(self):
		if self.s:
			return False
		else:
			return True

s = Stack()

def exp():
	for elem in elems[::-1]:
		try:
			if elem == '+':
				s.push(s.pop() + s.pop())
			elif elem == '-':
				s.push(s.pop() - s.pop())
			elif elem == '*':
				s.push(s.pop() * s.pop())
			elif elem == '/':
				s.push(s.pop() / s.pop())
			else:
				s.push(string.atof(elem))
		except:
			return 'ERROR'
	if s.isEmpty():
		return 'ERROR'
	else:
		return round(s.pop(), 1)
print exp()

