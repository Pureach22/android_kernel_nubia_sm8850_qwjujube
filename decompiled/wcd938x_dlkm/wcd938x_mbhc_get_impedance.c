__int64 __fastcall wcd938x_mbhc_get_impedance(__int64 a1, __int64 a2, __int64 a3)
{
  void *v4; // x0

  if ( !a1 )
  {
    if ( !(unsigned int)__ratelimit(&wcd938x_mbhc_get_impedance__rs, "wcd938x_mbhc_get_impedance") )
      return 4294967274LL;
    v4 = &unk_13E89;
LABEL_11:
    printk(v4, "wcd938x_mbhc_get_impedance");
    return 4294967274LL;
  }
  if ( a2 && a3 )
    return wcd_mbhc_get_impedance();
  if ( (unsigned int)__ratelimit(&wcd938x_mbhc_get_impedance__rs_1, "wcd938x_mbhc_get_impedance") )
  {
    v4 = &unk_138B4;
    goto LABEL_11;
  }
  return 4294967274LL;
}
