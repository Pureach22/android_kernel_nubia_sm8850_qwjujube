__int64 __fastcall wlan_get_crypto_params_from_rsn_ie(_DWORD *a1, __int64 a2, unsigned __int16 a3, int *a4)
{
  unsigned __int8 *rsn_data_from_ie_ptr; // x0
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

  qdf_mem_set(a1, 0x120u, 0);
  rsn_data_from_ie_ptr = (unsigned __int8 *)wlan_get_rsn_data_from_ie_ptr(a2, a3);
  if ( rsn_data_from_ie_ptr )
  {
    result = wlan_crypto_rsnie_check(a1, rsn_data_from_ie_ptr, a4);
    if ( (_DWORD)result )
    {
      v26 = result;
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: RSN IE check failed",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "wlan_get_crypto_params_from_rsn_ie");
      return v26;
    }
  }
  else
  {
    qdf_trace_msg(
      0x1Cu,
      8u,
      "%s: RSN IE not present",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_get_crypto_params_from_rsn_ie");
    if ( a4 )
      *a4 = 1;
    return 4;
  }
  return result;
}
