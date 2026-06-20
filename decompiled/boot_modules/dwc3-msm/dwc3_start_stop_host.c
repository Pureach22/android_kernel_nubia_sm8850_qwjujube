__int64 __fastcall dwc3_start_stop_host(__int64 a1, char a2)
{
  __int64 v3; // x0

  v3 = *(_QWORD *)(a1 + 1256);
  if ( (a2 & 1) != 0 )
  {
    ipc_log_string(v3, "%s: start host mode", "dwc3_start_stop_host");
    *(_DWORD *)(a1 + 752) = 0;
    *(_BYTE *)(a1 + 746) = 0;
    dwc3_ext_event_notify(a1);
  }
  else
  {
    ipc_log_string(v3, "%s: stop_host_mode started", "dwc3_start_stop_host");
    *(_BYTE *)(a1 + 746) = 0;
    *(_DWORD *)(a1 + 752) = 1;
    dwc3_ext_event_notify(a1);
    _pm_runtime_resume(*(_QWORD *)(a1 + 40) + 16LL, 5);
    flush_work(a1 + 568);
    _flush_workqueue(*(_QWORD *)(a1 + 648));
    _pm_runtime_idle(*(_QWORD *)(a1 + 40) + 16LL, 5);
    while ( (*(_QWORD *)(a1 + 688) & 8) != 0 )
      msleep(20);
    ipc_log_string(*(_QWORD *)(a1 + 1256), "%s: stop_host_mode completed", "dwc3_start_stop_host");
    if ( !*(_DWORD *)(a1 + 752) )
      return 4294967280LL;
  }
  return 0;
}
