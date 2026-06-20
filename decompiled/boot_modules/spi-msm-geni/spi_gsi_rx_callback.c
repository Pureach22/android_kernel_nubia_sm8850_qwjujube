void __fastcall spi_gsi_rx_callback(int *a1)
{
  _QWORD *v1; // x8
  __int64 v2; // x20
  __int64 v3; // x19
  int v4; // w3
  int v5; // w2
  __int64 v6; // x0
  __int64 v8; // x0

  if ( !a1 || (v1 = *((_QWORD **)a1 + 4)) == nullptr )
  {
    printk(&unk_F020);
    return;
  }
  v2 = v1[1];
  if ( *(_QWORD *)(v2 + 8) )
  {
    v3 = *(_QWORD *)(*v1 + 152LL);
    if ( a1[2] == 16 )
    {
      ipc_log_string(*(_QWORD *)(v3 + 472), "%s: Unexpected GSI CB error\n", "spi_gsi_rx_callback");
      v6 = *(_QWORD *)(v3 + 200);
      if ( v6 )
        dev_err(v6, "%s: Unexpected GSI CB error\n", "spi_gsi_rx_callback");
      else
        printk(&unk_E3DA);
      if ( *(_QWORD *)(v3 + 200) )
        goto LABEL_17;
    }
    else
    {
      v4 = *a1;
      v5 = *(_DWORD *)(v2 + 16);
      if ( *a1 == v5 )
      {
        ipc_log_string(*(_QWORD *)(v3 + 472), "GSI Rx Callback for %d bytes\n", v4);
        if ( *(_QWORD *)(v3 + 200) )
          spi_trace_log();
        spi_dump_ipc(v3, (__int64)"GSI Rx", *(_QWORD *)(v2 + 8), *(_DWORD *)(v2 + 16));
        complete(v3 + 416);
        return;
      }
      ipc_log_string(*(_QWORD *)(v3 + 472), "GSI Rx Callback: Length mismatch. Expected %d Callback %d\n", v5, v4);
      v8 = *(_QWORD *)(v3 + 200);
      if ( v8 )
        dev_err(v8, "GSI Rx Callback: Length mismatch. Expected %d Callback %d\n", *(_DWORD *)(v2 + 16), *a1);
      else
        printk(&unk_EF15);
      if ( *(_QWORD *)(v3 + 200) )
LABEL_17:
        spi_trace_log();
    }
  }
}
