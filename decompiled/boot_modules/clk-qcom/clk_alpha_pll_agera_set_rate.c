__int64 __fastcall clk_alpha_pll_agera_set_rate(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x9
  unsigned __int64 v6; // x2
  unsigned __int64 v7; // x10
  char v8; // w11
  unsigned __int64 v9; // x20
  unsigned __int64 v10; // x21

  v3 = (unsigned int)a3;
  v6 = a2 / (unsigned int)a3;
  v7 = a2 - v6 * v3;
  if ( v7 )
  {
    v8 = 16;
    if ( *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 4LL) - *(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL) == 4 )
      v8 = 32;
    v9 = (v7 << v8) / v3;
    v10 = 1000 * (((((unsigned __int64)(unsigned int)v9 * a3) >> v8) + (unsigned int)v6 * a3 + 999) / 0x3E8);
  }
  else
  {
    LODWORD(v9) = 0;
    v10 = a2;
  }
  if ( v10 < a2 || a2 + 500 < v10 )
  {
    clk_hw_get_name(a1);
    printk(&unk_28661);
    return 4294967274LL;
  }
  else
  {
    regmap_write(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 1LL),
      v6);
    regmap_write(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL),
      (unsigned int)v9);
    if ( (clk_hw_is_enabled(a1) & 1) != 0 )
      return wait_for_pll(a1 - 48, 0x80000000LL, 0, "enable");
    else
      return 0;
  }
}
