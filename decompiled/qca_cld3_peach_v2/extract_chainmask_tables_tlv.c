__int64 __fastcall extract_chainmask_tables_tlv(
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
        __int64 a11)
{
  __int64 v11; // x22
  unsigned int v12; // w8
  __int64 v13; // x23
  int v14; // w6
  unsigned int v16; // w5
  unsigned int v17; // w4
  __int64 v18; // x20
  __int64 result; // x0
  __int64 v20; // x20
  __int64 v21; // x3
  unsigned __int8 v22; // w24
  __int64 v23; // x25
  int v24; // w26
  __int64 v25; // x8
  __int64 v26; // x9
  unsigned int v27; // w11

  if ( !a10 )
    return 4;
  v11 = *(_QWORD *)(a10 + 16);
  if ( !v11 )
    return 4;
  v12 = *(_DWORD *)(v11 + 8);
  if ( v12 - 6 < 0xFFFFFFFB )
    return 4;
  if ( v12 > *(_DWORD *)(a10 + 104) )
    return 4;
  v13 = *(_QWORD *)(a10 + 112);
  if ( !v13 )
    return 4;
  v14 = *(_DWORD *)(a11 + 4);
  v16 = 0;
  v17 = 0;
  while ( 1 )
  {
    ++v16;
    v17 += v14;
    if ( v16 >= (unsigned __int8)*(_DWORD *)(v11 + 8) )
      break;
    v14 = *(_DWORD *)(a11 + 16LL * v16 + 4);
    if ( __CFADD__(v17, v14) )
    {
      v18 = jiffies;
      if ( extract_chainmask_tables_tlv___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: integer overflow, num_mac_phy_chainmask_caps:%d, i:%d, um_valid_chainmasks:%d",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "extract_chainmask_tables_tlv");
        extract_chainmask_tables_tlv___last_ticks = v18;
      }
      return 4;
    }
  }
  if ( v17 > *(_DWORD *)(a10 + 120) )
  {
    v20 = jiffies;
    if ( extract_chainmask_tables_tlv___last_ticks_462 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: invalid chainmask caps num, num_mac_phy_chainmask_caps:%d, param_buf->num_mac_phy_chainmask_caps:%d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_chainmask_tables_tlv");
      extract_chainmask_tables_tlv___last_ticks_462 = v20;
    }
    return 4;
  }
  v21 = 0;
  v22 = 0;
  do
  {
    qdf_trace_msg(0x31u, 8u, "Dumping chain mask combo data for table : %d", a1, a2, a3, a4, a5, a6, a7, a8, v21);
    v23 = a11 + 16LL * v22;
    if ( *(_DWORD *)(v23 + 4) )
    {
      v24 = 0;
      do
      {
        v25 = 8LL * (unsigned __int8)v24;
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25 + 4) = *(_DWORD *)(v13 + 8);
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0xFFFFFFFE
                                                | *(_DWORD *)(v13 + 4) & 1;
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0xFFFFFFFD
                                                | (2 * ((*(_DWORD *)(v13 + 4) >> 1) & 1));
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0xFFFFFFFB
                                                | (4 * ((*(_DWORD *)(v13 + 4) >> 2) & 1));
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0xFFFFFFF7
                                                | (8 * ((*(_DWORD *)(v13 + 4) >> 3) & 1));
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0xFFFFFFEF
                                                | (16 * ((*(_DWORD *)(v13 + 4) >> 4) & 1));
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0xF7FFFFFF
                                                | (((*(_DWORD *)(v13 + 4) >> 27) & 1) << 27);
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0xEFFFFFFF
                                                | (((*(_DWORD *)(v13 + 4) >> 28) & 1) << 28);
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0xDFFFFFFF
                                                | (((*(_DWORD *)(v13 + 4) >> 29) & 1) << 29);
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0xBFFFFFFF
                                                | (((*(_DWORD *)(v13 + 4) >> 30) & 1) << 30);
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(v13 + 4) & 0x80000000
                                                | *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0x7FFFFFFF;
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0xFFFFFFBF
                                                | (((*(_DWORD *)(v13 + 4) >> 5) & 1) << 6);
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0xFFFFFF7F
                                                | (((*(_DWORD *)(v13 + 4) >> 6) & 1) << 7);
        *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) = *(_DWORD *)(*(_QWORD *)(v23 + 8) + v25) & 0xFFFFFEFF
                                                | (((*(_DWORD *)(v13 + 4) >> 7) & 1) << 8);
        v26 = *(_QWORD *)(v23 + 8);
        v27 = *(_DWORD *)(v26 + v25) & 0xFFFFFFDF | (32 * ((*(_DWORD *)(v13 + 4) >> 8) & 1));
        *(_DWORD *)(v26 + v25) = v27;
        *(_DWORD *)(v26 + v25) = v27 & 0xFFFFFDFF | (((*(_DWORD *)(v13 + 4) >> 9) & 1) << 9);
        qdf_trace_msg(
          0x31u,
          8u,
          "supported_flags: 0x%08x  chainmasks: 0x%08x",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          *(unsigned int *)(v13 + 4),
          *(unsigned int *)(v13 + 8));
        ++v24;
        v13 += 12;
      }
      while ( *(_DWORD *)(v23 + 4) > (unsigned int)(unsigned __int8)v24 );
    }
    ++v22;
    result = 0;
    v21 = v22;
  }
  while ( *(_DWORD *)(v11 + 8) > (unsigned int)v22 );
  return result;
}
