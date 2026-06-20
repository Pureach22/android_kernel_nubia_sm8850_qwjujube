__int64 __fastcall infra_cp_stats_bmiss_response_cb(
        __int64 a1,
        __int64 a2,
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
  __int64 v21; // x19
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8

  qdf_trace_msg(0x48u, 8u, "%s: Enter", a3, a4, a5, a6, a7, a8, a9, a10, "infra_cp_stats_bmiss_response_cb");
  v12 = osif_request_get(a2);
  if ( !v12 )
    return qdf_trace_msg(
             0x48u,
             2u,
             "%s: Obsolete request",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "infra_cp_stats_bmiss_response_cb");
  v21 = v12;
  v22 = osif_request_priv(v12);
  *(_DWORD *)v22 = *(_DWORD *)a1;
  *(_DWORD *)(v22 + 4) = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(v22 + 8) = *(_DWORD *)(a1 + 8);
  if ( a1 && (v31 = *(_QWORD *)(a1 + 24)) != 0 )
  {
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 8LL) = *(_DWORD *)(v31 + 8);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 12LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 12LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 16LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 16LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 20LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 20LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 24LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 24LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 28LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 28LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 32LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 32LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 36LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 36LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 40LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 40LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 44LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 44LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 48LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 48LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 52LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 52LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 56LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 56LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 60LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 60LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 64LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 64LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 68LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 68LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 72LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 72LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 76LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 76LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 80LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 80LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 84LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 84LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 88LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 88LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 92LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 92LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 96LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 96LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 100LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 100LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 104LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 104LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 108LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 108LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 112LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 112LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 116LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 116LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 120LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 120LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 124LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 124LL);
    *(_DWORD *)(*(_QWORD *)(v22 + 24) + 128LL) = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 128LL);
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: got bmiss_infra_cp_stats as NULL",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "get_bmiss_infra_cp_stats");
  }
  osif_request_complete(v21);
  return osif_request_put(v21);
}
