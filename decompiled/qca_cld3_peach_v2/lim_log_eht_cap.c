__int64 __fastcall lim_log_eht_cap(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _BYTE *a10)
{
  __int64 result; // x0

  if ( *a10 )
  {
    qdf_trace_msg(0x35u, 8u, "EHT Capabilities:", a1, a2, a3, a4, a5, a6, a7, a8);
    return ((__int64 (__fastcall *)(__int64, __int64, _BYTE *, __int64))qdf_trace_hex_dump)(53, 8, a10, 92);
  }
  return result;
}
