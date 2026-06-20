__int64 __fastcall _clk_alpha_pll_set_rate(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        __int64 (__fastcall *a4)(_QWORD))
{
  unsigned __int64 v4; // x11
  unsigned __int64 v6; // x2
  __int64 v7; // x21
  unsigned __int8 *v8; // x10
  int v11; // w23
  unsigned __int64 v12; // x12
  char v13; // w13
  unsigned __int64 v14; // x22
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x11
  unsigned __int64 v17; // x24
  __int64 result; // x0

  v4 = (unsigned int)a3;
  v6 = a2 / (unsigned int)a3;
  v7 = a1 - 48;
  v8 = *(unsigned __int8 **)(a1 - 40);
  v11 = v8[4] - v8[3];
  v12 = a2 - v6 * v4;
  if ( v12 )
  {
    v13 = 16;
    if ( v11 == 4 )
      v13 = 32;
    v14 = (v12 << v13) / v4;
    a2 = 1000 * (((((unsigned __int64)(unsigned int)v14 * a3) >> v13) + (unsigned int)v6 * a3 + 999) / 0x3E8);
  }
  else
  {
    v14 = 0;
  }
  v15 = *(_QWORD *)(a1 - 24);
  v16 = v15 + 24LL * *(_QWORD *)(a1 - 16);
  if ( v15 >= v16 )
  {
LABEL_13:
    v17 = 0;
  }
  else
  {
    v17 = *(_QWORD *)(a1 - 24);
    while ( *(_QWORD *)v17 > a2 || *(_QWORD *)(v17 + 8) < a2 )
    {
      v17 += 24LL;
      if ( v17 >= v16 )
        goto LABEL_13;
    }
    if ( v17 )
      goto LABEL_15;
  }
  if ( v15 )
  {
    clk_hw_get_name(a1);
    printk(&unk_28895);
    return 4294967274LL;
  }
LABEL_15:
  regmap_write(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 48) + (unsigned int)v8[1], v6);
  if ( v11 == 4 )
  {
    regmap_write(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 4LL),
      v14 >> 24);
    LODWORD(v14) = (_DWORD)v14 << 8;
  }
  regmap_write(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL),
    (unsigned int)v14);
  if ( v17 )
    regmap_update_bits_base(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
      3145728,
      (unsigned int)(*(_DWORD *)(v17 + 16) << 20),
      0,
      0,
      0);
  regmap_update_bits_base(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
    0x1000000,
    0x1000000,
    0,
    0,
    0);
  if ( *((_DWORD *)a4 - 1) != 1154662183 )
    __break(0x8234u);
  result = a4(a1);
  if ( (_DWORD)result )
  {
    if ( (*(_BYTE *)(a1 - 8) & 8) != 0 )
      return _clk_alpha_pll_update_latch(v7);
    else
      return 0;
  }
  return result;
}
