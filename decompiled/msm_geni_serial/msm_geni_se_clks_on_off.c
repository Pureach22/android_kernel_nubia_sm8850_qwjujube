void __fastcall msm_geni_se_clks_on_off(_QWORD *a1, char a2)
{
  unsigned int v3; // w0
  const char *v4; // x21
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x22
  unsigned int v8; // w0
  unsigned int v9; // w0
  __int64 v10; // x20
  __int64 v11; // x22
  __int64 v12; // x21

  if ( (a2 & 1) != 0 )
  {
    v3 = geni_icc_enable(a1 + 89);
    if ( v3 )
    {
      v4 = "%s: Error %d geni_icc_enable failed\n";
      ipc_log_string(a1[120], "%s: Error %d geni_icc_enable failed\n", "msm_geni_se_clks_on_off", v3);
      goto LABEL_8;
    }
    v9 = geni_icc_set_bw(a1 + 89);
    if ( v9 )
    {
      v4 = "%s: Error %d ICC BW voting failed\n";
      ipc_log_string(a1[120], "%s: Error %d ICC BW voting failed\n", "msm_geni_se_clks_on_off", v9);
      goto LABEL_8;
    }
    v10 = a1[82];
    v11 = a1[81];
    v12 = a1[83];
    if ( !(unsigned int)clk_prepare(v10) )
    {
      if ( (unsigned int)clk_enable(v10) )
      {
LABEL_16:
        clk_unprepare(v10);
        goto LABEL_17;
      }
      if ( (unsigned int)clk_prepare_enable(v12) )
      {
LABEL_15:
        clk_disable(v10);
        goto LABEL_16;
      }
      if ( (unsigned int)clk_prepare_enable(v11) )
      {
        clk_disable(v12);
        clk_unprepare(v12);
        goto LABEL_15;
      }
    }
LABEL_17:
    msm_geni_enable_disable_se_clk(a1, 1);
    return;
  }
  msm_geni_enable_disable_se_clk(a1, 0);
  v5 = a1[81];
  v6 = a1[82];
  v7 = a1[83];
  clk_disable(v5);
  clk_unprepare(v5);
  clk_disable(v6);
  clk_unprepare(v6);
  clk_disable(v7);
  clk_unprepare(v7);
  v8 = geni_icc_disable(a1 + 89);
  if ( !v8 )
    return;
  v4 = "%s: Error %d geni_icc_disable failed\n";
  ipc_log_string(a1[120], "%s: Error %d geni_icc_disable failed\n", "msm_geni_se_clks_on_off", v8);
LABEL_8:
  _ftrace_dbg(a1[43], v4);
}
