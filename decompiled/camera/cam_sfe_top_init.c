__int64 __fastcall cam_sfe_top_init(int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, _QWORD *a6)
{
  _BYTE *v6; // x27
  __int64 v13; // x0
  _QWORD *v14; // x20
  __int64 v15; // x0
  __int64 v16; // x21
  unsigned int v17; // w6
  unsigned int v18; // w21
  _QWORD *v19; // x19
  __int64 v20; // x20
  __int64 v21; // x8
  int v22; // w6
  _QWORD *v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x8
  _QWORD *v28; // x20
  _QWORD *v29; // x0
  _QWORD *v30; // x20
  _QWORD *v31; // x0
  _QWORD *v32; // x20
  _QWORD *v33; // x0
  _QWORD *v34; // x20
  _QWORD *v35; // x0
  _QWORD *v36; // x20
  _QWORD *v37; // x0
  _QWORD *v38; // x20
  _QWORD *v39; // x0
  _QWORD *v40; // x12
  __int64 v41; // x11
  __int64 v42; // x8
  __int64 v43; // x9
  __int64 v44; // x9
  __int64 *v45; // x10
  __int64 *v46; // x1
  _QWORD *v47; // x0
  _QWORD *v48; // x21
  unsigned __int64 StatusReg; // x19
  __int64 v50; // x20
  __int64 v51; // x0
  _QWORD *v53; // [xsp+10h] [xbp-20h]
  _QWORD *v54; // [xsp+18h] [xbp-18h]
  __int64 v55; // [xsp+28h] [xbp-8h]

  v6 = &unk_2FD000;
  if ( mem_trace_en == 1 )
    v13 = cam_mem_trace_alloc(112, 0xCC0u, 0, "cam_sfe_top_init", 0x8D4u);
  else
    v13 = _kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
  v14 = (_QWORD *)v13;
  if ( v13 )
  {
    while ( 1 )
    {
      v15 = v6[2904] == 1
          ? cam_mem_trace_alloc(32328, 0xCC0u, 0, "cam_sfe_top_init", 0x8DCu)
          : _kvmalloc_node_noprof(32328, 0, 3520, 0xFFFFFFFFLL);
      v16 = v15;
      if ( !v15 )
        break;
      *v14 = v15;
      *(_QWORD *)(v15 + 32) = a5;
      v17 = *(_DWORD *)(a4 + 88);
      if ( v17 >= 7 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_top_init",
          2280,
          "Invalid number of input resources: %d max: %d",
          v17,
          6);
        v18 = -22;
LABEL_86:
        v47 = (_QWORD *)*v14;
        if ( v6[2904] == 1 )
          cam_mem_trace_free(v47, 0);
        else
          kvfree(v47);
        *v14 = 0;
        goto LABEL_95;
      }
      v53 = v14;
      v54 = a6;
      *(_DWORD *)(v15 + 23496) = v17;
      if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40000000,
          4,
          "cam_sfe_top_init",
          2289,
          "Initializing SFE [%u] top with hw_version: 0x%x",
          *(_DWORD *)(a3 + 4),
          a1);
        if ( !*(_DWORD *)(v16 + 23496) )
        {
LABEL_76:
          *(_QWORD *)v16 = a2;
          *(_QWORD *)(v16 + 8) = a3;
          v40 = v53;
          v41 = 256;
          *(_QWORD *)(v16 + 16) = *(_QWORD *)a4;
          v42 = *(_QWORD *)(a4 + 16);
          *(_QWORD *)(v16 + 32296) = a4;
          *(_QWORD *)(v16 + 24) = v42;
          *(_QWORD *)(v16 + 32288) = *(_QWORD *)(a4 + 32);
          *(_DWORD *)(v16 + 32304) = *(_DWORD *)(a4 + 128);
          v43 = *(_QWORD *)(a4 + 136);
          *(_DWORD *)(v16 + 32228) = 0;
          *(_DWORD *)(v16 + 32252) = 0;
          *(_QWORD *)(v16 + 32312) = v43;
          v53[11] = cam_sfe_top_process_cmd;
          v53[7] = cam_sfe_top_start;
          v53[8] = cam_sfe_top_stop;
          v53[5] = cam_sfe_top_reserve;
          v53[6] = cam_sfe_top_release;
          v53[2] = cam_sfe_top_init_hw;
          v44 = v16 + 22568;
          *(_DWORD *)(v16 + 32272) = 0;
          v45 = (__int64 *)(v16 + 40);
          *(_QWORD *)(v16 + 22568) = v16 + 22568;
          *(_QWORD *)(v16 + 22576) = v16 + 22568;
          a6 = v54;
          do
          {
            *v45 = (__int64)v45;
            v45[1] = (__int64)v45;
            v46 = *(__int64 **)(v16 + 22576);
            if ( v45 == v46 || *v46 != v44 )
            {
              _list_add_valid_or_report(v45);
            }
            else
            {
              *(_QWORD *)(v16 + 22576) = v45;
              *v45 = v44;
              v45[1] = (__int64)v46;
              *v46 = (__int64)v45;
            }
            --v41;
            v45 += 11;
          }
          while ( v41 );
          v18 = 0;
          goto LABEL_99;
        }
      }
      else if ( !v17 )
      {
        goto LABEL_76;
      }
      v19 = nullptr;
      a1 = 0;
      v20 = 2939;
      a5 = 92;
      v55 = v16 + 23512;
      _ReadStatusReg(SP_EL0);
      while ( v19 != &_ksymtab_cam_res_mgr_led_trigger_register )
      {
        *(_QWORD *)((char *)v19 + v16 + 22600) = a3;
        v21 = (__int64)v19 + v55;
        *(_DWORD *)(v21 - 928) = 10;
        *(_DWORD *)(v21 - 920) = 1;
        *(_QWORD *)(v16 + 8 * v20) = 0;
        v22 = *(_DWORD *)(a4 + a5);
        if ( v22 == 4096 )
        {
          *(_DWORD *)(v21 - 924) = a1 + 1;
          if ( mem_trace_en == 1 )
            v24 = cam_mem_trace_alloc(72, 0xCC0u, 0, "cam_sfe_top_init", 0x91Du);
          else
            v24 = _kvmalloc_node_noprof(72, 0, 3520, 0xFFFFFFFFLL);
          v6 = (_BYTE *)v24;
          if ( !v24 )
          {
            v6 = &unk_2FD000;
            if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x40000000,
                4,
                "cam_sfe_top_init",
                2338,
                "Failed to alloc SFE [%u] rdi data res_id: %u",
                *(_DWORD *)(a3 + 4),
                a1 + 1);
              if ( !v19 )
                goto LABEL_84;
LABEL_40:
              v28 = (_QWORD *)((char *)v19 + v16);
              v29 = *(_QWORD **)((char *)v19 + v16 + 22456);
              v28[2819] = 0;
              v28[2818] = 0;
              v28[2817] = 0;
              v28[2816] = 0;
              v28[2815] = 0;
              if ( v29 )
              {
                if ( mem_trace_en == 1 )
                  cam_mem_trace_free(v29, 0);
                else
                  kvfree(v29);
                v28[2807] = 0;
                *(_DWORD *)((char *)v19 + v55 - 1072) = 0;
              }
              if ( v19 == (_QWORD *)&unk_98 )
                goto LABEL_84;
              v30 = (_QWORD *)((char *)v19 + v16);
              v31 = *(_QWORD **)((char *)v19 + v16 + 22304);
              v30[2800] = 0;
              v30[2799] = 0;
              v30[2798] = 0;
              v30[2797] = 0;
              v30[2796] = 0;
              if ( v31 )
              {
                if ( (mem_trace_en & 1) != 0 )
                  cam_mem_trace_free(v31, 0);
                else
                  kvfree(v31);
                v30[2788] = 0;
                *(_DWORD *)((char *)v19 + v55 - 1224) = 0;
              }
              if ( v19 == &qword_130 )
                goto LABEL_84;
              v32 = (_QWORD *)((char *)v19 + v16);
              v33 = *(_QWORD **)((char *)v19 + v16 + 22152);
              v32[2781] = 0;
              v32[2780] = 0;
              v32[2779] = 0;
              v32[2778] = 0;
              v32[2777] = 0;
              if ( v33 )
              {
                if ( (mem_trace_en & 1) != 0 )
                  cam_mem_trace_free(v33, 0);
                else
                  kvfree(v33);
                v32[2769] = 0;
                *(_DWORD *)((char *)v19 + v55 - 1376) = 0;
              }
              if ( v19 == &_ksymtab_cam_cpas_reg_read )
                goto LABEL_84;
              v34 = (_QWORD *)((char *)v19 + v16);
              v35 = *(_QWORD **)((char *)v19 + v16 + 22000);
              v34[2762] = 0;
              v34[2761] = 0;
              v34[2760] = 0;
              v34[2759] = 0;
              v34[2758] = 0;
              if ( v35 )
              {
                if ( (mem_trace_en & 1) != 0 )
                  cam_mem_trace_free(v35, 0);
                else
                  kvfree(v35);
                v34[2750] = 0;
                *(_DWORD *)((char *)v19 + v55 - 1528) = 0;
              }
              if ( v19 == (_QWORD *)&unk_260 )
                goto LABEL_84;
              v36 = (_QWORD *)((char *)v19 + v16);
              v37 = *(_QWORD **)((char *)v19 + v16 + 21848);
              v36[2743] = 0;
              v36[2742] = 0;
              v36[2741] = 0;
              v36[2740] = 0;
              v36[2739] = 0;
              if ( v37 )
              {
                if ( (mem_trace_en & 1) != 0 )
                  cam_mem_trace_free(v37, 0);
                else
                  kvfree(v37);
                v36[2731] = 0;
                *(_DWORD *)((char *)v19 + v55 - 1680) = 0;
              }
              if ( v19 == &qword_2F8
                || (v38 = (_QWORD *)((char *)v19 + v16),
                    v39 = *(_QWORD **)((char *)v19 + v16 + 21696),
                    v38[2724] = 0,
                    v38[2723] = 0,
                    v38[2722] = 0,
                    v38[2721] = 0,
                    v38[2720] = 0,
                    !v39) )
              {
LABEL_84:
                v18 = 0;
              }
              else
              {
                if ( (mem_trace_en & 1) != 0 )
                  cam_mem_trace_free(v39, 0);
                else
                  kvfree(v39);
                v18 = 0;
                v38[2712] = 0;
                *(_DWORD *)((char *)v19 + v55 - 1832) = 0;
              }
              v14 = v53;
              a6 = v54;
              goto LABEL_86;
            }
LABEL_39:
            if ( !v19 )
              goto LABEL_84;
            goto LABEL_40;
          }
          scnprintf((char *)v19 + v55 - 800, 16, "RDI%d", a1);
          *(_QWORD *)((char *)v19 + v16 + 22608) = v6;
          *(_QWORD *)v6 = *(_QWORD *)(a2 + 288);
          *((_QWORD *)v6 + 1) = a3;
          *((_QWORD *)v6 + 3) = *(_QWORD *)a4;
          *((_QWORD *)v6 + 4) = *(_QWORD *)(a4 + 16);
          v26 = *(_QWORD *)(a4 + 8);
          *((_QWORD *)v6 + 7) = a2;
          *((_QWORD *)v6 + 2) = v16;
          *((_QWORD *)v6 + 5) = v26;
          if ( (unsigned int)a1 > 4 )
            break;
          v27 = *(_QWORD *)(a4 + 48 + 8LL * (unsigned int)a1++);
          *((_QWORD *)v6 + 6) = v27;
        }
        else if ( v22 == 16 )
        {
          v6 = &unk_2FD000;
          *(_DWORD *)((char *)v19 + v55 - 924) = 0;
          if ( mem_trace_en == 1 )
          {
            v23 = (_QWORD *)cam_mem_trace_alloc(72, 0xCC0u, 0, "cam_sfe_top_init", 0x901u);
            if ( !v23 )
              goto LABEL_37;
          }
          else
          {
            v23 = (_QWORD *)_kvmalloc_node_noprof(72, 0, 3520, 0xFFFFFFFFLL);
            if ( !v23 )
            {
LABEL_37:
              if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x40000000,
                  4,
                  "cam_sfe_top_init",
                  2309,
                  "Failed to alloc SFE [%u] pix data",
                  *(_DWORD *)(a3 + 4));
                if ( !v19 )
                  goto LABEL_84;
                goto LABEL_40;
              }
              goto LABEL_39;
            }
          }
          *(_QWORD *)((char *)v19 + v16 + 22608) = v23;
          *v23 = *(_QWORD *)(a2 + 288);
          v23[6] = *(_QWORD *)(a4 + 40);
          v23[3] = *(_QWORD *)a4;
          v23[4] = *(_QWORD *)(a4 + 16);
          v25 = *(_QWORD *)(a4 + 8);
          v23[1] = a3;
          v23[2] = v16;
          v23[7] = a2;
          v23[5] = v25;
          scnprintf((char *)v19 + v55 - 800, 16, "PIX");
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            2,
            "cam_sfe_top_init",
            2361,
            "Invalid SFE input type: %u",
            v22);
        }
        if ( v20 - 2938 < (unsigned __int64)*(unsigned int *)(v16 + 23496) )
        {
          v19 += 19;
          ++v20;
          a5 += 4;
          if ( a1 < 5 )
            continue;
        }
        goto LABEL_76;
      }
      __break(0x5512u);
      v48 = v19;
      StatusReg = _ReadStatusReg(SP_EL0);
      v50 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &cam_sfe_top_init__alloc_tag;
      v51 = _kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v50;
      v14 = (_QWORD *)v51;
      a6 = v48;
      if ( !v51 )
        goto LABEL_91;
    }
    v18 = -12;
LABEL_95:
    if ( v6[2904] == 1 )
      cam_mem_trace_free(v14, 0);
    else
      kvfree(v14);
    goto LABEL_98;
  }
LABEL_91:
  v40 = nullptr;
  v18 = -12;
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_top_init",
      2262,
      "Error, Failed to alloc for sfe_top");
LABEL_98:
    v40 = nullptr;
  }
LABEL_99:
  *a6 = v40;
  return v18;
}
