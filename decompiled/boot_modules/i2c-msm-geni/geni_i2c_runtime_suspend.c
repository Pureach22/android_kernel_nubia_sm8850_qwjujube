__int64 __fastcall geni_i2c_runtime_suspend(__int64 a1)
{
  __int64 *v1; // x19
  __int64 v2; // x21
  unsigned __int64 v3; // x20
  int v4; // w8
  unsigned int v5; // w0
  unsigned int v6; // w21
  __int64 v7; // x21
  __int64 v8; // x22
  __int64 v9; // x23
  int v10; // w8
  __int64 v11; // x22
  __int64 v12; // x0
  __int64 v13; // x22
  __int64 v14; // x0
  __int64 v16; // x21
  __int64 v17; // x22
  __int64 v18; // x23

  v1 = *(__int64 **)(a1 + 152);
  v2 = v1[638];
  if ( v2 )
  {
    if ( *((_DWORD *)v1 + 1278) )
    {
      v3 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "geni_i2c_runtime_suspend", v3, v3 / 0x3E8);
    }
    else
    {
      v3 = 0;
    }
  }
  else
  {
    v3 = -22;
  }
  v4 = *((_DWORD *)v1 + 2270);
  if ( v4 == 1 )
  {
    disable_irq(*((unsigned int *)v1 + 5));
    v4 = *((_DWORD *)v1 + 2270);
  }
  if ( v4 == 2 && (v1[1138] & 1) == 0 )
  {
    v5 = geni_i2c_gpi_pause_resume(v1, 1);
    if ( v5 )
    {
      v6 = v5;
      goto LABEL_12;
    }
  }
  if ( *((_BYTE *)v1 + 9114) == 1 )
  {
    if ( *((_BYTE *)v1 + 9085) == 1 )
    {
      v7 = v1[623];
      v8 = v1[632];
      v9 = v1[633];
      clk_disable(v7);
      clk_unprepare(v7);
      clk_disable(v8);
      clk_unprepare(v8);
      clk_disable(v9);
      clk_unprepare(v9);
    }
    else if ( (v1[1138] & 1) == 0 )
    {
      geni_se_resources_off(v1 + 620);
    }
    goto LABEL_28;
  }
  v10 = *((unsigned __int8 *)v1 + 9104);
  if ( v10 != 1 || *((_BYTE *)v1 + 9108) != 1 )
  {
    if ( *((_BYTE *)v1 + 9085) == 1 && (*((_BYTE *)v1 + 9106) & 1) == 0 )
    {
      v16 = v1[623];
      v17 = v1[632];
      v18 = v1[633];
      clk_disable(v16);
      clk_unprepare(v16);
      clk_disable(v17);
      clk_unprepare(v17);
      clk_disable(v18);
      clk_unprepare(v18);
    }
    else
    {
      if ( (v10 & 1) != 0 )
        goto LABEL_28;
      geni_se_resources_off(v1 + 620);
    }
    v6 = geni_icc_disable(v1 + 620);
    if ( v6 )
    {
      ipc_log_string(v1[637], "%s failing at geni_icc_disable ret=%d\n", "geni_i2c_runtime_suspend", v6);
      if ( *v1 )
        i2c_trace_log();
    }
LABEL_29:
    if ( *((_BYTE *)v1 + 9110) == 1 )
    {
      v11 = v1[634];
      clk_disable(v11);
      clk_unprepare(v11);
    }
    ipc_log_string(v1[637], "%s ret=%d\n", "geni_i2c_runtime_suspend", v6);
    v12 = *v1;
    if ( *v1 )
      i2c_trace_log();
    v13 = v1[638];
    if ( v13 )
    {
      v6 = 0;
      if ( !v3 || !*((_DWORD *)v1 + 1278) )
        return v6;
      v14 = sched_clock(v12);
      ipc_log_string(v13, "%s:took %llu nsec(%llu usec)\n", "geni_i2c_runtime_suspend", v14 - v3, (v14 - v3) / 0x3E8);
    }
    return 0;
  }
  geni_i2c_unlock_bus(v1);
  if ( *((_DWORD *)v1 + 2270) != 2 )
  {
LABEL_28:
    v6 = 0;
    goto LABEL_29;
  }
  v6 = geni_i2c_gpi_pause_resume(v1, 1);
  if ( !v6 )
    goto LABEL_29;
LABEL_12:
  ipc_log_string(v1[637], "%s: ret:%d\n", "geni_i2c_runtime_suspend", v6);
  if ( *v1 )
    i2c_trace_log();
  return v6;
}
