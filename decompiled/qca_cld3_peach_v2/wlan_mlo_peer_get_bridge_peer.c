__int64 __fastcall wlan_mlo_peer_get_bridge_peer(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 *v10; // x8
  __int64 v11; // x20
  __int64 v12; // x8
  __int64 *v13; // x8

  if ( !a1 )
    return 0;
  qdf_mutex_acquire(a1 + 120);
  v10 = (__int64 *)(a1 + 16);
  if ( a1 != -16 && (v11 = *v10) != 0 && *(_DWORD *)(v11 + 68) == 13 )
  {
    v12 = 16;
  }
  else
  {
    v13 = (__int64 *)(a1 + 56);
    if ( a1 == -56 )
      goto LABEL_12;
    v11 = *v13;
    if ( !*v13 )
      goto LABEL_13;
    if ( *(_DWORD *)(v11 + 68) != 13 )
    {
LABEL_12:
      v11 = 0;
      goto LABEL_13;
    }
    v12 = 56;
  }
  if ( (*(_BYTE *)(a1 + v12 + 15) & 1) == 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Bridge peer is not primary",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_mlo_peer_get_bridge_peer");
    goto LABEL_12;
  }
LABEL_13:
  qdf_mutex_release(a1 + 120);
  return v11;
}
