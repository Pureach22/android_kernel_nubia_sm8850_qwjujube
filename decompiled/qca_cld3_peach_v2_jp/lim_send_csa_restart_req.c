__int64 __fastcall lim_send_csa_restart_req(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 session_by_vdev_id; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v2 = a2;
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2);
  if ( session_by_vdev_id )
    return wlan_vdev_mlme_sm_deliver_evt(
             *(_QWORD *)(session_by_vdev_id + 16),
             0x18u,
             0x2A28u,
             session_by_vdev_id,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11);
  else
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: session not found for vdev id %d",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "lim_send_csa_restart_req",
             v2);
}
