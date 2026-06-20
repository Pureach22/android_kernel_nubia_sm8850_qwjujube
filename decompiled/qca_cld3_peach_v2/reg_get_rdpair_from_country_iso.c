__int64 __fastcall reg_get_rdpair_from_country_iso(unsigned __int8 *a1, unsigned __int16 *a2, unsigned __int16 *a3)
{
  int v6; // w10
  unsigned __int16 v7; // w8
  __int16 *v8; // x14
  __int16 *v9; // x14
  int v10; // t1
  __int64 result; // x0
  int v12; // w11
  unsigned __int16 v13; // w10
  int v14; // w12
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  reg_get_num_countries((_DWORD *)v15 + 1);
  reg_get_num_reg_dmn_pairs(v15);
  if ( SHIDWORD(v15[0]) < 1 )
  {
    v7 = 0;
    if ( !HIDWORD(v15[0]) )
    {
LABEL_7:
      result = 16;
      *a2 = -1;
      goto LABEL_15;
    }
  }
  else
  {
    v6 = 0;
    v7 = 0;
    do
    {
      v8 = &g_all_countries_0[7 * v7];
      v10 = *((unsigned __int8 *)v8 + 4);
      v9 = v8 + 2;
      if ( v10 == *a1 && *((unsigned __int8 *)v9 + 1) == a1[1] )
        break;
      v6 = ++v7;
    }
    while ( HIDWORD(v15[0]) > v7 );
    if ( HIDWORD(v15[0]) == v6 )
      goto LABEL_7;
  }
  if ( SLODWORD(v15[0]) < 1
    || (v12 = (unsigned __int16)g_all_countries_0[7 * v7 + 1], (unsigned __int16)g_reg_dmn_pairs_0[0] == v12) )
  {
    v13 = 0;
    v14 = 0;
  }
  else
  {
    v13 = 0;
    do
      v14 = ++v13;
    while ( LODWORD(v15[0]) > v13 && (unsigned __int16)g_reg_dmn_pairs_0[2 * v13] != v12 );
  }
  if ( LODWORD(v15[0]) == v14 )
  {
    result = 16;
    *a3 = -1;
  }
  else
  {
    result = 0;
    *a2 = v7;
    *a3 = v13;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
