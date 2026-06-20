__int64 __fastcall pongo_elu_pll_list_registers(__int64 a1, __int64 a2)
{
  unsigned __int8 *v4; // x9
  __int64 result; // x0
  __int64 i; // x23
  __int64 v7; // x9
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 **)(a2 - 40);
  v8 = 0;
  regmap_read(*(_QWORD *)(a2 + 24), *(_DWORD *)(a2 - 48) + (unsigned int)*v4, &v8);
  if ( a1 )
    result = seq_printf(a1, "%20s: 0x%.8x\n", "PLL_MODE", v8);
  else
    result = printk(&unk_28721);
  for ( i = 0; i != 30; i += 2 )
  {
    v7 = LODWORD((&pongo_elu_pll_list_registers_data)[i + 3]);
    if ( *(_BYTE *)(*(_QWORD *)(a2 - 40) + v7) )
    {
      regmap_read(
        *(_QWORD *)(a2 + 24),
        *(_DWORD *)(a2 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a2 - 40) + v7),
        &v8);
      if ( a1 )
        result = seq_printf(a1, "%20s: 0x%.8x\n", (&pongo_elu_pll_list_registers_data)[i + 2], v8);
      else
        result = printk(&unk_28721);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
