__int64 __fastcall extract_twt_session_stats_event_tlv(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 (*v13)(void); // x9
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( a2 )
  {
    v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3688LL);
    if ( *((_DWORD *)v13 - 1) != -2112860426 )
      __break(0x8229u);
    v14 = v13();
    *a3 = v14;
    a3[1] = *(_DWORD *)(a2 + 24);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: pdev_id=%d, num of TWT sessions=%d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "extract_twt_session_stats_event_tlv",
      v14);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: evt_buf is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_twt_session_stats_event_tlv");
    return 4;
  }
}
