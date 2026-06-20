__int64 __fastcall sme_hdd_ready_ind(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w19
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w19

  qdf_trace(52, 8u, 255, 0);
  v2 = _qdf_mem_malloc(0x38u, "sme_hdd_ready_ind", 1163);
  if ( !v2 )
    return 2;
  *(_DWORD *)v2 = 3675137;
  *(_QWORD *)(v2 + 24) = sme_stop_roaming;
  *(_QWORD *)(v2 + 32) = sme_process_msg_callback;
  *(_QWORD *)(v2 + 8) = csr_roam_auth_offload_callback;
  v3 = u_mac_post_ctrl_msg(a1, v2);
  if ( v3 )
  {
    v12 = v3;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: u_mac_post_ctrl_msg failed to send eWNI_SME_SYS_READY_IND",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "sme_hdd_ready_ind");
    return v12;
  }
  else
  {
    result = csr_ready(a1);
    if ( (_DWORD)result )
    {
      v22 = result;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: csr_ready failed with status: %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sme_hdd_ready_ind",
        (unsigned int)result);
      return v22;
    }
    else
    {
      *(_DWORD *)(a1 + 12768) = 2;
    }
  }
  return result;
}
