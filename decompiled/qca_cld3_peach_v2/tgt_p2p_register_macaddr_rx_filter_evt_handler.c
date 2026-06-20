__int64 __fastcall tgt_p2p_register_macaddr_rx_filter_evt_handler(__int64 a1, char a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  __int64 v4; // x8
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  __int64 v7; // x1
  unsigned int v8; // w19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v18; // [xsp+8h] [xbp-18h]

  v4 = *(_QWORD *)(a1 + 2128);
  if ( v4 == -144 )
    return 16;
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(v4 + 208);
  if ( !v5 )
    return 16;
  v18 = v3;
  v7 = a2 & 1;
  if ( *((_DWORD *)v5 - 1) != -132374536 )
    __break(0x8228u);
  v8 = v5(a1, v7);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: register mac addr rx filter event,  register %d status:%d",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "tgt_p2p_register_macaddr_rx_filter_evt_handler",
    a2 & 1,
    v8,
    v2,
    v18);
  return v8;
}
