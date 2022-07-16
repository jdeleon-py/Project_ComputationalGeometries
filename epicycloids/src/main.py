#import turtle as t
import cardioid

if __name__ == "__main__":
	print("Enter a number of points:")
	points_input = int(input())
	print("Enter a multiplier:")
	mult_input = int(input())

	circle = cardioid.Shape(points = points_input, multiplier = mult_input)

	circle.draw_circle()
	circle.draw_cardioid()

	delay = input("Press enter to exit")