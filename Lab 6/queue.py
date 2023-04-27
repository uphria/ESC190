class CircularQueue:
    def __init__(self, size):
        self.size = size
        self.data = size*[None]
        self.start = -1
        self.end = -1

    def enqueue(self, item):
        if self.end+1 == self.start or (self.end == self.size and self.start == 0):       # arr full
            print("Queue full\n")
        elif self.start == -1:      # no elements in arr
            self.start = 0
            self.end = 0
            self.data[self.end] = item
        elif self.end == self.size-1:       # reached end of fixed arr
            self.end = 0
            self.data[self.end] = item
        else:           # elements in arr
            self.end = self.end+1
            self.data[self.end] = item

    def dequeue(self):
        if self.start == -1:        # arr empty
            print("Queue empty\n")
        elif self.start == self.end:        # arr has one element
            ret_val = self.data[self.start]
            self.start = -1
            self.end = -1
        elif self.start == self.size-1:     # arr starts at wrap
            ret_val = self.data[self.start]
            self.start = 0
        else:       # elements in arr
            ret_val = self.data[self.start]
            self.start = self.start+1
        return ret_val    
    
    def __str__(self):
        if self.start == -1:
            print("Queue empty")
        elif (self.end >= self.start):          # no wrap
            print("Elements in queue: ")
            for i in range(self.start, self.end+1):
                print(self.data[i], end = " ")
            print("\n")
        else:
            print("Elements in queue: ")
            for i in range(self.start, self.size):
                print(self.data[i], end = " ")
            for i in range(0, self.end+1):
                print(self.data[i], end = " ")
            print("\n")
    
    def __lt__(self, other):
        if self.data[self.start] < other.data[other.start]:
            return True
        else:
            return False
        # case where starts are same --> compare next val

q = CircularQueue(4)
q.enqueue(5)
q.enqueue(0)
q.enqueue(99)
q.enqueue(17)
#q.__str__()
q.dequeue()
q.dequeue()
#q.__str__()
q.enqueue(3)
#q.__str__()

r  = CircularQueue(2)
r.enqueue(7)
r.enqueue(5)

s = CircularQueue(1)
s.enqueue(1002)

arrQueue = [q, r, s]
arrQueue.sort()
print("Sorted now:")
for i in range(len(arrQueue)):
    arrQueue[i].__str__()