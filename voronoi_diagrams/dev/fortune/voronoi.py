# VORONOI CLASS

from event import Event
from queue import Queue

class Voronoi:
	'''
	'''
	def __init__(self, points: [object], width: int, height: int) -> None:
		self.points = points
		self.width = width
		self.height = height
		self.reset()


	def reset(self) -> None:
		'''
		'''
		self.events = Queue()
		self.beachline_root = None
		self.vor_vertices = []
		self.edges = []


	def update(self) -> None:
		'''
		'''
		self.reset()
		points = []
		event = None
		for point in points: point.append(Event("POINT"), point)
		self.events.points = points

		while(len(self.events) > 0):
			event = self.events.pop(0)
			if e.type == "POINT": self.point_event(event.position)
			elif event.active == True: self.vertex_event(event)

		self.complete_segments(event.position)


	def point_event(self, point: object) -> None:
		'''
		'''
		pass


	def vertex_event(self, event: object) -> None:
		'''
		'''
		pass



if __name__ == "__main__":
	pass
