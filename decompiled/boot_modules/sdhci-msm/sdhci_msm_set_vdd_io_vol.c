__int64 __fastcall sdhci_msm_set_vdd_io_vol(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 *v3; // x20
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x0
  unsigned int v7; // w19
  __int64 result; // x0
  unsigned int v9; // w20

  v2 = *(_QWORD *)(a1 + 120);
  if ( !v2 )
    return 0;
  v3 = *(__int64 **)(v2 + 8);
  if ( !v3 || *((_BYTE *)v3 + 80) != 1 )
    return 0;
  v4 = *v3;
  v5 = 68;
  if ( !a2 )
    v5 = 64;
  v6 = *(_QWORD *)(v4 + 752);
  v7 = *(_DWORD *)((char *)v3 + v5);
  if ( v6 && *(_BYTE *)(v4 + 760) == 1 )
    ipc_log_string(v6, "%s: reg=%s min_uV=%d max_uV=%d\n", "sdhci_msm_vreg_set_voltage", (const char *)v3[3], v7, v7);
  if ( *((_BYTE *)v3 + 83) != 1 || *((_BYTE *)v3 + 84) != 1 )
    return 0;
  result = regulator_set_voltage(v3[1], v7, v7);
  if ( (_DWORD)result )
  {
    v9 = result;
    printk(&unk_10CA2, "sdhci_msm_vreg_set_voltage");
    return v9;
  }
  return result;
}
