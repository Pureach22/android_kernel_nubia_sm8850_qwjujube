__int64 __fastcall sub_21EB74(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6)
{
  __asm { FMLAL           V6.1D, V25.1S, V31.1S }
  return _cam_isp_ctx_unlink_in_ready(a1, a2, a3, a4, a5, a6, _D6);
}
