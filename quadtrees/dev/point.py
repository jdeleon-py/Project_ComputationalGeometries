# POINT (SITE) CLASS

class Point:
	'''
	'''
	def __init__(self, x: int, y: int) -> None:
		self.x = x
		self.y = y
		self.coordinates = tuple([self.x, self.y])

	def __str__(self) -> str:
		return "Coordinates: {0}".format(self.coordinates)

	def draw_point(self, tool: object, surface: object) -> None:
		tool.circle(surface = surface, 
					color = (255, 255, 255), 
					center = self.coordinates, 
					radius = 3
		)


if __name__ == "__main__":
	pass