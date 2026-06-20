__int64 __fastcall wlan_hdd_is_key_associated_with_peer(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3)
{
  __int64 key; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7

  key = wlan_crypto_get_key(a1, (__int64)a3, a2);
  if ( key )
  {
    if ( !(unsigned int)qdf_mem_cmp(a3, (const void *)(key + 16), 6u) )
      return 1;
    if ( a3 )
    {
      v21 = *a3;
      v22 = a3[1];
      v23 = a3[2];
      v24 = a3[5];
    }
    else
    {
      v23 = 0;
      v21 = 0;
      v22 = 0;
      v24 = 0;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: key is not associated, peer addr%02x:%02x:%02x:**:**:%02x",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_hdd_is_key_associated_with_peer",
      v21,
      v22,
      v23,
      v24);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Crypto KEY is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_hdd_is_key_associated_with_peer");
  }
  return 0;
}
