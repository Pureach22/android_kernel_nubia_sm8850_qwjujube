__int64 __fastcall extract_peer_stats_count_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _DWORD *a10,
        __int64 a11)
{
  unsigned int v11; // w4
  unsigned int v12; // w9
  __int64 v13; // x20

  if ( !a10 || !*(_QWORD *)a10 )
    return 16;
  v11 = a10[6];
  if ( v11 && (v12 = *(_DWORD *)(*(_QWORD *)a10 + 8LL), v11 >= v12) )
  {
    if ( a11 )
    {
      *(_DWORD *)(a11 + 56) = v12;
      return 0;
    }
    else
    {
      return 16;
    }
  }
  else
  {
    v13 = jiffies;
    if ( extract_peer_stats_count_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: actual num of peers stats info: %d is less than provided peers: %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_peer_stats_count_tlv");
      extract_peer_stats_count_tlv___last_ticks = v13;
    }
    return 5;
  }
}
