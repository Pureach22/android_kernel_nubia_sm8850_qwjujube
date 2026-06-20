__int64 __fastcall wcd9378_mbhc_get_impedance(__int64 a1, __int64 a2, __int64 a3)
{
  void *v4; // x0

  if ( !a1 )
  {
    v4 = &unk_149BC;
LABEL_8:
    printk(v4, "wcd9378_mbhc_get_impedance");
    return 4294967274LL;
  }
  if ( !a2 || !a3 )
  {
    v4 = &unk_142EB;
    goto LABEL_8;
  }
  return wcd_mbhc_get_impedance();
}
