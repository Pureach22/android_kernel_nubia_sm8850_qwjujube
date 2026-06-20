__int64 __fastcall lim_get_vdev_rmf_capable(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  int param; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int8 v21; // w20
  _BOOL4 has_mgmtcipher; // w0
  unsigned int *v23; // x8
  unsigned int v24; // w20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  v2 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)(a1 + 21552),
         *(unsigned __int8 *)(a2 + 10),
         11);
  if ( !v2 )
  {
    qdf_trace_msg(0x35u, 2u, "%s: Invalid vdev", v3, v4, v5, v6, v7, v8, v9, v10, "lim_get_vdev_rmf_capable");
    return 0;
  }
  v11 = v2;
  param = wlan_crypto_get_param(v2, 5u);
  if ( param < 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid mgmt cipher",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_get_vdev_rmf_capable");
    wlan_objmgr_vdev_release_ref(v11, 0xBu, v33, v34, v35, v36, v37, v38, v39, v40, v41);
    return 0;
  }
  v21 = param;
  has_mgmtcipher = wlan_crypto_vdev_has_mgmtcipher(v11, 6208);
  v23 = (unsigned int *)(v21 & 0x80);
  v24 = has_mgmtcipher & ((unsigned int)v23 >> 7);
  wlan_objmgr_vdev_release_ref(v11, 0xBu, v23, v25, v26, v27, v28, v29, v30, v31, v32);
  return v24;
}
