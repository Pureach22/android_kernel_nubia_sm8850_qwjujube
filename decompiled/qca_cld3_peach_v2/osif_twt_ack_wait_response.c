__int64 __fastcall osif_twt_ack_wait_response(__int64 a1, __int64 a2, unsigned int a3)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int *v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  int v23; // w8
  int v24; // w9
  int v25; // w10
  int v26; // w11
  _BYTE v27[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  ucfg_twt_get_twt_ack_supported(a1, v27);
  if ( (v27[0] & 1) == 0 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: TWT ack is not supported. No need to wait",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "osif_twt_ack_wait_response");
LABEL_9:
    result = 0;
    goto LABEL_10;
  }
  v13 = (unsigned int *)osif_request_priv(a2);
  v13[4] = a3;
  if ( !(unsigned int)osif_request_wait_for_response(a2) )
  {
    if ( v13 == (unsigned int *)-4LL )
    {
      v25 = 0;
      v23 = 0;
      v24 = 0;
      v26 = 0;
    }
    else
    {
      v23 = *((unsigned __int8 *)v13 + 4);
      v24 = *((unsigned __int8 *)v13 + 5);
      v25 = *((unsigned __int8 *)v13 + 6);
      v26 = *((unsigned __int8 *)v13 + 9);
    }
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: TWT ack info: vdev_id %d dialog_id %d twt_cmd %d status %d peer_macaddr %02x:%02x:%02x:**:**:%02x",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "osif_twt_ack_wait_response",
      *v13,
      v13[3],
      v13[4],
      v13[5],
      v23,
      v24,
      v25,
      v26);
    goto LABEL_9;
  }
  qdf_trace_msg(
    0x48u,
    2u,
    "%s: TWT ack response timed out",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "osif_twt_ack_wait_response");
  result = 15;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
