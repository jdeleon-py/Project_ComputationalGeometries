def setup():
    size(600, 600)
    global ax, bx, cx, dx, ex, x
    global ay, by, cy, dy, ey, y
    global store_random, random_n
    
    ax = width / 2
    ay = 10
    bx = (height / 2) - 285.32
    by = (height / 2) - 82.71
    cx = (height / 2) - 176.34
    cy = (height / 2) + 252.71
    dx = (height / 2) + 176.34
    dy = (height / 2) + 252.71
    ex = (height / 2) + 285.32
    ey = (height / 2) - 82.71
    
    store_random = []
    
    x = random(width)
    y = random(height)
    
    random_n = floor(random(1, 6))
    store_random.append(random_n)
    
    background(0)
    stroke(255)
    strokeWeight(4)
    point(ax, ay)
    point(bx, by)
    point(cx, cy)
    point(dx, dy)
    point(ex, ey)
    
    stroke(255, 0, 0)
    strokeWeight(1)
    line(ax, ay, bx, by)
    line(bx, by, cx, cy)
    line(cx, cy, dx, dy)
    line(dx, dy, ex, ey)
    line(ex, ey, ax, ay)
    
def draw():
    global ax, bx, cx, dx, ex, x
    global ay, by, cy, dy, ey, y
    global store_random, random_n
    
    for i in range(0, 50):
        stroke(255, 0, 255)
        strokeWeight(1)
        point(x, y)
        
        store_random[0] = random_n

        if random_n == 1:
            x = lerp(x, ax, 0.5)
            y = lerp(y, ay, 0.5)
        
        elif random_n == 2:
            x = lerp(x, bx, 0.5)
            y = lerp(y, by, 0.5)
            
        elif random_n == 3:
            x = lerp(x, cx, 0.5)
            y = lerp(y, cy, 0.5)
        
        elif random_n == 4:
            x = lerp(x, dx, 0.5)
            y = lerp(y, dy, 0.5)
        
        elif random_n == 5:
            x = lerp(x, ex, 0.5)
            y = lerp(y, ey, 0.5)
            
        while True:
            random_n = floor(random(1, 6))
            if store_random[0] == random_n:
                continue
            break
