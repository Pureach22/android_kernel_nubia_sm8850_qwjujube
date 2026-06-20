__int64 __fastcall clk_zonda_pll_set_rate(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v4; // x10
  char v5; // w11
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x20
  int v8; // w12
  __int64 v9; // x0
  unsigned int v10; // w11
  unsigned int v11; // w20
  const char *v12; // x3
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 result; // x0
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v4 = a2 % (unsigned int)a3;
  if ( v4 )
  {
    v5 = 16;
    if ( *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 4LL) - *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL) == 4 )
      v5 = 32;
    v6 = (v4 << v5) / (unsigned int)a3;
    v7 = 1000 * (((((unsigned int)v6 * a3) >> v5) + (unsigned int)(a2 / (unsigned int)a3) * a3 + 999) / 0x3E8);
  }
  else
  {
    LODWORD(v6) = 0;
    v7 = a2;
  }
  if ( v7 < a2 || a2 + 500 < v7 )
  {
    clk_hw_get_name(a1);
    printk(&unk_28661);
    result = 4294967274LL;
    goto LABEL_21;
  }
  v8 = *(_DWORD *)(a1 - 48);
  v9 = *(_QWORD *)(a1 + 24);
  if ( a3 > 2 * v4 )
    v10 = a2;
  else
    v10 = a2 + 1;
  if ( (v6 & 0x8000) != 0 )
    v11 = v10;
  else
    v11 = a2 / (unsigned int)a3;
  regmap_write(v9, v8 + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL), (unsigned int)v6);
  regmap_write(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL),
    v11);
  if ( (clk_hw_is_enabled(a1) & 1) == 0 )
    goto LABEL_20;
  _const_udelay(21475);
  regmap_read(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 12LL),
    &v16);
  if ( (v16 & 0x10000) != 0 )
  {
    v12 = "freq enable";
    v13 = a1 - 48;
    v14 = 0x20000000;
  }
  else
  {
    v12 = "enable";
    v13 = a1 - 48;
    v14 = 0x80000000LL;
  }
  result = wait_for_pll(v13, v14, 0, v12);
  if ( !(_DWORD)result )
  {
    _const_udelay(429500);
LABEL_20:
    result = 0;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
