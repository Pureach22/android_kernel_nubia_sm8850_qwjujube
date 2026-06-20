__int64 __fastcall cds_set_driver_state(
        __int64 result,
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

  if ( !gp_cds_context )
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s: global cds context is NULL: %x",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "cds_set_driver_state",
             (unsigned int)result,
             v9,
             v10);
  *(_DWORD *)(gp_cds_context + 16) |= result;
  return result;
}
