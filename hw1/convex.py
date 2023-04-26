from scipy.spatial import ConvexHull
import random
# Define your points as a list of tuples
# n = 5000
# points = [(random.randint(-2147483648, 2147483647),random.randint(-2147483648, 2147483647)) for i, j in zip(range(n), range(n))]
# print(n)
# for i in range(n):
#     print(points[i][0], points[i][1])

points = [(1073741823, 1073741823), (-1073741824,1073741823), (-1073741824, -1073741824), (1073741823,-1073741824)]
# Create a convex hull object from the points
hull = ConvexHull(points)

# # Calculate the area of the convex hull
area = hull.volume

print(f"The area of the convex hull is: {area:.1f}")
# print("The area of the convex hull is: ", area)
