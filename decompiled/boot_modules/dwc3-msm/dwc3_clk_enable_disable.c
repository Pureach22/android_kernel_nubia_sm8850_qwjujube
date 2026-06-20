__int64 __fastcall dwc3_clk_enable_disable(_QWORD *a1, char a2, char a3)
{
  __int64 result; // x0
  __int64 v6; // x21
  int v7; // w0
  int v8; // w0
  int v9; // w22
  __int64 v10; // x21
  unsigned int v11; // w0
  unsigned int v12; // w0
  unsigned int v13; // w22
  __int64 v14; // x21
  unsigned int v15; // w0
  unsigned int v16; // w0
  unsigned int v17; // w22
  __int64 v18; // x21
  unsigned int v19; // w0
  unsigned int v20; // w0
  unsigned int v21; // w22
  __int64 v22; // x1
  __int64 v23; // x8
  __int64 v24; // x21
  unsigned int v25; // w22
  __int64 v26; // x21
  __int64 v27; // x21
  __int64 v28; // x21
  __int64 v29; // x21
  __int64 v30; // x20
  __int64 v31; // x19
  __int64 v32; // x21
  unsigned int v33; // w0
  unsigned int v34; // w0
  unsigned int v35; // w22
  __int64 v36; // x21
  unsigned int v37; // w0
  unsigned int v38; // w0
  unsigned int v39; // w22
  __int64 v40; // x21
  unsigned int v41; // w0
  unsigned int v42; // w22
  __int64 v43; // x8
  unsigned int v44; // w19

  if ( (*((_BYTE *)a1 + 2804) & 1) != 0 )
    return 0;
  if ( (a2 & 1) == 0 )
  {
    v24 = a1[51];
    clk_disable(v24);
    clk_unprepare(v24);
    v25 = 0;
LABEL_25:
    v26 = a1[48];
    clk_disable(v26);
    clk_unprepare(v26);
LABEL_26:
    clk_set_rate(a1[42], 19200000);
    v27 = a1[42];
    clk_disable(v27);
    clk_unprepare(v27);
LABEL_27:
    v28 = a1[52];
    clk_disable(v28);
    clk_unprepare(v28);
    goto LABEL_28;
  }
  v6 = a1[41];
  v7 = clk_prepare(v6);
  if ( !v7 )
  {
    v8 = clk_enable(v6);
    if ( !v8 )
      goto LABEL_8;
    v9 = v8;
    clk_unprepare(v6);
    v7 = v9;
  }
  if ( v7 < 0 )
  {
    v43 = *a1;
    v44 = v7;
    dev_err(v43, "%s failed to vote TCXO buffer%d\n", "dwc3_clk_enable_disable", v7);
    return v44;
  }
LABEL_8:
  if ( (a3 & 1) == 0 )
    goto LABEL_13;
  v10 = a1[47];
  v11 = clk_prepare(v10);
  if ( !v11 )
  {
    v12 = clk_enable(v10);
    if ( !v12 )
      goto LABEL_13;
    v13 = v12;
    clk_unprepare(v10);
    v11 = v13;
  }
  if ( (v11 & 0x80000000) != 0 )
  {
    v25 = v11;
    dev_err(*a1, "%s: sleep_clk enable failed\n", "dwc3_clk_enable_disable");
    goto LABEL_30;
  }
LABEL_13:
  v14 = a1[46];
  v15 = clk_prepare(v14);
  if ( !v15 )
  {
    v16 = clk_enable(v14);
    if ( !v16 )
      goto LABEL_17;
    v17 = v16;
    clk_unprepare(v14);
    v15 = v17;
  }
  if ( (v15 & 0x80000000) != 0 )
  {
    v25 = v15;
    dev_err(*a1, "%s: iface_clk enable failed\n", "dwc3_clk_enable_disable");
    if ( (a3 & 1) == 0 )
      goto LABEL_30;
    goto LABEL_29;
  }
LABEL_17:
  v18 = a1[52];
  v19 = clk_prepare(v18);
  if ( !v19 )
  {
    v20 = clk_enable(v18);
    if ( !v20 )
      goto LABEL_21;
    v21 = v20;
    clk_unprepare(v18);
    v19 = v21;
  }
  if ( (v19 & 0x80000000) != 0 )
  {
    v25 = v19;
    dev_err(*a1, "%s: noc_aggr_clk enable failed\n", "dwc3_clk_enable_disable");
LABEL_28:
    v29 = a1[46];
    clk_disable(v29);
    clk_unprepare(v29);
    if ( (a3 & 1) == 0 )
    {
LABEL_30:
      v31 = a1[41];
      clk_disable(v31);
      clk_unprepare(v31);
      return v25;
    }
LABEL_29:
    v30 = a1[47];
    clk_disable(v30);
    clk_unprepare(v30);
    goto LABEL_30;
  }
LABEL_21:
  v22 = a1[45];
  if ( *((_BYTE *)a1 + 736) == 1 && *((_DWORD *)a1 + 185) == 3 )
  {
    v23 = 44;
  }
  else
  {
    if ( (a1[96] & 4) != 0 )
      goto LABEL_34;
    v23 = 43;
  }
  v22 = a1[v23];
LABEL_34:
  clk_set_rate(a1[42], v22);
  v32 = a1[42];
  v33 = clk_prepare(v32);
  if ( !v33 )
  {
    v34 = clk_enable(v32);
    if ( !v34 )
      goto LABEL_38;
    v35 = v34;
    clk_unprepare(v32);
    v33 = v35;
  }
  if ( (v33 & 0x80000000) != 0 )
  {
    v25 = v33;
    dev_err(*a1, "%s: core_clk enable failed\n", "dwc3_clk_enable_disable");
    goto LABEL_27;
  }
LABEL_38:
  v36 = a1[48];
  v37 = clk_prepare(v36);
  if ( !v37 )
  {
    v38 = clk_enable(v36);
    if ( !v38 )
      goto LABEL_42;
    v39 = v38;
    clk_unprepare(v36);
    v37 = v39;
  }
  if ( (v37 & 0x80000000) != 0 )
  {
    v25 = v37;
    dev_err(*a1, "%s: utmi_clk enable failed\n", "dwc3_clk_enable_disable");
    goto LABEL_26;
  }
LABEL_42:
  v40 = a1[51];
  v41 = clk_prepare(v40);
  if ( !v41 )
  {
    result = clk_enable(v40);
    if ( !(_DWORD)result )
      return result;
    v42 = result;
    clk_unprepare(v40);
    v41 = v42;
  }
  if ( (v41 & 0x80000000) != 0 )
  {
    v25 = v41;
    dev_err(*a1, "%s: bus_aggr_clk enable failed\n", "dwc3_clk_enable_disable");
    goto LABEL_25;
  }
  return 0;
}
