__int64 __fastcall tgt_p2p_unregister_ap_assist_bmiss_ev_handler(__int64 a1, __int64 a2)
{
  __int64 v2; // x29
  __int64 v3; // x30
  __int64 v4; // x8
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w19
  __int64 v16; // [xsp+8h] [xbp-18h]

  v4 = *(_QWORD *)(a1 + 2128);
  if ( v4 == -144 )
    return 16;
  v16 = v3;
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(v4 + 224);
  if ( !v5 )
    return 16;
  if ( *((_DWORD *)v5 - 1) != -770124015 )
    __break(0x8228u);
  result = v5(a1, a2);
  if ( (_DWORD)result )
  {
    v15 = result;
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: unreg ap assist bmiss event status %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "tgt_p2p_unregister_ap_assist_bmiss_ev_handler",
      (unsigned int)result,
      v2,
      v16);
    return v15;
  }
  return result;
}
