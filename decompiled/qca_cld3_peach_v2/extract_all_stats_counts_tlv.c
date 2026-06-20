__int64 __fastcall extract_all_stats_counts_tlv(__int64 a1, __int64 a2, _DWORD *a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x8
  _DWORD *v16; // x22
  unsigned int v17; // w11
  int v18; // w12
  bool v19; // cc
  __int64 v20; // x1
  __int64 (__fastcall *v21)(__int64, __int64); // x9
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w4
  __int64 v31; // x20
  int v32; // w8

  qdf_mem_set(a3, 0x48u, 0);
  v14 = *(_DWORD **)a2;
  if ( !*(_QWORD *)a2 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: event fixed param NULL",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "extract_all_stats_counts_tlv");
    return 16;
  }
  if ( *(_DWORD *)(a2 + 24) > 0x5C0u )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: num_data : %u is invalid",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "extract_all_stats_counts_tlv");
    return 5;
  }
  v16 = *(_DWORD **)(a2 + 32);
  v17 = 1;
  do
  {
    v18 = v14[1] & v17;
    if ( v18 > 2047 )
    {
      if ( v18 < 0x10000 )
      {
        switch ( v18 )
        {
          case 0x800:
            goto LABEL_9;
          case 0x2000:
            v18 = 0x4000;
LABEL_9:
            *a3 |= v18;
            break;
          case 0x8000:
            goto LABEL_9;
        }
      }
      else if ( v18 >= 0x40000 )
      {
        if ( v18 == 0x40000 || v18 == 0x80000 )
          goto LABEL_9;
      }
      else if ( v18 == 0x10000 || v18 == 0x20000 )
      {
        goto LABEL_9;
      }
    }
    else if ( (unsigned int)v18 <= 0x20 && ((1LL << v18) & 0x100010116LL) != 0 || v18 == 1024 )
    {
      goto LABEL_9;
    }
    v19 = v17 > 0x40000;
    v17 *= 2;
  }
  while ( !v19 );
  if ( 240LL * (unsigned int)v14[2]
     + 164LL * (unsigned int)v14[3]
     + 24LL * (unsigned int)v14[5]
     + 160LL * (unsigned int)v14[7]
     + 20 * ((unsigned int)v14[6] + (unsigned __int64)(unsigned int)v14[4])
     + 12LL * (unsigned int)v14[9]
     + 44LL * (unsigned int)v14[10]
     + 60LL * (unsigned int)v14[13] == *(_DWORD *)(a2 + 24) )
  {
    a3[17] = v14[12];
    a3[1] = v14[2];
    a3[2] = *(_DWORD *)(a2 + 136);
    a3[3] = v14[3];
    a3[4] = v14[4];
    a3[5] = v14[10];
    a3[6] = v14[5];
    a3[7] = v14[6];
    a3[12] = v14[7];
    a3[13] = v14[13];
    a3[9] = v14[9];
    a3[16] = *(_DWORD *)(a2 + 168);
    v20 = (unsigned int)v14[8];
    v21 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3688LL);
    if ( *((_DWORD *)v21 - 1) != -2112860426 )
      __break(0x8229u);
    a3[8] = v21(a1, v20);
    if ( !*(_QWORD *)(a2 + 32) || !*(_DWORD *)(a2 + 40) || *v16 != 35651588 )
      return 0;
    v30 = v16[1];
    if ( v30 >= 4 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: num_per_chain_rssi_stats:%u is out of bounds",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "extract_all_stats_counts_tlv");
      return 4;
    }
    a3[10] = v30;
    if ( *(_QWORD *)(a2 + 112) )
      a3[15] = *(_DWORD *)(a2 + 120);
    v32 = *(_DWORD *)(a2 + 88);
    if ( v32 )
    {
      a3[11] = v32;
      return 0;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v31 = jiffies;
    if ( extract_all_stats_counts_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: data len: %u isn't same as calculated: %llu",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "extract_all_stats_counts_tlv");
      extract_all_stats_counts_tlv___last_ticks = v31;
    }
    return 5;
  }
}
