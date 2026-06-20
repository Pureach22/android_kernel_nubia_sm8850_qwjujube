__int64 __fastcall clk_rcg2_crmc_hw_set_rate(__int64 a1, unsigned int a2, unsigned int a3, int a4, __int64 a5)
{
  __int64 v9; // x23
  __int64 v10; // x0
  unsigned int crm_freq_index; // w0
  int v12; // w8
  __int64 v13; // x0
  int v14; // w20
  __int64 result; // x0
  _DWORD v16[3]; // [xsp+8h] [xbp-18h] BYREF
  int v17; // [xsp+14h] [xbp-Ch]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 120);
  v10 = *(_QWORD *)(a1 - 8);
  v17 = 0;
  crm_freq_index = qcom_find_crm_freq_index(v10, a5);
  if ( (crm_freq_index & 0x80000000) != 0 || crm_freq_index >= *(unsigned __int8 *)(v9 + 45) )
  {
    if ( !*(_QWORD *)(a1 + 16) )
      clk_hw_get_name(a1);
    printk(&unk_2910A);
    result = -22;
  }
  else
  {
    v12 = *(unsigned __int8 *)(a1 + 128);
    LOBYTE(v17) = 1;
    v16[1] = v12;
    v16[2] = crm_freq_index;
    v13 = *(_QWORD *)(v9 + 16);
    v16[0] = a4;
    v14 = crm_write_perf_ol(v13, a2, a3, v16);
    if ( v14 )
    {
      if ( !*(_QWORD *)(a1 + 16) )
        clk_hw_get_name(a1);
      printk(&unk_28B00);
      if ( v14 == -110 && (unsigned int)crm_dump_regs(**(_QWORD **)(a1 + 120)) )
      {
        if ( !*(_QWORD *)(a1 + 16) )
          clk_hw_get_name(a1);
        printk(&unk_28CEC);
      }
    }
    result = v14;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
