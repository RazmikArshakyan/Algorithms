import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def distance(p1, p2):
     return math.sqrt((p1.x - p2.x)**2 + (p1.y - p2.y)**2)

def merge(Sy, d):
     min_dist = d
     for i in range(len(Sy)):
         for j in range(i + 1, min(i + 16, len(Sy))):
              min_dist = min(min_dist, distance(Sy[i], Sy[j]))
     return min_dist

def closest_pair(Px, Py):
    if len(Px) <= 3:
        min_dist = float('inf')
        for i in range(len(Px)):
            for j in range(i + 1, len(Px)):
                min_dist = min(min_dist, distance(Px[i], Px[j]))
        return min_dist

    mid = len(Px) // 2
    mid_point  = Px[mid]

    Qx = Px[:mid]
    Qy = []

    Rx = Px[mid:]
    Ry = []

    for p in Py:
        if p in Qx:
            Qy.append(p)
        else:
            Ry.append(p)

    d1 = closest_pair(Qx, Qy)
    d2 = closest_pair(Rx, Ry)
    d = min(d1, d2)

    Sy = [p for p in Py if abs(p.x - mid_point.x) < d]

    return merge(Sy, d)

if __name__ == '__main__':
    points = [Point(1, 2), Point(3, 4), Point(5, 6), Point(7, 8)]
    sorted_by_x = sorted(points, key=lambda point: point.x)
    sorted_by_y = sorted(points, key=lambda point: point.y)
    print(closest_pair(sorted_by_x, sorted_by_y))



