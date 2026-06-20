void __fastcall geni_i2c_stop_on_bus(__int64 a1)
{
  int v2; // w0
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x9
  __int64 v6; // x0
  __int64 (*v7)(void); // x8
  int v8; // w0
  void (*v9)(void); // x8
  int v10; // w8
  __int64 v11; // x8
  int v12; // w20
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned int v15; // w20

  v2 = readl_relaxed(*(_QWORD *)(a1 + 8) + 2312LL);
  if ( (*(_BYTE *)(a1 + 9085) & 1) == 0 && (v2 & 3) != 3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 5096), "%s: IOS:0x%x, try I2C_STOP_ON_BUS\n", "geni_i2c_stop_on_bus", v2);
    if ( *(_QWORD *)a1 )
      i2c_trace_log();
    if ( *(_DWORD *)(a1 + 9080) == 2 )
    {
      v3 = *(_QWORD *)(a1 + 5096);
      *(_QWORD *)(a1 + 5200) = 7;
      *(_DWORD *)(a1 + 24) = 0;
      v4 = a1 + 5200;
      *(_DWORD *)(a1 + 1272) = 0;
      *(_QWORD *)(a1 + 5208) = 0x20020000000000LL;
      ipc_log_string(
        v3,
        "%s: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
        "geni_i2c_gsi_stop_on_bus",
        7,
        0,
        0,
        2097664);
      if ( *(_QWORD *)a1 )
        i2c_trace_log();
      sg_init_table(*(_QWORD *)(a1 + 8920), 1);
      v5 = *(_QWORD *)(a1 + 8920);
      *(_QWORD *)v5 = (*(_QWORD *)v5 & 3LL | ((unsigned __int64)((v4 << 8 >> 8) + 0x8000000000LL) >> 12 << 6))
                    - 0x140000000LL;
      *(_DWORD *)(v5 + 8) = v4 & 0xFFF;
      *(_DWORD *)(v5 + 12) = 16;
      v6 = geni_i2c_prep_desc(a1, 1, 1);
      *(_QWORD *)(a1 + 8968) = v6;
      if ( v6 )
      {
        v7 = *(__int64 (**)(void))(v6 + 24);
        if ( *((_DWORD *)v7 - 1) != 1188179853 )
          __break(0x8228u);
        v8 = v7();
        if ( (v8 & 0x80000000) == 0 )
        {
          v9 = *(void (**)(void))(**(_QWORD **)(a1 + 5120) + 360LL);
          if ( *((_DWORD *)v9 - 1) != 905352215 )
            __break(0x8228u);
          v9();
          if ( !(unsigned int)wait_for_completion_timeout(a1 + 1272, 250) )
          {
            ipc_log_string(*(_QWORD *)(a1 + 5096), "%s:wait_for_completion timed out\n", "geni_i2c_gsi_stop_on_bus");
            if ( *(_QWORD *)a1 )
              i2c_trace_log();
            ipc_log_string(*(_QWORD *)(a1 + 5096), "%s\n", "I2C TXN timed out");
            if ( *(_QWORD *)a1 )
              i2c_trace_log();
            geni_i2c_se_dump_dbg_regs(a1 + 4960, *(_QWORD *)(a1 + 8), *(_QWORD *)(a1 + 5096));
            v10 = -110;
            goto LABEL_35;
          }
          goto LABEL_25;
        }
        v15 = v8;
        ipc_log_string(*(_QWORD *)(a1 + 5096), "%s: dmaengine_submit failed (%d)\n", "geni_i2c_gsi_stop_on_bus", v8);
        if ( *(_QWORD *)a1 )
          dev_err(*(_QWORD *)a1, "%s: dmaengine_submit failed (%d)\n", "geni_i2c_gsi_stop_on_bus", v15);
        else
          printk(&unk_F551, "geni_i2c_gsi_stop_on_bus", v15);
        if ( *(_QWORD *)a1 )
          i2c_trace_log();
        v10 = -22;
      }
      else
      {
        ipc_log_string(*(_QWORD *)(a1 + 5096), "%s: geni_i2c_prep_desc failed\n", "geni_i2c_gsi_stop_on_bus");
        if ( *(_QWORD *)a1 )
          i2c_trace_log();
        v10 = -12;
      }
LABEL_35:
      v14 = *(_QWORD *)(a1 + 5096);
      *(_DWORD *)(a1 + 24) = v10;
      ipc_log_string(v14, "%s: I2C Bus stop failed\n", "geni_i2c_stop_on_bus");
      if ( !*(_QWORD *)a1 )
        return;
LABEL_41:
      i2c_trace_log();
      return;
    }
    v11 = *(_QWORD *)(a1 + 4960);
    *(_DWORD *)(a1 + 1272) = 0;
    writel(939524096, v11 + 1536);
    if ( !(unsigned int)wait_for_completion_timeout(a1 + 1272, 250) )
    {
      ipc_log_string(*(_QWORD *)(a1 + 5096), "%s\n", "I2C TXN timed out");
      if ( *(_QWORD *)a1 )
        i2c_trace_log();
      geni_i2c_se_dump_dbg_regs(a1 + 4960, *(_QWORD *)(a1 + 8), *(_QWORD *)(a1 + 5096));
      *(_QWORD *)(a1 + 1336) = 0;
      *(_DWORD *)(a1 + 24) = -110;
      if ( (unsigned int)geni_i2c_stop_with_cancel(a1) )
      {
        ipc_log_string(*(_QWORD *)(a1 + 5096), "%s:I2C Bus stop failed\n", "geni_i2c_stop_on_bus");
        if ( !*(_QWORD *)a1 )
          return;
        goto LABEL_41;
      }
    }
    ipc_log_string(*(_QWORD *)(a1 + 5096), "%s: I2C Bus stop success\n", "geni_i2c_stop_on_bus");
    if ( *(_QWORD *)a1 )
      i2c_trace_log();
LABEL_25:
    v12 = readl_relaxed(*(_QWORD *)(a1 + 8) + 2312LL);
    v13 = *(_QWORD *)(a1 + 5096);
    if ( (~v12 & 3) != 0 )
    {
      ipc_log_string(v13, "%s: IOS:0x%x, I2C lines in bad state\n", "geni_i2c_stop_on_bus", v12);
      if ( *(_QWORD *)a1 )
        i2c_trace_log();
      geni_i2c_se_dump_dbg_regs(a1 + 4960, *(_QWORD *)(a1 + 8), *(_QWORD *)(a1 + 5096));
    }
    else
    {
      ipc_log_string(v13, "%s: IOS:0x%x, I2C lines in good state\n", "geni_i2c_stop_on_bus", v12);
      if ( *(_QWORD *)a1 )
        i2c_trace_log();
    }
    return;
  }
  if ( *(_BYTE *)(a1 + 9085) )
    *(_DWORD *)(a1 + 8952) = 0;
}
