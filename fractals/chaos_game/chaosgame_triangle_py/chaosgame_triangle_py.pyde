import shape
import chaos

def setup():
    size(600, 600)
    global ax, bx, cx, x
    global ay, by, cy, y
    global store_random
    
    ax = width / 2
    ay = 10
    bx = 10
    by = height - 10
    cx = width - 10
    cy = height - 10
    
    x = random(width)
    y = random(height)
    
    background(0)
    stroke(255)
    strokeWeight(4)
    point(ax, ay)
    point(bx, by)
    point(cx, cy)
    
def draw():
    global ax, bx, cx, x
    global ay, by, cy, y
    global store_random
    
    for i in range(0, 100):
        stroke(255, 0, 255)
        strokeWeight(1)
        point(x, y)
        
        random_n = floor((random(1, 4)))

        if random_n == 1:
            x = lerp(x, ax, 0.5)
            y = lerp(y, ay, 0.5)
        
        elif random_n == 2:
            x = lerp(x, bx, 0.5)
            y = lerp(y, by, 0.5)
            
        elif random_n == 3:
            x = lerp(x, cx, 0.5)
            y = lerp(y, cy, 0.5)
