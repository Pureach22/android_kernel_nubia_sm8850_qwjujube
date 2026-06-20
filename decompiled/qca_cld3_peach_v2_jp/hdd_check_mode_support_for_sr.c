__int64 __fastcall hdd_check_mode_support_for_sr(__int64 a1, char a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  bool is_vdev_connected; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // [xsp+8h] [xbp-18h]

  if ( *(_DWORD *)(a1 + 40) )
    return 1;
  v16 = v3;
  is_vdev_connected = hdd_cm_is_vdev_connected(*(_DWORD **)(a1 + 52824));
  if ( (a2 & 0xA) != 2 && is_vdev_connected )
    return 1;
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: mode %d doesn't supports SR",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "hdd_check_mode_support_for_sr",
    *(unsigned int *)(a1 + 40),
    v2,
    v16);
  return 0;
}
