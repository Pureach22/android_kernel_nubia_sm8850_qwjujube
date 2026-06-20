__int64 __fastcall clk_alpha_pll_stromer_plus_set_rate(__int64 a1, unsigned __int64 a2, unsigned int a3)
{
  unsigned __int64 v3; // x21
  unsigned __int64 v5; // x9
  __int64 v6; // x1
  unsigned int *v7; // x20
  int v8; // w22
  char v9; // w10
  unsigned __int64 v10; // x23
  __int64 v11; // x0
  __int64 result; // x0
  unsigned __int64 v13; // x21
  unsigned int v14; // w0
  unsigned int v15; // w20
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v3 = a2 / a3;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a2 % a3;
  v7 = (unsigned int *)(a1 - 48);
  v6 = *(unsigned int *)(a1 - 48);
  v8 = *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 4LL) - *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL);
  if ( v5 )
  {
    v9 = 16;
    if ( v8 == 4 )
      v9 = 32;
    v10 = (v5 << v9) / a3;
  }
  else
  {
    v10 = 0;
  }
  v11 = *(_QWORD *)(a1 + 24);
  v16 = 0;
  result = regmap_read(v11, v6, &v16);
  if ( !(_DWORD)result )
  {
    regmap_write(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 0);
    _const_udelay(4295);
    regmap_write(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL),
      (unsigned int)v3);
    if ( v8 == 4 )
      v13 = v10 << 8;
    else
      v13 = v10;
    regmap_write(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL),
      (unsigned int)v13);
    regmap_write(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 4LL),
      HIDWORD(v13));
    regmap_update_bits_base(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
      0x1000000,
      0x1000000,
      0,
      0,
      0);
    regmap_write(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 2);
    _const_udelay(21475);
    regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 4, 4, 0, 0, 0);
    usleep_range_state(50, 60, 2);
    v14 = wait_for_pll(v7, 0x80000000, 0, "enable");
    if ( v14 )
    {
      v15 = v14;
      clk_hw_get_name(a1);
      printk(&unk_28695);
      result = v15;
    }
    else
    {
      if ( (v16 & 1) != 0 )
        regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 1, 1, 0, 0, 0);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
