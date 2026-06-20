__int64 __fastcall dp_txrx_register_pause_cb(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a1 && a2 )
  {
    *(_QWORD *)(a1 + 12872) = a2;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: soc or pause_cb is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_txrx_register_pause_cb",
      v10,
      v11);
    return 4;
  }
}
