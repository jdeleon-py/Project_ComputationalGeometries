# SECTOR BOUNDARY CLASS

from point import Point

class Sector:
	'''
	'''
	def __init__(self, center: object, half_dim: float) -> None:
		self.center = center
		self.half_dim = half_dim

	def contains_point(self, point: object) -> bool:
		pass

	def intersects(self, boundary: object) -> bool:
		pass


if __name__ == "__main__":
	pass