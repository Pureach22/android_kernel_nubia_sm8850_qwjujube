__int64 __fastcall pmic_arb_debug_read_cmd(
        __int64 a1,
        char a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        unsigned __int64 a6)
{
  _QWORD *v10; // x26
  unsigned int v12; // w25
  __int64 v13; // x23
  unsigned int v14; // w0
  unsigned int v15; // w0
  __int64 v16; // x23
  unsigned int v17; // w21
  unsigned __int64 v18; // x22
  unsigned int v19; // w24
  int v20; // w25
  __int64 v21; // x19
  unsigned int v23; // w19

  v10 = **(_QWORD ***)(a1 + 152);
  if ( a2 <= 95 )
  {
    if ( (a2 & 0xF0) == 0x20 )
    {
      v12 = 13;
    }
    else
    {
      if ( (a2 & 0xF8) != 0x38 )
        return 4294967274LL;
      v12 = 1;
    }
  }
  else
  {
    v12 = 15;
  }
  v13 = v10[2];
  v14 = clk_prepare(v13);
  if ( v14 )
  {
    v23 = v14;
LABEL_18:
    printk(&unk_6F40, "pmic_arb_debug_read_cmd", v23);
    return v23;
  }
  v15 = clk_enable(v13);
  if ( v15 )
  {
    v23 = v15;
    clk_unprepare(v13);
    goto LABEL_18;
  }
  v16 = raw_spin_lock_irqsave(v10 + 1);
  v17 = pmic_arb_debug_issue_command(a1, v12, a3, a4, a6);
  if ( !v17 && a6 )
  {
    v18 = 0;
    v19 = 56;
    v20 = 1;
    do
    {
      *(_BYTE *)(a5 + v18) = readl_relaxed((unsigned int *)(*v10 + v19));
      v18 = v20;
      v19 += 4;
      ++v20;
    }
    while ( v18 < a6 );
  }
  raw_spin_unlock_irqrestore(v10 + 1, v16);
  v21 = v10[2];
  clk_disable(v21);
  clk_unprepare(v21);
  return v17;
}
