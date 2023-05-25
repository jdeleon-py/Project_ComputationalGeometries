# SECTOR (BOUNDARY) CLASS

from corner import Corner

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
		self.define_corners()

	def __str__(self) -> str:
		return "Center: {0}, Radius: {1}".format(self.center, self.radius)

	def define_corners(self) -> None:
		'''
		'''
		self.nw_corner = Corner(x = self.center[0] - self.radius - 0, y = self.center[1] - self.radius - 0)
		self.ne_corner = Corner(x = self.center[0] + self.radius - 1, y = self.center[1] - self.radius - 0)
		self.sw_corner = Corner(x = self.center[0] - self.radius - 0, y = self.center[1] + self.radius - 1)
		self.se_corner = Corner(x = self.center[0] + self.radius - 1, y = self.center[1] + self.radius - 1)

	def corner_scan(self, points: [object]) -> None:
		for point in points:
			dist_nw = self.nw_corner.distance(self.nw_corner, point)
			if dist_nw < self.nw_corner.minimum_distance: 
				self.nw_corner.closest_point = point
				self.nw_corner.minimum_distance = dist_nw
			dist_ne = self.ne_corner.distance(self.ne_corner, point)
			if dist_ne < self.ne_corner.minimum_distance:
				self.ne_corner.closest_point = point
				self.ne_corner.minimum_distance = dist_ne
			dist_sw = self.sw_corner.distance(self.sw_corner, point)
			if dist_sw < self.sw_corner.minimum_distance:
				self.sw_corner.closest_point = point
				self.sw_corner.minimum_distance = dist_sw
			dist_se = self.se_corner.distance(self.se_corner, point)
			if dist_se < self.se_corner.minimum_distance:
				self.se_corner.closest_point = point
				self.se_corner.minimum_distance = dist_se

	def corner_check(self) -> bool:
		'''
		- checks to see if all four corners share the same closest point
		'''
		return self.nw_corner == self.ne_corner == self.sw_corner == self.se_corner


if __name__ == "__main__":
	sector1 = Sector(center = (128, 128), radius = 128)
	sector2 = Sector(center = (384, 128), radius = 128)
	sector3 = Sector(center = (128, 384), radius = 128)
	sector4 = Sector(center = (384, 384), radius = 128)
	for sector in [sector1, sector2, sector3, sector4]:
		print("Sector: {}".format(sector))
		print("NW Sector Corner: {}".format(sector.nw_corner))
		print("NE Sector Corner: {}".format(sector.ne_corner))
		print("SW Sector Corner: {}".format(sector.sw_corner))
		print("SE Sector Corner: {}".format(sector.se_corner))
