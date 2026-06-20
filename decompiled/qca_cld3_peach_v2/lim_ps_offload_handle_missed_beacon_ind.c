__int64 __fastcall lim_ps_offload_handle_missed_beacon_ind(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 session_by_vdev_id; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _QWORD v30[7]; // [xsp+8h] [xbp-38h] BYREF

  v30[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 8);
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(v2 + 4));
  if ( session_by_vdev_id )
  {
    *(_BYTE *)(session_by_vdev_id + 7279) = 1;
    v12 = session_by_vdev_id;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Received Heart Beat Failure",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "lim_ps_offload_handle_missed_beacon_ind");
    memset(&v30[2], 0, 32);
    v30[1] = v12;
    v30[0] = 5079;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Heartbeat failure from Fw",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_send_heart_beat_timeout_ind");
    result = scheduler_post_message_debug(
               0x35u,
               0x35u,
               53,
               (unsigned __int16 *)v30,
               0x4DAu,
               (__int64)"lim_post_msg_api");
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: posting message: %X to LIM failed, reason: %d",
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 "lim_send_heart_beat_timeout_ind",
                 LOWORD(v30[0]),
                 (unsigned int)result);
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: session does not exist for vdev_id %d",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "lim_ps_offload_handle_missed_beacon_ind",
               *(unsigned __int8 *)(v2 + 4));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
