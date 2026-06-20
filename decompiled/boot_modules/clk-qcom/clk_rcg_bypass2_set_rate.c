__int64 __fastcall clk_rcg_bypass2_set_rate(__int64 a1)
{
  int num_parents; // w21
  __int64 result; // x0
  char v4; // w9
  unsigned int v5; // w8
  __int64 v6; // x9
  int v7; // w8
  unsigned __int8 *v8; // x10
  unsigned int v9; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v10; // [xsp+10h] [xbp-20h] BYREF
  __int64 v11; // [xsp+18h] [xbp-18h]
  __int64 v12; // [xsp+20h] [xbp-10h]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v12 = 0;
  v10 = 0;
  v9 = 0;
  num_parents = clk_hw_get_num_parents(a1);
  result = regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), &v9);
  if ( !(_DWORD)result )
  {
    v4 = *(_BYTE *)(a1 - 24);
    BYTE1(v11) = ((v9 >> *(_BYTE *)(a1 - 33)) & ~(unsigned __int8)(-1LL << *(_BYTE *)(a1 - 32))) + 1;
    if ( num_parents < 1 )
    {
LABEL_6:
      result = 4294967274LL;
    }
    else
    {
      v5 = v9 >> v4;
      v6 = (unsigned int)num_parents;
      v7 = v5 & 7;
      v8 = (unsigned __int8 *)(*(_QWORD *)(a1 - 16) + 1LL);
      while ( v7 != *v8 )
      {
        --v6;
        v8 += 2;
        if ( !v6 )
          goto LABEL_6;
      }
      LOBYTE(v11) = *(v8 - 1);
      _clk_rcg_set_rate(a1 - 48, &v10);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
