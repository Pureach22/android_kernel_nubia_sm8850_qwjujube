__int64 __fastcall mlo_connect(__int64 a1, const void *a2)
{
  __int64 v2; // x21
  __int64 v4; // x22
  __int64 v5; // x20
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  void *v15; // x0
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v19; // x9
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20

  v2 = *(_QWORD *)(a1 + 1360);
  if ( v2 )
  {
    v4 = *(_QWORD *)(v2 + 2224);
    if ( v4 )
    {
      v5 = a1;
      qdf_mutex_acquire(v2 + 1656);
      qdf_mutex_acquire(v4 + 40);
      v6 = *(_QWORD *)(v4 + 32);
      if ( v6 )
      {
        wlan_cm_free_connect_req_param(v6);
        v15 = *(void **)(v4 + 32);
        if ( v15 )
          goto LABEL_5;
      }
      else
      {
        v15 = (void *)_qdf_mem_malloc(0x3E0u, "mlo_connect", 790);
        *(_QWORD *)(v4 + 32) = v15;
        if ( v15 )
        {
LABEL_5:
          qdf_mem_copy(v15, a2, 0x3E0u);
          mlo_allocate_and_copy_ies(*(_QWORD **)(v4 + 32), (__int64)a2);
          qdf_mutex_release(v4 + 40);
          v16 = v5;
          if ( v5 )
          {
            v17 = *(_QWORD *)(v5 + 1360);
            if ( v17 )
            {
              v18 = *(_QWORD *)(v17 + 2224);
              if ( !v18 || (qdf_mem_set((void *)(v18 + 8), 8u, 0), v17 = *(_QWORD *)(v5 + 1360), v16 = v5, v17) )
              {
                v19 = *(_QWORD *)(v17 + 2224);
                if ( v19 )
                {
                  qdf_mem_set((void *)(v19 + 16), 6u, 0);
                  qdf_trace_msg(
                    0x8Fu,
                    8u,
                    "%s: clear sta_key_mgmt",
                    v20,
                    v21,
                    v22,
                    v23,
                    v24,
                    v25,
                    v26,
                    v27,
                    "mlo_clear_sta_key_mgmt");
                  v16 = v5;
                }
              }
            }
          }
          v28 = v16;
          qdf_mutex_release(v2 + 1656);
          a1 = v28;
          return wlan_cm_start_connect(a1, (__int64)a2);
        }
      }
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Failed to allocate orig connect req",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "mlo_connect");
      qdf_mutex_release(v4 + 40);
      qdf_mutex_release(v2 + 1656);
      return 2;
    }
  }
  return wlan_cm_start_connect(a1, (__int64)a2);
}
