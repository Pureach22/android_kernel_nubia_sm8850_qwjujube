__int64 __fastcall mlo_dev_mlpeer_detach(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  qdf_mutex_acquire(a1 + 1584);
  if ( a2 )
    v4 = 16 * ((unsigned int)qdf_list_remove_node(a1 + 24LL * (*(_BYTE *)(a2 + 109) & 0x3F) + 48, (_QWORD *)a2) != 0);
  else
    v4 = 16;
  qdf_mutex_release(a1 + 1584);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x is detached",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "mlo_dev_mlpeer_detach",
    *(unsigned __int8 *)(a1 + 16),
    *(unsigned __int8 *)(a2 + 104),
    *(unsigned __int8 *)(a2 + 105),
    *(unsigned __int8 *)(a2 + 106),
    *(unsigned __int8 *)(a2 + 109));
  return v4;
}
