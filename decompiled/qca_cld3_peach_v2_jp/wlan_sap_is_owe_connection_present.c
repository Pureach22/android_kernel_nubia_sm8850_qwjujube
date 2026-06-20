__int64 __fastcall wlan_sap_is_owe_connection_present(
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
  __int64 ext_hdl; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  char v19; // w8

  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !ext_hdl )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_sap_is_owe_connection_present");
LABEL_6:
    v19 = 1;
    return v19 & 1;
  }
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 1 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Invalid mode %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_sap_is_owe_connection_present");
    goto LABEL_6;
  }
  v19 = *(_BYTE *)(ext_hdl + 24532);
  return v19 & 1;
}
