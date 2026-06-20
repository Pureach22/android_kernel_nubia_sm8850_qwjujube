__int64 __fastcall sde_encoder_helper_get_jitter_bounds_ns(
        __int64 result,
        unsigned int a2,
        int a3,
        _QWORD *a4,
        _QWORD *a5)
{
  __int64 v5; // x8
  unsigned __int64 v6; // x9

  v5 = 0x3B9ACA00 / (unsigned int)result;
  v6 = (unsigned int)v5 * (unsigned __int64)a2 / (unsigned int)(100 * a3);
  *a4 = v5 - v6;
  *a5 = v6 + v5;
  return result;
}
