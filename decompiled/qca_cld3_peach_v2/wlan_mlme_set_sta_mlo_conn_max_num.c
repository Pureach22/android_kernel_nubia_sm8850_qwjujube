__int64 __fastcall wlan_mlme_set_sta_mlo_conn_max_num(__int64 a1, unsigned __int8 a2)
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
  __int64 v13; // x9
  int v14; // w8

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  if ( !a1 || (v13 = *(_QWORD *)(a1 + 2800)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: target psoc info is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_mlme_set_sta_mlo_conn_max_num");
    return 16;
  }
  LOBYTE(v14) = a2;
  if ( !a2 )
    v14 = *(_DWORD *)(v13 + 428);
  *(_BYTE *)(psoc_ext_obj_fl + 3592) = v14;
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: mlo_support_link_num user input %d intersected value :%d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "wlan_mlme_set_sta_mlo_conn_max_num",
    a2,
    (unsigned __int8)v14);
  return 0;
}
