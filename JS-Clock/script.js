const sNeedle = document.querySelector(".s-needle");
const mNeedle = document.querySelector(".m-needle");
const hNeedle = document.querySelector(".h-needle");

h3 = document.querySelector("h3");

const createNumbers = () => {
  const numbers = document.querySelector(".numbers");
  for (let i = 1; i <= 60; i++) {
    const dash = document.createElement("div");
    dash.classList.add("dash");
    const d = document.createElement("div");
    d.classList.add("d");
    dash.style.transform = `rotate(${(i / 5) * 30}deg)`;
    dash.appendChild(d);
    numbers.appendChild(dash);
    if (i % 5 == 0) {
      const number = document.createElement("div");
      const p = document.createElement("p");
      p.innerText = i / 5;
      p.style.transform = `rotate(${-(i / 5) * 30}deg)`;
      number.appendChild(p);
      number.classList.add("number");
      number.style.transform = `rotate(${(i / 5) * 30}deg)`;
      numbers.appendChild(number);
      d.classList.add("small");
    }
  }
};

const rotate = () => {
  const dt = new Date();

  const sRotationDeg = -90 + (dt.getSeconds() * 360) / 60;
  const mRotationDeg = -90 + (dt.getMinutes() * 360) / 60;
  const hRotationDeg = -90 + (dt.getHours() * 360) / 12;

  sNeedle.style.transform = `rotate(${sRotationDeg}deg)`;
  mNeedle.style.transform = `rotate(${mRotationDeg}deg)`;
  hNeedle.style.transform = `rotate(${hRotationDeg}deg)`;

  h3.innerText = new Date().toLocaleTimeString();
};

createNumbers();
rotate();
setInterval(rotate, 1000);
