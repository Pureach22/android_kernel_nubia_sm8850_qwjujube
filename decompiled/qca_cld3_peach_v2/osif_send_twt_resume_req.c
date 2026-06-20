__int64 __fastcall osif_send_twt_resume_req(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 v14; // x0
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w21
  unsigned int v25; // w0
  unsigned int v26; // w20
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x20
  unsigned int v38; // w8

  v4 = osif_request_alloc(osif_send_twt_resume_req_params);
  if ( v4 )
  {
    v13 = v4;
    v14 = osif_request_cookie(v4);
    v15 = ucfg_twt_resume_req(a1, a2, v14);
    if ( v15 )
    {
      v24 = v15;
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Failed to send resume dialog command",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "osif_send_twt_resume_req");
      v25 = v24;
    }
    else
    {
      v25 = osif_twt_ack_wait_response(a1, v13, 3);
      if ( !v25 )
      {
        v28 = osif_request_priv(v13);
        if ( *(_DWORD *)(v28 + 20) )
        {
          v37 = v28;
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: Received TWT ack error:%d. Reset twt command",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "osif_send_twt_resume_req");
          v38 = *(_DWORD *)(v37 + 20) - 1;
          if ( v38 > 9 )
            v26 = -22;
          else
            v26 = dword_B33DBC[v38];
        }
        else
        {
          v26 = 0;
        }
        goto LABEL_7;
      }
    }
    v26 = qdf_status_to_os_return(v25);
LABEL_7:
    osif_request_put(v13);
    return v26;
  }
  qdf_trace_msg(
    0x48u,
    2u,
    "%s: Request allocation failure",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "osif_send_twt_resume_req");
  return (unsigned int)-12;
}
