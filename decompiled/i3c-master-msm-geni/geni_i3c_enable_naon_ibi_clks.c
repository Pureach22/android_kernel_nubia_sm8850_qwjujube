__int64 __fastcall geni_i3c_enable_naon_ibi_clks(__int64 a1, char a2)
{
  __int64 v2; // x22
  __int64 v4; // x20
  __int64 v5; // x20
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x21
  unsigned int v10; // w0
  unsigned int v11; // w0
  __int64 v12; // x21
  unsigned int v13; // w0
  unsigned int v14; // w0
  __int64 v15; // x21
  unsigned int v16; // w0
  unsigned int v17; // w0
  __int64 v18; // x0
  unsigned int v19; // w20
  __int64 v20; // x3
  __int64 v21; // x0
  __int64 v22; // x3
  __int64 v23; // x0
  __int64 v24; // x19
  __int64 v25; // x3
  __int64 v26; // x0
  __int64 v27; // x21

  v2 = a1 + 20480;
  if ( *(_BYTE *)(a1 + 21460) != 1 )
    return 4294967274LL;
  if ( (a2 & 1) != 0 && (*(_BYTE *)(a1 + 21461) & 1) == 0 )
  {
    v9 = *(_QWORD *)(a1 + 21464);
    v10 = clk_prepare(v9);
    if ( v10 )
    {
      v19 = v10;
    }
    else
    {
      v11 = clk_enable(v9);
      if ( !v11 )
      {
        v12 = *(_QWORD *)(a1 + 21472);
        v13 = clk_prepare(v12);
        if ( v13 )
        {
          v19 = v13;
        }
        else
        {
          v14 = clk_enable(v12);
          if ( !v14 )
          {
            v15 = *(_QWORD *)(a1 + 21480);
            v16 = clk_prepare(v15);
            if ( v16 )
            {
              v19 = v16;
            }
            else
            {
              v17 = clk_enable(v15);
              if ( !v17 )
              {
                v18 = *(_QWORD *)(a1 + 2528);
                *(_BYTE *)(v2 + 981) = 1;
                ipc_log_string(v18, "%s: Enable Clock success\n", "geni_i3c_enable_naon_ibi_clks");
                result = *(_QWORD *)(a1 + 8);
                if ( result )
                  goto LABEL_5;
                return result;
              }
              v19 = v17;
              clk_unprepare(v15);
            }
            ipc_log_string(
              *(_QWORD *)(a1 + 2528),
              "%s failed at NAON src clk enable ret=%d\n",
              "geni_i3c_enable_naon_ibi_clks",
              v19);
            v26 = *(_QWORD *)(a1 + 8);
            if ( v26 )
              dev_err(v26, "%s failed at NAON src clk enable ret=%d\n", "geni_i3c_enable_naon_ibi_clks", v19);
            else
              printk(&unk_144E5, "geni_i3c_enable_naon_ibi_clks", v19, v25);
            if ( *(_QWORD *)(a1 + 8) )
              i3c_trace_log();
            v27 = *(_QWORD *)(a1 + 21464);
            clk_disable(v27);
            clk_unprepare(v27);
            v24 = *(_QWORD *)(a1 + 21472);
            goto LABEL_39;
          }
          v19 = v14;
          clk_unprepare(v12);
        }
        ipc_log_string(
          *(_QWORD *)(a1 + 2528),
          "%s failed at NAON ahb clk enable ret=%d\n",
          "geni_i3c_enable_naon_ibi_clks",
          v19);
        v23 = *(_QWORD *)(a1 + 8);
        if ( v23 )
          dev_err(v23, "%s failed at NAON ahb clk enable ret=%d\n", "geni_i3c_enable_naon_ibi_clks", v19);
        else
          printk(&unk_12D64, "geni_i3c_enable_naon_ibi_clks", v19, v22);
        if ( *(_QWORD *)(a1 + 8) )
          i3c_trace_log();
        v24 = *(_QWORD *)(a1 + 21464);
LABEL_39:
        clk_disable(v24);
        clk_unprepare(v24);
        return v19;
      }
      v19 = v11;
      clk_unprepare(v9);
    }
    ipc_log_string(
      *(_QWORD *)(a1 + 2528),
      "%s failed at NAON core clk enable ret=%d\n",
      "geni_i3c_enable_naon_ibi_clks",
      v19);
    v21 = *(_QWORD *)(a1 + 8);
    if ( v21 )
      dev_err(v21, "%s failed at NAON core clk enable ret=%d\n", "geni_i3c_enable_naon_ibi_clks", v19);
    else
      printk(&unk_127BC, "geni_i3c_enable_naon_ibi_clks", v19, v20);
    if ( *(_QWORD *)(a1 + 8) )
    {
      i3c_trace_log();
      return v19;
    }
    return v19;
  }
  v4 = *(_QWORD *)(a1 + 21464);
  clk_disable(v4);
  clk_unprepare(v4);
  v5 = *(_QWORD *)(a1 + 21472);
  clk_disable(v5);
  clk_unprepare(v5);
  v6 = *(_QWORD *)(a1 + 21480);
  clk_disable(v6);
  clk_unprepare(v6);
  v7 = *(_QWORD *)(a1 + 2528);
  *(_BYTE *)(v2 + 981) = 0;
  ipc_log_string(v7, "%s: Disable clock success\n", "geni_i3c_enable_naon_ibi_clks");
  result = *(_QWORD *)(a1 + 8);
  if ( result )
  {
LABEL_5:
    i3c_trace_log();
    return 0;
  }
  return result;
}
