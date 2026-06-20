__int64 __fastcall lim_sae_auth_cleanup_retry(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 session_by_vdev_id; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v2 = a2;
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2);
  if ( !session_by_vdev_id )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: session not found for given vdev_id %d",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "lim_sae_auth_cleanup_retry",
             v2);
  v13 = session_by_vdev_id;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: sae auth cleanup for vdev_id %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "lim_sae_auth_cleanup_retry",
    v2);
  lim_deactivate_and_change_timer(a1, 20);
  return mlme_free_sae_auth_retry(*(_QWORD *)(v13 + 16), v14, v15, v16, v17, v18, v19, v20, v21);
}
