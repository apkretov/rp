function addNums1(num1, num2) {
    console.log(num1 + num2);
}
addNums1(1, 0);

const addNums2 = (num1, num2) => {
    console.log(num1 + num2);
}
addNums2(2, 0);

const addNums3 = (num1, num2) => console.log(num1 + num2);
addNums3(3, 0);

const addNums4 = (num1, num2) => {return num1 + num2};
console.log(addNums4(4, 0));

const addNums5 = (num1, num2) => num1 + num2;
console.log(addNums5(5, 0));

const addNums6 = num1 => num1 + 5;
console.log(addNums6(1));

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
todos.forEach((todo) => console.log(todo.text));