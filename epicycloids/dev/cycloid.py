# CYCLOID CONSTRUCTION CLASS

from turtle import Turtle

class Cycloid:
	'''
	'''
	def __init__(self):
		pass

class Shape:
	coordinates = []

if __name__ == "__main__":
	points = 10000
	circle = Turtle()
	circle.speed(0)
	circle.setheading(90)

	circle.penup()
	circle.goto(-300, 0)
	circle.pendown()
	for i in range(0, points):
		Shape.coordinates.append(circle.position())
		#print("{x} : {y}" .format(x = i, y = circle.position()))
		circle.penup()
		circle.forward(1800 * (points ** -1))
		circle.pendown()
		circle.dot(5)
		circle.right(360 / points)

	circle.penup()
	circle.goto(-300, 300)
	circle.pendown()
	circle.hideturtle()
	delay = input("Press enter to exit")
