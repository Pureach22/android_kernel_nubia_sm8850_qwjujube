__int64 __fastcall wma_smps_mode_to_force_mode_param(
        unsigned __int8 a1,
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

  switch ( a1 )
  {
    case 0u:
      return 2;
    case 3u:
      return 1;
    case 1u:
      return 3;
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: smps mode cannot be mapped :%d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wma_smps_mode_to_force_mode_param",
    a1,
    v9,
    v10);
  return 4294967274LL;
}
