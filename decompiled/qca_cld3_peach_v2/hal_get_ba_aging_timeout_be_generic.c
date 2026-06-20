__int64 __fastcall hal_get_ba_aging_timeout_be_generic(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0

  if ( a2 > 1u )
  {
    if ( a2 == 2 )
    {
      result = ((__int64 (*)(__int64, const char *, ...))hal_read32_mb_1)(a1, "on_present_for_given_peer");
      goto LABEL_11;
    }
    if ( a2 == 3 )
    {
      result = ((__int64 (*)(__int64, const char *, ...))hal_read32_mb_1)(a1, "resent_for_given_peer");
      goto LABEL_11;
    }
    return qdf_trace_msg(0x45u, 2u, "Invalid AC: %d\n", a4, a5, a6, a7, a8, a9, a10, a11, a2);
  }
  if ( !a2 )
  {
    result = ((__int64 (*)(__int64, const char *, ...))hal_read32_mb_1)(a1, "wt_session_present_for_given_peer");
    goto LABEL_11;
  }
  if ( a2 != 1 )
    return qdf_trace_msg(0x45u, 2u, "Invalid AC: %d\n", a4, a5, a6, a7, a8, a9, a10, a11, a2);
  result = ((__int64 (*)(__int64, const char *, ...))hal_read32_mb_1)(a1, "ession_present_for_given_peer");
LABEL_11:
  *a3 = (unsigned int)result / 0x3E8;
  return result;
}
