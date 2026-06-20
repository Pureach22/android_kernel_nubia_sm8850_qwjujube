__int64 __fastcall tpg_hw_copy_settings_config(_QWORD *a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v5; // x0
  const char *v6; // x5
  __int64 v7; // x4
  __int64 v8; // x0
  __int64 v9; // x22
  __int64 v10; // x8
  void *v11; // x0
  __int64 v12; // x8
  __int64 v13; // x10
  __int64 v14; // x11

  if ( a1 && a2 )
  {
    v3 = *(unsigned int *)(a2 + 20);
    if ( mem_trace_en == 1 )
    {
      v5 = cam_mem_trace_alloc(32 * v3, 0xCC0u, 0, "tpg_hw_copy_settings_config", 0x428u);
      a1[24] = v5;
      if ( !v5 )
        goto LABEL_9;
    }
    else
    {
      v8 = _kvmalloc_node_noprof(32 * v3, 0, 3520, 0xFFFFFFFFLL);
      a1[24] = v8;
      if ( !v8 )
      {
LABEL_9:
        v6 = "unable to allocate memory";
        v7 = 1067;
        goto LABEL_10;
      }
    }
    v9 = *(unsigned int *)(a2 + 16);
    mutex_lock(a1 + 6);
    v10 = *(_QWORD *)(a2 + 8);
    v11 = (void *)a1[24];
    a1[18] = *(_QWORD *)a2;
    a1[19] = v10;
    v12 = *(_QWORD *)(a2 + 40);
    v13 = *(_QWORD *)(a2 + 16);
    v14 = *(_QWORD *)(a2 + 24);
    a1[22] = *(_QWORD *)(a2 + 32);
    a1[23] = v12;
    a1[20] = v13;
    a1[21] = v14;
    memcpy(v11, (const void *)(a2 + v9), 32 * v3);
    mutex_unlock(a1 + 6);
    return 0;
  }
  v6 = "invalid parameter";
  v7 = 1057;
LABEL_10:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x200000000LL,
    1,
    "tpg_hw_copy_settings_config",
    v7,
    v6);
  return 4294967274LL;
}
