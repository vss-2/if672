class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        x1, y1 = coordinates[0][0], coordinates[0][1]
        x2, y2 = coordinates[1][0], coordinates[1][1]
        x3, y3 = 0, 0
        for i in range(2, len(coordinates)):
            x3, y3 = coordinates[i][0], coordinates[i][1]
            if( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) == 0):
                return True
            else:
                return False

# Algorithm: https://www.geeksforgeeks.org/program-check-three-points-collinear/
