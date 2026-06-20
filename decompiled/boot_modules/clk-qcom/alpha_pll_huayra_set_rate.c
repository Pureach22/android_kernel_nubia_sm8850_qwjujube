__int64 __fastcall alpha_pll_huayra_set_rate(__int64 a1, unsigned __int64 a2, unsigned int a3)
{
  unsigned __int64 v4; // x20
  unsigned __int64 v5; // x9
  unsigned __int64 v6; // x21
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 result; // x0
  int v13; // [xsp+Ch] [xbp-14h] BYREF
  int v14; // [xsp+10h] [xbp-10h] BYREF
  int v15; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v4 = a2 / a3;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v5 = a2 % a3;
  if ( v5 )
  {
    v6 = (v5 << 16) / a3;
    if ( (v6 & 0x7FFFFFFFFFFF8000LL) != 0 )
      LODWORD(v4) = v4 + 1;
  }
  else
  {
    LODWORD(v6) = 0;
  }
  v7 = *(_QWORD *)(a1 - 40);
  v14 = 0;
  regmap_read(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(v7 + 5), &v14);
  if ( (v14 & 0x1000000) != 0 )
    regmap_read(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL),
      &v13);
  v8 = *(_QWORD *)(a1 + 24);
  v9 = *(unsigned int *)(a1 - 48);
  v15 = 0;
  if ( (unsigned int)regmap_read(v8, v9, &v15) || v15 < 0 )
  {
    if ( v13 == (_DWORD)v6 )
    {
      regmap_write(
        *(_QWORD *)(a1 + 24),
        *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL),
        (unsigned int)v4);
      __dsb(0xFu);
      result = wait_for_pll(a1 - 48, 0x80000000LL, 0, "enable");
    }
    else
    {
      clk_hw_get_name(a1);
      printk(&unk_28E59);
      result = 4294967280LL;
    }
  }
  else
  {
    regmap_write(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL),
      (unsigned int)v4);
    regmap_write(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL),
      (unsigned int)v6);
    if ( (_DWORD)v6 )
    {
      v10 = 50331648;
      v11 = 0x1000000;
    }
    else
    {
      v10 = 0x1000000;
      v11 = 0;
    }
    regmap_update_bits_base(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
      v10,
      v11,
      0,
      0,
      0);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
