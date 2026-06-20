__int64 __fastcall pmic_arb_debug_write_cmd(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        unsigned __int64 a6)
{
  _QWORD *v11; // x26
  unsigned int v12; // w24
  __int64 v14; // x25
  unsigned int v15; // w0
  unsigned int v16; // w0
  __int64 v17; // x25
  unsigned __int64 v18; // x8
  unsigned int v19; // w27
  int v20; // w28
  unsigned int v21; // w19
  __int64 v22; // x20

  if ( a6 >= 9 )
  {
    dev_err(a1, "pmic-arb supports 1 to %d bytes per transaction, but %zu requested\n", 8, a6);
    return 4294967274LL;
  }
  v11 = **(_QWORD ***)(a1 + 152);
  if ( (a2 & 0xE0) == 0x40 )
  {
    v12 = 14;
  }
  else if ( a2 >= 0x10u )
  {
    if ( (a2 & 0xF8) == 0x30 )
    {
      v12 = 0;
    }
    else
    {
      if ( (a2 & 0x80) == 0 )
        return 4294967274LL;
      v12 = 16;
    }
  }
  else
  {
    v12 = 2;
  }
  v14 = v11[2];
  v15 = clk_prepare(v14);
  if ( v15 )
  {
    v21 = v15;
  }
  else
  {
    v16 = clk_enable(v14);
    if ( !v16 )
    {
      v17 = raw_spin_lock_irqsave(v11 + 1);
      if ( a6 )
      {
        v18 = 0;
        v19 = 24;
        v20 = 1;
        do
        {
          writel_relaxed(*(unsigned __int8 *)(a5 + v18), *v11 + v19);
          v18 = v20;
          v19 += 4;
          ++v20;
        }
        while ( v18 < a6 );
      }
      v21 = pmic_arb_debug_issue_command(a1, v12, a3, a4, a6);
      raw_spin_unlock_irqrestore(v11 + 1, v17);
      v22 = v11[2];
      clk_disable(v22);
      clk_unprepare(v22);
      return v21;
    }
    v21 = v16;
    clk_unprepare(v14);
  }
  printk(&unk_6F40, "pmic_arb_debug_write_cmd", v21);
  return v21;
}
