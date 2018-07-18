# Dining philosophers problem


## Contributors

Theo Ferreira

## 0. Subject

A group of philosophers are dedicating themselves to a new project: dictating a group of rules about sharing
natural resources to prevent world famine.

Before making these rules public, they want to test them in a simulator.
You’ve been hired to supervise this simulator, so that the philosophers could finally be able to show the
whole world their infinite wisdom.

A huge responsibility rests on your shoulders: you must prove that your new friends have solved the famine
problem.

In order to avoid the stress that the risk of this mission carries, you’ll work in teams of two.

The problem was designed to illustrate the challenges of avoiding deadlock, a system state in which no progress is possible. To see that a proper solution to this problem is not obvious, consider a proposal in which each philosopher is instructed to behave as follows:
• N philosophers are around one table (N is defined on the command line)
• Each philosopher has one rice bowl in front of him
• There is a chopstick to the left of each bowl
• A philosopher can only use a chopstick if it is to the left or right of his bowls
• A philosopher goes through three steps:
• eat with two chopsticks. One left and one right.
• rest, does not use either chopstick, even if one is available.
• think, uses one and only one chopstick.

There are a few more rules to guarantee better digestion.
It is really important for them to be healthy and to assimilate the rice’s nutrients (that’s the real solution to
ending famine. . .) but you have to keep it a secret!

• A philosopher who thinks must eat before resting (obviously, to get his energy back).
• After resting, a philosopher can either eat or think.
• The think and eat states must have a time limit (to be determined by you).
• A chopstick cannot be used by two philosophers at the same time. For hygienic reasons.

Thus, you have to create this simulator and define a few limits (execution time of actions, resource usage
quota, program execution time,. . .)
Obviously, each resource can only be used by one person at any given time.
Otherwise, you might create a spatiotemporal disaster, the likes of which has never been seen.

## 1. Program

USAGE
> ./philo -p nbr_p -e nbr_e

DESCRIPTION
> -p nbr_p number of philosophers
> -e nbr_e maximum number times a philosopher eats before exiting the program

exemple:
> ./philo -p 100 -e 10
