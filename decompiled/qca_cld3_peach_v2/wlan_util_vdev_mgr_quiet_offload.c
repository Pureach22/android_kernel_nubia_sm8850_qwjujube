__int64 __fastcall wlan_util_vdev_mgr_quiet_offload(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w8
  int v13; // w9
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  __int64 v23; // x20
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x0
  __int64 v34; // x2
  __int64 v35; // x1
  const void *v36; // x1
  __int64 v37; // x0
  __int64 result; // x0
  __int64 v39; // x4
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  const char *v43; // x2
  const char *v44; // x2
  _BYTE v45[36]; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v46; // [xsp+28h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_DWORD *)a2;
  v13 = *((unsigned __int16 *)a2 + 2);
  v45[0] = 0;
  if ( !(v12 | v13) && !(*(_DWORD *)(a2 + 6) | *((unsigned __int16 *)a2 + 5)) )
  {
    v43 = "%s: mld_mac and link mac are invalid";
LABEL_20:
    qdf_trace_msg(0x68u, 2u, v43, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_util_vdev_mgr_quiet_offload");
LABEL_25:
    result = 4;
    goto LABEL_26;
  }
  if ( *(_DWORD *)a2 | *((unsigned __int16 *)a2 + 2) )
  {
    if ( (wlan_get_connected_vdev_by_mld_addr(a1, (__int64)a2, v45) & 1) != 0 )
    {
      v22 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v45[0], 67);
      if ( v22 )
      {
        v23 = v22;
        if ( (wlan_vdev_mlme_is_mlo_vdev(v22, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
        {
          v33 = *(_QWORD *)(v23 + 1360);
          v34 = a2[13];
          v35 = a2[12];
LABEL_13:
          v25 = mlo_sta_save_quiet_status(v33, v35, v34);
          goto LABEL_14;
        }
        goto LABEL_14;
      }
LABEL_19:
      v43 = "%s: Null vdev";
      goto LABEL_20;
    }
    if ( a2 )
    {
      v39 = *a2;
      v40 = a2[1];
      v41 = a2[2];
      v42 = a2[5];
    }
    else
    {
      v41 = 0;
      v39 = 0;
      v40 = 0;
      v42 = 0;
    }
    v44 = "%s: Can't find vdev with mld %02x:%02x:%02x:**:**:%02x";
    goto LABEL_24;
  }
  v36 = a2 + 6;
  if ( *(_DWORD *)(a2 + 6) | *((unsigned __int16 *)a2 + 5) )
  {
    if ( (wlan_get_connected_vdev_from_psoc_by_bssid(a1, v36, v45) & 1) != 0 )
    {
      v37 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v45[0], 67);
      if ( v37 )
      {
        v23 = v37;
        if ( (wlan_vdev_mlme_is_mlo_vdev(v37, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
        {
          v33 = *(_QWORD *)(v23 + 1360);
          v34 = a2[13];
          v35 = *(unsigned __int8 *)(v23 + 93);
          goto LABEL_13;
        }
LABEL_14:
        wlan_objmgr_vdev_release_ref(v23, 0x43u, v24, v25, v26, v27, v28, v29, v30, v31, v32);
        goto LABEL_15;
      }
      goto LABEL_19;
    }
    v39 = a2[6];
    v40 = a2[7];
    v44 = "%s: Can't find vdev with BSSID%02x:%02x:%02x:**:**:%02x";
    v41 = a2[8];
    v42 = a2[11];
LABEL_24:
    qdf_trace_msg(
      0x68u,
      2u,
      v44,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_util_vdev_mgr_quiet_offload",
      v39,
      v40,
      v41,
      v42);
    goto LABEL_25;
  }
LABEL_15:
  result = 0;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
