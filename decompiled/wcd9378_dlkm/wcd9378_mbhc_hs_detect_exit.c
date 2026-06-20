__int64 __fastcall wcd9378_mbhc_hs_detect_exit(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 result; // x0
  void *v6; // x0

  if ( !a1 )
  {
    v6 = &unk_14301;
    return printk(v6, "wcd9378_mbhc_hs_detect_exit");
  }
  v2 = *(_QWORD *)(a1 + 24);
  v3 = *(_QWORD *)(v2 + 152);
  if ( !v3 )
  {
    v6 = &unk_131C3;
    return printk(v6, "wcd9378_mbhc_hs_detect_exit");
  }
  v4 = *(_QWORD *)(v3 + 336);
  if ( !v4 )
    return dev_err(v2, "%s: mbhc not initialized!\n", "wcd9378_mbhc_hs_detect_exit");
  result = wcd_mbhc_stop(*(_QWORD *)(v3 + 336));
  if ( *(_BYTE *)(v4 + 207) == 1 )
  {
    result = wcd9378_micbias_control(a1, 2u, 3, 0);
    *(_BYTE *)(v4 + 207) = 0;
  }
  return result;
}
