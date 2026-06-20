void *__fastcall wlan_crypto_update_set_key_peer(__int64 a1, __int64 a2, unsigned __int8 a3, const void *a4)
{
  __int64 key; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  key = wlan_crypto_get_key(a1, (__int64)a4, a3);
  if ( key )
    return qdf_mem_copy((void *)(key + 16), a4, 6u);
  else
    return (void *)qdf_trace_msg(
                     0x1Cu,
                     2u,
                     "%s: crypto_key not present for key_idx %d",
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     v13,
                     v14,
                     "wlan_crypto_update_set_key_peer",
                     a3);
}
