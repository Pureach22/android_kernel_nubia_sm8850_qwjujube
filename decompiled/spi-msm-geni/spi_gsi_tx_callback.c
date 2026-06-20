void __fastcall spi_gsi_tx_callback(_DWORD *a1)
{
  _QWORD *v1; // x8
  __int64 v2; // x21
  __int64 v3; // x19
  int v4; // w20
  __int64 v5; // x0
  __int64 v7; // x0

  if ( !a1 || (v1 = *((_QWORD **)a1 + 4)) == nullptr )
  {
    printk(&unk_F8B3);
    return;
  }
  v2 = v1[1];
  v3 = *(_QWORD *)(*v1 + 152LL);
  if ( !v2 )
  {
    ipc_log_string(*(_QWORD *)(v3 + 472), "GSI Tx Callback: Lock/unlock IEOB received\n");
    if ( *(_QWORD *)(v3 + 200) )
      spi_trace_log();
    goto LABEL_15;
  }
  if ( !*(_QWORD *)v2 )
    return;
  if ( a1[2] == 16 )
  {
    ipc_log_string(*(_QWORD *)(v3 + 472), "GSI Tx Callback: Unexpected GSI CB error\n");
    v5 = *(_QWORD *)(v3 + 200);
    if ( v5 )
      dev_err(v5, "GSI Tx Callback: Unexpected GSI CB error\n");
    else
      printk(&unk_F673);
    if ( *(_QWORD *)(v3 + 200) )
      goto LABEL_24;
  }
  else
  {
    if ( *(_BYTE *)(v3 + 536) != 1 || (v4 = *(_DWORD *)(v3 + 540)) == 0 )
      v4 = *(_DWORD *)(v2 + 16);
    if ( *a1 == v4 )
    {
      ipc_log_string(*(_QWORD *)(v3 + 472), "GSI Tx Callback for %d bytes\n", v4);
      if ( *(_QWORD *)(v3 + 200) )
        spi_trace_log();
      spi_dump_ipc(v3, "GSI Tx", *(_QWORD *)v2, *(unsigned int *)(v2 + 16));
LABEL_15:
      complete(v3 + 384);
      return;
    }
    ipc_log_string(*(_QWORD *)(v3 + 472), "GSI Tx Callback: Length mismatch. Expected %d Callback %d\n", v4, *a1);
    v7 = *(_QWORD *)(v3 + 200);
    if ( v7 )
      dev_err(v7, "GSI Tx Callback: Length mismatch. Expected %d Callback %d\n", v4, *a1);
    else
      printk(&unk_DDED);
    if ( *(_QWORD *)(v3 + 200) )
LABEL_24:
      spi_trace_log();
  }
}
