__int64 __fastcall send_csa_offload_enable_cmd_tlv(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w22
  __int64 v13; // x0
  _DWORD *v14; // x8
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v10 = a2;
  qdf_trace_msg(0x31u, 8u, "%s: vdev_id %d", a3, a4, a5, a6, a7, a8, a9, a10, "send_csa_offload_enable_cmd_tlv", a2);
  v13 = wmi_buf_alloc_fl(a1, 0xCu, "send_csa_offload_enable_cmd_tlv", 0x1F3Cu);
  if ( !v13 )
    return 2;
  v14 = *(_DWORD **)(v13 + 224);
  v15 = v13;
  *v14 = 9568264;
  v14[1] = v10;
  v14[2] = 1;
  qdf_mtrace(49, 100, 0xD01u, a2, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v15,
             0xCu,
             0x1A001u,
             "send_csa_offload_enable_cmd_tlv",
             0x1F49u,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send CSA offload enable command",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "send_csa_offload_enable_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
