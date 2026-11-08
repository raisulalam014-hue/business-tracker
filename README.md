# BizLedger - Universal Multi-Currency Business Tracker

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Pages](https://img.shields.io/badge/GitHub%20Pages-Live%20Demo-brightgreen.svg)](https://raisulalam014-hue.github.io/business-tracker/)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-blue.svg)](CONTRIBUTING.md)

A modern, responsive single-page web application for tracking daily business income, expenses, profit, and multi-wallet account balances (Bank, bKash, Cash, Upwork USD, etc.) with support for **35+ world currencies** and daily auto-updated exchange rates.

---

## 🌟 Key Features

### 💱 35+ Global Currencies & Universal Converter
- Supports conversions across major world currencies: **BDT (৳)**, **USD ($)**, **EUR (€)**, **GBP (£)**, **INR (₹)**, **SAR (﷼)**, **AED (د.إ)**, **CAD (CA$)**, **AUD (AU$)**, **SGD (SG$)**, **MYR (RM)**, **QAR (﷼)**, **KWD (د.ك)**, **JPY (¥)**, **CNY (¥)**, **TRY (₺)**, and more.
- **Interactive Quick Converter Tool**: Convert any amount on the spot between any two world currencies.
- **Daily Auto-Updated Exchange Rates**: Automatically fetches fresh market rates from open web APIs in the background.

### 🏦 Multi-Currency Wallets & Accounts
- Assign native currencies to each account (e.g. Bank in BDT, Upwork / PayPal in USD, European Client in EUR).
- Automatically calculates **Combined Initial Capital** and **Combined Current Cash Balance** in your preferred currency.
- When an expense is recorded, it deducts from that specific account and your combined total.

### 🔄 Customizable Primary & Secondary Display
- Switch your primary business view currency (e.g., BDT or USD) with one click.
- Choose a secondary counter-currency for side-by-side conversion previews on all summary cards and table rows.

### 📝 History & Data Privacy
- Filter history by Account or Transaction Type.
- One-click CSV export with detailed multi-currency breakdowns.
- 100% private, client-side persistence using `localStorage`.

---

## 🚀 Live Demo & Usage

- **Live Web App**: [https://raisulalam014-hue.github.io/business-tracker/](https://raisulalam014-hue.github.io/business-tracker/)
- Or clone this repository and open `index.html` directly in any web browser!

---

## 📂 Repository Structure

```text
business-tracker/
├── .github/
│   └── workflows/
│       └── deploy.yml      # Automatic GitHub Pages deployment
├── .gitignore              # Ignored files
├── CONTRIBUTING.md         # Guidelines for contributors
├── LICENSE                 # MIT License (2026 Raisul Alam)
├── README.md               # Documentation
├── SECURITY.md             # Security policy
└── index.html              # Complete application code (HTML, CSS, JS)
```

---

## 📜 License

Licensed under the [MIT License](LICENSE) - Copyright (c) 2026 Raisul Alam.
