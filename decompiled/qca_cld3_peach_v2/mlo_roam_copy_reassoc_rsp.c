__int64 __fastcall mlo_roam_copy_reassoc_rsp(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  __int64 v6; // x9
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v10; // x21
  void *v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  void *v20; // x0
  __int64 v21; // x0
  __int64 v22; // x22
  size_t v23; // x0
  void *v24; // x0
  __int64 v25; // x5
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  result = 29;
  if ( a1 && a2 )
  {
    v6 = *(_QWORD *)(a1 + 1360);
    if ( v6 && (v7 = *(_QWORD *)(v6 + 2224)) != 0 )
    {
      v8 = *(_QWORD *)(v7 + 112);
      v10 = a1;
      if ( v8 )
      {
        _qdf_mem_free(v8);
        *(_QWORD *)(v7 + 112) = 0;
        *(_DWORD *)(v7 + 104) = 0;
      }
      v11 = (void *)_qdf_mem_malloc(*(unsigned int *)(a2 + 120), "mlo_roam_copy_reassoc_rsp", 1137);
      *(_QWORD *)(v7 + 112) = v11;
      if ( v11 )
      {
        qdf_mem_copy(v11, *(const void **)(a2 + 128), *(unsigned int *)(a2 + 120));
        *(_DWORD *)(v7 + 104) = *(_DWORD *)(a2 + 120);
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: save assoc_rsp frame for vdev: %d len: %d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "mlo_roam_copy_reassoc_rsp",
          *(unsigned __int8 *)(v10 + 168));
        wlan_cm_free_connect_resp(*(void **)(v7 + 288));
        *(_QWORD *)(v7 + 288) = 0;
        memcpy((void *)(v7 + 1168), (const void *)(a2 + 160), 0xB0u);
        if ( a3 != 1 || *(unsigned __int8 *)(a2 + 160) < 2u )
          return 0;
        v20 = (void *)_qdf_mem_malloc(0x150u, "mlo_roam_copy_reassoc_rsp", 1161);
        *(_QWORD *)(v7 + 288) = v20;
        if ( v20 )
        {
          qdf_mem_copy(v20, (const void *)a2, 0x150u);
          *(_QWORD *)(*(_QWORD *)(v7 + 288) + 144LL) = _qdf_mem_malloc(0xC8u, "mlo_roam_copy_reassoc_rsp", 1169);
          v21 = *(_QWORD *)(v7 + 288);
          if ( *(_QWORD *)(v21 + 144) )
          {
            qdf_mem_copy(*(void **)(v21 + 144), *(const void **)(a2 + 144), 0xC8u);
            v22 = *(_QWORD *)(v7 + 288);
            v23 = *(unsigned int *)(a2 + 120);
            *(_DWORD *)(v22 + 120) = v23;
            v24 = (void *)_qdf_mem_malloc(v23, "mlo_roam_copy_reassoc_rsp", 1187);
            *(_QWORD *)(v22 + 128) = v24;
            if ( v24 )
            {
              qdf_mem_copy(v24, *(const void **)(a2 + 128), *(unsigned int *)(a2 + 120));
              *(_DWORD *)(v22 + 104) = 0;
              v25 = *(unsigned int *)(v22 + 120);
              *(_QWORD *)(v22 + 112) = 0;
              *(_DWORD *)(v22 + 72) = 0;
              *(_QWORD *)(v22 + 80) = 0;
              *(_DWORD *)(v22 + 88) = 0;
              *(_QWORD *)(v22 + 96) = 0;
              *(_QWORD *)(v22 + 136) = 0;
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: Copied reassoc response for vdev: %d len: %d",
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                "mlo_roam_copy_reassoc_rsp",
                *(unsigned __int8 *)(v10 + 168),
                v25);
              return 0;
            }
            _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v7 + 288) + 144LL));
            *(_QWORD *)(*(_QWORD *)(v7 + 288) + 144LL) = 0;
            v21 = *(_QWORD *)(v7 + 288);
          }
          _qdf_mem_free(v21);
          *(_QWORD *)(v7 + 288) = 0;
        }
      }
      return 2;
    }
    else
    {
      return 29;
    }
  }
  return result;
}
