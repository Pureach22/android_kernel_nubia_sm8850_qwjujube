__int64 __fastcall hdd_tx_pb_convert_status_reg_to_nl(
        unsigned int a1,
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
  unsigned int v11; // w4

  v11 = a1;
  if ( a1 >= 3 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: TPB: Invalid status: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_tx_pb_convert_status_reg_to_nl",
      a1,
      v9,
      v10);
    return 0;
  }
  return v11;
}
