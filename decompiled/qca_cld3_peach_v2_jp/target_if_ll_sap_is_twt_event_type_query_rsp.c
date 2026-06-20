bool __fastcall target_if_ll_sap_is_twt_event_type_query_rsp(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  __int64 v12; // x8
  __int64 v13; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 comp_private_obj; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  if ( a1 && (v12 = *(_QWORD *)(a1 + 2800)) != 0 && (v13 = *(_QWORD *)(v12 + 16)) != 0 )
  {
    if ( (unsigned int)wmi_extract_twt_session_stats_data(v13) )
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Unable to extract twt params",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "target_if_ll_sap_is_twt_event_type_query_rsp");
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x34u);
      if ( !comp_private_obj )
      {
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: ll_sap_psoc_obj is null",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "target_if_ll_sap_is_twt_event_type_query_rsp");
        return 0;
      }
      return (unsigned int)qdf_mc_timer_get_current_state(comp_private_obj + 40) == 21;
    }
    else
    {
      return *(_DWORD *)(a12 + 12) == 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: wmi_handle is null!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_ll_sap_is_twt_event_type_query_rsp");
    return 1;
  }
}
