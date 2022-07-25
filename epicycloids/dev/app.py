# EPICYCLOID GENERATION GUI

from tkinter import Tk, Frame, StringVar
from tkinter import Button, Label, Entry, Scale
from tkinter import N, E, S, W, NE, NW, SE, SW, HORIZONTAL

from tool import Tool
from hyperparameters import Hyperparameters as h

class App:
	'''
	'''
	def __init__(self, master: object) -> None:
		self.master = master
		self.frame = Frame(self.master)
		self.frame.pack()
		self.multiplier = StringVar()
		self.points = StringVar()
		self.window = 500

		# Multiplier Label
		self.mult_label = Label(master = self.frame,
								text = "Multiplier"
		)
		self.mult_label.pack()

		# Multiplier Scale
		self.mult_scale = Scale(master = self.frame, 
								variable = self.multiplier, 
								from_ = 0, 
								to = 200, 
								length = 300, 
								tickinterval = 20, 
								orient = HORIZONTAL, 
								command = self.config_mult
		)
		self.mult_scale.pack()

		# Multiplier Entry
		self.mult_entry = Entry(master = self.frame, 
								textvariable = self.multiplier
		)
		self.mult_entry.pack()

		# Number of Points Label
		self.point_label = Label(master = self.frame,
								 text = "Number of Points"
		)
		self.point_label.pack()

		# Number of Points Scale
		self.point_scale = Scale(master = self.frame, 
								 variable = self.points, 
								 from_ = 1, 
								 to = 1000, 
								 length = 300, 
								 tickinterval = 100, 
								 orient = HORIZONTAL, 
								 command = self.config_point
		)
		self.point_scale.pack()

		# Number of Points Entry
		self.point_entry = Entry(master = self.frame,
								 textvariable = self.points
		)
		self.point_entry.pack()

		# Window Size Label
		self.window_label = Label(master = self.frame,
								  text = "Window Size"
		)
		self.window_label.pack()

		# Window Size Entry
		self.window_entry = Entry(master = self.frame,
								  textvariable = self.window
		)
		self.window_entry.pack()

		# Simulate Button
		self.simulate_button = Button(master = self.frame,
									  text = "Simulate",
									  command = self.simulate
		)
		self.simulate_button.pack()

	def config_mult(self, value = None): pass

	def config_point(self, value = None): pass

	def config_window(self, value = None): pass

	def simulate(self):
		h.MULTIPLIER = int(self.multiplier.get())
		h.POINT_NUM = int(self.points.get())
		h.DIM = int(self.window)
		tool = Tool()
		tool.run()


if __name__ == "__main__":
	root = Tk()
	root.geometry("500x500")
	root.wm_title('Epicycloid Generator')
	app = App(master = root)

	root.mainloop()
