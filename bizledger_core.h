/**
 * ============================================================================
 * Project: BizLedger — Business & Finance Tracker
 * Module:  bizledger_core.h (C Header & Interface Definitions)
 * Author:  Raisul Alam & Senior Systems Architecture Team
 * ============================================================================
 */

#ifndef BIZLEDGER_CORE_H
#define BIZLEDGER_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

/* 1. Core Data Structures */
typedef struct {
    char code[4];             /* 3-letter currency code, e.g. "BDT", "USD" */
    char symbol[8];           /* Currency symbol, e.g. "$", "৳", "€" */
    double rate_to_usd;       /* Rate equivalent to 1 USD */
} Currency;

typedef struct {
    char id[32];              /* Unique account identifier */
    char name[64];            /* Account display name */
    char currency[4];         /* Native account currency code */
    double initial_balance;   /* Baseline opening deposit */
    double current_balance;   /* Live calculated balance */
} Account;

typedef struct {
    char id[32];              /* Transaction ID */
    char date[12];            /* YYYY-MM-DD */
    char type[8];             /* "Income" or "Expense" */
    char description[128];    /* Transaction note */
    double amount;            /* Amount in transaction currency */
    char currency[4];         /* Currency code */
    char account_id[32];      /* Target wallet ID */
    double usd_equivalent;    /* Converted USD value */
} Transaction;

typedef struct {
    double total_initial_capital;
    double total_income;
    double total_expense;
    double net_cash_flow;
    double current_total_balance;
    double capital_growth_pct;
    double inflow_ratio_pct;
} FinancialSummary;

/* 2. Exported C Functions (WebAssembly / Native API) */

/**
 * Converts an amount from one currency to another using USD pivot.
 */
double convert_currency(double amount, double from_rate_to_usd, double to_rate_to_usd);

/**
 * Computes current wallet balance from initial, inflows, and outflows.
 */
double calculate_account_balance(double initial_balance, double total_income, double total_expense);

/**
 * Calculates net cash flow (Income - Expenses).
 */
double calculate_net_cash_flow(double total_income, double total_expense);

/**
 * Calculates percentage capital growth vs initial capital.
 */
double calculate_capital_growth(double initial_capital, double current_balance);

/**
 * Calculates the percentage ratio of inflows over total turnover.
 */
double calculate_inflow_ratio(double total_income, double total_expense);

/**
 * Batch calculation of complete financial summary.
 */
void compute_financial_summary(
    const double* initial_balances, int num_accounts,
    const double* income_amounts,   int num_incomes,
    const double* expense_amounts,  int num_expenses,
    FinancialSummary* out_summary
);

#ifdef __cplusplus
}
#endif

#endif /* BIZLEDGER_CORE_H */
