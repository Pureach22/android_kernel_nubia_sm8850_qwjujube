__int64 __fastcall osif_send_twt_setup_req(__int64 a1, __int64 a2, __int64 a3)
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
  __int64 v16; // x0
  unsigned int v17; // w0
  unsigned int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w0
  unsigned int v28; // w23
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x23
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w8

  v6 = osif_request_alloc(osif_send_twt_setup_req_params);
  if ( v6 )
  {
    v15 = v6;
    v16 = osif_request_cookie(v6);
    v17 = ucfg_twt_setup_req(a2, (unsigned __int8 *)a3, v16);
    if ( v17 )
    {
      v18 = qdf_status_to_os_return(v17);
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Failed to send add dialog command",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "osif_send_twt_setup_req");
    }
    else
    {
      if ( (*(_BYTE *)(a3 + 52) & 1) == 0 || (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 1 )
      {
        v27 = osif_twt_ack_wait_response(a2, v15, 0);
        if ( v27 )
        {
          v28 = v27;
          ucfg_twt_init_context(a2, (unsigned __int8 *)(a3 + 4), *(_DWORD *)(a3 + 12));
          v18 = qdf_status_to_os_return(v28);
          goto LABEL_10;
        }
        v30 = osif_request_priv(v15);
        if ( *(_DWORD *)(v30 + 20) )
        {
          v39 = v30;
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: Received TWT ack error: %d. Reset twt command",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "osif_send_twt_setup_req");
          if ( (ucfg_twt_is_setup_done() & 1) != 0 )
          {
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: setup_done set, renego failure",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "osif_send_twt_setup_req");
            osif_send_twt_delete_cmd(a1, (int *)(a3 + 4), *(_DWORD *)(a3 + 12), 0);
          }
          else
          {
            ucfg_twt_init_context(a2, (unsigned __int8 *)(a3 + 4), *(_DWORD *)(a3 + 12));
          }
          v48 = *(_DWORD *)(v39 + 20) - 1;
          if ( v48 > 0xF )
            v18 = -22;
          else
            v18 = dword_A2E4CC[v48];
          goto LABEL_10;
        }
      }
      v18 = 0;
    }
LABEL_10:
    osif_request_put(v15);
    return v18;
  }
  qdf_trace_msg(
    0x48u,
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
    "osif_send_twt_setup_req");
  return (unsigned int)-12;
}
