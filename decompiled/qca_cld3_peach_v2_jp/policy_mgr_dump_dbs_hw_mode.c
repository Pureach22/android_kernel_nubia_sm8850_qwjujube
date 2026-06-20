__int64 __fastcall policy_mgr_dump_dbs_hw_mode(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int64 v20; // x20
  unsigned int *v21; // x8
  unsigned int v22; // w26
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // [xsp+0h] [xbp-10h]

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "policy_mgr_dump_dbs_hw_mode");
  v10 = context;
  result = qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: old_hw_mode_index=%d, new_hw_mode_index=%d",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "policy_mgr_dump_dbs_hw_mode",
             *(unsigned int *)(context + 1496),
             *(unsigned int *)(context + 1500));
  if ( *(_DWORD *)(v10 + 1184) )
  {
    v20 = 0;
    do
    {
      v21 = (unsigned int *)(*(_QWORD *)(v10 + 1192) + 8 * v20);
      v22 = *v21;
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: [%d] 0x%x 0x%x",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "policy_mgr_dump_dbs_hw_mode",
        (unsigned int)v20,
        *v21,
        v21[1]);
      LODWORD(v47) = (v22 >> 3) & 3;
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: [%d]-MAC0: tx_ss:%d rx_ss:%d bw_idx:%d band_cap:%d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "policy_mgr_dump_dbs_hw_mode",
        (unsigned int)v20,
        v22 >> 28,
        HIBYTE(v22) & 0xF,
        (unsigned __int16)v22 >> 12,
        v47);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: [%d]-MAC1: tx_ss:%d rx_ss:%d bw_idx:%d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "policy_mgr_dump_dbs_hw_mode",
        (unsigned int)v20,
        (v22 >> 20) & 0xF,
        HIWORD(v22) & 0xF,
        (v22 >> 8) & 0xF);
      result = qdf_trace_msg(
                 0x4Fu,
                 8u,
                 "%s: [%d] DBS:%d SBS:%d hw_mode_id:%d",
                 v39,
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 "policy_mgr_dump_dbs_hw_mode",
                 (unsigned int)v20++,
                 (v22 >> 7) & 1,
                 (v22 >> 5) & 1,
                 v22 & 7);
    }
    while ( v20 < *(unsigned int *)(v10 + 1184) );
  }
  return result;
}
