__int64 __fastcall clk_regmap_mux_list_registers(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 24);
  v4 = *(unsigned int *)(a2 - 24);
  v6 = 0;
  regmap_read(v3, v4, &v6);
  if ( a1 )
    result = seq_printf(a1, "%20s: 0x%.8x\n", "MUXR", v6);
  else
    result = printk(&unk_28721);
  _ReadStatusReg(SP_EL0);
  return result;
}
