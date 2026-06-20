__int64 __fastcall hs_uart_version_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23

  v3 = *(_QWORD *)(a1 + 152);
  ipc_log_string(*(_QWORD *)(v3 + 960), "%s: Version: %s\n", "hs_uart_version_show", "1.1");
  _ftrace_dbg(*(_QWORD *)(v3 + 344), "%s: Version: %s\n");
  return (int)scnprintf(a3, 4096, "%s\n", "1.1");
}
