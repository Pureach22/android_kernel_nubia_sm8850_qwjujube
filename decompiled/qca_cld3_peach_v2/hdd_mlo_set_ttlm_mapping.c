__int64 __fastcall hdd_mlo_set_ttlm_mapping(__int64 a1, __int64 a2)
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w22
  __int64 result; // x0
  __int64 v25; // x20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _QWORD v34[4]; // [xsp+0h] [xbp-20h] BYREF

  v34[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34[2] = 0;
  v4 = osif_request_alloc(hdd_mlo_set_ttlm_mapping_params);
  if ( v4 )
  {
    v13 = v4;
    v34[0] = osif_request_cookie(v4);
    v34[1] = ttlm_send_cmd_resp_cb;
    v14 = mlo_ttlm_send_cmd_register_resp_cb(a1, v34);
    if ( v14 )
    {
      v23 = v14;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to register resp callback: %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "hdd_mlo_set_ttlm_mapping",
        v14);
    }
    else
    {
      v23 = wlan_mlo_set_ttlm_mapping(a1, a2);
      if ( !v23 )
      {
        v25 = osif_request_priv(v13);
        if ( (unsigned int)osif_request_wait_for_response(v13) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: TTLM TX wait response timed out",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "hdd_ttlm_tx_wait_response");
          ttlm_sm_deliver_event(*(_QWORD *)v25, 10, 0, 0);
          v23 = 16;
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: TTLM mapping info: dialog_token %d status %d",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "hdd_ttlm_tx_wait_response",
            *(unsigned __int8 *)(v25 + 8),
            *(unsigned int *)(v25 + 12));
          v23 = *(_DWORD *)(osif_request_priv(v13) + 12);
        }
      }
    }
    osif_request_put(v13);
    result = qdf_status_to_os_return(v23);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
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
      "hdd_mlo_set_ttlm_mapping");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
