__int64 __fastcall ucfg_cm_set_cckm_ie(__int64 a1, __int64 a2, const void *a3, unsigned __int8 a4)
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
  __int64 v16; // x20
  __int64 ext_hdl; // x0
  unsigned int *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x22
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  v6 = a2;
  v7 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( v7 )
  {
    v16 = v7;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v7, v8, v9, v10, v11, v12, v13, v14, v15);
    if ( ext_hdl )
    {
      v27 = ext_hdl;
      qdf_mem_copy((void *)(ext_hdl + 24088), a3, a4);
      *(_BYTE *)(v27 + 24226) = a4;
      wlan_objmgr_vdev_release_ref(v16, 0x4Du, dword_5EA2, v28, v29, v30, v31, v32, v33, v34, v35);
      return 0;
    }
    wlan_objmgr_vdev_release_ref(v16, 0x4Du, v18, v19, v20, v21, v22, v23, v24, v25, v26);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev not found for id %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "ucfg_cm_set_cckm_ie",
      v6);
  }
  return 16;
}
