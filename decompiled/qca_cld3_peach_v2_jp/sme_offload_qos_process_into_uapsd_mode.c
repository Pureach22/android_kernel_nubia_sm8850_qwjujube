__int64 __fastcall sme_offload_qos_process_into_uapsd_mode(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 result; // x0
  unsigned int v23; // w10
  unsigned __int64 v24; // x11
  __int64 v25; // x1
  void (__fastcall *v26)(__int64, __int64, __int64, __int64, __int64); // x9
  __int64 v27; // x4
  __int64 v28; // x26
  __int64 v29; // x2

  v12 = csr_ll_peek_head((__int64)&unk_856128, 0, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( v12 )
  {
    v21 = v12;
    while ( 1 )
    {
      result = csr_ll_next((__int64)&unk_856128, v21, 0, v13, v14, v15, v16, v17, v18, v19, v20);
      if ( *(unsigned __int8 *)(v21 + 16) == a2
        && (*(_DWORD *)(v21 + 64) || *(_DWORD *)(v21 + 60))
        && *(_DWORD *)(v21 + 20) == 4 )
      {
        v23 = *(_DWORD *)(v21 + 28);
        if ( v23 >= 4 || (v24 = *(unsigned __int8 *)(v21 + 17) - 1LL, v24 > 2) )
        {
          __break(0x5512u);
          return sme_qos_is_ts_info_ack_policy_valid(result);
        }
        v25 = *(_QWORD *)(v21 + 112);
        v26 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v21 + 120);
        v27 = *(unsigned int *)(v21 + 24);
        v28 = result;
        v29 = qword_856120 + 3040LL * *(unsigned __int8 *)(v21 + 16) + 728LL * v23 + 76LL * (int)v24 + 16;
        if ( *((_DWORD *)v26 - 1) != -518755401 )
          __break(0x8229u);
        v26(a1, v25, v29, 401, v27);
        result = v28;
      }
      v21 = result;
      if ( !result )
        return result;
    }
  }
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: Flow List empty, can't search",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "sme_offload_qos_process_into_uapsd_mode");
  return 16;
}
