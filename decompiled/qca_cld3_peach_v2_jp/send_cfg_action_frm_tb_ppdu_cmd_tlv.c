__int64 __fastcall send_cfg_action_frm_tb_ppdu_cmd_tlv(__int64 a1, __int64 a2)
{
  int v4; // w24
  unsigned int v5; // w23
  __int64 v6; // x0
  _DWORD *v7; // x22
  __int64 v8; // x19
  size_t v9; // x2
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v4 = *(_DWORD *)(a2 + 4) + 3;
  v5 = v4 & 0xFFFFFFFC;
  v6 = wmi_buf_alloc_fl(a1, (v4 & 0xFFFFFFFC) + 16, "send_cfg_action_frm_tb_ppdu_cmd_tlv", 0x2B7Du);
  if ( v6 )
  {
    v7 = *(_DWORD **)(v6 + 224);
    v8 = v6;
    qdf_mem_set(v7, v5 + 16, 0);
    *v7 = 49741832;
    v7[1] = *(_DWORD *)a2;
    v9 = *(unsigned int *)(a2 + 4);
    v7[2] = v9;
    v7[3] = v4 & 0xFFFC | 0x110000;
    qdf_mem_copy(v7 + 4, *(const void **)(a2 + 8), v9);
    v18 = wmi_unified_cmd_send_fl(
            a1,
            v8,
            v5 + 16,
            0x4035u,
            "send_cfg_action_frm_tb_ppdu_cmd_tlv",
            0x2B95u,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17);
    if ( v18 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: HE TB action frame cmnd send fail, ret %d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "send_cfg_action_frm_tb_ppdu_cmd_tlv",
        v18);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v18;
}
