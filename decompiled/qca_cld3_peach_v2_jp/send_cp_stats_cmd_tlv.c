__int64 __fastcall send_cp_stats_cmd_tlv(__int64 a1, const void *a2, unsigned int a3)
{
  __int64 v6; // x0
  __int64 v7; // x20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0

  v6 = wmi_buf_alloc_fl(a1, a3, "send_cp_stats_cmd_tlv", 0x1B14u);
  if ( !v6 )
    return 2;
  v7 = v6;
  qdf_mem_copy(*(void **)(v6 + 224), a2, a3);
  qdf_mtrace(49, 100, 0xB0Fu, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v7,
             a3,
             0x1600Fu,
             "send_cp_stats_cmd_tlv",
             0x1B1Du,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15);
  if ( (_DWORD)result )
  {
    wmi_buf_free();
    return 16;
  }
  return result;
}
