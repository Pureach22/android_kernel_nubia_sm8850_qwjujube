__int64 __fastcall wma_de_register_mgmt_frm_client(
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
  _QWORD **v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  context = _cds_get_context(54, (__int64)"wma_de_register_mgmt_frm_client", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    return 29;
  v9 = (_QWORD **)context;
  if ( (unsigned int)cds_get_conparam() == 5 )
    return 0;
  result = wmi_unified_unregister_event_handler(*v9, 0xEu, v10, v11, v12, v13, v14, v15, v16, v17);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to Unregister rx mgmt handler with wmi",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wma_de_register_mgmt_frm_client");
    return 16;
  }
  return result;
}
