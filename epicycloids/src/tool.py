# TURTLE DRAWING TOOL CLASS

from turtle import Turtle, Screen
from circle import Circle
from cycloid import Cycloid
from hyperparameters import Hyperparameters as h

class Tool:
	'''
	'''
	def __init__(self) -> None:
		self.turtle = Turtle()
		self.screen = Screen()
		self.turtle.speed(0)
		self.screen.setup(h.DIM, h.DIM)
		self.circle = Circle()
		self.cycloid = Cycloid(multiplier = h.MULTIPLIER)

	def run(self) -> None:
		self.circle.draw(self.turtle)
		self.cycloid.draw(self.turtle)
		delay = input("Press enter to exit")


if __name__ == "__main__":
	tool = Tool()
	tool.run()
