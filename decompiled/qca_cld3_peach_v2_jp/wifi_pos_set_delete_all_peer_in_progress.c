__int64 __fastcall wifi_pos_set_delete_all_peer_in_progress(__int64 a1, char a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = wifi_pos_get_vdev_priv_obj(a1);
  if ( !result )
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
             "wifi_pos_set_delete_all_peer_in_progress");
  *(_BYTE *)(result + 12265) = a2 & 1;
  return result;
}
