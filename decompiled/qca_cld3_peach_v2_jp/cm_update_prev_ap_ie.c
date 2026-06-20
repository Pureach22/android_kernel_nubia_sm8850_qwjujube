__int64 __fastcall cm_update_prev_ap_ie(__int64 result, __int64 a2, unsigned int a3, const void *a4)
{
  unsigned __int8 v6; // w22
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  __int64 rso_config_fl; // x0
  unsigned int *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x22
  __int64 v28; // x0
  void *v29; // x0

  if ( a3 && a4 )
  {
    v6 = a2;
    v7 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(result, a2, 77);
    if ( v7 )
    {
      v16 = v7;
      rso_config_fl = wlan_cm_get_rso_config_fl(v7, "cm_update_prev_ap_ie", 236);
      if ( rso_config_fl )
      {
        v27 = rso_config_fl;
        v28 = *(_QWORD *)(rso_config_fl + 264);
        if ( v28 )
        {
          _qdf_mem_free(v28);
          *(_QWORD *)(v27 + 264) = 0;
          *(_DWORD *)(v27 + 256) = 0;
        }
        v29 = (void *)_qdf_mem_malloc(a3, "cm_update_prev_ap_ie", 246);
        *(_QWORD *)(v27 + 264) = v29;
        if ( v29 )
          qdf_mem_copy(v29, a4, a3);
        else
          *(_DWORD *)(v27 + 256) = 0;
      }
      return wlan_objmgr_vdev_release_ref(v16, 0x4Du, v18, v19, v20, v21, v22, v23, v24, v25, v26);
    }
    else
    {
      return qdf_trace_msg(
               0x68u,
               2u,
               "%s: vdev is NULL for vdev id %d",
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               "cm_update_prev_ap_ie",
               v6);
    }
  }
  return result;
}
