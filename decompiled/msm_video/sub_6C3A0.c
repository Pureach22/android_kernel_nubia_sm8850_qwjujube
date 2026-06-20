__int64 __fastcall sub_6C3A0(
        long double a1,
        long double a2,
        long double a3,
        long double a4,
        long double a5,
        long double a6,
        long double a7,
        long double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        _WORD *a16)
{
  HIWORD(a7) = *a16;
  HIWORD(a8) = a16[1];
  return msm_v4l2_try_encoder_cmd(a1, a2, a3, a4, a5, a6, a7, a8);
}
