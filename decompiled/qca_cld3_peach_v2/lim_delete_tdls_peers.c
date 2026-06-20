__int64 __fastcall lim_delete_tdls_peers(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  char is_link_switch_in_progress; // w8

  if ( a2 )
  {
    lim_check_aid_and_delete_peer();
    tgt_tdls_delete_all_peers_indication(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a2 + 10));
    if ( wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(a2 + 16), v14, v15, v16, v17, v18, v19, v20, v21) )
    {
      return 0;
    }
    else
    {
      is_link_switch_in_progress = mlo_mgr_is_link_switch_in_progress(*(_QWORD *)(a2 + 16));
      result = 0;
      if ( a3 != 3 && (is_link_switch_in_progress & 1) == 0 )
      {
        if ( *(_BYTE *)(a2 + 7260) == 1 )
          tgt_tdls_peers_deleted_notification(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a2 + 10));
        *(_BYTE *)(a2 + 7260) = 1;
        return 0;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: NULL session_entry", a4, a5, a6, a7, a8, a9, a10, a11, "lim_delete_tdls_peers");
    return 16;
  }
  return result;
}
