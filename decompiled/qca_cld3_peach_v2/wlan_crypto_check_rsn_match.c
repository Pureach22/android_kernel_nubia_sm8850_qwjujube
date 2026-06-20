__int64 __fastcall wlan_crypto_check_rsn_match(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned __int16 a4,
        _DWORD *a5,
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
  unsigned __int8 *rsn_data_from_ie_ptr; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w20
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v47; // x2
  __int64 v48; // x0
  __int64 v49; // x22

  if ( a1 )
  {
    qdf_mem_set(a5, 0x120u, 0);
    rsn_data_from_ie_ptr = (unsigned __int8 *)wlan_get_rsn_data_from_ie_ptr(a3, a4);
    if ( !rsn_data_from_ie_ptr )
    {
      qdf_trace_msg(
        0x1Cu,
        8u,
        "%s: RSN IE not present",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "wlan_get_crypto_params_from_rsn_ie");
      v38 = 4;
      if ( a6 )
        *a6 = 1;
      goto LABEL_16;
    }
    v29 = wlan_crypto_rsnie_check(a5, rsn_data_from_ie_ptr, a6);
    if ( v29 )
    {
      v38 = v29;
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: RSN IE check failed",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "wlan_get_crypto_params_from_rsn_ie");
LABEL_16:
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: get crypto prarams from RSN IE failed",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "wlan_crypto_check_rsn_match");
      return v38;
    }
    v48 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 19);
    if ( v48 )
    {
      v49 = v48;
      if ( (wlan_crypto_rsn_info(v48, (__int64)a5, a6) & 1) != 0 )
        v38 = 0;
      else
        v38 = 16;
      wlan_objmgr_vdev_release_ref(v49, 19);
      return v38;
    }
    v47 = "%s: vdev is NULL";
  }
  else
  {
    v47 = "%s: PSOC is NULL";
  }
  qdf_trace_msg(0x1Cu, 2u, v47, a7, a8, a9, a10, a11, a12, a13, a14, "wlan_crypto_check_rsn_match");
  v38 = 29;
  if ( a6 )
    *a6 = 1;
  return v38;
}
