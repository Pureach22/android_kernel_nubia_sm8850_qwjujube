__int64 __fastcall hdd_get_chain_rssi_cb(
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
  __int64 v21; // x20
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x10
  __int64 v25; // x11
  __int64 v26; // x8
  __int64 v27; // x10
  __int64 v28; // x11
  __int64 v29; // x9
  __int64 v30; // x10
  __int64 v31; // x11

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_get_chain_rssi_cb");
  v12 = osif_request_get(a1);
  if ( !v12 )
    return qdf_trace_msg(
             0x33u,
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
             "hdd_get_chain_rssi_cb");
  v21 = v12;
  v22 = osif_request_priv(v12);
  *(_QWORD *)v22 = *(_QWORD *)a2;
  v23 = *(_QWORD *)(a2 + 32);
  v25 = *(_QWORD *)(a2 + 8);
  v24 = *(_QWORD *)(a2 + 16);
  *(_QWORD *)(v22 + 24) = *(_QWORD *)(a2 + 24);
  *(_QWORD *)(v22 + 32) = v23;
  *(_QWORD *)(v22 + 8) = v25;
  *(_QWORD *)(v22 + 16) = v24;
  v26 = *(_QWORD *)(a2 + 64);
  v28 = *(_QWORD *)(a2 + 40);
  v27 = *(_QWORD *)(a2 + 48);
  *(_QWORD *)(v22 + 56) = *(_QWORD *)(a2 + 56);
  *(_QWORD *)(v22 + 64) = v26;
  *(_QWORD *)(v22 + 40) = v28;
  *(_QWORD *)(v22 + 48) = v27;
  v30 = *(_QWORD *)(a2 + 80);
  v29 = *(_QWORD *)(a2 + 88);
  v31 = *(_QWORD *)(a2 + 72);
  *(_DWORD *)(v22 + 96) = *(_DWORD *)(a2 + 96);
  *(_QWORD *)(v22 + 80) = v30;
  *(_QWORD *)(v22 + 88) = v29;
  *(_QWORD *)(v22 + 72) = v31;
  osif_request_complete(v21);
  return osif_request_put(v21);
}
