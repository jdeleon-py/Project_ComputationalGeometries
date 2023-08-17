#TKINTER GUI CLASS

from tkinter import Tk, Frame
from tkinter import Button, Label, Entry
from tkinter import N, E, S, W, NE, NW, SE, SW

class App:
	'''
	'''
	def __init__(self, master: object) -> None:
		self.master = master
		self.frame = Frame(self.master)
		self.frame.pack()


if __name__ == "__main__":
	root = Tk()
	root.geometry("500x500")
	root.wm_title('Cellular Automata (Game of Life) Simulator')
	app = App(master = root)

	root.mainloop()
