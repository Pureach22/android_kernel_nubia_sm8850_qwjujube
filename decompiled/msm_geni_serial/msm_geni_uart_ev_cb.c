void __fastcall msm_geni_uart_ev_cb(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x20

  v5 = *(_QWORD *)(a2 + 8);
  ipc_log_string(*(_QWORD *)(a3 + 960), "%s: Start\n", "msm_geni_uart_ev_cb");
  _ftrace_dbg(*(_QWORD *)(a3 + 344), "%s: Start\n");
  if ( *(_DWORD *)a2 )
  {
    ipc_log_string(
      *(_QWORD *)(a3 + 960),
      "GSI QN err:0x%x, status:0x%x, err:%d\n",
      *(_DWORD *)(a2 + 40),
      v5,
      *(_DWORD *)a2);
    _ftrace_dbg(*(_QWORD *)(a3 + 344), "GSI QN err:0x%x, status:0x%x, err:%d\n");
  }
  else if ( (v5 & 4) != 0 )
  {
    __break(0x800u);
  }
  ipc_log_string(*(_QWORD *)(a3 + 960), "%s: End\n", "msm_geni_uart_ev_cb");
  _ftrace_dbg(*(_QWORD *)(a3 + 344), "%s: End\n");
}
