__int64 __fastcall wcd938x_mbhc_hs_detect_exit(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 result; // x0
  void *v4; // x0

  if ( !a1 )
  {
    result = __ratelimit(&wcd938x_mbhc_hs_detect_exit__rs, "wcd938x_mbhc_hs_detect_exit");
    if ( !(_DWORD)result )
      return result;
    v4 = &unk_138CA;
    return printk(v4, "wcd938x_mbhc_hs_detect_exit");
  }
  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v1 )
  {
    result = __ratelimit(&wcd938x_mbhc_hs_detect_exit__rs_8, "wcd938x_mbhc_hs_detect_exit");
    if ( !(_DWORD)result )
      return result;
    v4 = &unk_1349F;
    return printk(v4, "wcd938x_mbhc_hs_detect_exit");
  }
  v2 = *(_QWORD *)(v1 + 256);
  if ( v2 )
    return wcd_mbhc_stop(v2);
  result = __ratelimit(&wcd938x_mbhc_hs_detect_exit__rs_9, "wcd938x_mbhc_hs_detect_exit");
  if ( (_DWORD)result )
    return dev_err(*(_QWORD *)(a1 + 24), "%s: mbhc not initialized!\n", "wcd938x_mbhc_hs_detect_exit");
  return result;
}
