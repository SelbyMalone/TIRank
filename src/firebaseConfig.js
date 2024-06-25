// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
    apiKey: "AIzaSyDE7DDsHfx-Bazp5N1E8CYXwxtNZ9tZiTk",
    authDomain: "ti-rank.firebaseapp.com",
    projectId: "ti-rank",
    storageBucket: "ti-rank.appspot.com",
    messagingSenderId: "264282843862",
    appId: "1:264282843862:web:f029f14df7dfbcbd957777",
    measurementId: "G-KW9QZTD5JT"
};

// Initialize Firebase
export const app = initializeApp(firebaseConfig);
export const analytics = getAnalytics(app);