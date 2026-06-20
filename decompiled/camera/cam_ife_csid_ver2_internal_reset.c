__int64 __fastcall cam_ife_csid_ver2_internal_reset(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // w0
  const char *v4; // x5
  unsigned int v5; // w6
  __int64 v6; // x4
  unsigned int v7; // w0
  unsigned int v8; // w19
  __int64 v10; // x8
  __int64 v11; // x26
  __int64 v12; // x21
  __int64 v13; // x20
  __int64 v14; // x22
  __int64 v15; // x23
  __int64 v16; // x8
  unsigned int *v17; // x10
  unsigned int v18; // w27
  unsigned int v19; // w28
  unsigned int *v20; // x8
  unsigned int *v21; // x9
  __int64 result; // x0
  unsigned int v23; // w22
  unsigned int v24; // w23
  unsigned int v25; // w22
  int v26; // w8
  __int64 *v27; // x8
  __int64 v28; // x26
  __int64 v29; // x27
  __int64 v30; // x28
  __int64 v31; // x22
  int v32; // w23
  int v33; // w24
  int v34; // w25
  int v35; // w0
  int v36; // w0
  __int64 v37; // x3
  __int64 v38; // x5
  __int64 v39; // x7
  __int64 v40; // x9
  int v41; // w10
  __int64 v42; // x8
  int v43; // w23
  _QWORD v44[2]; // [xsp+20h] [xbp-10h] BYREF

  v44[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 31128);
  if ( *(_DWORD *)(v10 + 92) != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_internal_reset",
      3943,
      "CSID[%u] powered down state",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
    result = 4294967274LL;
LABEL_36:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v11 = *(_QWORD *)(v10 + 384);
  v12 = a3;
  v13 = a2;
  v14 = **(_QWORD **)(a1 + 31136);
  if ( a2 == 1 )
  {
    v15 = *(_QWORD *)(v14 + 128);
    cam_io_w_mb(0, v11 + *(unsigned int *)(v15 + 32));
    cam_io_w_mb(0, v11 + *(unsigned int *)(v15 + 36));
    v10 = *(_QWORD *)(a1 + 31128);
  }
  if ( *(_DWORD *)(a1 + 32240) != 2 )
  {
    *(_DWORD *)(v10 + 56) = 0;
    v16 = 129;
    v17 = *(unsigned int **)(v14 + 120);
    if ( !(_DWORD)v12 )
      v16 = 128;
    v18 = v17[v16] << v17[57];
    v19 = v17[131] << v17[58];
    cam_io_w_mb(v19 | v18, v11 + v17[4]);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_internal_reset",
        3976,
        "CSID[%u] reset_cfg: 0x%x",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
        v19 | v18);
      if ( (_DWORD)v13 )
      {
LABEL_10:
        v20 = *(unsigned int **)(v14 + 120);
        if ( (_DWORD)v13 == 2 )
        {
          v21 = v20 + 134;
        }
        else
        {
          if ( (_DWORD)v13 != 1 )
          {
            v23 = 0;
LABEL_19:
            cam_io_w_mb(v23, v11 + v20[5]);
            if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_ife_csid_ver2_internal_reset",
                3989,
                "CSID[%u] reset_cmd: 0x%x",
                *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
                v23);
              if ( (_DWORD)v13 )
                goto LABEL_22;
            }
            else if ( (_DWORD)v13 )
            {
LABEL_22:
              v10 = *(_QWORD *)(a1 + 31128);
              goto LABEL_23;
            }
            result = 0;
            goto LABEL_36;
          }
          v21 = v20 + 133;
        }
LABEL_18:
        v23 = *v21;
        goto LABEL_19;
      }
    }
    else if ( (_DWORD)v13 )
    {
      goto LABEL_10;
    }
    v20 = *(unsigned int **)(v14 + 120);
    v21 = v20 + 132;
    goto LABEL_18;
  }
LABEL_23:
  if ( cam_common_wait_for_completion_timeout(v10 + 56) )
  {
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_wait_for_reset",
        3903,
        "CSID[%u], sync-mode[%d] reset success",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
        *(_DWORD *)(a1 + 32240));
      result = 0;
    }
    goto LABEL_35;
  }
  if ( *(_BYTE *)(a1 + 2213) == 1 )
  {
    v24 = *(_DWORD *)(a1 + 32240);
    v25 = *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL);
    v26 = cam_io_r_mb(
            *(_QWORD *)(*(_QWORD *)(a1 + 31128) + 384LL)
          + *(unsigned int *)(*(_QWORD *)(**(_QWORD **)(a1 + 31136) + 120LL) + 104LL));
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_wait_for_reset",
      3893,
      "CSID[%u], sync-mode[%d] test_bus: 0x%x reset timed out",
      v25,
      v24,
      v26);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_wait_for_reset",
      3896,
      "CSID[%u], sync-mode[%d] reset timed out",
      *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL),
      *(unsigned int *)(a1 + 32240));
  }
  v27 = *(__int64 **)(a1 + 31136);
  v28 = *(_QWORD *)(a1 + 31128);
  HIDWORD(v44[0]) = 0;
  v29 = *v27;
  v30 = *(_QWORD *)(v28 + 384);
  v31 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
  v32 = cam_io_r_mb(v30 + *(unsigned int *)(*(_QWORD *)(*v27 + 120) + 44LL));
  v33 = cam_io_r_mb(v30 + *(unsigned int *)(*(_QWORD *)(v29 + 120) + 52LL));
  v34 = cam_io_r_mb(v30 + *(unsigned int *)(*(_QWORD *)(v29 + 120) + 60LL));
  v35 = cam_io_r_mb(v30 + *(unsigned int *)(*(_QWORD *)(v29 + 120) + 68LL));
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_ife_csid_ver2_dump_imp_regs",
    3846,
    "CSID[%d] csid top status 0x%x, mask 0x%x, clr 0x%x, set 0x%x",
    v31,
    v32,
    v33,
    v34,
    v35);
  v36 = cam_io_r_mb(v30 + *(unsigned int *)(*(_QWORD *)(v29 + 120) + 16LL));
  v42 = *(_QWORD *)(v29 + 232);
  v43 = v36;
  if ( v42 )
  {
    if ( (unsigned int)v31 > 7 )
      goto LABEL_39;
    LODWORD(v42) = cam_io_r_mb(*(_QWORD *)(v28 + 408) + *(unsigned int *)(v42 + 4 * v31 + 32));
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_ife_csid_ver2_dump_imp_regs",
    3857,
    "CSID[%d] csid reset_cfg 0x%x, dual_csid_cfg 0x%x, is_dual_en %d",
    v31,
    v43,
    v42,
    *(unsigned __int8 *)(a1 + 2064));
  cam_soc_util_get_clk_level((_BYTE *)(v28 + 96), *(_QWORD *)(a1 + 32184), *(_DWORD *)(v28 + 2892), (int *)v44 + 1);
  if ( (unsigned int)v31 < 3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_csid_ver2_dump_imp_regs",
      3868,
      "CSID[%d] clk lvl %u received clk_rate %u applied clk_rate sw_client:%lu hw_client:[%lu %lu]",
      v31,
      HIDWORD(v44[0]),
      *(_QWORD *)(a1 + 32184),
      *(_QWORD *)(v28 + 2896),
      *(_QWORD *)(v28 + 16 * v31 + 2904),
      *(_QWORD *)(v28 + 16 * v31 + 2912));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_internal_reset",
      4002,
      "CSID[%u] Reset failed mode %d cmd %d loc %d",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      2,
      v13,
      v12);
    result = 4294967186LL;
LABEL_35:
    *(_DWORD *)(*(_QWORD *)(a1 + 31128) + 56LL) = 0;
    goto LABEL_36;
  }
LABEL_39:
  __break(0x5512u);
  if ( !v40 )
    return cam_ife_csid_hw_ver2_prepare_hw_cfg();
  ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD, __int64, _DWORD, _DWORD))cam_print_log)(
    3,
    *(_QWORD *)&v41 & 0x400000LL,
    4,
    v37,
    1312,
    v38 + 870,
    (unsigned int)a1,
    v39,
    v42,
    v40);
  v3 = dma_buf_begin_cpu_access(*(_QWORD *)(v13 + 64), *(_DWORD *)(v12 + 4) != 3);
  if ( v3 )
  {
    v4 = "dma begin access failed rc=%d";
    v5 = v3;
    v6 = 1320;
  }
  else
  {
    v7 = dma_buf_end_cpu_access(*(_QWORD *)(v13 + 64), 0);
    if ( !v7 )
    {
      v8 = 0;
      goto LABEL_46;
    }
    v4 = "dma end access failed rc=%d";
    v5 = v7;
    v6 = 1327;
  }
  v8 = v5;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x400000,
    1,
    "cam_mem_mgr_cache_ops",
    v6,
    v4);
LABEL_46:
  mutex_unlock(v13 + 72);
  return v8;
}
