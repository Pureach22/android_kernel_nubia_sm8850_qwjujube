__int64 __fastcall hdd_nan_sr_concurrency_update(__int64 *a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  unsigned int v4; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x25
  __int64 v14; // x26
  __int64 v15; // x20
  __int64 v16; // x1
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w22
  int v27; // w8
  __int64 cmpt_obj; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x0
  unsigned __int8 v38[4]; // [xsp+8h] [xbp-48h] BYREF
  _BYTE v39[4]; // [xsp+Ch] [xbp-44h] BYREF
  _BYTE v40[4]; // [xsp+10h] [xbp-40h] BYREF
  _BYTE v41[4]; // [xsp+14h] [xbp-3Ch] BYREF
  int v42; // [xsp+18h] [xbp-38h] BYREF
  char v43; // [xsp+1Ch] [xbp-34h]
  _QWORD v44[6]; // [xsp+20h] [xbp-30h] BYREF

  v44[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v41[0] = 0;
  v40[0] = 0;
  v39[0] = 0;
  v43 = 0;
  v42 = 255;
  memset(v44, 0, 40);
  v38[0] = 0;
  result = policy_mgr_get_connection_info(v2, (__int64)v44);
  if ( !(_DWORD)result )
    goto LABEL_32;
  v4 = result;
  result = policy_mgr_get_mode_specific_conn_info(*a1, 0, (unsigned __int64)&v42, 0);
  v13 = (unsigned __int8)result;
  if ( !(_BYTE)result )
    goto LABEL_32;
  v14 = 0;
  v15 = 0;
  while ( 1 )
  {
    if ( v14 == 5 )
      __break(0x5512u);
    v16 = *((unsigned __int8 *)&v42 + v14);
    if ( (_DWORD)v16 == 255 )
      goto LABEL_5;
    v17 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(*a1, v16, 6);
    v15 = v17;
    if ( v17 )
      break;
    result = qdf_trace_msg(
               0x53u,
               2u,
               "%s: sta vdev invalid for vdev id %d",
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               "hdd_nan_sr_concurrency_update",
               *((unsigned __int8 *)&v42 + v14));
LABEL_5:
    if ( v13 == ++v14 )
    {
      v26 = 255;
      if ( !v15 )
        goto LABEL_32;
      goto LABEL_14;
    }
  }
  result = ucfg_spatial_reuse_get_sr_config(v17, v41, v39, v40);
  if ( v40[0] != 1 )
  {
    result = wlan_objmgr_vdev_release_ref(v15, 6u, (unsigned int *)v40[0], v5, v6, v7, v8, v9, v10, v11, v12);
    goto LABEL_5;
  }
  v26 = *((unsigned __int8 *)&v42 + v14);
  if ( !v15 )
    goto LABEL_32;
LABEL_14:
  if ( (v41[0] & 0xA) != 2 && v40[0] == 1 )
  {
    v27 = *((_DWORD *)a1 + 2);
    if ( v27 == 1 )
    {
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v15, v5, v6, v7, v8, v9, v10, v11, v12);
      if ( cmpt_obj )
        *(_BYTE *)(cmpt_obj + 203) = 1;
      result = wlan_spatial_reuse_osif_event(v15, 0, 1);
      v27 = *((_DWORD *)a1 + 2);
    }
    if ( v27 == 5 || v27 == 2 )
    {
      if ( v4 >= 3 )
      {
        if ( (unsigned int)policy_mgr_get_mac_id_by_session_id(*a1, v26, v38) )
        {
          result = qdf_trace_msg(
                     0x33u,
                     2u,
                     "%s: get mac id failed",
                     v29,
                     v30,
                     v31,
                     v32,
                     v33,
                     v34,
                     v35,
                     v36,
                     "hdd_nan_sr_concurrency_update");
          goto LABEL_30;
        }
        if ( (unsigned int)policy_mgr_get_conc_vdev_on_same_mac(*a1, v26, v38[0]) != 255
          && (policy_mgr_sr_same_mac_conc_enabled(*a1, v5, v6, v7, v8, v9, v10, v11, v12) & 1) == 0 )
        {
          result = qdf_trace_msg(
                     0x33u,
                     8u,
                     "%s: don't enable SR in SCC/MCC",
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     "hdd_nan_sr_concurrency_update");
          goto LABEL_30;
        }
      }
      v37 = wlan_vdev_mlme_get_cmpt_obj(v15, v5, v6, v7, v8, v9, v10, v11, v12);
      if ( v37 )
        *(_BYTE *)(v37 + 203) = 0;
      result = wlan_spatial_reuse_osif_event(v15, 1, 1);
    }
  }
LABEL_30:
  if ( v40[0] == 1 )
    result = wlan_objmgr_vdev_release_ref(v15, 6u, (unsigned int *)v40[0], v5, v6, v7, v8, v9, v10, v11, v12);
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
