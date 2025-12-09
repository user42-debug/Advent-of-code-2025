# Day 8 – Write-up

## Part 1

### Problem description

Equipped with a new understanding of teleporter maintenance, you confidently step onto the repaired teleporter pad.

You rematerialize on an unfamiliar teleporter pad and find yourself in a vast underground space which contains a **giant playground**.

Across the playground, a group of Elves are working on an ambitious Christmas decoration project. They have suspended a large number of small electrical junction boxes and plan to connect them with long strings of lights.  

- Most junction boxes **do not provide electricity**.  
- When **two junction boxes are connected** by a string of lights, electricity can pass between them.  

The Elves want to figure out **which junction boxes to connect** so that electricity can eventually reach every junction box. You are given a **list of all junction box positions in 3D space** (your puzzle input), with each position given as `X,Y,Z` coordinates.

### Rules

- Electricity can flow between connected junction boxes.  
- Initially, each junction box is in its **own circuit**.  
- Repeatedly connect the **two closest junction boxes** which are not already in the same circuit.  
  - The “closest” pair is determined by **straight-line distance in 3D space**.  
  - If a pair is already in the same circuit, **nothing happens**.  
- Keep connecting pairs until you reach the desired number of connections (in your input, 1000 pairs).  

### Goal

After connecting the 1000 closest pairs of junction boxes:

1. Determine the sizes of all resulting circuits.  
2. Multiply together the sizes of the **three largest circuits**.  

> Example (after 10 shortest connections in the sample):
>
> - Circuits: 5, 4, 2, 2, 1, 1, 1, 1, 1, 1, 1  
> - Three largest: 5, 4, 2  
> - Product: 5 × 4 × 2 = 40

---

### Key idea

We can just look for every pair, and then sort everything. Then we count by using a DSU to keep track of the connected nodes.

---

## Part 2

### Problem description

The Elves quickly realize that they **still don't have enough extension cables**. They need to continue connecting junction boxes **until all of them form a single large circuit**.

- Each time you connect the **closest pair of junction boxes** that are not already in the same circuit, you merge their circuits.  
- You continue this process until there is only **one circuit containing all junction boxes**.  

### Example

Continuing the previous example:

- The first connection that merges all junction boxes into a single circuit is between the junction boxes at `216,146,977` and `117,168,530`.  
- The Elves need to know the distance from the wall to pick the right extension cable. One way to compute this is to multiply the **X coordinates** of these two junction boxes: `216 × 117 = 252

### Key idea

This is a classic MST problem, and **Kruskal's algorithm** is perfectly typed for this kind of problem.
Still using a DSU, we add every nodes until there is only one set left. Then we return the last connection we've done.