__int64 __fastcall wlan_mlme_set_ml_link_control_mode(__int64 a1, unsigned int a2, unsigned __int8 a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 v25; // x8
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
    if ( result )
    {
      v15 = result;
      if ( (wlan_vdev_mlme_is_mlo_vdev(result, v7, v8, v9, v10, v11, v12, v13, v14) & 1) != 0 )
      {
        v24 = *(_QWORD *)(v15 + 1360);
        if ( v24 )
        {
          v25 = *(_QWORD *)(v24 + 2224);
          if ( v25 )
          {
            *(_BYTE *)(v25 + 1492) = a3;
            qdf_trace_msg(
              0x1Fu,
              8u,
              "%s: set ml_link_control_mode %d",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "wlan_mlme_set_ml_link_control_mode",
              a3);
            return wlan_objmgr_vdev_release_ref(v15, 1u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
          }
        }
        v35 = "%s: mlo dev/sta ctx is null";
      }
      else
      {
        v35 = "%s: not mlo vdev";
      }
      qdf_trace_msg(0x1Fu, 8u, v35, v16, v17, v18, v19, v20, v21, v22, v23, "wlan_mlme_set_ml_link_control_mode");
      return wlan_objmgr_vdev_release_ref(v15, 1u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
    }
  }
  return result;
}
