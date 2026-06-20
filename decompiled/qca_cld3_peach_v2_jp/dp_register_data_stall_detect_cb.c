__int64 __fastcall dp_register_data_stall_detect_cb(
        __int64 a1,
        char a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x8

  if ( a2 || (v13 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: pdev NULL!",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_register_data_stall_detect_cb",
      v11,
      v12);
    return 4;
  }
  else
  {
    *(_QWORD *)(v13 + 95448) = a3;
    return 0;
  }
}
