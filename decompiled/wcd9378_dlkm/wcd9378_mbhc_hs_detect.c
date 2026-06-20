__int64 __fastcall wcd9378_mbhc_hs_detect(__int64 a1)
{
  __int64 v1; // x0
  __int64 v2; // x8
  __int64 v3; // x8
  void *v5; // x0

  if ( !a1 )
  {
    v5 = &unk_14301;
LABEL_8:
    printk(v5, "wcd9378_mbhc_hs_detect");
    return 4294967274LL;
  }
  v1 = *(_QWORD *)(a1 + 24);
  v2 = *(_QWORD *)(v1 + 152);
  if ( !v2 )
  {
    v5 = &unk_131C3;
    goto LABEL_8;
  }
  v3 = *(_QWORD *)(v2 + 336);
  if ( v3 )
    return wcd_mbhc_start(v3);
  dev_err(v1, "%s: mbhc not initialized!\n", "wcd9378_mbhc_hs_detect");
  return 4294967274LL;
}
