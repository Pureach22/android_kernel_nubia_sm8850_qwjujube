__int64 __fastcall i2c_pmic_domain_xlate(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        int a4,
        __int64 *a5,
        unsigned int *a6)
{
  __int64 v6; // x8
  unsigned int v7; // w9

  if ( a4 != 3 )
    return 4294967274LL;
  v6 = *a3;
  if ( (unsigned int)v6 > 0xFF )
    return 4294967274LL;
  v7 = a3[1];
  if ( v7 > 7 || a3[2] > 0xF )
    return 4294967274LL;
  *a5 = (1LL << v7) | (v6 << 8);
  *a6 = a3[2] & 0xF;
  return 0;
}
