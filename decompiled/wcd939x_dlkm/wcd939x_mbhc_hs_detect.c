__int64 __fastcall wcd939x_mbhc_hs_detect(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  void *v4; // x0

  if ( !a1 )
  {
    if ( !(unsigned int)__ratelimit(&wcd939x_mbhc_hs_detect__rs, "wcd939x_mbhc_hs_detect") )
      return 4294967274LL;
    v4 = &unk_19E1E;
LABEL_9:
    printk(v4, "wcd939x_mbhc_hs_detect");
    return 4294967274LL;
  }
  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v1 )
  {
    if ( !(unsigned int)__ratelimit(&wcd939x_mbhc_hs_detect__rs_4, "wcd939x_mbhc_hs_detect") )
      return 4294967274LL;
    v4 = &unk_18BF3;
    goto LABEL_9;
  }
  v2 = *(_QWORD *)(v1 + 256);
  if ( v2 )
    return wcd_mbhc_start(v2);
  if ( (unsigned int)__ratelimit(&wcd939x_mbhc_hs_detect__rs_6, "wcd939x_mbhc_hs_detect") )
    dev_err(*(_QWORD *)(a1 + 24), "%s: mbhc not initialized!\n", "wcd939x_mbhc_hs_detect");
  return 4294967274LL;
}
