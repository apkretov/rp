import React, { Component } from 'react'; // React.Component option 1.
// import React from 'react'; // React.Component option 2.

import Todos from './components/Todos';
import './App.css';

class App extends Component { // React.Component option 1.
// class App extends React.Component { // React.Component option 2.
  render() {
    return (
      <div className="App">
        <Todos/>
      </div>
    );
  }
}

export default App;
