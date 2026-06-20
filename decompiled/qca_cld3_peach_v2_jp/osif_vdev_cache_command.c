__int64 __fastcall osif_vdev_cache_command(__int64 a1, unsigned __int8 a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  dsc_vdev_cache_command(*(_QWORD *)(a1 + 8), a2);
  return qdf_trace_msg(
           0x48u,
           8u,
           "%s: Set cache cmd to %d",
           v3,
           v4,
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           "osif_vdev_cache_command",
           a2);
}
