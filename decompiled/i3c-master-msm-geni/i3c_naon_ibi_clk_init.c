__int64 __fastcall i3c_naon_ibi_clk_init(__int64 a1)
{
  unsigned __int64 v2; // x0
  unsigned int v3; // w19
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x0
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x0
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x0
  __int64 v13; // x3
  __int64 v14; // x0
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x0

  if ( *(_BYTE *)(a1 + 21460) == 1 )
  {
    v2 = devm_clk_get(*(_QWORD *)(a1 + 8), "ibic-core-clk");
    v3 = v2;
    *(_QWORD *)(a1 + 21464) = v2;
    if ( v2 >= 0xFFFFFFFFFFFFF001LL )
    {
      ipc_log_string(*(_QWORD *)(a1 + 2528), "Error getting NAON IBI Core clk %d\n", v2);
      v12 = *(_QWORD *)(a1 + 8);
      if ( v12 )
        dev_err(v12, "Error getting NAON IBI Core clk %d\n", v3);
      else
        printk(&unk_144BF, v3, v10, v11);
      if ( *(_QWORD *)(a1 + 8) )
        goto LABEL_27;
    }
    else
    {
      v3 = clk_set_rate(v2);
      if ( v3 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 2528), "%s:Error Setting the clock rate: %d\n", "i3c_naon_ibi_clk_init", v3);
        v14 = *(_QWORD *)(a1 + 8);
        if ( v14 )
          dev_err(v14, "%s:Error Setting the clock rate: %d\n", "i3c_naon_ibi_clk_init", v3);
        else
          printk(&unk_13DE2, "i3c_naon_ibi_clk_init", v3, v13);
        if ( *(_QWORD *)(a1 + 8) )
          i3c_trace_log();
      }
      v4 = devm_clk_get(*(_QWORD *)(a1 + 8), "ibic-ahb-clk");
      *(_QWORD *)(a1 + 21472) = v4;
      if ( v4 >= 0xFFFFFFFFFFFFF001LL )
      {
        v3 = v4;
        ipc_log_string(*(_QWORD *)(a1 + 2528), "Error getting NAON AHB clk %d\n", v4);
        v17 = *(_QWORD *)(a1 + 8);
        if ( v17 )
          dev_err(v17, "Error getting NAON AHB clk %d\n", v3);
        else
          printk(&unk_14E39, v3, v15, v16);
        if ( *(_QWORD *)(a1 + 8) )
          goto LABEL_27;
      }
      else
      {
        v5 = devm_clk_get(*(_QWORD *)(a1 + 8), "ibic-src-clk");
        *(_QWORD *)(a1 + 21480) = v5;
        if ( v5 >= 0xFFFFFFFFFFFFF001LL )
        {
          v3 = v5;
          ipc_log_string(*(_QWORD *)(a1 + 2528), "Error getting NAON src clk %d\n", v5);
          v8 = *(_QWORD *)(a1 + 8);
          if ( v8 )
            dev_err(v8, "Error getting NAON src clk %d\n", v3);
          else
            printk(&unk_13F1C, v3, v6, v7);
          if ( *(_QWORD *)(a1 + 8) )
LABEL_27:
            i3c_trace_log();
        }
      }
    }
  }
  else
  {
    return 0;
  }
  return v3;
}
