__int64 __fastcall msm_geni_serial_ioctl(__int64 a1, int a2)
{
  __int64 v4; // x0
  unsigned __int64 StatusReg; // x24
  __int64 result; // x0
  __int64 v7; // x21
  unsigned __int64 v8; // x20
  unsigned int v9; // w20
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x21
  unsigned __int64 v13; // x20
  unsigned int v14; // w0
  int v15; // w4
  __int64 v16; // x8
  __int64 v17; // x21
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x21
  __int64 v21; // x21
  __int64 v22; // x8
  unsigned int v23; // w19

  v4 = *(_QWORD *)(a1 + 960);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(v4, "%s:%s cmd 0x%x\n", "msm_geni_serial_ioctl", (const char *)(StatusReg + 2320), a2);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s:%s cmd 0x%x\n");
  if ( (*(_BYTE *)(a1 + 1336) & 1) != 0 )
    return 4294966781LL;
  result = 4294966781LL;
  if ( a2 > 21741 )
  {
    if ( a2 != 21742 )
    {
      if ( a2 == 21743 )
        return *(_DWORD *)(*(_QWORD *)(a1 + 344) + 500LL) != 2;
      return result;
    }
    v12 = *(_QWORD *)(a1 + 968);
    if ( v12 )
    {
      if ( *(_DWORD *)(a1 + 916) )
      {
        v13 = sched_clock(4294966781LL);
        ipc_log_string(v12, "%s:start at %llu nsec(%llu usec)\n", "vote_clock_off", v13, v13 / 0x3E8);
      }
      else
      {
        v13 = 0;
      }
    }
    else
    {
      v13 = -22;
    }
    ipc_log_string(
      *(_QWORD *)(a1 + 952),
      "Enter %s:%s ioctl_count:%d\n",
      "vote_clock_off",
      (const char *)(StatusReg + 2320),
      *(_DWORD *)(a1 + 1004));
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "Enter %s:%s ioctl_count:%d\n");
    v18 = *(_QWORD *)(a1 + 344);
    if ( (*(_WORD *)(v18 + 488) & 7) != 0 )
    {
      dev_err(v18, "RPM not available.Can't enable clocks\n");
      return 0xFFFFFFFFLL;
    }
    if ( !*(_DWORD *)(a1 + 1004) )
    {
      dev_warn();
      ipc_log_string(
        *(_QWORD *)(a1 + 952),
        "%s Imbalanced vote_off from userspace. %d",
        "vote_clock_off",
        *(_DWORD *)(a1 + 1004));
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s Imbalanced vote_off from userspace. %d");
      return 0xFFFFFFFFLL;
    }
    v19 = wait_for_transfers_inflight(a1);
    if ( (_DWORD)v19 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 952), "%s wait_for_transfer_inflight return ret: %d", "vote_clock_off", v19);
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s wait_for_transfer_inflight return ret: %d");
      return 4294967285LL;
    }
    v20 = *(_QWORD *)(a1 + 344);
    --*(_DWORD *)(a1 + 1004);
    if ( *(_DWORD *)(v20 + 480) )
    {
      if ( (*(_WORD *)(v20 + 488) & 7) == 0 )
      {
        *(_QWORD *)(v20 + 520) = ktime_get_mono_fast_ns(v19);
        _pm_runtime_suspend(*(_QWORD *)(a1 + 344), 13);
      }
    }
    else
    {
      ipc_log_string(*(_QWORD *)(a1 + 952), "%s: Usage Count is already 0\n", "msm_geni_serial_power_off");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Usage Count is already 0\n");
    }
    ipc_log_string(
      *(_QWORD *)(a1 + 952),
      "%s:%s ioctl:%d usage_count:%d\n",
      "vote_clock_off",
      (const char *)(StatusReg + 2320),
      *(_DWORD *)(a1 + 1004),
      *(_DWORD *)(*(_QWORD *)(a1 + 344) + 480LL));
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s:%s ioctl:%d usage_count:%d\n");
    v21 = *(_QWORD *)(a1 + 968);
    if ( v21 )
    {
      result = 0;
      if ( v13 && *(_DWORD *)(a1 + 916) )
      {
        sched_clock(0);
        ipc_log_string(v21, "%s:took %llu nsec(%llu usec)\n", "vote_clock_off");
        return 0;
      }
      return result;
    }
    return 0;
  }
  if ( a2 == 21740 )
  {
    v9 = *(_DWORD *)(a1 + 1120);
    v10 = *(_QWORD *)(a1 + 960);
    *(_DWORD *)(a1 + 1120) = 0;
    ipc_log_string(v10, "%s TIOCFAULT - uart_error_set %d new_uart_error %d", "msm_geni_serial_ioctl", v9, 0);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s TIOCFAULT - uart_error_set %d new_uart_error %d");
    if ( *(_DWORD *)(a1 + 1004) )
      geni_se_dump_dbg_regs((_QWORD *)a1);
    v11 = *(_QWORD *)(a1 + 976);
    *(_QWORD *)(a1 + 944) = v11;
    *(_QWORD *)(a1 + 936) = v11;
    *(_QWORD *)(a1 + 960) = v11;
    *(_QWORD *)(a1 + 952) = v11;
    *(_QWORD *)(a1 + 992) = v11;
    return v9;
  }
  if ( a2 != 21741 )
    return result;
  v7 = *(_QWORD *)(a1 + 968);
  if ( v7 )
  {
    if ( *(_DWORD *)(a1 + 916) )
    {
      v8 = sched_clock(4294966781LL);
      ipc_log_string(v7, "%s:start at %llu nsec(%llu usec)\n", "vote_clock_on", v8, v8 / 0x3E8);
    }
    else
    {
      v8 = 0;
    }
  }
  else
  {
    v8 = -22;
  }
  ipc_log_string(
    *(_QWORD *)(a1 + 952),
    "Enter %s:%s ioctl_count:%d\n",
    "vote_clock_on",
    (const char *)(StatusReg + 2320),
    *(_DWORD *)(a1 + 1004));
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "Enter %s:%s ioctl_count:%d\n");
  if ( *(_DWORD *)(a1 + 1004) )
  {
    ipc_log_string(*(_QWORD *)(a1 + 952), "%s clock already on\n", "vote_clock_on");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s clock already on\n");
    return 0;
  }
  v14 = msm_geni_serial_power_on(a1);
  if ( v14 )
  {
    v22 = *(_QWORD *)(a1 + 344);
    v23 = v14;
    dev_err(v22, "Failed to vote clock on\n");
    return v23;
  }
  *(_DWORD *)(a1 + 1344) = 0;
  complete(a1 + 1464);
  v15 = *(_DWORD *)(a1 + 1004) + 1;
  v16 = *(_QWORD *)(a1 + 344);
  *(_DWORD *)(a1 + 1004) = v15;
  ipc_log_string(
    *(_QWORD *)(a1 + 952),
    "%s :%s ioctl:%d usage_count:%d\n",
    "vote_clock_on",
    (const char *)(StatusReg + 2320),
    v15,
    *(_DWORD *)(v16 + 480));
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s :%s ioctl:%d usage_count:%d\n");
  v17 = *(_QWORD *)(a1 + 968);
  if ( !v17 )
    return 0;
  result = 0;
  if ( v8 && *(_DWORD *)(a1 + 916) )
  {
    sched_clock(0);
    ipc_log_string(v17, "%s:took %llu nsec(%llu usec)\n", "vote_clock_on");
    return 0;
  }
  return result;
}
