__int64 __fastcall mlme_set_supplicant_disabled_roaming(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 ext_hdl; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int *v23; // x8

  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( !v4 )
    return qdf_trace_msg(
             0x1Fu,
             2u,
             "%s: vdev object is NULL",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "mlme_set_supplicant_disabled_roaming");
  v13 = v4;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v4, v5, v6, v7, v8, v9, v10, v11, v12);
  if ( ext_hdl )
  {
    v23 = (unsigned int *)(a3 & 1);
    *(_BYTE *)(ext_hdl + 164) = a3 & 1;
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "mlme_set_supplicant_disabled_roaming");
  }
  return wlan_objmgr_vdev_release_ref(v13, 0x43u, v23, v15, v16, v17, v18, v19, v20, v21, v22);
}
