# import numpy as np
# import matplotlib.pyplot as plt
# from matplotlib import animation
# import seaborn as sns

# COLS = 10
# ROWS = 10
# plt.rcParams["figure.autolayout"] = True


# def make_arr(cols, rows):
#     return np.random.randint(2, size=(cols, rows))


# def print_it(grid):
#     plt.imshow(grid, cmap="Greys")
#     plt.show()
#     print("\n".join(["  ".join([str(cell) for cell in row]) for row in grid]))
#     print()


# if __name__ == "__main__":
#     grid = make_arr(COLS, ROWS)
#     sns.heatmap(grid)

#     # try:
#     #     for i in range(100):
#     #         grid = make_arr(COLS, ROWS)
#     #         print_it(grid)
#     # except KeyboardInterrupt:
#     #     print("Stopped Successfully")

import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from matplotlib import animation

plt.rcParams["figure.autolayout"] = True

fig = plt.figure()
dimension = (10, 10)
data = np.random.randint(2, size=dimension)
sns.heatmap(data, vmax=0.8, cbar=False, xticklabels=False, yticklabels=False)


def init():
    sns.heatmap(
        np.zeros(dimension), vmax=0.8, cbar=False, xticklabels=False, yticklabels=False
    )


def animate(i):
    data = np.random.randint(2, size=dimension)
    sns.heatmap(data, vmax=0.8, cbar=False, xticklabels=False, yticklabels=False)


anim = animation.FuncAnimation(fig, animate, init_func=init, frames=2000, repeat=True)

plt.show()
