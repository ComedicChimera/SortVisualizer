# SortVisualizer

A simple application for visualizing sorting algorithms written with C++ & SFML.

<img src="images/normal.png"/>


<img src="images/rainbow.png"/>

## Algorithms

The visualizer supports the following algorithms:

 - Bubble Sort
 - Selection Sort
 - Radix Sort (LSD)
 - Quick Sort
 - Merge Sort
 - Insertion Sort
 - Ripple Sort
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

	.\SortVisualizer sort-name [-d ms] [-c count] [-w width] [-h height] [-f] [-rainbow] [-ns]

The mandatory argument `sort-name` is the name of the sorting algorithm minus its " Sort" suffix.  For example Merge Sort's *sort-name* is `Merge`. There is no flag for this argument since it always comes before the other flag arguments.

### Additional Parameters

These can be specified in any order and are all optional.

#### Arguments

| Name | Meaning | Arguments | Default Value |
| ---- | ------- | --------- | ------------- |
| `-d` | The operation delay in milliseconds | ms | 1 |
| `-c` | The number of randomly shuffled elements to sort | count | 256 |
| `-w` | The width of the screen in pixels (non resizable) | width | 1280 |
| `-h` | The height of the screen in pixels (non resizable) | height | 720 |

#### Flags

| Flag | Meaning |
| ---- | ------- |
| `-f` | The sort will run in fullscreen |
| `-rainbow` | The sort will now run in rainbow mode |
| `-ns` | No sound will be played during sort |

***Note*** *Rainbow mode does not run a visible validation check at the end for aesthetic purposes.*
