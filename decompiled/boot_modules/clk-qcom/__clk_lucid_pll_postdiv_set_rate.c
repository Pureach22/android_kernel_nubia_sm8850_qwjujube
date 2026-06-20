__int64 __fastcall _clk_lucid_pll_postdiv_set_rate(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  __int64 v8; // x8
  __int64 result; // x0
  int v10; // w8
  __int64 v11; // x9
  unsigned __int64 v12; // x10
  unsigned __int64 v13; // x12
  int v14; // w13
  int *v15; // x12
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 - 8);
  v16 = 0;
  result = regmap_read(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 16) + (unsigned int)*(unsigned __int8 *)(v8 + 5), &v16);
  if ( !(_DWORD)result )
  {
    v10 = v16;
    if ( (v16 & a4) != 0 )
    {
      result = 0;
    }
    else
    {
      v11 = *(_QWORD *)(a1 + 152);
      if ( v11 )
      {
        v12 = *(_QWORD *)(a1 + 160);
        if ( v12 )
        {
          v13 = 0;
          v14 = 1;
          while ( 1 )
          {
            v15 = (int *)(v11 + 8 * v13);
            if ( v15[1] == (unsigned int)((a2 + a3 - 1) / (unsigned __int64)(unsigned int)a2) )
              break;
            v13 = v14++;
            if ( v12 <= v13 )
              goto LABEL_11;
          }
          v10 = *v15;
          v16 = *v15;
        }
LABEL_11:
        result = regmap_update_bits_base(
                   *(_QWORD *)(a1 + 24),
                   *(_DWORD *)(a1 - 16) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 8) + 5LL),
                   (unsigned int)(0xFFFFFFFFFFFFFFFFLL >> -(char)(*(_DWORD *)(a1 + 144) + *(_BYTE *)(a1 - 12)))
                 & (unsigned int)(-1LL << *(_DWORD *)(a1 + 144)),
                   (unsigned int)(v10 << *(_DWORD *)(a1 + 144)),
                   0,
                   0,
                   0);
      }
      else
      {
        clk_hw_get_name(a1);
        printk(&unk_2854B);
        result = 4294967274LL;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
