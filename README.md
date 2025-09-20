# 💳 Bank Data Manager by V.R.Jadeja

![C](https://img.shields.io/badge/language-C-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Status](https://img.shields.io/badge/status-active-brightgreen.svg)

💳 Bank Data Manager by V.R.Jadeja
A simple yet powerful C program that allows users to securely store and manage their bank transaction data offline — no internet, no app, no server dependency. Just run the executable and keep your financial records safe and accessible anytime.

📌 Description
Bank Data Manager is designed for users who want a lightweight, offline solution to track their bank transactions. Whether your banking app is down, the server is unreachable, or you simply prefer privacy, this tool lets you:
- Record deposits and withdrawals
- View your current balance
- Review your transaction history
- Store up to 99 transactions securely in a local file
All data is saved in a file named bankData.txt, and protected by a PIN for secure access.

🔐 Features
- ✅ PIN-protected access
- 💰 Deposit and withdrawal tracking
- 📊 Balance check
- 📜 Transaction history viewer
- 🧾 Persistent storage using bankData.txt
- 🧹 Option to clear transaction history when full

🛠 How It Works
- The program uses an array of size 102:
- Index 0–98: Transaction history
- Index 99: Transaction count (TID)
- Index 100: Current balance
- All data is saved to and loaded from bankData.txt automatically.
- Transactions are stored as positive (deposit) or negative (withdrawal) integers.

⚠️ Important Note
If you reach the maximum of 99 transactions, the program will prompt you to clear the history.
If you want to preserve all 100 transactions, you must move the bankData.txt file and bankdata.exe executable to a different location. This allows the program to create a new file and continue tracking without overwriting previous data(don't forget your previous balance to add in new).

🚀 Getting Started
- Compile the program using a C compiler:
"gcc BankDataManager.c -o BankDataManager.exe"
- Run the executable:
"./BankDataManager.exe"
- Enter your PIN (default: 700182) to access the system.
- Go to code at line 39 and change the pin value to set your own

📂 File Structure
BankDataManager/
├── bankdata.c          # Source code
├── bankdata.exe        # Compiled executable
└── bankData.txt        # Auto-generated transaction data file



👨‍💻 Author
Vishvdeepsinh R Jadeja
Passionate about building secure, offline-first tools for everyday use.

Let me know if you'd like a badge section, license, or GitHub Actions setup too!

---

## 📄 License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).

You are free to use, modify, and distribute this software for personal or commercial purposes. Just make sure to credit the original author:

**Vishvdeepsinh R Jadeja**

