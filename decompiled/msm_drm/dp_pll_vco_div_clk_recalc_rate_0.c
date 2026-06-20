__int64 __fastcall dp_pll_vco_div_clk_recalc_rate_0(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 v2; // x9
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 24);
    v2 = *(_QWORD *)(v1 + 8);
    if ( v2 == 5400000 || v2 == 8100000 )
      return 1350000LL * *(unsigned int *)(v1 + 396);
    else
      return (v2 >> 1) * *(unsigned int *)(v1 + 396);
  }
  else
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input parameters\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_26189D, "dp_pll_vco_div_clk_recalc_rate");
    return -22;
  }
}
