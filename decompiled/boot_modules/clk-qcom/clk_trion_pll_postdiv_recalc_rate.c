__int64 __fastcall clk_trion_pll_postdiv_recalc_rate(__int64 a1, unsigned __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  unsigned __int64 v6; // x9
  unsigned int v7; // w10
  __int64 v8; // x11
  unsigned __int64 v9; // x12
  unsigned __int64 v10; // x8
  unsigned int v11; // w13
  __int64 result; // x0
  unsigned int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  v4 = *(_QWORD *)(a1 + 24);
  v13 = 0;
  if ( v3 )
  {
    regmap_read(v4, *(_DWORD *)(a1 - 16) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 8) + 5LL), &v13);
    v6 = *(_QWORD *)(a1 + 160);
    v7 = (v13 >> *(_DWORD *)(a1 + 144)) & (0xFFFFFFFFFFFFFFFFLL >> -*(_BYTE *)(a1 - 12));
    v13 = v7;
    if ( v6 )
    {
      v8 = *(_QWORD *)(a1 + 152);
      v9 = 0;
      v10 = 1;
      v11 = 1;
      while ( *(_DWORD *)(v8 + 8 * v9) != v7 )
      {
        v9 = v11++;
        if ( v6 <= v9 )
          goto LABEL_9;
      }
      v10 = *(unsigned int *)(v8 + 8 * v9 + 4);
    }
    else
    {
      v10 = 1;
    }
LABEL_9:
    result = a2 / v10;
  }
  else
  {
    printk(&unk_28731);
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
