import subprocess

sort_names = [
    'Bubble',
    'Selection',
    'Radix',
    'Radix4',
    'Radix2',
    'RadixMSD',
    'Quick',
    'Merge',
    'Insertion',
    'Ripple',
    'Gnome',
    'Stooge',
    'Pancake',
    'Cycle',
    'Heap',
    'Shell',
    'Bitonic',
    'Gravity',
    'Time',
    'OddEven',
    'Tim',
    'Intro',
    'Strand',
    'Comb',
    'Tree',
    'Cartesian',
    'Dutch',
    'DoubleSelect',
    'Smooth',
    'Flash'
]


specializations = {
    'Bubble': (128, 2),
    'Insertion': (128, 4),
    'Stooge': (128, 4),
    'Ripple': (128, 2),
    'Gnome': (128, 4),
    'Cycle': (512, 25),
    'Radix': (512, 30),
    'Tree': (512, 25),
    'Cartesian': (256, 10),
    'Pancake': (64, 2),
    'Time': (128, 35),
    'OddEven': (128, 2),
    'Strand': (128, 2),
    'Selection': (512, 15),
    'DoubleSelect': (512, 25)
}


def call_sort(sr, c=None, d=None):
    if not c and not d:
        proc = subprocess.Popen(f'../build/Release/SortVisualizer.exe {sr} -d 10 -f -w 1920 -h 1080 -nw -v circle -ss'.split(' '))
    else:
        proc = subprocess.Popen(f'../build/Release/SortVisualizer.exe {sr} -c {c} -d {d} -f -w 1920 -h 1080 -nw -v circle -ss'.split(' '))
    proc.wait(timeout=90)
    proc.terminate()


for name in sort_names:
    if name in specializations:
        call_sort(name, *specializations[name])
    else:
        call_sort(name)
