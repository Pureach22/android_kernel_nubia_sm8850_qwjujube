__int64 __fastcall msm_geni_serial_sys_suspend(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x22
  unsigned __int64 v4; // x20
  __int64 v5; // x8
  __int64 v6; // x21
  __int64 v7; // x24
  __int64 result; // x0
  __int64 v9; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v1 + 968);
  if ( v3 )
  {
    if ( *(_DWORD *)(v1 + 916) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_sys_suspend", v4, v4 / 0x3E8);
      if ( (*(_BYTE *)(v1 + 1036) & 1) != 0 )
        return 0;
    }
    else
    {
      v4 = 0;
      if ( (*(_BYTE *)(v1 + 1036) & 1) != 0 )
        return 0;
    }
  }
  else
  {
    v4 = -22;
    if ( (*(_BYTE *)(v1 + 1036) & 1) != 0 )
      return 0;
  }
  v5 = *(_QWORD *)(v1 + 264);
  if ( v5 && *(_DWORD *)(v1 + 316) == *(__int16 *)(v5 + 74) )
  {
    ipc_log_string(*(_QWORD *)(v1 + 984), "%s start %d\n", "msm_geni_serial_sys_suspend", 1);
    uart_suspend_port(*(_QWORD *)(v1 + 520), v1);
    ipc_log_string(*(_QWORD *)(v1 + 984), "%s end %d\n", "msm_geni_serial_sys_suspend", 1);
    v6 = *(_QWORD *)(v1 + 968);
    if ( !v6 )
      return 0;
  }
  else if ( *(_BYTE *)(v1 + 1336) == 1 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 952), "%s start %d\n", "msm_geni_serial_sys_suspend", 1);
    _ftrace_dbg(a1, "%s start %d\n");
    uart_suspend_port(*(_QWORD *)(v1 + 520), v1);
    ipc_log_string(*(_QWORD *)(v1 + 952), "%s end %d\n", "msm_geni_serial_sys_suspend", 1);
    _ftrace_dbg(a1, "%s end %d\n");
    v6 = *(_QWORD *)(v1 + 968);
    if ( !v6 )
      return 0;
  }
  else
  {
    v7 = *(_QWORD *)(v1 + 208);
    mutex_lock(v7 + 272);
    if ( *(_DWORD *)(a1 + 500) != 2 )
    {
      dev_err(a1, "%s:Active userspace vote; ioctl_cnt %d\n", "msm_geni_serial_sys_suspend", *(_DWORD *)(v1 + 1004));
      ipc_log_string(
        *(_QWORD *)(v1 + 952),
        "%s:Active userspace vote; ioctl_cnt %d\n",
        "msm_geni_serial_sys_suspend",
        *(_DWORD *)(v1 + 1004));
      _ftrace_dbg(a1, "%s:Active userspace vote; ioctl_cnt %d\n");
      mutex_unlock(v7 + 272);
      return 4294967280LL;
    }
    ipc_log_string(*(_QWORD *)(v1 + 952), "%s end %d\n", "msm_geni_serial_sys_suspend", 1);
    _ftrace_dbg(a1, "%s end %d\n");
    mutex_unlock(v7 + 272);
    v6 = *(_QWORD *)(v1 + 968);
    if ( !v6 )
      return 0;
  }
  result = 0;
  if ( v4 && *(_DWORD *)(v1 + 916) )
  {
    v9 = sched_clock(0);
    ipc_log_string(v6, "%s:took %llu nsec(%llu usec)\n", "msm_geni_serial_sys_suspend", v9 - v4, (v9 - v4) / 0x3E8);
    return 0;
  }
  return result;
}
