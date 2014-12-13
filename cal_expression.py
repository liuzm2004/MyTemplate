# -*- coding: utf-8 -*-
"""
Created on Sat Dec 13 16:27:27 2014
计算后缀表达式
@author: liuzm
"""

import string

expression = raw_input()
elems = expression.split()

class Stack(object):
	"""docstring for Stack"""
	def __init__(self):
		self.s = []

	def push(self, elem):
		self.s.append(elem)

	def pop(self, arg = -1):
		return self.s.pop(arg)

	def isEmpty(self):
		if self.s:
			return False
		else:
			return True

s = Stack()

def exp():
	for elem in elems[:]:
		try:
			if elem == '+':
				s.push(s.pop(-2) + s.pop())
			elif elem == '-':
				s.push(s.pop(-2) - s.pop())
			elif elem == '*':
				s.push(s.pop(-2) * s.pop())
			elif elem == '/':
				s.push(s.pop(-2) / s.pop())
			else:
				s.push(string.atof(elem))
		except:
			return 'ERROR'
	if s.isEmpty():
		return 'ERROR'
	else:
		return round(s.pop(), 1)
print exp()
