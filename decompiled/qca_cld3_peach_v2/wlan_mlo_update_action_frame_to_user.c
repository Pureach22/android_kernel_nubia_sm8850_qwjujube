__int64 __fastcall wlan_mlo_update_action_frame_to_user(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 bsspeer; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x21
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  result = wlan_vdev_mlme_is_mlo_vdev(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( (result & 1) != 0 && !*(_DWORD *)(a1 + 16) )
  {
    if ( a3 > 0x19 )
    {
      if ( *(_BYTE *)(a2 + 24) != 4 )
      {
        bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x5Au);
        if ( bsspeer )
        {
          v32 = bsspeer;
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Change link addr to MLD addr for non-Public action frame",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "wlan_mlo_update_action_frame_to_user");
          qdf_ether_addr_copy((_WORD *)(a2 + 4), (_WORD *)(a1 + 80));
          qdf_ether_addr_copy((_WORD *)(a2 + 10), (_WORD *)(v32 + 792));
          qdf_ether_addr_copy((_WORD *)(a2 + 16), (_WORD *)(v32 + 792));
          return wlan_objmgr_peer_release_ref(v32, 0x5Au, v33, v34, v35, v36, v37, v38, v39, v40);
        }
        else
        {
          return qdf_trace_msg(
                   0x8Fu,
                   8u,
                   "%s: Peer not found",
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   "wlan_mlo_update_action_frame_to_user");
        }
      }
    }
    else
    {
      return qdf_trace_msg(
               0x8Fu,
               8u,
               "%s: Not a valid Action frame len: %d",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "wlan_mlo_update_action_frame_to_user",
               a3);
    }
  }
  return result;
}
