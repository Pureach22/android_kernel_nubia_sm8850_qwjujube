__int64 __fastcall cm_roam_disconnect_params(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
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

  *(_DWORD *)a3 = (unsigned __int8)a2;
  wlan_mlme_get_enable_disconnect_roam_offload(a1, (char *)(a3 + 4));
  result = mlme_get_roam_trigger_bitmap(a1, a2);
  if ( *(_BYTE *)(a3 + 4) == 1 && (result & 0x2000) != 0 )
  {
    v7 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
    if ( v7 )
    {
      v16 = v7;
      rso_config_fl = wlan_cm_get_rso_config_fl(v7, "cm_roam_disconnect_params", 457);
      if ( rso_config_fl )
      {
        v18 = (unsigned int *)*(unsigned int *)(rso_config_fl + 232);
        *(_DWORD *)(a3 + 8) = (_DWORD)v18;
      }
      return wlan_objmgr_vdev_release_ref(v16, 2u, v18, v19, v20, v21, v22, v23, v24, v25, v26);
    }
    else
    {
      return qdf_trace_msg(
               0x68u,
               2u,
               "%s: vdev is NULL",
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               "cm_roam_disconnect_params");
    }
  }
  return result;
}
