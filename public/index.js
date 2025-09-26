const connect = document.getElementById("connect");
const up = document.getElementById("up");
const right = document.getElementById("right");
const bottom = document.getElementById("bottom");
const left = document.getElementById("left");
const output = document.getElementById("output");

function print(text) {
    output.innerText = text;
    console.log(text);
}

connect.addEventListener("click", async () => {
    print("Connecting");

    const port = await navigator.serial.requestPort();
});

