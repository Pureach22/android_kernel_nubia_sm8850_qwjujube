__int64 __fastcall wcd9378_mbhc_deinit(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  void *v3; // x0

  if ( !a1 )
  {
    v3 = &unk_14301;
    return printk(v3, "wcd9378_mbhc_deinit");
  }
  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v1 )
  {
    v3 = &unk_131C3;
    return printk(v3, "wcd9378_mbhc_deinit");
  }
  result = *(_QWORD *)(v1 + 336);
  if ( result )
    return wcd_mbhc_deinit(result);
  return result;
}
