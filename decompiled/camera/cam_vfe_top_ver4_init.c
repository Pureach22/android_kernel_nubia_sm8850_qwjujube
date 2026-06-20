__int64 __fastcall cam_vfe_top_ver4_init(__int64 a1, __int64 a2, __int64 *a3, __int64 a4, unsigned __int64 a5)
{
  _BYTE *v5; // x23
  __int64 v9; // x0
  _QWORD *v10; // x19
  __int64 v11; // x0
  __int64 v12; // x22
  unsigned int v13; // w7
  __int64 v14; // x28
  unsigned int v15; // w27
  _DWORD *v16; // x23
  __int64 v17; // x24
  unsigned __int64 v18; // x10
  int v19; // w8
  __int64 v20; // x25
  __int64 v21; // x4
  int v22; // w7
  _QWORD *v23; // x3
  unsigned int v24; // w0
  unsigned int v25; // w23
  __int64 v26; // x8
  unsigned int v27; // w6
  __int64 v28; // x25
  __int64 v29; // x27
  int *v30; // x28
  __int64 v31; // x8
  int v32; // t1
  int v33; // w0
  _QWORD *v34; // x0
  unsigned __int64 StatusReg; // x22
  _DWORD *v36; // x24
  __int64 v37; // x23
  _QWORD *v39; // [xsp+8h] [xbp-18h]

  v5 = &unk_2FD000;
  if ( mem_trace_en == 1 )
    v9 = cam_mem_trace_alloc(112, 0xCC0u, 0, "cam_vfe_top_ver4_init", 0xC0Eu);
  else
    v9 = _kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
  v10 = (_QWORD *)v9;
  if ( !v9 )
    goto LABEL_44;
  do
  {
    if ( v5[2904] == 1 )
      v11 = cam_mem_trace_alloc(10936, 0xCC0u, 0, "cam_vfe_top_ver4_init", 0xC16u);
    else
      v11 = _kvmalloc_node_noprof(10936, 0, 3520, 0xFFFFFFFFLL);
    v12 = v11;
    if ( !v11 )
    {
      LODWORD(a5) = -12;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_top_ver4_init",
          3096,
          "VFE:%u Error, Failed to alloc for vfe_top_priv",
          *(_DWORD *)(a2 + 4));
      goto LABEL_50;
    }
    *v10 = v11;
    *(_QWORD *)(v11 + 10440) = 0;
    v13 = *((_DWORD *)a3 + 26);
    if ( v13 >= 8 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_ver4_init",
        3106,
        "VFE:%u Invalid number of input rsrc: %d, max: %d",
        *(unsigned int *)(a2 + 4));
      LODWORD(a5) = -22;
LABEL_39:
      v34 = (_QWORD *)*v10;
      if ( v5[2904] == 1 )
        cam_mem_trace_free(v34, 0);
      else
        kvfree(v34);
LABEL_50:
      if ( v5[2904] == 1 )
        cam_mem_trace_free(v10, 0);
      else
        kvfree(v10);
      return (unsigned int)a5;
    }
    *(_DWORD *)(v11 + 1088) = v13;
    if ( !v13 )
    {
      v25 = 0;
LABEL_28:
      v10[1] = cam_vfe_top_ver4_get_hw_caps;
      v10[2] = cam_vfe_top_ver4_init_hw;
      v10[4] = cam_vfe_top_ver4_reset;
      v10[5] = cam_vfe_top_ver4_reserve;
      v10[6] = cam_vfe_top_ver4_release;
      v10[7] = &cam_vfe_top_ver4_start;
      v10[8] = &cam_vfe_top_ver4_stop;
      v10[9] = cam_vfe_top_ver4_read;
      v10[10] = cam_vfe_top_ver4_write;
      v10[11] = cam_vfe_top_ver4_process_cmd;
      *(_QWORD *)a5 = v10;
      *(_QWORD *)(v12 + 16) = a3;
      *(_QWORD *)(v12 + 10432) = a1;
      *(_QWORD *)v12 = a2;
      *(_DWORD *)(v12 + 1092) = *(_DWORD *)(a2 + 4);
      v26 = *a3;
      *(_QWORD *)(v12 + 8) = *a3;
      v27 = *(_DWORD *)(v26 + 248);
      if ( v27 < 9 )
      {
        LODWORD(a5) = 0;
        return (unsigned int)a5;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_ver4_init",
        3188,
        "Invalid number of perf counters: %d max: %d",
        v27,
        8);
      LODWORD(a5) = -22;
LABEL_30:
      if ( v25 )
      {
        v28 = 0;
        v29 = 152LL * v25;
        v30 = (int *)a3 + v25 + 27;
        do
        {
          v32 = *v30--;
          v33 = cam_vfe_res_mux_deinit((_QWORD *)(v12 + v29 - 128));
          if ( v32 == 64 )
          {
            if ( v33 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_vfe_top_ver4_init",
                3201,
                "VFE:%u Camif Deinit failed",
                *(_DWORD *)(a2 + 4));
          }
          else if ( v33 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_vfe_top_ver4_init",
              3208,
              "VFE:%u Camif lite res id %d Deinit failed",
              *(_DWORD *)(a2 + 4),
              *(_DWORD *)(v12 + v29 - 124));
          }
          v28 += 152;
          v31 = v12 + v29;
          v12 -= 152;
          *(_DWORD *)(v31 - 120) = 0;
        }
        while ( v29 != v28 );
      }
      v5 = &unk_2FD000;
      goto LABEL_39;
    }
    v14 = 0;
    v15 = 0;
    v16 = a3 + 14;
    v17 = 1306;
    v39 = (_QWORD *)a5;
    while ( v14 != 1064 )
    {
      v20 = v12 + v14;
      *(_DWORD *)(v12 + v14 + 24) = 4;
      v21 = v12 + v14 + 24;
      *(_QWORD *)(v21 + 16) = a2;
      *(_DWORD *)(v21 + 8) = 1;
      *(_QWORD *)(v12 + 8 * v17) = 0;
      v22 = *v16;
      if ( *v16 == 0x10000 )
      {
        *(_DWORD *)(v20 + 28) = 8;
        a5 = (unsigned int)cam_vfe_res_mux_init(v12, a2, a1, a3 + 3, v21, a4);
        scnprintf(v20 + 152, 16, "PDLIB");
LABEL_24:
        if ( (_DWORD)a5 )
        {
LABEL_25:
          v25 = v17 - 1306;
          goto LABEL_30;
        }
        goto LABEL_14;
      }
      if ( v22 == 4096 )
      {
        if ( v15 < *((_DWORD *)a3 + 41) )
        {
          *(_DWORD *)(v12 + v14 + 28) = v15 + 3;
          scnprintf(v12 + v14 + 152, 16, "RDI_%d", v15);
          v23 = (_QWORD *)(a3[5] + 16LL * (int)v15++);
          v24 = cam_vfe_res_mux_init(v12, a2, a1, v23, v12 + v14 + 24, a4);
          a5 = v24;
          if ( v24 )
            goto LABEL_25;
          goto LABEL_14;
        }
      }
      else if ( v22 == 64 )
      {
        *(_DWORD *)(v12 + v14 + 28) = 0;
        a5 = (unsigned int)cam_vfe_res_mux_init(v12, a2, a1, a3 + 1, v21, a4);
        scnprintf(v12 + v14 + 152, 16, "CAMIF");
        goto LABEL_24;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        8,
        2,
        "cam_vfe_top_ver4_init",
        3160,
        "VFE:%u Invalid mux type: %u",
        *(unsigned int *)(a2 + 4));
LABEL_14:
      v18 = v17 - 1305;
      v19 = v17 + 1;
      v14 += 152;
      ++v16;
      ++v17;
      if ( v18 >= *(unsigned int *)(v12 + 1088) )
      {
        a5 = (unsigned __int64)v39;
        v25 = v19 - 1306;
        goto LABEL_28;
      }
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v36 = v16;
    v37 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_vfe_top_ver4_init__alloc_tag;
    v10 = (_QWORD *)_kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v37;
    v5 = v36;
  }
  while ( v10 );
LABEL_44:
  LODWORD(a5) = -12;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_top_ver4_init",
      3088,
      "VFE:%u Error, Failed to alloc for vfe_top",
      *(_DWORD *)(a2 + 4));
  return (unsigned int)a5;
}
