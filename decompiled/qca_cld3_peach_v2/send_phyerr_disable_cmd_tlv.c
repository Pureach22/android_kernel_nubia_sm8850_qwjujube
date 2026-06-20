__int64 __fastcall send_phyerr_disable_cmd_tlv(__int64 a1)
{
  __int64 v2; // x0
  _DWORD *v3; // x21
  __int64 v4; // x19
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w20

  v2 = wmi_buf_alloc_fl(a1, 8u, "send_phyerr_disable_cmd_tlv", 0x230Bu);
  if ( !v2 )
    return 16;
  v3 = *(_DWORD **)(v2 + 224);
  v4 = v2;
  *v3 = 11665412;
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( *((_DWORD *)v5 - 1) != -2112860426 )
    __break(0x8228u);
  v3[1] = v5(a1, 255);
  qdf_mtrace(49, 100, 0x502u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v4,
             8u,
             0xA002u,
             "send_phyerr_disable_cmd_tlv",
             0x231Bu,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13);
  if ( (_DWORD)result )
  {
    v23 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Sending PDEV DFS disable cmd failed",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "send_phyerr_disable_cmd_tlv");
    wmi_buf_free();
    return v23;
  }
  return result;
}
