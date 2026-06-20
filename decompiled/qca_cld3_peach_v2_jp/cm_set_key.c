__int64 __fastcall cm_set_key(__int64 *a1, unsigned int a2, unsigned int a3, const void *a4)
{
  unsigned __int8 default_key_idx; // w22
  unsigned int cipher; // w0
  __int64 key; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  default_key_idx = a3;
  cipher = wlan_crypto_get_cipher(*a1, (__int64)a4, a2, a3);
  if ( cipher > 0x10 || ((1 << cipher) & 0x18001) == 0 )
  {
    if ( wlan_crypto_get_key(*a1, (__int64)a4, default_key_idx) )
      return wlan_crypto_set_key_req(*a1, v10, v11, v12, v13, v14, v15, v16, v17);
  }
  else
  {
    default_key_idx = wlan_crypto_get_default_key_idx(*a1, 0);
    key = wlan_crypto_get_key(*a1, (__int64)a4, default_key_idx);
    if ( key )
    {
      qdf_mem_copy((void *)(key + 16), a4, 6u);
      return wlan_crypto_set_key_req(*a1, v10, v11, v12, v13, v14, v15, v16, v17);
    }
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: NULL crypto key at index=%d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "cm_set_key",
    default_key_idx);
  return 29;
}
