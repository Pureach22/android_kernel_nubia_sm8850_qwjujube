__int64 __fastcall hif_wake_interrupt_handler(int a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x0

  qdf_trace_msg(61, 1, "%s: wake interrupt received on irq %d", "hif_wake_interrupt_handler", a1);
  v3 = hif_rtpm_set_monitor_wake_intr(0);
  v4 = hif_rtpm_request_resume(v3);
  v5 = *(__int64 (__fastcall **)(_QWORD))(a2 + 2584);
  if ( v5 )
  {
    v6 = *(_QWORD *)(a2 + 2592);
    if ( *((_DWORD *)v5 - 1) != 251140989 )
      __break(0x8228u);
    v4 = v5(v6);
  }
  qdf_pm_system_wakeup(v4);
  return 1;
}
