__int64 __fastcall hdd_cm_get_handoff_param(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 v16; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  v6 = osif_request_alloc(hdd_cm_get_handoff_param_params);
  if ( v6 )
  {
    v15 = v6;
    v16 = osif_request_cookie(v6);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: sending vendor handoff param request for :0x%x",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "hdd_cm_get_handoff_param",
      a3);
    v25 = ucfg_cm_roam_send_vendor_handoff_param_req(a1, a2, a3, v16);
    if ( v25 )
    {
      v34 = v25;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Unable to get vendor handoff param",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_cm_get_handoff_param");
    }
    else
    {
      v34 = osif_request_wait_for_response(v15);
      if ( v34 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Target response timed out",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "hdd_cm_get_handoff_param");
        ucfg_cm_roam_reset_vendor_handoff_req(a1, a2);
        v34 = qdf_status_from_os_return(v34);
      }
    }
    osif_request_put(v15);
  }
  else
  {
    v34 = 2;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Request allocation failure",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "hdd_cm_get_handoff_param");
  }
  return v34;
}
