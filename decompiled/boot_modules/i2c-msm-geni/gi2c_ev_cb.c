__int64 __fastcall gi2c_ev_cb(__int64 a1, int *a2, __int64 a3)
{
  int v4; // w4
  __int64 v5; // x21
  __int16 v7; // w22
  __int64 result; // x0

  if ( !a2 || !a3 )
    return printk(&unk_F4AB, "gi2c_ev_cb", a3);
  v4 = *a2;
  v5 = *((_QWORD *)a2 + 1);
  if ( (*a2 | 2) != 2 )
    goto LABEL_21;
  if ( (v5 & 0x400) == 0 )
    goto LABEL_12;
  v7 = *(_WORD *)(*(_QWORD *)(a3 + 1336) + 2LL);
  if ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a3 + 8) + 2320LL)) )
  {
    if ( (v7 & 1) != 0 )
      goto LABEL_12;
    ipc_log_string(*(_QWORD *)(a3 + 5096), "%s\n", "Data NACK: Device NACK before end of TX transfer");
    if ( *(_QWORD *)a3 )
      goto LABEL_10;
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a3 + 5096), "%s\n", "Address NACK: slv unresponsive, check its power/reset-ln");
    if ( *(_QWORD *)a3 )
LABEL_10:
      i2c_trace_log();
  }
  *(_DWORD *)(a3 + 24) = -107;
LABEL_12:
  if ( (v5 & 0x1000) != 0 )
  {
    ipc_log_string(*(_QWORD *)(a3 + 5096), "%s\n", "Bus proto err, noisy/unepxected start/stop");
    if ( *(_QWORD *)a3 )
      i2c_trace_log();
    geni_i2c_se_dump_dbg_regs(a3 + 4960, *(_QWORD *)(a3 + 8), *(_QWORD *)(a3 + 5096));
    *(_DWORD *)(a3 + 24) = -71;
  }
  if ( (v5 & 0x2000) != 0 )
  {
    ipc_log_string(*(_QWORD *)(a3 + 5096), "%s\n", "Bus arbitration lost, clock line undriveable");
    if ( *(_QWORD *)a3 )
      i2c_trace_log();
    geni_i2c_se_dump_dbg_regs(a3 + 4960, *(_QWORD *)(a3 + 8), *(_QWORD *)(a3 + 5096));
    *(_DWORD *)(a3 + 24) = -16;
  }
  result = complete(a3 + 1272);
  v4 = *a2;
  if ( *a2 )
  {
LABEL_21:
    ipc_log_string(*(_QWORD *)(a3 + 5096), "GSI QN err:0x%x, status:0x%x, err:%d\n", a2[10], v5, v4);
    if ( *(_QWORD *)a3 )
      i2c_trace_log();
    *(_BYTE *)(a3 + 9112) = 1;
    return complete(a3 + 1272);
  }
  return result;
}
