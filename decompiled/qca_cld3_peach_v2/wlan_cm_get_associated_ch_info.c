__int64 __fastcall wlan_cm_get_associated_ch_info(__int64 a1, __int64 a2, int a3, _DWORD *a4)
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
  __int64 v16; // x19
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
  __int64 v33; // x8
  __int64 v34; // x9
  __int64 v35; // x22
  __int64 v36; // x10
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 ext_hdl; // x0
  const char *v41; // x2
  const char *v42; // x3
  unsigned int v43; // w0
  unsigned int v44; // w1

  v6 = a2;
  *a4 = 8;
  a4[3] = 0;
  v7 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v7 )
    return qdf_trace_msg(
             0x1Fu,
             2u,
             "%s: vdev %d: vdev not found",
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             "wlan_cm_get_associated_ch_info",
             v6);
  v16 = v7;
  if ( (wlan_vdev_mlme_is_mlo_vdev(v7, v8, v9, v10, v11, v12, v13, v14, v15) & 1) == 0 )
  {
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v16, v17, v18, v19, v20, v21, v22, v23, v24);
    if ( ext_hdl )
    {
      *a4 = *(_DWORD *)(ext_hdl + 24248);
      a4[3] = *(_DWORD *)(ext_hdl + 24260);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d: associated_ch_width:%d, sec_2g_freq:%d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "wlan_cm_get_associated_ch_info",
        v6);
      return wlan_objmgr_vdev_release_ref(v16, 2u, (unsigned int *)v33, v25, v26, v27, v28, v29, v30, v31, v32);
    }
    v41 = "%s: mlme_priv is NULL";
    v42 = "wlan_cm_get_associated_ch_info";
LABEL_20:
    v43 = 31;
    v44 = 2;
LABEL_21:
    qdf_trace_msg(v43, v44, v41, v25, v26, v27, v28, v29, v30, v31, v32, v42);
    return wlan_objmgr_vdev_release_ref(v16, 2u, (unsigned int *)v33, v25, v26, v27, v28, v29, v30, v31, v32);
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d: get assoc chan info for mlo connection",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "wlan_cm_get_associated_ch_info",
    v6);
  v33 = *(_QWORD *)(v16 + 1360);
  if ( !v33 || (v34 = *(_QWORD *)(v33 + 2224)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d :mlo_dev_ctx is NULL",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wlan_cm_get_mlo_associated_ch_info",
      *(unsigned __int8 *)(v16 + 168));
    return wlan_objmgr_vdev_release_ref(v16, 2u, (unsigned int *)v33, v25, v26, v27, v28, v29, v30, v31, v32);
  }
  v35 = *(_QWORD *)(v33 + 24);
  if ( v35 && (*(_QWORD *)(v34 + 8) & 1) != 0 )
  {
    v36 = *(_QWORD *)(v35 + 40);
    if ( !v36 )
    {
LABEL_24:
      v41 = "%s: NULL des_chan";
      v42 = "wlan_cm_get_mlo_associated_ch_info";
      v43 = 104;
      v44 = 8;
      goto LABEL_21;
    }
    if ( *(_DWORD *)(v36 + 24) == a3 )
    {
LABEL_13:
      v38 = wlan_vdev_mlme_get_ext_hdl(v35, v25, v26, v27, v28, v29, v30, v31, v32);
      if ( v38 )
      {
        a4[3] = *(_DWORD *)(v38 + 24260);
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev %d: assoc sec_2g_freq:%d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "wlan_cm_get_mlo_associated_ch_info",
          *(unsigned __int8 *)(v35 + 168));
        return wlan_objmgr_vdev_release_ref(v16, 2u, (unsigned int *)v33, v25, v26, v27, v28, v29, v30, v31, v32);
      }
      v41 = "%s: mlme_priv is NULL";
      v42 = "wlan_cm_get_mlo_associated_ch_info";
      goto LABEL_20;
    }
  }
  v35 = *(_QWORD *)(v33 + 32);
  if ( !v35 )
    return wlan_objmgr_vdev_release_ref(v16, 2u, (unsigned int *)v33, v25, v26, v27, v28, v29, v30, v31, v32);
  v33 = *(_QWORD *)(v34 + 8);
  if ( (v33 & 2) == 0 )
    return wlan_objmgr_vdev_release_ref(v16, 2u, (unsigned int *)v33, v25, v26, v27, v28, v29, v30, v31, v32);
  v37 = *(_QWORD *)(v35 + 40);
  if ( !v37 )
    goto LABEL_24;
  v33 = *(unsigned int *)(v37 + 24);
  if ( (_DWORD)v33 == a3 )
    goto LABEL_13;
  return wlan_objmgr_vdev_release_ref(v16, 2u, (unsigned int *)v33, v25, v26, v27, v28, v29, v30, v31, v32);
}
