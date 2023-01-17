# EDGE CLASS

import math
from point import Point

class Edge:
	'''
	'''
	def __init__(self, p1: object, p2: object, start_x: bool) -> None:
		self.m = -(p1.x - p2.x) / (p1.y - p2.y)
		self.q = (0.5 * (p1.x ** 2 - p2.x ** 2 + p1.y ** 2 - p2.y ** 2)) / (p1.y - p2.y)
		self.arc = None
		self.end = None
		self.start = None
		if start_x: self.start = Point(x = start_x, y = self.getY(x = start_x))


	def getX(self, y) -> float:
		'''
		'''
		if self.m == math.inf: return self.start.x
		return (y - self.q) / self.m


	def getY(self, x) -> float:
		'''
		'''
		if self.m == math.inf: return None
		return (x * self.m) + self.q



if __name__ == "__main__":
	pass