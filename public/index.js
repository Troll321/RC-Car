const connect = document.getElementById("connect");
const up = document.getElementById("up");
const right = document.getElementById("right");
const bottom = document.getElementById("bottom");
const left = document.getElementById("left");
const output = document.getElementById("output");

function print(text) {
    output.innerText = text;
}

connect.addEventListener("click", async () => {
    print("Connecting");

    try { 
        const devices = await navigator.bluetooth.requestDevice({
            acceptAllDevices: true
        });

        print(devices.name);
    } catch (err) {
        print(err);
    }
});

