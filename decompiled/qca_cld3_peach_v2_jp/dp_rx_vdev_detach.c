__int64 __fastcall dp_rx_vdev_detach(__int64 a1)
{
  __int64 (__fastcall *v1)(__int64, __int64); // x8
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x4
  unsigned int v15; // w19

  v1 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 192);
  if ( !v1 )
    return 0;
  v3 = *(_QWORD *)(a1 + 88);
  v4 = *(unsigned __int8 *)(a1 + 59);
  if ( *((_DWORD *)v1 - 1) != -1972642151 )
    __break(0x8228u);
  result = v1(v3, v4);
  if ( (_DWORD)result )
  {
    v14 = *(unsigned __int8 *)(a1 + 59);
    v15 = result;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to flush rx pkts for vdev %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "dp_rx_vdev_detach",
      v14);
    return v15;
  }
  return result;
}
