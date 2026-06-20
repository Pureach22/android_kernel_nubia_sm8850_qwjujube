__int64 __fastcall cam_generic_fence_process_synx_obj_cmd(int a1, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v3; // w0
  unsigned __int64 v4; // x20
  __int64 v5; // x6
  char v6; // w23
  unsigned int v7; // w21
  __int64 v8; // x19
  int v9; // w8
  int v10; // w9
  int v11; // w25
  __int64 v12; // x0
  unsigned int v13; // w0
  int v14; // w21
  __int64 v15; // x25
  int v16; // w8
  __int64 v17; // x1
  __int64 v18; // x1
  __int64 v19; // x4
  const char *v20; // x5
  __int64 v21; // x6
  int v22; // w0
  unsigned int v23; // w0
  unsigned __int64 v24; // x28
  int v25; // w24
  unsigned __int64 v26; // x25
  unsigned __int64 v27; // x26
  __int64 v28; // x0
  int obj_in_table; // w0
  __int64 v30; // x27
  int util; // w0
  int v32; // w19
  unsigned int v33; // w23
  __int64 v34; // x28
  int v35; // w8
  int v36; // w0
  unsigned __int64 v43; // x9
  const char *v44; // x3
  const char *v45; // x5
  __int64 v46; // x4
  unsigned __int64 v47; // x7
  int v48; // w22
  __int64 v49; // x21
  unsigned __int64 v50; // x23
  unsigned __int64 v51; // x8
  unsigned __int64 v52; // x9
  int v53; // w9
  unsigned __int64 v54; // x9
  unsigned __int64 v56; // x8
  unsigned __int64 v57; // x8
  unsigned __int64 v59; // x10
  __int64 v60; // x6
  __int64 v61; // x7
  const char *v62; // x3
  __int64 v63; // x4
  int v64; // w22
  __int64 v65; // x21
  unsigned __int64 v66; // x23
  unsigned __int64 v67; // x8
  unsigned __int64 v68; // x9
  unsigned __int64 v69; // x9
  unsigned __int64 v71; // x8
  unsigned __int64 v72; // x8
  unsigned __int64 v74; // x10
  unsigned int v75; // w19
  int v76; // w8
  _QWORD *v77; // x0
  __int64 result; // x0
  unsigned int v79; // w8
  const char *v80; // x5
  __int64 v81; // x4
  __int64 v82; // x6
  int v83; // w7
  __int64 v84; // x0
  unsigned __int64 v85; // x0
  int v86; // w19
  unsigned int v87; // w19
  int v88; // w19
  _QWORD *v89; // x21
  unsigned int v90; // w27
  _QWORD *v91; // x9
  _QWORD *v92; // x24
  unsigned int v93; // w0
  int v94; // w6
  int v95; // w8
  unsigned int v96; // w24
  __int64 v97; // x22
  unsigned int v98; // w23
  unsigned __int64 v99; // x26
  unsigned __int64 StatusReg; // x24
  unsigned __int64 v101; // x8
  unsigned __int64 v102; // x8
  unsigned __int64 v104; // x9
  unsigned __int64 v105; // x8
  unsigned __int64 v107; // x9
  __int64 v108; // x6
  const char *v109; // x5
  __int64 v110; // x4
  __int64 v111; // x7
  __int64 v112; // x8
  __int64 v113; // x22
  unsigned __int64 v114; // x9
  unsigned __int64 v115; // x9
  unsigned __int64 v117; // x10
  __int64 v118; // x0
  unsigned __int64 v119; // x8
  unsigned __int64 v121; // x9
  __int64 v122; // x21
  int v123; // w22
  unsigned __int64 v124; // x23
  unsigned __int64 v125; // x8
  unsigned __int64 v126; // x9
  int v127; // w9
  unsigned __int64 v128; // x9
  unsigned __int64 v130; // x8
  unsigned __int64 v131; // x8
  unsigned __int64 v133; // x10
  __int64 v134; // [xsp+0h] [xbp-80h]
  __int64 v135; // [xsp+28h] [xbp-58h]
  __int64 v136; // [xsp+28h] [xbp-58h]
  unsigned __int64 v137; // [xsp+30h] [xbp-50h]
  unsigned __int64 v138; // [xsp+38h] [xbp-48h] BYREF
  __int64 v139; // [xsp+40h] [xbp-40h] BYREF
  int v140; // [xsp+48h] [xbp-38h]
  unsigned int v141; // [xsp+4Ch] [xbp-34h] BYREF
  unsigned __int64 v142; // [xsp+50h] [xbp-30h] BYREF
  __int64 v143; // [xsp+58h] [xbp-28h]
  __int64 v144; // [xsp+60h] [xbp-20h]
  __int64 v145; // [xsp+68h] [xbp-18h]
  __int64 v146; // [xsp+70h] [xbp-10h]
  __int64 v147; // [xsp+78h] [xbp-8h]

  v2 = a2;
  v147 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 > 12 )
  {
    if ( a1 != 13 )
    {
      if ( a1 != 14 )
        goto LABEL_20;
      if ( *(_DWORD *)(a2 + 12) != 56 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          128,
          1,
          "cam_generic_fence_validate_signal_input_info_util",
          1473,
          "Size is invalid expected: 0x%llx actual: 0x%llx",
          56);
        v5 = 4294967274LL;
LABEL_118:
        v44 = "cam_generic_fence_handle_synx_signal";
        v45 = "Fence input signal info validation failed rc: %d fence_input_info: %pK synx_signal_info: %pK";
        v46 = 1858;
        v47 = 0;
        v134 = 0;
        goto LABEL_119;
      }
      v12 = *(_QWORD *)(a2 + 16);
      if ( mem_trace_en == 1 )
      {
        v4 = memdup_user_trace(v12, 0x38u, "cam_generic_fence_validate_signal_input_info_util", 0x5C6u);
        if ( !v4 )
          goto LABEL_99;
      }
      else
      {
        v4 = memdup_user(v12, 56);
        if ( !v4 )
          goto LABEL_99;
      }
      if ( v4 < 0xFFFFFFFFFFFFF001LL )
      {
        v79 = *(_DWORD *)(v4 + 4);
        if ( v79 - 11 <= 0xFFFFFFF5 )
        {
          v80 = "Invalid number of fences: %u for batching";
          v81 = 1489;
          v82 = v79;
LABEL_112:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            128,
            1,
            "cam_generic_fence_validate_signal_input_info_util",
            v81,
            v80,
            v82);
LABEL_113:
          v87 = -22;
LABEL_114:
          if ( mem_trace_en == 1 )
            cam_mem_trace_free((_QWORD *)v4, 0);
          else
            kvfree(v4);
          v5 = v87;
          goto LABEL_118;
        }
        v82 = *(unsigned int *)(v4 + 12);
        if ( (_DWORD)v82 != 1 )
        {
          v80 = "Invalid signal handle type: %d";
          v81 = 1496;
          goto LABEL_112;
        }
        v83 = *(_DWORD *)(v4 + 16);
        if ( v83 != 40 * v79 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            128,
            1,
            "cam_generic_fence_validate_signal_input_info_util",
            1520,
            "Invalid input size expected: 0x%x actual: 0x%x for fences: %u",
            40 * v79,
            v83,
            *(_DWORD *)(v4 + 4));
          goto LABEL_113;
        }
        v84 = *(_QWORD *)(v4 + 24);
        if ( mem_trace_en == 1 )
          v85 = memdup_user_trace(
                  v84,
                  *(unsigned int *)(v4 + 16),
                  "cam_generic_fence_validate_signal_input_info_util",
                  0x5F6u);
        else
          v85 = memdup_user(v84, *(unsigned int *)(v4 + 16));
        v89 = (_QWORD *)v85;
        if ( !v85 || v85 > 0xFFFFFFFFFFFFF000LL )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            128,
            1,
            "cam_generic_fence_validate_signal_input_info_util",
            1529,
            "memdup failed for hdl: %d size: 0x%x",
            *(_QWORD *)(v4 + 24),
            *(_DWORD *)(v4 + 16));
          v87 = -12;
          goto LABEL_114;
        }
        if ( *(_DWORD *)(v4 + 4) )
        {
          v90 = 0;
          do
          {
            v92 = &v89[5 * (int)v90];
            ++*(_DWORD *)(v4 + 8);
            v93 = cam_synx_obj_signal_obj(v92);
            if ( v93 )
            {
              v94 = *((_DWORD *)v92 + 1);
              v95 = *((_DWORD *)v92 + 2);
              v96 = v93;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x1000000000LL,
                1,
                "cam_generic_fence_handle_synx_signal",
                1870,
                "Failed to signal for synx_obj: %d, rc: %d, status : %d",
                v94,
                v93,
                v95);
              v93 = v96;
            }
            v91 = &v89[5 * (int)v90++];
            *((_DWORD *)v91 + 3) = v93;
          }
          while ( v90 < *(_DWORD *)(v4 + 4) );
        }
        else
        {
          v93 = 0;
        }
        v97 = *(unsigned int *)(v4 + 16);
        if ( (v97 & 0x80000000) != 0 )
        {
          __break(0x800u);
        }
        else
        {
          v98 = v93;
          v99 = *(_QWORD *)(v4 + 24);
          _check_object_size(v89, *(unsigned int *)(v4 + 16), 1);
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v101 = v99, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v101 = v99 & ((__int64)(v99 << 8) >> 8);
          if ( 0x8000000000LL - v97 >= v101 )
          {
            v102 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v104 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v104 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v104);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v102);
            v97 = _arch_copy_to_user(v99 & 0xFF7FFFFFFFFFFFFFLL);
            v105 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v107 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v107 - 4096);
            _WriteStatusReg(TTBR1_EL1, v107);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v105);
          }
          if ( !v97 )
          {
            v112 = *(_QWORD *)(v2 + 16);
            v113 = v2;
            if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0
              || (v114 = *(_QWORD *)(v2 + 16), (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            {
              v114 = v112 & (v112 << 8 >> 8);
            }
            if ( v114 <= 0x7FFFFFFFC8LL )
            {
              v115 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v117 = *(_QWORD *)(StatusReg + 8);
              _WriteStatusReg(TTBR1_EL1, v117 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v117);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v115);
              v118 = _arch_copy_to_user(v112 & 0xFF7FFFFFFFFFFFFFLL);
              v119 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v121 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v121 - 4096);
              _WriteStatusReg(TTBR1_EL1, v121);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v119);
              v75 = v98;
              if ( !v118 )
                goto LABEL_151;
            }
            v108 = *(_QWORD *)(v113 + 16);
            v109 = "copy to user failed hdl: %d size: 0x%x";
            v110 = 1891;
            v111 = 56;
LABEL_150:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
              3,
              0x1000000000LL,
              1,
              "cam_generic_fence_handle_synx_signal",
              v110,
              v109,
              v108,
              v111);
            v75 = -14;
LABEL_151:
            if ( mem_trace_en == 1 )
              cam_mem_trace_free(v89, 0);
            else
              kvfree(v89);
            v76 = (unsigned __int8)mem_trace_en;
            goto LABEL_93;
          }
        }
        v108 = *(_QWORD *)(v2 + 16);
        v109 = "copy to user for signal data failed hdl: %d size: 0x%x";
        v110 = 1882;
        v111 = 40LL * *(unsigned int *)(v4 + 4);
        goto LABEL_150;
      }
LABEL_99:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        128,
        1,
        "cam_generic_fence_validate_signal_input_info_util",
        1481,
        "memdup failed for hdl: %d size: 0x%x",
        *(_QWORD *)(v2 + 16),
        *(_DWORD *)(v2 + 12));
      v5 = 4294967284LL;
      goto LABEL_118;
    }
    v141 = 0;
    v140 = 0;
    v138 = 0;
    v139 = 0;
    v23 = cam_generic_fence_alloc_validate_input_info_util(a2, &v138);
    v24 = v138;
    v5 = v23;
    if ( v23 || !v138 )
    {
      v44 = "cam_generic_fence_handle_synx_import";
      v45 = "Fence input info validation failed rc: %d fence_input_info: %pK";
      v46 = 1767;
      v47 = v138;
      goto LABEL_119;
    }
    if ( !*(_DWORD *)(v138 + 4) )
    {
      util = 0;
      goto LABEL_158;
    }
    v136 = v2;
    v137 = v138;
    v25 = 0;
    v26 = v138 + 32;
    while ( 1 )
    {
      v27 = v26 + 112LL * v25;
      v28 = *(unsigned int *)(v27 + 80);
      ++*(_DWORD *)(v24 + 8);
      *(_DWORD *)(v27 + 84) = 0;
      obj_in_table = cam_synx_obj_find_obj_in_table(v28, &v141);
      if ( obj_in_table )
      {
        v86 = obj_in_table;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x1000000000LL,
          1,
          "cam_generic_fence_handle_synx_import",
          1783,
          "Invalid synx obj for handle: %d",
          *(_DWORD *)(v27 + 80));
        util = v86;
        *(_DWORD *)(v27 + 84) = -22;
        goto LABEL_157;
      }
      v30 = *(unsigned int *)(v27 + 72);
      if ( (unsigned int)(v30 - 2048) >= 0xFFFFF801 )
      {
        v32 = *(_DWORD *)(v27 + 80);
        v33 = v141;
        v145 = 0;
        v146 = 0;
        v143 = 0;
        v144 = 0;
        v142 = 0;
        util = cam_sync_check_valid(v30);
        if ( util )
          goto LABEL_156;
        v34 = *(_QWORD *)(sync_dev + 128) + 216LL * (unsigned int)v30;
        raw_spin_lock(sync_dev + 4 * v30 + 136);
        if ( (*(_QWORD *)(v34 + 184) & 8) != 0 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            128,
            1,
            "cam_sync_synx_associate_obj",
            1729,
            "sync_obj: %s[%d] has already been associated with a synx_hdl: 0x%x",
            (const char *)v34,
            v30,
            *(_DWORD *)(v34 + 204));
          raw_spin_unlock(sync_dev + 4 * v30 + 136);
          v24 = v137;
          util = -22;
LABEL_156:
          *(_DWORD *)(v27 + 84) = util;
LABEL_157:
          v2 = v136;
LABEL_158:
          v122 = *(unsigned int *)(v2 + 12);
          if ( (v122 & 0x80000000) != 0 )
          {
            __break(0x800u);
            goto LABEL_166;
          }
          v123 = util;
          v124 = *(_QWORD *)(v2 + 16);
          _check_object_size(v24, *(unsigned int *)(v2 + 12), 1);
          v125 = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(v125 + 70) & 0x20) != 0 || (v126 = v124, (*(_QWORD *)v125 & 0x4000000) != 0) )
            v126 = v124 & ((__int64)(v124 << 8) >> 8);
          _CF = 0x8000000000LL - v122 >= v126;
          v127 = v123;
          if ( _CF )
          {
            v128 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v130 = *(_QWORD *)(v125 + 8);
            _WriteStatusReg(TTBR1_EL1, v130 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v130);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v128);
            v122 = _arch_copy_to_user(v124 & 0xFF7FFFFFFFFFFFFFLL);
            v127 = v123;
            v131 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v133 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v133 - 4096);
            _WriteStatusReg(TTBR1_EL1, v133);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v131);
          }
          if ( v122 )
          {
LABEL_166:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x1000000000LL,
              1,
              "cam_generic_fence_handle_synx_import",
              1838,
              "copy to user failed hdl: %d size: 0x%x",
              *(_QWORD *)(v2 + 16),
              *(_DWORD *)(v2 + 12));
            v127 = -14;
          }
          v75 = v127;
          v77 = (_QWORD *)v24;
          if ( mem_trace_en == 1 )
            goto LABEL_94;
LABEL_168:
          kvfree(v77);
          result = v75;
          goto LABEL_121;
        }
        v35 = *(_DWORD *)(v34 + 104);
        if ( v35 != 1 )
        {
          HIDWORD(v142) = v32;
          LODWORD(v143) = v35;
          raw_spin_unlock(sync_dev + 4 * v30 + 136);
          util = cam_synx_obj_signal_obj(&v142);
          v24 = v137;
          if ( util )
            goto LABEL_156;
          goto LABEL_59;
        }
        *(_BYTE *)(v34 + 212) = 1;
        *(_DWORD *)(v34 + 204) = v32;
        *(_DWORD *)(v34 + 208) = v33;
        _X8 = (unsigned __int64 *)(v34 + 184);
        __asm { PRFM            #0x11, [X8] }
        do
          v43 = __ldxr(_X8);
        while ( __stxr(v43 | 8, _X8) );
        if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1000000000LL,
            4,
            "cam_sync_synx_associate_obj",
            1742,
            "sync_obj: %s[%d] associated with synx_obj: %d",
            (const char *)v34,
            v30,
            *(_DWORD *)(v34 + 204));
        raw_spin_unlock(sync_dev + 4 * v30 + 136);
        v24 = v137;
      }
      else
      {
        LOBYTE(v140) = 1;
        LODWORD(v139) = *(_DWORD *)(v27 + 80);
        HIDWORD(v139) = v141;
        util = cam_sync_create_util((unsigned int *)(v27 + 72), (const char *)(v27 + 4), 0, (__int64)&v139);
        if ( util )
          goto LABEL_156;
      }
      v36 = cam_synx_obj_register_cb(v27 + 72, v141, cam_sync_synx_obj_cb);
      if ( v36 )
      {
        v88 = v36;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x1000000000LL,
          1,
          "cam_generic_fence_handle_synx_import",
          1816,
          "Failed to register cb for synx_obj: %d sync_obj: %d rc: %d",
          *(_DWORD *)(v27 + 80),
          *(_DWORD *)(v27 + 72),
          v36);
        if ( (unsigned int)(v30 - 2048) <= 0xFFFFF800 )
        {
          cam_sync_deinit_object(*(_QWORD *)(sync_dev + 128), *(unsigned int *)(v27 + 72), 0, 0);
          v24 = v138;
        }
        util = v88;
        *(_DWORD *)(v27 + 84) = v88;
        goto LABEL_157;
      }
LABEL_59:
      if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1000000000LL,
          4,
          "cam_generic_fence_handle_synx_import",
          1830,
          "synx_obj handle = %d imported for dma fence fd: %d sync_obj = %d[%s] num fences [requested: %u processed: %u]",
          *(_DWORD *)(v27 + 80),
          *(_DWORD *)(v27 + 76),
          *(_DWORD *)(v27 + 72),
          (const char *)(v27 + 4),
          *(_DWORD *)(v24 + 4),
          *(_DWORD *)(v24 + 8));
      if ( (unsigned int)++v25 >= *(_DWORD *)(v24 + 4) )
      {
        util = 0;
        goto LABEL_157;
      }
    }
  }
  if ( a1 != 11 )
  {
    if ( a1 == 12 )
    {
      v142 = 0;
      v139 = 0;
      v3 = cam_generic_fence_alloc_validate_input_info_util(a2, &v142);
      v4 = v142;
      v5 = v3;
      if ( !v3 && v142 )
      {
        if ( *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + v142 + 4) )
        {
          v6 = 0;
          v7 = 0;
          v135 = v2;
          do
          {
            v8 = v4 + 32 + 112LL * (int)v7;
            v9 = *(int *)((char *)&dword_8 + v4) + 1;
            *(_DWORD *)(v8 + 84) = 0;
            BYTE4(v139) = 0;
            v10 = *(_DWORD *)(v8 + 80);
            *(int *)((char *)&dword_8 + v4) = v9;
            LODWORD(v139) = v10;
            v11 = ((__int64 (__fastcall *)(__int64 *))cam_synx_obj_release)(&v139);
            if ( v11 )
            {
              v6 = 1;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x1000000000LL,
                1,
                "cam_generic_fence_handle_synx_release",
                1683,
                "Failed to release synx object at index: %d rc: %d num fences [requested: %u processed: %u]",
                v7,
                v11,
                *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + v4 + 4),
                *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + v4 + 8));
              *(_DWORD *)(v8 + 84) = v11;
            }
            else if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x1000000000LL,
                4,
                "cam_generic_fence_handle_synx_release",
                1694,
                "Released synx object @ i: %d handle: %d num fences [requested: %u processed: %u]",
                v7,
                *(_DWORD *)(v8 + 80),
                *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + v4 + 4),
                *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + v4 + 8));
            }
            ++v7;
          }
          while ( v7 < *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + v4 + 4) );
          v2 = v135;
          if ( (v6 & 1) != 0 )
            v64 = -42;
          else
            v64 = v11;
          v65 = *(unsigned int *)(v135 + 12);
          if ( (v65 & 0x80000000) == 0 )
          {
LABEL_83:
            v66 = *(_QWORD *)(v2 + 16);
            _check_object_size(v4, v65, 1);
            v67 = _ReadStatusReg(SP_EL0);
            if ( (*(_BYTE *)(v67 + 70) & 0x20) != 0 || (v68 = v66, (*(_QWORD *)v67 & 0x4000000) != 0) )
              v68 = v66 & ((__int64)(v66 << 8) >> 8);
            _CF = 0x8000000000LL - v65 >= v68;
            v53 = v64;
            if ( _CF )
            {
              v69 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v71 = *(_QWORD *)(v67 + 8);
              _WriteStatusReg(TTBR1_EL1, v71 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v71);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v69);
              v65 = _arch_copy_to_user(v66 & 0xFF7FFFFFFFFFFFFFLL);
              v53 = v64;
              v72 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v74 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v74 - 4096);
              _WriteStatusReg(TTBR1_EL1, v74);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v72);
            }
            if ( !v65 )
              goto LABEL_92;
            goto LABEL_90;
          }
        }
        else
        {
          v64 = 0;
          v65 = *(unsigned int *)(v2 + 12);
          if ( (v65 & 0x80000000) == 0 )
            goto LABEL_83;
        }
        __break(0x800u);
LABEL_90:
        v60 = *(_QWORD *)(v2 + 16);
        v61 = *(unsigned int *)(v2 + 12);
        v62 = "cam_generic_fence_handle_synx_release";
        v63 = 1703;
LABEL_91:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
          3,
          0x1000000000LL,
          1,
          v62,
          v63,
          "copy to user failed hdl: %d size: 0x%x",
          v60,
          v61);
        v53 = -14;
        goto LABEL_92;
      }
      v44 = "cam_generic_fence_handle_synx_release";
      v45 = "Fence input info validation failed rc: %d fence_input_info: %pK";
      v46 = 1666;
      goto LABEL_67;
    }
LABEL_20:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      "cam_generic_fence_process_synx_obj_cmd",
      1920,
      "IOCTL cmd: %u not supported for synx object",
      a1);
LABEL_120:
    result = 4294967274LL;
    goto LABEL_121;
  }
  LODWORD(v139) = 0;
  v142 = 0;
  v13 = cam_generic_fence_alloc_validate_input_info_util(a2, &v142);
  v4 = v142;
  v5 = v13;
  if ( v13 || !v142 )
  {
    v44 = "cam_generic_fence_handle_synx_create";
    v45 = "Fence input info validation failed rc: %d fence_input_info: %pK";
    v46 = 1610;
LABEL_67:
    v47 = v4;
LABEL_119:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, __int64))cam_print_log)(
      3,
      0x1000000000LL,
      1,
      v44,
      v46,
      v45,
      v5,
      v47,
      v134);
    goto LABEL_120;
  }
  if ( !*(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + v142 + 4) )
  {
LABEL_70:
    v48 = 0;
    v49 = *(unsigned int *)(v2 + 12);
    if ( (v49 & 0x80000000) != 0 )
      goto LABEL_104;
    goto LABEL_71;
  }
  v14 = 0;
  while ( 1 )
  {
    v15 = v4 + 32 + 112LL * v14;
    ++*(int *)((char *)&dword_8 + v4);
    v16 = *(_DWORD *)(v15 + 88);
    *(_DWORD *)(v15 + 84) = 0;
    if ( v16 )
    {
      if ( (*(_DWORD *)(v15 + 92) & 1) != 0 )
      {
        v17 = *(unsigned int *)(v15 + 96);
      }
      else
      {
        v17 = 0;
        if ( (debug_mdl & 0x80) != 0 && !debug_priority )
        {
          v18 = (unsigned __int8)debug_mdl & 0x80;
          v19 = 1581;
          v20 = "Requested parameter not set in additional param mask expecting: 0x%x actual: 0x%x";
          v21 = 1;
LABEL_34:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            v18,
            4,
            "cam_generic_fence_config_parse_params",
            v19,
            v20,
            v21);
          v17 = 0;
        }
      }
    }
    else
    {
      v17 = 0;
      if ( (debug_mdl & 0x80) != 0 && !debug_priority )
      {
        v18 = (unsigned __int8)debug_mdl & 0x80;
        v19 = 1574;
        v20 = "No params configured num_valid = %d requested_mask = 0x%x";
        v21 = 0;
        goto LABEL_34;
      }
    }
    v22 = cam_synx_obj_create(v15 + 4, v17, v15 + 80, &v139);
    if ( v22 )
      break;
    if ( (debug_mdl & 0x1000000000LL) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000000000LL,
        4,
        "cam_generic_fence_handle_synx_create",
        1638,
        "Created synx fence @ i: %d synx_obj: %d[%s] num fences [requested: %u processed: %u] ",
        v14,
        *(_DWORD *)(v15 + 80),
        (const char *)(v15 + 4),
        *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + v4 + 4),
        *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + v4 + 8));
    if ( (unsigned int)++v14 >= *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + v4 + 4) )
      goto LABEL_70;
  }
  v48 = v22;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x1000000000LL,
    1,
    "cam_generic_fence_handle_synx_create",
    1629,
    "Failed to create synx fence at index: %d rc: %d num fences [requested: %u processed: %u]",
    v14,
    v22,
    *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + v4 + 4),
    *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + v4 + 8));
  *(_DWORD *)(v15 + 84) = v48;
  v49 = *(unsigned int *)(v2 + 12);
  if ( (v49 & 0x80000000) != 0 )
  {
LABEL_104:
    __break(0x800u);
    goto LABEL_78;
  }
LABEL_71:
  v50 = *(_QWORD *)(v2 + 16);
  _check_object_size(v4, v49, 1);
  v51 = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(v51 + 70) & 0x20) != 0 || (v52 = v50, (*(_QWORD *)v51 & 0x4000000) != 0) )
    v52 = v50 & ((__int64)(v50 << 8) >> 8);
  _CF = 0x8000000000LL - v49 >= v52;
  v53 = v48;
  if ( _CF )
  {
    v54 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v56 = *(_QWORD *)(v51 + 8);
    _WriteStatusReg(TTBR1_EL1, v56 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v56);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v54);
    v49 = _arch_copy_to_user(v50 & 0xFF7FFFFFFFFFFFFFLL);
    v53 = v48;
    v57 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v59 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v59 - 4096);
    _WriteStatusReg(TTBR1_EL1, v59);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v57);
  }
  if ( v49 )
  {
LABEL_78:
    v60 = *(_QWORD *)(v2 + 16);
    v61 = *(unsigned int *)(v2 + 12);
    v62 = "cam_generic_fence_handle_synx_create";
    v63 = 1645;
    goto LABEL_91;
  }
LABEL_92:
  v75 = v53;
  v76 = (unsigned __int8)mem_trace_en;
LABEL_93:
  v77 = (_QWORD *)v4;
  if ( v76 != 1 )
    goto LABEL_168;
LABEL_94:
  cam_mem_trace_free(v77, 0);
  result = v75;
LABEL_121:
  _ReadStatusReg(SP_EL0);
  return result;
}
