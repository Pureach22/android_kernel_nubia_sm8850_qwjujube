void __fastcall msm_geni_wakeup_work(__int64 a1)
{
  __int64 v2; // x20
  const char *v3; // x1
  __int64 v4; // x0
  __int64 v5; // x0
  _QWORD *v6; // x21
  __int64 v7; // x20

  if ( *(_DWORD *)(a1 - 16) )
  {
    *(_DWORD *)(a1 + 104) = 0;
    v2 = a1 + 104;
    if ( (unsigned int)msm_geni_serial_power_on((_QWORD *)(a1 - 1360)) )
    {
      *(_DWORD *)(a1 - 16) = 0;
      ipc_log_string(*(_QWORD *)(a1 - 416), "%s:Failed to power on\n", "msm_geni_wakeup_work");
      v3 = "%s:Failed to power on\n";
      v4 = *(_QWORD *)(a1 - 1016);
LABEL_4:
      _ftrace_dbg(v4, v3);
      return;
    }
    v5 = wait_for_completion_timeout(v2, 500);
    if ( !v5 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 - 416),
        "%s completion of wakeup_comp task timedout %dmsec\n",
        "msm_geni_wakeup_work",
        2000);
      _ftrace_dbg(*(_QWORD *)(a1 - 1016), "%s completion of wakeup_comp task timedout %dmsec\n");
    }
    v6 = (_QWORD *)(a1 - 1016);
    v7 = *(_QWORD *)(a1 - 1016);
    if ( !*(_DWORD *)(v7 + 480) )
    {
      ipc_log_string(*(_QWORD *)(a1 - 408), "%s: Usage Count is already 0\n", "msm_geni_serial_power_off");
      v4 = *v6;
      v3 = "%s: Usage Count is already 0\n";
      goto LABEL_4;
    }
    if ( (*(_WORD *)(v7 + 488) & 7) == 0 )
    {
      *(_QWORD *)(v7 + 520) = ktime_get_mono_fast_ns(v5);
      _pm_runtime_suspend(*v6, 13);
    }
  }
}
