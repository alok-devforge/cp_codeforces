# 4A. Watermelon

**Contest:** Codeforces Beta Round 4 (Div. 2 Only)  
**Problem Link:** [https://codeforces.com/problemset/problem/4/A](https://codeforces.com/problemset/problem/4/A)  
**Rating:** 800  
**Tags:** Math, Brute Force  
**Time Limit:** 1.0 second  
**Memory Limit:** 64 MB  

---

## 📌 Problem Statement

Pete and Billy bought a watermelon of weight $w$ kilos. They want to divide it into two parts such that:
1. Each part weighs a strictly positive integer number of kilos.
2. Each part weighs an **even** number of kilos.
3. The parts do not necessarily have to be equal.

Determine whether it is possible to divide the watermelon according to these conditions.

### Input Format
- A single integer $w$ ($1 \le w \le 100$) — the total weight of the watermelon in kilos.

### Output Format
- Print `YES` if they can divide the watermelon into two positive even-weight parts.
- Print `NO` otherwise.

### Constraints
- $1 \le w \le 100$

### Examples

| Sample Input | Sample Output | Explanation |
|:------------:|:-------------:|:------------|
| `8`          | `YES`         | Can be split into $2 + 6 = 8$ or $4 + 4 = 8$ (both parts are positive and even). |
| `2`          | `NO`          | The only positive integer partition is $1 + 1 = 2$, but $1$ is odd. |

---

## 🧠 Intuition & Approach

### 1. Brute-Force Idea
Iterate over all possible weights for the first part, $a$, from $1$ to $w - 1$. For each $a$, the second part is $b = w - a$. Check if both $a$ and $b$ are even ($a \pmod 2 == 0$ and $b \pmod 2 == 0$). If any such pair is found, output `YES`.

### 2. Why It Is Inefficient / Unnecessary
Although $w \le 100$ is very small and an $O(w)$ loop passes well within the 1-second limit, looping is completely redundant because this problem is governed by a fundamental number theory rule: **parity**.

### 3. Key Observations & Trick
1. **Parity property of addition:**  
   The sum of two even numbers is always even:  
   $$\text{even} + \text{even} = \text{even}$$  
   If $w$ is odd, it is mathematically impossible to express it as the sum of two even integers ($\text{odd} \ne \text{even} + \text{even}$).
2. **Minimal positive even number:**  
   Each boy must get a part of *positive* weight ($> 0$). The smallest positive even integer is $2$.
3. **Smallest achievable sum:**  
   The absolute minimum weight needed to form two positive even parts is:  
   $$2 + 2 = 4$$  
4. **Generalization for all even $w \ge 4$:**  
   If $w$ is even and $w \ge 4$, we can always choose the first part to be $2$. The remaining part is $w - 2$. Because both $w$ and $2$ are even, $w - 2$ must also be even and strictly positive ($w - 2 \ge 2$). Thus, a valid division **always** exists for any even $w \ge 4$.
5. **The special trap ($w = 2$):**  
   While $2$ is even, the only integer split into two positive parts is $1 + 1$. Since $1$ is odd, $w = 2$ must yield `NO`.

### 4. Algorithm Walkthrough
1. Read the integer `w`.
2. Check if `w % 2 == 0` (parity check) AND `w >= 4` (minimum threshold).
3. If both conditions hold, print `YES`.
4. Otherwise, print `NO`.

---

## 💻 C++ Solution

> 📄 **Standalone File:** [4A-Watermelon.cpp](./4A-Watermelon.cpp)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w;
    if (!(cin >> w)) return 0;

    // A valid partition requires two positive even integers (minimum 2 + 2 = 4).
    // An even number w >= 4 can always be partitioned into 2 and (w - 2), both even.
    // For w = 2, the only positive split is 1 + 1 (both odd), which is invalid.
    if (w >= 4 && w % 2 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
```

---

## ⏱️ Complexity Analysis

| Metric | Complexity | Reason |
|:------:|:----------:|:-------|
| **Time** | $\mathcal{O}(1)$ | We perform only a single modulo operation and a comparison. |
| **Space** | $\mathcal{O}(1)$ | Only a single scalar integer variable `w` is allocated. |

---

## ⚠️ Edge Cases

- **Minimum Input ($w = 1$):** Odd number, cannot be divided into even parts. Outputs `NO`.
- **Boundary Trap ($w = 2$):** Even number, but the only positive split is $1 + 1$ (both odd). Handled correctly by condition `w >= 4`, outputs `NO`.
- **Smallest Valid Value ($w = 4$):** Splits into $2 + 2$, outputs `YES`.
- **Arbitrary Odd Numbers ($w = 3, 5, 7, \dots, 99$):** Sum of two evens is always even, so odd inputs always fail. Handled by `w % 2 == 0`, outputs `NO`.
- **Maximum Constraint ($w = 100$):** Splits into $2 + 98$, fits easily in standard 32-bit integer `int`, outputs `YES`.

---

## 🎯 Interview Follow-up Questions

**Q1: Why did you choose this approach over looping through possible parts?**  
**A:** Checking parity and the lower bound $w \ge 4$ computes the exact answer in $\mathcal{O}(1)$ time and $\mathcal{O}(1)$ auxiliary space without iterating through partitions, making it both optimal and mathematically concise.

**Q2: How would you handle input size up to $10^7$ queries?**  
**A:** Since each query takes $\mathcal{O}(1)$, we can process $10^7$ queries within ~0.2 seconds using fast I/O (`cin.tie(nullptr)` or custom fast reader routines like `fread`).

**Q3: Can you reduce the space complexity?**  
**A:** The space is already strictly $\mathcal{O}(1)$ using a single 4-byte integer. It cannot be reduced further.

**Q4: What if the constraint on $w$ was up to $10^{18}$?**  
**A:** The logic remains completely identical. We would only need to read $w$ as a 64-bit integer (`long long` in C++), and the execution time remains $\mathcal{O}(1)$.

**Q5: What if Pete and Billy wanted to divide the watermelon into $k$ parts of even weight instead of 2?**  
**A:** The condition generalizes directly: each of the $k$ parts must be at least $2$. Hence, the minimum sum is $2k$. As long as $w$ is even and $w \ge 2k$, we can pick $(k - 1)$ parts of size $2$ and the final part of size $w - 2(k - 1)$, which will also be even and positive. Thus, the condition is `w % 2 == 0 && w >= 2 * k`.

**Q6: How would you test this code?**  
**A:** Test boundary points $w = 1, 2, 3, 4$, typical evens ($6, 8, 100$), typical odds ($5, 99$), and verify that only even numbers $\ge 4$ output `YES`.

---

## 📝 Key Takeaways

- **Parity Invariance:** In competitive programming, problems involving sums of even/odd numbers often boil down to invariant arithmetic properties ($\text{even} + \text{even} = \text{even}$).
- **Beware of Lower Boundaries:** $w = 2$ is the classic trap for this problem; always check whether boundary values meet the strict positivity condition ($> 0$).
- **Generalization Pattern:** The partition idea extends naturally to $k$ parts with minimum weight $2k$.

---

## 🔗 Related Codeforces Problems

- [71A - Way Too Long Words](https://codeforces.com/problemset/problem/71/A) (Rating: `800`) — String manipulation and boundary checking.
- [231A - Team](https://codeforces.com/problemset/problem/231/A) (Rating: `800`) — Implementation and counting conditions.
- [1A - Theatre Square](https://codeforces.com/problemset/problem/1/A) (Rating: `1000`) — Mathematical division, ceiling arithmetic, and 64-bit integer handling.

---

## 📄 Credits

*Solution by [Alok Kumar](https://github.com/alok-devforge)*  
*Problem belongs to Codeforces — Codeforces Beta Round 4 (Div. 2 Only).*

---

## 📂 Repo Metadata

**Suggested file path in `cp_codeforces` repo:**
```
Rating-800/4A-Watermelon.md
```

**One-line entry for my `README.md` index table (paste-ready):**

```markdown
| [4A](https://codeforces.com/problemset/problem/4/A) | Watermelon | 800 | Math, Brute Force | [Notes](./Rating-800/4A-Watermelon.md) | [C++](./Rating-800/4A-Watermelon.cpp) |
```
