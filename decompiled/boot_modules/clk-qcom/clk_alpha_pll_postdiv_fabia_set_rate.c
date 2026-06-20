__int64 __fastcall clk_alpha_pll_postdiv_fabia_set_rate(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 result; // x0
  int v9; // w8
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x12
  int v12; // w13
  int *v13; // x12
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 24);
  v7 = *(unsigned int *)(a1 - 16);
  v14 = 0;
  result = regmap_read(v6, v7, &v14);
  if ( !(_DWORD)result )
  {
    v9 = v14;
    if ( (v14 & 0x100000) != 0 )
    {
      result = 0;
    }
    else
    {
      v10 = *(_QWORD *)(a1 + 160);
      if ( v10 )
      {
        v11 = 0;
        v12 = 1;
        while ( 1 )
        {
          v13 = (int *)(*(_QWORD *)(a1 + 152) + 8 * v11);
          if ( v13[1] == (unsigned int)((a2 + a3 - 1) / (unsigned __int64)(unsigned int)a2) )
            break;
          v11 = v12++;
          if ( v10 <= v11 )
            goto LABEL_10;
        }
        v9 = *v13;
        v14 = *v13;
      }
LABEL_10:
      result = regmap_update_bits_base(
                 *(_QWORD *)(a1 + 24),
                 *(_DWORD *)(a1 - 16) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 8) + 5LL),
                 (unsigned __int64)(unsigned int)~(-1 << *(_BYTE *)(a1 - 12)) << *(_DWORD *)(a1 + 144),
                 (unsigned int)(v9 << *(_DWORD *)(a1 + 144)),
                 0,
                 0,
                 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
