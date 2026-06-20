__int64 __fastcall sme_update_beacon_country_ie(__int64 a1, __int64 a2, char a3)
{
  unsigned __int8 v5; // w22
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  __int64 ext_hdl; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v5 = a2;
  v6 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)(a1 + 21552),
         a2,
         2);
  if ( v6 )
  {
    v15 = v6;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v6, v7, v8, v9, v10, v11, v12, v13, v14);
    if ( ext_hdl )
    {
      *(_BYTE *)(ext_hdl + 24465) = a3 & 1;
      wlan_objmgr_vdev_release_ref(v15, 2u, dword_5F91, v18, v19, v20, v21, v22, v23, v24, v25);
      csr_update_beacon(a1);
      return 0;
    }
    wlan_objmgr_vdev_release_ref(v15, 2u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: vdev object is NULL for vdev_id %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "sme_update_beacon_country_ie",
      v5);
  }
  return 16;
}
