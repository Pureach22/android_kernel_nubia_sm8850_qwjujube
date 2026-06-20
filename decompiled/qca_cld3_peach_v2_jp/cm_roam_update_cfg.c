__int64 __fastcall cm_roam_update_cfg(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  unsigned int v4; // w21
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 ext_hdl_fl; // x8
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v4 = a2;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( !v6 )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev object is NULL",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "cm_roam_update_cfg");
  ext_hdl_fl = *(unsigned int *)(v6 + 16);
  if ( (ext_hdl_fl & 0xFFFFFFFD) == 0 )
  {
    v17 = v6;
    ext_hdl_fl = cm_get_ext_hdl_fl(v6, (__int64)"cm_roam_acquire_lock", 0x7C4u, v7, v8, v9, v10, v11, v12, v13, v14);
    v6 = v17;
    cm_roam_acquire_lock_rso_cfg = ext_hdl_fl;
    if ( ext_hdl_fl )
    {
      ext_hdl_fl = (unsigned int)qdf_mutex_acquire(ext_hdl_fl);
      v6 = v17;
      if ( !(_DWORD)ext_hdl_fl )
      {
        if ( (unsigned int)mlme_get_roam_state(a1, v4) == 2 )
          cm_roam_send_rso_cmd(a1, v4, 4u, a3);
        else
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: Update cfg received while ROAM RSO not started",
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            "cm_roam_update_cfg");
        ext_hdl_fl = *(unsigned int *)(v17 + 16);
        v6 = v17;
        if ( (ext_hdl_fl & 0xFFFFFFFD) == 0 )
        {
          ext_hdl_fl = cm_get_ext_hdl_fl(
                         v17,
                         (__int64)"cm_roam_release_lock",
                         0x7CFu,
                         v7,
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         v13,
                         v14);
          v6 = v17;
          cm_roam_release_lock_rso_cfg = ext_hdl_fl;
          if ( ext_hdl_fl )
          {
            qdf_mutex_release(ext_hdl_fl);
            v6 = v17;
          }
        }
      }
    }
  }
  return wlan_objmgr_vdev_release_ref(v6, 0x4Du, (unsigned int *)ext_hdl_fl, v7, v8, v9, v10, v11, v12, v13, v14);
}
