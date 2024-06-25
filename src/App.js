import React from 'react';
import './App.css';
import { queryFirestore } from './firebaseScripts'


function App() {
    return (
        <div className="app row-flex">
            <div className="main-content">
                <div className="header">
                    Game History
                </div>
                main content
            </div>

            <div className="sidebar">
                <div className="header">
                    Ranks
                </div>
                <button onClick={queryFirestore}>Query Firestore</button>

                <p>Jade	1,121</p>
                <p>Mike	1,096</p>
                <p>Fry	1,065</p>
                <p>Jayden	1,052</p>
                <p>Keagan	1,035</p>
                <p>Will D	1,035</p>
                <p>Selby	1,030</p>
                <p>Nick	1,016</p>
                <p>Tiana	1,010</p>
                <p>Aaron	1,008</p>
                <p>Jane	978</p>
                <p>John	973</p>
                <p>Jordan	967</p>
                <p>Will R	962</p>
                <p>Peter	960</p>
                <p>Bob	938</p>
                <p>Doug	934</p>
                <p>Kai	928</p>
                <p>Rob	887</p>
            </div>
        </div>
    );
}

export default App;