__int64 __fastcall mlo_is_ml_connection_in_progress(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  unsigned int *is_vdev_connected; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 *v12; // x19
  __int64 v13; // x20

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 90);
  if ( v2 )
  {
    v12 = *(__int64 **)(v2 + 1360);
    if ( v12 )
    {
      v13 = v2;
      if ( (wlan_vdev_mlme_is_mlo_vdev(v2, v4, v5, v6, v7, v8, v9, v10, v11) & 1) != 0 )
      {
        v2 = v13;
        LODWORD(v12) = v12[3]
                    && (*(_QWORD *)(v12[278] + 8) & 1) != 0
                    && (is_vdev_connected = (unsigned int *)wlan_cm_is_vdev_connected(
                                                              v12[3],
                                                              v4,
                                                              v5,
                                                              v6,
                                                              v7,
                                                              v8,
                                                              v9,
                                                              v10,
                                                              v11),
                        v2 = v13,
                        ((unsigned __int8)is_vdev_connected & 1) == 0)
                    || (is_vdev_connected = (unsigned int *)v12[4]) != nullptr
                    && (*(_QWORD *)(v12[278] + 8) & 2) != 0
                    && (is_vdev_connected = (unsigned int *)wlan_cm_is_vdev_connected(
                                                              v12[4],
                                                              v4,
                                                              v5,
                                                              v6,
                                                              v7,
                                                              v8,
                                                              v9,
                                                              v10,
                                                              v11),
                        v2 = v13,
                        ((unsigned __int8)is_vdev_connected & 1) == 0);
      }
      else
      {
        LODWORD(v12) = 0;
        v2 = v13;
      }
    }
    wlan_objmgr_vdev_release_ref(v2, 0x5Au, is_vdev_connected, v4, v5, v6, v7, v8, v9, v10, v11);
  }
  else
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: Invalid vdev", v4, v5, v6, v7, v8, v9, v10, v11, "mlo_is_ml_connection_in_progress");
    LODWORD(v12) = 0;
  }
  return (unsigned int)v12;
}
