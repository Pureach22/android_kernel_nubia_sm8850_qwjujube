__int64 __fastcall clk_dyn_rcg_get_parent(__int64 a1)
{
  int num_parents; // w19
  __int64 v3; // x0
  __int64 v4; // x1
  int v5; // w8
  __int64 result; // x0
  _BOOL4 v7; // w21
  int v8; // w8
  unsigned __int8 *v9; // x10
  int v10; // t1
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  num_parents = clk_hw_get_num_parents(a1);
  v3 = *(_QWORD *)(a1 + 24);
  v4 = *(unsigned int *)(a1 - 64);
  v11[0] = 0;
  v5 = regmap_read(v3, v4, v11);
  result = 0;
  if ( !v5 )
  {
    v7 = (v11[0] & (unsigned int)(1LL << *(_BYTE *)(a1 - 60))) != 0;
    if ( (unsigned int)regmap_read(
                         *(_QWORD *)(a1 + 24),
                         *(unsigned int *)(a1 + 4LL * ((v11[0] & (unsigned int)(1LL << *(_BYTE *)(a1 - 60))) != 0) - 80),
                         (char *)v11 + 4)
      || (v8 = (HIDWORD(v11[0]) >> *(_BYTE *)(a1 + 16LL * v7 - 40)) & 7, HIDWORD(v11[0]) = v8, num_parents < 1) )
    {
LABEL_3:
      result = 0;
    }
    else
    {
      result = 0;
      v9 = (unsigned __int8 *)(*(_QWORD *)(a1 + 16LL * v7 - 32) + 1LL);
      while ( 1 )
      {
        v10 = *v9;
        v9 += 2;
        if ( v8 == v10 )
          break;
        if ( num_parents == ++result )
          goto LABEL_3;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
