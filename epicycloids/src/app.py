# EPICYCLOID GENERATION GUI

import json
from tkinter import Tk, Frame, StringVar, IntVar
from tkinter import Button, Label, Entry, Scale
from tkinter import HORIZONTAL
from tool import Tool

class App:
	'''
	METHODS:
		- ability to convert user-specified data to a parameter json file
		- ability to simulate the generator with a button

	ATTRIBUTES:
		- mult, point_num, dim StringVar attributes used to 
			edit the json parameter file
		- Multiplier:
			- label
			- scale
			- entry
		- Number of Points:
			- label
			- scale
			- entry
		- Window Size:
			- label
			- scale
			- entry
		- Reference Circle:
			- Label
			- Button
		- Simulate Button
	'''
	def __init__(self, master: object) -> None:
		self.master = master
		self.frame = Frame(self.master)
		self.frame.pack()
		self.params = self.define_params()
		self.multiplier = StringVar(value = str(self.params["Multiplier"]))
		self.points = StringVar(value = str(self.params["Number of Points"]))
		self.window = StringVar(value = str(self.params["Window Dimension"]))
		self.ref_circle = IntVar(value = self.params["Reference Circle"])
		self.is_on = bool(self.ref_circle)

		# Multiplier Label
		self.mult_label = Label(master = self.frame,
								text = "Multiplier:"
		)
		self.mult_label.grid(row = 0, column = 0, padx = 0, pady = 20)

		# Multiplier Scale
		self.mult_scale = Scale(master = self.frame,
								variable = self.multiplier,
								from_ = 0,
								to = 200,
								length = 300,
								tickinterval = 20,
								orient = HORIZONTAL
		)
		self.mult_scale.grid(row = 1, columnspan = 2, padx = 0, pady = 0)

		# Multiplier Entry
		self.mult_entry = Entry(master = self.frame, 
								textvariable = self.multiplier
		)
		self.mult_entry.grid(row = 0, column = 1, padx = 30, pady = 0)

		# Number of Points Label
		self.point_label = Label(master = self.frame,
								 text = "Number of Points:"
		)
		self.point_label.grid(row = 2, column = 0, padx = 10, pady = 10)

		# Number of Points Scale
		self.point_scale = Scale(master = self.frame,
								 variable = self.points,
								 from_ = 1,
								 to = 1000,
								 length = 300,
								 tickinterval = 100,
								 orient = HORIZONTAL
		)
		self.point_scale.grid(row = 3, columnspan = 2, padx = 0, pady = 0)

		# Number of Points Entry
		self.point_entry = Entry(master = self.frame,
								 textvariable = self.points
		)
		self.point_entry.grid(row = 2, column = 1, padx = 30, pady = 0)

		# Window Size Label
		self.window_label = Label(master = self.frame,
								  text = "Window Size:"
		)
		self.window_label.grid(row = 4, column = 0, padx = 0, pady = 10)

		# Window Size Scale
		self.window_scale = Scale(master = self.frame,
								  variable = self.window,
								  from_ = 100,
								  to = 1000,
								  length = 300,
								  tickinterval = 500,
								  orient = HORIZONTAL
		)
		self.window_scale.grid(row = 5, columnspan = 2, padx = 0, pady = 0)

		# Window Size Entry
		self.window_entry = Entry(master = self.frame,
								  textvariable = self.window
		)
		self.window_entry.grid(row = 4, column = 1, padx = 30, pady = 0)

		# Reference Circle Label
		self.ref_circle_label = Label(master = self.frame,
									  text = "Reference Circle?"
		)
		self.ref_circle_label.grid(row = 6, column = 0, padx = 20, pady = 0)

		# Reference Circle Button
		self.ref_circle_button = Button(master = self.frame,
										text = "Click Here",
										command = self.config_ref_circle
		)
		self.ref_circle_button.grid(row = 7, column = 0, padx = 20, pady = 10)

		# Simulate Button
		self.simulate_button = Button(master = self.frame,
									  text = "Simulate",
									  command = self.simulate
		)
		self.simulate_button.grid(row = 6, rowspan = 2, column = 1, padx = 10, pady = 10)

	def config_ref_circle(self) -> None:
		'''
		- defines the reference circle parameter as a toggle switch
		'''
		if self.is_on:
			self.is_on = False
			self.ref_circle_label.configure(text = "Reference Circle? No")
			self.ref_circle.set(value = 0)
		else:
			self.is_on = True
			self.ref_circle_label.configure(text = "Reference Circle? Yes")
			self.ref_circle.set(value = 1)

	def define_params(self) -> None:
		'''
		- reads the preset parameters and sets the default app values to
			the preset parameters
		'''
		with open("parameters.json", 'r') as file:
			data = json.load(file)
		file.close()
		return data

	def update_params(self) -> None:
		'''
		- writes the set parameters to a new json file
		- overwrites the original json file
		'''
		formatted_data = {
			"Reference Circle": self.ref_circle.get(),
			"Number of Points": int(self.points.get()),
			"Multiplier": int(self.multiplier.get()),
			"Window Dimension": int(self.window.get())
		}
		with open("parameters.json", 'w') as file:
			json_obj = json.dumps(formatted_data, indent = 4)
			file.write(json_obj)
		file.close()

	def simulate(self) -> None:
		'''
		- updates the parameters to the json file and then
		- runs as if running the cli
		- Note: problems occur with Turtle if more than one sim is ran
			within one app cycle
		'''
		self.update_params()
		tool = Tool()
		tool.run()


if __name__ == "__main__":
	root = Tk()
	root.wm_title('Epicycloid Generator')
	app = App(master = root)

	root.mainloop()
