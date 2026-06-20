void __fastcall msm_geni_uart_gsi_cancel_rx(__int64 a1)
{
  __int64 v2; // x0
  void (*v3)(void); // x8
  const char *v4; // x20

  ipc_log_string(*(_QWORD *)(a1 - 224), "%s: Start\n", "msm_geni_uart_gsi_cancel_rx");
  _ftrace_dbg(*(_QWORD *)(a1 - 840), "%s: Start\n");
  if ( *(_BYTE *)(a1 + 153) == 1 )
  {
    v2 = *(_QWORD *)(*(_QWORD *)(a1 - 40) + 8LL);
    if ( v2 )
    {
      v3 = *(void (**)(void))(*(_QWORD *)v2 + 336LL);
      if ( v3 )
      {
        if ( *((_DWORD *)v3 - 1) != -403578064 )
          __break(0x8228u);
        v3();
      }
    }
    complete(a1 + 80);
    v4 = "%s: End\n";
    *(_BYTE *)(a1 + 153) = 0;
    *(_DWORD *)(a1 + 148) = 0;
    ipc_log_string(*(_QWORD *)(a1 - 224), "%s: End\n", "msm_geni_uart_gsi_cancel_rx");
  }
  else
  {
    v4 = "%s: gsi_rx not yet done\n";
    ipc_log_string(*(_QWORD *)(a1 - 224), "%s: gsi_rx not yet done\n", "msm_geni_uart_gsi_cancel_rx");
  }
  _ftrace_dbg(*(_QWORD *)(a1 - 840), v4);
}
