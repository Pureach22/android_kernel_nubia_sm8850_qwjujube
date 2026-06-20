__int64 __fastcall wlan_mlme_is_aux_scan_support(__int64 a1)
{
  _DWORD *psoc_ext_obj_fl; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  psoc_ext_obj_fl = (_DWORD *)mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
    return (psoc_ext_obj_fl[286]
          | psoc_ext_obj_fl[283]
          | psoc_ext_obj_fl[289]
          | psoc_ext_obj_fl[292]
          | psoc_ext_obj_fl[295]
          | psoc_ext_obj_fl[298]
          | psoc_ext_obj_fl[301]
          | psoc_ext_obj_fl[304]
          | psoc_ext_obj_fl[307]
          | psoc_ext_obj_fl[310]
          | psoc_ext_obj_fl[313])
         & 1;
  qdf_trace_msg(0x68u, 2u, "%s: MLME obj is NULL", v2, v3, v4, v5, v6, v7, v8, v9, "wlan_mlme_is_aux_cap_support");
  return 0;
}
