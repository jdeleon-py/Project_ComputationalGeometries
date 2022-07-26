# CIRCLE GEOMETRY DATA (DERIVED) CLASS

from shape import Shape

class Circle(Shape):
	'''
	** DERIVED CLASS TO SHAPE **

	METHODS:
		- ability to draw each Point object on a canvas

	ATTRIBUTES:
		- inherited attributes of the Shape object
	'''
	def __init__(self) -> None:
		Shape.__init__(self)

	def draw(self, tool: object) -> None:
		'''
		- this draw function takes the shape of a circle
		- this draw function draws every Point object onto a canvas
		'''
		tool.hideturtle()
		for point in self.points:
			tool.penup()
			tool.goto(point.coordinates)
			tool.pendown()
			point.draw(tool)


if __name__ == "__main__":
	from turtle import Turtle, Screen
	circle = Circle(point_num = 300)
	for point in circle.points: print('{}'.format(point))

	t = Turtle()
	screen = Screen()
	screen.setup(h.DIM, h.DIM)
	circle.draw(tool = t)
	inp = input('Press enter to exit')
