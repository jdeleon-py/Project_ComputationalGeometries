# GRID CLASS

import json
from cell import Cell

class Grid:
	'''
	DESCRIPTION:
		- sets all cell objects up as a grid
		- cell rules follow that of John Conway's Game of Life

	METHODS:
		- ability to read out preset parameters set up
			by the json parameters file
		- ability to check the state of each cell's neightbors (Moore)
		- ability to define cell rules for underpopulation
		- ability to define cell rules for overpopulation
		- ability to define cell rules for birth
		- ability to define cell rules for survival
		- ability to update a cell's state based on rules described

	ATTRIBUTES:
		- parameter dictionary
		- 2D list of cell objects encapsulating the grid
	'''
	def __init__(self) -> None:
		self.params = self.define_params()
		self.grid = [[Cell(init = True) for _ in range(0, self.params["DIM"])] for _ in range(0, self.params["DIM"])]

	def define_params(self) -> dict:
		'''
		- reads parameter json file and loads dict data
		'''
		with open("parameters.json", 'r') as file:
			data = json.load(file)
		file.close()
		return data 

	def check_neighbors(self, i, j, border: bool) -> None:
		'''
		- checks based on the Moore Neighborhood
		- checks 8 adjacent neighbors of current cell object
		- counts how many of these adjacent cells are "alive" (state == 1)
		'''
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
		'''
		- returns bool if the cell is alive and has less than 2 alive neighbors
		'''
		return self.grid[i][j].neighbors < 2 and self.grid[i][j].state == 1

	def survival_rule(self, i: int, j: int) -> bool:
		'''
		- returns bool if the cell is alive and has 2 or 3 alive neighbors
		'''
		return self.grid[i][j].neighbors in [2, 3] and self.grid[i][j].state == 1

	def overpopulation_rule(self, i: int, j: int) -> bool:
		'''
		- returns bool if the cell is alive and has more than 3 alive neighbors
		'''
		return self.grid[i][j].neighbors > 3 and self.grid[i][j].state == 1

	def birth_rule(self, i: int, j: int) -> bool:
		'''
		- returns bool if the cell is dead and has exactly 3 alive neighbors
		'''
		return self.grid[i][j].neighbors == 3 and self.grid[i][j].state == 0

	def eval_state(self) -> None:
		'''
		- copies the grid, then replaces the original as the next iteration
		- if condiitons are right for underpopulation, the cell dies
		- if conditiona are right for overpopulation, the cell dies
		- if conditions are right for birth, the cell turns alive
		- if conditions are right for survival, the cell stays alive
		'''
		grid_copy = [[Cell(init = False) for _ in range(0, self.params["DIM"])] for _ in range(0, self.params["DIM"])]
		for row in range(1, self.params["DIM"] - 1):
			for col in range(1, self.params["DIM"] - 1):
				self.check_neighbors(row, col, border = True)
				if self.underpopulation_rule(row, col) == True: grid_copy[row][col].state = 0
				elif self.survival_rule(row, col) == True: grid_copy[row][col].state = 1
				elif self.overpopulation_rule(row, col) == True: grid_copy[row][col].state = 0
				elif self.birth_rule(row, col) == True: grid_copy[row][col].state = 1
				else: pass
		self.grid = grid_copy


if __name__ == "__main__":
	pass
