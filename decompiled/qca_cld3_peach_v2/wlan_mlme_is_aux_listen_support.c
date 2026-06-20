__int64 __fastcall wlan_mlme_is_aux_listen_support(__int64 a1)
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
    return ((psoc_ext_obj_fl[291]
           | psoc_ext_obj_fl[288]
           | psoc_ext_obj_fl[294]
           | psoc_ext_obj_fl[297]
           | psoc_ext_obj_fl[300]
           | psoc_ext_obj_fl[303]
           | psoc_ext_obj_fl[306]
           | (unsigned int)(psoc_ext_obj_fl[309] | psoc_ext_obj_fl[312])
           | psoc_ext_obj_fl[315]
           | psoc_ext_obj_fl[318]) >> 1)
         & 1;
  qdf_trace_msg(0x68u, 2u, "%s: MLME obj is NULL", v2, v3, v4, v5, v6, v7, v8, v9, "wlan_mlme_is_aux_cap_support");
  return 0;
}
