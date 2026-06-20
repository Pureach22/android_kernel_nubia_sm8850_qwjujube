__int64 __fastcall wlan_twt_responder_disable(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 comp_private_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x4
  __int64 v16; // x6
  __int64 v17; // x7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Cu);
  if ( comp_private_obj )
  {
    *(_QWORD *)(comp_private_obj + 72) = a3;
    *(_DWORD *)(comp_private_obj + 64) = 1;
    v15 = *a2;
    v16 = *((unsigned __int8 *)a2 + 4);
    v17 = a2[4];
    a2[2] = 1;
    qdf_trace_msg(
      0x96u,
      8u,
      "%s: TWT res disable: mac_id:%d role:%d ext:%d reason_code:%d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_twt_responder_disable",
      v15,
      1,
      v16,
      v17);
    return tgt_twt_disable_req_send(a1, a2);
  }
  else
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: null twt psoc priv obj",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_twt_responder_disable");
    return 16;
  }
}
