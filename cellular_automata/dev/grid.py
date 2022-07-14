# GRID CLASS

from cell import Cell
from hyperparameters import Hyperparameters as h

class Grid:
	'''
	'''
	def __init__(self) -> None:
		self.grid = [[Cell(init = True) for _ in range(0, h.DIM)] for _ in range(0, h.DIM)]

	def check_neighbors(self, border: bool) -> None:
		if border == True:
			for i in range(1, h.DIM - 1):
				for j in range(1, h.DIM - 1):
					if self.grid[i - 1][j - 1].state == 1: self.grid[i][j].neighbors += 1
					if self.grid[i - 1][j + 0].state == 1: self.grid[i][j].neighbors += 1
					if self.grid[i - 1][j + 1].state == 1: self.grid[i][j].neighbors += 1
					if self.grid[i + 0][j - 1].state == 1: self.grid[i][j].neighbors += 1
					if self.grid[i + 0][j + 1].state == 1: self.grid[i][j].neighbors += 1
					if self.grid[i + 1][j - 1].state == 1: self.grid[i][j].neighbors += 1
					if self.grid[i + 1][j + 0].state == 1: self.grid[i][j].neighbors += 1
					if self.grid[i + 1][j + 1].state == 1: self.grid[i][j].neighbors += 1

	def eval_state(self) -> None:
		grid_copy = [[Cell(init = False) for _ in range(0, h.DIM)] for _ in range(0, h.DIM)]
		self.check_neighbors(border = True)
		for row in range(1, h.DIM - 1):
			for col in range(1, h.DIM - 1):
				if self.grid[row][col].neighbors < 2 and self.grid[row][col].state == 1: 
					grid_copy[row][col].state = 0
				elif (self.grid[row][col].neighbors == 2 or self.grid[row][col].neighbors == 3) and self.grid[row][col].state == 1: 
					grid_copy[row][col].state = 1
				elif self.grid[row][col].neighbors > 3 and self.grid[row][col].state == 1: 
					grid_copy[row][col].state = 0
				elif self.grid[row][col].neighbors == 3 and self.grid[row][col].state == 0: 
					grid_copy[row][col].state = 1
				else: pass
		self.grid = grid_copy


if __name__ == "__main__":
	pass