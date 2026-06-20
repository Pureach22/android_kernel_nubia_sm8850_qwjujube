__int64 __fastcall tgt_p2p_unregister_noa_ev_handler(__int64 a1)
{
  __int64 v1; // x29
  __int64 v2; // x30
  __int64 v3; // x8
  _DWORD *v4; // x8
  unsigned int v5; // w19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v15; // [xsp+8h] [xbp-18h]

  v3 = *(_QWORD *)(a1 + 2128);
  if ( v3 == -144 )
    return 16;
  v4 = *(_DWORD **)(v3 + 200);
  if ( !v4 )
    return 16;
  v15 = v2;
  if ( *(v4 - 1) != -1796695762 )
    __break(0x8228u);
  v5 = ((__int64 (__fastcall *)(__int64, _QWORD))v4)(a1, 0);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: unregister noa event, status:%d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "tgt_p2p_unregister_noa_ev_handler",
    v5,
    v1,
    v15);
  return v5;
}
