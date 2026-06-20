__int64 __fastcall target_if_register_mcc_quota_event_handler(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  _QWORD *v11; // x0
  unsigned int v12; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2

  if ( a1 && (v10 = *(_QWORD *)(a1 + 2800)) != 0 && (v11 = *(_QWORD **)(v10 + 16)) != nullptr )
  {
    if ( (a2 & 1) != 0 )
    {
      v12 = wmi_unified_register_event_handler(
              v11,
              0x103u,
              (__int64)target_if_mcc_quota_event_handler,
              2u,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10);
      v21 = "%s: wmi register mcc_quota event handle, status:%d";
    }
    else
    {
      v12 = wmi_unified_unregister_event_handler(v11, 0x103u, a3, a4, a5, a6, a7, a8, a9, a10);
      v21 = "%s: wmi unregister mcc_quota event handle, status:%d";
    }
    qdf_trace_msg(
      0x49u,
      8u,
      v21,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_register_mcc_quota_event_handler",
      v12);
    return v12;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid wmi handle",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_register_mcc_quota_event_handler");
    return 4;
  }
}
