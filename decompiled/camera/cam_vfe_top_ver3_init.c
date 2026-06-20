__int64 __fastcall cam_vfe_top_ver3_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  _BYTE *v5; // x20
  __int64 v9; // x0
  _QWORD *v10; // x19
  __int64 v11; // x0
  __int64 v12; // x25
  unsigned int v13; // w6
  __int64 v14; // x28
  __int64 v15; // x22
  int v16; // w27
  __int64 v17; // x23
  __int64 v18; // x3
  int v19; // w6
  int v20; // w0
  __int64 v21; // x23
  int v22; // w8
  _QWORD *v23; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v25; // x23
  _QWORD *v27; // [xsp+8h] [xbp-28h]
  _QWORD *v28; // [xsp+18h] [xbp-18h]

  v5 = &unk_2FD000;
  if ( mem_trace_en == 1 )
    v9 = cam_mem_trace_alloc(112, 0xCC0u, 0, "cam_vfe_top_ver3_init", 0x2E3u);
  else
    v9 = _kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
  v10 = (_QWORD *)v9;
  if ( !v9 )
    goto LABEL_50;
  while ( 2 )
  {
    if ( v5[2904] == 1 )
      v11 = cam_mem_trace_alloc(10512, 0xCC0u, 0, "cam_vfe_top_ver3_init", 0x2EBu);
    else
      v11 = _kvmalloc_node_noprof(10512, 0, 3520, 0xFFFFFFFFLL);
    v12 = v11;
    if ( !v11 )
    {
      LODWORD(a5) = -12;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_top_ver3_init",
          749,
          "Error, Failed to alloc for vfe_top_priv");
LABEL_56:
      if ( v5[2904] == 1 )
        cam_mem_trace_free(v10, 0);
      else
        kvfree(v10);
      return (unsigned int)a5;
    }
    *v10 = v11;
    *(_QWORD *)(v11 + 10440) = 0;
    v13 = *(_DWORD *)(a3 + 136);
    if ( v13 >= 8 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_top_ver3_init",
        758,
        "Invalid number of input rsrc: %d, max: %d",
        v13,
        7);
      LODWORD(a5) = -22;
LABEL_46:
      v23 = (_QWORD *)*v10;
      if ( v5[2904] == 1 )
        cam_mem_trace_free(v23, 0);
      else
        kvfree(v23);
      goto LABEL_56;
    }
    v27 = (_QWORD *)a5;
    *(_DWORD *)(v11 + 1088) = v13;
    v28 = (_QWORD *)a3;
    *(_QWORD *)v11 = a3;
    if ( !v13 )
    {
LABEL_32:
      LODWORD(a5) = 0;
      v10[1] = cam_vfe_top_ver3_get_hw_caps;
      v10[2] = cam_vfe_top_ver3_init_hw;
      v10[4] = cam_vfe_top_ver3_reset;
      v10[5] = cam_vfe_top_ver3_reserve;
      v10[6] = cam_vfe_top_ver3_release;
      v10[7] = cam_vfe_top_ver3_start;
      v10[8] = &cam_vfe_top_ver3_stop;
      v10[9] = cam_vfe_top_ver3_read;
      v10[10] = cam_vfe_top_ver3_write;
      v10[11] = cam_vfe_top_ver3_process_cmd;
      *v27 = v10;
      *(_QWORD *)(v12 + 8) = a2;
      *(_QWORD *)(v12 + 10432) = a1;
      *(_DWORD *)(v12 + 1092) = *(_DWORD *)(a2 + 4);
      *(_QWORD *)(v12 + 16) = *v28;
      return (unsigned int)a5;
    }
    v14 = 0;
    v15 = 0;
    v16 = 0;
    v17 = 1306;
    a3 += 144;
    while ( v14 != 1064 )
    {
      *(_DWORD *)(v12 + v14 + 24) = 4;
      v18 = v12 + v14 + 24;
      *(_QWORD *)(v18 + 16) = a2;
      *(_DWORD *)(v18 + 8) = 1;
      *(_QWORD *)(v12 + 8 * v17) = 0;
      v19 = *(_DWORD *)(a3 + v15);
      if ( v19 <= 4095 )
      {
        if ( v19 == 48 )
        {
          v5 = (_BYTE *)(v12 + v14);
          *(_DWORD *)(v12 + v14 + 28) = 0;
          a5 = (unsigned int)cam_vfe_camif_ver3_init(a2, a1, v28 + 1);
          scnprintf(v12 + v14 + 152, 16, "CAMIF");
        }
        else
        {
          if ( v19 != 256 )
          {
LABEL_29:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              2,
              "cam_vfe_top_ver3_init",
              845,
              "Invalid mux type: %u",
              v19);
            goto LABEL_30;
          }
          v5 = (_BYTE *)(v12 + v14);
          *(_DWORD *)(v12 + v14 + 28) = 9;
          a5 = (unsigned int)cam_vfe_camif_lite_ver3_init(a2, a1, v28 + 11);
          scnprintf(v12 + v14 + 152, 16, "LCR");
        }
        goto LABEL_27;
      }
      if ( v19 != 4096 )
      {
        if ( v19 == 0x2000 )
        {
          v5 = (_BYTE *)(v12 + v14);
          *(_DWORD *)(v12 + v14 + 28) = 2;
          a5 = (unsigned int)cam_vfe_fe_ver1_init(a2, a1, v28 + 14);
          scnprintf(v12 + v14 + 152, 16, "IN_RD");
        }
        else
        {
          if ( v19 != 0x10000 )
            goto LABEL_29;
          v5 = (_BYTE *)(v12 + v14);
          *(_DWORD *)(v12 + v14 + 28) = 8;
          a5 = (unsigned int)cam_vfe_camif_lite_ver3_init(a2, a1, v28 + 4);
          scnprintf(v12 + v14 + 152, 16, "PDLIB");
        }
LABEL_27:
        if ( (_DWORD)a5 )
          goto LABEL_34;
        goto LABEL_30;
      }
      a5 = v12 + v14 + 24;
      *(_DWORD *)(v12 + v14 + 28) = v16 + 3;
      scnprintf(v12 + v14 + 152, 16, "RDI_%d", v16);
      if ( (unsigned int)v16 > 3 )
        break;
      v20 = cam_vfe_camif_lite_ver3_init(a2, a1, v28[(unsigned int)v16 + 7]);
      if ( v20 )
      {
        LODWORD(a5) = v20;
LABEL_34:
        if ( v14 )
        {
          v21 = v12 + v14 - 128;
          do
          {
            v22 = *(_DWORD *)((char *)v28 + v15 + 140);
            if ( v22 == 0x2000 )
            {
              if ( (unsigned int)cam_vfe_fe_ver1_deinit(v21) )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_vfe_top_ver3_init",
                  877,
                  "Camif fe Deinit failed");
            }
            else if ( v22 == 48 )
            {
              if ( (unsigned int)cam_vfe_camif_ver3_deinit(v21) )
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_vfe_top_ver3_init",
                  873,
                  "Camif Deinit failed");
            }
            else if ( (unsigned int)cam_vfe_camif_lite_ver3_deinit(v21) )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_vfe_top_ver3_init",
                884,
                "Camif lite res id %d Deinit failed",
                *(_DWORD *)(v21 + 4));
            }
            v15 -= 4;
            *(_DWORD *)(v21 + 8) = 0;
            v21 -= 152;
          }
          while ( v15 );
        }
        v5 = &unk_2FD000;
        goto LABEL_46;
      }
      ++v16;
LABEL_30:
      if ( v17 - 1305 < (unsigned __int64)*(unsigned int *)(v12 + 1088) )
      {
        v15 += 4;
        v14 += 152;
        ++v17;
        if ( v16 < 4 )
          continue;
      }
      goto LABEL_32;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v25 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_vfe_top_ver3_init__alloc_tag;
    v10 = (_QWORD *)_kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v25;
    if ( v10 )
      continue;
    break;
  }
LABEL_50:
  LODWORD(a5) = -12;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_top_ver3_init",
      741,
      "Error, Failed to alloc for vfe_top");
  return (unsigned int)a5;
}
