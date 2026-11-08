# BizLedger - Universal Multi-Currency Business Tracker & PWA

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub Pages](https://img.shields.io/badge/GitHub%20Pages-Live%20Demo-brightgreen.svg)](https://raisulalam014-hue.github.io/business-tracker/)
[![PWA Ready](https://img.shields.io/badge/PWA-Installable-emerald.svg)](https://raisulalam014-hue.github.io/business-tracker/)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-blue.svg)](CONTRIBUTING.md)

A modern, mobile-optimized Progressive Web Application (PWA) for tracking business income, expenses, profit, and multi-wallet accounts (Bank, bKash, Cash, Upwork USD, etc.) with support for **35+ world currencies**, live daily ups & downs fluctuations, permanent data persistence, and offline capability.

---

## 📱 Mobile App & PWA Features

- **Installable on Android & iOS**: Add to your home screen directly from Chrome, Samsung Internet, or Safari as a standalone app with its custom logo and splash screen.
- **Mobile-First Responsive Interface**:
  - High-density 2x2 dashboard cards on mobile screens.
  - Native card-based transaction history feed (replaces clumsy horizontal table scrolling on phones).
  - One-hand bottom floating navigation bar (`➕ Add`, `🏦 Wallets`, `💱 Rates`, `🛡️ Backup`, `📲 Install`).
- **Offline Reliability**: Powered by a Service Worker (`sw.js`) and Web App Manifest (`manifest.json`) for fast loading even without internet.
- **Custom Brand Identity**: High-resolution vector logo (`icon.svg`), app icons (`192x192`, `512x512`), and favicon.

---

## 🌟 Key Capabilities

### 💱 35+ Global Currencies & Real-Time Market Fluctuations
- Track live rates and daily ups & downs (▲ / ▼ percentage shifts) across **BDT (৳)**, **USD ($)**, **EUR (€)**, **GBP (£)**, **INR (₹)**, **SAR (﷼)**, **AED (د.إ)**, **CAD (CA$)**, **AUD (AU$)**, **SGD (SG$)**, **MYR (RM)**, **QAR (﷼)**, **KWD (د.ك)**, **JPY (¥)**, **CNY (¥)**, **TRY (₺)**, and more.
- **Interactive Quick Converter Tool**: Instant on-the-fly currency calculations.
- **Daily Auto-Updated Exchange Rates**: Fetches live rates in the background from open web APIs every 5 minutes.

### 🏦 Multi-Currency Wallets & Accounts
- Assign native currencies to each account (e.g., Bank in BDT, Upwork in USD, Cash in BDT, International in EUR).
- Automatically calculates **Combined Initial Capital** and **Combined Current Cash Balance** converted into your preferred currency.
- Spending deducts from the specific wallet and updates combined totals.

### 🛡️ Permanent Data Protection & Backup / Restore
- **Permanent Storage**: Locked keys with automatic legacy version migration to prevent data loss across updates.
- **Persistent Storage API**: Calls `navigator.storage.persist()` to safeguard against browser eviction.
- **One-Click JSON Backup & Restore**: Export all financial records to a `.json` file anytime and restore on any device.

### 🔄 Dual Currency Display & CSV Export
- Switch primary business view currency (e.g., BDT or USD) with one click.
- Secondary counter-currency previews on all summary cards and transaction rows.
- Detailed CSV spreadsheet exports.

---

## 🚀 Live Web App & Installation

- **Live URL**: [https://raisulalam014-hue.github.io/business-tracker/](https://raisulalam014-hue.github.io/business-tracker/)

### How to Install on Android Phone:
1. Open [https://raisulalam014-hue.github.io/business-tracker/](https://raisulalam014-hue.github.io/business-tracker/) in **Google Chrome** on your phone.
2. Tap the **"Install Now"** banner at the top, or tap the **"📲 Install"** button on the bottom bar.
3. Or tap Chrome's three dots menu (⋮) > **"Install app"** (or **"Add to Home screen"**).
4. The app icon will appear on your phone's home screen and app drawer just like a native app from the Play Store!

---

## 📂 Repository Structure

```text
business-tracker/
├── .github/
│   └── workflows/
│       └── deploy.yml          # Automated GitHub Pages CI/CD
├── icon.svg                    # Brand vector logo
├── favicon.svg                 # SVG favicon
├── favicon.png                 # 64x64 PNG favicon
├── icon-192.png                # 192x192 Android PWA icon
├── icon-512.png                # 512x512 High-Res PWA icon
├── apple-touch-icon.png        # 180x180 iOS home screen icon
├── manifest.json               # Web App Manifest
├── sw.js                       # Service Worker for PWA & offline cache
├── CONTRIBUTING.md             # Contribution guidelines
├── LICENSE                     # MIT License (2026 Raisul Alam)
├── README.md                   # Full documentation
├── SECURITY.md                 # Security policy
└── index.html                  # Core single-page application
```

---

## 📜 License

Licensed under the [MIT License](LICENSE) - Copyright (c) 2026 Raisul Alam.
