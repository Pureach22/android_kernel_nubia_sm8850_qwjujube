__int64 __fastcall p2p_roc_req_for_tx_action(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x21
  __int64 v12; // x20
  int v13; // w8
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  const char *v24; // x2
  __int64 result; // x0

  v2 = _qdf_mem_malloc(0xF8u, "p2p_roc_req_for_tx_action", 1334);
  if ( !v2 )
    return 2;
  v11 = *(_QWORD *)(a1 + 16);
  v12 = v2;
  *(_QWORD *)(v2 + 16) = v11;
  *(_DWORD *)(v2 + 24) = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(v2 + 40) = *(_DWORD *)(a1 + 44);
  v13 = *(_DWORD *)(a1 + 64);
  *(_DWORD *)(v2 + 224) = 0;
  *(_QWORD *)(v2 + 32) = a1;
  *(_DWORD *)(v2 + 48) = v13;
  *(_DWORD *)(v2 + 52) = 1;
  *(_DWORD *)(v2 + 228) = *(_DWORD *)(a1 + 40);
  *(_QWORD *)(a1 + 32) = v2;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: create roc request for off channel tx, tx ctx:%pK, roc ctx:%pK",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "p2p_roc_req_for_tx_action",
    a1,
    v2);
  v14 = p2p_process_roc_req(v12);
  if ( v14 )
  {
    v23 = v14;
    v24 = "%s: request roc for tx action frrame fail";
  }
  else
  {
    result = qdf_list_insert_back((_QWORD *)(v11 + 32), (_QWORD *)a1);
    if ( !(_DWORD)result )
      return result;
    v23 = result;
    v24 = "%s: Failed to insert off chan tx context to wait roc req queue";
  }
  qdf_trace_msg(0x4Eu, 2u, v24, v15, v16, v17, v18, v19, v20, v21, v22, "p2p_roc_req_for_tx_action");
  return v23;
}
