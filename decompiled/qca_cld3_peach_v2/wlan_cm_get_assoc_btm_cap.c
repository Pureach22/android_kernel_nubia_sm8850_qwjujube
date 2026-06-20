__int64 __fastcall wlan_cm_get_assoc_btm_cap(__int64 a1, __int64 a2)
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
  __int64 ext_hdl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int *v21; // x8
  char v22; // w20

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 7);
  if ( v2 )
  {
    v11 = v2;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v2, v3, v4, v5, v6, v7, v8, v9, v10);
    if ( ext_hdl )
    {
      v21 = (_DWORD *)&unk_5EB4;
      v22 = *(_BYTE *)(ext_hdl + 24244);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: mlme_priv is NULL",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_cm_get_assoc_btm_cap");
      v22 = 1;
    }
    wlan_objmgr_vdev_release_ref(v11, 7u, v21, v13, v14, v15, v16, v17, v18, v19, v20);
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "wlan_cm_get_assoc_btm_cap");
    v22 = 1;
  }
  return v22 & 1;
}
