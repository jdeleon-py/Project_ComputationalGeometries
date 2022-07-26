# TURTLE DRAWING TOOL CLASS

from turtle import Turtle, Screen
from circle import Circle
from cycloid import Cycloid
from hyperparameters import Hyperparameters as h

class Tool:
	'''
	METHODS:
		- ability to run through the drawing process
			- draws either a circle object and/or a 
				cycloid object onto a canvas

	ATTRIBUTES:
		- turtle drawing object
		- screen specifier object
		- circle object with parameters user-specified
		- cycloid object with parameters user-specified
	'''
	def __init__(self) -> None:
		self.turtle = Turtle()
		self.screen = Screen()
		self.turtle.speed(0)
		self.screen.setup(h.DIM, h.DIM)
		self.circle = Circle()
		self.cycloid = Cycloid(multiplier = h.MULTIPLIER)

	def run(self) -> None:
		'''
		- draws the cycloid object
		- draws the circle object if user-specified
		'''
		if h.REF_CIR == True: self.circle.draw(self.turtle)
		self.cycloid.draw(self.turtle)
		delay = input("Press enter to exit")


if __name__ == "__main__":
	tool = Tool()
	tool.run()
