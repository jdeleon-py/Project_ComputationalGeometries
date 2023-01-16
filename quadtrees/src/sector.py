# SECTOR BOUNDARY CLASS

class Sector:
	'''
	DESCRIPTION:
		-

	METHODS:
		-

	ATTRIBUTES:
		-
	'''
	def __init__(self, center: tuple, radius: int) -> None:
		self.center = center
		self.radius = radius


	def __str__(self) -> str:
		return "Center: {0}, Radius: {1}".format(self.center, self.radius)


	def contains_point(self, point: object) -> bool:
		'''
		'''
		x_cond = (point.x < (self.center[0] + self.radius)) and (point.x > (self.center[0] - self.radius))
		y_cond = (point.y < (self.center[1] + self.radius)) and (point.y > (self.center[1] - self.radius))
		return True if (x_cond and y_cond) else False


	def intersects(self, boundary: object) -> bool:
		pass


if __name__ == "__main__":
	pass
