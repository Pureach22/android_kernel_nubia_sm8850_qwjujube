__int64 __fastcall wlan_mlme_reset_sta_keepalive_period(__int64 a1, __int64 a2)
{
  __int64 psoc_ext_obj_fl; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 ext_hdl; // x0
  __int64 v22; // x20
  __int64 result; // x0
  const char *v24; // x2

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    *(_DWORD *)(psoc_ext_obj_fl + 3300) = *(_DWORD *)(cfg_psoc_get_values(a1) + 9932);
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(a2, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( ext_hdl )
    {
      v22 = ext_hdl;
      result = cfg_psoc_get_values(a1);
      *(_WORD *)(v22 + 24826) = *(_DWORD *)(result + 9932);
      return result;
    }
    v24 = "%s: vdev legacy private object is NULL";
  }
  else
  {
    v24 = "%s: invalid mlem object";
  }
  return qdf_trace_msg(0x68u, 2u, v24, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_mlme_reset_sta_keepalive_period");
}
