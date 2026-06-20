__int64 __fastcall osif_send_sta_twt_teardown_req(__int64 a1, __int64 a2)
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
  unsigned int v14; // w0
  unsigned int v15; // w20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w0
  unsigned int v25; // w22
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x20
  unsigned int v37; // w8

  v4 = osif_request_alloc(osif_send_sta_twt_teardown_req_params);
  if ( v4 )
  {
    v13 = v4;
    osif_request_cookie(v4);
    v14 = ucfg_twt_teardown_req();
    if ( v14 )
    {
      v15 = qdf_status_to_os_return(v14);
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Failed to send del dialog command",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "osif_send_sta_twt_teardown_req");
    }
    else
    {
      v24 = osif_twt_ack_wait_response(a1, v13, 1);
      if ( v24 )
      {
        v25 = v24;
        ucfg_twt_reset_active_command(a1, a2 + 4, *(unsigned int *)(a2 + 12));
        v15 = qdf_status_to_os_return(v25);
      }
      else
      {
        v27 = osif_request_priv(v13);
        if ( *(_DWORD *)(v27 + 20) )
        {
          v36 = v27;
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: Received TWT ack error:%d. Reset twt command",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "osif_send_sta_twt_teardown_req");
          v37 = *(_DWORD *)(v36 + 20) - 1;
          if ( v37 > 0xA )
            v15 = -11;
          else
            v15 = dword_A2E488[v37];
        }
        else
        {
          v15 = 0;
        }
      }
    }
    osif_request_put(v13);
  }
  else
  {
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
      "osif_send_sta_twt_teardown_req");
    return (unsigned int)-12;
  }
  return v15;
}
