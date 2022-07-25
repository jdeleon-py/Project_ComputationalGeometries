# SHAPE FEATURE BASE CLASS

from point import Point
from hyperparameters import Hyperparameters as h

class Shape:
	'''
	'''
	ANGLE_MAX = 360
	SCALE = 0.3

	def __init__(self) -> None:
		self.dimension = h.DIM
		self.point_num = h.POINT_NUM
		self.radius = Shape.SCALE * self.dimension
		self.points = self.define_points()

	def define_points(self) -> list:
		angle_increment = Shape.ANGLE_MAX / self.point_num
		return [Point(i, self.radius, angle_increment * i) for i in range(0, self.point_num)]


if __name__ == "__main__":
	pass

