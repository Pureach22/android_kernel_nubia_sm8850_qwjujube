__int64 __fastcall wma_register_mws_coex_events(
        _QWORD **a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7

  result = _wma_validate_handle((__int64)a1, (__int64)"wma_register_mws_coex_events", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !(_DWORD)result )
  {
    wmi_unified_register_event_handler(
      *a1,
      0xD3u,
      (__int64)wma_mws_coex_state_host_event_handler,
      2u,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18);
    wmi_unified_register_event_handler(
      *a1,
      0xD4u,
      (__int64)wma_mws_coex_state_dpwb_event_handler,
      2u,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26);
    wmi_unified_register_event_handler(
      *a1,
      0xD5u,
      (__int64)wma_mws_coex_tdm_event_handler,
      2u,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34);
    wmi_unified_register_event_handler(
      *a1,
      0xD6u,
      (__int64)wma_mws_coex_idrx_event_handler,
      2u,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42);
    return wmi_unified_register_event_handler(
             *a1,
             0xD7u,
             (__int64)wma_mws_coex_antenna_sharing_event_handler,
             2u,
             v43,
             v44,
             v45,
             v46,
             v47,
             v48,
             v49,
             v50);
  }
  return result;
}
