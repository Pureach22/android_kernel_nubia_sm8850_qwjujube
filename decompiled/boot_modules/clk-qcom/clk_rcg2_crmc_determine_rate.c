__int64 __fastcall clk_rcg2_crmc_determine_rate(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 result; // x0
  unsigned int v6; // w0
  unsigned int v7; // w0
  unsigned int v8; // w20

  v2 = *(_QWORD *)(a1 + 120);
  result = clk_runtime_get_regmap(a1);
  if ( !(_DWORD)result )
  {
    v6 = qcom_clk_crm_init(*(_QWORD *)(a1 + 112), v2);
    if ( v6 )
    {
      v8 = v6;
      if ( !*(_QWORD *)(a1 + 16) )
        clk_hw_get_name(a1);
      printk(&unk_29052);
      goto LABEL_7;
    }
    if ( (*(_BYTE *)(a1 + 153) & 1) == 0 )
    {
      v7 = clk_rcg2_crmc_populate_freq_table(a1 - 48);
      if ( v7 )
      {
        v8 = v7;
        if ( !*(_QWORD *)(a1 + 16) )
          clk_hw_get_name(a1);
        printk(&unk_2884F);
        goto LABEL_7;
      }
      *(_BYTE *)(a1 + 153) = 1;
    }
    v8 = freq_tbl_determine_rate_0(a1, *(_QWORD *)(a1 - 8), a2, 1);
LABEL_7:
    clk_runtime_put_regmap(a1);
    return v8;
  }
  return result;
}
