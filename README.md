# BizLedger - Daily Business Tracker

A modern, responsive, single-page web application for tracking daily business income, expenses, profit, and multi-wallet account balances (Bank, bKash, Cash, Nagad) with dual-currency support (BDT ৳ & USD $) and live exchange rate auto-updates.

## 🚀 Features

- **Multi-Account & Wallet System**:
  - Track individual balances across Bank, bKash, Cash in Hand, Nagad, or custom accounts.
  - Automatically view **Combined Initial Capital** and **Combined Current Balance**.
  - Deduct expenses directly from specific accounts (e.g. paying rent from Bank only affects Bank and the Combined Total).
- **Dual-Currency & Live Daily Exchange Rates**:
  - Live auto-fetching of daily USD to BDT rates from open exchange web APIs.
  - One-click refresh and custom manual rate override.
  - Live side-by-side conversion for all amounts (BDT ৳ and USD $).
  - Historical rate locking: past transactions preserve their exact exchange rate permanently.
- **Interactive Dashboard**:
  - Summary cards for Combined Initial Capital, Total Income, Total Expenses, and Net Profit / Available Balance.
  - Dynamic status indicators for Profitable, Net Loss, or Break-Even.
- **Transaction History & Controls**:
  - Add transactions with Date, Description, Account/Wallet, Currency, and Amount.
  - Filter transactions by Account or Type (Income / Expense).
  - Individual Delete with modal confirmation.
  - Export all data to CSV anytime.
- **100% Client-Side & Offline-Ready**:
  - Uses browser `localStorage` to securely persist all accounts, transactions, and settings without any external database.
  - Styled with Tailwind CSS via CDN.

## 💻 How to Use

1. Clone or download the repository.
2. Open `index.html` directly in any web browser (Chrome, Edge, Firefox, Safari).
3. Set your initial balances under **"Add / Manage Accounts"** and start recording transactions!

## 📄 License
MIT License
