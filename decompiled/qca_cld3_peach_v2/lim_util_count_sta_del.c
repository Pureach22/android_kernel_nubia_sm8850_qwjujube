__int64 __fastcall lim_util_count_sta_del(
        __int64 result,
        _WORD *a2,
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
  __int16 v11; // w8

  if ( a2 && (*a2 & 0x201) == 0x200 )
  {
    *a2 &= 0xFDFEu;
    if ( *(_WORD *)(result + 3994) )
    {
      v11 = *(_WORD *)(result + 3994) - 1;
      *(_WORD *)(result + 3994) = v11;
      if ( !v11 && !*(_DWORD *)(*(_QWORD *)(result + 8) + 5672LL) )
        return sch_edca_profile_update(result, a3, 0);
    }
    else
    {
      return qdf_trace_msg(
               0x35u,
               2u,
               "%s: CountStaDel: ignoring Delete Req when AniPeer count: %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_util_count_sta_del",
               0);
    }
  }
  return result;
}
