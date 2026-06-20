void cam_mem_mgr_deinit()
{
  __int64 v0; // x0
  _QWORD *v1; // x27
  __int64 v2; // x28
  int v3; // w23
  void *v4; // x0
  unsigned int v6; // w26
  __int64 v7; // x1
  const void *v8; // x26
  __int64 v9; // x7
  _QWORD **v11; // x20
  __int64 v12; // x21
  _QWORD *v13; // x0
  __int64 *v14; // x0
  __int64 **v15; // x8
  __int64 *v16; // x20
  __int64 *v17; // x9
  __int64 *v18; // x10
  __int64 **v19; // x9
  __int64 **v20; // x8
  __int64 *v21; // x11
  unsigned __int64 v26; // x9

  if ( cam_mem_mgr_state )
  {
    cam_mem_mgr_state = 0;
    if ( (cam_presil_mode_enabled() & 1) != 0 )
    {
      v0 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             0x400000,
             3,
             "cam_mem_mgr_cleanup_table",
             2653,
             "PRESIL-HACK  not cleaning up table, HFI not free/alloc hack");
    }
    else
    {
      v1 = &unk_2FDCC8;
      v2 = -2047;
      v3 = 1;
      do
      {
        mutex_lock(v1 + 1);
        raw_spin_lock(v1 + 36);
        if ( (v1[15] & 1) != 0 )
        {
          if ( ((debug_priority == 0) & ((unsigned int)debug_mdl >> 22)) != 0 )
          {
            v6 = v2 + 2048;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x400000,
              4,
              "cam_mem_mgr_cleanup_table",
              2670,
              "Buffer active at idx=%d fd=0x%x handle:0x%x kref:%d name: %s",
              v2 + 2048,
              *((_DWORD *)v1 + 14),
              *((_DWORD *)v1 + 18),
              *((_DWORD *)v1 + 36),
              (const char *)v1 + 152);
          }
          else
          {
            v6 = v3;
          }
          raw_spin_unlock(v1 + 36);
          if ( (v1[11] & 0x801) == 1 )
            v7 = 3;
          else
            v7 = 1;
          cam_mem_util_unmap_hw_va(v6, v7, 0, 1);
          if ( (v1[11] & 8) != 0 )
          {
            v8 = (const void *)*v1;
            v9 = v1[12];
            if ( *v1 && v9 )
            {
              cam_compat_util_put_dmabuf_va(*v1, v1[12]);
              if ( (unsigned int)dma_buf_end_cpu_access(v8, 0) )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x400000,
                  1,
                  "cam_mem_util_unmap_cpu_va",
                  237,
                  "Failed in end cpu access, dmabuf=%pK",
                  v8);
            }
            else
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x400000,
                1,
                "cam_mem_util_unmap_cpu_va",
                223,
                "Invalid input args %pK %llX",
                (const void *)*v1,
                v9);
            }
          }
          if ( *v1 )
            dma_buf_put(*v1);
          *((_DWORD *)v1 + 14) = -1;
          v4 = (void *)v1[14];
          v1[8] = 0;
          *((_DWORD *)v1 + 22) = 0;
          *((_DWORD *)v1 + 18) = -1;
          v1[10] = 0;
          *((_DWORD *)v1 + 26) = 0;
          *v1 = 0;
          *((_WORD *)v1 + 60) = 0;
          *((_BYTE *)v1 + 123) = 0;
          memset(v4, 0, qword_391BB0);
          *((_DWORD *)v1 + 36) = 1;
          *((_DWORD *)v1 + 71) = 1;
        }
        else
        {
          if ( ((debug_priority == 0) & ((unsigned int)debug_mdl >> 22)) != 0 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x400000,
              4,
              "cam_mem_mgr_cleanup_table",
              2662,
              "Buffer inactive at idx=%d, continuing",
              v2 + 2048);
          raw_spin_unlock(v1 + 36);
        }
        mutex_unlock(v1 + 1);
        _CF = __CFADD__(v2++, 1);
        ++v3;
        v1 += 37;
      }
      while ( !_CF );
      mutex_lock(&tbl);
      memset((void *)qword_2FDB90, 0, ((unsigned int)(qword_2FDB98 + 63) >> 3) & 0x1FFFFFF8);
      _X8 = (unsigned __int64 *)qword_2FDB90;
      __asm { PRFM            #0x11, [X8] }
      do
        v26 = __ldxr(_X8);
      while ( __stxr(v26 | 1, _X8) );
      v0 = mutex_unlock(&tbl);
    }
    cam_smmu_driver_deinit(v0);
    mutex_lock(&tbl);
    memset((void *)qword_2FDB90, 0, ((unsigned int)(qword_2FDB98 + 63) >> 3) & 0x1FFFFFF8);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)qword_2FDB90, 0);
    else
      kvfree(qword_2FDB90);
    v11 = (_QWORD **)&unk_2FDD38;
    v12 = 2047;
    qword_2FDB90 = 0;
    qword_391BA0 = -1;
    do
    {
      v13 = *v11;
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v13, 0);
      else
        kvfree(v13);
      --v12;
      *v11 = nullptr;
      v11 += 37;
    }
    while ( v12 );
    mutex_unlock(&tbl);
    mem_trace_en = byte_2FDB54;
    if ( (byte_2FDB54 & 1) == 0 )
    {
      v14 = (__int64 *)qword_2FDB30;
      if ( (__int64 *)qword_2FDB30 != &qword_2FDB30 )
      {
        do
        {
          v16 = (__int64 *)*v14;
          v15 = (__int64 **)v14[1];
          if ( *v15 == v14 && (__int64 *)v16[1] == v14 )
          {
            v16[1] = (__int64)v15;
            *v15 = v16;
          }
          else
          {
            _list_del_entry_valid_or_report(v14);
            v14 = v17;
          }
          *v14 = (__int64)v14;
          v14[1] = (__int64)v14;
          cam_mem_trace_free(v14, 0);
          v14 = v16;
        }
        while ( v16 != &qword_2FDB30 );
      }
      v18 = &g_trace;
      v19 = (__int64 **)g_trace;
      if ( (__int64 *)g_trace != &g_trace )
      {
        do
        {
          v21 = *v19;
          v20 = (__int64 **)v19[1];
          if ( *v20 == (__int64 *)v19 && (__int64 **)v21[1] == v19 )
          {
            v21[1] = (__int64)v20;
            *v20 = v21;
          }
          else
          {
            _list_del_entry_valid_or_report(v19);
          }
          *v19 = (__int64 *)v19;
          v19[1] = (__int64 *)v19;
          v19 = (__int64 **)v21;
        }
        while ( v21 != v18 );
      }
      if ( qword_2FDB48 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          2,
          "cam_mem_trace_reset",
          272,
          "Possible leakage: total_trace_mem NOT zero: %lu",
          qword_2FDB48);
      qword_2FDB48 = 0;
      dword_2FDB50 = 0;
      byte_2FDB54 = 0;
    }
  }
}
