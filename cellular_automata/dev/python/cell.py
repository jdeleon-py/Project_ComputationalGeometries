# CELL PIXEL CLASS

import json
import random

class Cell:
	'''
	DESCRIPTION:
		- classifies a cell on a grid of cells

	METHODS:
		- ability to preset certain parameters based on
			the parameters json file
		- ability to define an initial state for the cell (0, 1)
		- ability to define a color for the cell based on its state

	ATTRIBUTES:
		- init boolean, which determines whether the cell is 
			first initialized or iteratively updated
		- parameter dictionary
		- state boolean (0, 1)
		- color coordinate tuple (R, G, B)
		- a counter for the cell's number of alive neighbors
	'''
	def __init__(self, init: bool) -> None: 
		self.init = init
		self.params = self.define_params()
		self.state = self.define_state()
		self.color = self.define_color()
		self.neighbors = 0

	def define_params(self) -> dict:
		'''
		- reads parameter json file and loads dict data
		'''
		with open("parameters.json", 'r') as file:
			data = json.load(file)
		file.close()
		return data

	def define_state(self) -> int:
		'''
		- randomly assigns an initial state for the cell
		- if state == 1: "alive"
		- if state == 0: "dead"
		'''
		return random.choice([0, 1]) if self.init else 0

	def define_color(self) -> tuple:
		'''
		- defines a color based on the cell's state
		- white if state == 1
		- black if state == 0
		'''
		return (255, 255, 255) if self.state == 1 else (0, 0, 0)


if __name__ == "__main__":
	pass
