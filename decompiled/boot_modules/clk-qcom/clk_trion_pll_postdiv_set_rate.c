__int64 __fastcall clk_trion_pll_postdiv_set_rate(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x9
  unsigned __int64 v5; // x10
  __int64 v6; // x0
  unsigned __int64 v7; // x12
  int v8; // w13
  int *v9; // x12
  int v10; // w9

  v3 = *(_QWORD *)(a1 + 152);
  if ( v3 )
  {
    v5 = *(_QWORD *)(a1 + 160);
    v6 = *(_QWORD *)(a1 + 24);
    if ( v5 )
    {
      v7 = 0;
      v8 = 1;
      while ( 1 )
      {
        v9 = (int *)(v3 + 8 * v7);
        if ( v9[1] == (unsigned int)((a2 + a3 - 1) / (unsigned __int64)(unsigned int)a2) )
          break;
        v7 = v8++;
        if ( v5 <= v7 )
          goto LABEL_6;
      }
      v10 = *v9;
    }
    else
    {
LABEL_6:
      v10 = 0;
    }
    return regmap_update_bits_base(
             v6,
             *(_DWORD *)(a1 - 16) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 8) + 5LL),
             0xFFFFFFFFFFFFFFFFLL >> -*(_BYTE *)(a1 - 12) << *(_DWORD *)(a1 + 144),
             (unsigned int)(v10 << *(_DWORD *)(a1 + 144)),
             0,
             0,
             0);
  }
  else
  {
    printk(&unk_28731);
    return 4294967274LL;
  }
}
