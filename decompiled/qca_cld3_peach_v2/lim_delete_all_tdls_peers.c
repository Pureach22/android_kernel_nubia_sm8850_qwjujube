__int64 __fastcall lim_delete_all_tdls_peers(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  __int64 session_by_vdev_id; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 result; // x0
  char is_link_switch_in_progress; // w8

  context = _cds_get_context(53, (__int64)"lim_delete_all_tdls_peers", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return 16;
  v21 = (__int64)context;
  session_by_vdev_id = pe_find_session_by_vdev_id(
                         (__int64)context,
                         *(_BYTE *)(a1 + 168),
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20);
  if ( session_by_vdev_id )
  {
    v31 = session_by_vdev_id;
    lim_check_aid_and_delete_peer(v21, session_by_vdev_id);
    tgt_tdls_delete_all_peers_indication(*(_QWORD *)(v21 + 21624), *(unsigned __int8 *)(v31 + 10));
    if ( wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(v31 + 16), v32, v33, v34, v35, v36, v37, v38, v39) )
    {
      return 0;
    }
    else
    {
      is_link_switch_in_progress = mlo_mgr_is_link_switch_in_progress(*(_QWORD *)(v31 + 16));
      result = 0;
      if ( a2 != 3 && (is_link_switch_in_progress & 1) == 0 )
      {
        if ( *(_BYTE *)(v31 + 7260) == 1 )
          tgt_tdls_peers_deleted_notification(*(_QWORD *)(v21 + 21624), *(unsigned __int8 *)(v31 + 10));
        *(_BYTE *)(v31 + 7260) = 1;
        return 0;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: No pe_session found for vdev_id:%d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "lim_delete_all_tdls_peers",
      *(unsigned __int8 *)(a1 + 168));
    return 16;
  }
  return result;
}
