__int64 __fastcall t2lm_handle_rx_req(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, _BYTE *a5)
{
  __int64 v5; // x8
  __int64 v6; // x0
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
  __int64 result; // x0
  __int64 v28; // x20
  __int64 v29; // x0
  _QWORD v30[21]; // [xsp+8h] [xbp-B8h] BYREF
  int v31; // [xsp+B0h] [xbp-10h]
  __int64 v32; // [xsp+B8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  memset(v30, 0, sizeof(v30));
  if ( a1 && (v5 = *(_QWORD *)(a1 + 216)) != 0 && (v6 = *(_QWORD *)(v5 + 80)) != 0 )
  {
    if ( (unsigned int)wlan_mlme_get_t2lm_negotiation_supported(v6) )
    {
      if ( (unsigned int)wlan_mlo_parse_t2lm_action_frame(
                           (__int64)v30,
                           a3,
                           a4,
                           1u,
                           v11,
                           v12,
                           v13,
                           v14,
                           v15,
                           v16,
                           v17,
                           v18) )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: Unable to parse T2LM request action frame",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "t2lm_handle_rx_req");
        result = 16;
      }
      else
      {
        v29 = *(_QWORD *)(a2 + 784);
        if ( v29 )
          result = ttlm_sm_deliver_event(v29, 4u, 0xACu, (__int64)v30);
        else
          result = 16;
        *a5 = BYTE4(v30[0]);
      }
    }
    else
    {
      v28 = jiffies;
      if ( t2lm_handle_rx_req___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: T2LM negotiation not supported",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "t2lm_handle_rx_req");
        t2lm_handle_rx_req___last_ticks = v28;
      }
      result = 11;
    }
  }
  else
  {
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
