__int64 __fastcall wma_vdev_start_rsp(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  int v4; // w22
  __int64 result; // x0
  __int64 v7; // x20
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w8
  __int64 v17; // x22
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  int v28; // w8
  __int64 v29; // x1
  int v30; // w9
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
  __int64 *v47; // x22

  v4 = *(_DWORD *)(a2 + 16);
  result = _qdf_mem_malloc(0x10u, "wma_vdev_start_rsp", 822);
  if ( !result )
    return result;
  v7 = result;
  *(_BYTE *)result = *a3;
  *(_DWORD *)(result + 4) = *((_DWORD *)a3 + 2);
  *(_DWORD *)(result + 8) = *((_DWORD *)a3 + 4);
  *(_BYTE *)(result + 12) = host_map_smps_mode(*((unsigned int *)a3 + 5));
  v16 = *((_DWORD *)a3 + 2);
  if ( !v16 && (v4 & 0xFFFFFFFD) == 1 )
  {
    *(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * *a3 + 8) = _qdf_mem_malloc(0x78u, "wma_vdev_start_rsp", 836);
    v17 = *(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * *a3 + 8);
    if ( v17 )
    {
      v18 = _qdf_nbuf_alloc(0, 512, 0, 4, 0, "wma_vdev_start_rsp", 844);
      *(_QWORD *)v17 = v18;
      if ( v18 )
      {
        *(_DWORD *)(v17 + 104) = 0;
        *(_WORD *)(v17 + 22) = 256;
        *(_QWORD *)(v17 + 112) = 0;
        *(_DWORD *)(*(_QWORD *)(a1 + 520) + 488LL * *a3 + 228) = 1;
        v27 = *(_QWORD *)(a1 + 520) + 488LL * *a3;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: AP mode (type %d subtype %d) BSS is started",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "wma_vdev_start_rsp",
          *(unsigned int *)(v27 + 164),
          *(unsigned int *)(v27 + 168));
LABEL_10:
        v16 = *((_DWORD *)a3 + 2);
        goto LABEL_11;
      }
      _qdf_mem_free(v17);
      v28 = 16;
    }
    else
    {
      v28 = 2;
    }
    *(_DWORD *)(v7 + 4) = v28;
    goto LABEL_10;
  }
LABEL_11:
  v29 = *a3;
  v30 = *(_DWORD *)(v7 + 4);
  if ( v16 )
  {
    if ( !v30 )
    {
LABEL_14:
      wma_remove_bss_peer_on_failure(a1, v29);
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Sending add bss rsp to umac(vdev %d status %d)",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "wma_send_start_resp",
        *a3,
        *(unsigned int *)(v7 + 4));
      return lim_handle_add_bss_rsp(*(_QWORD *)(a1 + 16), (unsigned __int8 *)v7, v39, v40, v41, v42, v43, v44, v45, v46);
    }
LABEL_13:
    v29 = *a3;
    goto LABEL_14;
  }
  v47 = (__int64 *)(*(_QWORD *)(a1 + 520) + 488LL * *a3);
  if ( v30 )
    return wlan_vdev_mlme_sm_deliver_evt(*v47, 0xCu, 0x10u, v7, v8, v9, v10, v11, v12, v13, v14, v15);
  result = wlan_vdev_mlme_sm_deliver_evt(*v47, 3u, 0x10u, v7, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( (_DWORD)result )
  {
    *(_DWORD *)(v7 + 4) = result;
    if ( *((_DWORD *)a3 + 2) )
      goto LABEL_13;
    return wlan_vdev_mlme_sm_deliver_evt(*v47, 0xCu, 0x10u, v7, v8, v9, v10, v11, v12, v13, v14, v15);
  }
  return result;
}
