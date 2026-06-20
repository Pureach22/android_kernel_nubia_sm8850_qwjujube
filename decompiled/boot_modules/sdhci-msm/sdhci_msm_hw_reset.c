__int64 __fastcall sdhci_msm_hw_reset(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  void (*v4)(void); // x8
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 1408);
  if ( !*(_QWORD *)(a1 + 2016) )
    return dev_err(v1 + 16, "%s: failed, err = %d\n", "sdhci_msm_hw_reset", -95);
  *(_BYTE *)(a1 + 2009) = 1;
  sdhci_msm_registers_save(a1);
  v3 = *(_QWORD *)(a1 + 72);
  if ( (*(_BYTE *)(v3 + 1002) & 0x80) != 0 )
  {
    v4 = *(void (**)(void))(*(_QWORD *)(v3 + 1456) + 8LL);
    if ( *((_DWORD *)v4 - 1) != -452870896 )
      __break(0x8228u);
    v4();
    *(_BYTE *)(*(_QWORD *)(a1 + 72) + 1476LL) = 0;
  }
  sdhci_msm_gcc_reset(v1 + 16, a1);
  sdhci_msm_registers_restore(a1);
  result = *(_QWORD *)(a1 + 2160);
  *(_BYTE *)(a1 + 2009) = 0;
  if ( result )
  {
    if ( *(_BYTE *)(a1 + 2168) == 1 )
      return ipc_log_string();
  }
  return result;
}
