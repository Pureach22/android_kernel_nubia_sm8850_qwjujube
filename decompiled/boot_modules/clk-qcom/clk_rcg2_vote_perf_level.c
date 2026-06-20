__int64 __fastcall clk_rcg2_vote_perf_level(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x21
  unsigned int crm_freq_index; // w0
  int v5; // w8
  __int64 v6; // x0
  __int64 v7; // x2
  int v8; // w0
  __int64 v9; // x0
  __int64 v10; // x2
  int v11; // w0
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 result; // x0
  int v15; // w20
  int v16; // w20
  unsigned int v17; // w20
  _DWORD v18[3]; // [xsp+8h] [xbp-18h] BYREF
  int v19; // [xsp+14h] [xbp-Ch]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 8);
  v3 = *(_QWORD *)(a1 + 120);
  v19 = 0;
  if ( v2 && (*(_BYTE *)(v3 + 44) & 1) != 0 )
  {
    crm_freq_index = qcom_find_crm_freq_index();
    if ( (crm_freq_index & 0x80000000) != 0 || crm_freq_index >= *(unsigned __int8 *)(v3 + 45) )
    {
      if ( !*(_QWORD *)(a1 + 16) )
        clk_hw_get_name(a1);
      printk(&unk_2910A);
      result = 4294967274LL;
    }
    else
    {
      v18[2] = crm_freq_index;
      v5 = *(unsigned __int8 *)(a1 + 128);
      v6 = *(_QWORD *)(v3 + 16);
      v7 = *(unsigned __int8 *)(v3 + 46);
      LOBYTE(v19) = 1;
      v18[0] = 0;
      v18[1] = v5;
      v8 = crm_write_perf_ol(v6, 1, v7, v18);
      if ( v8 )
      {
        v15 = v8;
        if ( !*(_QWORD *)(a1 + 16) )
          clk_hw_get_name(a1);
        printk(&unk_28B00);
        if ( v15 == -110 && (unsigned int)crm_dump_regs(**(_QWORD **)(a1 + 120)) )
        {
          if ( !*(_QWORD *)(a1 + 16) )
            clk_hw_get_name(a1);
          printk(&unk_28CEC);
        }
      }
      v9 = *(_QWORD *)(v3 + 16);
      v10 = *(unsigned __int8 *)(v3 + 46);
      v18[0] = 1;
      v11 = crm_write_perf_ol(v9, 1, v10, v18);
      if ( v11 )
      {
        v16 = v11;
        if ( !*(_QWORD *)(a1 + 16) )
          clk_hw_get_name(a1);
        printk(&unk_28B00);
        if ( v16 == -110 && (unsigned int)crm_dump_regs(**(_QWORD **)(a1 + 120)) )
        {
          if ( !*(_QWORD *)(a1 + 16) )
            clk_hw_get_name(a1);
          printk(&unk_28CEC);
        }
      }
      v12 = *(_QWORD *)(v3 + 16);
      v13 = *(unsigned __int8 *)(v3 + 46);
      v18[0] = 2;
      result = crm_write_perf_ol(v12, 1, v13, v18);
      if ( (_DWORD)result )
      {
        v17 = result;
        if ( !*(_QWORD *)(a1 + 16) )
          clk_hw_get_name(a1);
        printk(&unk_28B00);
        result = v17;
        if ( v17 == -110 )
        {
          if ( (unsigned int)crm_dump_regs(**(_QWORD **)(a1 + 120)) )
          {
            if ( !*(_QWORD *)(a1 + 16) )
              clk_hw_get_name(a1);
            printk(&unk_28CEC);
          }
          result = 4294967186LL;
        }
      }
    }
  }
  else
  {
    if ( !*(_QWORD *)(a1 + 16) )
      clk_hw_get_name(a1);
    printk(&unk_28D8D);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
