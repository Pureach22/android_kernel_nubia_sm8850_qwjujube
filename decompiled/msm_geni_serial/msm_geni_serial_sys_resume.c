__int64 __fastcall msm_geni_serial_sys_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x22
  unsigned __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x21
  __int64 v8; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v1 + 968);
  if ( v3 )
  {
    if ( *(_DWORD *)(v1 + 916) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_sys_resume", v4, v4 / 0x3E8);
    }
    else
    {
      v4 = 0;
    }
  }
  else
  {
    v4 = -22;
  }
  ipc_log_string(*(_QWORD *)(v1 + 952), "%s: Start %d\n", "msm_geni_serial_sys_resume", 1);
  _ftrace_dbg(a1, "%s: Start %d\n");
  if ( (*(_BYTE *)(v1 + 1036) & 1) == 0 )
  {
    v6 = *(_QWORD *)(v1 + 264);
    if ( v6 && *(_DWORD *)(v1 + 316) == *(__int16 *)(v6 + 74) && console_suspend_enabled == 1 && *(_BYTE *)(v1 + 372)
      || *(_BYTE *)(v1 + 1336) == 1 )
    {
      ipc_log_string(*(_QWORD *)(v1 + 984), "%s start %d\n", "msm_geni_serial_sys_resume", 1);
      uart_resume_port(*(_QWORD *)(v1 + 520), v1);
      v5 = ipc_log_string(*(_QWORD *)(v1 + 984), "%s end %d", "msm_geni_serial_sys_resume", 1);
    }
    v7 = *(_QWORD *)(v1 + 968);
    if ( v7 && v4 && *(_DWORD *)(v1 + 916) )
    {
      v8 = sched_clock(v5);
      ipc_log_string(v7, "%s:took %llu nsec(%llu usec)\n", "msm_geni_serial_sys_resume", v8 - v4, (v8 - v4) / 0x3E8);
    }
  }
  return 0;
}
