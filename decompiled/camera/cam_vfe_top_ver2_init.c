__int64 __fastcall cam_vfe_top_ver2_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4, _QWORD *a5)
{
  char *v5; // x27
  __int64 v9; // x0
  _QWORD *v10; // x19
  __int64 v11; // x0
  __int64 v12; // x26
  unsigned int v13; // w6
  unsigned int v14; // w25
  __int64 v15; // x28
  int v16; // w23
  __int64 v17; // x22
  unsigned __int64 v18; // x9
  __int64 v19; // x3
  int v20; // w6
  unsigned int v21; // w0
  __int64 v22; // x24
  __int64 v23; // x4
  const char *v24; // x5
  int v25; // w8
  _QWORD *v26; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v28; // x24
  _QWORD *v30; // [xsp+8h] [xbp-18h]

  v5 = (char *)&unk_2FD000;
  if ( mem_trace_en == 1 )
    v9 = cam_mem_trace_alloc(112, 0xCC0u, 0, "cam_vfe_top_ver2_init", 0x322u);
  else
    v9 = _kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
  v10 = (_QWORD *)v9;
  if ( v9 )
  {
    do
    {
      if ( v5[2904] == 1 )
        v11 = cam_mem_trace_alloc(10512, 0xCC0u, 0, "cam_vfe_top_ver2_init", 0x32Au);
      else
        v11 = _kvmalloc_node_noprof(10512, 0, 3520, 0xFFFFFFFFLL);
      v12 = v11;
      if ( !v11 )
      {
        v14 = -12;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_top_ver2_init",
            812,
            "Error! Failed to alloc for vfe_top_priv");
        goto LABEL_56;
      }
      *v10 = v11;
      *(_QWORD *)(v11 + 10440) = 0;
      v13 = *(_DWORD *)(a3 + 152);
      if ( v13 >= 8 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_top_ver2_init",
          821,
          "Invalid number of input rsrc: %d, max: %d",
          v13,
          7);
        v14 = -22;
        goto LABEL_46;
      }
      v30 = a5;
      *(_DWORD *)(v11 + 1088) = v13;
      if ( !v13 )
      {
LABEL_29:
        v14 = 0;
        v10[1] = cam_vfe_top_get_hw_caps;
        v10[2] = cam_vfe_top_init_hw;
        v10[4] = cam_vfe_top_reset;
        v10[5] = &cam_vfe_top_reserve;
        v10[6] = cam_vfe_top_release;
        v10[7] = cam_vfe_top_start;
        v10[8] = &cam_vfe_top_stop;
        v10[9] = cam_vfe_top_read;
        v10[10] = cam_vfe_top_write;
        v10[11] = &cam_vfe_top_process_cmd;
        *v30 = v10;
        *(_QWORD *)v12 = a2;
        *(_QWORD *)(v12 + 10432) = a1;
        *(_DWORD *)(v12 + 1092) = *(_DWORD *)(a2 + 4);
        *(_QWORD *)(v12 + 8) = *(_QWORD *)a3;
        *(_QWORD *)(v12 + 16) = *(_QWORD *)(a3 + 144);
        return v14;
      }
      v5 = nullptr;
      v15 = 0;
      v16 = 0;
      v17 = 1306;
      while ( v5 != byte_428 )
      {
        *(_DWORD *)&v5[v12 + 24] = 4;
        v19 = (__int64)&v5[v12 + 24];
        *(_QWORD *)(v19 + 16) = a2;
        *(_DWORD *)(v19 + 8) = 1;
        *(_QWORD *)(v12 + 8 * v17) = 0;
        v20 = *(_DWORD *)(a3 + 156 + v15);
        if ( v20 > 4095 )
        {
          if ( v20 == 4096 )
          {
            *(_DWORD *)&v5[v12 + 28] = v16 + 3;
            v21 = cam_vfe_rdi_ver2_init(a2, a1, a3 + 56);
            if ( v21 )
            {
LABEL_30:
              v14 = v21;
              if ( !v5 )
              {
LABEL_45:
                v5 = (char *)&unk_2FD000;
LABEL_46:
                v26 = (_QWORD *)*v10;
                if ( v5[2904] == 1 )
                  cam_mem_trace_free(v26, 0);
                else
                  kvfree(v26);
LABEL_56:
                if ( v5[2904] == 1 )
                  cam_mem_trace_free(v10, 0);
                else
                  kvfree(v10);
                return v14;
              }
              v22 = (__int64)&v5[v12 - 128];
              while ( 2 )
              {
                v25 = *(_DWORD *)(a3 + 152 + v15);
                if ( v25 == 2 )
                {
                  if ( !(unsigned int)cam_vfe_camif_lite_ver2_deinit((_QWORD *)v22) )
                    goto LABEL_35;
                  v23 = 917;
                  v24 = "Camif lite deinit failed";
                }
                else
                {
                  if ( v25 != 0x2000 )
                  {
                    if ( v25 == 32 )
                    {
                      if ( (unsigned int)cam_vfe_camif_ver2_deinit(v22) )
                      {
                        v23 = 912;
                        v24 = "Camif Deinit failed";
                        break;
                      }
                    }
                    else if ( (unsigned int)cam_vfe_rdi_ver2_deinit() )
                    {
                      v23 = 926;
                      v24 = "RDI Deinit failed";
                      break;
                    }
LABEL_35:
                    v15 -= 4;
                    *(_DWORD *)(v22 + 8) = 0;
                    v22 -= 152;
                    if ( !v15 )
                      goto LABEL_45;
                    continue;
                  }
                  if ( !(unsigned int)cam_vfe_fe_ver1_deinit(v22) )
                    goto LABEL_35;
                  v23 = 922;
                  v24 = "VFE FE deinit failed";
                }
                break;
              }
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                8,
                1,
                "cam_vfe_top_ver2_init",
                v23,
                v24);
              goto LABEL_35;
            }
            ++v16;
          }
          else
          {
            if ( v20 != 0x2000 )
            {
LABEL_13:
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                2,
                "cam_vfe_top_ver2_init",
                883,
                "Invalid mux type: %u",
                v20);
              goto LABEL_14;
            }
            *(_DWORD *)&v5[v12 + 28] = 2;
            v21 = cam_vfe_fe_ver1_init(a2, a1, a3 + 120);
            if ( v21 )
              goto LABEL_30;
          }
        }
        else if ( v20 == 2 )
        {
          *(_DWORD *)&v5[v12 + 28] = 8;
          v21 = cam_vfe_camif_lite_ver2_init(a2, a1, (_QWORD *)(a3 + 32), (_QWORD *)v19, a4);
          if ( v21 )
            goto LABEL_30;
        }
        else
        {
          if ( v20 != 32 )
            goto LABEL_13;
          *(_DWORD *)&v5[v12 + 28] = 0;
          v21 = cam_vfe_camif_ver2_init(a2, a1, a3 + 8);
          if ( v21 )
            goto LABEL_30;
        }
LABEL_14:
        v18 = v17 - 1305;
        ++v17;
        v15 += 4;
        v5 += 152;
        if ( v18 >= *(unsigned int *)(v12 + 1088) )
          goto LABEL_29;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v28 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_vfe_top_ver2_init__alloc_tag;
      v10 = (_QWORD *)_kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v28;
    }
    while ( v10 );
  }
  v14 = -12;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_top_ver2_init",
      804,
      "Error! Failed to alloc for vfe_top");
  return v14;
}
