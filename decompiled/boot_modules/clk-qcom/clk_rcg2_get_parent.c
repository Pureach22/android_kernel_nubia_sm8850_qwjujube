__int64 __fastcall clk_rcg2_get_parent(__int64 a1)
{
  int v2; // w8
  int v3; // w9
  __int64 v4; // x0
  int v5; // w8
  __int64 result; // x0
  unsigned int v7; // w20
  int num_parents; // w0
  int v9; // w8
  unsigned __int8 *v10; // x10
  int v11; // t1
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 - 48);
  v3 = *(unsigned __int8 *)(a1 + 144);
  v4 = *(_QWORD *)(a1 + 24);
  v12 = 0;
  v5 = regmap_read(v4, (unsigned int)(v2 + v3 + 4), &v12);
  result = 0;
  if ( !v5 )
  {
    v7 = v12;
    num_parents = clk_hw_get_num_parents(a1);
    if ( num_parents < 1 )
    {
LABEL_6:
      result = 0;
    }
    else
    {
      v9 = num_parents;
      result = 0;
      v10 = (unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL);
      while ( 1 )
      {
        v11 = *v10;
        v10 += 2;
        if ( ((v7 >> 8) & 7) == v11 )
          break;
        if ( v9 == ++result )
          goto LABEL_6;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
