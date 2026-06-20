__int64 __fastcall hdd_indicate_ese_bcn_report_no_results(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int16 a10,
        char a11,
        unsigned __int8 a12)
{
  __int64 result; // x0
  char s[256]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v17; // [xsp+108h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: CCXBCNREP=%d %d %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "hdd_indicate_ese_bcn_report_no_results",
    a10,
    a11 & 1,
    a12);
  result = snprintf(s, 0x100u, "CCXBCNREP=%d %d %d", a10, a11 & 1, a12);
  _ReadStatusReg(SP_EL0);
  return result;
}
