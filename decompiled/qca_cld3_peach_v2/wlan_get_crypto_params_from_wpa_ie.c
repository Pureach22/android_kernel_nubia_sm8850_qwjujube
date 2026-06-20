__int64 __fastcall wlan_get_crypto_params_from_wpa_ie(void *a1, __int64 a2, unsigned int a3, int *a4)
{
  __int64 vendor_ie_ptr_from_oui; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w19
  int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_mem_set(a1, 0x120u, 0);
  v27 = 32657408;
  vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&v27, 4, a2, a3);
  if ( vendor_ie_ptr_from_oui )
  {
    result = wlan_crypto_wpaie_check((__int64)a1, vendor_ie_ptr_from_oui, a4);
    if ( (_DWORD)result )
    {
      v26 = result;
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: WPA IE check failed",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "wlan_get_crypto_params_from_wpa_ie");
      result = v26;
    }
  }
  else
  {
    qdf_trace_msg(
      0x1Cu,
      8u,
      "%s: WPA IE not present",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_get_crypto_params_from_wpa_ie");
    result = 4;
    if ( a4 )
      *a4 = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
