__int64 __fastcall infra_cp_stats_response_cb(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 v14; // x9

  v3 = osif_request_get(a2);
  if ( !v3 )
    return qdf_trace_msg(
             0x48u,
             2u,
             "%s: Obsolete request",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "infra_cp_stats_response_cb");
  v12 = v3;
  v13 = osif_request_priv(v3);
  v14 = *(_QWORD *)(v13 + 16);
  *(_DWORD *)v13 = *(_DWORD *)a1;
  *(_DWORD *)(v13 + 4) = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(v13 + 8) = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(v13 + 12) = *(_DWORD *)(a1 + 12);
  *(_DWORD *)(v14 + 8) = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 8LL);
  *(_DWORD *)(*(_QWORD *)(v13 + 16) + 12LL) = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 12LL);
  *(_DWORD *)(*(_QWORD *)(v13 + 16) + 16LL) = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 16LL);
  *(_DWORD *)(*(_QWORD *)(v13 + 16) + 20LL) = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 20LL);
  *(_DWORD *)(*(_QWORD *)(v13 + 16) + 24LL) = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 24LL);
  *(_DWORD *)(*(_QWORD *)(v13 + 16) + 28LL) = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 28LL);
  *(_DWORD *)(*(_QWORD *)(v13 + 16) + 32LL) = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 32LL);
  *(_DWORD *)(*(_QWORD *)(v13 + 16) + 36LL) = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 36LL);
  *(_DWORD *)(*(_QWORD *)(v13 + 16) + 40LL) = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 40LL);
  *(_DWORD *)(*(_QWORD *)(v13 + 16) + 44LL) = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 44LL);
  *(_DWORD *)(*(_QWORD *)(v13 + 16) + 48LL) = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 48LL);
  *(_DWORD *)(*(_QWORD *)(v13 + 16) + 52LL) = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 52LL);
  osif_request_complete(v12);
  return osif_request_put(v12);
}
