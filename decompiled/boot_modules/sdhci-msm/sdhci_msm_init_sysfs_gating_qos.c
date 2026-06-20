__int64 __fastcall sdhci_msm_init_sysfs_gating_qos(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 v7; // x1

  v1 = *(_QWORD *)(a1 + 152);
  *(_QWORD *)(v1 + 1952) = show_sdhci_msm_clk_gating;
  *(_QWORD *)(v1 + 1960) = store_sdhci_msm_clk_gating;
  *(_QWORD *)(v1 + 1936) = "clk_gating";
  *(_WORD *)(v1 + 1944) = 420;
  if ( (unsigned int)((__int64 (*)(void))device_create_file)() )
  {
    v4 = *(_QWORD *)(v1 + 72);
    v5 = *(_QWORD *)(v4 + 120);
    if ( !v5 )
      v5 = *(_QWORD *)(v4 + 8);
    printk(&unk_10018, v5);
  }
  *(_QWORD *)(v1 + 1984) = show_sdhci_msm_pm_qos;
  *(_QWORD *)(v1 + 1992) = store_sdhci_msm_pm_qos;
  *(_QWORD *)(v1 + 1968) = "pm_qos";
  *(_WORD *)(v1 + 1976) = 420;
  result = device_create_file(a1, v1 + 1968);
  if ( (_DWORD)result )
  {
    v6 = *(_QWORD *)(v1 + 72);
    v7 = *(_QWORD *)(v6 + 120);
    if ( !v7 )
      v7 = *(_QWORD *)(v6 + 8);
    return printk(&unk_11131, v7);
  }
  return result;
}
