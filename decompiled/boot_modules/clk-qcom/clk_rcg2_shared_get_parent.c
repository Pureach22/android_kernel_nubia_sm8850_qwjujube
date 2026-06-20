__int64 __fastcall clk_rcg2_shared_get_parent(__int64 a1)
{
  int v2; // w8
  int v3; // w9
  __int64 v4; // x0
  int v5; // w8
  __int64 result; // x0
  unsigned int v7; // w20
  int num_parents; // w0
  __int64 v9; // x8
  unsigned __int8 *v10; // x11
  int v11; // t1
  unsigned int v12; // w20
  int v13; // w0
  int v14; // w8
  unsigned __int8 *v15; // x10
  int v16; // t1
  unsigned int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (clk_hw_is_enabled(a1) & 1) != 0 )
  {
    v2 = *(_DWORD *)(a1 - 48);
    v3 = *(unsigned __int8 *)(a1 + 144);
    v4 = *(_QWORD *)(a1 + 24);
    v17 = 0;
    v5 = regmap_read(v4, (unsigned int)(v2 + v3 + 4), &v17);
    result = 0;
    if ( v5 )
      goto LABEL_13;
    v7 = v17;
    num_parents = clk_hw_get_num_parents(a1);
    if ( num_parents >= 1 )
    {
      v9 = 0;
      v10 = (unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL);
      while ( 1 )
      {
        v11 = *v10;
        v10 += 2;
        if ( ((v7 >> 8) & 7) == v11 )
          break;
        if ( num_parents == ++v9 )
          goto LABEL_12;
      }
      result = (unsigned int)v9;
      goto LABEL_13;
    }
LABEL_12:
    result = 0;
    goto LABEL_13;
  }
  v12 = *(_DWORD *)(a1 + 148);
  v13 = clk_hw_get_num_parents(a1);
  if ( v13 < 1 )
    goto LABEL_12;
  v14 = v13;
  result = 0;
  v15 = (unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL);
  while ( 1 )
  {
    v16 = *v15;
    v15 += 2;
    if ( ((v12 >> 8) & 7) == v16 )
      break;
    if ( v14 == ++result )
      goto LABEL_12;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
