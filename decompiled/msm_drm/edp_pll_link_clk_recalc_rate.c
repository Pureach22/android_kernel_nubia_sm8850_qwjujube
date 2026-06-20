__int64 __fastcall edp_pll_link_clk_recalc_rate(__int64 a1)
{
  __int64 ipc_log_context; // x0

  if ( a1 )
    return 100LL * *(_QWORD *)(*(_QWORD *)(a1 + 24) + 8LL);
  ipc_log_context = get_ipc_log_context();
  ipc_log_string(ipc_log_context, "[e][%-4d]invalid input parameters\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  printk(&unk_26189D, "edp_pll_link_clk_recalc_rate");
  return -22;
}
