__int64 __fastcall cam_tpg_core_cfg(__int64 a1, int *a2)
{
  int v3; // w22
  unsigned int v5; // w20
  int v6; // w6
  unsigned __int64 v7; // x9
  char v8; // w10
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x10
  unsigned __int64 v11; // x10
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x2
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x9
  unsigned __int64 v22; // x9
  char v23; // w10
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x10
  unsigned __int64 v26; // x10
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x8
  unsigned __int64 v31; // x9
  int v32; // w8
  unsigned __int64 StatusReg; // x9
  char v34; // w10
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x10
  unsigned __int64 v37; // x10
  unsigned __int64 v39; // x9
  unsigned __int64 v40; // x8
  unsigned __int64 v42; // x9
  unsigned int v43; // w10
  _DWORD *v44; // x8
  __int64 v45; // x0
  __int64 *v46; // x1
  unsigned __int64 v47; // x9
  char v48; // w10
  unsigned __int64 v49; // x8
  unsigned __int64 v50; // x10
  unsigned __int64 v51; // x9
  char v52; // w10
  unsigned __int64 v53; // x8
  unsigned __int64 v54; // x10
  unsigned __int64 v55; // x10
  unsigned __int64 v57; // x9
  unsigned __int64 v58; // x8
  unsigned __int64 v60; // x9
  int v61; // w7
  unsigned __int64 v62; // x9
  char v63; // w10
  unsigned __int64 v64; // x8
  unsigned __int64 v65; // x10
  unsigned __int64 v66; // x10
  unsigned __int64 v68; // x9
  unsigned __int64 v69; // x8
  unsigned __int64 v71; // x9
  __int64 v72; // x6
  int v73; // w8
  const char *v74; // x3
  const char *v75; // x5
  __int64 v76; // x4
  unsigned __int64 v77; // x10
  unsigned __int64 v79; // x9
  unsigned __int64 v80; // x8
  unsigned __int64 v82; // x9
  unsigned int cpu_buf; // w0
  unsigned int v84; // w0
  __int64 v85; // x6
  const char *v86; // x5
  __int64 v87; // x4
  __int64 v88; // x7
  const char *v89; // x5
  __int64 v90; // x4
  const char *v91; // x5
  __int64 v92; // x4
  const char *v93; // x5
  __int64 v94; // x4
  int device_hdl; // w0
  int v96; // w8
  unsigned int v97; // w0
  __int64 v98; // x6
  const char *v99; // x5
  __int64 v100; // x4
  int v101; // w6
  unsigned int v102; // w0
  __int64 v103; // x6
  const char *v104; // x5
  __int64 v105; // x4
  int v106; // w6
  int v108; // w7
  int v109; // w9
  __int64 v110; // x10
  void (__fastcall *v111)(_QWORD); // x8
  __int64 v112; // x4
  __int64 v113; // [xsp+20h] [xbp-60h] BYREF
  unsigned __int64 v114; // [xsp+28h] [xbp-58h]
  __int64 v115; // [xsp+30h] [xbp-50h]
  unsigned int *v116; // [xsp+38h] [xbp-48h] BYREF
  unsigned __int64 v117; // [xsp+40h] [xbp-40h] BYREF
  __int64 v118; // [xsp+48h] [xbp-38h] BYREF
  __int64 v119; // [xsp+50h] [xbp-30h] BYREF
  __int64 v120; // [xsp+58h] [xbp-28h]
  __int64 v121; // [xsp+60h] [xbp-20h]
  __int64 v122; // [xsp+68h] [xbp-18h]
  __int64 v123; // [xsp+70h] [xbp-10h]
  __int64 v124; // [xsp+78h] [xbp-8h]

  v124 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v3 = a2[2];
    if ( v3 == 1 )
    {
      v5 = 0;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "validate_ioctl_params",
        854,
        "TPG[%d] Invalid handle type: %d",
        *(_DWORD *)(a1 + 564),
        v3);
      v5 = -22;
    }
    if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x200000000LL,
        4,
        "validate_ioctl_params",
        857,
        "TPG[%d] Opcode: %d",
        *(_DWORD *)(a1 + 564),
        *a2);
      if ( v3 != 1 )
        goto LABEL_130;
LABEL_10:
      mutex_lock(a1 + 24);
      v6 = *a2;
      if ( *a2 <= 259 )
      {
        switch ( v6 )
        {
          case 257:
            StatusReg = _ReadStatusReg(SP_EL0);
            v34 = *(_BYTE *)(StatusReg + 70);
            v35 = *((_QWORD *)a2 + 2);
            v120 = 0;
            v121 = 0;
            v119 = 0;
            if ( (v34 & 0x20) != 0 || (v36 = v35, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
              v36 = v35 & ((__int64)(v35 << 8) >> 8);
            if ( v36 <= 0x7FFFFFFFE8LL )
            {
              v37 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v39 = *(_QWORD *)(StatusReg + 8);
              _WriteStatusReg(TTBR1_EL1, v39 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v39);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v37);
              v18 = _arch_copy_from_user(&v119, v35 & 0xFF7FFFFFFFFFFFFFLL, 24);
              v40 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v42 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v42 - 4096);
              _WriteStatusReg(TTBR1_EL1, v42);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v40);
              if ( !v18 )
              {
                if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x200000000LL,
                    4,
                    "__cam_tpg_handle_query_cap",
                    247,
                    "Handling tpg query capability for %d slot: %d phy:%d",
                    *(_DWORD *)(a1 + 564),
                    *(_DWORD *)(a1 + 4836),
                    *(_DWORD *)(a1 + 4840));
                v43 = *(_DWORD *)(a1 + 564);
                v44 = *(_DWORD **)(a1 + 4600);
                HIDWORD(v120) = *(_DWORD *)(a1 + 4840);
                v119 = v43;
                if ( !v44 )
                {
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    0x200000000LL,
                    1,
                    "__cam_tpg_handle_query_cap",
                    254,
                    "Invalid hw info");
                  v85 = *(unsigned int *)(a1 + 564);
                  v86 = "TPG[%d] querycap is failed(rc = %d)";
                  v87 = 888;
                  v88 = 4294967274LL;
                  v5 = -22;
LABEL_128:
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
                    3,
                    0x200000000LL,
                    1,
                    "cam_tpg_core_cfg",
                    v87,
                    v86,
                    v85,
                    v88);
                  goto LABEL_129;
                }
                v45 = *((_QWORD *)a2 + 2);
                v46 = &v119;
                HIDWORD(v119) = *v44;
                goto LABEL_47;
              }
LABEL_70:
              if ( v18 >= 0x19 )
                goto LABEL_71;
LABEL_56:
              v5 = -14;
              goto LABEL_129;
            }
            break;
          case 258:
            v51 = _ReadStatusReg(SP_EL0);
            v52 = *(_BYTE *)(v51 + 70);
            v53 = *((_QWORD *)a2 + 2);
            v114 = 0;
            v115 = 0;
            v113 = 0;
            if ( (v52 & 0x20) != 0 || (v54 = v53, (*(_QWORD *)v51 & 0x4000000) != 0) )
              v54 = v53 & ((__int64)(v53 << 8) >> 8);
            if ( v54 <= 0x7FFFFFFFE8LL )
            {
              v55 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v57 = *(_QWORD *)(v51 + 8);
              _WriteStatusReg(TTBR1_EL1, v57 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v57);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v55);
              v18 = _arch_copy_from_user(&v113, v53 & 0xFF7FFFFFFFFFFFFFLL, 24);
              v58 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v60 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v60 - 4096);
              _WriteStatusReg(TTBR1_EL1, v60);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v58);
              if ( !v18 )
              {
                v61 = *(_DWORD *)(a1 + 4832);
                v120 = 0;
                if ( v61 )
                {
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                    3,
                    0x200000000LL,
                    1,
                    "__cam_tpg_handle_acquire_dev",
                    276,
                    "TPG[%d] not in right state[%d] to acquire",
                    *(unsigned int *)(a1 + 564));
                  v5 = -22;
LABEL_94:
                  v85 = *(unsigned int *)(a1 + 564);
                  v86 = "TPG[%d] acquire device failed(rc = %d)";
                  v87 = 910;
LABEL_127:
                  v88 = v5;
                  goto LABEL_128;
                }
                v119 = (unsigned int)v113;
                v122 = a1 + 4504;
                v123 = a1;
                v121 = 0x200000000LL;
                device_hdl = cam_create_device_hdl((__int64)&v119);
                v96 = v113;
                HIDWORD(v113) = device_hdl;
                *(_DWORD *)(a1 + 4488) = device_hdl;
                *(_DWORD *)(a1 + 4492) = v96;
                v97 = tpg_hw_acquire(a1 + 4568, 0);
                if ( v97 )
                {
                  v5 = v97;
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    0x200000000LL,
                    1,
                    "__cam_tpg_handle_acquire_dev",
                    294,
                    "TPG[%d] hw acquire failed",
                    *(_DWORD *)(a1 + 564));
                  cam_destroy_device_hdl(*(unsigned int *)(a1 + 4488));
                  *(_QWORD *)(a1 + 4488) = -1;
                  goto LABEL_94;
                }
                v101 = *(_DWORD *)(a1 + 564);
                *(_DWORD *)(a1 + 4832) = 1;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x200000000LL,
                  3,
                  "__cam_tpg_handle_acquire_dev",
                  300,
                  "TPG[%d] Acquire Device done",
                  v101);
                v45 = *((_QWORD *)a2 + 2);
                v46 = &v113;
LABEL_47:
                if ( inline_copy_to_user_6(v45, v46, v18) )
                  v5 = -14;
                else
                  v5 = 0;
                goto LABEL_129;
              }
              goto LABEL_70;
            }
            break;
          case 259:
            v7 = _ReadStatusReg(SP_EL0);
            v8 = *(_BYTE *)(v7 + 70);
            v9 = *((_QWORD *)a2 + 2);
            v119 = 0;
            if ( (v8 & 0x20) != 0 || (v10 = v9, (*(_QWORD *)v7 & 0x4000000) != 0) )
              v10 = v9 & ((__int64)(v9 << 8) >> 8);
            if ( v10 <= 0x7FFFFFFFF8LL )
            {
              v11 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v17 = *(_QWORD *)(v7 + 8);
              _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v17);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v11);
              v18 = _arch_copy_from_user(&v119, v9 & 0xFF7FFFFFFFFFFFFFLL, 8);
              v19 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v21 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v21 - 4096);
              _WriteStatusReg(TTBR1_EL1, v21);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v19);
              if ( v18 )
                goto LABEL_55;
              if ( v119 <= 0 )
              {
                v91 = "Invalid device handle for context";
                v92 = 366;
              }
              else
              {
                if ( (int)v119 > 0 )
                {
                  if ( *(_DWORD *)(a1 + 4832) == 1 )
                  {
                    v5 = tpg_hw_start(a1 + 4568);
                    if ( !v5 )
                    {
                      v72 = *(unsigned int *)(a1 + 564);
                      v73 = 2;
                      v74 = "__cam_tpg_handle_start_dev";
                      v75 = "TPG[%d] START_DEV done.";
                      v76 = 384;
LABEL_123:
                      *(_DWORD *)(a1 + 4832) = v73;
                      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                        3,
                        0x200000000LL,
                        3,
                        v74,
                        v76,
                        v75,
                        v72);
                      goto LABEL_129;
                    }
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      0x200000000LL,
                      1,
                      "__cam_tpg_handle_start_dev",
                      381,
                      "TPG[%d] START_DEV failed",
                      *(_DWORD *)(a1 + 564));
                    goto LABEL_109;
                  }
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                    3,
                    0x200000000LL,
                    1,
                    "__cam_tpg_handle_start_dev",
                    376,
                    "TPG[%d] not in right state[%d] to start",
                    *(unsigned int *)(a1 + 564));
LABEL_108:
                  v5 = -22;
LABEL_109:
                  v85 = *(unsigned int *)(a1 + 564);
                  v86 = "TPG[%d] start device failed(rc = %d)";
                  v87 = 946;
                  goto LABEL_127;
                }
                v91 = "Invalid session handle for context";
                v92 = 371;
              }
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x200000000LL,
                1,
                "__cam_tpg_handle_start_dev",
                v92,
                v91);
              goto LABEL_108;
            }
LABEL_54:
            v18 = 8;
            do
            {
LABEL_55:
              if ( v18 < 9 )
                goto LABEL_56;
LABEL_71:
              _fortify_panic(15, 0, v18);
LABEL_72:
              v66 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v68 = *(_QWORD *)(v47 + 8);
              _WriteStatusReg(TTBR1_EL1, v68 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v68);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v66);
              v18 = _arch_copy_from_user(&v119, v49 & 0xFF7FFFFFFFFFFFFFLL, 8);
              v69 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v71 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v71 - 4096);
              _WriteStatusReg(TTBR1_EL1, v71);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v69);
            }
            while ( v18 );
            if ( v119 <= 0 )
            {
              v89 = "Invalid device handle for context";
              v90 = 399;
            }
            else
            {
              if ( (int)v119 > 0 )
              {
                if ( *(_DWORD *)(a1 + 4832) == 2 )
                {
                  v5 = tpg_hw_stop(a1 + 4568);
                  if ( !v5 )
                  {
                    v72 = *(unsigned int *)(a1 + 564);
                    v73 = 1;
                    v74 = "__cam_tpg_handle_stop_dev";
                    v75 = "TPG[%d] STOP_DEV done.";
                    v76 = 420;
                    goto LABEL_123;
                  }
                }
                else
                {
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                    3,
                    0x200000000LL,
                    1,
                    "__cam_tpg_handle_stop_dev",
                    409,
                    "TPG[%d] not in right state[%d] to stop",
                    *(unsigned int *)(a1 + 564));
                  v5 = -22;
                }
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x200000000LL,
                  1,
                  "__cam_tpg_handle_stop_dev",
                  417,
                  "TPG[%d] STOP_DEV failed",
                  *(_DWORD *)(a1 + 564));
                goto LABEL_106;
              }
              v89 = "Invalid session handle for context";
              v90 = 404;
            }
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x200000000LL,
              1,
              "__cam_tpg_handle_stop_dev",
              v90,
              v89);
            v5 = -22;
LABEL_106:
            v85 = *(unsigned int *)(a1 + 564);
            v86 = "TPG[%d] stop device failed(rc = %d)";
            v87 = 962;
            goto LABEL_127;
          default:
            goto LABEL_57;
        }
LABEL_69:
        v18 = 24;
        goto LABEL_70;
      }
      if ( v6 == 260 )
      {
        v47 = _ReadStatusReg(SP_EL0);
        v48 = *(_BYTE *)(v47 + 70);
        v49 = *((_QWORD *)a2 + 2);
        v119 = 0;
        if ( (v48 & 0x20) != 0 || (v50 = v49, (*(_QWORD *)v47 & 0x4000000) != 0) )
          v50 = v49 & ((__int64)(v49 << 8) >> 8);
        if ( v50 <= 0x7FFFFFFFF8LL )
          goto LABEL_72;
        goto LABEL_54;
      }
      if ( v6 != 261 )
      {
        if ( v6 != 262 )
        {
LABEL_57:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x200000000LL,
            1,
            "cam_tpg_core_cfg",
            984,
            "Invalid ioctl : %d",
            v6);
          v5 = -22;
          goto LABEL_129;
        }
        v22 = _ReadStatusReg(SP_EL0);
        v23 = *(_BYTE *)(v22 + 70);
        v24 = *((_QWORD *)a2 + 2);
        v119 = 0;
        if ( (v23 & 0x20) != 0 || (v25 = v24, (*(_QWORD *)v22 & 0x4000000) != 0) )
          v25 = v24 & ((__int64)(v24 << 8) >> 8);
        if ( v25 > 0x7FFFFFFFF8LL )
          goto LABEL_54;
        v26 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v28 = *(_QWORD *)(v22 + 8);
        _WriteStatusReg(TTBR1_EL1, v28 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v28);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v26);
        v18 = _arch_copy_from_user(&v119, v24 & 0xFF7FFFFFFFFFFFFFLL, 8);
        v29 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v31 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v31 - 4096);
        _WriteStatusReg(TTBR1_EL1, v31);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v29);
        if ( v18 )
          goto LABEL_55;
        if ( v119 <= 0 )
        {
          v93 = "Invalid device handle for context";
          v94 = 318;
        }
        else
        {
          if ( (int)v119 > 0 )
          {
            v32 = *(_DWORD *)(a1 + 4832);
            if ( v32 == 2 )
            {
              if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x200000000LL,
                  4,
                  "__cam_tpg_handle_release_dev",
                  334,
                  "TPG[%d] release from start state",
                  *(_DWORD *)(a1 + 564));
              v102 = tpg_hw_stop(a1 + 4568);
              if ( (v102 & 0x80000000) != 0 )
              {
                v103 = *(unsigned int *)(a1 + 564);
                v5 = v102;
                v104 = "TPG[%d] unable to stop tpg";
                v105 = 338;
LABEL_125:
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                  3,
                  0x200000000LL,
                  1,
                  "__cam_tpg_handle_release_dev",
                  v105,
                  v104,
                  v103);
                goto LABEL_126;
              }
            }
            else if ( !v32 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x200000000LL,
                2,
                "__cam_tpg_handle_release_dev",
                328,
                "TPG[%d] not in right state[%d] to release",
                *(_DWORD *)(a1 + 564),
                0);
              v5 = 0;
LABEL_129:
              mutex_unlock(a1 + 24);
              goto LABEL_130;
            }
            v5 = tpg_hw_release(a1 + 4568);
            if ( !v5 )
            {
              cam_destroy_device_hdl(*(unsigned int *)(a1 + 4488));
              v106 = *(_DWORD *)(a1 + 564);
              *(_QWORD *)(a1 + 4488) = -1;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x200000000LL,
                3,
                "__cam_tpg_handle_release_dev",
                350,
                "TPG[%d] Release Done.",
                v106);
              *(_DWORD *)(a1 + 4832) = 0;
              goto LABEL_129;
            }
            v103 = *(unsigned int *)(a1 + 564);
            v104 = "TPG[%d] hw release failed";
            v105 = 345;
            goto LABEL_125;
          }
          v93 = "Invalid session handle for context";
          v94 = 323;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x200000000LL,
          1,
          "__cam_tpg_handle_release_dev",
          v94,
          v93);
        v5 = -22;
LABEL_126:
        v85 = *(unsigned int *)(a1 + 564);
        v86 = "TPG[%d] release device failed(rc = %d)";
        v87 = 930;
        goto LABEL_127;
      }
      v62 = _ReadStatusReg(SP_EL0);
      v63 = *(_BYTE *)(v62 + 70);
      v64 = *((_QWORD *)a2 + 2);
      v114 = 0;
      v115 = 0;
      v113 = 0;
      if ( (v63 & 0x20) != 0 || (v65 = v64, (*(_QWORD *)v62 & 0x4000000) != 0) )
        v65 = v64 & ((__int64)(v64 << 8) >> 8);
      if ( v65 > 0x7FFFFFFFE8LL )
        goto LABEL_69;
      v77 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v79 = *(_QWORD *)(v62 + 8);
      _WriteStatusReg(TTBR1_EL1, v79 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v79);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v77);
      v18 = _arch_copy_from_user(&v113, v64 & 0xFF7FFFFFFFFFFFFFLL, 24);
      v80 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v82 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v82 - 4096);
      _WriteStatusReg(TTBR1_EL1, v82);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v80);
      if ( v18 )
        goto LABEL_70;
      if ( v113 <= 0 )
      {
        v98 = *(unsigned int *)(a1 + 564);
        v99 = "TPG[%d] Invalid device handle";
        v100 = 820;
      }
      else
      {
        if ( (int)v113 > 0 )
        {
          if ( *(int *)(a1 + 4832) <= 0 )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              0x200000000LL,
              1,
              "__cam_tpg_handle_config_dev",
              832,
              "TPG[%d] not in right state[%d] to configure",
              *(unsigned int *)(a1 + 564));
          v118 = 0;
          v116 = nullptr;
          v117 = 0;
          cpu_buf = cam_mem_get_cpu_buf(v115, &v118, &v117);
          if ( (cpu_buf & 0x80000000) != 0 )
          {
            v5 = cpu_buf;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x200000000LL,
              1,
              "cam_tpg_packet_parse",
              722,
              "Failed in getting the packet: %d",
              cpu_buf);
            goto LABEL_113;
          }
          if ( v117 < 0x40 || v114 >= v117 - 64 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              0x200000000LL,
              1,
              "cam_tpg_packet_parse",
              731,
              "Inval cam_packet struct size: %zu, len_of_buff: %zu",
              64);
            v5 = -22;
            goto LABEL_111;
          }
          v84 = cam_packet_util_copy_pkt_to_kmd(v118 + (unsigned int)v114, &v116, v117 - v114);
          if ( v84 )
          {
            v5 = v84;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              0x200000000LL,
              1,
              "cam_tpg_packet_parse",
              741,
              "Copying packet to KMD failed");
LABEL_111:
            cam_mem_put_cpu_buf(v115);
            goto LABEL_113;
          }
          if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x200000000LL,
              4,
              "cam_tpg_packet_parse",
              751,
              "TPG[%d] CONFIG_DEV, Packet opcode = %d num_cmds: %d num_ios: %d num_patch: %d",
              *(_DWORD *)(a1 + 564),
              *(unsigned __int8 *)v116,
              v116[7],
              v116[9],
              v116[11]);
          v108 = *(unsigned __int8 *)v116;
          if ( (unsigned int)(v108 - 2) >= 2 )
          {
            if ( v108 != 1 )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                0x200000000LL,
                1,
                "cam_tpg_packet_parse",
                797,
                "TPG[%d] Invalid packet %x",
                *(unsigned int *)(a1 + 564));
              v5 = -22;
              goto LABEL_157;
            }
            if ( !v116[7] )
            {
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                3,
                0x200000000LL,
                1,
                "cam_tpg_packet_parse",
                755,
                "Expecting atleast one command in Init packet");
              v5 = -22;
              goto LABEL_157;
            }
            v5 = cam_tpg_cmd_buf_parse(a1);
            if ( (v5 & 0x80000000) == 0 )
            {
              tpg_hw_config(a1 + 4568, 1, 0);
              goto LABEL_157;
            }
            v112 = 761;
          }
          else
          {
            v121 = 0;
            v122 = 0;
            v5 = cam_tpg_cmd_buf_parse(a1);
            if ( (v5 & 0x80000000) == 0 )
            {
              if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x200000000LL,
                  4,
                  "cam_tpg_packet_parse",
                  779,
                  "TPG[%d] packet request id : %llu",
                  *(_DWORD *)(a1 + 564),
                  *((_QWORD *)v116 + 1));
              if ( *(_DWORD *)(a1 + 4496) == -1
                || (v109 = *(_DWORD *)(a1 + 4488), v109 == -1)
                || (v110 = *(_QWORD *)(a1 + 4560)) == 0 )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x200000000LL,
                  1,
                  "cam_tpg_packet_parse",
                  790,
                  "TPG[%d] add request %d failed",
                  *(_DWORD *)(a1 + 564),
                  *((_QWORD *)v116 + 1));
              }
              else
              {
                LODWORD(v119) = *(_DWORD *)(a1 + 4496);
                HIDWORD(v119) = v109;
                v111 = *(void (__fastcall **)(_QWORD))(v110 + 16);
                v120 = *((_QWORD *)v116 + 1);
                if ( *((_DWORD *)v111 - 1) != -1947527126 )
                  __break(0x8228u);
                v111(&v119);
              }
LABEL_157:
              cam_common_mem_free((__int64)v116);
              cam_mem_put_cpu_buf(v115);
              if ( !v5 )
                goto LABEL_129;
              goto LABEL_113;
            }
            v112 = 773;
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x200000000LL,
            1,
            "cam_tpg_packet_parse",
            v112,
            "CMD buffer parse failed");
          goto LABEL_157;
        }
        v98 = *(unsigned int *)(a1 + 564);
        v99 = "TPG[%d] Invalid session handle";
        v100 = 826;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "__cam_tpg_handle_config_dev",
        v100,
        v99,
        v98);
      v5 = -22;
LABEL_113:
      v85 = *(unsigned int *)(a1 + 564);
      v86 = "TPG[%d] config device failed(rc = %d)";
      v87 = 979;
      goto LABEL_127;
    }
    if ( v3 == 1 )
      goto LABEL_10;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "validate_ioctl_params",
      846,
      "Invalid input args");
    v5 = -22;
  }
LABEL_130:
  _ReadStatusReg(SP_EL0);
  return v5;
}
