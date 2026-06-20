__int64 __fastcall edp_pll_vco_div_clk_round(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  unsigned __int64 v3; // x8
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 24);
    result = 1350000000;
    v3 = *(_QWORD *)(v1 + 8);
    if ( v3 != 5400000 && v3 != 8100000 )
      return 1000 * (v3 >> 1);
  }
  else
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input parameters\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_26189D, "edp_pll_vco_div_clk_recalc_rate");
    return -22;
  }
  return result;
}
