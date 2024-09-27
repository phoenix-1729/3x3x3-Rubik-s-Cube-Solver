# 3x3x3-Rubik-s-Cube-Solver

This C++ program simulates a 3x3x3 Rubik's cube and allows applying standard cube moves such as rotations on various cube faces. The goal is to manipulate the cube from any scrambled state back to the solved state. The program represents the cube as a string of 54 characters, with each character corresponding to one sticker on the cube.

## Cube Representation

The Rubik's cube is represented as a 54-character string, where each character corresponds to one of the cube's stickers. The stickers are indexed as follows:

```text
                [36] [35] [34]
                [33] [32] [31]
                [30] [29] [28]
[43] [40] [37]  [1]  [2]  [3]   [21] [24] [27]  [54] [53] [52]
[44] [41] [38]  [4]  [5]  [6]   [20] [23] [26]  [51] [50] [49]
[45] [42] [39]  [7]  [8]  [9]   [19] [22] [25]  [48] [47] [46]
                [10] [11] [12]
                [13] [14] [15]
                [16] [17] [18]
```

A 2D representation of the solved cube looks like this:

```text
           B  B  B
           B  B  B
           B  B  B
 O  O  O   W  W  W   R R R  Y Y Y
 O  O  O   W  W  W   R R R  Y Y Y
 O  O  O   W  W  W   R R R  Y Y Y
           G  G  G
           G  G  G
           G  G  G
```

### Sticker Colors:
- W: White (Top)
- Y: Yellow (Bottom)
- R: Red (Front)
- O: Orange (Back)
- B: Blue (Left)
- G: Green (Right)

The solved state of the cube is represented as based on above numberings :
```text
WWWWWWWWWGGGGGGGGGRRRRRRRRRBBBBBBBBBOOOOOOOOOYYYYYYYYY
```

## Moves
The program supports the following moves:

U: Rotate the upper face clockwise
Ui: Rotate the upper face counter-clockwise
F: Rotate the front face clockwise
Fi: Rotate the front face counter-clockwise
R: Rotate the right face clockwise
Ri: Rotate the right face counter-clockwise
L: Rotate the left face clockwise
Li: Rotate the left face counter-clockwise
D: Rotate the down face clockwise
Di: Rotate the down face counter-clockwise
B: Rotate the back face clockwise
Bi: Rotate the back face counter-clockwise
Each move alters specific portions of the cube, represented by corresponding changes in the string.


### Example of Usage
To apply moves to the cube, the function applyMove takes a current cube state and a move. For instance, applying the move "U" (Up face clockwise) alters the top face and edges of adjacent faces.

After two "U" moves, the cube looks like this:

```text
           B  B  B
           B  B  B
           G  G  G
 O  O  R   W  W  W   O R R  Y Y Y
 O  O  R   W  W  W   O R R  Y Y Y
 O  O  R   W  W  W   O R R  Y Y Y
           B  B  B
           G  G  G
           G  G  G
```

## Algorithm used for calculating Moves

### GOD's Number
God's Number for the Rubik's Cube, in terms of quarter turns (90-degree rotations), is 26. This means that no matter how scrambled a Rubik's Cube is, it can always be solved in 26 or fewer quarter turns.
Quarter turns are the most basic single move on the cube, where a face is rotated by 90 degrees.

### solveCube Function
The program employs the **2-way BFS (Bidirectional Breadth-First Search)** algorithm to calculate the shortest sequence of moves from a scrambled state back to the solved state. 

- **2-way BFS** begins from both the scrambled state and the solved state, simultaneously exploring all possible moves.
- It works by meeting in the middle of the search space, thus reducing the number of states explored compared to a standard BFS.
- This allows for efficient calculation of the optimal number of moves to solve the cube, even for complex scramble configurations.

Here's how the implementation works:

#### Key Data Structures

1. **Queues**:
   - The algorithm uses two queues, `forward_queue` and `backward_queue`.
   - **`forward_queue`**: Starts from the scrambled state and explores possible moves forward.
   - **`backward_queue`**: Starts from the solved state and explores possible moves backward.
   - Both queues follow a breadth-first search (BFS) approach, where states are processed level by level, ensuring that the shortest path is found.

2. **Parent Tracking**:
   - Two unordered maps, **`forward_parents`** and **`backward_parents`**, are used to keep track of each state's parent (i.e., the previous state from which the current state was reached).
   - **`forward_parents`**: Maps each state visited by the forward search to the move that led to that state from its parent.
   - **`backward_parents`**: Maps each state visited by the backward search in a similar way, but from the solved state backward.

#### Detailed Algorithm Steps

1. **Initialization**:
   - The algorithm starts by checking if the initial scrambled state is already solved. If so, it returns `"Already Solved!"`.
   - Both `forward_queue` and `backward_queue` are initialized with the scrambled and solved states, respectively.
   - The **parent maps** (`forward_parents` and `backward_parents`) are initialized with `"N"` as a placeholder to indicate that these states do not have a parent.

2. **Two-way BFS Execution**:
   - The algorithm processes each queue alternately (first `forward_queue`, then `backward_queue`), exploring all possible moves (`MOVES`) from the current state.
   - For each move:
     - The resulting state (`next_position`) is calculated using the `applyMove` function.
     - If the state has not been visited before (i.e., it is not in the parent map), it is added to the respective parent map and queue.
     - If a state found in the forward search is already visited by the backward search (or vice versa), the search terminates, and the solution is reconstructed.

3. **Meeting in the Middle**:
   - When the forward and backward searches meet at the same state, the shortest path is constructed by combining the paths from both searches.
   - The solution is reconstructed in two parts:
     - **Forward Path**: Traced back from the meeting state to the scrambled state using `forward_parents`.
     - **Backward Path**: Traced back from the meeting state to the solved state using `backward_parents`, but with each move inverted using `inverseMove`.
   - The final solution is the concatenation of these two paths.


### applyMove Function
The `applyMove` function is responsible for applying a single move (like `U`, `F`, `R`, etc.) to the current state of the Rubik's Cube. This function takes two arguments:

- **cubeState**: The current state of the cube, represented as a 54-character string.
- **move**: The move to be applied, represented as a string (e.g., `"U"` for an upper face clockwise move, `"Fi"` for a front face counter-clockwise move).

**How it Works**
1. **Move Parsing**: The function first determines which face of the cube is being moved based on the move string. For example:
"U" refers to the upper face.
"F" refers to the front face.
"Ri" refers to the right face rotated counter-clockwise.

2. **Sticker Rotation**: Each move rotates a face of the cube, affecting both the stickers on that face and the stickers on adjacent edges. For example:
  A "U" move rotates the top face (stickers 0–8) and cycles the edge stickers of the front, right, back, and left faces.

3. **Transformation Logic**: Depending on whether the move is clockwise or counter-clockwise, the function shifts the stickers in the cube's string representation. This is done by rearranging the characters at the relevant indices to reflect the rotation of stickers on the cube.

4. **Return Value**: After applying the transformation, the function returns the updated cube state.

## Time Complexity
Move Application: Each move involves modifying the positions of several stickers, but the number of stickers modified is constant (at most 20 per move). Thus, applying a single move takes constant time: O(1).
Multiple Moves: Applying n moves takes O(n) time, as each move independently takes constant time.
The time complexity is **O(b^(d/2))**, where `b` is the branching factor (the number of possible moves), and `d` is the optimal solution depth (number of moves to solve the cube).

## Space Complexity
The space complexity is O(1) for each move, as the cube's state is represented by a string of 54 characters, which is a fixed size. No extra space is required proportional to the input size.
The space complexity is **O(b^(d/2))** due to the storage required for the queues and parent maps in both forward and backward searches.

## Compilation and Execution

**Compile the program**:
```bash
g++ -o rubik_solver q.cpp
```

**Run the program**:
```bash
./rubik_solver
```

