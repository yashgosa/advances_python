import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from matplotlib import animation

plt.rcParams["figure.autolayout"] = True

fig = plt.figure()
dimension = (10, 10)


def make_arr(dimension):
    return np.random.randint(2, size=dimension)


def animate(i):
    grid = make_arr(dimension)
    sns.heatmap(
        grid, vmax=0.8, cbar=False, xticklabels=False, yticklabels=False, cmap="Greys"
    )


if __name__ == "__main__":
    anim = animation.FuncAnimation(fig, animate, frames=2000, repeat=True)
    plt.show()
