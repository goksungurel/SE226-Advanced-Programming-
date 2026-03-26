tasks = {}
execution_order = []
completed_tasks = set()

n = int(input("Enter number of tasks: "))

for _ in range(n):
    taskname = input("Enter task name: ")

    numdep = int(input(f"How many dependencies for {taskname}? "))

    dependencies = []
    for j in range(numdep):
        dep_name = input(f"Enter dependency {j + 1}: ")
        dependencies.append(dep_name)

    tasks[taskname] = dependencies

print("\nTASK STRUCTURE:")
for task, deps in tasks.items():
    print(f"{task} -> {deps}")

print("\nINITIAL TASKS (no dependencies):")
initial_tasks = [t for t, d in tasks.items() if len(d) == 0]
if not initial_tasks:
    print("None")
else:
    for t in initial_tasks:
        print(t)

while len(completed_tasks) < len(tasks):
    progress_made = False
    for task, deps in tasks.items():
        if task not in completed_tasks:
            if all(d in completed_tasks for d in deps):
                completed_tasks.add(task)
                execution_order.append(task)
                progress_made = True
                break

    if not progress_made:
        print("\nEXECUTION ORDER:")
        print("No task can be started.")
        print("ERROR: Circular dependency detected!")
        print("These tasks could not be completed:")
        for t in tasks:
            if t not in completed_tasks:
                print(t)

print("\nEXECUTION ORDER:")
for i, task in enumerate(execution_order, 1):
    print(f"Step {i}: {task}")

print("\nALL TASKS COMPLETED SUCCESSFULLY")  
