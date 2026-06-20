__int64 __fastcall lucid_evo_calc_pll_out(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 parent; // x0
  __int64 rate; // x0
  unsigned __int64 v9; // x20
  __int64 v10; // x8
  unsigned __int64 v11; // x9
  unsigned int v12; // w10
  __int64 v13; // x11
  unsigned __int64 v14; // x12
  unsigned __int64 v15; // x8
  unsigned int v16; // w13
  unsigned int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = clk_hw_get_parent(a1);
  if ( result )
  {
    parent = clk_hw_get_parent(result);
    if ( parent )
    {
      rate = clk_hw_get_rate(parent);
      v9 = 1000 * ((rate * a2 + ((rate * (unsigned __int64)a3) >> 16) + 999) / 0x3E8);
    }
    else
    {
      v9 = 0;
    }
    v10 = *(_QWORD *)(a1 - 8);
    v17 = 0;
    LODWORD(result) = regmap_read(
                        *(_QWORD *)(a1 + 24),
                        *(_DWORD *)(a1 - 16) + (unsigned int)*(unsigned __int8 *)(v10 + 5),
                        &v17);
    if ( (_DWORD)result )
    {
      result = (int)result;
    }
    else
    {
      v11 = *(_QWORD *)(a1 + 160);
      v12 = (v17 >> *(_DWORD *)(a1 + 144)) & ~(unsigned int)(-1LL << *(_BYTE *)(a1 - 12));
      v17 = v12;
      if ( v11 )
      {
        v13 = *(_QWORD *)(a1 + 152);
        v14 = 0;
        v15 = 1;
        v16 = 1;
        while ( *(_DWORD *)(v13 + 8 * v14) != v12 )
        {
          v14 = v16++;
          if ( v11 <= v14 )
            goto LABEL_14;
        }
        v15 = *(unsigned int *)(v13 + 8 * v14 + 4);
      }
      else
      {
        v15 = 1;
      }
LABEL_14:
      result = v9 / v15;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
