__int64 __fastcall wlan_is_tdls_session_present(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x3
  __int64 connected_peer_count_from_vdev; // x0
  __int64 v22; // x1

  if ( (mlo_is_mld_sta(a1) & 1) != 0 )
  {
    v10 = *(_QWORD *)(a1 + 1360);
    if ( !v10 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: MLO dev ctx is null",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "wlan_mlo_is_tdls_session_present");
      return 16;
    }
    if ( *(_WORD *)(v10 + 40) )
    {
      if ( (unsigned __int16)tdls_get_connected_peer_count_from_vdev(
                               *(_QWORD *)(v10 + 24),
                               v2,
                               v3,
                               v4,
                               v5,
                               v6,
                               v7,
                               v8,
                               v9) )
      {
LABEL_5:
        v19 = "wlan_mlo_is_tdls_session_present";
LABEL_8:
        qdf_trace_msg(0, 8u, "%s: TDLS session is present", v11, v12, v13, v14, v15, v16, v17, v18, v19);
        return 0;
      }
      if ( *(unsigned __int16 *)(v10 + 40) >= 2u )
      {
        connected_peer_count_from_vdev = tdls_get_connected_peer_count_from_vdev(
                                           *(_QWORD *)(v10 + 32),
                                           v11,
                                           v12,
                                           v13,
                                           v14,
                                           v15,
                                           v16,
                                           v17,
                                           v18);
        if ( (_WORD)connected_peer_count_from_vdev )
          goto LABEL_5;
        if ( *(unsigned __int16 *)(v10 + 40) >= 3u )
        {
          __break(0x5512u);
          return wlan_tdls_notify_start_bss(connected_peer_count_from_vdev, v22);
        }
      }
    }
  }
  else if ( (unsigned __int16)tdls_get_connected_peer_count_from_vdev(a1, v2, v3, v4, v5, v6, v7, v8, v9) )
  {
    v19 = "wlan_is_tdls_session_present";
    goto LABEL_8;
  }
  return 4;
}
