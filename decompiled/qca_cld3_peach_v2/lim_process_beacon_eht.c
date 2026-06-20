__int64 __fastcall lim_process_beacon_eht(
        __int64 result,
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
  __int64 v11; // x8
  __int64 v13; // x9
  __int64 v14; // x19

  if ( !result || !a2 || !a3 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: invalid input parameters",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_process_beacon_eht");
  v11 = *(_QWORD *)(a2 + 16);
  if ( v11
    && !*(_DWORD *)(v11 + 16)
    && *(_DWORD *)(a2 + 24) == *(_DWORD *)(a3 + 1183)
    && *(unsigned __int16 *)(a2 + 28) == *(unsigned __int16 *)(a3 + 1187) )
  {
    v13 = *(_QWORD *)(v11 + 40);
    if ( v13 )
    {
      if ( (unsigned int)(*(_DWORD *)(v13 + 28) - 31) <= 9 )
      {
        v14 = result;
        result = mlo_is_mld_sta(*(_QWORD *)(a2 + 16));
        if ( (result & 1) != 0 )
          return ((__int64 (__fastcall *)(__int64, __int64, __int64))lim_process_beacon_mlo)(v14, a2, a3);
      }
    }
  }
  return result;
}
