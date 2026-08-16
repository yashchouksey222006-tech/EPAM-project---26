let balance = 25000;

function deposit() {
    let amount = Number(document.getElementById("amount").value);

    if (amount <= 0) {
        document.getElementById("message").innerText =
            "Please enter a valid amount.";
        return;
    }

    balance = balance + amount;

    document.getElementById("balance").innerText = balance;
    document.getElementById("message").innerText =
        "₹" + amount + " deposited successfully.";

    document.getElementById("amount").value = "";
}

function withdraw() {
    let amount = Number(document.getElementById("amount").value);

    if (amount <= 0) {
        document.getElementById("message").innerText =
            "Please enter a valid amount.";
        return;
    }

    if (amount > balance) {
        document.getElementById("message").innerText =
            "Insufficient balance.";
        return;
    }

    balance = balance - amount;

    document.getElementById("balance").innerText = balance;
    document.getElementById("message").innerText =
        "₹" + amount + " withdrawn successfully.";

    document.getElementById("amount").value = "";
}