__int64 cam_mem_mgr_init()
{
  unsigned int v0; // w19
  char v1; // w0
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  const void *v9; // x0
  __int64 *v10; // x8
  _QWORD *v11; // x0
  __int64 v13; // x25
  _DWORD *v14; // x19
  __int64 *v16; // x27
  unsigned __int64 v17; // x20
  unsigned __int64 v18; // x26
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 *v21; // x19
  unsigned __int64 v27; // x9
  _QWORD v28[2]; // [xsp+40h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( cam_mem_mgr_state )
  {
    v0 = 0;
    goto LABEL_74;
  }
  memset(&unk_2FDBA0, 0, 0x94000u);
  if ( (unsigned int)cam_smmu_need_force_alloc_cached(&byte_391BB8) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_init",
      836,
      "Error in getting force cache alloc flag");
    v0 = -22;
    goto LABEL_74;
  }
  v1 = cam_smmu_need_shared_buffer_padding();
  qword_391BC8 = 0;
  qword_391BD0 = 0;
  byte_391BB9 = v1 & 1;
  qword_391BD8 = 0;
  qword_391BE0 = 0;
  qword_391BE8 = 0;
  qword_391BF0 = 0;
  qword_391BF8 = 0;
  qword_391C00 = 0;
  v2 = dma_heap_find("qcom,system");
  v0 = v2;
  qword_391BC8 = v2;
  if ( v2 && v2 < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = dma_heap_find("qcom,system-movable");
    qword_391BD0 = v3;
    if ( !v3 || v3 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x400000,
          4,
          "cam_mem_mgr_get_dma_heaps",
          1367,
          "qcom system heap not found, rc=%d",
          v3);
      qword_391BD0 = 0;
    }
    v4 = dma_heap_find("qcom,system-uncached");
    v0 = v4;
    qword_391BD8 = v4;
    if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( byte_391BB8 != 1 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          1,
          "cam_mem_mgr_get_dma_heaps",
          1385,
          "qcom system-uncached heap not found, rc=%d",
          v4);
        v10 = &qword_391BD8;
        goto LABEL_50;
      }
      if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x400000,
          4,
          "cam_mem_mgr_get_dma_heaps",
          1378,
          "qcom system-uncached heap not found, err=%d",
          v4);
      qword_391BD8 = 0;
    }
    v5 = dma_heap_find("qcom,ubwcp");
    qword_391BF8 = v5;
    if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x400000,
          4,
          "cam_mem_mgr_get_dma_heaps",
          1393,
          "qcom ubwcp heap not found, err=%d",
          v5);
      qword_391BF8 = 0;
    }
    v6 = dma_heap_find("qcom,ubwcp-movable");
    qword_391C00 = v6;
    if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x400000,
          4,
          "cam_mem_mgr_get_dma_heaps",
          1400,
          "qcom ubwcp movable heap not found, err=%d",
          v6);
      qword_391C00 = 0;
    }
    v7 = dma_heap_find("qcom,display");
    v0 = v7;
    qword_391BF0 = v7;
    if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
    {
      v8 = dma_heap_find("qcom,camera");
      qword_391BE0 = v8;
      if ( !v8 || v8 >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x400000,
            4,
            "cam_mem_mgr_get_dma_heaps",
            1417,
            "qcom camera heap not found, err=%d",
            v8);
        qword_391BE0 = 0;
      }
      v9 = (const void *)dma_heap_find("qcom,camera-uncached");
      qword_391BE8 = (__int64)v9;
      if ( !v9 || (unsigned __int64)v9 >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x400000,
            4,
            "cam_mem_mgr_get_dma_heaps",
            1425,
            "qcom camera heap not found, err=%d",
            (_DWORD)v9);
        v9 = nullptr;
        qword_391BE8 = 0;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        3,
        "cam_mem_mgr_get_dma_heaps",
        1433,
        "Heaps : system=%pK %pK, system_uncached=%pK, camera=%pK, camera-uncached=%pK, secure_display=%pK, ubwc_p=%pK %pK",
        (const void *)qword_391BC8,
        (const void *)qword_391BD0,
        (const void *)qword_391BD8,
        (const void *)qword_391BE0,
        v9,
        (const void *)qword_391BF0,
        (const void *)qword_391BF8,
        (const void *)qword_391C00);
      goto LABEL_55;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_get_dma_heaps",
      1408,
      "qcom,display heap not found, rc=%d",
      v7);
    v10 = &qword_391BF0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_get_dma_heaps",
      1359,
      "qcom system heap not found, rc=%d",
      v2);
    v10 = &qword_391BC8;
  }
LABEL_50:
  *v10 = 0;
  if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x400000,
      4,
      "cam_mem_mgr_put_dma_heaps",
      1339,
      "Releasing DMA Buf heaps usage");
    if ( v0 )
      goto LABEL_53;
  }
  else if ( v0 )
  {
LABEL_53:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_init",
      845,
      "Failed in getting dma heaps rc=%d",
      v0);
    goto LABEL_74;
  }
LABEL_55:
  if ( mem_trace_en == 1 )
    v11 = (_QWORD *)cam_mem_trace_alloc(256, 0xCC0u, 0, "cam_mem_mgr_init", 0x35Fu);
  else
    v11 = (_QWORD *)_kvmalloc_node_noprof(256, 0, 3520, 0xFFFFFFFFLL);
  qword_2FDB90 = (__int64)v11;
  if ( !v11 )
  {
    v0 = -12;
    goto LABEL_71;
  }
  qword_2FDB98 = 2048;
  v11[30] = 0;
  v11[31] = 0;
  v11[28] = 0;
  v11[29] = 0;
  v11[26] = 0;
  v11[27] = 0;
  v11[24] = 0;
  v11[25] = 0;
  v11[22] = 0;
  v11[23] = 0;
  v11[20] = 0;
  v11[21] = 0;
  v11[18] = 0;
  v11[19] = 0;
  v11[16] = 0;
  v11[17] = 0;
  v11[14] = 0;
  v11[15] = 0;
  v11[12] = 0;
  v11[13] = 0;
  v11[10] = 0;
  v11[11] = 0;
  v11[8] = 0;
  v11[9] = 0;
  v11[6] = 0;
  v11[7] = 0;
  v11[4] = 0;
  v11[5] = 0;
  v11[2] = 0;
  v11[3] = 0;
  *v11 = 0;
  v11[1] = 0;
  _X8 = qword_2FDB90;
LABEL_94:
  __asm { PRFM            #0x11, [X8] }
  do
    v27 = __ldxr((unsigned __int64 *)_X8);
  while ( __stxr(v27 | 1, (unsigned __int64 *)_X8) );
  v14 = &unk_2FDCD0;
  v13 = 2047;
  do
  {
    v14[12] = -1;
    v14[16] = -1;
    _mutex_init(v14, "&tbl.bufq[i].q_lock", &cam_mem_mgr_init___key);
    --v13;
    v14[70] = 0;
    v14 += 74;
  }
  while ( v13 );
  _mutex_init(&tbl, "&tbl.m_lock", &cam_mem_mgr_init___key_16);
  cam_mem_mgr_state = 1;
  v28[0] = 0;
  if ( !g_cam_mem_mgr_debug )
  {
    if ( (unsigned int)cam_debugfs_create_subdir("memmgr", v28) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x400000,
        1,
        "cam_mem_mgr_create_debug_fs",
        717,
        "DebugFS could not create directory!");
    }
    else
    {
      g_cam_mem_mgr_debug = v28[0];
      debugfs_create_bool("alloc_profile_enable", 420);
      debugfs_create_bool("override_cpu_access_dir", 420);
      debugfs_create_file("mem_trace", 420, g_cam_mem_mgr_debug, 0, &cam_mem_trace);
    }
  }
  cam_common_register_mini_dump_cb(cam_mem_mgr_mini_dump_cb, "cam_mem", 0);
  v0 = cam_smmu_driver_init(&dword_391BBC);
  if ( v0 )
    goto LABEL_67;
  if ( !dword_391BA8 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_init",
      894,
      "Invalid number of supported handles");
    v0 = -22;
    goto LABEL_67;
  }
  v16 = (__int64 *)&unk_2FDD38;
  v17 = 1;
  v18 = -606200;
  qword_391BB0 = 40LL * dword_391BA8;
  _ReadStatusReg(SP_EL0);
  while ( mem_trace_en == 1 )
  {
    v19 = cam_mem_trace_alloc(qword_391BB0, 0xCC0u, 0, "cam_mem_mgr_init", 0x388u);
    *v16 = v19;
    if ( !v19 )
      goto LABEL_83;
LABEL_81:
    v18 += 296LL;
    v0 = 0;
    ++v17;
    v16 += 37;
    if ( v18 == -288 )
      goto LABEL_74;
  }
  v20 = _kvmalloc_node_noprof(qword_391BB0, 0, 3520, 0xFFFFFFFFLL);
  *v16 = v20;
  if ( v20 )
    goto LABEL_81;
LABEL_83:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x400000,
    1,
    "cam_mem_mgr_init",
    907,
    "Failed to allocate hdls array queue idx: %d",
    v17);
  if ( (unsigned int)v17 >= 2 )
  {
    v21 = v16 - 37;
    do
    {
      _X8 = (unsigned __int8)mem_trace_en;
      if ( mem_trace_en == 1 )
      {
        if ( v18 < 0xFFFFFFFFFFF6BF58LL )
          goto LABEL_93;
        cam_mem_trace_free((_QWORD *)*v21, 0);
      }
      else
      {
        if ( v18 < 0xFFFFFFFFFFF6BF58LL )
        {
LABEL_93:
          __break(1u);
          goto LABEL_94;
        }
        kvfree(*v21);
      }
      --v17;
      *v21 = 0;
      v18 -= 296LL;
      v21 -= 37;
    }
    while ( v17 > 1 );
  }
  v0 = -12;
LABEL_67:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)qword_2FDB90, 0);
  else
    kvfree(qword_2FDB90);
  qword_2FDB90 = 0;
  cam_mem_mgr_state = 0;
LABEL_71:
  if ( (debug_mdl & 0x400000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x400000,
      4,
      "cam_mem_mgr_put_dma_heaps",
      1339,
      "Releasing DMA Buf heaps usage");
LABEL_74:
  _ReadStatusReg(SP_EL0);
  return v0;
}
