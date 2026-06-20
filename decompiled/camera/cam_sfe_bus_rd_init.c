__int64 __fastcall cam_sfe_bus_rd_init(
        const void *a1,
        __int64 (__fastcall *a2)(),
        const void *a3,
        __int64 (__fastcall *a4)(),
        __int64 a5)
{
  __int64 v5; // x22
  unsigned __int64 v6; // x23
  __int64 (__fastcall *v7)(); // x24
  char *v8; // x28
  __int64 v11; // x0
  __int64 result; // x0
  _QWORD *v13; // x19
  __int64 v14; // x0
  __int64 v15; // x20
  __int64 v16; // x1
  int v17; // w8
  int v18; // w8
  int v19; // w0
  _QWORD *v20; // x0
  __int64 v21; // x27
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 v25; // x9
  const char *v26; // x3
  unsigned int v27; // w6
  __int64 v28; // x26
  __int64 v29; // x0
  unsigned int v30; // w8
  int v31; // w8
  unsigned __int64 v32; // x8
  __int64 v33; // x10
  __int64 v34; // x9
  __int64 v35; // x8
  __int64 v36; // x0
  _QWORD *v37; // x1
  int v38; // w6
  int v39; // w7
  char *v40; // x8
  _QWORD *v41; // x0
  char *v42; // x8
  _QWORD *v43; // x0
  char *v44; // x8
  _QWORD *v45; // x0
  unsigned __int64 v46; // x8
  __int64 v47; // x9
  _QWORD *v48; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v50; // x26
  const void *v51; // [xsp+8h] [xbp-18h]

  v5 = (__int64)a3;
  v6 = (unsigned __int64)a1;
  v7 = a2;
  if ( !a1 || !a2 || !a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_rd_init",
      2101,
      "Invalid_params soc_info:%pK hw_intf:%pK hw_info:%pK data:%pK",
      a1,
      a2,
      a3,
      v51);
    return 4294967274LL;
  }
  v8 = (char *)&unk_2FD000;
  if ( mem_trace_en == 1 )
    v11 = cam_mem_trace_alloc(128, 0xCC0u, 0, "cam_sfe_bus_rd_init", 0x83Au);
  else
    v11 = _kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
  v13 = (_QWORD *)v11;
  if ( !v11 )
    goto LABEL_94;
  while ( 2 )
  {
    if ( v8[2904] == 1 )
      v14 = cam_mem_trace_alloc(2824, 0xCC0u, 0, "cam_sfe_bus_rd_init", 0x842u);
    else
      v14 = _kvmalloc_node_noprof(2824, 0, 3520, 0xFFFFFFFFLL);
    v15 = v14;
    if ( !v14 )
    {
      LODWORD(a5) = -12;
      if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x40000000,
          4,
          "cam_sfe_bus_rd_init",
          2116,
          "Failed to alloc for sfe_bus_priv");
LABEL_100:
      if ( v8[2904] == 1 )
        cam_mem_trace_free(v13, 0);
      else
        kvfree(v13);
      return (unsigned int)a5;
    }
    *v13 = v14;
    *(_DWORD *)(v14 + 1864) = *(_DWORD *)(v5 + 64);
    *(_DWORD *)(v14 + 1868) = *(_DWORD *)(v5 + 240);
    *(_DWORD *)v14 = *(_DWORD *)(v6 + 20);
    if ( *(_DWORD *)(v6 + 480) )
      v16 = *(_QWORD *)(v6 + 288);
    else
      v16 = 0;
    *(_QWORD *)(v14 + 8) = v16;
    *(_QWORD *)(v14 + 16) = v7;
    *(_QWORD *)(v14 + 384) = a4;
    *(_QWORD *)(v14 + 24) = v5;
    *(_DWORD *)(v14 + 1836) = *(_DWORD *)(v5 + 356);
    *(_BYTE *)(v14 + 1860) = *(_BYTE *)(*(_QWORD *)(v5 + 368) + 16LL);
    v17 = *(_DWORD *)(*(_QWORD *)(v5 + 368) + 12LL);
    *(_QWORD *)(v14 + 32) = v6;
    *(_DWORD *)(v14 + 1856) = v17;
    *(_DWORD *)(v14 + 2808) = *(_DWORD *)(v5 + 344);
    *(_DWORD *)(v14 + 2812) = *(_DWORD *)(v5 + 348);
    v18 = *(_DWORD *)(v5 + 352);
    *(_QWORD *)(v14 + 2784) = v5;
    *(_DWORD *)(v14 + 2816) = v18;
    v19 = cam_irq_controller_init("sfe_bus_rd", v16, (unsigned int *)(v5 + 32), (__int64 *)(v14 + 376));
    if ( v19 )
    {
      LODWORD(a5) = v19;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_rd_init",
        2147,
        "IRQ controller init failed");
LABEL_18:
      v20 = (_QWORD *)*v13;
      if ( v8[2904] == 1 )
        cam_mem_trace_free(v20, 0);
      else
        kvfree(v20);
      goto LABEL_100;
    }
    if ( !*(_DWORD *)(v15 + 1864) )
    {
LABEL_35:
      if ( *(_DWORD *)(v15 + 1868) )
      {
        v7 = nullptr;
        v6 = 0;
        a4 = (__int64 (__fastcall *)())(v5 + 244);
        v8 = (_BYTE *)&unk_98;
        v5 = 1;
        _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          if ( v7 == (__int64 (__fastcall *)())&_ksymtab_cam_cpas_reg_read )
            goto LABEL_93;
          v27 = *(_DWORD *)a4;
          if ( *(_DWORD *)a4 >= 3u )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              1,
              "cam_sfe_bus_init_sfe_bus_read_resource",
              1288,
              "Init SFE RD failed, Invalid type=%d",
              v27);
            a5 = 4294967274LL;
            goto LABEL_57;
          }
          v28 = v15 + 2328 + 152LL * v27;
          if ( *(_DWORD *)(v28 + 8) || *(_QWORD *)(v28 + 24) )
            break;
          if ( mem_trace_en == 1 )
          {
            v29 = cam_mem_trace_alloc(96, 0xCC0u, 0, "cam_sfe_bus_init_sfe_bus_read_resource", 0x515u);
            if ( !v29 )
              goto LABEL_47;
          }
          else
          {
            v29 = _kvmalloc_node_noprof(96, 0, 3520, 0xFFFFFFFFLL);
            if ( !v29 )
            {
LABEL_47:
              a5 = 4294967284LL;
LABEL_57:
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x40000000,
                1,
                "cam_sfe_bus_rd_init",
                2166,
                "Init SFE RD failed for client:%d, rc=%d",
                v6,
                a5);
              v8 = (char *)&unk_2FD000;
              if ( (_DWORD)v7 )
              {
                v40 = (char *)v7 + v15;
                if ( *(_DWORD *)((char *)v7 + v15 + 2184) )
                {
                  v41 = *((_QWORD **)v40 + 275);
                  *((_QWORD *)v40 + 274) = 0;
                  *((_DWORD *)v40 + 546) = 0;
                  *((_QWORD *)v40 + 283) = 0;
                  *((_QWORD *)v40 + 284) = 0;
                  *((_QWORD *)v40 + 286) = 0;
                  *((_QWORD *)v40 + 287) = 0;
                  *((_QWORD *)v40 + 276) = v40 + 2208;
                  *((_QWORD *)v40 + 277) = v40 + 2208;
                  *((_QWORD *)v40 + 275) = 0;
                  if ( v41 )
                  {
                    if ( mem_trace_en == 1 )
                      cam_mem_trace_free(v41, 0);
                    else
                      kvfree(v41);
                  }
                }
                else if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x40000000,
                    4,
                    "cam_sfe_bus_deinit_sfe_bus_rd_resource",
                    1338,
                    "HW%d Res %d already deinitialized",
                    v38,
                    v39);
                }
                if ( v6 >= 2 )
                {
                  v42 = (char *)v7 + v15;
                  if ( *(_DWORD *)((char *)v7 + v15 + 2032) )
                  {
                    v43 = *((_QWORD **)v42 + 256);
                    *((_QWORD *)v42 + 255) = 0;
                    *((_DWORD *)v42 + 508) = 0;
                    *((_QWORD *)v42 + 264) = 0;
                    *((_QWORD *)v42 + 265) = 0;
                    *((_QWORD *)v42 + 267) = 0;
                    *((_QWORD *)v42 + 268) = 0;
                    *((_QWORD *)v42 + 257) = v42 + 2056;
                    *((_QWORD *)v42 + 258) = v42 + 2056;
                    *((_QWORD *)v42 + 256) = 0;
                    if ( v43 )
                    {
                      if ( (mem_trace_en & 1) != 0 )
                        cam_mem_trace_free(v43, 0);
                      else
                        kvfree(v43);
                    }
                  }
                  else if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      debug_mdl & 0x40000000,
                      4,
                      "cam_sfe_bus_deinit_sfe_bus_rd_resource",
                      1338,
                      "HW%d Res %d already deinitialized",
                      v38,
                      v39);
                  }
                  if ( v6 - 1 >= 2 )
                  {
                    v44 = (char *)v7 + v15;
                    if ( *(_DWORD *)((char *)v7 + v15 + 1880) )
                    {
                      v45 = *((_QWORD **)v44 + 237);
                      *((_QWORD *)v44 + 236) = 0;
                      *((_DWORD *)v44 + 470) = 0;
                      *((_QWORD *)v44 + 245) = 0;
                      *((_QWORD *)v44 + 246) = 0;
                      *((_QWORD *)v44 + 248) = 0;
                      *((_QWORD *)v44 + 249) = 0;
                      *((_QWORD *)v44 + 238) = v44 + 1904;
                      *((_QWORD *)v44 + 239) = v44 + 1904;
                      *((_QWORD *)v44 + 237) = 0;
                      if ( v45 )
                      {
                        if ( (mem_trace_en & 1) != 0 )
                          cam_mem_trace_free(v45, 0);
                        else
                          kvfree(v45);
                      }
                    }
                    else if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
                    {
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        debug_mdl & 0x40000000,
                        4,
                        "cam_sfe_bus_deinit_sfe_bus_rd_resource",
                        1338,
                        "HW%d Res %d already deinitialized",
                        v38,
                        v39);
                    }
                  }
                }
              }
              LODWORD(v6) = *(_DWORD *)(v15 + 1864);
              goto LABEL_85;
            }
          }
          *(_QWORD *)(v28 + 24) = v29;
          ++v6;
          *(_DWORD *)v28 = 11;
          v7 = (__int64 (__fastcall *)())((char *)v7 + 152);
          *(_DWORD *)(v28 + 8) = 1;
          *(_QWORD *)(v28 + 32) = v28 + 32;
          *(_QWORD *)(v28 + 40) = v28 + 32;
          v30 = *(_DWORD *)a4;
          *(_QWORD *)(v29 + 8) = v15;
          *(_DWORD *)v29 = v30;
          *(_DWORD *)(v29 + 52) = *((_DWORD *)a4 + 5);
          v31 = *((_DWORD *)a4 + 6);
          *(_DWORD *)(v29 + 80) = 0;
          a4 = (__int64 (__fastcall *)())((char *)a4 + 28);
          *(_DWORD *)(v29 + 56) = v31;
          v32 = *(unsigned int *)(v15 + 1868);
          *(_QWORD *)(v28 + 16) = *(_QWORD *)(v15 + 16);
          if ( v6 >= v32 )
            goto LABEL_48;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_init_sfe_bus_read_resource",
          1296,
          "Error. Looks like same resource is init again");
        a5 = 4294967282LL;
        goto LABEL_57;
      }
LABEL_48:
      v33 = 0;
      v34 = v15 + 400;
      *(_DWORD *)(v15 + 392) = 0;
      *(_QWORD *)(v15 + 400) = v15 + 400;
      *(_QWORD *)(v15 + 408) = v15 + 400;
      do
      {
        v35 = v15 + v33;
        v36 = v35 + 416;
        *(_QWORD *)(v35 + 416) = v35 + 416;
        *(_QWORD *)(v35 + 424) = v35 + 416;
        v37 = *(_QWORD **)(v15 + 408);
        if ( (_QWORD *)(v15 + v33 + 416) == v37 || *v37 != v34 )
        {
          _list_add_valid_or_report(v36);
        }
        else
        {
          *(_QWORD *)(v15 + 408) = v36;
          *(_QWORD *)(v35 + 416) = v34;
          *(_QWORD *)(v35 + 424) = v37;
          *v37 = v36;
        }
        v33 += 88;
      }
      while ( v33 != 1408 );
      v13[5] = cam_sfe_bus_acquire_bus_rd;
      v13[6] = &cam_sfe_bus_release_bus_rd;
      v13[7] = &cam_sfe_bus_start_bus_rd;
      v13[8] = &cam_sfe_bus_stop_bus_rd;
      v13[2] = cam_sfe_bus_init_hw;
      v13[3] = cam_sfe_bus_deinit_hw;
      v13[11] = cam_sfe_bus_rd_process_cmd;
      v13[14] = cam_sfe_bus_rd_handle_irq;
      v13[15] = 0;
      *(_QWORD *)a5 = v13;
      *(_DWORD *)(v15 + 1832) = 0;
      return 0;
    }
    v21 = 0;
    v6 = 0;
    v8 = (_BYTE *)&_ksymtab_cam_cdm_stream_on;
    v7 = cam_sfe_bus_start_rm;
    a4 = cam_sfe_bus_stop_rm;
    _ReadStatusReg(SP_EL0);
    while ( mem_trace_en == 1 )
    {
      v22 = cam_mem_trace_alloc(96, 0xCC0u, 0, "cam_sfe_bus_init_rm_resource", 0x272u);
      if ( !v22 )
        goto LABEL_31;
LABEL_28:
      v23 = v15 + v21;
      *(_QWORD *)(v23 + 1896) = v22;
      *(_QWORD *)v22 = v15;
      *(_QWORD *)(v22 + 8) = &v8[v5 - 48];
      v24 = v15 + v21 + 1904;
      *(_DWORD *)(v22 + 24) = v6;
      *(_DWORD *)(v23 + 1880) = 1;
      *(_QWORD *)(v23 + 1904) = v24;
      *(_QWORD *)(v23 + 1912) = v24;
      v25 = *(_QWORD *)(v15 + 16);
      *(_QWORD *)(v23 + 1960) = cam_sfe_bus_start_rm;
      *(_QWORD *)(v23 + 1968) = cam_sfe_bus_stop_rm;
      *(_QWORD *)(v23 + 1888) = v25;
      if ( v21 == 456 )
        goto LABEL_93;
      v26 = *(const char **)&v8[*(_QWORD *)(v15 + 2784)];
      if ( v26 )
        scnprintf(v15 + v21 + 2000, 16, "%s", v26);
      ++v6;
      v8 += 56;
      v21 += 152;
      if ( v6 >= *(unsigned int *)(v15 + 1864) )
        goto LABEL_35;
    }
    v22 = _kvmalloc_node_noprof(96, 0, 3520, 0xFFFFFFFFLL);
    if ( v22 )
      goto LABEL_28;
LABEL_31:
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_bus_init_rm_resource",
        629,
        "Failed to alloc SFE:%d RM res priv",
        *(_DWORD *)v15);
    a5 = 4294967284LL;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_rd_init",
      2156,
      "Init RM failed for client:%d, rc=%d",
      v6,
      -12);
    v8 = (char *)&unk_2FD000;
LABEL_85:
    v5 = (unsigned int)(v6 - 1);
    if ( (int)v6 - 1 < 0 )
      goto LABEL_18;
    v6 = 152LL * (unsigned int)v5;
    while ( (unsigned int)v5 <= 3 )
    {
      v46 = v15 + v6;
      v47 = v15 + v6 + 1904;
      *(_DWORD *)(v46 + 1880) = 0;
      *(_QWORD *)(v46 + 1904) = v47;
      *(_QWORD *)(v46 + 1912) = v47;
      v48 = *(_QWORD **)(v15 + v6 + 1896);
      *(_QWORD *)(v46 + 1888) = 0;
      *(_QWORD *)(v46 + 1960) = 0;
      *(_QWORD *)(v46 + 1968) = 0;
      *(_QWORD *)(v46 + 1984) = 0;
      *(_QWORD *)(v46 + 1992) = 0;
      *(_QWORD *)(v46 + 1896) = 0;
      if ( v48 )
      {
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v48, 0);
        else
          kvfree(v48);
      }
      v6 -= 152LL;
      if ( v6 == -152 )
        goto LABEL_18;
    }
LABEL_93:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v50 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_sfe_bus_rd_init__alloc_tag;
    v13 = (_QWORD *)_kvmalloc_node_noprof(128, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v50;
    if ( v13 )
      continue;
    break;
  }
LABEL_94:
  result = 4294967284LL;
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_rd_init",
      2108,
      "Failed to alloc for sfe_bus");
    return 4294967284LL;
  }
  return result;
}
