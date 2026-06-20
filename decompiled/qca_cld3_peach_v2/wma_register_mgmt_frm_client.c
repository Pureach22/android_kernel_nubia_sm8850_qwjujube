__int64 __fastcall wma_register_mgmt_frm_client(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _QWORD **v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  __int64 result; // x0

  context = _cds_get_context(54, (__int64)"wma_register_mgmt_frm_client", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    return 29;
  v17 = (_QWORD **)context;
  if ( (unsigned int)wmi_unified_register_event_handler(
                       (_QWORD *)*context,
                       0xEu,
                       (__int64)wma_mgmt_rx_process,
                       0,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16) )
  {
    v26 = "%s: Failed to register rx mgmt handler with wmi";
  }
  else
  {
    result = wmi_unified_register_event_handler(
               *v17,
               0xF5u,
               (__int64)wma_mlo_link_info_sync_rx_process,
               0,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25);
    if ( !(_DWORD)result )
      return result;
    v26 = "%s: Failed to register rx mgmt mlo handler with wmi";
  }
  qdf_trace_msg(0x36u, 2u, v26, v18, v19, v20, v21, v22, v23, v24, v25, "wma_register_mgmt_frm_client");
  return 16;
}
