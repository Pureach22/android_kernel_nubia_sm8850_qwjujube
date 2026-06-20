__int64 __fastcall wlan_mlme_update_dual_sap_sta_cap(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 psoc_ext_obj_fl; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  __int64 v21; // x0
  char v22; // w8

  if ( !a1 || (v9 = *(_QWORD *)(a1 + 2800)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: target psoc info is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_mlme_update_dual_sap_sta_cap");
    return 16;
  }
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  if ( *(_BYTE *)(v9 + 1068) == 2 )
  {
    v20 = psoc_ext_obj_fl;
    v21 = mlme_get_psoc_ext_obj_fl(a1);
    if ( v21 )
      v22 = *(_BYTE *)(v21 + 3439);
    else
      v22 = 0;
    psoc_ext_obj_fl = v20;
  }
  else
  {
    v22 = 0;
  }
  *(_BYTE *)(psoc_ext_obj_fl + 3439) = v22 & 1;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: Dual SAP supported intersect value : %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wlan_mlme_update_dual_sap_sta_cap");
  return 0;
}
