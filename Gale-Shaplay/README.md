# Gale-Shapley Stable Marriage Algorithm

## Overview

The Gale-Shapley Stable Marriage Algorithm, also known as the stable marriage algorithm, is used to solve the stable marriage problem. In this problem, there are two groups of individuals, such as men and women, each having their own preferences over the members of the opposite group. The goal is to find a stable matching, where no individuals in the two groups prefer each other over their current partners.

## Input and Output Representation

In the algorithm, the input is structured as follows:

- **Integer N:** Represents the cardinality of each group.

- **For 2*N lines:** For each person from 0 to 2*N-1, input their list of preferences of size N.

The input format ensures that the preferences of each individual from both groups are specified, forming the basis for the stable marriage problem.

The output adheres to the following structure:

- **A vector of integers of size N:** Represents the pairing of the element at index i with the node arr[i]. In the context of the stable marriage problem, the vector indicates that the woman at index + N is paired with the man at arr[index].

This output format provides a clear mapping of individuals from one group to their respective partners in the other group, demonstrating the stable matching achieved by the Gale-Shapley algorithm.

## When to Use Gale-Shapley Algorithm

The Gale-Shapley Stable Marriage Algorithm is applicable in scenarios where:

- **Matching Problem:** There is a need to match two equally sized sets of entities, such as men and women, hospitals and residents, or schools and students, based on their preferences.

- **Stability Requirement:** Ensuring that the resulting matches are stable, meaning there are no pairs of individuals who would both prefer to be with each other over their current partners.

- **Optimizing Preferences:** The goal is to optimize the matching based on the preferences of the entities involved, taking their priorities into account.

