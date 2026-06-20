__int64 __fastcall reg_get_rdpair_from_regdmn_id(__int16 a1, __int16 *a2)
{
  unsigned __int16 v4; // w9
  int v5; // w11
  bool v6; // zf
  __int16 v7; // w8
  int v8; // w8
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  reg_get_num_reg_dmn_pairs(&v10);
  if ( v10 < 1 || g_reg_dmn_pairs_0[0] == a1 )
  {
    v4 = 0;
    v5 = 0;
  }
  else
  {
    v4 = 0;
    do
      v5 = ++v4;
    while ( v10 > (unsigned int)v4 && g_reg_dmn_pairs_0[2 * v4] != a1 );
  }
  v6 = v10 == v5;
  if ( v10 == v5 )
    v7 = -1;
  else
    v7 = v4;
  *a2 = v7;
  _ReadStatusReg(SP_EL0);
  v8 = v6;
  return (unsigned int)(16 * v8);
}
