__int64 __fastcall clk_regera_pll_set_rate(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned int *v6; // x19
  int v7; // t1
  unsigned __int8 *v8; // x9
  int v9; // w24
  int v10; // w25
  __int64 result; // x0
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x8
  char v14; // w11
  unsigned __int64 v15; // x2
  unsigned __int64 v16; // x9
  int v17; // w8
  unsigned int v18; // w23
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_DWORD *)(a1 - 48);
  v6 = (unsigned int *)(a1 - 48);
  v8 = *(unsigned __int8 **)(a1 - 40);
  v19[0] = 0;
  v9 = v8[4];
  v10 = v8[3];
  result = regmap_read(*(_QWORD *)(a1 + 24), v7 + (unsigned int)v8[1], (char *)v19 + 4);
  if ( !(_DWORD)result )
  {
    if ( !HIDWORD(v19[0]) )
    {
      v18 = clk_regera_pll_configure(v6, *(_QWORD *)(a1 + 24), *(unsigned int **)(a1 - 32));
      clk_hw_get_name(a1);
      if ( v18 )
      {
        printk(&unk_28177);
        result = v18;
        goto LABEL_24;
      }
      printk(&unk_28578);
    }
    v12 = a2 / (unsigned int)a3;
    v13 = a2 % (unsigned int)a3;
    HIDWORD(v19[0]) = v12;
    if ( v13 )
    {
      v14 = 16;
      if ( v9 - v10 == 4 )
        v14 = 32;
      v15 = (v13 << v14) / (unsigned int)a3;
      v16 = 1000 * (((((unsigned int)v15 * a3) >> v14) + (unsigned int)v12 * a3 + 999) / 0x3E8);
    }
    else
    {
      v15 = 0;
      v16 = a2;
    }
    if ( v16 > a2 + 500 || v16 < a2 )
    {
      printk(&unk_2929B);
      result = 4294967274LL;
      goto LABEL_24;
    }
    if ( (v15 & 0x8000) != 0 )
    {
      if ( a3 > 2 * v13 )
        v17 = a2;
      else
        v17 = a2 + 1;
      HIDWORD(v19[0]) = v17;
    }
    regmap_write(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL),
      v15);
    regmap_write(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL),
      HIDWORD(v19[0]));
    result = regmap_read(
               *(_QWORD *)(a1 + 24),
               *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL),
               v19);
    if ( !(_DWORD)result )
    {
      if ( !LODWORD(v19[0]) )
      {
LABEL_19:
        result = 0;
        goto LABEL_24;
      }
      _const_udelay(21475);
      result = wait_for_pll(v6, 0x80000000, 0, "enable");
      if ( !(_DWORD)result )
      {
        _const_udelay(429500);
        goto LABEL_19;
      }
    }
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
