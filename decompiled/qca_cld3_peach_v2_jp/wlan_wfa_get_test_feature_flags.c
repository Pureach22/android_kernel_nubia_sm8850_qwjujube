__int64 __fastcall wlan_wfa_get_test_feature_flags(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 ext_hdl; // x0
  int v12; // w8
  const char *v13; // x2

  if ( !a1 )
  {
    v13 = "%s: psoc object is NULL";
LABEL_8:
    qdf_trace_msg(0x1Fu, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_wfa_get_test_feature_flags");
LABEL_10:
    LOBYTE(v12) = 0;
    return v12 & 1;
  }
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(a1);
  if ( !ext_hdl )
  {
    v13 = "%s: psoc legacy private object is NULL";
    goto LABEL_8;
  }
  if ( a2 != 1 )
  {
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: Invalid feature flag: 0x%x",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_wfa_get_test_feature_flags",
      a2);
    goto LABEL_10;
  }
  v12 = *(_DWORD *)(ext_hdl + 7424);
  if ( (v12 & 1) != 0 )
  {
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: IGNORE_RSNXE is set",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_wfa_get_test_feature_flags");
    LOBYTE(v12) = 1;
  }
  return v12 & 1;
}
