import turtle as t

class Shape():

    coordinates = []
    count = 0
    iteration = 0
  
    def __init__(self, points, multiplier):
        self.points = points
        self.multiplier = multiplier

    def draw_circle(self):
        circle = t.Turtle()
        circle.speed(0)
        circle.setheading(90)
        
        circle.penup()
        circle.goto(-300, 0)
        circle.pendown()
        for i in range(0, self.points):
            Shape.coordinates.append(circle.position())
            #print("{x} : {y}" .format(x = i, y = circle.position()))
            circle.penup()
            circle.forward(1800 * (self.points ** -1))
            circle.pendown()
            circle.dot(5)
            circle.right(360 / self.points)

        circle.penup()
        circle.goto(-300, 300)
        circle.pendown()
        circle.hideturtle()

        return ""

    def draw_cardioid(self):
        cardioid = t.Turtle()
        cardioid.speed(0)

        group_intervals = int(self.points / self.multiplier)

        while(Shape.iteration - 1 < group_intervals):

            product = Shape.iteration * self.multiplier

            if Shape.count == self.points:
                break
            
            elif int(Shape.iteration / group_intervals) == 1:
                cardioid.penup()
                cardioid.goto(Shape.coordinates[Shape.count])
                cardioid.pendown()
                
                #Shape.count = Shape.count + 1
                Shape.iteration = 0
                continue

            else:
                cardioid.penup()
                cardioid.goto(Shape.coordinates[Shape.count])
                cardioid.pendown()

                cardioid.goto(Shape.coordinates[product])
                Shape.count = Shape.count + 1
                Shape.iteration = Shape.iteration + 1

        cardioid.penup()
        cardioid.goto(-300,300)
        cardioid.pendown()
        cardioid.hideturtle()

        return ""