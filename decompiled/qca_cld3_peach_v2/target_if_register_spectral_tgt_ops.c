__int64 __fastcall target_if_register_spectral_tgt_ops(
        __int64 a1,
        __int64 *a2,
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

  if ( a1 )
  {
    ops_tgt = *a2;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: psoc is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_register_spectral_tgt_ops",
      v10,
      v11);
    return 4;
  }
}
