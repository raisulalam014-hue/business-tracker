# BizLedger - Daily Business Tracker

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](CONTRIBUTING.md)

A modern, responsive, single-page web application for tracking daily business income, expenses, profit, and multi-wallet account balances (Bank, bKash, Cash, Nagad) with dual-currency support (BDT ৳ & USD $) and live exchange rate auto-updates.

---

## 🌟 Key Features

### 🏦 Multi-Account & Wallet System
- Track separate balances across **Bank Account**, **bKash**, **Cash in Hand**, **Nagad**, or custom accounts.
- View **Combined Initial Capital** and **Combined Current Balance** in real time.
- Routing: Expenses deduct specifically from the chosen account and the combined total, leaving other wallets unaffected.

### 🌐 Dual-Currency & Live Exchange Rates
- Daily auto-fetching of live exchange rates from open web APIs (USD, BDT, EUR, GBP, SAR, AED, INR).
- One-click live rate refresh + manual custom override option.
- Automatic side-by-side conversion for all figures in **BDT (৳)** and **USD ($)**.
- **Historical Rate Locking**: Each transaction permanently locks its date's exact exchange rate to preserve accurate financial history.

### 📊 Summary Dashboard
- Three-level financial view: **Initial Capital**, **Income & Expenses**, and **Net Profit / Cash Available**.
- Dynamic visual indicators for Profitable, Net Loss, or Break-Even status.

### 📝 History & Export
- Formatted transaction table displaying account badges, currency pills, and formatted dates.
- Filter by Account (e.g. Bank only, bKash only) or by Transaction Type.
- One-click CSV export containing full multi-currency breakdowns.
- Secure, 100% private client-side data persistence via browser `localStorage`.

---

## 🚀 Live Demo & Usage

1. Open `index.html` directly in any modern web browser.
2. Or use GitHub Pages if deployed: [Live Demo](https://raisulalam014-hue.github.io/business-tracker/)
3. Click **"Add / Manage Accounts"** to configure your starting wallet balances, and you are ready to record transactions!

---

## 📂 Repository Structure

```text
business-tracker/
├── .github/
│   └── workflows/
│       └── deploy.yml      # Automatic GitHub Pages deployment
├── .gitignore              # Ignored files
├── CONTRIBUTING.md         # Guidelines for contributors
├── LICENSE                 # MIT License
├── README.md               # Project documentation
├── SECURITY.md             # Security policy
└── index.html              # Complete application code (HTML, CSS, JS)
```

---

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com/raisulalam014-hue/business-tracker/issues) or read [CONTRIBUTING.md](CONTRIBUTING.md).

---

## 📜 License

This project is licensed under the [MIT License](LICENSE) - see the [LICENSE](LICENSE) file for details.

Copyright (c) 2026 Raisul Alam
