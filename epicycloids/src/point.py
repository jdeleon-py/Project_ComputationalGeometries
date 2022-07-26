# POINT COORDINATES DATA CLASS

import math

class Point:
	'''
	METHODS:
		- ability to radout the cartesian coordinates of the point
		- ability to determine the cartesian coordinates of the point
			given the point's polar coordinates (r, theta)
		- ability to draw the point using a given drawing tool (turtle)

	- HELPER FUNCTIONS: 
		- ability to convert from radians to degrees

	ATTRIBUTES:
		- argument index specifying where in a 'points' array this 
			point is located
		- argument representing the polar coordinate 'radius' 
			where this point is located
		- argument representing the polar coordinate 'angle' from the 
			origin where this point is located
	'''
	FIGURES = 5

	def __init__(self, index: int, r: float, theta: float) -> None:
		self.index = index
		self.r = r
		self.theta = theta
		self.coordinates = tuple(self.solve_cartesian())

	def __str__(self) -> str:
		'''
		- reads out the cartesian coordinate conversion given the 
			point's polar coordinates
		'''
		return 'x: {0}, y: {1}'.format(self.coordinates[0], self.coordinates[1])

	def solve_cartesian(self) -> [float, float]:
		'''
		- follows the polar -> cartesian conversion
			- x = r * cos(theta)
			- y = r * sin(theta)
		- rounds the conversion to a specified figure precision
		'''
		x = round(self.r * solve_deg(self.theta, mode = 'cos'), Point.FIGURES)
		y = round(self.r * solve_deg(self.theta, mode = 'sin'), Point.FIGURES)
		return x, y

	def draw(self, tool: object) -> None:
		'''
		- draws a point with a hardcoded weight
		- follows the 'turtle' library, but can be adjusted 
			for any [faster] graphics library with ease
		'''
		tool.dot(5)

def solve_deg(rad: float, mode: str) -> float:
	'''
	- helper function
	- converts a given radian to its corresponding degree
	- computes either the 'sin' or 'cos' of the resultant degree
		given the specified mode of calculation
	'''
	deg = rad * (math.pi / 180)
	return math.cos(deg) if mode == 'cos' else math.sin(deg)


if __name__ == "__main__":
	print('{}'.format(Point(index = 0, r = 1.41421, theta = 45)))
