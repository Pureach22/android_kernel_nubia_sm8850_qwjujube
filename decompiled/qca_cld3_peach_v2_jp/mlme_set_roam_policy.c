__int64 __fastcall mlme_set_roam_policy(__int64 a1, __int64 a2, int a3)
{
  unsigned __int8 v4; // w19
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  __int64 ext_hdl; // x0
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( !v5 )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev%d: vdev object is NULL",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "mlme_set_roam_policy",
             v4);
  v14 = v5;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v5, v6, v7, v8, v9, v10, v11, v12, v13);
  if ( ext_hdl )
    *(_DWORD *)(ext_hdl + 168) = a3;
  else
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev%d: vdev legacy private object is NULL",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "mlme_set_roam_policy",
      v4);
  return wlan_objmgr_vdev_release_ref(v14, 0x43u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
}
