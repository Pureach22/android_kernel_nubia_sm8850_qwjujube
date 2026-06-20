__int64 __fastcall cam_generic_fence_process_dma_fence_cmd(int a1, __int64 a2)
{
  unsigned int v3; // w0
  _QWORD *v4; // x20
  __int64 v5; // x6
  char v6; // w23
  unsigned int v7; // w21
  __int64 v8; // x28
  int v9; // w8
  int v10; // w9
  int v11; // w25
  int v12; // w7
  __int64 result; // x0
  unsigned int v14; // w0
  int v15; // w21
  __int64 v16; // x23
  int v17; // w0
  unsigned int v18; // w0
  int v19; // w26
  __int64 v20; // x25
  __int64 v21; // x0
  unsigned __int64 fence_from_fd; // x0
  int v23; // w8
  int util; // w0
  int v25; // w0
  const char *v26; // x3
  __int64 v27; // x4
  int v28; // w22
  __int64 v29; // x21
  unsigned __int64 v30; // x23
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x9
  int v34; // w9
  unsigned __int64 v35; // x9
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8
  unsigned __int64 v43; // x10
  __int64 v44; // x6
  __int64 v45; // x7
  const char *v46; // x3
  __int64 v47; // x4
  int v48; // w22
  __int64 v49; // x21
  unsigned __int64 v50; // x23
  unsigned __int64 v51; // x8
  unsigned __int64 v52; // x9
  unsigned __int64 v53; // x9
  unsigned __int64 v55; // x8
  unsigned __int64 v56; // x8
  unsigned __int64 v58; // x10
  int v59; // w22
  __int64 v60; // x21
  unsigned __int64 v61; // x23
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v63; // x9
  unsigned __int64 v64; // x9
  unsigned __int64 v66; // x8
  unsigned __int64 v67; // x8
  unsigned __int64 v69; // x10
  unsigned int v70; // w19
  _QWORD *v71; // [xsp+18h] [xbp-38h] BYREF
  unsigned int v72; // [xsp+24h] [xbp-2Ch] BYREF
  _QWORD *v73; // [xsp+28h] [xbp-28h] BYREF
  __int64 v74; // [xsp+30h] [xbp-20h]
  __int64 v75; // [xsp+38h] [xbp-18h]
  __int64 v76; // [xsp+40h] [xbp-10h]
  __int64 v77; // [xsp+48h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 > 12 )
  {
    if ( a1 != 13 )
    {
      if ( a1 == 14 )
      {
        v12 = *(_DWORD *)(a2 + 12);
        v75 = 0;
        v76 = 0;
        v73 = nullptr;
        v74 = 0;
        if ( v12 == 32 )
        {
          if ( inline_copy_from_user_2((__int64)&v73, *(_QWORD *)(a2 + 16), 0x20u) )
            result = 4294967282LL;
          else
            result = cam_dma_fence_signal_fd(&v73);
          goto LABEL_47;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          0x400000000LL,
          1,
          "cam_generic_fence_handle_dma_signal",
          1403,
          "Size is invalid expected: 0x%llx actual: 0x%llx",
          32);
LABEL_46:
        result = 4294967274LL;
        goto LABEL_47;
      }
LABEL_19:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000000LL,
        1,
        "cam_generic_fence_process_dma_fence_cmd",
        1434,
        "IOCTL cmd: %u not supported for dma fence",
        a1);
      goto LABEL_46;
    }
    v72 = 0;
    LODWORD(v74) = 0;
    v73 = nullptr;
    v71 = nullptr;
    v18 = cam_generic_fence_alloc_validate_input_info_util(a2, &v71);
    v4 = v71;
    v5 = v18;
    if ( !v18 && v71 )
    {
      if ( *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v71 + 4) )
      {
        v19 = 0;
        while ( 1 )
        {
          v20 = (__int64)&v4[14 * v19 + 4];
          v21 = *(unsigned int *)(v20 + 76);
          ++*(int *)((char *)&dword_8 + (_QWORD)v4);
          *(_DWORD *)(v20 + 84) = 0;
          fence_from_fd = cam_dma_fence_get_fence_from_fd(v21, &v72);
          if ( !fence_from_fd || fence_from_fd >= 0xFFFFFFFFFFFFF001LL )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x400000000LL,
              1,
              "cam_generic_fence_handle_dma_import",
              1343,
              "Invalid dma fence for fd: %d",
              *(_DWORD *)(v20 + 76));
            v59 = 0;
            *(_DWORD *)(v20 + 84) = -22;
            goto LABEL_78;
          }
          LODWORD(v73) = v72;
          v23 = *(_DWORD *)(v20 + 76);
          LOBYTE(v74) = 1;
          HIDWORD(v73) = v23;
          util = cam_sync_create_util((unsigned int *)(v20 + 72), (const char *)(v20 + 4), (__int64)&v73, 0);
          if ( util )
          {
            *(_DWORD *)(v20 + 84) = util;
            v59 = util;
            cam_dma_fence_get_put_ref(0, v72);
            goto LABEL_78;
          }
          v25 = cam_dma_fence_register_cb(v20 + 72, &v72, cam_sync_dma_fence_cb);
          if ( v25 )
            break;
          if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x400000000LL,
              4,
              "cam_generic_fence_handle_dma_import",
              1380,
              "dma fence fd = %d imported for sync_obj = %d[%s] num fences [requested: %u processed: %u]",
              *(_DWORD *)(v20 + 76),
              *(_DWORD *)(v20 + 72),
              (const char *)(v20 + 4),
              *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4),
              *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 8));
          if ( (unsigned int)++v19 >= *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4) )
            goto LABEL_69;
        }
        v59 = v25;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000000LL,
          1,
          "cam_generic_fence_handle_dma_import",
          1369,
          "Failed to register cb for dma fence fd: %d sync_obj: %d rc: %d",
          *(_DWORD *)(v20 + 76),
          *(_DWORD *)(v20 + 72),
          v25);
        cam_sync_deinit_object(*(_QWORD *)(sync_dev + 128), *(unsigned int *)(v20 + 72), 0, 0);
        *(_DWORD *)(v20 + 84) = v59;
        v4 = v71;
      }
      else
      {
LABEL_69:
        v59 = 0;
      }
LABEL_78:
      v60 = *(unsigned int *)(a2 + 12);
      if ( (v60 & 0x80000000) != 0 )
      {
        __break(0x800u);
      }
      else
      {
        v61 = *(_QWORD *)(a2 + 16);
        _check_object_size(v4, *(unsigned int *)(a2 + 12), 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v63 = v61, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v63 = v61 & ((__int64)(v61 << 8) >> 8);
        _CF = 0x8000000000LL - v60 >= v63;
        v34 = v59;
        if ( _CF )
        {
          v64 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v66 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v66 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v66);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v64);
          v60 = _arch_copy_to_user(v61 & 0xFF7FFFFFFFFFFFFFLL);
          v34 = v59;
          v67 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v69 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v69 - 4096);
          _WriteStatusReg(TTBR1_EL1, v69);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v67);
        }
        if ( !v60 )
          goto LABEL_88;
      }
      v44 = *(_QWORD *)(a2 + 16);
      v45 = *(unsigned int *)(a2 + 12);
      v46 = "cam_generic_fence_handle_dma_import";
      v47 = 1388;
      goto LABEL_87;
    }
    v26 = "cam_generic_fence_handle_dma_import";
    v27 = 1329;
LABEL_44:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD *))cam_print_log)(
      3,
      0x400000000LL,
      1,
      v26,
      v27,
      "Fence input info validation failed rc: %d fence_input_info: %pK",
      v5,
      v4);
    goto LABEL_46;
  }
  if ( a1 != 11 )
  {
    if ( a1 == 12 )
    {
      v73 = nullptr;
      v71 = nullptr;
      v3 = cam_generic_fence_alloc_validate_input_info_util(a2, &v71);
      v4 = v71;
      v5 = v3;
      if ( !v3 && v71 )
      {
        if ( *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v71 + 4) )
        {
          v6 = 0;
          v7 = 0;
          do
          {
            v8 = (__int64)&v4[14 * (int)v7 + 4];
            v9 = *(int *)((char *)&dword_8 + (_QWORD)v4) + 1;
            *(_DWORD *)(v8 + 84) = 0;
            BYTE4(v73) = 0;
            v10 = *(_DWORD *)(v8 + 76);
            *(int *)((char *)&dword_8 + (_QWORD)v4) = v9;
            LODWORD(v73) = v10;
            v11 = cam_dma_fence_release(&v73);
            if ( v11 )
            {
              v6 = 1;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x400000000LL,
                1,
                "cam_generic_fence_handle_dma_release",
                1288,
                "Failed to destroy dma fence at index: %d fd: %d rc: %d num fences [requested: %u processed: %u]",
                v7,
                *(_DWORD *)(v8 + 76),
                v11,
                *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4),
                *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 8));
              *(_DWORD *)(v8 + 84) = v11;
            }
            else if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x400000000LL,
                4,
                "cam_generic_fence_handle_dma_release",
                1299,
                "Released dma_fence @ i: %d fd: %d num fences [requested: %u processed: %u]",
                v7,
                *(_DWORD *)(v8 + 76),
                *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4),
                *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 8));
            }
            ++v7;
          }
          while ( v7 < *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4) );
          if ( (v6 & 1) != 0 )
            v48 = -42;
          else
            v48 = v11;
          v49 = *(unsigned int *)(a2 + 12);
          if ( (v49 & 0x80000000) == 0 )
          {
LABEL_61:
            v50 = *(_QWORD *)(a2 + 16);
            _check_object_size(v4, v49, 1);
            v51 = _ReadStatusReg(SP_EL0);
            if ( (*(_BYTE *)(v51 + 70) & 0x20) != 0 || (v52 = v50, (*(_QWORD *)v51 & 0x4000000) != 0) )
              v52 = v50 & ((__int64)(v50 << 8) >> 8);
            _CF = 0x8000000000LL - v49 >= v52;
            v34 = v48;
            if ( _CF )
            {
              v53 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v55 = *(_QWORD *)(v51 + 8);
              _WriteStatusReg(TTBR1_EL1, v55 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v55);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v53);
              v49 = _arch_copy_to_user(v50 & 0xFF7FFFFFFFFFFFFFLL);
              v34 = v48;
              v56 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v58 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v58 - 4096);
              _WriteStatusReg(TTBR1_EL1, v58);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v56);
            }
            if ( !v49 )
              goto LABEL_88;
            goto LABEL_68;
          }
        }
        else
        {
          v48 = 0;
          v49 = *(unsigned int *)(a2 + 12);
          if ( (v49 & 0x80000000) == 0 )
            goto LABEL_61;
        }
        __break(0x800u);
LABEL_68:
        v44 = *(_QWORD *)(a2 + 16);
        v45 = *(unsigned int *)(a2 + 12);
        v46 = "cam_generic_fence_handle_dma_release";
        v47 = 1308;
        goto LABEL_87;
      }
      v26 = "cam_generic_fence_handle_dma_release";
      v27 = 1271;
      goto LABEL_44;
    }
    goto LABEL_19;
  }
  LODWORD(v71) = 0;
  v73 = nullptr;
  v14 = cam_generic_fence_alloc_validate_input_info_util(a2, &v73);
  v4 = v73;
  v5 = v14;
  if ( v14 || !v73 )
  {
    v26 = "cam_generic_fence_handle_dma_create";
    v27 = 1219;
    goto LABEL_44;
  }
  if ( *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v73 + 4) )
  {
    v15 = 0;
    while ( 1 )
    {
      v16 = (__int64)&v4[14 * v15 + 4];
      ++*(int *)((char *)&dword_8 + (_QWORD)v4);
      *(_DWORD *)(v16 + 84) = 0;
      v17 = cam_dma_fence_create_fd(v16 + 76, &v71, v16 + 4);
      if ( v17 )
        break;
      if ( (debug_mdl & 0x400000000LL) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x400000000LL,
          4,
          "cam_generic_fence_handle_dma_create",
          1243,
          "Created dma_fence @ i: %d fence fd: %d[%s] num fences [requested: %u processed: %u] ",
          v15,
          *(_DWORD *)(v16 + 76),
          (const char *)(v16 + 4),
          *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4),
          *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 8));
      if ( (unsigned int)++v15 >= *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4) )
        goto LABEL_48;
    }
    v28 = v17;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000000LL,
      1,
      "cam_generic_fence_handle_dma_create",
      1234,
      "Failed to create dma fence at index: %d rc: %d num fences [requested: %u processed: %u]",
      v15,
      v17,
      *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 4),
      *(_DWORD *)((char *)&_ksymtab_cam_cci_dump_registers + (_QWORD)v4 + 8));
    *(_DWORD *)(v16 + 84) = v28;
    v29 = *(unsigned int *)(a2 + 12);
    if ( (v29 & 0x80000000) != 0 )
      goto LABEL_74;
LABEL_49:
    v30 = *(_QWORD *)(a2 + 16);
    _check_object_size(v4, v29, 1);
    v31 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v31 + 70) & 0x20) != 0 || (v32 = v30, (*(_QWORD *)v31 & 0x4000000) != 0) )
      v32 = v30 & ((__int64)(v30 << 8) >> 8);
    _CF = 0x8000000000LL - v29 >= v32;
    v34 = v28;
    if ( _CF )
    {
      v35 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v40 = *(_QWORD *)(v31 + 8);
      _WriteStatusReg(TTBR1_EL1, v40 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v40);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v35);
      v29 = _arch_copy_to_user(v30 & 0xFF7FFFFFFFFFFFFFLL);
      v34 = v28;
      v41 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v43 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v43 - 4096);
      _WriteStatusReg(TTBR1_EL1, v43);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v41);
    }
    if ( !v29 )
      goto LABEL_88;
    goto LABEL_56;
  }
LABEL_48:
  v28 = 0;
  v29 = *(unsigned int *)(a2 + 12);
  if ( (v29 & 0x80000000) == 0 )
    goto LABEL_49;
LABEL_74:
  __break(0x800u);
LABEL_56:
  v44 = *(_QWORD *)(a2 + 16);
  v45 = *(unsigned int *)(a2 + 12);
  v46 = "cam_generic_fence_handle_dma_create";
  v47 = 1250;
LABEL_87:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
    3,
    0x400000000LL,
    1,
    v46,
    v47,
    "copy to user failed hdl: %d size: 0x%x",
    v44,
    v45);
  v34 = -14;
LABEL_88:
  v70 = v34;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v4, 0);
  else
    kvfree(v4);
  result = v70;
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
