import argparse
import random
import subprocess
import math

parser = argparse.ArgumentParser()

parser.add_argument("size", type=int,
                    help="argument size.")
parser.add_argument("times", type=int,
                    help="test times.")
parser.add_argument("-s", help="output rundom number string",
                    action="store_true")
args = parser.parse_args()

step_list = []

for num in range(args.times):
    num_list = list(range(args.size))
    random.shuffle(num_list)
    s = ' '.join(map(str, num_list))
    output = subprocess.Popen("./push_swap " + s, shell=True,
                        stdout=subprocess.PIPE)
    steps = subprocess.run("./push_swap " + s, shell=True,
                        capture_output=True, text=True).stdout.count('\n')
    step_list.append(steps)
    print("step: " + str(steps) + ", ", end="")
    result = subprocess.run("./checker " + s, shell=True,
                        stdin=output.stdout, capture_output=True, text=True)
    print("result: " + result.stdout, end="")

print("")
print("min score: " + str(min(step_list)))
print("max score: " + str(max(step_list)))
print("score average: " + str(math.ceil(sum(step_list) / args.times)))