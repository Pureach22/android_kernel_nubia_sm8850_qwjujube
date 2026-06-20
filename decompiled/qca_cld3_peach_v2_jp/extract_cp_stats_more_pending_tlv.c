__int64 __fastcall extract_cp_stats_more_pending_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _DWORD *a11)
{
  __int64 v12; // x20

  if ( a10 )
  {
    *a11 = *(_DWORD *)(*(_QWORD *)a10 + 8LL);
    return 0;
  }
  else
  {
    v12 = jiffies;
    if ( extract_cp_stats_more_pending_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: param_buf is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_cp_stats_more_pending_tlv");
      extract_cp_stats_more_pending_tlv___last_ticks = v12;
    }
    return 16;
  }
}
