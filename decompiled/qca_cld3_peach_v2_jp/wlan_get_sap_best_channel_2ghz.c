__int64 __fastcall wlan_get_sap_best_channel_2ghz(
        __int64 a1,
        _QWORD *a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 ext_hdl; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 v26; // [xsp+8h] [xbp-18h]

  if ( *(_DWORD *)(a1 + 16) != 1 )
    return 4;
  v26 = v12;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( ext_hdl )
  {
    v24 = ext_hdl;
    *a2 = v24 + 24540;
    *a3 = *(_BYTE *)(v24 + 24592);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev legacy private object is NULL",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wlan_get_sap_best_channel_2ghz",
      v11,
      v26);
    return 4;
  }
}
