void __fastcall gi2c_gsi_cb_err(__int64 a1, const char *a2, __int64 a3)
{
  __int64 v3; // x21
  int v4; // w3
  __int16 v6; // w20
  __int64 v7; // x0
  int v8; // w8

  v3 = *(_QWORD *)(a1 + 32);
  if ( !v3 )
  {
    printk(&unk_103AE, "gi2c_gsi_cb_err", a3);
    return;
  }
  if ( *(_QWORD *)(v3 + 1336) )
  {
    v4 = *(_DWORD *)(a1 + 8);
    if ( (v4 & 0x340) == 0 )
      return;
    ipc_log_string(*(_QWORD *)(v3 + 5096), "%s TCE Unexpected Err, stat:0x%x\n", a2, v4);
    if ( *(_QWORD *)v3 )
      i2c_trace_log();
    if ( (*(_BYTE *)(a1 + 8) & 0x40) == 0 )
      goto LABEL_18;
    v6 = *(_WORD *)(*(_QWORD *)(v3 + 1336) + 2LL);
    if ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(v3 + 8) + 2320LL)) )
    {
      if ( (v6 & 1) != 0 )
      {
LABEL_18:
        v8 = *(_DWORD *)(a1 + 8);
        if ( (v8 & 0x100) != 0 )
        {
          ipc_log_string(*(_QWORD *)(v3 + 5096), "%s\n", "Bus proto err, noisy/unepxected start/stop");
          if ( *(_QWORD *)v3 )
            i2c_trace_log();
          geni_i2c_se_dump_dbg_regs(v3 + 4960, *(_QWORD *)(v3 + 8), *(_QWORD *)(v3 + 5096));
          *(_DWORD *)(v3 + 24) = -71;
          v8 = *(_DWORD *)(a1 + 8);
        }
        if ( (v8 & 0x200) != 0 )
        {
          ipc_log_string(*(_QWORD *)(v3 + 5096), "%s\n", "Bus arbitration lost, clock line undriveable");
          if ( *(_QWORD *)v3 )
            i2c_trace_log();
          geni_i2c_se_dump_dbg_regs(v3 + 4960, *(_QWORD *)(v3 + 8), *(_QWORD *)(v3 + 5096));
          *(_DWORD *)(v3 + 24) = -16;
        }
        return;
      }
      ipc_log_string(*(_QWORD *)(v3 + 5096), "%s\n", "Data NACK: Device NACK before end of TX transfer");
      if ( *(_QWORD *)v3 )
        goto LABEL_16;
    }
    else
    {
      ipc_log_string(*(_QWORD *)(v3 + 5096), "%s\n", "Address NACK: slv unresponsive, check its power/reset-ln");
      if ( *(_QWORD *)v3 )
LABEL_16:
        i2c_trace_log();
    }
    *(_DWORD *)(v3 + 24) = -107;
    goto LABEL_18;
  }
  ipc_log_string(*(_QWORD *)(v3 + 5096), "%s\n", "Received unexpected interrupt");
  if ( *(_QWORD *)v3 )
    i2c_trace_log();
  geni_i2c_se_dump_dbg_regs(v3 + 4960, *(_QWORD *)(v3 + 8), *(_QWORD *)(v3 + 5096));
  v7 = *(_QWORD *)(v3 + 5096);
  *(_DWORD *)(v3 + 24) = -22;
  ipc_log_string(v7, "%s: Invalid gi2c dev\n", "gi2c_gsi_cb_err");
  if ( *(_QWORD *)v3 )
    i2c_trace_log();
}
