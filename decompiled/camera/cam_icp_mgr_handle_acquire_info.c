__int64 __fastcall cam_icp_mgr_handle_acquire_info(__int64 a1, __int64 a2, char a3)
{
  int v5; // w9
  unsigned __int64 v6; // x1
  const char *v7; // x3
  const char *v8; // x5
  __int64 v9; // x6
  __int64 v10; // x4
  unsigned __int64 v11; // x8
  _DWORD *v12; // x10
  int v13; // w12
  int v14; // w13
  int v15; // w11
  int v16; // w11
  unsigned __int64 StatusReg; // x11
  char v18; // w14
  unsigned int v19; // w12
  unsigned int v20; // w13
  int v21; // w10
  unsigned __int64 v22; // x10
  unsigned __int64 v23; // x9
  unsigned __int64 v29; // x10
  __int64 v30; // x0
  unsigned __int64 v31; // x8
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x1
  unsigned int v35; // w21
  int v36; // w12
  unsigned int v37; // w14
  int v38; // w11
  int v39; // w11
  int v40; // w11
  int v41; // w12
  unsigned int v42; // w15
  unsigned int v43; // w11
  unsigned int v44; // w13
  unsigned __int64 v45; // x10
  unsigned __int64 v46; // x11
  unsigned __int64 v47; // x9
  unsigned __int64 v49; // x10
  unsigned __int64 v50; // x8
  unsigned __int64 v52; // x9
  int v53; // w0
  __int64 v54; // x7
  __int64 v55; // x0
  const char *v56; // x5
  __int64 v57; // x6
  __int64 v58; // x4
  const char *v59; // x3
  const char *v60; // x5
  __int64 v61; // x6
  __int64 v62; // x4
  int v63; // w0
  unsigned int v65; // w22
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x21
  unsigned __int64 v70; // x23
  const char *v71; // x3
  __int64 v72; // x6
  __int64 v73; // x4
  unsigned __int64 v74; // x23
  int v75; // w8
  _DWORD *v76; // x0
  int v77; // w8
  _DWORD *v78; // x0
  unsigned int v79; // w9
  __int64 v80; // x23
  unsigned int v81; // w8
  _DWORD *v82; // x9
  __int64 v83; // x13
  __int16 v84; // w12
  int v85; // w13
  unsigned int v86; // w10
  unsigned int v87; // w9
  __int64 v88; // x23
  signed int v89; // w8
  _DWORD *v90; // x9
  _DWORD *v91; // x13
  int i; // w8
  __int64 v93; // x12
  __int64 v94; // x7
  __int16 v95; // w12
  int v96; // w13
  unsigned int v97; // w10
  _DWORD *v98; // x8
  _QWORD *v99; // x0
  _DWORD *v100; // x9
  _DWORD *v101; // x9
  unsigned int v102; // [xsp+34h] [xbp-7Ch]
  unsigned int v103; // [xsp+34h] [xbp-7Ch]
  __int64 v104; // [xsp+38h] [xbp-78h] BYREF
  __int64 v105; // [xsp+40h] [xbp-70h]
  __int64 v106; // [xsp+48h] [xbp-68h]
  __int64 v107; // [xsp+50h] [xbp-60h]
  unsigned __int64 v108; // [xsp+58h] [xbp-58h]
  _QWORD v109[3]; // [xsp+60h] [xbp-50h] BYREF
  __int64 v110; // [xsp+78h] [xbp-38h]
  __int64 v111; // [xsp+80h] [xbp-30h]
  __int64 v112; // [xsp+88h] [xbp-28h]
  __int64 v113; // [xsp+90h] [xbp-20h]
  __int64 v114; // [xsp+98h] [xbp-18h]
  __int64 v115; // [xsp+A0h] [xbp-10h]
  __int64 v116; // [xsp+A8h] [xbp-8h]

  v116 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a1 + 192);
  if ( (a3 & 1) != 0 )
  {
    if ( v5 == 1 )
    {
      v6 = *(_QWORD *)(a1 + 40);
      memset(v109, 0, 20);
      v107 = 0;
      v108 = 0;
      v105 = 0;
      v106 = 0;
      v104 = 0;
      if ( inline_copy_from_user_6((__int64)&v104, v6, 0x3Cu) )
      {
        v7 = "cam_icp_get_acquire_info_v1";
        v8 = "%s: Failed in acquire";
        v9 = a2 + 29824;
        v10 = 8371;
LABEL_13:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          256,
          1,
          v7,
          v10,
          v8,
          v9);
        v35 = -14;
        goto LABEL_42;
      }
      if ( (unsigned int)v106 >= 2 )
      {
        v59 = "cam_icp_get_acquire_info_v1";
        v60 = "%s: Invalid mode: %d";
        v61 = a2 + 29824;
        v62 = 8377;
LABEL_40:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          256,
          1,
          v59,
          v62,
          v60,
          v61);
        goto LABEL_41;
      }
      if ( (_DWORD)v106 == 1 )
      {
        *(_BYTE *)(a2 + 30172) = 1;
        *(_QWORD *)(a2 + 30156) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30164) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30140) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30148) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30124) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30132) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30108) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30116) = 0x101010101010101LL;
      }
      if ( (unsigned int)(LODWORD(v109[0]) - 16) <= 0xFFFFFFF0 )
      {
        v59 = "cam_icp_get_acquire_info_v1";
        v60 = "%s: Invalid num of out resources: %u";
        v61 = a2 + 29824;
        v62 = 8390;
        goto LABEL_40;
      }
      if ( (unsigned int)(HIDWORD(v104) - 10) <= 0xFFFFFFF6 )
      {
        v7 = "cam_icp_get_acquire_info_v1";
        v8 = "%s Invalid device type";
        v9 = a2 + 29824;
        v10 = 8397;
        goto LABEL_13;
      }
      v65 = 16 * LODWORD(v109[0]) + 44;
      if ( mem_trace_en == 1 )
        v66 = cam_mem_trace_alloc(16LL * LODWORD(v109[0]) + 44, 0xCC0u, 0, "cam_icp_get_acquire_info_v1", 0x20D4u);
      else
        v66 = _kvmalloc_node_noprof(v65, 0, 3520, 0xFFFFFFFFLL);
      v69 = v66;
      if ( v66 )
      {
        v70 = *(_QWORD *)(a1 + 40);
        _check_object_size(v66, v65, 0);
        if ( inline_copy_from_user_6(v69, v70, v65) )
        {
          v71 = "cam_icp_get_acquire_info_v1";
          v72 = a2 + 29824;
          v73 = 8411;
LABEL_65:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
            3,
            256,
            1,
            v71,
            v73,
            "%s: Failed in acquire: size = %d",
            v72,
            v65);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free((_QWORD *)v69, 0);
          else
            kvfree(v69);
          v35 = -14;
          goto LABEL_42;
        }
        v75 = 24 * LODWORD(v109[0]) + 52;
        if ( mem_trace_en == 1 )
        {
          v76 = (_DWORD *)cam_mem_trace_alloc(v75, 0xCC0u, 0, "cam_icp_get_acquire_info_v1", 0x20E4u);
          *(_QWORD *)(a2 + 80) = v76;
          if ( !v76 )
            goto LABEL_123;
LABEL_76:
          *v76 = *(_DWORD *)v69;
          *(_DWORD *)(*(_QWORD *)(a2 + 80) + 4LL) = *(_DWORD *)(v69 + 4);
          *(_DWORD *)(*(_QWORD *)(a2 + 80) + 8LL) = *(_DWORD *)(v69 + 8);
          *(_DWORD *)(*(_QWORD *)(a2 + 80) + 12LL) = *(_DWORD *)(v69 + 12);
          *(_DWORD *)(*(_QWORD *)(a2 + 80) + 16LL) = *(_DWORD *)(v69 + 16);
          *(_DWORD *)(*(_QWORD *)(a2 + 80) + 20LL) = *(_DWORD *)(v69 + 20);
          *(_DWORD *)(*(_QWORD *)(a2 + 80) + 24LL) = *(_DWORD *)(v69 + 24);
          *(_DWORD *)(*(_QWORD *)(a2 + 80) + 28LL) = *(_DWORD *)(v69 + 28);
          *(_DWORD *)(*(_QWORD *)(a2 + 80) + 32LL) = *(_DWORD *)(v69 + 32);
          *(_DWORD *)(*(_QWORD *)(a2 + 80) + 36LL) = *(_DWORD *)(v69 + 36);
          *(_DWORD *)(*(_QWORD *)(a2 + 80) + 40LL) = -1;
          *(_DWORD *)(*(_QWORD *)(a2 + 80) + 44LL) = 0;
          *(_DWORD *)(*(_QWORD *)(a2 + 80) + 48LL) = *(_DWORD *)(v69 + 40);
          v79 = v109[0];
          v80 = *(_QWORD *)(a2 + 80) + 52LL;
          if ( LODWORD(v109[0]) )
          {
            v81 = 0;
            do
            {
              v82 = (_DWORD *)(v69 + 44 + 16LL * (int)v81);
              v83 = v80 + 24LL * (int)v81++;
              *(_DWORD *)v83 = *v82;
              *(_DWORD *)(v83 + 4) = v82[1];
              *(_DWORD *)(v83 + 8) = v82[2];
              LODWORD(v82) = v82[3];
              *(_QWORD *)(v83 + 16) = 0xFFFFFFFFLL;
              *(_DWORD *)(v83 + 12) = (_DWORD)v82;
              v79 = v109[0];
            }
            while ( v81 < LODWORD(v109[0]) );
          }
          if ( (debug_mdl & 0x100) != 0 && !debug_priority )
          {
            v100 = *(_DWORD **)(a2 + 80);
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x100,
              4,
              "cam_icp_get_acquire_info_v1",
              8474,
              "%s: %x %x %x %x %x %x",
              (const char *)(a2 + 29824),
              v100[6],
              v100[7],
              v100[8],
              v100[9],
              v100[12],
              *v100);
            v79 = v109[0];
            if ( LODWORD(v109[0]) )
            {
LABEL_82:
              v84 = debug_mdl;
              v85 = debug_priority;
              v86 = 0;
              do
              {
                if ( (v84 & 0x100) != 0 && !v85 )
                {
                  v102 = v86;
                  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    v84 & 0x100,
                    4,
                    "cam_icp_get_acquire_info_v1",
                    8482,
                    "%s: out[i] %x %x %x %x",
                    (const char *)(a2 + 29824),
                    *(_DWORD *)(v80 + 24LL * (int)v86),
                    *(_DWORD *)(v80 + 24LL * (int)v86 + 4),
                    *(_DWORD *)(v80 + 24LL * (int)v86 + 8),
                    *(_DWORD *)(v80 + 24LL * (int)v86 + 12));
                  v86 = v102;
                  v84 = debug_mdl;
                  v85 = debug_priority;
                  v79 = v109[0];
                }
                ++v86;
              }
              while ( v86 < v79 );
            }
          }
          else if ( v79 )
          {
            goto LABEL_82;
          }
LABEL_118:
          if ( mem_trace_en == 1 )
            cam_mem_trace_free((_QWORD *)v69, 0);
          else
            kvfree(v69);
          v35 = 0;
          goto LABEL_42;
        }
        v76 = (_DWORD *)_kvmalloc_node_noprof(v75, 0, 3520, 0xFFFFFFFFLL);
        *(_QWORD *)(a2 + 80) = v76;
        if ( v76 )
          goto LABEL_76;
LABEL_123:
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v69, 0);
        else
          kvfree(v69);
        v35 = -12;
        goto LABEL_42;
      }
    }
    else
    {
      v34 = *(_QWORD *)(a1 + 40);
      v114 = 0;
      v115 = 0;
      v112 = 0;
      v113 = 0;
      v110 = 0;
      v111 = 0;
      v108 = 0;
      memset(v109, 0, sizeof(v109));
      v106 = 0;
      v107 = 0;
      v104 = 0;
      v105 = 0;
      if ( inline_copy_from_user_6((__int64)&v104, v34, 0x70u) )
      {
        v7 = "cam_icp_get_acquire_info_v2";
        v8 = "%s: Failed in acquire";
        v9 = a2 + 29824;
        v10 = 8501;
        goto LABEL_13;
      }
      if ( (unsigned int)v106 >= 2 )
      {
        v59 = "cam_icp_get_acquire_info_v2";
        v60 = "%s: Invalid mode: %d";
        v61 = a2 + 29824;
        v62 = 8507;
        goto LABEL_40;
      }
      if ( (_DWORD)v106 == 1 )
      {
        *(_BYTE *)(a2 + 30172) = 1;
        *(_QWORD *)(a2 + 30156) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30164) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30140) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30148) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30124) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30132) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30108) = 0x101010101010101LL;
        *(_QWORD *)(a2 + 30116) = 0x101010101010101LL;
      }
      if ( (unsigned int)(v112 - 16) <= 0xFFFFFFF0 )
      {
        v59 = "cam_icp_get_acquire_info_v2";
        v60 = "%s: Invalid num of out resources: %u";
        v61 = a2 + 29824;
        v62 = 8520;
        goto LABEL_40;
      }
      if ( (unsigned int)(HIDWORD(v104) - 10) <= 0xFFFFFFF6 )
      {
        v7 = "cam_icp_get_acquire_info_v2";
        v8 = "%s Invalid device type";
        v9 = a2 + 29824;
        v10 = 8527;
        goto LABEL_13;
      }
      v67 = 56LL * (unsigned int)v112;
      v65 = v67 + 112;
      if ( mem_trace_en == 1 )
        v68 = cam_mem_trace_alloc(v67 + 112, 0xCC0u, 0, "cam_icp_get_acquire_info_v2", 0x2156u);
      else
        v68 = _kvmalloc_node_noprof(v65, 0, 3520, 0xFFFFFFFFLL);
      v69 = v68;
      if ( v68 )
      {
        v74 = *(_QWORD *)(a1 + 40);
        _check_object_size(v68, v65, 0);
        if ( inline_copy_from_user_6(v69, v74, v65) )
        {
          v71 = "cam_icp_get_acquire_info_v2";
          v72 = a2 + 29824;
          v73 = 8541;
          goto LABEL_65;
        }
        v77 = 24 * v112 + 52;
        if ( mem_trace_en == 1 )
        {
          v78 = (_DWORD *)cam_mem_trace_alloc(v77, 0xCC0u, 0, "cam_icp_get_acquire_info_v2", 0x2166u);
          *(_QWORD *)(a2 + 80) = v78;
          if ( !v78 )
            goto LABEL_123;
        }
        else
        {
          v78 = (_DWORD *)_kvmalloc_node_noprof(v77, 0, 3520, 0xFFFFFFFFLL);
          *(_QWORD *)(a2 + 80) = v78;
          if ( !v78 )
            goto LABEL_123;
        }
        *v78 = *(_DWORD *)v69;
        *(_DWORD *)(*(_QWORD *)(a2 + 80) + 4LL) = *(_DWORD *)(v69 + 4);
        *(_DWORD *)(*(_QWORD *)(a2 + 80) + 8LL) = *(_DWORD *)(v69 + 8);
        *(_DWORD *)(*(_QWORD *)(a2 + 80) + 12LL) = *(_DWORD *)(v69 + 12);
        *(_DWORD *)(*(_QWORD *)(a2 + 80) + 16LL) = *(_DWORD *)(v69 + 16);
        *(_DWORD *)(*(_QWORD *)(a2 + 80) + 20LL) = *(_DWORD *)(v69 + 20);
        *(_DWORD *)(*(_QWORD *)(a2 + 80) + 24LL) = *(_DWORD *)(v69 + 24);
        *(_DWORD *)(*(_QWORD *)(a2 + 80) + 28LL) = *(_DWORD *)(v69 + 28);
        *(_DWORD *)(*(_QWORD *)(a2 + 80) + 32LL) = *(_DWORD *)(v69 + 32);
        *(_DWORD *)(*(_QWORD *)(a2 + 80) + 36LL) = *(_DWORD *)(v69 + 36);
        *(_DWORD *)(*(_QWORD *)(a2 + 80) + 40LL) = *(_DWORD *)(v69 + 40);
        *(_DWORD *)(*(_QWORD *)(a2 + 80) + 44LL) = *(_DWORD *)(v69 + 44);
        *(_DWORD *)(*(_QWORD *)(a2 + 80) + 48LL) = *(_DWORD *)(v69 + 80);
        v87 = v112;
        v88 = *(_QWORD *)(a2 + 80) + 52LL;
        if ( (_DWORD)v112 )
        {
          v89 = 0;
          do
          {
            v90 = (_DWORD *)(v69 + 112 + 56LL * v89);
            v91 = (_DWORD *)(v88 + 24LL * v89++);
            *v91 = *v90;
            v91[1] = v90[1];
            v91[2] = v90[2];
            v91[3] = v90[3];
            v91[4] = v90[4];
            v91[5] = v90[5];
            v87 = v112;
          }
          while ( v89 < (unsigned int)v112 );
          if ( (_DWORD)v112 && (_DWORD)v106 == 1 )
          {
            for ( i = 0; v87 != i; ++i )
            {
              v93 = v88 + 24LL * i;
              if ( *(_DWORD *)(v93 + 20) != 1 )
              {
                v94 = *(unsigned int *)(v93 + 16);
                if ( (unsigned int)v94 >= 0x41 )
                {
                  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                      3,
                      debug_mdl & 0x100,
                      4,
                      "cam_icp_get_acquire_info_v2",
                      8604,
                      "%s: Invalid out port ID: %d",
                      a2 + 29824);
                  if ( mem_trace_en == 1 )
                    cam_mem_trace_free((_QWORD *)v69, 0);
                  else
                    kvfree(v69);
                  v99 = *(_QWORD **)(a2 + 80);
                  if ( mem_trace_en == 1 )
                    cam_mem_trace_free(v99, 0);
                  else
                    kvfree(v99);
LABEL_41:
                  v35 = -22;
LABEL_42:
                  if ( v35 )
                  {
                    v63 = __ratelimit(&cam_icp_mgr_handle_acquire_info__rs, "cam_icp_mgr_handle_acquire_info");
                    v54 = *(unsigned int *)(a1 + 192);
                    if ( v63 )
                      v55 = 3;
                    else
                      v55 = 2;
                    v56 = "%s: copy from user failed, api version: %u";
                    v57 = a2 + 29824;
                    v58 = 8822;
                    goto LABEL_47;
                  }
                  goto LABEL_48;
                }
                *(_BYTE *)(a2 + 30108 + v94) = 0;
              }
            }
          }
        }
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        {
          v101 = *(_DWORD **)(a2 + 80);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_get_acquire_info_v2",
            8621,
            "%s: %x %x %x %x %x %x",
            (const char *)(a2 + 29824),
            v101[6],
            v101[7],
            v101[8],
            v101[9],
            v101[12],
            *v101);
          v87 = v112;
          if ( !(_DWORD)v112 )
            goto LABEL_118;
        }
        else if ( !v87 )
        {
          goto LABEL_118;
        }
        v95 = debug_mdl;
        v96 = debug_priority;
        v97 = 0;
        do
        {
          if ( (v95 & 0x100) != 0 && !v96 )
          {
            v98 = (_DWORD *)(v88 + 24LL * (int)v97);
            v103 = v97;
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v95 & 0x100,
              4,
              "cam_icp_get_acquire_info_v2",
              8630,
              "%s: out[i] %x %x %x %x %d",
              (const char *)(a2 + 29824),
              *v98,
              v98[1],
              v98[2],
              v98[3],
              v98[5]);
            v97 = v103;
            v95 = debug_mdl;
            v96 = debug_priority;
            v87 = v112;
          }
          ++v97;
        }
        while ( v97 < v87 );
        goto LABEL_118;
      }
    }
    v35 = -12;
    goto LABEL_42;
  }
  v11 = *(_QWORD *)(a1 + 40);
  v12 = *(_DWORD **)(a2 + 80);
  if ( v5 == 1 )
  {
    *(_OWORD *)((char *)v109 + 4) = 0u;
    v13 = v12[1];
    LODWORD(v104) = *v12;
    HIDWORD(v104) = v13;
    v14 = v12[3];
    LODWORD(v105) = v12[2];
    HIDWORD(v105) = v14;
    v15 = v12[5];
    LODWORD(v106) = v12[4];
    HIDWORD(v106) = v15;
    v16 = v12[7];
    LODWORD(v107) = v12[6];
    HIDWORD(v107) = v16;
    StatusReg = _ReadStatusReg(SP_EL0);
    v18 = *(_BYTE *)(StatusReg + 70);
    v19 = v12[8];
    v20 = v12[9];
    v21 = v12[12];
    v108 = __PAIR64__(v20, v19);
    LODWORD(v109[0]) = v21;
    if ( (v18 & 0x20) != 0 || (v22 = v11, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v22 = v11 & ((__int64)(v11 << 8) >> 8);
    if ( v22 <= 0x7FFFFFFFC4LL )
    {
      v23 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v29 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v29 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v29);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v23);
      v30 = _arch_copy_to_user(v11 & 0xFF7FFFFFFFFFFFFFLL);
      v31 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v33 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v33 - 4096);
      _WriteStatusReg(TTBR1_EL1, v33);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v31);
      goto LABEL_20;
    }
  }
  else
  {
    v114 = 0;
    v115 = 0;
    v112 = 0;
    v113 = 0;
    v110 = 0;
    v111 = 0;
    v109[1] = 0;
    v109[2] = 0;
    v36 = v12[1];
    v37 = v12[10];
    LODWORD(v104) = *v12;
    HIDWORD(v104) = v36;
    v38 = v12[3];
    LODWORD(v105) = v12[2];
    HIDWORD(v105) = v38;
    v39 = v12[5];
    LODWORD(v106) = v12[4];
    HIDWORD(v106) = v39;
    v40 = v12[7];
    v42 = v12[11];
    v41 = v12[12];
    LODWORD(v107) = v12[6];
    HIDWORD(v107) = v40;
    v43 = v12[8];
    v44 = v12[9];
    LODWORD(v112) = v41;
    v45 = _ReadStatusReg(SP_EL0);
    v109[0] = __PAIR64__(v42, v37);
    v108 = __PAIR64__(v44, v43);
    if ( (*(_BYTE *)(v45 + 70) & 0x20) != 0 || (v46 = v11, (*(_QWORD *)v45 & 0x4000000) != 0) )
      v46 = v11 & ((__int64)(v11 << 8) >> 8);
    if ( v46 <= 0x7FFFFFFF90LL )
    {
      v47 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v49 = *(_QWORD *)(v45 + 8);
      _WriteStatusReg(TTBR1_EL1, v49 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v49);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v47);
      v30 = _arch_copy_to_user(v11 & 0xFF7FFFFFFFFFFFFFLL);
      v50 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v52 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v52 - 4096);
      _WriteStatusReg(TTBR1_EL1, v52);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v50);
LABEL_20:
      if ( v30 )
        v35 = -22;
      else
        v35 = 0;
      if ( !v35 )
        goto LABEL_48;
      goto LABEL_24;
    }
  }
  v35 = -22;
LABEL_24:
  v53 = __ratelimit(&cam_icp_mgr_handle_acquire_info__rs_64, "cam_icp_mgr_handle_acquire_info");
  v54 = *(unsigned int *)(a1 + 192);
  if ( v53 )
    v55 = 3;
  else
    v55 = 2;
  v56 = "%s: copy to user failed, api version: %u";
  v57 = a2 + 29824;
  v58 = 8835;
LABEL_47:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
    v55,
    256,
    1,
    "cam_icp_mgr_handle_acquire_info",
    v58,
    v56,
    v57,
    v54);
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return v35;
}
