__int64 __fastcall sdhci_msm_runtime_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v4; // x21
  unsigned __int64 v5; // x9
  unsigned __int64 v6; // x11
  unsigned int v7; // w1
  unsigned int v8; // w0
  unsigned int v9; // w0
  __int64 v10; // x20
  __int64 v11; // x8
  int v12; // w0
  int v13; // w0
  __int64 v14; // x8
  unsigned int v15; // w9
  int v16; // w0
  __int64 v17; // x0
  unsigned int v19; // w21
  unsigned int v20; // w20

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v1 + 2160);
  v4 = *(_QWORD *)(v1 + 1872);
  if ( v3 && *(_BYTE *)(v1 + 2168) == 1 )
    ipc_log_string(v3, "%s: Enter\n", "sdhci_msm_runtime_resume");
  if ( (cancel_delayed_work_sync(v1 + 1760) & 1) != 0 )
    goto LABEL_26;
  v5 = *(_QWORD *)(v1 + 1520);
  v6 = v5 >> 3;
  if ( *(_BYTE *)(*(_QWORD *)(v1 + 72) + 1055LL) == 2 )
    v5 >>= 1;
  if ( *(_BYTE *)(*(_QWORD *)(v1 + 72) + 1055LL) )
    v7 = v5;
  else
    v7 = v6;
  sdhci_msm_bus_get_and_set_vote(v1, v7);
  dev_pm_opp_set_rate(a1, *(_QWORD *)(v1 + 1520));
  v8 = clk_bulk_prepare(4, v1 + 1448);
  if ( v8 )
  {
    v19 = v8;
LABEL_35:
    dev_err(a1, "Failed to enable clocks %d\n", v19);
    sdhci_msm_bus_get_and_set_vote(v1, 0);
    return v19;
  }
  v9 = clk_bulk_enable(4, v1 + 1448);
  if ( v9 )
  {
    v19 = v9;
    clk_bulk_unprepare(4, v1 + 1448);
    goto LABEL_35;
  }
  sdhci_msm_registers_restore(v1);
  v10 = *(_QWORD *)(v1 + 1624);
  v11 = *(_QWORD *)(v1 + 72);
  if ( ((*(_BYTE *)(v1 + 1561) & 1) != 0 || (*(_BYTE *)(v11 + 1059) & 1) != 0) && *(_BYTE *)(v11 + 1056) == 10 )
  {
    v12 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + *(unsigned int *)(v10 + 104)));
    writel_relaxed(v12 | 2, (unsigned int *)(*(_QWORD *)(v1 + 24) + *(unsigned int *)(v10 + 104)));
    __dsb(0xEu);
    _const_udelay(8590);
    v13 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + *(unsigned int *)(v10 + 104)));
    writel_relaxed(v13 & 0xFFFFFFFD, (unsigned int *)(*(_QWORD *)(v1 + 24) + *(unsigned int *)(v10 + 104)));
  }
  if ( *(_BYTE *)(v1 + 1609) == 1 && *(_QWORD *)(v1 + 1520) )
  {
    if ( (v14 = *(_QWORD *)(v1 + 72), v15 = *(unsigned __int8 *)(v14 + 1056), v15 == 5)
      && (*(_BYTE *)(v1 + 796) & 0x10) != 0
      || *(_DWORD *)(v1 + 820) >= 0x5F5E101u
      && v15 <= 0xA
      && ((1 << v15) & 0x640) != 0
      && (*(_BYTE *)(v14 + 1059) & 1) == 0 )
    {
      if ( !(unsigned int)msm_init_cm_dll(v1, 0) )
        msm_config_cm_dll_phase((_QWORD *)v1, *(_BYTE *)(v1 + 1563));
    }
  }
LABEL_26:
  if ( v4 )
    sdhci_msm_vote_pmqos(*(_QWORD *)(v1 + 1536), *(_DWORD *)(*(_QWORD *)(v1 + 1872) + 12LL));
  if ( (*(_BYTE *)(*(_QWORD *)(v1 + 1536) + 1003LL) & 8) != 0 && (v16 = qcom_ice_resume(*(_QWORD *)(v1 + 1512))) != 0 )
  {
    v20 = v16;
    dev_warn(**(_QWORD **)(v1 + 1536), "Could not resume ICE err=%d, Disabling inline encryption capability.\n", v16);
    *(_DWORD *)(*(_QWORD *)(v1 + 1536) + 1000LL) &= ~0x8000000u;
    return v20;
  }
  else
  {
    v17 = raw_spin_lock_irqsave(v1 + 792);
    *(_BYTE *)(v1 + 827) = 0;
    raw_spin_unlock_irqrestore(v1 + 792, v17);
    return 0;
  }
}
