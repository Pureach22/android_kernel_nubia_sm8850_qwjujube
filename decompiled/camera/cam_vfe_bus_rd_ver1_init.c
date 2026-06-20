__int64 __fastcall cam_vfe_bus_rd_ver1_init(
        __int64 (__fastcall *a1)(),
        __int64 (__fastcall *a2)(),
        const void *a3,
        const void *a4,
        _QWORD *a5)
{
  __int64 v6; // x21
  __int64 (__fastcall *v7)(); // x24
  __int64 (__fastcall *v8)(); // x23
  __int64 v10; // x0
  __int64 result; // x0
  _QWORD *v12; // x19
  __int64 v13; // x0
  __int64 v14; // x20
  int v15; // w8
  __int64 v16; // x8
  int v17; // w0
  _QWORD *v18; // x0
  __int64 v19; // x0
  unsigned int v20; // w8
  __int64 v21; // x9
  __int64 v22; // x0
  int v23; // w22
  unsigned int v24; // w8
  __int64 v25; // x9
  int v26; // w6
  __int64 v27; // x0
  int v28; // w8
  int v29; // w8
  unsigned int v30; // w8
  __int64 v31; // x10
  int v32; // w22
  __int64 v33; // x8
  _QWORD *v34; // x0
  _QWORD *v35; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v37; // x27

  v6 = (__int64)a3;
  v7 = a1;
  v8 = a2;
  if ( !a1 || !a2 || !a3 || !a4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_rd_ver1_init",
      1241,
      "Inval_prms soc_info:%pK hw_intf:%pK hw_info%pK",
      a1,
      a2,
      a3);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_rd_ver1_init",
      1242,
      "controller: %pK",
      a4);
    return 4294967274LL;
  }
  if ( mem_trace_en == 1 )
    v10 = cam_mem_trace_alloc(128, 0xCC0u, 0, "cam_vfe_bus_rd_ver1_init", 0x4DFu);
  else
    v10 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
  v12 = (_QWORD *)v10;
  if ( v10 )
  {
    if ( mem_trace_en == 1 )
      v13 = cam_mem_trace_alloc(648, 0xCC0u, 0, "cam_vfe_bus_rd_ver1_init", 0x4E7u);
    else
      v13 = _kvmalloc_node_noprof(648, 0, 3520, 0xFFFFFFFFLL);
    v14 = v13;
    if ( !v13 )
    {
      LODWORD(v6) = -12;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_rd_ver1_init",
          1257,
          "Failed to alloc for vfe_bus_priv");
      goto LABEL_52;
    }
    *v12 = v13;
    *(_DWORD *)(v13 + 312) = *(_DWORD *)(v6 + 64);
    v15 = *(_DWORD *)(v6 + 96);
    *(_QWORD *)(v13 + 288) = 0;
    *(_DWORD *)(v13 + 316) = v15;
    *(_DWORD *)v13 = *((_DWORD *)v7 + 5);
    if ( *((_DWORD *)v7 + 120) )
      v16 = *((_QWORD *)v7 + 36);
    else
      v16 = 0;
    *(_QWORD *)(v13 + 8) = v16;
    *(_QWORD *)(v13 + 16) = v8;
    *(_QWORD *)(v13 + 32) = a4;
    *(_QWORD *)(v13 + 40) = v6;
    *(_DWORD *)(v13 + 640) = *(_DWORD *)(v6 + 112);
    _mutex_init(v13 + 240, "&bus_priv->common_data.bus_mutex", &cam_vfe_bus_rd_ver1_init___key);
    v17 = cam_irq_controller_init("vfe_bus_rd", *(_QWORD *)(v14 + 8), (unsigned int *)(v6 + 32), (__int64 *)(v14 + 24));
    if ( v17 )
    {
      LODWORD(v6) = v17;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_bus_rd_ver1_init",
        1283,
        "cam_irq_controller_init failed");
LABEL_19:
      v18 = (_QWORD *)*v12;
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v18, 0);
      else
        kvfree(v18);
LABEL_52:
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v12, 0);
      else
        kvfree(v12);
      return (unsigned int)v6;
    }
    if ( !*(_DWORD *)(v14 + 312) )
      goto LABEL_33;
    if ( (mem_trace_en & 1) != 0 )
    {
      v19 = cam_mem_trace_alloc(112, 0xCC0u, 0, "cam_vfe_bus_init_rm_resource", 0x1FAu);
      if ( !v19 )
        goto LABEL_57;
    }
    else
    {
      v19 = _kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
      if ( !v19 )
      {
LABEL_57:
        v23 = 0;
LABEL_58:
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_init_rm_resource",
            509,
            "Failed to alloc VFE:%d RM res priv",
            *(_DWORD *)v14);
        v6 = 4294967284LL;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_rd_ver1_init",
          1292,
          "Init RM failed for client:%d, rc=%d",
          v23,
          -12);
        while ( 2 )
        {
          v32 = v23 - 1;
          if ( v32 >= 0 )
          {
            if ( (unsigned int)v32 > 1 )
            {
              while ( 1 )
              {
                do
                {
                  __break(0x5512u);
                  StatusReg = _ReadStatusReg(SP_EL0);
                  v37 = *(_QWORD *)(StatusReg + 80);
                  *(_QWORD *)(StatusReg + 80) = &cam_vfe_bus_init_rm_resource__alloc_tag;
                  v22 = _kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
                  *(_QWORD *)(StatusReg + 80) = v37;
                  v23 = 1;
                  if ( !v22 )
                    goto LABEL_58;
LABEL_32:
                  *(_QWORD *)(v14 + 496) = v22;
                  *(_QWORD *)(v22 + 8) = v14;
                  *(_QWORD *)(v22 + 16) = v6 + 96;
                  *(_DWORD *)v22 = 1;
                  *(_DWORD *)(v14 + 480) = 1;
                  *(_QWORD *)(v14 + 504) = v14 + 504;
                  *(_QWORD *)(v14 + 512) = v14 + 504;
                  v24 = *(_DWORD *)(v14 + 312);
                  v25 = *(_QWORD *)(v14 + 16);
                  *(_QWORD *)(v14 + 560) = v8;
                  *(_QWORD *)(v14 + 568) = v7;
                  *(_QWORD *)(v14 + 488) = v25;
                }
                while ( v24 > 2 );
LABEL_33:
                if ( !*(_DWORD *)(v14 + 316) )
                  goto LABEL_45;
                v26 = *(_DWORD *)(v6 + 100);
                if ( v26 )
                  break;
                if ( *(_DWORD *)(v14 + 480) || *(_QWORD *)(v14 + 496) )
                {
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    8,
                    1,
                    "cam_vfe_bus_init_vfe_bus_read_resource",
                    794,
                    "Error. Looks like same resource is init again");
                  v6 = 4294967282LL;
                  goto LABEL_39;
                }
                if ( mem_trace_en == 1 )
                {
                  v27 = cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_vfe_bus_init_vfe_bus_read_resource", 0x31Fu);
                  if ( !v27 )
                    goto LABEL_75;
                }
                else
                {
                  v27 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
                  if ( !v27 )
                  {
LABEL_75:
                    v6 = 4294967284LL;
                    goto LABEL_39;
                  }
                }
                *(_QWORD *)(v14 + 496) = v27;
                *(_DWORD *)(v14 + 472) = 5;
                *(_DWORD *)(v14 + 480) = 1;
                *(_QWORD *)(v14 + 504) = v14 + 504;
                *(_QWORD *)(v14 + 512) = v14 + 504;
                v28 = *(_DWORD *)(v6 + 100);
                *(_QWORD *)(v27 + 8) = v14;
                *(_DWORD *)v27 = v28;
                *(_DWORD *)(v27 + 76) = *(_DWORD *)(v6 + 104);
                v29 = *(_DWORD *)(v6 + 108);
                *(_DWORD *)(v27 + 96) = 0;
                *(_DWORD *)(v27 + 80) = v29;
                *(_QWORD *)(v14 + 568) = cam_vfe_bus_stop_vfe_bus_rd;
                v30 = *(_DWORD *)(v14 + 316);
                v31 = *(_QWORD *)(v14 + 16);
                *(_QWORD *)(v14 + 560) = cam_vfe_bus_start_vfe_bus_rd;
                *(_QWORD *)(v14 + 576) = cam_vfe_bus_rd_process_cmd;
                *(_QWORD *)(v14 + 488) = v31;
                if ( v30 <= 1 )
                {
LABEL_45:
                  *(_DWORD *)(v14 + 232) = 0;
                  v12[5] = cam_vfe_bus_acquire_vfe_bus_rd;
                  v12[6] = &cam_vfe_bus_release_vfe_bus_rd;
                  v12[7] = cam_vfe_bus_start_hw_0;
                  v12[8] = cam_vfe_bus_stop_hw_0;
                  v12[2] = cam_vfe_bus_init_hw_0;
                  v12[3] = cam_vfe_bus_deinit_hw_0;
                  v12[11] = _cam_vfe_bus_rd_process_cmd;
                  v12[14] = cam_vfe_bus_rd_ver1_handle_irq;
                  v12[15] = 0;
                  *a5 = v12;
                  return 0;
                }
              }
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_vfe_bus_init_vfe_bus_read_resource",
                786,
                "Init VFE Out failed, Invalid type=%d",
                v26);
              v6 = 4294967274LL;
LABEL_39:
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_vfe_bus_rd_ver1_init",
                1302,
                "Init VFE Out failed for client:%d, rc=%d",
                0,
                v6);
              v23 = *(_DWORD *)(v14 + 312);
              continue;
            }
            v33 = v14 + 320 + 152LL * (unsigned int)v32;
            *(_DWORD *)(v33 + 8) = 0;
            *(_QWORD *)(v33 + 32) = v33 + 32;
            *(_QWORD *)(v33 + 40) = v33 + 32;
            v34 = *(_QWORD **)(v33 + 24);
            *(_QWORD *)(v33 + 88) = 0;
            *(_QWORD *)(v33 + 96) = 0;
            *(_QWORD *)(v33 + 112) = 0;
            *(_QWORD *)(v33 + 120) = 0;
            *(_QWORD *)(v33 + 16) = 0;
            *(_QWORD *)(v33 + 24) = 0;
            if ( v34 )
            {
              if ( (mem_trace_en & 1) != 0 )
                cam_mem_trace_free(v34, 0);
              else
                kvfree(v34);
            }
            if ( v32 == 1 )
            {
              *(_DWORD *)(v14 + 328) = 0;
              *(_QWORD *)(v14 + 352) = v14 + 352;
              *(_QWORD *)(v14 + 360) = v14 + 352;
              v35 = *(_QWORD **)(v14 + 344);
              *(_QWORD *)(v14 + 408) = 0;
              *(_QWORD *)(v14 + 416) = 0;
              *(_QWORD *)(v14 + 432) = 0;
              *(_QWORD *)(v14 + 440) = 0;
              *(_QWORD *)(v14 + 336) = 0;
              *(_QWORD *)(v14 + 344) = 0;
              if ( v35 )
              {
                if ( mem_trace_en == 1 )
                  cam_mem_trace_free(v35, 0);
                else
                  kvfree(v35);
              }
            }
          }
          goto LABEL_19;
        }
      }
    }
    *(_QWORD *)(v14 + 344) = v19;
    v8 = cam_vfe_bus_start_rm;
    *(_QWORD *)(v19 + 8) = v14;
    *(_QWORD *)(v19 + 16) = v6 + 68;
    *(_DWORD *)v19 = 0;
    v7 = cam_vfe_bus_stop_rm;
    *(_DWORD *)(v14 + 328) = 1;
    *(_QWORD *)(v14 + 352) = v14 + 352;
    *(_QWORD *)(v14 + 360) = v14 + 352;
    v20 = *(_DWORD *)(v14 + 312);
    v21 = *(_QWORD *)(v14 + 16);
    *(_QWORD *)(v14 + 408) = cam_vfe_bus_start_rm;
    *(_QWORD *)(v14 + 416) = cam_vfe_bus_stop_rm;
    *(_QWORD *)(v14 + 336) = v21;
    if ( v20 < 2 )
      goto LABEL_33;
    if ( (mem_trace_en & 1) != 0 )
    {
      v22 = cam_mem_trace_alloc(112, 0xCC0u, 0, "cam_vfe_bus_init_rm_resource", 0x1FAu);
      v23 = 1;
      if ( v22 )
        goto LABEL_32;
    }
    else
    {
      v22 = _kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
      v23 = 1;
      if ( v22 )
        goto LABEL_32;
    }
    goto LABEL_58;
  }
  result = 4294967284LL;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_rd_ver1_init",
      1249,
      "Failed to alloc for vfe_bus");
    return 4294967284LL;
  }
  return result;
}
