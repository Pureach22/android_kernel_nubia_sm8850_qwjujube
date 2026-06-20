__int64 __fastcall wlan_crypto_check_wpa_match(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        void *a5,
        int *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v18; // x0
  __int64 v19; // x20
  unsigned int crypto_params_from_wpa_ie; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w19
  const char *v30; // x2

  if ( a1 )
  {
    v18 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 19);
    if ( v18 )
    {
      v19 = v18;
      crypto_params_from_wpa_ie = wlan_get_crypto_params_from_wpa_ie(a5, a3, a4, a6);
      if ( crypto_params_from_wpa_ie )
      {
        v29 = crypto_params_from_wpa_ie;
        qdf_trace_msg(
          0x1Cu,
          2u,
          "%s: get crypto prarams from WPA IE failed",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "wlan_crypto_check_wpa_match");
      }
      else if ( (wlan_crypto_rsn_info(v19, (__int64)a5, a6) & 1) != 0 )
      {
        v29 = 0;
      }
      else
      {
        v29 = 16;
      }
      wlan_objmgr_vdev_release_ref(v19, 19);
      return v29;
    }
    v30 = "%s: vdev is NULL";
  }
  else
  {
    v30 = "%s: PSOC is NULL";
  }
  qdf_trace_msg(0x1Cu, 2u, v30, a7, a8, a9, a10, a11, a12, a13, a14, "wlan_crypto_check_wpa_match");
  if ( a6 )
    *a6 = 1;
  return 29;
}
