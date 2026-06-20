__int64 __fastcall ucfg_p2p_lo_stop(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _DWORD *v20; // x8
  unsigned int v21; // w19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  qdf_trace_msg(0x4Eu, 8u, "%s: soc:%pK, vdev_id:%d", a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_p2p_lo_stop", a1, a2);
  if ( a1 )
  {
    v20 = *(_DWORD **)(*(_QWORD *)(a1 + 2128) + 160LL);
    if ( v20 )
    {
      if ( *(v20 - 1) != 787953853 )
        __break(0x8228u);
      v21 = ((__int64 (__fastcall *)(__int64, _QWORD))v20)(a1, a2);
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: p2p lo stop, status:%d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "ucfg_p2p_lo_stop",
        v21);
      return v21;
    }
    else
    {
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: psoc context passed is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_p2p_lo_stop");
    return 4;
  }
}
