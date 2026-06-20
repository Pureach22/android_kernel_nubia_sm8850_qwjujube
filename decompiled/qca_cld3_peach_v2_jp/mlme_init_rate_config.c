__int64 __fastcall mlme_init_rate_config(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  _QWORD *v11; // x8

  v11 = *(_QWORD **)(a1 + 520);
  if ( v11 )
  {
    v11[2964] = 12;
    v11[2965] = 0;
    v11[2969] = 8;
    v11[2970] = 0;
    v11[2974] = 16;
    v11[2975] = 0;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlme_init_rate_config",
      v9,
      v10);
    return 16;
  }
}
