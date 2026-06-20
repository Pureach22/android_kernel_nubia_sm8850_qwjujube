void __fastcall gi3c_gsi_rx_cb(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v6; // x20

  if ( a1 && (v4 = *(_QWORD *)(a1 + 32)) != 0 )
  {
    v6 = *(_QWORD *)(v4 + 24);
    ipc_log_string(*(_QWORD *)(v6 + 2528), "%s rnw:%d\n", "gi3c_gsi_rx_cb", *(_DWORD *)(v6 + 21272));
    if ( *(_QWORD *)(v6 + 8) )
      i3c_trace_log();
    if ( (*(_BYTE *)(v6 + 21272) & 1) != 0 )
    {
      gi3c_gsi_cb_err(a1, "RX");
      complete_all(v6 + 2552);
    }
    else
    {
      ipc_log_string(*(_QWORD *)(v6 + 2528), "%s:Unexpected gsi rx cb\n", "gi3c_gsi_rx_cb");
      if ( *(_QWORD *)(v6 + 8) )
        i3c_trace_log();
    }
  }
  else
  {
    printk(&unk_14252, "gi3c_gsi_rx_cb", a3, a4);
  }
}
