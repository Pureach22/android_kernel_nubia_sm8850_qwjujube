void __fastcall msm_geni_update_uart_error_code(__int64 a1, int a2)
{
  __int64 v2; // x8

  if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
  {
    v2 = *(_QWORD *)(a1 + 960);
    *(_DWORD *)(a1 + 1120) = a2;
    ipc_log_string(v2, "%s uart_error_code %d", "msm_geni_update_uart_error_code", a2);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
  }
}
