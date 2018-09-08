from random import shuffle
import pyglet


class Sort:
    def __init__(self, array, sort_gen):
        self._sort_generator = sort_gen(array)

        self.array = array
        self.selected = [0]

    def update(self):
        value = next(self._sort_generator)

        self.array, self.selected = value
        return True


class SortArray:
    def __init__(self, size, alg):
        self._size = size

        self._arr = list(range(1, size + 1))
        shuffle(self._arr)

        self._sort = Sort(self._arr, alg)

        self._bar_width = 1280 / self._size

    def draw(self):
        for i, item in enumerate(self._arr):
            gb = 0 if i in self._sort.selected else 255

            pyglet.graphics.draw_indexed(4, pyglet.gl.GL_TRIANGLES, [0, 1, 2, 2, 3, 0],
                ('v2f', (
                    self._bar_width * i, 0,
                    self._bar_width * (i + 1), 0,
                    self._bar_width * (i + 1), 720 * (item / self._size),
                    self._bar_width * i, 720 * (item / self._size)
                )),
                ('c3B', (
                    255, gb, gb,
                    255, gb, gb,
                    255, gb, gb,
                    255, gb, gb
                )))

    def update(self):
        if self._sort.update():
            self._arr = self._sort.array

    def clear(self):
        self._sort.selected = []
        self.draw()

