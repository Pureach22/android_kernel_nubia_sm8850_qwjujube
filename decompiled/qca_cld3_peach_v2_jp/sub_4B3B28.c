// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_4B3B28(
        __int64 a1,
        __int64 a2,
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
  int v11; // w22

  if ( !v11 )
    return dp_srng_access_start(a1, a2, a3);
  qdf_trace_msg(0x49u, 2u, (const char *)(a3 + 3957), a4, a5, a6, a7, a8, a9, a10, a11, "target_if_ndp_confirm_handler");
  _ReadStatusReg(SP_EL0);
  return 4294967274LL;
}
