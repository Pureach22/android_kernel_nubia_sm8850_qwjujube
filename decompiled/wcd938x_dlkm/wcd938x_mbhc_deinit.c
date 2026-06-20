__int64 __fastcall wcd938x_mbhc_deinit(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x20
  void *v4; // x0

  if ( !result )
  {
    v4 = &unk_138CA;
    return printk(v4, "wcd938x_mbhc_deinit");
  }
  v1 = result;
  v2 = *(_QWORD *)(*(_QWORD *)(result + 24) + 152LL);
  if ( !v2 )
  {
    v4 = &unk_1349F;
    return printk(v4, "wcd938x_mbhc_deinit");
  }
  v3 = *(_QWORD *)(v2 + 256);
  if ( v3 )
  {
    wcd_mbhc_deinit(*(_QWORD *)(v2 + 256));
    return devm_kfree(*(_QWORD *)(v1 + 24), v3);
  }
  return result;
}
