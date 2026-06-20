__int64 __fastcall geni_i2c_runtime_resume(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x20
  unsigned __int64 v3; // x21
  __int64 v4; // x0
  unsigned int v5; // w0
  unsigned int v6; // w0
  unsigned int v7; // w20
  const char *v8; // x3
  int v9; // w0
  __int64 v10; // x22
  __int64 v11; // x0
  __int64 v12; // x22
  __int64 v13; // x0
  unsigned int v14; // w23
  unsigned int v15; // w0
  unsigned int v16; // w23
  unsigned int v17; // w0
  unsigned int v18; // w23
  unsigned int v19; // w0
  __int64 v20; // x22
  unsigned int v21; // w0
  unsigned int v22; // w0
  int v23; // w8
  __int64 v25; // x21
  _QWORD v26[2]; // [xsp+0h] [xbp-20h] BYREF
  int v27; // [xsp+10h] [xbp-10h]
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD **)(a1 + 152);
  v2 = v1[638];
  if ( v2 )
  {
    if ( *((_DWORD *)v1 + 1278) )
    {
      v3 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "geni_i2c_runtime_resume", v3, v3 / 0x3E8);
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
  v4 = v1[637];
  if ( v4 )
  {
    if ( (v1[1138] & 1) != 0 )
      goto LABEL_8;
  }
  else
  {
    v27 = 0;
    v26[0] = 0;
    v26[1] = 0;
    v8 = *(const char **)(*v1 + 112LL);
    if ( !v8 )
      v8 = *(const char **)*v1;
    snprintf((char *)v26, 0x14u, "%s", v8);
    v4 = ipc_log_context_create(2, v26, 0);
    v1[637] = v4;
    if ( (v1[1138] & 1) != 0 )
    {
LABEL_8:
      if ( *((_BYTE *)v1 + 9108) == 1 )
      {
        v5 = geni_i2c_prepare(v1);
        if ( v5 )
        {
          v7 = v5;
          dev_err(*v1, "I2C prepare failed:%d\n", v5);
          goto LABEL_46;
        }
        if ( *((_DWORD *)v1 + 2270) == 2 )
        {
          v6 = geni_i2c_gpi_pause_resume((__int64)v1, 0);
          if ( v6 )
          {
            v7 = v6;
            v4 = v1[637];
            goto LABEL_44;
          }
        }
        v7 = geni_i2c_lock_bus(v1);
        v4 = v1[637];
        if ( v7 )
        {
          ipc_log_string(v4, "%s failed: %d\n", "geni_i2c_runtime_resume", v7);
          if ( *v1 )
            dev_err(*v1, "%s failed: %d\n", "geni_i2c_runtime_resume", v7);
          else
            printk(&unk_F693, "geni_i2c_runtime_resume", v7);
          if ( *v1 )
            goto LABEL_45;
          goto LABEL_46;
        }
      }
LABEL_21:
      ipc_log_string(v4, "%s ret=%d\n", "geni_i2c_runtime_resume", 0);
      v11 = *v1;
      if ( *v1 )
        i2c_trace_log();
      v12 = v1[638];
      if ( v12 )
      {
        v7 = 0;
        if ( !v3 || !*((_DWORD *)v1 + 1278) )
          goto LABEL_46;
        v13 = sched_clock(v11);
        ipc_log_string(v12, "%s:took %llu nsec(%llu usec)\n", "geni_i2c_runtime_resume", v13 - v3, (v13 - v3) / 0x3E8);
      }
      v7 = 0;
      goto LABEL_46;
    }
  }
  if ( (*((_BYTE *)v1 + 9114) & 1) == 0 )
  {
    v9 = geni_icc_enable(v1 + 620);
    v10 = v1[637];
    if ( v9 )
    {
      v7 = v9;
      ipc_log_string(v1[637], "%s failing at geni icc enable ret=%d\n", "geni_i2c_runtime_resume", v9);
      if ( *v1 )
        goto LABEL_45;
      goto LABEL_46;
    }
    v14 = *((_DWORD *)v1 + 1254);
    v15 = icc_set_bw(v1[626], v14 / 0x64, v14);
    if ( v15 )
    {
      v7 = v15;
      v25 = 0;
    }
    else
    {
      ipc_log_string(v10, "ICC BW voting on path: %s, avg_bw: %u, peak_bw: %u\n", "qup-core", v14 / 0x64, v14);
      v16 = *((_DWORD *)v1 + 1258);
      v17 = icc_set_bw(v1[628], v16, v16);
      if ( v17 )
      {
        v7 = v17;
        v25 = 1;
      }
      else
      {
        ipc_log_string(v10, "ICC BW voting on path: %s, avg_bw: %u, peak_bw: %u\n", "qup-config", v16, v16);
        v18 = *((_DWORD *)v1 + 1262);
        v19 = icc_set_bw(v1[630], v18, v18);
        if ( !v19 )
        {
          ipc_log_string(v10, "ICC BW voting on path: %s, avg_bw: %u, peak_bw: %u\n", "qup-memory", v18, v18);
          goto LABEL_32;
        }
        v7 = v19;
        v25 = 2;
      }
    }
    if ( (unsigned int)__ratelimit(&geni_common_icc_set_bw__rs, "geni_common_icc_set_bw") )
      dev_err(v1[621], "ICC BW voting failed on path '%s': %d\n", icc_path_names[v25], v7);
    ipc_log_string(v1[637], "%s failing at icc set bw ret=%d\n", "geni_i2c_runtime_resume", v7);
    if ( *v1 )
      dev_err(*v1, "%s failing at icc set bw ret=%d\n", "geni_i2c_runtime_resume", v7);
    else
      printk(&unk_F1F1, "geni_i2c_runtime_resume", v7);
    if ( *v1 )
      goto LABEL_45;
    goto LABEL_46;
  }
LABEL_32:
  if ( *((_BYTE *)v1 + 9110) == 1 )
  {
    v20 = v1[634];
    v7 = clk_prepare(v20);
    if ( v7 )
      goto LABEL_36;
    v21 = clk_enable(v20);
    if ( v21 )
    {
      v7 = v21;
      clk_unprepare(v20);
LABEL_36:
      ipc_log_string(v1[637], "%s failing at core clk prepare enable ret=%d\n", "geni_i2c_runtime_resume", v7);
      if ( *v1 )
        goto LABEL_45;
      goto LABEL_46;
    }
  }
  v7 = geni_se_resources_on(v1 + 620);
  if ( v7 )
    goto LABEL_46;
  v22 = geni_i2c_prepare(v1);
  if ( v22 )
  {
    v7 = v22;
    dev_err(*v1, "I2C prepare failed: %d\n", v22);
    goto LABEL_46;
  }
  writel_relaxed(0x7Fu, (unsigned int *)(v1[1] + 36LL));
  _const_udelay(42950);
  v23 = *((_DWORD *)v1 + 2270);
  if ( v23 == 1 )
  {
    enable_irq(*((unsigned int *)v1 + 5));
    v23 = *((_DWORD *)v1 + 2270);
  }
  if ( v23 != 2 )
  {
    v4 = v1[637];
    goto LABEL_21;
  }
  v7 = geni_i2c_gpi_pause_resume((__int64)v1, 0);
  v4 = v1[637];
  if ( !v7 )
    goto LABEL_21;
LABEL_44:
  ipc_log_string(v4, "%s: ret:%d\n", "geni_i2c_runtime_resume", v7);
  if ( *v1 )
LABEL_45:
    i2c_trace_log();
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return v7;
}
