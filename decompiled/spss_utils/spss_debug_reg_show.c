__int64 __fastcall spss_debug_reg_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x2
  unsigned int *v5; // x19
  __int64 v6; // x2
  unsigned int *v7; // x20
  __int64 v8; // x2
  __int64 v9; // x0
  unsigned int *v10; // x22
  int v11; // w23
  int v12; // w24
  int v13; // w25
  int v14; // w26
  int v15; // w27
  int v16; // w0
  __int64 v17; // x21

  if ( a1 && a2 && a3 )
  {
    if ( arm64_use_ng_mappings )
      v4 = 0x68000000000F13LL;
    else
      v4 = 0x68000000000713LL;
    v5 = (unsigned int *)ioremap_prot(spss_debug_reg_addr, 8, v4);
    if ( arm64_use_ng_mappings )
      v6 = 0x68000000000F13LL;
    else
      v6 = 0x68000000000713LL;
    v7 = (unsigned int *)ioremap_prot((unsigned int)spss_debug_reg_addr1, 8, v6);
    if ( arm64_use_ng_mappings )
      v8 = 0x68000000000F13LL;
    else
      v8 = 0x68000000000713LL;
    v9 = ioremap_prot((unsigned int)spss_debug_reg_addr3, 8, v8);
    if ( v5 )
    {
      if ( v7 )
      {
        v10 = (unsigned int *)v9;
        if ( v9 )
        {
          v11 = readl_relaxed(v5);
          v12 = readl_relaxed(v5 + 1);
          v13 = readl_relaxed(v7);
          v14 = readl_relaxed(v7 + 1);
          v15 = readl_relaxed(v10);
          v16 = readl_relaxed(v10 + 1);
          v17 = (int)scnprintf(
                       a3,
                       4096,
                       "MB0: val1[0x%x] val2[0x%x],\n MB1: val3[0x%x] val4[0x%x],\n MB3: val7[0x%x] val8[0x%x]\n",
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16);
        }
        else
        {
          printk(&unk_87FF, "spss_debug_reg_show");
          v17 = 0;
        }
        iounmap(v10);
      }
      else
      {
        printk(&unk_8A64, "spss_debug_reg_show");
        v17 = 0;
      }
      iounmap(v7);
    }
    else
    {
      printk(&unk_8554, "spss_debug_reg_show");
      v17 = 0;
    }
    iounmap(v5);
  }
  else
  {
    printk(&unk_8619, "spss_debug_reg_show");
    return -22;
  }
  return v17;
}
