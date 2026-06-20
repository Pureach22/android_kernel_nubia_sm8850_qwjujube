__int64 __fastcall extract_per_chain_rssi_stats_tlv(
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
        unsigned int a11,
        unsigned int *a12)
{
  __int64 v12; // x8
  __int64 v13; // x8
  unsigned int v14; // w9
  __int64 v16; // x20
  void *v18; // x19

  if ( a10 )
  {
    v12 = *(_QWORD *)(a10 + 32);
    if ( *(_DWORD *)(v12 + 4) <= a11 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid index: %u",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_per_chain_rssi_stats_tlv",
        a11);
      return 4;
    }
    else
    {
      v13 = v12 + 80LL * a11;
      v14 = *(_DWORD *)(v13 + 16);
      if ( v14 <= 5 )
      {
        v16 = v13 + 12;
        *a12 = v14;
        v18 = a12 + 17;
        qdf_mem_copy(a12 + 1, (const void *)(v13 + 20), 0x20u);
        qdf_mem_copy(a12 + 9, (const void *)(v16 + 40), 0x20u);
        qdf_mem_copy(v18, (const void *)(v16 + 72), 8u);
        return 0;
      }
      else
      {
        return 4;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: evt_buf is null", a1, a2, a3, a4, a5, a6, a7, a8, "extract_per_chain_rssi_stats_tlv");
    return 29;
  }
}
