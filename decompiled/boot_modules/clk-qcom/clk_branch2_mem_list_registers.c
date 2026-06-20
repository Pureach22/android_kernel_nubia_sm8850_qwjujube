__int64 __fastcall clk_branch2_mem_list_registers(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 result; // x0
  __int64 v7; // x1
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 24);
  v5 = *(unsigned int *)(a2 - 12);
  v8 = 0;
  regmap_read(v4, v5, &v8);
  if ( a1 )
  {
    result = seq_printf(a1, "%20s: 0x%.8x\n", "CBCR", v8);
    v7 = *(unsigned int *)(a2 - 40);
    if ( !(_DWORD)v7 )
      goto LABEL_6;
  }
  else
  {
    result = printk(&unk_28721);
    v7 = *(unsigned int *)(a2 - 40);
    if ( !(_DWORD)v7 )
      goto LABEL_6;
  }
  if ( *(_DWORD *)(a2 - 36) )
  {
    regmap_read(*(_QWORD *)(a2 + 24), v7, &v8);
    if ( a1 )
    {
      seq_printf(a1, "%20s: 0x%.8x\n", "MEM_ENABLE", v8);
      regmap_read(*(_QWORD *)(a2 + 24), *(unsigned int *)(a2 - 36), &v8);
      seq_printf(a1, "%20s: 0x%.8x\n", "MEM_ENABLE_ACK", v8);
      result = seq_printf(a1, "%20s: 0x%.8x\n", "MEM_ENABLE_ACK_MASK", *(_DWORD *)(a2 - 28));
    }
    else
    {
      printk(&unk_28721);
      regmap_read(*(_QWORD *)(a2 + 24), *(unsigned int *)(a2 - 36), &v8);
      printk(&unk_28721);
      result = printk(&unk_28721);
    }
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
