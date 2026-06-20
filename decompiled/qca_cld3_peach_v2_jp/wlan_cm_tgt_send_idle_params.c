__int64 __fastcall wlan_cm_tgt_send_idle_params(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w20
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v14; // x19
  __int64 v15; // x0
  __int64 ext_hdl; // x0
  __int64 (*v17)(void); // x8
  __int64 v18; // x9
  unsigned int *v19; // x8
  unsigned int v20; // w21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2

  v2 = a2;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v4 )
    return 4;
  v13 = *(_QWORD *)(v4 + 152);
  v14 = v4;
  if ( !v13 || (v15 = *(_QWORD *)(v13 + 80)) == 0 )
  {
    v29 = "%s: psoc object is NULL";
LABEL_14:
    qdf_trace_msg(0x1Fu, 2u, v29, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_cm_roam_get_tx_ops_from_vdev");
    goto LABEL_15;
  }
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(v15);
  if ( !ext_hdl )
  {
    v29 = "%s: psoc legacy private object is NULL";
    goto LABEL_14;
  }
  v17 = *(__int64 (**)(void))(ext_hdl + 7280);
  if ( !v17 )
  {
LABEL_15:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: CM_RSO: vdev %d send_roam_idle_trigger is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_cm_tgt_send_idle_params",
      v2);
    goto LABEL_16;
  }
  if ( a1 )
  {
    v18 = *(_QWORD *)(a1 + 2800);
    if ( v18 )
    {
      if ( *(_QWORD *)(v18 + 16) )
      {
        if ( *((_DWORD *)v17 - 1) != -1476241509 )
          __break(0x8228u);
        v20 = v17();
        if ( v20 )
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: CM_RSO: vdev %d failed to send idle params",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "wlan_cm_tgt_send_idle_params",
            v2);
        goto LABEL_17;
      }
    }
  }
  qdf_trace_msg(0x68u, 8u, "%s: Invalid WMI handle", v5, v6, v7, v8, v9, v10, v11, v12, "wlan_cm_tgt_send_idle_params");
LABEL_16:
  v20 = 4;
LABEL_17:
  wlan_objmgr_vdev_release_ref(v14, 2u, v19, v21, v22, v23, v24, v25, v26, v27, v28);
  return v20;
}
