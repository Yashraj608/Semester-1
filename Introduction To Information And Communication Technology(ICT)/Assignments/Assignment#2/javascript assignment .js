const prompt = require('prompt-sync')();
let tasks = [];

function addtask() {
    console.log("WHAT TASK WOULD YOU LIKE TO ADD");
    const task = prompt("Enter task: ");
    tasks.push(task);
    console.log(`TASK ADDED : "${task}"`);
}

function removetask() {
    if (tasks.length === 0) {
        console.log("NO TASKS AVAILABLE TO REMOVE.");
        return;
    }

    console.log("ENTER THE TASK NUMBER THAT YOU WANT TO REMOVE");
    const i = parseInt(prompt("Enter the task number to remove: ")) - 1;

    if (i >= 0 && i < tasks.length) {
        const removeTask = tasks.splice(i, 1);
        console.log(`Task removed: "${removeTask}"`);
    } else {
        console.log("Invalid task number. Please try again.");
    }
}

function displaytasks() {
    if (tasks.length !== 0) {
        console.log("TASKS LIST : ");
        for (let i = 0; i < tasks.length; i++) {
            console.log(`${i + 1}.${tasks[i]}`);
        }
    } else {
        console.log("NO TASKS TO SHOW");
    }
}

function cleartask() {
    tasks = [];
    console.log("ALL TASKS CLEARED");
}

while (true) {
    console.log("\nTask Manager");
    console.log("1. Add Task");
    console.log("2. Remove Task");
    console.log("3. Display Tasks");
    console.log("4. Clear Tasks");
    console.log("5. Exit");

    const choice = prompt("Choose an option: ");

    switch (choice) {
        case "1":
            addtask();
            break;
        case "2":
            removetask();
            break;
        case "3":
            displaytasks();
            break;
        case "4":
            cleartask();
            break;
        case "5":
            console.log("Exiting Task Manager...");
            process.exit();
        default:
            console.log("Invalid option. Please choose a number between 1 and 5.");
    }
}
