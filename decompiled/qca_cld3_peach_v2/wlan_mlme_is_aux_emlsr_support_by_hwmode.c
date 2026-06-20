__int64 __fastcall wlan_mlme_is_aux_emlsr_support_by_hwmode(__int64 a1, unsigned int a2)
{
  _DWORD *psoc_ext_obj_fl; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w8

  psoc_ext_obj_fl = (_DWORD *)mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    if ( a2 < 0xB )
      v12 = psoc_ext_obj_fl[3 * a2 + 288];
    else
      v12 = psoc_ext_obj_fl[291]
          | psoc_ext_obj_fl[288]
          | psoc_ext_obj_fl[294]
          | psoc_ext_obj_fl[297]
          | psoc_ext_obj_fl[300]
          | psoc_ext_obj_fl[303]
          | psoc_ext_obj_fl[306]
          | psoc_ext_obj_fl[309]
          | psoc_ext_obj_fl[312]
          | psoc_ext_obj_fl[315]
          | psoc_ext_obj_fl[318];
    return (v12 >> 2) & 1;
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: MLME obj is NULL", v4, v5, v6, v7, v8, v9, v10, v11, "wlan_mlme_is_aux_cap_support");
    return 0;
  }
}
