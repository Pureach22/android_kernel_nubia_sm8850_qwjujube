__int64 __fastcall lim_sta_mlme_vdev_sta_disconnect_start(
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
  unsigned int v10; // w21
  _QWORD *context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x22
  __int64 session_by_vdev_id; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x19
  __int64 hash_entry; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x21
  int v41; // w8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  v10 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL);
  context = _cds_get_context(53, (__int64)"lim_sta_mlme_vdev_sta_disconnect_start", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v20 = (__int64)context;
    session_by_vdev_id = pe_find_session_by_vdev_id((__int64)context, v10, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( session_by_vdev_id )
    {
      v30 = session_by_vdev_id;
      hash_entry = dph_get_hash_entry(v20, 1u, session_by_vdev_id + 360);
      if ( hash_entry )
      {
        v40 = hash_entry;
        mlme_set_connection_fail(*(_QWORD *)(a1 + 504), 0, v32, v33, v34, v35, v36, v37, v38, v39);
        v41 = *(_DWORD *)(v30 + 80);
        *(_DWORD *)(v30 + 80) = 12;
        *(_DWORD *)(v30 + 84) = v41;
        *(_DWORD *)(v40 + 24) = 1;
        *(_WORD *)(v40 + 34) = 0;
        *(_DWORD *)(v40 + 8) = 22;
        wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)(v30 + 16), 0xDu, 0x2A28u, v30, v42, v43, v44, v45, v46, v47, v48, v49);
        return 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: session is NULL for vdevid %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "lim_sta_mlme_vdev_sta_disconnect_start",
        v10);
    }
  }
  return 4;
}
