#!/usr/bin/env python3
import sys

def load_config(filepath):
    config = {}
    with open(filepath, 'r') as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            if line.startswith('#'):
                # Handle "# CONFIG_XXX is not set"
                parts = line.split()
                if len(parts) >= 5 and parts[4] == 'not' and parts[5] == 'set':
                    opt = parts[1]
                    config[opt] = 'is not set'
            elif '=' in line:
                opt, val = line.split('=', 1)
                config[opt] = val
    return config

def main():
    stock = load_config('stock_config.txt')
    custom = load_config('kernel_platform/common/arch/arm64/configs/nx809j_defconfig')
    
    all_opts = sorted(list(set(stock.keys()) | set(custom.keys())))
    
    print(f"{'Option':<50} | {'Stock':<20} | {'Custom':<20}")
    print("-" * 96)
    
    interesting_prefixes = ('CONFIG_QCOM', 'CONFIG_ARM', 'CONFIG_CLK', 'CONFIG_MAILBOX', 'CONFIG_SCMI', 'CONFIG_SCHED', 'CONFIG_PINCTRL', 'CONFIG_POWER', 'CONFIG_REGULATOR')
    
    for opt in all_opts:
        if not opt.startswith(interesting_prefixes):
            continue
        val_stock = stock.get(opt, 'MISSING')
        val_custom = custom.get(opt, 'MISSING')
        if val_stock != val_custom:
            print(f"{opt:<50} | {val_stock:<20} | {val_custom:<20}")

if __name__ == '__main__':
    main()
