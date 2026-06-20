__int64 __fastcall _cam_isp_ctx_acquire_hw_in_acquired(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x6
  __int64 v3; // x8
  __int64 v4; // x23
  __int64 v5; // x6
  __int64 v6; // x7
  const char *v7; // x3
  const char *v8; // x5
  __int64 v9; // x4
  __int64 v10; // x8
  __int64 v11; // x23
  __int64 result; // x0
  __int64 v13; // x6
  __int64 v14; // x7
  const char *v15; // x3
  const char *v16; // x5
  __int64 v17; // x4
  __int64 v18; // x6
  __int64 v19; // x7
  const char *v20; // x3
  const char *v21; // x5
  __int64 v22; // x4
  unsigned int *v23; // x20
  __int64 v24; // x26
  __int64 v25; // x0
  unsigned int *v26; // x20
  __int64 v27; // x24
  __int64 v28; // x0
  _QWORD *v29; // x19
  unsigned int *v30; // x8
  size_t v31; // x20
  __int64 v32; // x21
  unsigned int *v33; // x27
  unsigned int v34; // w21
  _QWORD *v35; // x19
  unsigned int *v36; // x8
  size_t v37; // x20
  __int64 v38; // x21
  unsigned int *v39; // x27
  unsigned int v40; // w20
  unsigned int v41; // w9
  __int64 v42; // x21
  unsigned int v43; // w0
  __int64 v44; // x6
  __int64 v45; // x7
  const char *v46; // x5
  __int64 v47; // x4
  unsigned int v48; // w9
  __int64 *v49; // x9
  unsigned int v50; // w8
  __int64 (__fastcall *v51)(__int64, __int64 *); // x8
  __int64 v52; // x0
  unsigned int v53; // w0
  __int64 *v54; // x8
  __int64 (__fastcall *v55)(__int64, __int64 *); // x9
  __int64 v56; // x0
  unsigned int v57; // w0
  __int64 v58; // x9
  __int64 *v59; // x21
  unsigned int v60; // w0
  unsigned int v61; // w28
  __int64 *v62; // x9
  _DWORD *v63; // x8
  __int64 v64; // x0
  __int64 v65; // x20
  __int64 *v66; // x10
  __int64 (__fastcall *v67)(__int64, __int64 *); // x9
  __int64 v68; // x0
  __int64 *v69; // x26
  unsigned int v70; // w0
  int v71; // w6
  int v72; // w7
  __int64 v73; // x23
  __int64 *v74; // x9
  void (__fastcall *v75)(__int64, __int64 *); // x8
  __int64 v76; // x0
  char v77; // w8
  __int64 v78; // x0
  unsigned int v79; // w9
  __int64 v80; // x6
  __int64 v81; // x8
  __int64 v82; // x0
  __int64 v83; // x7
  const char *v84; // x5
  __int64 v85; // x4
  __int64 *v86; // x8
  __int64 (__fastcall *v87)(__int64, __int64 *); // x9
  __int64 v88; // x0
  unsigned int v89; // w0
  __int64 *v90; // x9
  __int64 (__fastcall *v91)(__int64, __int64 *); // x8
  __int64 v92; // x0
  unsigned int v93; // w0
  __int64 (__fastcall **v94)(); // x8
  void *v95; // x9
  __int64 v96; // x8
  unsigned int *v97; // x19
  __int64 v98; // x20
  unsigned int *v99; // x19
  __int64 v100; // x20
  __int64 v101; // x9
  unsigned int v102; // w11
  __int64 v103; // x8
  __int64 v104; // x11
  __int64 v105; // x8
  __int64 v106; // x9
  __int64 v107; // x8
  __int64 v108; // x9
  __int64 v109; // x8
  __int64 v110; // x8
  int v111; // w9
  unsigned int (__fastcall *v112)(_QWORD); // x8
  unsigned int v113; // w8
  __int64 v114; // x10
  _BOOL4 v115; // w9
  int v116; // w9
  __int64 (__fastcall **v117)(); // x8
  void *v118; // x9
  const char *v119; // x8
  const char *v120; // x7
  __int64 v121; // x8
  int v122; // w9
  int v123; // [xsp+0h] [xbp-1D0h]
  unsigned int v124; // [xsp+24h] [xbp-1ACh]
  __int64 v125; // [xsp+28h] [xbp-1A8h] BYREF
  __int64 v126; // [xsp+30h] [xbp-1A0h]
  __int64 *v127; // [xsp+38h] [xbp-198h]
  _QWORD v128[4]; // [xsp+40h] [xbp-190h] BYREF
  __int64 v129; // [xsp+60h] [xbp-170h] BYREF
  __int64 v130; // [xsp+68h] [xbp-168h]
  __int64 v131; // [xsp+70h] [xbp-160h] BYREF
  __int64 *v132; // [xsp+78h] [xbp-158h]
  __int64 v133; // [xsp+80h] [xbp-150h]
  __int64 v134; // [xsp+88h] [xbp-148h]
  __int64 v135; // [xsp+90h] [xbp-140h]
  __int64 v136; // [xsp+98h] [xbp-138h]
  __int64 v137; // [xsp+A0h] [xbp-130h]
  __int64 v138; // [xsp+A8h] [xbp-128h]
  __int64 v139; // [xsp+B0h] [xbp-120h]
  __int64 v140; // [xsp+B8h] [xbp-118h]
  __int64 v141; // [xsp+C0h] [xbp-110h]
  __int64 v142; // [xsp+C8h] [xbp-108h]
  __int64 v143; // [xsp+D0h] [xbp-100h] BYREF
  __int64 v144; // [xsp+D8h] [xbp-F8h]
  __int64 *v145; // [xsp+E0h] [xbp-F0h]
  _QWORD v146[2]; // [xsp+E8h] [xbp-E8h] BYREF
  __int64 v147; // [xsp+F8h] [xbp-D8h] BYREF
  __int64 v148; // [xsp+100h] [xbp-D0h]
  __int64 v149; // [xsp+108h] [xbp-C8h]
  __int64 (__fastcall *v150)(__int64, __int64); // [xsp+110h] [xbp-C0h]
  __int64 v151; // [xsp+118h] [xbp-B8h]
  _QWORD *v152; // [xsp+120h] [xbp-B0h]
  __int64 v153; // [xsp+128h] [xbp-A8h]
  __int64 v154; // [xsp+130h] [xbp-A0h]
  __int64 v155; // [xsp+138h] [xbp-98h]
  __int64 v156; // [xsp+140h] [xbp-90h]
  _QWORD v157[8]; // [xsp+148h] [xbp-88h] BYREF
  __int64 v158; // [xsp+188h] [xbp-48h]
  __int64 v159; // [xsp+190h] [xbp-40h]
  __int64 v160; // [xsp+198h] [xbp-38h]
  __int64 v161; // [xsp+1A0h] [xbp-30h]
  __int64 v162; // [xsp+1A8h] [xbp-28h]
  __int64 (__fastcall *v163)(); // [xsp+1B0h] [xbp-20h]
  __int64 v164; // [xsp+1B8h] [xbp-18h]
  __int64 v165; // [xsp+1C0h] [xbp-10h]

  v165 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_acquire_hw_in_acquired",
      9149,
      "Invalid input pointer");
    goto LABEL_28;
  }
  v2 = *a2;
  if ( (_DWORD)v2 != 2 )
  {
    if ( (_DWORD)v2 == 1 )
    {
      v3 = *(_QWORD *)(a1 + 208);
      v4 = *(_QWORD *)(a1 + 256);
      v163 = nullptr;
      v164 = 0;
      v161 = 0;
      v162 = 0;
      v159 = 0;
      v160 = 0;
      v158 = 0;
      v156 = 0;
      memset(v157, 0, sizeof(v157));
      v154 = 0;
      v155 = 0;
      v152 = nullptr;
      v153 = 0;
      v150 = nullptr;
      v151 = 0;
      v148 = 0;
      v149 = 0;
      v147 = 0;
      v143 = 0;
      v144 = 0;
      v126 = 0;
      v127 = nullptr;
      v125 = 0;
      v141 = 0;
      v142 = 0;
      v139 = 0;
      v140 = 0;
      v137 = 0;
      v138 = 0;
      v135 = 0;
      v136 = 0;
      v133 = 0;
      v134 = 0;
      v131 = 0;
      v132 = nullptr;
      if ( v3 )
      {
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v97 = a2;
          v98 = a1;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "__cam_isp_ctx_acquire_hw_v1",
            8640,
            "session_hdl 0x%x, hdl type %d, res %lld ctx %u link: 0x%x",
            a2[2],
            a2[4],
            *((_QWORD *)a2 + 3),
            *(_DWORD *)(a1 + 32),
            *(_DWORD *)(a1 + 64));
          a2 = v97;
          a1 = v98;
        }
        if ( a2[4] == 1 )
        {
          if ( a2[5] <= 0x1F )
          {
            v5 = *(unsigned int *)(a1 + 32);
            v6 = *(unsigned int *)(a1 + 64);
            v7 = "__cam_isp_ctx_acquire_hw_v1";
            v8 = "data_size is not a valid value, ctx %u link: 0x%x";
            v9 = 8652;
LABEL_20:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
              3,
              8,
              1,
              v7,
              v9,
              v8,
              v5,
              v6);
            result = 0;
            goto LABEL_29;
          }
          if ( mem_trace_en == 1 )
          {
            v23 = a2;
            v24 = a1;
            v25 = cam_mem_trace_alloc(a2[5], 0xCC0u, 0, "__cam_isp_ctx_acquire_hw_v1", 0x21D0u);
          }
          else
          {
            v24 = a1;
            v23 = a2;
            v25 = _kvmalloc_node_noprof(a2[5], 0, 3520, 0xFFFFFFFFLL);
          }
          v29 = (_QWORD *)v25;
          if ( v25 )
          {
            if ( (debug_mdl & 8) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "__cam_isp_ctx_acquire_hw_v1",
                8663,
                "start copy resources from user, ctx_idx: %u, link: 0x%x",
                *(_DWORD *)(v24 + 32),
                *(_DWORD *)(v24 + 64));
            v30 = v23;
            v31 = v23[5];
            if ( (v31 & 0x80000000) != 0 )
            {
              __break(0x800u);
              v34 = -14;
              goto LABEL_61;
            }
            v32 = *((_QWORD *)v30 + 3);
            v33 = v30;
            _check_object_size(v29, v31, 0);
            if ( inline_copy_from_user_5((int)v29, v32, v31) )
            {
              v34 = -14;
LABEL_61:
              if ( mem_trace_en == 1 )
                cam_mem_trace_free(v29, 0);
              else
                kvfree(v29);
              result = v34;
              goto LABEL_29;
            }
            v149 = *(_QWORD *)(v24 + 232);
            v150 = cam_context_dump_pf_info;
            v41 = v33[5];
            LODWORD(v151) = -16843010;
            v42 = v24;
            HIDWORD(v151) = v41;
            v164 = 0;
            v161 = 0;
            v162 = 0;
            v159 = 0;
            v160 = 0;
            v158 = 0;
            v156 = 0;
            memset(v157, 0, sizeof(v157));
            v154 = 0;
            v155 = 0;
            v147 = v24;
            v148 = 0;
            v152 = v29;
            v153 = 0;
            v163 = _cam_isp_ctx_minidump_cb;
            v43 = _cam_isp_ctx_allocate_mem_hw_entries(v24, &v147);
            if ( v43 )
            {
              v44 = *(unsigned int *)(v24 + 32);
              v45 = *(unsigned int *)(v24 + 64);
              v46 = "Ctx[%u] link: 0x%x allocate hw entry fail";
              v34 = v43;
              v47 = 8684;
LABEL_60:
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
                3,
                8,
                1,
                "__cam_isp_ctx_acquire_hw_v1",
                v47,
                v46,
                v44,
                v45);
              goto LABEL_61;
            }
            v54 = *(__int64 **)(v24 + 208);
            v55 = (__int64 (__fastcall *)(__int64, __int64 *))v54[3];
            v56 = *v54;
            if ( *((_DWORD *)v55 - 1) != 1863972096 )
              __break(0x8229u);
            v57 = v55(v56, &v147);
            if ( v57 )
            {
              v44 = *(unsigned int *)(v24 + 32);
              v45 = *(unsigned int *)(v24 + 64);
              v46 = "Acquire device failed, ctx_idx: %u, link: 0x%x";
              v34 = v57;
              v47 = 8693;
              goto LABEL_60;
            }
            v65 = v4 + 42112;
            *(_BYTE *)(v4 + 45745) = (v154 & 0x400000000LL) != 0;
            LODWORD(v131) = 4;
            v66 = *(__int64 **)(v24 + 208);
            LODWORD(v126) = 0;
            v125 = v153;
            v127 = &v131;
            v67 = (__int64 (__fastcall *)(__int64, __int64 *))v66[12];
            v68 = *v66;
            v69 = (__int64 *)(v4 + 37296);
            if ( *((_DWORD *)v67 - 1) != 1863972096 )
              __break(0x8229u);
            v70 = v67(v68, &v125);
            if ( v70 )
            {
              v71 = *(_DWORD *)(v42 + 32);
              v72 = *(_DWORD *)(v42 + 64);
              v73 = v42;
              v34 = v70;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "__cam_isp_ctx_acquire_hw_v1",
                8709,
                "HW command failed, ctx_idx: %u, link: 0x%x",
                v71,
                v72);
              v74 = *(__int64 **)(v73 + 208);
              v143 = *v69;
              v75 = (void (__fastcall *)(__int64, __int64 *))v74[4];
              v76 = *v74;
              if ( *((_DWORD *)v75 - 1) != 1863972096 )
                __break(0x8228u);
              v75(v76, &v143);
              *v69 = 0;
              *(_BYTE *)(v65 + 3628) = 0;
              goto LABEL_61;
            }
            v79 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 3);
            switch ( v133 )
            {
              case 1LL:
                if ( v79 )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 8,
                    4,
                    "__cam_isp_ctx_acquire_hw_v1",
                    8728,
                    "FS2 Session has PIX, RD and RDI, ctx_idx: %u, link: 0x%x",
                    *(_DWORD *)(v42 + 32),
                    *(_DWORD *)(v42 + 64));
                v94 = cam_isp_ctx_fs2_state_machine_irq;
                v95 = &cam_isp_ctx_fs2_state_machine;
                break;
              case 4LL:
                if ( v79 )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 8,
                    4,
                    "__cam_isp_ctx_acquire_hw_v1",
                    8735,
                    "Offline session has PIX and RD resources, ctx: %u, link: 0x%x",
                    *(_DWORD *)(v42 + 32),
                    *(_DWORD *)(v42 + 64));
                *(_QWORD *)(v4 + 32) = 0;
                *(_QWORD *)(v4 + 40) = &cam_isp_ctx_offline_state_machine_irq;
                goto LABEL_120;
              case 2LL:
                if ( v79 )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 8,
                    4,
                    "__cam_isp_ctx_acquire_hw_v1",
                    8719,
                    "RDI only session Context, ctx_idx: %u, link: 0x%x",
                    *(_DWORD *)(v42 + 32),
                    *(_DWORD *)(v42 + 64));
                *(_QWORD *)(v4 + 32) = &cam_isp_ctx_rdi_only_activated_state_machine;
                *(_QWORD *)(v4 + 40) = &cam_isp_ctx_rdi_only_activated_state_machine_irq;
                *(_BYTE *)(v4 + 45736) = 1;
                goto LABEL_120;
              default:
                if ( v79 )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 8,
                    4,
                    "__cam_isp_ctx_acquire_hw_v1",
                    8741,
                    "Session has PIX or PIX and RDI resources, ctx: %u, link: 0x%x",
                    *(_DWORD *)(v42 + 32),
                    *(_DWORD *)(v42 + 64));
                v94 = cam_isp_ctx_activated_state_machine_irq;
                v95 = &cam_isp_ctx_activated_state_machine;
                break;
            }
            *(_QWORD *)(v4 + 32) = v95;
            *(_QWORD *)(v4 + 40) = v94;
LABEL_120:
            v96 = v153;
            *(_BYTE *)(v4 + 45740) = 1;
            *v69 = v96;
            *(_QWORD *)(v42 + 264) = v96;
            *(_QWORD *)(v4 + 37400) = -1;
            *(_QWORD *)(v4 + 45232) = -1;
            *(_QWORD *)v65 = -1;
            *(_QWORD *)(v4 + 42120) = -1;
            *(_QWORD *)(v4 + 42128) = -1;
            *(_QWORD *)(v4 + 42136) = -1;
            *(_QWORD *)(v4 + 42144) = -1;
            *(_QWORD *)(v4 + 42152) = -1;
            trace_cam_context_state(v42);
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              3,
              "__cam_isp_ctx_acquire_hw_v1",
              8762,
              "Acquire success:session_hdl 0x%xs ctx_type %d ctx %u link: 0x%x hw_mgr_ctx: %u",
              *(_DWORD *)(v42 + 56),
              v133,
              *(_DWORD *)(v42 + 32),
              *(_DWORD *)(v42 + 64),
              v154);
            if ( mem_trace_en == 1 )
              cam_mem_trace_free(v29, 0);
            else
              kvfree(v29);
            result = 0;
            goto LABEL_29;
          }
LABEL_166:
          result = 4294967284LL;
          goto LABEL_29;
        }
        v18 = *(unsigned int *)(a1 + 32);
        v19 = *(unsigned int *)(a1 + 64);
        v20 = "__cam_isp_ctx_acquire_hw_v1";
        v21 = "Only user pointer is supported, ctx %u link: 0x%x";
        v22 = 8645;
        goto LABEL_27;
      }
      v13 = *(unsigned int *)(a1 + 32);
      v14 = *(unsigned int *)(a1 + 64);
      v15 = "__cam_isp_ctx_acquire_hw_v1";
      v16 = "HW interface is not ready, ctx %u link: 0x%x";
      v17 = 8632;
LABEL_24:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        8,
        1,
        v15,
        v17,
        v16,
        v13,
        v14);
      result = 4294967282LL;
      goto LABEL_29;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_acquire_hw_in_acquired",
      9160,
      "Unsupported api version %d, ctx_id %u link: 0x%x",
      v2,
      *(unsigned int *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
LABEL_28:
    result = 4294967274LL;
    goto LABEL_29;
  }
  v10 = *(_QWORD *)(a1 + 208);
  v11 = *(_QWORD *)(a1 + 256);
  v163 = nullptr;
  v164 = 0;
  v161 = 0;
  v162 = 0;
  v159 = 0;
  v160 = 0;
  v158 = 0;
  v156 = 0;
  memset(v157, 0, sizeof(v157));
  v154 = 0;
  v155 = 0;
  v152 = nullptr;
  v153 = 0;
  v150 = nullptr;
  v151 = 0;
  v148 = 0;
  v149 = 0;
  v147 = 0;
  v146[0] = 0;
  v146[1] = 0;
  v144 = 0;
  v145 = nullptr;
  v142 = 0;
  v143 = 0;
  v140 = 0;
  v141 = 0;
  v138 = 0;
  v139 = 0;
  v136 = 0;
  v137 = 0;
  v134 = 0;
  v135 = 0;
  v132 = nullptr;
  v133 = 0;
  v130 = 0;
  v131 = 0;
  v129 = 0;
  v127 = nullptr;
  memset(v128, 0, sizeof(v128));
  v125 = 0;
  v126 = 0;
  if ( !v10 )
  {
    v13 = *(unsigned int *)(a1 + 32);
    v14 = *(unsigned int *)(a1 + 64);
    v15 = "__cam_isp_ctx_acquire_hw_v2";
    v16 = "HW interface is not ready, ctx_id %u link: 0x%x";
    v17 = 8887;
    goto LABEL_24;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v99 = a2;
    v100 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_acquire_hw_v2",
      8895,
      "session_hdl 0x%x, hdl type %d, res %lld, ctx_id %u link: 0x%x",
      a2[2],
      a2[4],
      *((_QWORD *)a2 + 3),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    a2 = v99;
    a1 = v100;
  }
  if ( a2[4] != 1 )
  {
    v18 = *(unsigned int *)(a1 + 32);
    v19 = *(unsigned int *)(a1 + 64);
    v20 = "__cam_isp_ctx_acquire_hw_v2";
    v21 = "Only user pointer is supported, ctx_id %u link: 0x%x";
    v22 = 8900;
LABEL_27:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
      3,
      8,
      1,
      v20,
      v22,
      v21,
      v18,
      v19,
      v123);
    goto LABEL_28;
  }
  if ( a2[5] <= 0x1F )
  {
    v5 = *(unsigned int *)(a1 + 32);
    v6 = *(unsigned int *)(a1 + 64);
    v7 = "__cam_isp_ctx_acquire_hw_v2";
    v8 = "data_size is not a valid value, ctx_id %u link: 0x%x";
    v9 = 8907;
    goto LABEL_20;
  }
  if ( mem_trace_en == 1 )
  {
    v26 = a2;
    v27 = a1;
    v28 = cam_mem_trace_alloc(a2[5], 0xCC0u, 0, "__cam_isp_ctx_acquire_hw_v2", 0x22CFu);
  }
  else
  {
    v27 = a1;
    v26 = a2;
    v28 = _kvmalloc_node_noprof(a2[5], 0, 3520, 0xFFFFFFFFLL);
  }
  v35 = (_QWORD *)v28;
  if ( !v28 )
    goto LABEL_166;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_acquire_hw_v2",
      8918,
      "start copy resources from user, ctx_id %u link: 0x%x",
      *(_DWORD *)(v27 + 32),
      *(_DWORD *)(v27 + 64));
  v36 = v26;
  v37 = v26[5];
  if ( (v37 & 0x80000000) != 0 )
  {
    __break(0x800u);
    goto LABEL_49;
  }
  v38 = *((_QWORD *)v36 + 3);
  v39 = v36;
  _check_object_size(v35, v37, 0);
  if ( inline_copy_from_user_5((int)v35, v38, v37) )
  {
LABEL_49:
    v40 = -14;
LABEL_71:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v35, 0);
    else
      kvfree(v35);
    result = v40;
    goto LABEL_29;
  }
  v149 = *(_QWORD *)(v27 + 232);
  v150 = cam_context_dump_pf_info;
  v48 = v39[5];
  LODWORD(v151) = -16843010;
  v152 = nullptr;
  HIDWORD(v151) = v48;
  v163 = nullptr;
  v164 = 0;
  v49 = *(__int64 **)(v27 + 208);
  v163 = _cam_isp_ctx_minidump_cb;
  v50 = *(_DWORD *)(v27 + 32);
  v161 = 0;
  v162 = 0;
  v159 = 0;
  v160 = 0;
  v158 = 0;
  v156 = 0;
  memset(v157, 0, sizeof(v157));
  v154 = 0;
  v155 = 0;
  v147 = v27;
  v152 = v35;
  v153 = 0;
  v148 = v50;
  v51 = (__int64 (__fastcall *)(__int64, __int64 *))v49[3];
  v52 = *v49;
  if ( *((_DWORD *)v51 - 1) != 1863972096 )
    __break(0x8228u);
  v53 = v51(v52, &v147);
  if ( v53 )
  {
    v40 = v53;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_acquire_hw_v2",
      8941,
      "Acquire device failed, ctx_id %u link: 0x%x",
      *(_DWORD *)(v27 + 32),
      *(_DWORD *)(v27 + 64));
    goto LABEL_71;
  }
  v58 = v159;
  v59 = (__int64 *)(v11 + 45672);
  *(_QWORD *)(v11 + 45704) = v159;
  if ( !v58 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_acquire_hw_v2",
      8949,
      "Failed in getting FCG caps, ctx_id: %u, link: 0x%x",
      *(_DWORD *)(v27 + 32),
      *(_DWORD *)(v27 + 64));
    goto LABEL_49;
  }
  v60 = _cam_isp_ctx_allocate_mem_hw_entries(v27, &v147);
  if ( v60 )
  {
    v61 = v60;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_acquire_hw_v2",
      8957,
      "Ctx[%u] link: 0x%x allocate hw entry fail",
      *(_DWORD *)(v27 + 32),
      *(_DWORD *)(v27 + 64));
LABEL_68:
    v62 = *(__int64 **)(v27 + 208);
    v146[0] = *(_QWORD *)(v11 + 37296);
    v63 = (_DWORD *)v62[4];
    v64 = *v62;
    if ( *(v63 - 1) != 1863972096 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD *))v63)(v64, v146);
    *(_QWORD *)(v11 + 37296) = 0;
    v40 = v61;
    *(_BYTE *)(v11 + 45740) = 0;
    goto LABEL_71;
  }
  v77 = BYTE4(v154);
  *(_BYTE *)(v11 + 45743) = BYTE4(v154) & 1;
  *(_BYTE *)(v11 + 45744) = (v77 & 2) != 0;
  *(_BYTE *)(v11 + 45747) = (v77 & 8) != 0;
  *(_BYTE *)(v11 + 45745) = (v77 & 4) != 0;
  *(_BYTE *)(v11 + 45748) = (v77 & 0x20) != 0;
  *(_BYTE *)(v11 + 45751) = (v77 & 0x40) != 0;
  *(_BYTE *)(v11 + 45752) = (v77 & 0x10) != 0;
  *(_BYTE *)(v11 + 45754) = v77 < 0;
  if ( mem_trace_en == 1 )
    v78 = cam_mem_trace_alloc(5256, 0xCC0u, 0, "__cam_isp_ctx_acquire_hw_v2", 0x2318u);
  else
    v78 = _kvmalloc_node_noprof(5256, 0, 3520, 0xFFFFFFFFLL);
  v80 = v27;
  *v59 = v78;
  if ( !v78 )
  {
    v83 = *(unsigned int *)(v27 + 32);
    v84 = "%s[%d] no memory for vfe_bus_comp_grp";
    v85 = 8987;
    goto LABEL_125;
  }
  if ( (v154 & 0x1000000000LL) != 0 )
  {
    if ( mem_trace_en == 1 )
      v82 = cam_mem_trace_alloc(3504, 0xCC0u, 0, "__cam_isp_ctx_acquire_hw_v2", 0x2322u);
    else
      v82 = _kvmalloc_node_noprof(3504, 0, 3520, 0xFFFFFFFFLL);
    v80 = v27;
    *(_QWORD *)(v11 + 45680) = v82;
    if ( v82 )
    {
      v129 = *v59;
      goto LABEL_101;
    }
    v83 = *(unsigned int *)(v27 + 32);
    v84 = "%s[%d] no memory for sfe_bus_comp_grp";
    v85 = 8997;
LABEL_125:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      0x80000,
      1,
      "__cam_isp_ctx_acquire_hw_v2",
      v85,
      v84,
      v80,
      v83);
    result = 4294967284LL;
    goto LABEL_29;
  }
  v81 = v78;
  v82 = *(_QWORD *)(v11 + 45680);
  v129 = v81;
  if ( v82 )
LABEL_101:
    v130 = v82;
  LODWORD(v131) = 10;
  v143 = v153;
  v86 = *(__int64 **)(v80 + 208);
  LODWORD(v144) = 0;
  v132 = &v129;
  v87 = (__int64 (__fastcall *)(__int64, __int64 *))v86[12];
  v145 = &v131;
  v88 = *v86;
  if ( *((_DWORD *)v87 - 1) != 1863972096 )
    __break(0x8229u);
  v89 = v87(v88, &v143);
  if ( v89 )
  {
    v61 = v89;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_acquire_hw_v2",
      9014,
      "HW command failed");
    goto LABEL_68;
  }
  LODWORD(v144) = 0;
  LODWORD(v131) = 4;
  v90 = *(__int64 **)(v27 + 208);
  v143 = v153;
  v145 = &v131;
  v91 = (__int64 (__fastcall *)(__int64, __int64 *))v90[12];
  v92 = *v90;
  if ( *((_DWORD *)v91 - 1) != 1863972096 )
    __break(0x8228u);
  v93 = v91(v92, &v143);
  if ( v93 )
  {
    v61 = v93;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_acquire_hw_v2",
      9027,
      "HW command failed, ctx_id %u link: 0x%x",
      *(_DWORD *)(v27 + 32),
      *(_DWORD *)(v27 + 64));
    goto LABEL_68;
  }
  if ( (_DWORD)v158 )
  {
    v101 = v156;
    v102 = v157[0];
    *((_QWORD *)v39 + 4) = v155;
    *((_QWORD *)v39 + 5) = v101;
    v103 = *(_QWORD *)((char *)&v157[4] + 4);
    LODWORD(v101) = HIDWORD(v157[7]);
    v39[12] = v102;
    v104 = *(_QWORD *)((char *)&v157[5] + 4);
    *(_QWORD *)(v39 + 21) = v103;
    v105 = *(_QWORD *)((char *)&v157[6] + 4);
    v39[27] = v101;
    v106 = *(_QWORD *)((char *)&v157[1] + 4);
    *(_QWORD *)(v39 + 25) = v105;
    v107 = *(_QWORD *)((char *)v157 + 4);
    *(_QWORD *)(v39 + 15) = v106;
    v108 = *(_QWORD *)((char *)&v157[3] + 4);
    *(_QWORD *)(v39 + 13) = v107;
    v109 = *(_QWORD *)((char *)&v157[2] + 4);
    *(_QWORD *)(v39 + 23) = v104;
    *(_QWORD *)(v39 + 17) = v109;
    LODWORD(v109) = v155;
    *(_QWORD *)(v39 + 19) = v108;
    *(_DWORD *)(v11 + 45696) = v109;
  }
  v110 = *(_QWORD *)(v27 + 216);
  if ( v110 && *(_QWORD *)(v110 + 40) )
  {
    v111 = *(_DWORD *)(v27 + 60);
    LODWORD(v125) = *(_DWORD *)(v27 + 64);
    HIDWORD(v125) = v111;
    LODWORD(v127) = 1;
    _cam_isp_ctx_convert_hw_id_to_string(v128, *(unsigned int *)(v11 + 45696));
    v112 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(v27 + 216) + 40LL);
    if ( *((_DWORD *)v112 - 1) != 1498387893 )
      __break(0x8228u);
    if ( v112(&v125) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_acquire_hw_v2",
        9052,
        "Failed at updating IFE hw idx to CRM");
  }
  v113 = debug_mdl;
  v114 = v133;
  v115 = debug_priority == 0;
  v39[28] = v158;
  v116 = v115 & (v113 >> 3);
  switch ( v114 )
  {
    case 1LL:
      if ( v116 )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v113 & 8,
          4,
          "__cam_isp_ctx_acquire_hw_v2",
          9077,
          "FS2 Session has PIX, RD and RDI, ctx_id %u link: 0x%x",
          *(_DWORD *)(v27 + 32),
          *(_DWORD *)(v27 + 64));
      v117 = cam_isp_ctx_fs2_state_machine_irq;
      v118 = &cam_isp_ctx_fs2_state_machine;
      break;
    case 4LL:
      if ( v116 )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v113 & 8,
          4,
          "__cam_isp_ctx_acquire_hw_v2",
          9084,
          "Offline Session has PIX and RD resources, ctx_id %u link: 0x%x",
          *(_DWORD *)(v27 + 32),
          *(_DWORD *)(v27 + 64));
      *(_QWORD *)(v11 + 32) = 0;
      *(_QWORD *)(v11 + 40) = &cam_isp_ctx_offline_state_machine_irq;
      *(_BYTE *)(v11 + 45737) = 1;
      goto LABEL_150;
    case 2LL:
      if ( v116 )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v113 & 8,
          4,
          "__cam_isp_ctx_acquire_hw_v2",
          9068,
          "RDI only session Context, ctx_id %u link: 0x%x",
          *(_DWORD *)(v27 + 32),
          *(_DWORD *)(v27 + 64));
      *(_QWORD *)(v11 + 32) = &cam_isp_ctx_rdi_only_activated_state_machine;
      *(_QWORD *)(v11 + 40) = &cam_isp_ctx_rdi_only_activated_state_machine_irq;
      *(_BYTE *)(v11 + 45736) = 1;
      goto LABEL_150;
    default:
      if ( v116 )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v113 & 8,
          4,
          "__cam_isp_ctx_acquire_hw_v2",
          9091,
          "Session has PIX or PIX and RDI resources, ctx_id %u link: 0x%x",
          *(_DWORD *)(v27 + 32),
          *(_DWORD *)(v27 + 64));
      v117 = cam_isp_ctx_activated_state_machine_irq;
      v118 = &cam_isp_ctx_activated_state_machine;
      break;
  }
  *(_QWORD *)(v11 + 32) = v118;
  *(_QWORD *)(v11 + 40) = v117;
LABEL_150:
  if ( ((*(_BYTE *)(v11 + 45737) & 1) != 0 || *(_BYTE *)(v11 + 45738) == 1)
    && (v124 = cam_req_mgr_workq_create(
                 "ife_apply_req",
                 0x14u,
                 (__int64 *)(v11 + 45592),
                 1,
                 0,
                 (__int64)cam_req_mgr_process_workq_apply_req_worker)) != 0 )
  {
    v119 = "Y";
    if ( *(_BYTE *)(v11 + 45737) )
      v120 = "Y";
    else
      v120 = "N";
    if ( !*(_BYTE *)(v11 + 45738) )
      v119 = "N";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_acquire_hw_v2",
      9107,
      "Failed to create workq for IFE rc:%d offline: %s vfps: %s ctx_id %u link: 0x%x",
      v124,
      v120,
      v119,
      *(_DWORD *)(v27 + 32),
      *(_DWORD *)(v27 + 64));
  }
  else
  {
    v124 = 0;
  }
  v121 = v153;
  *(_QWORD *)(v11 + 37296) = v153;
  *(_BYTE *)(v11 + 45740) = 1;
  v122 = v154;
  *(_QWORD *)(v27 + 264) = v121;
  LOBYTE(v121) = v134;
  *(_DWORD *)(v27 + 272) = v122;
  *(_BYTE *)(v11 + 45749) = v121;
  snprintf(
    (char *)(v27 + 276),
    0x80u,
    "%s_ctx[%d]_hwmgrctx[%d]_hwidx[0x%x]",
    (const char *)v27,
    *(_DWORD *)(v27 + 32),
    *(_DWORD *)(v27 + 272),
    *(_DWORD *)(v11 + 45696));
  trace_cam_context_state(v27);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "__cam_isp_ctx_acquire_hw_v2",
    9127,
    "Acquire success: session_hdl 0x%xs ctx_type %d ctx %u link: 0x%x hw_mgr_ctx: %u",
    *(_DWORD *)(v27 + 56),
    v133,
    *(_DWORD *)(v27 + 32),
    *(_DWORD *)(v27 + 64),
    v154);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v35, 0);
  else
    kvfree(v35);
  result = v124;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
