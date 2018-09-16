# SortVisualizer

A simple application for visualizing sorting algorithms written with C++ & SFML.

<img src="image.png"/>

## Algorithms

The visualizer supports the following algorithms:

 - Bubble Sort
 - Selection Sort
 - Radix Sort
 - Quick Sort
 - Merge Sort
 - Insertion Sort
 - Ripple Sort (LSD)
 - Gnome Sort
 - Stooge Sort
 - Pancake Sort
 - Cycle Sort
 - Heap Sort
 - Shell Sort
 - Bitonic Sort
 - Gravity Sort

## Requirements

You will need `Visual C++ 17` and a version of `SFML 2.4+` statically compiled for your platform (you may have to use a different compiler and adapt the source to your needs).  You will have to change the dependency directories in Visual Studio solution to wherever your local copy of SFML is stored. **THIS REPOSITORY DOES NOT CONTAIN AN SFML DISTRIBUTION, NOR ANY OF IT'S REQUIRED STATIC FILES**.

## Contributing

If you would like to add a feature or sorting algorithms just make a pull request and I will review it.  When designing your algorithms keep in mind that you want to showcase the algorithm.  Make sure to call `arr.draw()` wherever you see fit to update the display.

There is very little to no documentation of the source as it is just a very small side project of mine.  Feel free to use it as a base for whatever you want. 

## Command Line Interface

This application provides a minimalist CLI with a couple flags and one mandatory argument.  Below is an input
command template.

	.\SortVisualizer sort-name [-d ms] [-c count] [-w width] [-h height] [-f]

The mandatory argument `sort-name` is the name of the sorting algorithm minus its " Sort" suffix.  For example Merge Sort's *sort-name* is `Merge`. There is no flag for this argument since it always comes before the other flag arguments.

### Optional Flags

| Flag | Meaning | Arguments | Default Value |
| ---- | ------- | --------- | ------------- |
| `-d` | The operation delay in milliseconds | ms | 1 |
| `-c` | The number of randomly shuffled elements to sort | count | 256 |
| `-w` | The width of the screen in pixels (non resizable) | width | 1280 |
| `-h` | The height of the screen in pixels (non resizable) | height | 720 |
| `-f` | The sort will run in fullscreen | *none*  | *none* |

These flags can be specified in any order.  A flag that accepts *none* as a parameters means that it is a boolean flag.
If is is present, it's action will occur.
