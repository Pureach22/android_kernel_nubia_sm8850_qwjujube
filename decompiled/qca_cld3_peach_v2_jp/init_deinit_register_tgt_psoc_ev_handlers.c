__int64 __fastcall init_deinit_register_tgt_psoc_ev_handlers(
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
  __int64 v9; // x8
  __int64 v10; // x19
  const char *v12; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 2800);
    if ( v9 )
    {
      v10 = *(_QWORD *)(v9 + 16);
      wmi_unified_register_event_handler(v10, 0, init_deinit_service_ready_event_handler, 0);
      wmi_unified_register_event_handler(v10, 62, &init_deinit_service_ext_ready_event_handler, 0);
      wmi_unified_register_event_handler(v10, 154, init_deinit_service_available_handler, 1);
      wmi_unified_register_event_handler(v10, 1, init_deinit_ready_event_handler, 0);
      wmi_unified_register_event_handler(v10, 220, init_deinit_service_ext2_ready_event_handler, 0);
      return 0;
    }
    v12 = "%s: target_psoc_info null in register wmi hadler";
  }
  else
  {
    v12 = "%s: psoc is null in register wmi handler";
  }
  qdf_trace_msg(0x49u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "init_deinit_register_tgt_psoc_ev_handlers");
  return 16;
}
