__int64 __fastcall target_if_ftm_detach(
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
  _QWORD *v10; // x0
  const char *v12; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 2800);
    if ( v9 )
    {
      v10 = *(_QWORD **)(v9 + 16);
      if ( v10 )
        return 16
             * (unsigned int)((unsigned int)wmi_unified_unregister_event_handler(
                                              v10,
                                              0x39u,
                                              a2,
                                              a3,
                                              a4,
                                              a5,
                                              a6,
                                              a7,
                                              a8,
                                              a9) != 0);
    }
    v12 = "%s: null handle";
  }
  else
  {
    v12 = "%s: null psoc";
  }
  qdf_trace_msg(0x49u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_ftm_detach");
  return 16;
}
