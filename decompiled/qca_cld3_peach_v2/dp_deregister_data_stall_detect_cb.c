__int64 __fastcall dp_deregister_data_stall_detect_cb(
        __int64 a1,
        char a2,
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
  __int64 v12; // x8

  if ( a2 || (v12 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: pdev NULL!",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_deregister_data_stall_detect_cb",
      v10,
      v11);
    return 4;
  }
  else
  {
    *(_QWORD *)(v12 + 96344) = 0;
    return 0;
  }
}
