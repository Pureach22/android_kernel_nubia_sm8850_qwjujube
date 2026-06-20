__int64 __fastcall wlan_get_dcs_mode(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w20
  unsigned int *v13; // x8
  __int64 v14; // x20
  int ap_policy; // w21
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w20
  const char *v35; // x2
  __int64 v36; // x4

  v2 = a2;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( !v3 )
  {
    v35 = "%s: Invalid vdev %d: ";
    v36 = v2;
LABEL_9:
    qdf_trace_msg(0x74u, 8u, v35, v4, v5, v6, v7, v8, v9, v10, v11, "wlan_get_dcs_mode", v36);
    return 4;
  }
  v12 = *(_DWORD *)(v3 + 16);
  v13 = (unsigned int *)(v12 & 0xFFFFFFFD);
  if ( (_DWORD)v13 != 1 )
  {
    wlan_objmgr_vdev_release_ref(v3, 0x18u, v13, v4, v5, v6, v7, v8, v9, v10, v11);
    v35 = "%s: Invalid vdev opmode %d";
    v36 = v12;
    goto LABEL_9;
  }
  v14 = v3;
  ap_policy = wlan_mlme_get_ap_policy(v3, v4, v5, v6, v7, v8, v9, v10, v11);
  wlan_objmgr_vdev_release_ref(v14, 0x18u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( ap_policy == 3 )
    v33 = 2;
  else
    v33 = (unsigned int)(ap_policy - 1) < 2;
  qdf_trace_msg(
    0x74u,
    8u,
    "%s: vdev id %d dcs mode %d",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "wlan_get_dcs_mode",
    v2,
    v33);
  return v33;
}
