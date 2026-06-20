__int64 __fastcall send_p2p_ap_assist_dfs_group_params_cmd_tlv(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v11; // w23
  int v12; // w8
  int v13; // w9
  int v14; // w10
  unsigned int v16; // w21
  _BOOL4 v17; // w22
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _DWORD *v27; // x8
  _BOOL4 v28; // w12
  int v29; // w13
  __int64 v30; // x8
  int v31; // w9
  __int64 v32; // x8
  __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    v11 = *(_DWORD *)(a2 + 1) | *(unsigned __int16 *)(a2 + 5);
    v12 = *(_DWORD *)(a2 + 7);
    v13 = *(unsigned __int16 *)(a2 + 11);
    if ( v11 )
      v14 = 28;
    else
      v14 = 20;
    if ( v12 | v13 )
      v16 = v14 + 8;
    else
      v16 = v14;
    v17 = (v12 | v13) != 0;
    v18 = wmi_buf_alloc_fl(a1, v16, "send_p2p_ap_assist_dfs_group_params_cmd_tlv", 0x109u);
    if ( v18 )
    {
      v27 = *(_DWORD **)(v18 + 224);
      v28 = v11 != 0;
      *v27 = 81592328;
      v29 = *a2;
      v27[3] = (8 * v28) | 0x130000;
      v27[1] = v29;
      v27[2] = v28;
      if ( v11 )
      {
        v27[4] = *(_DWORD *)(a2 + 1);
        v27[5] = *(unsigned __int16 *)(a2 + 5);
      }
      v30 = (__int64)&v27[2 * (v11 != 0) + 3];
      if ( v17 )
        v31 = 1245192;
      else
        v31 = 1245184;
      *(_DWORD *)(v30 + 4) = v31;
      v32 = v30 + 4;
      if ( v17 )
      {
        *(_DWORD *)(v32 + 4) = *(_DWORD *)(a2 + 7);
        *(_DWORD *)(v32 + 8) = *(unsigned __int16 *)(a2 + 11);
      }
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v18,
                 v16,
                 0xD00Cu,
                 "send_p2p_ap_assist_dfs_group_params_cmd_tlv",
                 0x12Eu,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26);
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send P2P DFS assisted AP params",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "send_p2p_ap_assist_dfs_group_params_cmd_tlv");
        wmi_buf_free();
        result = 16;
      }
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed allocate wmi buffer",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "send_p2p_ap_assist_dfs_group_params_cmd_tlv");
      result = 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: WMA context is invalid!",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "send_p2p_ap_assist_dfs_group_params_cmd_tlv");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
