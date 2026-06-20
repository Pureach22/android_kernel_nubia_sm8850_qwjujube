__int64 __fastcall cam_generic_fence_process_sync_obj_cmd(int a1, __int64 a2)
{
  __int64 v2; // x23
  unsigned int v3; // w0
  _QWORD *v4; // x21
  __int64 v5; // x6
  unsigned int v6; // w20
  __int64 v7; // x23
  __int64 v8; // x8
  __int64 v9; // x26
  int fd; // w0
  int v11; // w8
  __int64 *v12; // x3
  __int64 *v13; // x2
  __int64 v14; // x1
  __int64 v15; // x1
  __int64 v16; // x4
  const char *v17; // x5
  __int64 v18; // x6
  __int64 fence_from_fd; // x0
  int v20; // w0
  int v21; // w0
  int util; // w0
  int v23; // w0
  int v24; // w0
  unsigned int v25; // w0
  _QWORD *v26; // x20
  char v27; // w27
  unsigned int v28; // w21
  __int64 v29; // x6
  __int64 v30; // x7
  __int64 v31; // x4
  const char *v32; // x5
  __int64 v33; // x19
  int v34; // w8
  __int64 v35; // x0
  unsigned int v36; // w23
  int v37; // w8
  int v38; // w9
  __int64 v39; // x4
  const char *v40; // x5
  const char *v41; // x3
  __int64 v42; // x4
  _QWORD *v43; // x7
  __int64 result; // x0
  int v45; // w19
  __int64 v46; // x21
  unsigned __int64 v47; // x22
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v49; // x9
  int v51; // w9
  unsigned __int64 v52; // x9
  unsigned __int64 v57; // x8
  unsigned __int64 v58; // x8
  unsigned __int64 v60; // x10
  __int64 v61; // x6
  __int64 v62; // x7
  const char *v63; // x3
  __int64 v64; // x4
  int v65; // w19
  int v66; // w8
  int v67; // w21
  __int64 v68; // x6
  __int64 v69; // x7
  const char *v70; // x5
  int v71; // w21
  __int64 v72; // x4
  int v73; // w8
  int v74; // w21
  int v75; // w8
  __int64 v76; // x21
  unsigned __int64 v77; // x22
  unsigned __int64 v78; // x8
  unsigned __int64 v79; // x9
  unsigned __int64 v80; // x9
  unsigned __int64 v82; // x8
  unsigned __int64 v83; // x8
  unsigned __int64 v85; // x10
  unsigned int v86; // w19
  __int64 v87; // [xsp+28h] [xbp-58h]
  __int64 v88; // [xsp+28h] [xbp-58h]
  char v89; // [xsp+30h] [xbp-50h]
  int v90; // [xsp+30h] [xbp-50h]
  __int64 v91; // [xsp+38h] [xbp-48h] BYREF
  __int64 v92; // [xsp+40h] [xbp-40h] BYREF
  __int64 v93; // [xsp+48h] [xbp-38h] BYREF
  int v94; // [xsp+50h] [xbp-30h]
  _QWORD *v95; // [xsp+58h] [xbp-28h] BYREF
  __int64 v96; // [xsp+60h] [xbp-20h] BYREF
  __int64 v97; // [xsp+68h] [xbp-18h] BYREF
  int v98; // [xsp+70h] [xbp-10h]
  __int64 v99; // [xsp+78h] [xbp-8h]

  v2 = a2;
  v99 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == 12 )
  {
    v98 = 0;
    v96 = 0;
    v97 = 0;
    v95 = nullptr;
    v94 = 0;
    v93 = 0;
    v92 = 0;
    v25 = cam_generic_fence_alloc_validate_input_info_util(a2, &v95);
    v26 = v95;
    v5 = v25;
    if ( v25 || !v95 )
    {
      v41 = "cam_generic_fence_handle_sync_release";
      v42 = 2152;
      v43 = v95;
      goto LABEL_62;
    }
    if ( !*(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v95 + 4) )
    {
      v45 = 0;
      v46 = *(unsigned int *)(v2 + 12);
      if ( (v46 & 0x80000000) != 0 )
        goto LABEL_79;
LABEL_69:
      v47 = *(_QWORD *)(v2 + 16);
      _check_object_size(v26, v46, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v49 = v47, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v49 = v47 & ((__int64)(v47 << 8) >> 8);
      _CF = 0x8000000000LL - v46 >= v49;
      v51 = v45;
      if ( _CF )
      {
        v52 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v57 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v57 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v57);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v52);
        v46 = _arch_copy_to_user(v47 & 0xFF7FFFFFFFFFFFFFLL);
        v51 = v45;
        v58 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v60 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v60 - 4096);
        _WriteStatusReg(TTBR1_EL1, v60);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v58);
      }
      if ( !v46 )
        goto LABEL_104;
LABEL_76:
      v61 = *(_QWORD *)(v2 + 16);
      v62 = *(unsigned int *)(v2 + 12);
      v63 = "cam_generic_fence_handle_sync_release";
      v64 = 2245;
      goto LABEL_103;
    }
    v27 = 0;
    v28 = 0;
    v88 = v2;
    while ( 1 )
    {
      v33 = (__int64)&v26[14 * (int)v28 + 4];
      ++*(int *)((char *)&dword_8 + (_QWORD)v26);
      *(_DWORD *)(v33 + 84) = 0;
      LOBYTE(v98) = 0;
      v34 = *(_DWORD *)(v33 + 76);
      LOBYTE(v94) = 0;
      v35 = *(_QWORD *)(sync_dev + 128);
      HIDWORD(v97) = v34;
      LODWORD(v93) = *(_DWORD *)(v33 + 80);
      v36 = cam_sync_deinit_object(v35, *(unsigned int *)(v33 + 72), &v97, &v93);
      if ( v36 )
      {
        *(_DWORD *)(v33 + 84) = v36;
        v27 = 1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          128,
          1,
          "cam_generic_fence_handle_sync_release",
          2174,
          "Failed to release sync obj at index: %d rc: %d num_fences [requested: %u processed: %u]",
          v28,
          v36,
          *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v26 + 4),
          *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v26 + 8));
      }
      v90 = *(_DWORD *)(v33 + 68);
      if ( (v90 & 4) != 0 )
      {
        if ( (v98 & 1) == 0 )
        {
          v30 = *(unsigned int *)(v33 + 72);
          v29 = *(unsigned int *)(v33 + 76);
          v31 = 2182;
          v32 = "Failed to release dma fence fd: %d with sync_obj: %d, not created together";
          goto LABEL_42;
        }
        BYTE4(v96) = 1;
        LODWORD(v96) = v97;
        v36 = cam_dma_fence_release(&v96);
        if ( v36 )
        {
          v37 = *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v26 + 4);
          v38 = *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v26 + 8);
          v39 = 2195;
          v40 = "Failed to destroy dma fence at index: %d rc: %d num fences [requested: %u processed: %u]";
LABEL_57:
          v27 = 1;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int, int))cam_print_log)(
            3,
            128,
            1,
            "cam_generic_fence_handle_sync_release",
            v39,
            v40,
            v28,
            v36,
            v37,
            v38);
          *(_DWORD *)(v33 + 84) = v36;
          goto LABEL_43;
        }
      }
      if ( (v90 & 8) == 0 )
        goto LABEL_48;
      if ( (v94 & 1) != 0 )
      {
        BYTE4(v92) = 1;
        LODWORD(v92) = HIDWORD(v93);
        v36 = ((__int64 (__fastcall *)(__int64 *))cam_synx_obj_release)(&v92);
        if ( !v36 )
        {
LABEL_48:
          if ( (debug_mdl & 0x80) != 0 && !debug_priority )
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              (unsigned __int8)debug_mdl & 0x80,
              4,
              "cam_generic_fence_handle_sync_release",
              2235,
              "Released sync_obj = %d[%s] with fence_sel_mask: 0x%x dma_fence_fd: %d synx_obj: %d num fences [requested: "
              "%u processed: %u]",
              *(_DWORD *)(v33 + 72),
              (const char *)(v33 + 4),
              *(_DWORD *)(v33 + 68),
              *(_DWORD *)(v33 + 76),
              *(_DWORD *)(v33 + 80),
              *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v26 + 4),
              *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v26 + 8));
          goto LABEL_43;
        }
        v37 = *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v26 + 4);
        v38 = *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v26 + 8);
        v39 = 2222;
        v40 = "Failed to destroy synx_obj at index: %d rc: %d num fences [requested: %u processed: %u]";
        goto LABEL_57;
      }
      v29 = *(unsigned int *)(v33 + 80);
      v30 = *(unsigned int *)(v33 + 72);
      v31 = 2208;
      v32 = "Failed to release synx_obj: %d with sync_obj: %d, not created together";
LABEL_42:
      v27 = 1;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        128,
        1,
        "cam_generic_fence_handle_sync_release",
        v31,
        v32,
        v29,
        v30);
      *(_DWORD *)(v33 + 84) = -1;
LABEL_43:
      if ( ++v28 >= *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v26 + 4) )
      {
        if ( (v27 & 1) != 0 )
          v45 = -42;
        else
          v45 = v36;
        v2 = v88;
        v46 = *(unsigned int *)(v88 + 12);
        if ( (v46 & 0x80000000) == 0 )
          goto LABEL_69;
LABEL_79:
        __break(0x800u);
        goto LABEL_76;
      }
    }
  }
  if ( a1 != 11 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_generic_fence_process_sync_obj_cmd",
      2266,
      "IOCTL cmd: %u not supported for sync object",
      a1);
LABEL_63:
    result = 4294967274LL;
    goto LABEL_64;
  }
  v91 = 0;
  v96 = 0;
  v97 = 0;
  v98 = 0;
  v95 = nullptr;
  v94 = 0;
  v93 = 0;
  v92 = 0;
  v3 = cam_generic_fence_alloc_validate_input_info_util(a2, &v95);
  v4 = v95;
  v5 = v3;
  if ( v3 || !v95 )
  {
    v41 = "cam_generic_fence_handle_sync_create";
    v42 = 1951;
    v43 = v95;
LABEL_62:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD *))cam_print_log)(
      3,
      128,
      1,
      v41,
      v42,
      "Fence input info validation failed rc: %d fence_input_info: %pK",
      v5,
      v43);
    goto LABEL_63;
  }
  if ( !*(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v95 + 4) )
  {
    v65 = 0;
    goto LABEL_94;
  }
  v6 = 0;
  v87 = v2;
  while ( 1 )
  {
    v7 = (__int64)&v4[14 * (int)v6 + 4];
    ++*(int *)((char *)&dword_8 + (_QWORD)v4);
    v8 = *(unsigned int *)(v7 + 68);
    *(_DWORD *)(v7 + 84) = 0;
    v89 = v8;
    v9 = v8;
    if ( (v8 & 4) != 0 )
    {
      fd = cam_dma_fence_create_fd(v7 + 76, (char *)&v91 + 4, v7 + 4);
      if ( fd )
      {
        v66 = *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4);
        v67 = fd;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          128,
          1,
          "cam_generic_fence_handle_sync_create",
          1971,
          "Failed to create dma fence at index: %d rc: %d num_fences: %u",
          v6,
          fd,
          v66);
        v65 = v67;
        *(_DWORD *)(v7 + 84) = v67;
        goto LABEL_93;
      }
      LODWORD(v97) = HIDWORD(v91);
      v11 = *(_DWORD *)(v7 + 76);
      LOBYTE(v98) = 1;
      HIDWORD(v97) = v11;
    }
    if ( (v89 & 8) == 0 )
    {
      v12 = nullptr;
      v13 = (__int64 *)((unsigned __int64)&v97 & (v9 << 61 >> 63));
      goto LABEL_29;
    }
    if ( (v9 & 4) == 0 )
    {
      if ( *(_DWORD *)(v7 + 88) )
      {
        if ( (*(_DWORD *)(v7 + 92) & 1) != 0 )
        {
          v14 = *(unsigned int *)(v7 + 96);
          goto LABEL_26;
        }
        v14 = 0;
        if ( (debug_mdl & 0x80) == 0 || debug_priority )
          goto LABEL_26;
        v15 = (unsigned __int8)debug_mdl & 0x80;
        v16 = 1581;
        v17 = "Requested parameter not set in additional param mask expecting: 0x%x actual: 0x%x";
        v18 = 1;
      }
      else
      {
        v14 = 0;
        if ( (debug_mdl & 0x80) == 0 || debug_priority )
          goto LABEL_26;
        v15 = (unsigned __int8)debug_mdl & 0x80;
        v16 = 1574;
        v17 = "No params configured num_valid = %d requested_mask = 0x%x";
        v18 = 0;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v15,
        4,
        "cam_generic_fence_config_parse_params",
        v16,
        v17,
        v18);
      v14 = 0;
LABEL_26:
      v21 = cam_synx_obj_create(v7 + 4, v14, v7 + 80, &v91);
      if ( !v21 )
      {
        v13 = nullptr;
        goto LABEL_28;
      }
      v73 = *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4);
      v74 = v21;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        128,
        1,
        "cam_generic_fence_handle_sync_create",
        2002,
        "Failed to create/import synx obj at index: %d rc: %d num_fences: %u",
        v6,
        v21,
        v73);
LABEL_92:
      v65 = v74;
      goto LABEL_93;
    }
    fence_from_fd = cam_dma_fence_get_fence_from_fd(HIDWORD(v97), (char *)&v91 + 4);
    v20 = cam_synx_obj_import_dma_fence(v7 + 4, *(unsigned int *)(v7 + 96), fence_from_fd, v7 + 80, &v91);
    if ( v20 )
    {
      v75 = *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4);
      v74 = v20;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        128,
        1,
        "cam_generic_fence_handle_sync_create",
        2002,
        "Failed to create/import synx obj at index: %d rc: %d num_fences: %u",
        v6,
        v20,
        v75);
      BYTE4(v96) = 1;
      LODWORD(v96) = HIDWORD(v91);
      cam_dma_fence_release(&v96);
      goto LABEL_92;
    }
    v13 = &v97;
LABEL_28:
    LOBYTE(v94) = 1;
    v12 = &v93;
    LODWORD(v93) = *(_DWORD *)(v7 + 80);
    HIDWORD(v93) = v91;
LABEL_29:
    util = cam_sync_create_util((unsigned int *)(v7 + 72), (const char *)(v7 + 4), (__int64)v13, (__int64)v12);
    if ( util )
    {
      *(_DWORD *)(v7 + 84) = util;
      v65 = util;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        128,
        1,
        "cam_generic_fence_handle_sync_create",
        2028,
        "Failed to create sync obj at index: %d rc: %d num_fences: %u",
        v6);
      if ( (v9 & 4) == 0 )
        goto LABEL_82;
LABEL_81:
      BYTE4(v96) = 1;
      LODWORD(v96) = HIDWORD(v91);
      cam_dma_fence_release(&v96);
      goto LABEL_82;
    }
    if ( (v89 & 4) != 0 )
    {
      v23 = cam_dma_fence_register_cb(v7 + 72, (char *)&v91 + 4, cam_sync_dma_fence_cb);
      if ( v23 )
      {
        v69 = *(unsigned int *)(v7 + 72);
        v68 = *(unsigned int *)(v7 + 76);
        v70 = "Failed to register cb for dma fence fd: %d sync_obj: %d rc: %d";
        v71 = v23;
        v72 = 2055;
        goto LABEL_88;
      }
    }
    if ( (v89 & 8) != 0 )
    {
      v24 = cam_synx_obj_register_cb(v7 + 72, (unsigned int)v91, cam_sync_synx_obj_cb);
      if ( v24 )
        break;
    }
    if ( (debug_mdl & 0x80) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        (unsigned __int8)debug_mdl & 0x80,
        4,
        "cam_generic_fence_handle_sync_create",
        2118,
        "Created sync_obj = %d[%s] with fence_sel_mask: 0x%x dma_fence_fd: %d num fences [requested: %u processed: %u]",
        *(_DWORD *)(v7 + 72),
        (const char *)(v7 + 4),
        *(_DWORD *)(v7 + 68),
        *(_DWORD *)(v7 + 76),
        *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4),
        *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 8));
    if ( ++v6 >= *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4) )
    {
      v65 = 0;
LABEL_93:
      v2 = v87;
      goto LABEL_94;
    }
  }
  v68 = *(unsigned int *)(v7 + 80);
  v69 = *(unsigned int *)(v7 + 72);
  v70 = "Failed to register cb for synx_obj: %d sync_obj: %d rc: %d";
  v71 = v24;
  v72 = 2088;
LABEL_88:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
    3,
    128,
    1,
    "cam_generic_fence_handle_sync_create",
    v72,
    v70,
    v68,
    v69,
    v71);
  *(_DWORD *)(v7 + 84) = v71;
  v65 = v71;
  cam_sync_deinit_object(*(_QWORD *)(sync_dev + 128), *(unsigned int *)(v7 + 72), 0, 0);
  if ( (v9 & 4) != 0 )
    goto LABEL_81;
LABEL_82:
  v2 = v87;
  if ( (v89 & 8) != 0 )
  {
    BYTE4(v92) = 1;
    LODWORD(v92) = v91;
    ((void (__fastcall *)(__int64 *))cam_synx_obj_release)(&v92);
  }
LABEL_94:
  v76 = *(unsigned int *)(v2 + 12);
  v26 = v95;
  if ( (v76 & 0x80000000) != 0 )
  {
    __break(0x800u);
    goto LABEL_102;
  }
  v77 = *(_QWORD *)(v2 + 16);
  _check_object_size(v95, *(unsigned int *)(v2 + 12), 1);
  v78 = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(v78 + 70) & 0x20) != 0 || (v79 = v77, (*(_QWORD *)v78 & 0x4000000) != 0) )
    v79 = v77 & ((__int64)(v77 << 8) >> 8);
  _CF = 0x8000000000LL - v76 >= v79;
  v51 = v65;
  if ( _CF )
  {
    v80 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v82 = *(_QWORD *)(v78 + 8);
    _WriteStatusReg(TTBR1_EL1, v82 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v82);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v80);
    v76 = _arch_copy_to_user(v77 & 0xFF7FFFFFFFFFFFFFLL);
    v51 = v65;
    v83 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v85 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v85 - 4096);
    _WriteStatusReg(TTBR1_EL1, v85);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v83);
  }
  if ( v76 )
  {
LABEL_102:
    v61 = *(_QWORD *)(v2 + 16);
    v62 = *(unsigned int *)(v2 + 12);
    v63 = "cam_generic_fence_handle_sync_create";
    v64 = 2126;
LABEL_103:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      128,
      1,
      v63,
      v64,
      "copy to user failed hdl: %d size: 0x%x",
      v61,
      v62);
    v51 = -14;
  }
LABEL_104:
  v86 = v51;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v26, 0);
  else
    kvfree(v26);
  result = v86;
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return result;
}
