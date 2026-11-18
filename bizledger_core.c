/**
 * ============================================================================
 * Project: BizLedger — Business & Finance Tracker
 * Module:  bizledger_core.c (C Computational Engine)
 * Author:  Raisul Alam & Senior Systems Architecture Team
 * Purpose: High-performance financial calculation core written in C,
 *          exportable as a native CLI binary or compiled to WebAssembly (WASM)
 *          to power the BizLedger Web Application frontend.
 * ============================================================================
 * 
 * Compilation Options:
 * 1. Native Binary (GCC / Clang):
 *    gcc -O3 bizledger_core.c -o bizledger_core.exe
 * 
 * 2. WebAssembly (Emscripten):
 *    emcc -O3 -s WASM=1 -s STANDALONE_WASM \
 *         -s EXPORTED_FUNCTIONS="['_convert_currency','_calculate_account_balance','_calculate_net_cash_flow','_calculate_capital_growth','_calculate_inflow_ratio']" \
 *         bizledger_core.c -o bizledger_core.wasm
 */

#include "bizledger_core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * ----------------------------------------------------------------------------
 * 1. CURRENCY CONVERSION ENGINE
 * ----------------------------------------------------------------------------
 * Converts a financial value between any two currencies using USD as pivot:
 * formula: (amount / from_rate_to_usd) * to_rate_to_usd
 */
double convert_currency(double amount, double from_rate_to_usd, double to_rate_to_usd) {
    if (from_rate_to_usd <= 0.0) from_rate_to_usd = 1.0;
    if (to_rate_to_usd <= 0.0) to_rate_to_usd = 1.0;
    
    double amount_in_usd = amount / from_rate_to_usd;
    return amount_in_usd * to_rate_to_usd;
}

/**
 * ----------------------------------------------------------------------------
 * 2. ACCOUNT BALANCE CALCULATION
 * ----------------------------------------------------------------------------
 * Calculates current balance for a wallet/account:
 * formula: Initial Balance + Total Inflow (Income) - Total Outflow (Expenses)
 */
double calculate_account_balance(double initial_balance, double total_income, double total_expense) {
    return initial_balance + total_income - total_expense;
}

/**
 * ----------------------------------------------------------------------------
 * 3. NET CASH FLOW POSITION
 * ----------------------------------------------------------------------------
 * Calculates net cash flow (Net Profit/Loss delta):
 * formula: Total Inflow - Total Outflow
 */
double calculate_net_cash_flow(double total_income, double total_expense) {
    return total_income - total_expense;
}

/**
 * ----------------------------------------------------------------------------
 * 4. CAPITAL GROWTH RATE (PERCENTAGE)
 * ----------------------------------------------------------------------------
 * Calculates percentage growth of total equity compared to initial baseline deposits:
 * formula: ((Current Balance - Initial Capital) / Initial Capital) * 100.0
 */
double calculate_capital_growth(double initial_capital, double current_balance) {
    if (initial_capital <= 0.0) {
        return 0.0;
    }
    return ((current_balance - initial_capital) / initial_capital) * 100.0;
}

/**
 * ----------------------------------------------------------------------------
 * 5. INFLOW / TURNOVER RATIO
 * ----------------------------------------------------------------------------
 * Calculates percentage of total turnover attributed to income inflows:
 * formula: (Income / (Income + Expense)) * 100.0
 */
double calculate_inflow_ratio(double total_income, double total_expense) {
    double turnover = total_income + total_expense;
    if (turnover <= 0.0) {
        return 50.0; // Default balanced ratio
    }
    return (total_income / turnover) * 100.0;
}

/**
 * ----------------------------------------------------------------------------
 * 6. BATCH FINANCIAL SUMMARY (C Data Structure Processing)
 * ----------------------------------------------------------------------------
 */
void compute_financial_summary(
    const double* initial_balances, int num_accounts,
    const double* income_amounts,   int num_incomes,
    const double* expense_amounts,  int num_expenses,
    FinancialSummary* out_summary
) {
    if (!out_summary) return;

    out_summary->total_initial_capital = 0.0;
    for (int i = 0; i < num_accounts; ++i) {
        out_summary->total_initial_capital += initial_balances[i];
    }

    out_summary->total_income = 0.0;
    for (int i = 0; i < num_incomes; ++i) {
        out_summary->total_income += income_amounts[i];
    }

    out_summary->total_expense = 0.0;
    for (int i = 0; i < num_expenses; ++i) {
        out_summary->total_expense += expense_amounts[i];
    }

    out_summary->net_cash_flow = calculate_net_cash_flow(
        out_summary->total_income,
        out_summary->total_expense
    );

    out_summary->current_total_balance = out_summary->total_initial_capital + out_summary->net_cash_flow;

    out_summary->capital_growth_pct = calculate_capital_growth(
        out_summary->total_initial_capital,
        out_summary->current_total_balance
    );

    out_summary->inflow_ratio_pct = calculate_inflow_ratio(
        out_summary->total_income,
        out_summary->total_expense
    );
}

/**
 * ----------------------------------------------------------------------------
 * NATIVE TEST RUNNER & VERIFICATION ENTRYPOINT
 * ----------------------------------------------------------------------------
 * If compiled directly as a native executable, demonstrates all functions.
 */
#ifdef NATIVE_RUNNER
int main(void) {
    printf("=====================================================\n");
    printf("   BizLedger C Computational Engine (Native Test)     \n");
    printf("=====================================================\n\n");

    // Test 1: Currency Conversion
    double usd_amount = 100.0;
    double bdt_rate = 122.25;
    double converted_bdt = convert_currency(usd_amount, 1.0, bdt_rate);
    printf("[1] Currency Conversion: $%.2f USD -> ৳%.2f BDT (Rate: %.2f)\n", 
           usd_amount, converted_bdt, bdt_rate);

    // Test 2: Account Balance
    double init_bal = 25000.0;
    double inc = 15000.0;
    double exp = 4500.0;
    double cur_bal = calculate_account_balance(init_bal, inc, exp);
    printf("[2] Account Balance: Init: ৳%.2f, +Inc: ৳%.2f, -Exp: ৳%.2f => Total: ৳%.2f\n", 
           init_bal, inc, exp, cur_bal);

    // Test 3: Net Cash Flow & Growth
    double net_flow = calculate_net_cash_flow(inc, exp);
    double growth = calculate_capital_growth(init_bal, cur_bal);
    double ratio = calculate_inflow_ratio(inc, exp);
    printf("[3] Net Cash Flow: ৳%.2f | Capital Growth: %.2f%% | Inflow Ratio: %.1f%%\n\n",
           net_flow, growth, ratio);

    printf(">> All C functions executed successfully.\n");
    return 0;
}
#endif
