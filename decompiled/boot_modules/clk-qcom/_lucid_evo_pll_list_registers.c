__int64 __fastcall lucid_evo_pll_list_registers(__int64 a1, __int64 a2, char a3)
{
  unsigned __int8 *v6; // x9
  __int64 i; // x24
  __int64 v8; // x9
  __int64 result; // x0
  __int64 v10; // x21
  __int64 v11; // x1
  __int64 v12; // x8
  int v13; // w25
  int v14; // w26
  int v15; // w27
  unsigned int v16; // w20
  int j; // w22
  int v18; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v19; // [xsp+10h] [xbp-10h] BYREF
  int v20; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int8 **)(a2 - 40);
  v18 = 0;
  regmap_read(*(_QWORD *)(a2 + 24), *(_DWORD *)(a2 - 48) + (unsigned int)*v6, &v18);
  if ( a1 )
    seq_printf(a1, "%20s: 0x%.8x\n", "PLL_MODE", v18);
  else
    printk(&unk_28721);
  for ( i = 0; i != 24; i += 2 )
  {
    v8 = LODWORD((&lucid_evo_pll_list_registers_data)[i + 3]);
    if ( *(_BYTE *)(*(_QWORD *)(a2 - 40) + v8) )
    {
      regmap_read(
        *(_QWORD *)(a2 + 24),
        *(_DWORD *)(a2 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a2 - 40) + v8),
        &v18);
      if ( a1 )
        seq_printf(a1, "%20s: 0x%.8x\n", (&lucid_evo_pll_list_registers_data)[i + 2], v18);
      else
        printk(&unk_28721);
    }
  }
  result = regmap_read(
             *(_QWORD *)(a2 + 24),
             *(_DWORD *)(a2 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a2 - 40) + 5LL),
             &v18);
  if ( (v18 & 0x2000000) == 0 )
  {
LABEL_12:
    if ( (a3 & 1) != 0 )
      goto LABEL_20;
    goto LABEL_13;
  }
  regmap_read(*(_QWORD *)(a2 + 24), *(unsigned int *)(a2 + 32), &v18);
  if ( a1 )
  {
    result = seq_printf(a1, "%20s: 0x%.8x\n", "APSS_PLL_VOTE", v18);
    goto LABEL_12;
  }
  result = printk(&unk_28721);
  if ( (a3 & 1) != 0 )
    goto LABEL_20;
LABEL_13:
  v10 = *(_QWORD *)(a2 + 24);
  v11 = *(unsigned int *)(a2 - 48);
  v20 = 0;
  v19 = 0;
  result = regmap_read(v10, v11, &v20);
  if ( (v20 & 4) != 0 )
  {
    v12 = *(_QWORD *)(a2 - 40);
    v13 = *(_DWORD *)(a2 - 48);
    v14 = *(unsigned __int8 *)(v12 + 12);
    v15 = *(unsigned __int8 *)(v12 + 18);
    regmap_read(v10, (unsigned int)(v13 + v14), &v19);
    regmap_update_bits_base(v10, (unsigned int)(v13 + v14), 256, 256, 0, 0, 0);
    v16 = 0;
    for ( j = 0; j != 32; ++j )
    {
      regmap_update_bits_base(v10, (unsigned int)(v13 + v14), 31744, v16, 0, 0, 0);
      regmap_read(v10, (unsigned int)(v13 + v15), &v20);
      if ( a1 )
        seq_printf(a1, "       PLL_STATUS_%02d: 0x%.8x\n", j, v20);
      else
        printk(&unk_28FCC);
      v16 += 1024;
    }
    result = regmap_write(v10, (unsigned int)(v13 + v14), v19);
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
