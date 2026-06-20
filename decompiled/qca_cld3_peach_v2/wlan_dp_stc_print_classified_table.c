__int64 __fastcall wlan_dp_stc_print_classified_table(__int64 result, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x23
  __int64 i; // x22
  __int64 v5; // x26
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // [xsp+0h] [xbp-130h]
  __int64 v15; // [xsp+8h] [xbp-128h]
  __int64 v16; // [xsp+20h] [xbp-110h]
  _QWORD v17[33]; // [xsp+28h] [xbp-108h] BYREF

  v17[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 2936);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 6424);
    for ( i = 0; i != 0x8000; i += 128 )
    {
      if ( *(_DWORD *)(v3 + i + 100) )
      {
        result = sched_clock(result, a2);
        if ( (*(_BYTE *)(v2 + 148) & 4) != 0 )
        {
          v5 = result;
          memset(v17, 0, 256);
          dp_print_tuple_to_str_0(v3 + i + 28, (__int64)v17);
          LODWORD(v16) = *(_DWORD *)(v3 + i + 112);
          LODWORD(v15) = *(_DWORD *)(v3 + i + 96);
          LODWORD(v14) = *(unsigned __int16 *)(v3 + i + 14);
          result = qdf_trace_msg(
                     0x45u,
                     5u,
                     "%s: STC: [%s] id %d active %d vdev_id %u peer_id %u traffic_type %d inactive %llu/%llu[%u]",
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     v13,
                     "wlan_dp_stc_print_c_entry",
                     v17,
                     *(unsigned __int16 *)(v3 + i + 16),
                     *(unsigned __int8 *)(v3 + i + 8),
                     *(unsigned __int8 *)(v3 + i + 9),
                     v14,
                     v15,
                     *(_QWORD *)(v3 + i + 120),
                     v5 - *(_QWORD *)(v3 + i + 128),
                     v16);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
