const btn = document.querySelector('.btn');

btn.addEventListener('click', (e) => {
    e.preventDefault();
    
    console.log('click');
    console.log(e);
    console.log(e.target);
    
    document.querySelector('#my-form').style.background = '#ccc';
    document.querySelector('body').classList.add('bg-dark');
});