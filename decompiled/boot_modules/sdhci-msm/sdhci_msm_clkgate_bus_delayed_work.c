__int64 __fastcall sdhci_msm_clkgate_bus_delayed_work(__int64 a1)
{
  __int64 v1; // x21
  _QWORD *v3; // x20

  v1 = *(_QWORD *)(a1 - 224);
  v3 = (_QWORD *)(a1 - 352);
  sdhci_msm_registers_save(v1 + 1792);
  dev_pm_opp_set_rate(*v3 + 16LL, 0);
  clk_bulk_disable(4, a1 - 312);
  clk_bulk_unprepare(4, a1 - 312);
  if ( *(_QWORD *)(a1 + 400) && *(_BYTE *)(a1 + 408) == 1 )
    ipc_log_string();
  return sdhci_msm_bus_get_and_set_vote(v1 + 1792, 0);
}
