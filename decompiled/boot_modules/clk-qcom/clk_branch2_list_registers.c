__int64 __fastcall clk_branch2_list_registers(__int64 a1, __int64 a2)
{
  unsigned int v3; // w8
  __int64 v4; // x0
  __int64 result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a2 - 12);
  v4 = *(_QWORD *)(a2 + 24);
  v6 = 0;
  regmap_read(v4, v3, &v6);
  if ( a1 )
    result = seq_printf(a1, "%20s: 0x%.8x\n", "CBCR", v6);
  else
    result = printk(&unk_28721);
  _ReadStatusReg(SP_EL0);
  return result;
}
