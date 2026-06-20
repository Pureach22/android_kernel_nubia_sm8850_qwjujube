__int64 __fastcall hdd_get_roam_stats_individual_record_len(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 v11; // x4
  int v12; // w8
  int v13; // w9

  if ( a1 )
  {
    v10 = a1 + 1840LL * a2;
    v11 = *(unsigned int *)(v10 + 8);
    if ( (unsigned int)v11 < 0x10 && ((0xB7BFu >> v11) & 1) != 0 )
    {
      v12 = dword_A08DF8[v11];
      if ( !*(_BYTE *)(v10 + 52) )
        return v12 + 28 * (unsigned int)*(unsigned __int8 *)(v10 + 64) + 1744;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid invoke reason received: %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "hdd_convert_roam_trigger_reason");
      v12 = 36;
      if ( !*(_BYTE *)(v10 + 52) )
        return v12 + 28 * (unsigned int)*(unsigned __int8 *)(v10 + 64) + 1744;
    }
    if ( *(_DWORD *)(v10 + 40) )
      v13 = 40;
    else
      v13 = 8;
    v12 += v13;
    return v12 + 28 * (unsigned int)*(unsigned __int8 *)(v10 + 64) + 1744;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: invalid param",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_get_roam_stats_individual_record_len");
  return 0;
}
