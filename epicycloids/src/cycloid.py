# CYCLOID CONSTRUCTION (DERIVED) CLASS

from shape import Shape

class Cycloid(Shape):
	'''
	** DERIVED CLASS TO SHAPE **

	METHODS:
		- ability to calculate the product of the current 
			index and specified multiplier modulo the number 
			of Point objects specified
		- ability to draw a number of lines from the 
			iterating index to the index's corresponding product

	ATTRIBUTES:
		- specified multiplier constant 
			- (multiplier specifies the times tables to follow)
		- inherited attributes of the Shape object
	'''
	def __init__(self, multiplier) -> None:
		Shape.__init__(self)
		self.multiplier = multiplier

	def solve_product(self, index: int) -> int:
		'''
		- ** essential function for this project **
		- within reference of the number of Point objects that exist (modulo)
			the current index will follow the <multiplier> times tables
			and then compute the corresponding product
		'''
		return (self.multiplier * index) % self.point_num

	def draw(self, tool: object) -> None:
		'''
		- this draw function takes the shape of an epicycloid pattern
		- this draw function iterates through every Point object,
			thus drawing a line from the current Point object to 
			the result product matching a Point object's index
		'''
		tool.hideturtle()
		for current_point in range(0, len(self.points)):
			index = self.points[current_point].index
			prod = self.solve_product(index = index)
			tool.penup()
			tool.goto(self.points[current_point].coordinates)
			tool.pendown()
			tool.goto(self.points[prod].coordinates)


if __name__ == "__main__":
	from turtle import Turtle, Screen
	cardioid = Cycloid(multiplier = h.MULTIPLIER)
	t = Turtle()
	t.speed(0)
	screen = Screen()
	screen.setup(h.DIM, h.DIM)
	cardioid.draw(t)
	delay = input("Press enter to exit")
