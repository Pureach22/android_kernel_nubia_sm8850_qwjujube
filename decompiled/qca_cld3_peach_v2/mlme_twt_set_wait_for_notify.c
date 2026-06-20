__int64 __fastcall mlme_twt_set_wait_for_notify(__int64 a1, __int64 a2, char a3)
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
  __int64 v13; // x20
  __int64 ext_hdl; // x0
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

  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( v4 )
  {
    v13 = v4;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v4, v5, v6, v7, v8, v9, v10, v11, v12);
    if ( ext_hdl )
    {
      *(_BYTE *)(ext_hdl + 23832) = a3 & 1;
      return wlan_objmgr_vdev_release_ref(v13, 2u, dword_5D18, v16, v17, v18, v19, v20, v21, v22, v23);
    }
    wlan_objmgr_vdev_release_ref(v13, 2u, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    v25 = "%s: vdev legacy private object is NULL";
  }
  else
  {
    v25 = "%s: vdev object not found";
  }
  return qdf_trace_msg(0x1Fu, 2u, v25, v5, v6, v7, v8, v9, v10, v11, v12, "mlme_twt_set_wait_for_notify");
}
