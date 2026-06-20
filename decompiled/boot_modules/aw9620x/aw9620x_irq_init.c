__int64 __fastcall aw9620x_irq_init(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x1
  __int64 v4; // x0
  int v5; // w0
  __int64 v6; // x1
  int v7; // w5
  int v8; // w20
  int v9; // w0
  __int64 v10; // x1
  unsigned int v11; // w20
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v14; // [xsp+10h] [xbp-20h]
  _WORD v15[7]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v16; // [xsp+28h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 48);
  v14 = 0;
  memset(v15, 0, sizeof(v15));
  *(_QWORD *)s = 0;
  dev_printk(&unk_142BB, v2, "[%s:%d] enter\n", "aw9620x_irq_init", 2732);
  snprintf(s, 0x1Eu, "aw_sar%u_irq", *(_DWORD *)(a1 + 8));
  v3 = *(_QWORD *)(a1 + 48);
  if ( (*(_DWORD *)(a1 + 12) & 0x80000000) == 0 )
  {
    dev_printk(&unk_142BB, v3, "[%s:%d] gpio_is_valid-sar%d\n", "aw9620x_irq_init", 2738, *(_DWORD *)(a1 + 8));
    v4 = gpio_to_desc(*(unsigned int *)(a1 + 12));
    v5 = gpiod_to_irq(v4);
    v6 = *(_QWORD *)(a1 + 48);
    v7 = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(a1 + 28) = v5;
    dev_printk(&unk_142BB, v6, "[%s:%d] gpio_to_irq-sar%d\n", "aw9620x_irq_init", 2740, v7);
    v8 = devm_gpio_request_one(*(_QWORD *)(a1 + 48), *(unsigned int *)(a1 + 12), 3, s);
    dev_printk(
      &unk_142BB,
      *(_QWORD *)(a1 + 48),
      "[%s:%d] devm_gpio_request_one-sar%d\n",
      "aw9620x_irq_init",
      2745,
      *(_DWORD *)(a1 + 8));
    if ( v8 )
    {
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(a1 + 48),
        "[%s:%d] request irq gpio failed, ret = %d\n",
        "aw9620x_irq_init",
        2748,
        v8);
    }
    else
    {
      v9 = devm_request_threaded_irq(
             *(_QWORD *)(a1 + 48),
             *(unsigned int *)(a1 + 28),
             0,
             aw9620x_irq,
             8194,
             "aw9620x_irq",
             a1);
      v10 = *(_QWORD *)(a1 + 48);
      if ( !v9 )
      {
        dev_printk(&unk_13D4F, v10, "[%s:%d] IRQ request successfully!\n", "aw9620x_irq_init", 2765);
        v11 = 0;
LABEL_9:
        dev_printk(&unk_13D4F, *(_QWORD *)(a1 + 48), "[%s:%d] disable_irq\n", "aw9620x_irq_init", 2774);
        disable_irq(*(unsigned int *)(a1 + 28));
        *(_BYTE *)(a1 + 5) = 1;
        goto LABEL_10;
      }
      dev_printk(
        &unk_134C0,
        v10,
        "[%s:%d] failed to request IRQ %d: %d\n",
        "aw9620x_irq_init",
        2761,
        *(_DWORD *)(a1 + 28),
        v9);
    }
    v11 = -1;
    goto LABEL_9;
  }
  dev_printk(&unk_134C0, v3, "[%s:%d] irq gpio invalid!\n", "aw9620x_irq_init", 2770);
  v11 = -1;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v11;
}
