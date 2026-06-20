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
  __int64 psoc_ext_obj_fl; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  if ( a1 && *(_QWORD *)(a1 + 2800) )
  {
    psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
    if ( psoc_ext_obj_fl )
    {
      *(_BYTE *)(psoc_ext_obj_fl + 3239) = 0;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Dual SAP supported intersect value : %d",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "wlan_mlme_update_dual_sap_sta_cap",
        0);
      return 0;
    }
  }
  else
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
  }
  return 16;
}
