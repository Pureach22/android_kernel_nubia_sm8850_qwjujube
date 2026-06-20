__int64 __fastcall wlan_cm_link_switch_notif_cb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        int a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x4
  unsigned int v32; // w19
  __int64 v33; // [xsp+8h] [xbp-18h]

  if ( a11 )
    return 0;
  v33 = v12;
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
    return 0;
  if ( (mlo_is_link_recfg_in_progress(a1) & 1) != 0 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: link recfg in progress vdev %d linksw reason %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_cm_link_switch_notif_cb",
      *(unsigned __int8 *)(a1 + 168),
      0,
      v11,
      v33);
    return 0;
  }
  if ( (*(_BYTE *)(a1 + 60) & 2) != 0 )
    return 0;
  result = cm_roam_state_change(*(_QWORD *)(a1 + 216), *(unsigned __int8 *)(a1 + 168), 3u, 4u, 0, 0);
  if ( (_DWORD)result )
  {
    v31 = *(unsigned __int8 *)(a1 + 168);
    v32 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev:%d switch to RSO Stop failed",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_cm_link_switch_notif_cb",
      v31,
      v11,
      v33);
    return v32;
  }
  return result;
}
