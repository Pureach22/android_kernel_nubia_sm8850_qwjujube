unsigned __int64 __fastcall dp_pll_link_clk_recalc_rate_1(__int64 a1)
{
  __int64 ipc_log_context; // x0

  if ( a1 )
    return *(_QWORD *)(*(_QWORD *)(a1 + 24) + 8LL) / 0xAuLL * *(unsigned int *)(*(_QWORD *)(a1 + 24) + 396LL)
         + *(_QWORD *)(*(_QWORD *)(a1 + 24) + 8LL) % 0xAuLL * *(unsigned int *)(*(_QWORD *)(a1 + 24) + 396LL) / 0xA;
  ipc_log_context = get_ipc_log_context();
  ipc_log_string(ipc_log_context, "[e][%-4d]invalid input parameters\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  printk(&unk_26189D, "dp_pll_link_clk_recalc_rate");
  return -22;
}
