# TURTLE DRAWING TOOL CLASS

import json
from turtle import Turtle, Screen
from circle import Circle
from cycloid import Cycloid

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
		self.params = self.define_params()
		self.turtle = Turtle()
		self.screen = Screen()
		self.turtle.speed(0)
		self.screen.setup(self.params["Window Dimension"],
						  self.params["Window Dimension"]
		)
		self.circle = Circle()
		self.cycloid = Cycloid(multiplier = self.params["Multiplier"])

	def define_params(self) -> dict:
		'''
		- extracts the hyperparameters json file that
			specifies conditions of the simulation
		'''
		with open("parameters.json", 'r') as file:
			data = json.load(file)
		file.close()
		return data

	def run(self) -> None:
		'''
		- draws the cycloid object
		- draws the circle object if user-specified
		'''
		if self.params["Reference Circle"] == True:
			self.circle.draw(self.turtle)
		self.cycloid.draw(self.turtle)
		delay = input("Press enter to exit")


if __name__ == "__main__":
	tool = Tool()
	tool.run()
