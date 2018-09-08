import pyglet
from sort_array import SortArray
from algorithms import *


window = pyglet.window.Window(
    width=1280,
    height=720,
    caption='Sort Visualizer'
)

sa = SortArray(1000, selection_sort)


@window.event
def on_draw():
    window.clear()
    sa.draw()


def loop(_):
    try:
        sa.update()

    except StopIteration:
        sa.clear()
        loop = lambda x: x


pyglet.clock.schedule_interval(loop, 0.05)
pyglet.app.run()





