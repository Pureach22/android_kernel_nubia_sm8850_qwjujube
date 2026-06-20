__int64 __fastcall send_pdev_set_regdomain_cmd_tlv(__int64 a1, unsigned __int16 *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  __int64 v7; // x1
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v4 = wmi_buf_alloc_fl(a1, 0xE0u, "send_pdev_set_regdomain_cmd_tlv", 0x21BBu);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 5308636;
  v5[2] = *a2;
  v5[3] = a2[1];
  v5[4] = a2[2];
  v5[5] = *((_DWORD *)a2 + 2);
  v5[6] = *((_DWORD *)a2 + 3);
  v5[7] = *((unsigned __int8 *)a2 + 16);
  v7 = *((unsigned int *)a2 + 5);
  v8 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( *((_DWORD *)v8 - 1) != -2112860426 )
    __break(0x8228u);
  v5[1] = v8(a1, v7);
  qdf_mtrace(49, 100, 0x201u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0xE0u,
             0x4001u,
             "send_pdev_set_regdomain_cmd_tlv",
             0x21D1u,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send pdev set regdomain command",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "send_pdev_set_regdomain_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
