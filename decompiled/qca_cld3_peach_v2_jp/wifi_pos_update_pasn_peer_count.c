__int64 __fastcall wifi_pos_update_pasn_peer_count(__int64 a1, char a2)
{
  __int64 vdev_priv_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  char v12; // w10
  unsigned __int8 v14; // w9
  __int64 v15; // x4

  vdev_priv_obj = wifi_pos_get_vdev_priv_obj(a1);
  if ( !vdev_priv_obj )
    return qdf_trace_msg(
             0x25u,
             2u,
             "%s: Wifi pos vdev priv obj is null",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "wifi_pos_update_pasn_peer_count");
  if ( (a2 & 1) != 0 )
  {
    v12 = 1;
  }
  else
  {
    if ( !*(_BYTE *)(vdev_priv_obj + 12264) )
    {
      v15 = 0;
      return qdf_trace_msg(
               0x25u,
               8u,
               "%s: Pasn peer count:%d",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "wifi_pos_update_pasn_peer_count",
               v15);
    }
    v12 = -1;
  }
  v14 = *(_BYTE *)(vdev_priv_obj + 12264) + v12;
  *(_BYTE *)(vdev_priv_obj + 12264) = v14;
  v15 = v14;
  return qdf_trace_msg(
           0x25u,
           8u,
           "%s: Pasn peer count:%d",
           v4,
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           "wifi_pos_update_pasn_peer_count",
           v15);
}
