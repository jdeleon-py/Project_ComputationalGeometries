# POINT COORDINATES DATA CLASS

import math

class Point:
	'''
	'''
	FIGURES = 5

	def __init__(self, index: int, r: float, theta: float) -> None:
		self.index = index
		self.r = r
		self.theta = theta
		self.x, self.y = self.solve_cartesian()
		self.coordinates = (self.x, self.y)

	def __str__(self) -> str:
		return 'x: {0}, y: {1}'.format(self.x, self.y)

	def solve_cartesian(self) -> [float, float]:
		x = round(self.r * solve_deg(self.theta, mode = 'cos'), Point.FIGURES)
		y = round(self.r * solve_deg(self.theta, mode = 'sin'), Point.FIGURES)
		return x, y

	def draw(self, tool: object) -> None: tool.dot(5)

def solve_deg(rad: float, mode: str) -> float:
	deg = rad * (math.pi / 180)
	return math.cos(deg) if mode == 'cos' else math.sin(deg)


if __name__ == "__main__":
	print('{}'.format(Point(index = 0, r = 1.41421, theta = 45)))