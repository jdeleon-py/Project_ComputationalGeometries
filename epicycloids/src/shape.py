# SHAPE FEATURE BASE CLASS

from point import Point
from hyperparameters import Hyperparameters as h

class Shape:
	'''
	** BASE CLASS **

	METHODS:
		- ability to define a group of Point objects arranged in a shape

	ATTRIBUTES:
		- adjustable window size
		- adjustable number of point objects representing the shape
		- adjustable radius of the shape
			- consists of a coefficient representing how 
				much of the window is occupied by the shape
		- array of Point objects with determined r and theta values
	'''
	ANGLE_MAX = 360
	SCALE = 0.3

	def __init__(self) -> None:
		self.dimension = h.DIM
		self.point_num = h.POINT_NUM
		self.radius = Shape.SCALE * self.dimension
		self.points = self.define_points()

	def define_points(self) -> list:
		'''
		- defines the angle increment based on the number of
			Point objects in the array of points
		- returns a list of Point objects with calculated angle and radius 
		'''
		angle_increment = Shape.ANGLE_MAX / self.point_num
		return [Point(i, self.radius, angle_increment * i) for i in range(0, self.point_num)]


if __name__ == "__main__":
	pass

