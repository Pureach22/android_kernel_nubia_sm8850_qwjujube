__int64 __fastcall dp_request_irq(__int64 a1)
{
  _QWORD *v1; // x22
  unsigned int v3; // w19
  unsigned int *v4; // x21
  unsigned int v5; // w0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0

  if ( a1 )
  {
    v1 = (_QWORD *)(a1 - 1144);
    v3 = irq_of_parse_and_map(*(_QWORD *)(*(_QWORD *)(a1 - 1144) + 760LL), 0);
    v4 = (unsigned int *)(a1 - 1160);
    *(_DWORD *)(a1 - 1160) = v3;
    if ( (v3 & 0x80000000) != 0 )
    {
      if ( !g_dp_display || (v8 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v8 = 0;
      ipc_log_string(v8, "[e][%-4d]failed to get irq: %d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v3);
      printk(&unk_22D7B1, "dp_request_irq");
    }
    else
    {
      v5 = devm_request_threaded_irq(*v1 + 16LL, v3, dp_display_irq, 0, 4, "dp_display_isr");
      if ( (v5 & 0x80000000) != 0 )
      {
        v3 = v5;
        if ( !g_dp_display || (v9 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v9 = 0;
        ipc_log_string(
          v9,
          "[e][%-4d]failed to request IRQ%u: %d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *v4,
          v3);
        printk(&unk_22694D, "dp_request_irq");
      }
      else
      {
        disable_irq(*v4);
        return 0;
      }
    }
  }
  else
  {
    if ( !g_dp_display || (v7 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v7 = 0;
    ipc_log_string(v7, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_request_irq");
    return (unsigned int)-22;
  }
  return v3;
}
