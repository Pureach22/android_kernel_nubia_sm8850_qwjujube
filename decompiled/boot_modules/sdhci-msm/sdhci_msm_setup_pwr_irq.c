__int64 __fastcall sdhci_msm_setup_pwr_irq(__int64 *a1)
{
  __int64 v1; // x21
  __int64 v3; // x19
  __int64 result; // x0
  void (__fastcall *v5)(__int64, __int64, __int64); // x8
  __int64 v6; // x2
  __int64 v7; // x5
  unsigned int v8; // w20

  v1 = a1[16];
  v3 = *a1;
  sdhci_msm_handle_pwr_irq(v1 + 1792, 0);
  __dsb(0xFu);
  result = platform_get_irq_byname(v3, "pwr_irq");
  *((_DWORD *)a1 + 4) = result;
  if ( (result & 0x80000000) == 0 )
  {
    _init_waitqueue_head(a1 + 21, "&msm_host->pwr_irq_wait", &sdhci_msm_init_pwr_irq_wait___key);
    v5 = *(void (__fastcall **)(__int64, __int64, __int64))(a1[26] + 8);
    v6 = *(unsigned int *)(a1[27] + 44);
    if ( *((_DWORD *)v5 - 1) != 1443578770 )
      __break(0x8228u);
    v5(15, v1 + 1792, v6);
    v7 = *(_QWORD *)(v3 + 128);
    if ( !v7 )
      v7 = *(_QWORD *)(v3 + 16);
    result = devm_request_threaded_irq(v3 + 16, *((unsigned int *)a1 + 4), 0, sdhci_msm_pwr_irq, 0x2000, v7, v1 + 1792);
    if ( (_DWORD)result )
    {
      v8 = result;
      dev_err(v3 + 16, "Request IRQ failed (%d)\n", result);
      return v8;
    }
  }
  return result;
}
