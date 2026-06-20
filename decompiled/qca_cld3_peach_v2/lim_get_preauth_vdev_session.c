__int64 __fastcall lim_get_preauth_vdev_session(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  _QWORD *vdev_by_macaddr_from_psoc; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 session_by_vdev_id; // x0
  __int64 v26; // x4
  __int64 v27; // x20
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  vdev_by_macaddr_from_psoc = wlan_objmgr_get_vdev_by_macaddr_from_psoc(
                                *(_QWORD *)(a1 + 21624),
                                *(_BYTE *)(*(_QWORD *)(a1 + 21632) + 40LL),
                                a3 + 4,
                                7u);
  if ( vdev_by_macaddr_from_psoc )
  {
    v15 = (__int64)vdev_by_macaddr_from_psoc;
    if ( cm_is_vdev_connecting(a2, v7, v8, v9, v10, v11, v12, v13, v14)
      || (wlan_vdev_mlme_is_mlo_vdev(a2, v17, v18, v19, v20, v21, v22, v23, v24) & 1) == 0 )
    {
      v27 = 0;
    }
    else
    {
      session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(v15 + 168));
      v26 = *(unsigned __int8 *)(a2 + 168);
      v27 = session_by_vdev_id;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: SAE: given vdev_id:%d lookup vdev_id:%d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "lim_get_preauth_vdev_session",
        v26,
        *(unsigned __int8 *)(v15 + 168));
    }
    wlan_objmgr_vdev_release_ref(v15, 7u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: not able to find preauth vdev by mac %02x:%02x:%02x:**:**:%02x",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "lim_get_preauth_vdev_session",
      a3[4],
      a3[5],
      a3[6],
      a3[9]);
    return 0;
  }
  return v27;
}
