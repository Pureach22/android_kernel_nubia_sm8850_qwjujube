__int64 __fastcall gi2c_gsi_rx_cb(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x8

  if ( !result )
    return printk(&unk_104CC, "gi2c_gsi_rx_cb", a3);
  v3 = *(_QWORD *)(result + 32);
  if ( !v3 )
    return printk(&unk_104CC, "gi2c_gsi_rx_cb", a3);
  v4 = *(_QWORD *)(v3 + 1336);
  if ( v4 )
  {
    if ( (*(_WORD *)(v4 + 2) & 1) == 0 )
      return result;
    gi2c_gsi_cb_err();
  }
  else
  {
    ipc_log_string(*(_QWORD *)(v3 + 5096), "%s\n", "Received unexpected interrupt");
    if ( *(_QWORD *)v3 )
      i2c_trace_log();
    geni_i2c_se_dump_dbg_regs(v3 + 4960, *(_QWORD *)(v3 + 8), *(_QWORD *)(v3 + 5096));
    *(_DWORD *)(v3 + 24) = -22;
  }
  return complete(v3 + 1272);
}
