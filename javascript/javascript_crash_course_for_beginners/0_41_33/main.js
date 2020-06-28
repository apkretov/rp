const todos = [
    {
        id: 1,
        text: 'Take out trash',
        isCompleted: true
    },
    {
        id: 2,
        text: 'Meeing with boss',
        isCompleted: true
    },
    {
        id: 3,
        text: 'Dentist appt',
        isCompleted: false
    }
];

for (todo of todos)
    console.log(todo.text);

todos.forEach(function(todo) {
    console.log(todo.id);
});

const todoText = todos.map(function(todo) {
    return todo.text;
})
console.log(todoText);

const todoCompleted = todos.filter(function(todo) {
    return todo.isCompleted === true;
});
console.log(todoCompleted);

const todoTextCompleted = todos.filter(function(todo) {
    return todo.isCompleted === true;
}).map(function(todo) {
    return todo.text;
});
console.log(todoTextCompleted);