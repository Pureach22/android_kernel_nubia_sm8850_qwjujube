__int64 __fastcall send_set_base_macaddr_indicate_cmd_tlv(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  __int64 (__fastcall *v7)(__int64, __int64); // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "send_set_base_macaddr_indicate_cmd_tlv", 0x476u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  qdf_mem_set(v5, 0x10u, 0);
  *v5 = 11272204;
  v5[2] = *(_DWORD *)a2;
  v5[3] = *(unsigned __int16 *)(a2 + 4);
  v7 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3664LL);
  if ( *((_DWORD *)v7 - 1) != -2112860426 )
    __break(0x8228u);
  v5[1] = v7(a1, 255);
  wmi_mtrace(0x400Du, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0x10u,
             0x400Du,
             "send_set_base_macaddr_indicate_cmd_tlv",
             0x489u,
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
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send set_base_macaddr cmd",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "send_set_base_macaddr_indicate_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
