__int64 __fastcall wlansap_set_dfs_target_chnl(
        __int64 a1,
        int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x0
  __int64 v13; // x19
  __int64 sap_ch_sw_info; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  const char *v25; // x2
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  if ( !a1 )
  {
    v25 = "%s: Invalid mac_handle pointer";
LABEL_7:
    qdf_trace_msg(0x39u, 2u, v25, a4, a5, a6, a7, a8, a9, a10, a11, "wlansap_set_dfs_target_chnl");
    return 5;
  }
  v12 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 21552),
          a3,
          7);
  if ( !v12 )
  {
    v25 = "%s: Invalid vdev";
    goto LABEL_7;
  }
  v13 = v12;
  sap_ch_sw_info = wlan_get_sap_ch_sw_info(v12, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( sap_ch_sw_info )
  {
    *(_DWORD *)(sap_ch_sw_info + 4) = a2;
    wlan_objmgr_vdev_release_ref(v13, 7u, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    return 0;
  }
  qdf_trace_msg(
    0x39u,
    2u,
    "%s: Invalid channel info",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wlansap_set_dfs_target_chnl");
  wlan_objmgr_vdev_release_ref(v13, 7u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
  return 5;
}
