__int64 __fastcall wlan_get_crypto_params_from_wapi_ie(_DWORD *a1, __int64 a2, unsigned __int16 a3)
{
  __int64 ie_ptr_from_eid; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19

  qdf_mem_set(a1, 0x120u, 0);
  ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(68, a2, a3);
  if ( ie_ptr_from_eid )
  {
    result = wlan_crypto_wapiie_check(a1, ie_ptr_from_eid);
    if ( (_DWORD)result )
    {
      v24 = result;
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: WAPI IE check failed",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_get_crypto_params_from_wapi_ie");
      return v24;
    }
  }
  else
  {
    qdf_trace_msg(
      0x1Cu,
      8u,
      "%s: WAPI ie not present",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_get_crypto_params_from_wapi_ie");
    return 4;
  }
  return result;
}
