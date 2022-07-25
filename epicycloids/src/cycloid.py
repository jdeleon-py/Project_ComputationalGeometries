# CYCLOID CONSTRUCTION (DERIVED) CLASS

from shape import Shape
from hyperparameters import Hyperparameters as h

class Cycloid(Shape):
	'''
	'''
	def __init__(self, multiplier) -> None:
		Shape.__init__(self, h.DIM, h.POINT_NUM)
		self.multiplier = multiplier

	def solve_product(self, index: int) -> int:
		return (self.multiplier * index) % self.point_num

	def draw(self, tool: object) -> None:
		tool.hideturtle()
		for current_point in range(0, len(self.points)):
			index = self.points[current_point].index
			prod = self.solve_product(index = index)
			tool.penup()
			tool.goto(self.points[current_point].coordinates)
			tool.pendown()
			tool.goto(self.points[prod].coordinates)


if __name__ == "__main__":
	from turtle import Turtle, Screenx
	cardioid = Cycloid(multiplier = h.MULTIPLIER)
	t = Turtle()
	t.speed(0)
	screen = Screen()
	screen.setup(h.DIM, h.DIM)
	cardioid.draw(t)
	delay = input("Press enter to exit")
