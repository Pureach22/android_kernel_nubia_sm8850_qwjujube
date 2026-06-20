__int64 __fastcall wma_he_update_tgt_services(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x2

  if ( (wmi_service_enabled(a1, 0x72u, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    *(_BYTE *)(a2 + 42) = 1;
    wma_set_fw_wlan_feat_caps(13);
    v19 = "%s: 11ax is enabled";
  }
  else
  {
    v19 = "%s: 11ax is not enabled";
  }
  return qdf_trace_msg(0x36u, 8u, v19, v11, v12, v13, v14, v15, v16, v17, v18, "wma_he_update_tgt_services");
}
