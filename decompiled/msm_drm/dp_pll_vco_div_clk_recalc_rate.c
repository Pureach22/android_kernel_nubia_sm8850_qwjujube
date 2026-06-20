unsigned __int64 __fastcall dp_pll_vco_div_clk_recalc_rate(__int64 a1)
{
  __int64 v1; // x9
  unsigned __int64 v2; // x8
  int v3; // w9
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 24);
    v2 = *(_QWORD *)(v1 + 8);
    v3 = *(_DWORD *)(v1 + 396);
    if ( v2 == 5400000 )
    {
      return 0x5265C0u / (4 * v3);
    }
    else if ( v2 == 8100000 )
    {
      return 0x7B98A0u / (6 * v3);
    }
    else
    {
      return v2 / (unsigned int)(2 * v3);
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input parameters\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_26189D, "dp_pll_vco_div_clk_recalc_rate");
    return -22;
  }
}
