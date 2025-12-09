# Day 7 – Write-up

## Part 1

### Problem description

You have exited the trash compactor, finding yourself in the familiar halls of a North Pole research wing. You notice a large sign that reads "Teleporter Hub," indicating that the researchers are experimenting with teleportation. Unable to resist, you step onto a large yellow teleporter pad.

Suddenly, you find yourself in an unfamiliar room. The room has no doors; the only way out is the teleporter. Unfortunately, the teleporter is leaking magical smoke.

Since this is a teleporter lab, there are spare parts, manuals, and diagnostic equipment scattered around. By connecting one of the diagnostic tools, you receive an error code `0H-N0`, indicating a malfunction in one of the tachyon manifolds.

You quickly locate a diagram of the tachyon manifold (your puzzle input). A tachyon beam enters the manifold at the location marked `S`. Tachyon beams always move downward. They pass freely through empty space (`.`). However, when a tachyon beam encounters a splitter (`^`), the beam stops; in its place, **two new beams are emitted immediately to the left and right of the splitter**.

Your task is to analyze the tachyon manifold diagram and determine **how many times the beam is split** as it traverses the manifold until all beams are stopped or exit.

---

### Key idea

A beam splits at position `X` if and only if:

- There is a splitter (`^`) at position `X`.
- A tachyon beam arrives at position `X`.

That's all that is needed for a split to occur.

---

### Algorithm

We can **simulate the downward flow** of beams:

1. Use an array `pos` of size `n` to track the current `x` positions of active tachyon beams.  
2. Initialize `pos[i] = 1` for each position `i` where there is an `'S'` in the first line.  
3. For each line of the input:
   - For each position `i`:
     - If `cur = '^'` and `pos[i] = 1`:
       - Stop the current beam at `i` (`pos[i] = 0`).
       - Emit two new beams at positions `i-1` and `i+1` (`pos[i-1] = 1`, `pos[i+1] = 1`).
       - Increment the split counter `res`.

---

### Pseudo-code



```
n = length of a line
pos = array of size n.
pos <- [0...0]

for i from 0 to n-1:
    if current_line[i] = 'S':
        pos[i] <- 1
res = 0

while next line:
    for i from 0 to n-1:
        if cur = '^' and pos[i] = 1:
            pos[i] <- 0
            pos[i-1] <- 1
            pos[i+1] <- 1
            res <- res + 1

print res

```

## Part 2

### Problem description

With your analysis of the manifold complete, you begin fixing the teleporter. However, as you open the side of the teleporter to replace the broken manifold, you discover that it isn't a classical tachyon manifold — it's a **quantum tachyon manifold**.

In a quantum tachyon manifold:

- Only a **single tachyon particle** is sent through the manifold.
- When the particle encounters a splitter (`^`), it takes **both the left and right path simultaneously**.
- According to the manual, the many-worlds interpretation applies: **each time the particle reaches a splitter, time itself splits into multiple timelines**. In one timeline, the particle goes left; in the other, it goes right.

Your task is to determine **how many timelines are active** after the single particle completes all of its possible journeys through the manifold.

---

### Key ideas

Instead of tracking individual particles, we track **timelines**.  
We can use the same approach as Part 1, but instead of marking whether a particle is at position `X`, we store **how many timelines have a particle at position `X`**.

When there is no splitter, nothing happen.

When we encounter a splitter (`^`):

- The current position no longer holds any timelines (the particle splits).
- The number of timelines at that position is **distributed to the left and right positions**.
- We continue propagating all timelines downward in this way until the particle reaches the bottom of the manifold.

In short: **each splitter doubles the number of timelines**, and the total number of timelines at the end is the sum over all positions.

### Pseudo-code

```
n = length of a line
pos = array of size n.
pos <- [0...0]

for i from 0 to n-1:
    if current_line[i] = 'S':
        pos[i] <- 1
res = 0

while next line:
    for i from 0 to n-1:
        if cur = '^' and pos[i] = 1:
            
            pos[i-1] <- pos[i-1] + pos[i]   (if pos > 0)
            pos[i+1] <- pos[i+1] + pos[i]   (if pos < n-1)
            pos[i] <- 0

print sum(pos)

```