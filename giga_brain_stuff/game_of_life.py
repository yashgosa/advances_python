import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from matplotlib import animation

plt.rcParams["figure.autolayout"] = True

fig = plt.figure(figsize=(7, 7))
dimension = (40, 40)
first = np.random.randint(2, size=dimension)


def animate(frameNum, img, grid):
    next = next_gen(grid)
    img.set_data(next)
    return img


def next_gen(old):
    new = np.zeros(dimension)
    for rows in range(dimension[0]):
        for cols in range(dimension[1]):
            state = old[rows][cols]
            if (
                rows == 0
                or rows == dimension[0] - 1
                or cols == 0
                or cols == dimension[1] - 1
            ):
                new[rows][cols] = state
                continue
            else:
                sum = count_neighbours(old, rows, cols)
                if sum == 3 and state == 0:
                    state = 1
                elif sum < 2 or sum > 3 and state == 1:
                    state = 0

            new[rows][cols] = state
    old[:] = new[:]
    return new


def count_neighbours(old, i, j):
    sum = 0
    for x in range(-1, 2):
        for y in range(-1, 2):
            sum += old[i + x][j + y]
    sum -= old[i][j]
    return sum


if __name__ == "__main__":
    grid = first
    fig, ax = plt.subplots()
    img = ax.imshow(grid, interpolation="nearest")

    update_interval = 50
    anim = animation.FuncAnimation(
        fig,
        animate,
        fargs=(img, grid),
        frames=2000,
        repeat=True,
    )
    plt.show()
