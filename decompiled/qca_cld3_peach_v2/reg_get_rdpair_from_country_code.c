__int64 __fastcall reg_get_rdpair_from_country_code(__int16 a1, unsigned __int16 *a2, unsigned __int16 *a3)
{
  unsigned __int16 v6; // w8
  int v7; // w12
  __int64 result; // x0
  int v9; // w11
  unsigned __int16 v10; // w10
  int v11; // w12
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  reg_get_num_countries((_DWORD *)v12 + 1);
  reg_get_num_reg_dmn_pairs(v12);
  if ( SHIDWORD(v12[0]) < 1 || g_all_countries_0[0] == a1 )
  {
    v6 = 0;
    v7 = 0;
  }
  else
  {
    v6 = 0;
    do
      v7 = ++v6;
    while ( HIDWORD(v12[0]) > v6 && g_all_countries_0[7 * v6] != a1 );
  }
  if ( HIDWORD(v12[0]) == v7 )
  {
    result = 16;
    *a2 = -1;
  }
  else
  {
    if ( SLODWORD(v12[0]) < 1
      || (v9 = (unsigned __int16)g_all_countries_0[7 * v6 + 1], (unsigned __int16)g_reg_dmn_pairs_0[0] == v9) )
    {
      v10 = 0;
      v11 = 0;
    }
    else
    {
      v10 = 0;
      do
        v11 = ++v10;
      while ( LODWORD(v12[0]) > v10 && (unsigned __int16)g_reg_dmn_pairs_0[2 * v10] != v9 );
    }
    if ( LODWORD(v12[0]) == v11 )
    {
      result = 16;
      *a3 = -1;
    }
    else
    {
      result = 0;
      *a2 = v6;
      *a3 = v10;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
