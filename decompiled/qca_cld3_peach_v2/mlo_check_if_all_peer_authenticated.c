__int64 __fastcall mlo_check_if_all_peer_authenticated(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  const char *v10; // x2
  __int64 *v12; // x21
  _QWORD *v13; // x20
  __int64 v14; // x19
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
  __int64 v32; // x20
  __int64 v33; // x21
  __int64 v34; // x21
  __int64 v35; // x21
  __int64 v36; // x4
  __int64 v37; // x19

  if ( !a1 || !*(_QWORD *)(a1 + 1360) )
  {
    v10 = "%s: Vdev is null";
LABEL_6:
    qdf_trace_msg(0x8Fu, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "mlo_check_if_all_peer_authenticated");
    return 0;
  }
  if ( (unsigned int)wlan_vdev_is_up() )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Vdev id %d is not in up state",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlo_check_if_all_peer_authenticated",
      *(unsigned __int8 *)(a1 + 168));
    return 0;
  }
  v12 = *(__int64 **)(a1 + 1360);
  v13 = (_QWORD *)v12[278];
  if ( !v13 )
  {
    v10 = "%s: mlo sta ctx is null";
    goto LABEL_6;
  }
  v14 = v12[3];
  if ( v14 && ((v13[1] & 1) != 0 || (*v13 & 1) != 0) )
  {
    if ( !wlan_cm_is_vdev_connected(v12[3], a2, a3, a4, a5, a6, a7, a8, a9) )
      goto LABEL_28;
    bsspeer = wlan_objmgr_vdev_try_get_bsspeer(v14, 0x5Au);
    if ( !bsspeer )
      goto LABEL_30;
    if ( (*(_BYTE *)(bsspeer + 87) & 1) == 0 )
      goto LABEL_32;
    wlan_objmgr_peer_release_ref(bsspeer, 0x5Au, v24, v25, v26, v27, v28, v29, v30, v31);
  }
  v14 = v12[4];
  if ( v14 && ((v13[1] & 2) != 0 || (*v13 & 2) != 0) )
  {
    if ( wlan_cm_is_vdev_connected(v12[4], a2, a3, a4, a5, a6, a7, a8, a9) )
    {
      bsspeer = wlan_objmgr_vdev_try_get_bsspeer(v14, 0x5Au);
      if ( bsspeer )
      {
        if ( *(_BYTE *)(bsspeer + 87) == 1 )
        {
          wlan_objmgr_peer_release_ref(bsspeer, 0x5Au, v24, v25, v26, v27, v28, v29, v30, v31);
          goto LABEL_24;
        }
LABEL_32:
        v35 = jiffies;
        if ( mlo_check_if_all_peer_authenticated___last_ticks_33 - jiffies + 125 < 0 )
        {
          v36 = *(unsigned __int8 *)(v14 + 168);
          v37 = bsspeer;
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Vdev%d bss peer not authenticated",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "mlo_check_if_all_peer_authenticated",
            v36);
          bsspeer = v37;
          mlo_check_if_all_peer_authenticated___last_ticks_33 = v35;
        }
        wlan_objmgr_peer_release_ref(bsspeer, 0x5Au, v24, v25, v26, v27, v28, v29, v30, v31);
        return 0;
      }
LABEL_30:
      v34 = jiffies;
      if ( mlo_check_if_all_peer_authenticated___last_ticks_31 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: BSS peer for vdev %d is null",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "mlo_check_if_all_peer_authenticated",
          *(unsigned __int8 *)(v14 + 168));
        mlo_check_if_all_peer_authenticated___last_ticks_31 = v34;
        return 0;
      }
      return 0;
    }
LABEL_28:
    v33 = jiffies;
    if ( mlo_check_if_all_peer_authenticated___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: vdev %d not connected",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "mlo_check_if_all_peer_authenticated",
        *(unsigned __int8 *)(v14 + 168));
      mlo_check_if_all_peer_authenticated___last_ticks = v33;
      return 0;
    }
    return 0;
  }
LABEL_24:
  v32 = jiffies;
  if ( mlo_check_if_all_peer_authenticated___last_ticks_35 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: all peers are authenticated",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlo_check_if_all_peer_authenticated");
    mlo_check_if_all_peer_authenticated___last_ticks_35 = v32;
  }
  return 1;
}
