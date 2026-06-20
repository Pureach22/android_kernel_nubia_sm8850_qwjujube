__int64 __fastcall clk_rcg_get_parent(__int64 a1)
{
  int num_parents; // w20
  __int64 v3; // x0
  __int64 v4; // x1
  int v5; // w8
  __int64 result; // x0
  int v7; // w8
  unsigned __int8 *v8; // x10
  int v9; // t1
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  num_parents = clk_hw_get_num_parents(a1);
  v3 = *(_QWORD *)(a1 + 24);
  v4 = *(unsigned int *)(a1 - 48);
  v10 = 0;
  v5 = regmap_read(v3, v4, &v10);
  result = 0;
  if ( !v5 )
  {
    v7 = (v10 >> *(_BYTE *)(a1 - 24)) & 7;
    v10 = v7;
    if ( num_parents < 1 )
    {
LABEL_6:
      result = 0;
    }
    else
    {
      result = 0;
      v8 = (unsigned __int8 *)(*(_QWORD *)(a1 - 16) + 1LL);
      while ( 1 )
      {
        v9 = *v8;
        v8 += 2;
        if ( v7 == v9 )
          break;
        if ( num_parents == ++result )
          goto LABEL_6;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
