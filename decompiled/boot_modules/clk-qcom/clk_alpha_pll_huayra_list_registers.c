__int64 __fastcall clk_alpha_pll_huayra_list_registers(__int64 a1, __int64 a2)
{
  __int64 v4; // x23
  __int64 result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v4 = 0;
  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  do
  {
    regmap_read(
      *(_QWORD *)(a2 + 24),
      *(_DWORD *)(a2 - 48)
    + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a2 - 40) + LODWORD((&clk_regera_pll_list_registers_data)[v4 + 1])),
      &v6);
    if ( a1 )
      seq_printf(a1, "%20s: 0x%.8x\n", (&clk_regera_pll_list_registers_data)[v4], v6);
    else
      printk(&unk_28721);
    v4 += 2;
  }
  while ( v4 != 24 );
  result = regmap_read(*(_QWORD *)(a2 + 24), *(_DWORD *)(a2 - 48) + (unsigned int)**(unsigned __int8 **)(a2 - 40), &v6);
  if ( (v6 & 0x100000) != 0 )
  {
    regmap_read(*(_QWORD *)(a2 + 24), *(unsigned int *)(a2 + 32), &v6);
    if ( a1 )
      result = seq_printf(a1, "%20s: 0x%.8x\n", "APSS_PLL_VOTE", v6);
    else
      result = printk(&unk_28721);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
