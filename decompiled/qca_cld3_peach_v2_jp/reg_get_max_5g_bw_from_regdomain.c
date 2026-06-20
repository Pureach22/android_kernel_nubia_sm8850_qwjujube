__int64 __fastcall reg_get_max_5g_bw_from_regdomain(__int64 a1, __int16 a2, _WORD *a3)
{
  __int64 v5; // x9
  __int64 result; // x0
  unsigned __int16 v7; // w11
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  *a3 = 0;
  reg_get_num_reg_dmn_pairs(&v8);
  if ( v8 >= 1 && g_reg_dmn_pairs_0[0] != a2 )
  {
    v7 = 0;
    do
      v5 = ++v7;
    while ( v8 > (unsigned int)v7 && g_reg_dmn_pairs_0[2 * v7] != a2 );
    if ( v8 == v7 )
      goto LABEL_4;
LABEL_9:
    result = 0;
    *a3 = *(_WORD *)&regdomains_5g[24 * LOBYTE(g_reg_dmn_pairs_0[2 * v5 + 1]) + 10];
    goto LABEL_10;
  }
  v5 = 0;
  if ( v8 )
    goto LABEL_9;
LABEL_4:
  result = 16;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
