# SHAPE FEATURE BASE CLASS

import json
from point import Point

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
		self.params = self.define_params()
		self.dimension = self.params["Window Dimension"]
		self.point_num = self.params["Number of Points"]
		self.radius = Shape.SCALE * self.dimension
		self.points = self.define_points()

	def define_params(self) -> dict:
		'''
		- extracts the hyperparameter json file that 
			specifies conditions of the simulation
		'''
		with open("parameters.json", 'r') as file:
			data = json.load(file)
		file.close()
		return data

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

