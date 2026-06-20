__int64 __fastcall wma_pdev_resume_event_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  qdf_trace_msg(0x36u, 4u, "Received PDEV resume event", a2, a3, a4, a5, a6, a7, a8, a9);
  ucfg_pmo_psoc_wakeup_host_event_received(*(_QWORD *)(a1 + 24));
  return 0;
}
