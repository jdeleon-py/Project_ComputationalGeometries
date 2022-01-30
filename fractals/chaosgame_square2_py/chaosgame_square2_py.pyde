def setup():
    size(600, 600)
    global ax, bx, cx, dx, x
    global ay, by, cy, dy, y
    global store_random, random_n
    
    ax = 10
    ay = 10
    bx = width - 10
    by = 10
    cx = 10
    cy = height - 10
    dx = width - 10
    dy = height - 10
    
    store_random = []
    
    x = random(width)
    y = random(height)
    
    random_n = floor(random(1, 5))
    store_random.append(random_n)
    
    background(0)
    stroke(255)
    strokeWeight(4)
    point(ax, ay)
    point(bx, by)
    point(cx, cy)
    point(dx, dy)
    
    stroke(255, 0, 0)
    strokeWeight(1)
    line(ax, ay, bx, by)
    line(bx, by, dx, dy)
    line(dx, dy, cx, cy)
    line(cx, cy, ax, ay)
    
def draw():
    global ax, bx, cx, dx, x
    global ay, by, cy, dy, y
    global store_random, random_n
    
    for i in range(0, 100):
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
            x = lerp(x, dx, 0.5)
            y = lerp(y, dy, 0.5)
                
        elif random_n == 4:
            x = lerp(x, cx, 0.5)
            y = lerp(y, cy, 0.5)
            
        while True:
            random_n = floor((random(1, 5)))
            if ((random_n == 1) and (store_random[0] == 4)):
                continue
            elif ((random_n - 1) == store_random[0]):
                continue
            break
        
def mousePressed(): exit()
