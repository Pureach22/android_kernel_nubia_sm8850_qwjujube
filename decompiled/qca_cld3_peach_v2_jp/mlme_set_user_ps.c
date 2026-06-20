__int64 __fastcall mlme_set_user_ps(__int64 a1, __int64 a2, char a3)
{
  unsigned __int8 v4; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
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
  unsigned int v25; // w20

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( v5 )
  {
    v14 = v5;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v5, v6, v7, v8, v9, v10, v11, v12, v13);
    if ( ext_hdl )
    {
      *(_BYTE *)(ext_hdl + 24457) = a3 & 1;
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: vdev:%d user PS:%d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "mlme_set_user_ps",
        v4,
        a3 & 1);
      v25 = 0;
    }
    else
    {
      v25 = 16;
    }
    wlan_objmgr_vdev_release_ref(v14, 0x43u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
  }
  else
  {
    return 16;
  }
  return v25;
}
