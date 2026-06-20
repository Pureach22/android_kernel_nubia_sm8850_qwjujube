__int64 __fastcall wcd938x_soc_get_mbhc(__int64 a1)
{
  __int64 v1; // x8
  void *v3; // x0

  if ( !a1 )
  {
    if ( !(unsigned int)__ratelimit(&wcd938x_soc_get_mbhc__rs, "wcd938x_soc_get_mbhc") )
      return 0;
    v3 = &unk_12CF7;
LABEL_10:
    printk(v3, "wcd938x_soc_get_mbhc");
    return 0;
  }
  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( v1 )
    return *(_QWORD *)(v1 + 256);
  if ( (unsigned int)__ratelimit(&wcd938x_soc_get_mbhc__rs_1, "wcd938x_soc_get_mbhc") )
  {
    v3 = &unk_1349F;
    goto LABEL_10;
  }
  return 0;
}
