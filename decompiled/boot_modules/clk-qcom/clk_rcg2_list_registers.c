__int64 __fastcall clk_rcg2_list_registers(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  char **v4; // x8
  char *v5; // x9
  __int64 v6; // x25
  int v7; // w24
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v3 = result;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a2 + 152) & 4) != 0 )
  {
    v4 = &clk_rcg2_list_registers_data3;
  }
  else
  {
    v4 = &clk_rcg2_list_registers_data1;
    if ( *(_BYTE *)(a2 - 44) )
      v4 = &clk_rcg2_list_registers_data2;
  }
  v5 = *v4;
  clk_rcg2_list_registers_data = (__int64)v4;
  if ( v5 )
  {
    v6 = 0;
    v7 = 1;
    v8 = 0;
    do
    {
      regmap_read(*(_QWORD *)(a2 + 24), (unsigned int)(*((_DWORD *)v4 + 2) + *(_DWORD *)(a2 - 48)), &v8);
      if ( v3 )
        result = seq_printf(v3, "%20s: 0x%.8x\n", *(const char **)(clk_rcg2_list_registers_data + 16 * v6), v8);
      else
        result = printk(&unk_28721);
      v6 = v7;
      v4 = (char **)(clk_rcg2_list_registers_data + 16LL * v7++);
    }
    while ( *v4 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
