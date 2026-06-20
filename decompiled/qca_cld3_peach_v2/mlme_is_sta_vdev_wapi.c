void __fastcall mlme_is_sta_vdev_wapi(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  int param; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // [xsp+8h] [xbp-18h]

  if ( (*a3 & 1) == 0 && !*(_DWORD *)(a2 + 16) )
  {
    v16 = v4;
    if ( !(unsigned int)wlan_vdev_is_up() )
    {
      param = wlan_crypto_get_param(a2, 7u);
      if ( (param & 0x80000000) == 0 && (param & 0x3000) != 0 )
      {
        *a3 = 1;
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: wapi exist for Vdev: %d",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "mlme_is_sta_vdev_wapi",
          *(unsigned __int8 *)(a2 + 168),
          v3,
          v16);
      }
    }
  }
}
