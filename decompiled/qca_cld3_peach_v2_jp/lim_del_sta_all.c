__int64 __fastcall lim_del_sta_all(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 cmpt_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w19
  __int64 v34; // [xsp+8h] [xbp-18h]

  if ( *(_DWORD *)(a2 + 88) != 1 )
    return 4;
  v34 = v11;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a2 + 16), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( cmpt_obj )
  {
    v23 = vdev_mgr_peer_delete_all_send(cmpt_obj, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( v23 )
    {
      v32 = v23;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: failed status = %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "lim_del_sta_all",
        v23,
        v10,
        v34);
      return v32;
    }
    else
    {
      return lim_del_peer_info(a1, a2, v24, v25, v26, v27, v28, v29, v30, v31);
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev component object is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "lim_del_sta_all",
      v10,
      v34);
    return 16;
  }
}
