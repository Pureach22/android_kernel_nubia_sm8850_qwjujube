__int64 __fastcall spectral_pdev_open(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x1
  const char *v11; // x2
  const char *v12; // x3

  if ( !a1 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: pdev is NULL!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_spectral_is_feature_disabled_pdev");
    goto LABEL_8;
  }
  if ( (~*(_DWORD *)(a1 + 16) & 0x1F0) == 0 )
  {
LABEL_8:
    v11 = "%s: Spectral feature is disabled";
    v12 = "spectral_pdev_open";
    goto LABEL_9;
  }
  if ( *(_BYTE *)(cfg_psoc_get_values(*(_QWORD *)(a1 + 80)) + 781) == 1 )
    tgt_set_spectral_dma_debug();
  if ( (~*(_DWORD *)(a1 + 16) & 0x1F0) != 0 )
    return tgt_spectral_register_to_dbr(a1, v10, a2, a3, a4, a5, a6, a7, a8, a9);
  v11 = "%s: spectral feature is disabled";
  v12 = "spectral_register_dbr";
LABEL_9:
  qdf_trace_msg(0x56u, 4u, v11, a2, a3, a4, a5, a6, a7, a8, a9, v12);
  return 39;
}
