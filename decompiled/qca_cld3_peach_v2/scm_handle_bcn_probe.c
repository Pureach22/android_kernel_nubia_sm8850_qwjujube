__int64 __fastcall scm_handle_bcn_probe(
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
  if ( a1 )
    return _scm_handle_bcn_probe(*(unsigned int **)(a1 + 8));
  qdf_trace_msg(0x15u, 2u, "%s: msg is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "scm_handle_bcn_probe");
  return 29;
}
