# CELL PIXEL CLASS

import random
from hyperparameters import Hyperparameters as h

class Cell:
	'''
	'''
	def __init__(self, init: bool) -> None: 
		self.init = init
		self.state = self.define_state()
		self.color = self.define_color()
		self.neighbors = 0

	def define_state(self):
		return random.choice([0, 1]) if self.init else 0

	def define_color(self) -> tuple:
		return h.WHITE if self.state == 1 else h.BLACK


if __name__ == "__main__":
	pass