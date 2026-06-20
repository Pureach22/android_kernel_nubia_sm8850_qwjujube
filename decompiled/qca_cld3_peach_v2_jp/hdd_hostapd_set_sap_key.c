__int64 __fastcall hdd_hostapd_set_sap_key(__int64 a1)
{
  unsigned int i; // w20
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x23
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  for ( i = 0; i != 8; ++i )
  {
    result = wlan_crypto_get_key(*(_QWORD *)(*(_QWORD *)(a1 + 52824) + 32LL), 0, i);
    if ( result )
    {
      v12 = result;
      qdf_trace_msg(0x33u, 8u, "%s: key idx %d", v4, v5, v6, v7, v8, v9, v10, v11, "hdd_hostapd_set_sap_key", i);
      ucfg_crypto_set_key_req(*(_QWORD *)(*(_QWORD *)(a1 + 52824) + 32LL), v13, v14, v15, v16, v17, v18, v19, v20);
      result = wma_update_set_key(
                 *(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL),
                 0,
                 i,
                 0,
                 *(unsigned int *)(v12 + 8));
    }
  }
  return result;
}
