__int64 __fastcall mlme_get_c2c_support(__int64 a1, _BYTE *a2)
{
  __int64 ext_hdl; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8

  ext_hdl = wlan_psoc_mlme_get_ext_hdl(a1);
  if ( ext_hdl )
  {
    v12 = ext_hdl;
    *a2 = *(_BYTE *)(v12 + 6393);
    return 0;
  }
  else
  {
    *a2 = 0;
    qdf_trace_msg(0x68u, 2u, "%s: Failed to get MLME Obj", v4, v5, v6, v7, v8, v9, v10, v11, "mlme_get_c2c_support");
    return 4;
  }
}
