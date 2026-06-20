__int64 __fastcall cam_sfe_top_print_debug_reg_info(int *a1)
{
  unsigned __int64 v2; // x23
  __int64 v3; // x24
  __int64 result; // x0
  _QWORD *v5; // x20
  unsigned int v6; // w28
  unsigned __int64 v7; // x26
  int v8; // w25
  unsigned int v9; // w27
  __int64 v10; // x26
  __int64 v11; // x28
  unsigned __int64 i; // x21
  __int64 v13; // x0
  int v14; // w8
  __int64 v15; // x24
  char v16; // w8
  __int64 v17; // x10
  unsigned int v18; // w11
  __int64 v20; // x21
  __int64 v21; // x8
  __int64 v22; // x23
  __int64 v23; // x22
  unsigned int v24; // w0
  _DWORD *v25; // x8
  int v26; // w6
  int v27; // w9
  unsigned int v28; // w21
  _DWORD *v29; // x8
  __int64 v30; // x23
  __int64 *v31; // x24
  unsigned int v32; // w9
  unsigned int v33; // w8
  char v34; // [xsp+0h] [xbp-450h]
  unsigned __int64 v35; // [xsp+38h] [xbp-418h] BYREF
  char s[1024]; // [xsp+40h] [xbp-410h] BYREF
  __int64 v37; // [xsp+440h] [xbp-10h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(*((_QWORD *)a1 + 2) + 180LL);
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 288LL);
  if ( (mem_trace_en & 1) != 0 )
    result = cam_mem_trace_alloc(4 * v2, 0xCC0u, 0, "cam_sfe_top_print_debug_reg_info", 0x16Cu);
  else
    result = _kvmalloc_node_noprof(4 * v2, 0, 3520, 0xFFFFFFFFLL);
  v5 = (_QWORD *)result;
  if ( !result )
    goto LABEL_67;
  if ( (_DWORD)v2 )
  {
    v6 = 0;
    while ( 1 )
    {
      v8 = v6 <= 0x14 ? 20 - v6 : 0;
      if ( v6 > 0x13 )
        break;
      v9 = v6;
      v7 = v6 + 1LL;
      *((_DWORD *)v5 + v6) = cam_io_r(v3 + *(unsigned int *)(*((_QWORD *)a1 + 2) + 4LL * v6 + 184));
      if ( v7 >= v2 )
      {
        ++v6;
        LODWORD(v7) = v9;
      }
      else
      {
        if ( v8 == 1 )
          break;
        *((_DWORD *)v5 + v7) = cam_io_r(v3 + *(unsigned int *)(*((_QWORD *)a1 + 2) + 4 * v7 + 184));
        if ( (unsigned __int64)v6 + 2 >= v2 )
        {
          v6 += 2;
        }
        else
        {
          if ( v8 == 2 )
            break;
          v7 = v6 + 3LL;
          *((_DWORD *)v5 + v6 + 2) = cam_io_r(v3 + *(unsigned int *)(*((_QWORD *)a1 + 2) + 4 * (v6 + 2LL) + 184));
          if ( v7 >= v2 )
          {
            v6 += 3;
            LODWORD(v7) = v9 + 2;
          }
          else
          {
            if ( v8 == 3 )
              break;
            v6 += 4;
            *((_DWORD *)v5 + v7) = cam_io_r(v3 + *(unsigned int *)(*((_QWORD *)a1 + 2) + 4 * v7 + 184));
          }
        }
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        3,
        "cam_sfe_top_print_debug_reg_info",
        375,
        "Debug%u: 0x%x Debug%u: 0x%x Debug%u: 0x%x Debug%u: 0x%x",
        v7 - 3,
        *((_DWORD *)v5 + (int)v7 - 3),
        v7 - 2,
        *((_DWORD *)v5 + (int)v7 - 2),
        v7 - 1,
        *((_DWORD *)v5 + (int)v7 - 1),
        v7,
        *((_DWORD *)v5 + (unsigned int)v7));
      if ( (unsigned int)v2 <= v6 )
        goto LABEL_22;
    }
LABEL_68:
    __break(0x5512u);
  }
LABEL_22:
  v10 = *((_QWORD *)a1 + 4039);
  v35 = 0;
  v11 = (unsigned int)a1[8076];
  if ( (_DWORD)v11 && v10 )
  {
    memset(s, 0, sizeof(s));
    for ( i = 0; i != v11; ++i )
    {
      v14 = *((_DWORD *)v5 + i);
      if ( v14 && v14 != 1431655765 )
      {
        if ( i > 0x13 )
          goto LABEL_68;
        v15 = 0;
        v16 = 0;
        while ( 2 )
        {
          v17 = 16 * v15++;
          while ( 1 )
          {
            v18 = *((_DWORD *)v5 + i) >> *(_DWORD *)(v10 + v17);
            if ( (v18 & 0xF) != 0 && ((*((_DWORD *)v5 + i) >> *(_DWORD *)(v10 + v17)) & 0xF) != 5 )
              break;
            ++v15;
            v17 += 16;
            if ( v15 == 9 )
            {
              if ( (v16 & 1) == 0 )
                goto LABEL_29;
              goto LABEL_25;
            }
          }
          cam_print_to_buffer(
            (__int64)s,
            0x400u,
            &v35,
            3u,
            0x40000000u,
            "%s [I:%u V:%u R:%u]",
            *(_QWORD *)(v10 + v17 + 8),
            (v18 >> 2) & 1,
            (v18 & 2) != 0);
          v16 = 1;
          if ( v15 != 8 )
            continue;
          break;
        }
LABEL_25:
        if ( (unsigned int)__ratelimit(&cam_sfe_top_check_module_status__rs, "cam_sfe_top_check_module_status") )
          v13 = 3;
        else
          v13 = 2;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          v13,
          0x40000000,
          3,
          "cam_sfe_top_check_module_status",
          263,
          "Check config for Debug%u - %s",
          i,
          s);
LABEL_29:
        v35 = 0;
      }
      v10 += 128;
    }
  }
  v20 = *((_QWORD *)a1 + 2);
  if ( *(_DWORD *)(v20 + 176) && a1[8063] )
  {
    v21 = *(_QWORD *)a1;
    v22 = *(unsigned int *)(v20 + 168);
    v35 = 0;
    v23 = *(_QWORD *)(v21 + 288);
    memset(s, 0, sizeof(s));
    if ( (unsigned int)v22 >= 0x14 )
      goto LABEL_68;
    v24 = cam_io_r(v23 + *(unsigned int *)(v20 + 4 * v22 + 184));
    v25 = *((_DWORD **)a1 + 4037);
    v26 = a1[8063];
    v27 = v25[36];
    if ( v27 )
    {
      v28 = v24;
      if ( v26 == v25[40] )
      {
        v29 = v25 + 38;
        v30 = (unsigned int)v29[3];
        if ( (_DWORD)v30 )
          goto LABEL_53;
        goto LABEL_60;
      }
      if ( v27 != 1 )
      {
        if ( v26 == v25[46] )
        {
          v29 = v25 + 44;
          v30 = (unsigned int)v29[3];
          if ( (_DWORD)v30 )
          {
LABEL_53:
            v31 = (__int64 *)(*((_QWORD *)v29 + 2) + 8LL);
            do
            {
              v32 = *((_DWORD *)v31 - 2);
              v33 = v28 >> *((_DWORD *)v31 - 1);
              if ( (v33 & v32) != 0 )
                cam_print_to_buffer((__int64)s, 0x400u, &v35, 3u, 0x40000000u, "%s [val:%u]", *v31, v33 & v32, v34);
              --v30;
              v31 += 2;
            }
            while ( v30 );
          }
LABEL_60:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            3,
            "cam_sfe_top_print_cc_test_bus",
            312,
            "SFE_TOP_DEBUG_%d val %d  config %s",
            *(_DWORD *)(*((_QWORD *)a1 + 2) + 168LL),
            v28,
            s);
          goto LABEL_63;
        }
        if ( v27 != 2 )
          goto LABEL_68;
      }
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      2,
      "cam_sfe_top_print_cc_test_bus",
      298,
      "Unexpected value[%d] is programed in test_bus_ctrl reg",
      v26);
  }
LABEL_63:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v5, 0);
  else
    kvfree(v5);
  result = cam_sfe_top_dump_perf_counters("ERROR", &unk_3E455A, a1);
LABEL_67:
  _ReadStatusReg(SP_EL0);
  return result;
}
