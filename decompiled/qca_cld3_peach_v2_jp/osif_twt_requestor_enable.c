__int64 __fastcall osif_twt_requestor_enable(__int64 a1, __int64 a2)
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
  unsigned int v24; // w20
  unsigned int v25; // w20
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  v4 = osif_request_alloc(osif_twt_requestor_enable_params);
  if ( v4 )
  {
    v13 = v4;
    v14 = osif_request_cookie(v4);
    v15 = ucfg_twt_requestor_enable(a1, a2, v14);
    if ( v15 )
    {
      v24 = v15;
      qdf_trace_msg(
        0x48u,
        3u,
        "%s: Failed to send TWT requestor enable command",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "osif_twt_requestor_enable");
      v25 = qdf_status_to_os_return(v24);
    }
    else
    {
      v26 = osif_request_wait_for_response(v13);
      if ( v26 )
      {
        qdf_trace_msg(
          0x48u,
          3u,
          "%s: TWT Requestor Enable timedout ret:%d",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "osif_twt_requestor_enable",
          v26);
        v25 = -110;
      }
      else if ( *(_DWORD *)osif_request_priv(v13) >= 2u )
      {
        v25 = -16;
      }
      else
      {
        v25 = 0;
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
      "osif_twt_requestor_enable");
    return (unsigned int)-12;
  }
  return v25;
}
