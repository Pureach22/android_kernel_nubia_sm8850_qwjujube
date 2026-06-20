__int64 __fastcall wlan_cm_get_associated_ch_info(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4)
{
  unsigned __int8 v5; // w20
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 ext_hdl; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v5 = a2;
  *a4 = 8;
  a4[3] = 0;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v6 )
    return qdf_trace_msg(
             0x1Fu,
             2u,
             "%s: vdev %d: vdev not found",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "wlan_cm_get_associated_ch_info",
             v5);
  v15 = v6;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v6, v7, v8, v9, v10, v11, v12, v13, v14);
  if ( ext_hdl )
  {
    *a4 = *(_DWORD *)(ext_hdl + 24248);
    a4[3] = *(_DWORD *)(ext_hdl + 24260);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d: associated_ch_width:%d, sec_2g_freq:%d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_cm_get_associated_ch_info",
      v5);
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: mlme_priv is NULL",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_cm_get_associated_ch_info");
  }
  return wlan_objmgr_vdev_release_ref(v15, 2u, v25, v26, v27, v28, v29, v30, v31, v32, v33);
}
