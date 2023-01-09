# QUEUE CLASS

class Queue:
	'''
	'''
	def __init__(self, events) -> None:
		self.events = events
		self.queue = []
		if events: self.queue = events
		self.sort()


	def get_length(self) -> int:
		return len(self.queue)


	def extract_first(self) -> object:
		if len(self.queue) == 0: return None
		index = self.queue.pop(0)
		return index


	def insert(self, event) -> None:
		self.queue.append(event)
		self.sort()


	def sort(self) -> None:
		pass


if __name__ == "__main__":
	pass
