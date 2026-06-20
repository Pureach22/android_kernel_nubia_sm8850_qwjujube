__int64 __fastcall wma_update_probe_resp_noa(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x9
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v4 = (_QWORD *)_qdf_mem_malloc(0x24u, "wma_update_probe_resp_noa", 1454);
  result = qdf_trace_msg(
             0x36u,
             8u,
             "%s: Received update NoA event",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "wma_update_probe_resp_noa");
  if ( v4 )
  {
    qdf_mem_set(v4, 0x24u, 0);
    v22 = *v4 & 0xFFFFFFFF00FFFFFFLL | ((unsigned __int64)*(unsigned __int8 *)(a2 + 2) << 24);
    *v4 = v22;
    v23 = v22 & 0xFFFFFFFFFF7FFFFFLL | ((unsigned __int64)(*(_BYTE *)(a2 + 3) & 1) << 23);
    *v4 = v23;
    *v4 = v23 & 0xFFFFFFFFFF80FFFFLL | ((((unsigned __int64)*(unsigned __int8 *)(a2 + 3) >> 1) & 0x7F) << 16);
    if ( *(_BYTE *)(a2 + 4) )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: %d NoA descriptors",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wma_update_probe_resp_noa");
      *((_BYTE *)v4 + 7) = *(_BYTE *)(a2 + 5);
      *((_DWORD *)v4 + 2) = *(_DWORD *)(a2 + 6);
      *((_DWORD *)v4 + 3) = *(_DWORD *)(a2 + 10);
      *((_DWORD *)v4 + 4) = *(_DWORD *)(a2 + 14);
      if ( *(unsigned __int8 *)(a2 + 4) >= 2u )
      {
        *((_BYTE *)v4 + 23) = *(_BYTE *)(a2 + 18);
        *((_DWORD *)v4 + 6) = *(_DWORD *)(a2 + 19);
        *((_DWORD *)v4 + 7) = *(_DWORD *)(a2 + 23);
        *((_DWORD *)v4 + 8) = *(_DWORD *)(a2 + 27);
      }
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Zero NoA descriptors",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wma_update_probe_resp_noa");
    }
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Sending SIR_HAL_P2P_NOA_ATTR_IND to LIM",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wma_update_probe_resp_noa");
    return wma_send_msg(a1, 0x1090u, (__int64)v4, 0);
  }
  return result;
}
