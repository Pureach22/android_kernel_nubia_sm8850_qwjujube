__int64 __fastcall wlan_dp_spm_flow_table_attach(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x22
  __int64 v12; // x23
  __int64 result; // x0
  __int64 v14; // x21

  v2 = _qdf_mem_malloc(0xC000u, "wlan_dp_spm_flow_table_attach", 1124);
  *(_QWORD *)(a1 + 2952) = v2;
  if ( !v2 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Failed to SPM Tx flow table",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "wlan_dp_spm_flow_table_attach");
  v11 = 0;
  v12 = 0;
  *(_QWORD *)(a1 + 2960) = a1 + 2960;
  *(_QWORD *)(a1 + 2968) = a1 + 2960;
  *(_QWORD *)(a1 + 2976) = 0x10000000000LL;
  *(_DWORD *)(a1 + 2984) = 0;
  *(_QWORD *)(a1 + 2992) = 0;
  do
  {
    v14 = *(_QWORD *)(a1 + 2952) + v11;
    result = (__int64)qdf_mem_set((void *)v14, 0xC0u, 0);
    *(_WORD *)(v14 + 48) = v12;
    if ( (v12 & 0x3F) != 0 )
      result = qdf_list_insert_back((_QWORD *)(a1 + 2960), (_QWORD *)v14);
    else
      *(_BYTE *)(v14 + 51) = 1;
    ++v12;
    v11 += 192;
  }
  while ( v12 != 256 );
  return result;
}
