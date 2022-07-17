# GRID CLASS

from cell import Cell
from hyperparameters import Hyperparameters as h

class Grid:
	'''
	'''
	def __init__(self) -> None:
		self.grid = [[Cell(init = True) for _ in range(0, h.DIM)] for _ in range(0, h.DIM)]

	def check_neighbors(self, i, j, border: bool) -> None:
		if border == True:
			if self.grid[i - 1][j - 1].state == 1: self.grid[i][j].neighbors += 1
			if self.grid[i - 1][j + 0].state == 1: self.grid[i][j].neighbors += 1
			if self.grid[i - 1][j + 1].state == 1: self.grid[i][j].neighbors += 1
			if self.grid[i + 0][j - 1].state == 1: self.grid[i][j].neighbors += 1
			if self.grid[i + 0][j + 1].state == 1: self.grid[i][j].neighbors += 1
			if self.grid[i + 1][j - 1].state == 1: self.grid[i][j].neighbors += 1
			if self.grid[i + 1][j + 0].state == 1: self.grid[i][j].neighbors += 1
			if self.grid[i + 1][j + 1].state == 1: self.grid[i][j].neighbors += 1

	def underpopulation_rule(self, i: int, j: int) -> bool:
		return self.grid[i][j].neighbors < 2 and self.grid[i][j].state == 1

	def survival_rule(self, i: int, j: int) -> bool:
		return self.grid[i][j].neighbors in [2, 3] and self.grid[i][j].state == 1

	def overpopulation_rule(self, i: int, j: int) -> bool:
		return self.grid[i][j].neighbors > 3 and self.grid[i][j].state == 1

	def birth_rule(self, i: int, j: int) -> bool:
		return self.grid[i][j].neighbors == 3 and self.grid[i][j].state == 0

	def eval_state(self) -> None:
		grid_copy = [[Cell(init = False) for _ in range(0, h.DIM)] for _ in range(0, h.DIM)]
		for row in range(1, h.DIM - 1):
			for col in range(1, h.DIM - 1):
				self.check_neighbors(row, col, border = True)
				if self.underpopulation_rule(row, col) == True: grid_copy[row][col].state = 0
				elif self.survival_rule(row, col) == True: grid_copy[row][col].state = 1
				elif self.overpopulation_rule(row, col) == True: grid_copy[row][col].state = 0
				elif self.birth_rule(row, col) == True: grid_copy[row][col].state = 1
				else: pass
		self.grid = grid_copy


if __name__ == "__main__":
	pass