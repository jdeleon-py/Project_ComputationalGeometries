# MERGE SORT EXAMPLE ALGORITHM

# compares the performance of two sorting algorithms
# this demonstration of merge sort will be modified to
#	operate on the voronoi generation algorithm

class MergeSort:
	'''
	'''
	def __init__(self, array: list) -> None:
		self.array = array
		self.unsorted_array = array
		self.array_sorted = self.sort()

	def __str__(self) -> str:
		return "{}".format(self.array_sorted)

	def sort(array: list = self.array) -> None:
		if len(array) <= 1: return array
		else:
			arr_temp = []
			midpoint = len(array) // 2
			left_arr = array[:midpoint]
			right_arr = array[midpoint:]
			self.sort(array = left_arr)
			self.sort(array = right_arr)


class InsertionSort:
	'''
	'''
	def __init__(self, array: list) -> None:
		self.array = array
		self.unsorted_array = array
		self.sorted_array = array

	def __str__(self) -> str:
		return "{}".format(self.array)

	def sort(array : list = self.array) -> None:
		pass


if __name__ == "__main__":
	pass