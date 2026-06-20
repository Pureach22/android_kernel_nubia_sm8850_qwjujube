__int64 __fastcall msm_geni_serial_sys_hib_resume(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x8
  int v4; // w8

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v1 + 264);
  if ( v3 && *(_DWORD *)(v1 + 316) == *(__int16 *)(v3 + 74) )
  {
    uart_resume_port(*(_QWORD *)(v1 + 520), v1);
    msm_geni_serial_port_setup(v1);
  }
  else
  {
    v4 = *(unsigned __int8 *)(v1 + 1336);
    *(_BYTE *)(v1 + 600) = 0;
    if ( v4 == 1 )
      uart_resume_port(*(_QWORD *)(v1 + 520), v1);
  }
  ipc_log_string(*(_QWORD *)(v1 + 952), "%s: End %d\n", "msm_geni_serial_sys_hib_resume", 1);
  _ftrace_dbg(a1, "%s: End %d\n");
  return 0;
}
