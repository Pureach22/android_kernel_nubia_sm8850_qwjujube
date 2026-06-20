__int64 __fastcall wlan_mlme_get_ml_link_control_mode(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x8
  unsigned int v24; // w20
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2

  if ( mlme_get_psoc_ext_obj_fl(a1) )
  {
    v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
    if ( v4 )
    {
      v13 = v4;
      if ( (wlan_vdev_mlme_is_mlo_vdev(v4, v5, v6, v7, v8, v9, v10, v11, v12) & 1) != 0 )
      {
        v22 = *(_QWORD *)(v13 + 1360);
        if ( v22 )
        {
          v23 = *(_QWORD *)(v22 + 2224);
          if ( v23 )
          {
            v24 = *(unsigned __int8 *)(v23 + 1492);
            qdf_trace_msg(
              0x1Fu,
              8u,
              "%s: get ml_link_control_mode %d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "wlan_mlme_get_ml_link_control_mode",
              *(unsigned __int8 *)(v23 + 1492));
LABEL_11:
            wlan_objmgr_vdev_release_ref(v13, 1u, v25, v26, v27, v28, v29, v30, v31, v32, v33);
            return v24;
          }
        }
        v34 = "%s: mlo dev/sta ctx is null";
      }
      else
      {
        v34 = "%s: not mlo vdev";
      }
      qdf_trace_msg(0x1Fu, 8u, v34, v14, v15, v16, v17, v18, v19, v20, v21, "wlan_mlme_get_ml_link_control_mode");
      v24 = 0;
      goto LABEL_11;
    }
  }
  return 0;
}
