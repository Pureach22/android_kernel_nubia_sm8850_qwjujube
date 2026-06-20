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
  __int64 v23; // x21
  __int64 v24; // x0
  unsigned int v25; // w22
  __int64 hash_entry; // x0
  __int64 v27; // x23
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w19
  __int64 v39; // [xsp+8h] [xbp-38h]

  if ( *(_DWORD *)(a2 + 88) != 1 )
    return 4;
  v39 = v11;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a2 + 16), a3, a4, a5, a6, a7, a8, a9, a10);
  if ( cmpt_obj )
  {
    v23 = cmpt_obj;
    v24 = *(_QWORD *)(a2 + 16);
    if ( *(_DWORD *)(v24 + 16) == 1
      && (wlan_vdev_mlme_is_mlo_vdev(v24, v15, v16, v17, v18, v19, v20, v21, v22) & 1) != 0
      && *(unsigned __int16 *)(a2 + 376) >= 2u )
    {
      v25 = 1;
      do
      {
        hash_entry = dph_get_hash_entry(a1, v25, a2 + 360);
        if ( hash_entry )
        {
          v27 = hash_entry;
          if ( (lim_is_mlo_conn(a2, hash_entry) & 1) != 0 )
            lim_mlo_delete_link_peer(a2, v27);
        }
        ++v25;
      }
      while ( v25 < *(unsigned __int16 *)(a2 + 376) );
    }
    v29 = vdev_mgr_peer_delete_all_send(v23, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( v29 )
    {
      v38 = v29;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: failed status = %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "lim_del_sta_all",
        v29,
        v10,
        v39);
      return v38;
    }
    else
    {
      return lim_del_peer_info(a1, a2, v30, v31, v32, v33, v34, v35, v36, v37);
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
      v39);
    return 16;
  }
}
