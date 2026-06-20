__int64 __fastcall get_peer_stats_cb(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v24; // x21
  __int64 v25; // x0
  int v26; // w8
  __int64 v27; // x28
  __int64 v28; // x22
  __int64 v29; // x26
  unsigned int v30; // w27
  __int64 v31; // x24
  __int64 v32; // x25
  __int64 v33; // x8
  void *v34; // x0
  int v35; // w8
  __int64 v36; // x8
  void *v37; // x0
  int v38; // w9

  v4 = osif_request_get(a2);
  if ( !v4 )
    return qdf_trace_msg(0x48u, 2u, "%s: Obsolete request", v5, v6, v7, v8, v9, v10, v11, v12, "get_peer_stats_cb");
  v13 = v4;
  v14 = osif_request_priv(v4);
  if ( *(_QWORD *)(v14 + 160) )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: invalid context cookie %pK request %pK",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "get_peer_stats_cb",
      a2,
      v13);
    goto LABEL_17;
  }
  v24 = v14;
  v25 = _qdf_mem_malloc((unsigned int)(136 * *(_DWORD *)(a1 + 156)), "get_peer_stats_cb", 1525);
  *(_QWORD *)(v24 + 160) = v25;
  if ( v25 )
  {
    v26 = *(_DWORD *)(a1 + 156);
    if ( !v26 )
      goto LABEL_16;
    v27 = *(_QWORD *)(a1 + 160);
    v28 = v25;
    v29 = 0;
    v30 = 0;
    while ( 1 )
    {
      v31 = v27 + v29;
      v32 = v28 + v29;
      qdf_mem_copy((void *)(v28 + v29), (const void *)(v27 + v29), 6u);
      *(_DWORD *)(v32 + 8) = *(_DWORD *)(v27 + v29 + 8);
      *(_QWORD *)(v32 + 16) = *(_QWORD *)(v27 + v29 + 16);
      *(_DWORD *)(v32 + 24) = *(_DWORD *)(v27 + v29 + 24);
      *(_QWORD *)(v32 + 32) = *(_QWORD *)(v27 + v29 + 32);
      *(_DWORD *)(v32 + 40) = *(_DWORD *)(v27 + v29 + 40);
      *(_DWORD *)(v32 + 44) = *(_DWORD *)(v27 + v29 + 44);
      *(_DWORD *)(v32 + 48) = *(_DWORD *)(v27 + v29 + 48);
      *(_DWORD *)(v32 + 52) = *(_DWORD *)(v27 + v29 + 52);
      *(_DWORD *)(v32 + 56) = *(_DWORD *)(v27 + v29 + 56);
      *(_DWORD *)(v32 + 60) = *(_DWORD *)(v27 + v29 + 60);
      *(_DWORD *)(v32 + 64) = *(_DWORD *)(v27 + v29 + 64);
      *(_DWORD *)(v32 + 68) = *(_DWORD *)(v27 + v29 + 68);
      *(_DWORD *)(v32 + 72) = *(_DWORD *)(v27 + v29 + 72);
      *(_DWORD *)(v32 + 76) = *(_DWORD *)(v27 + v29 + 76);
      *(_DWORD *)(v32 + 80) = *(_DWORD *)(v27 + v29 + 80);
      *(_DWORD *)(v32 + 84) = *(_DWORD *)(v27 + v29 + 84);
      *(_DWORD *)(v32 + 88) = *(_DWORD *)(v27 + v29 + 88);
      *(_DWORD *)(v32 + 92) = *(_DWORD *)(v27 + v29 + 92);
      *(_DWORD *)(v32 + 96) = *(_DWORD *)(v27 + v29 + 96);
      *(_DWORD *)(v32 + 100) = *(_DWORD *)(v27 + v29 + 100);
      v33 = *(unsigned int *)(v27 + v29 + 104);
      if ( (_DWORD)v33 )
      {
        v34 = (void *)_qdf_mem_malloc(4 * v33, "copy_peer_stats_info_ext", 1465);
        *(_QWORD *)(v32 + 112) = v34;
        if ( !v34 )
          goto LABEL_15;
        v35 = *(_DWORD *)(v31 + 104);
        *(_DWORD *)(v28 + v29 + 104) = v35;
        qdf_mem_copy(v34, *(const void **)(v27 + v29 + 112), (unsigned int)(4 * v35));
      }
      v36 = *(unsigned int *)(v31 + 108);
      if ( (_DWORD)v36 )
      {
        v37 = (void *)_qdf_mem_malloc(4 * v36, "copy_peer_stats_info_ext", 1480);
        *(_QWORD *)(v28 + v29 + 120) = v37;
        if ( !v37 )
        {
LABEL_15:
          v26 = *(_DWORD *)(a1 + 156);
LABEL_16:
          *(_DWORD *)(v24 + 156) = v26;
          break;
        }
        v38 = *(_DWORD *)(v31 + 108);
        *(_DWORD *)(v28 + v29 + 108) = v38;
        qdf_mem_copy(v37, *(const void **)(v27 + v29 + 120), (unsigned int)(4 * v38));
      }
      ++v30;
      v29 += 136;
      if ( v30 >= *(_DWORD *)(a1 + 156) )
        goto LABEL_15;
    }
  }
LABEL_17:
  osif_request_complete(v13);
  return osif_request_put(v13);
}
