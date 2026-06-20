__int64 __fastcall cam_jpeg_mgr_acquire_hw(_BYTE *a1, _QWORD *a2)
{
  __int64 v2; // x20
  __int64 v3; // x22
  __int64 v4; // x23
  char *v5; // x24
  _BYTE *v6; // x25
  unsigned int v9; // w6
  __int64 result; // x0
  unsigned __int64 StatusReg; // x26
  __int64 v12; // x8
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x9
  unsigned __int64 v20; // x10
  size_t v21; // x2
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x9
  unsigned int unique_tbl; // w0
  unsigned int v26; // w21
  __int64 v27; // x0
  _QWORD *v28; // x26
  __int64 v29; // x9
  __int64 v30; // x10
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x8
  char *v34; // x10
  int v35; // w9
  char *v36; // x22
  char *v37; // x9
  int v38; // w8
  __int64 v39; // x9
  __int64 v40; // x8
  int v41; // w0
  _QWORD *v42; // x0
  char *v43; // x22
  int v44; // w10
  int v45; // w9
  int v46; // w6
  __int64 v47; // x22
  __int64 v48; // x27
  __int64 v49; // [xsp+0h] [xbp-140h] BYREF
  __int64 v50; // [xsp+8h] [xbp-138h]
  __int64 v51; // [xsp+10h] [xbp-130h]
  __int64 v52; // [xsp+18h] [xbp-128h]
  __int64 v53; // [xsp+20h] [xbp-120h]
  _QWORD s[35]; // [xsp+28h] [xbp-118h] BYREF

  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v49 = 0;
  memset(s, 0, 0x108u);
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_acquire_hw",
      1449,
      "Invalid params: %pK %pK",
      a1,
      a2);
    result = 4294967274LL;
    goto LABEL_59;
  }
  v9 = *((_DWORD *)a2 + 8);
  if ( v9 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_acquire_hw",
      1456,
      "number of resources are wrong: %u",
      v9);
    result = 4294967274LL;
    goto LABEL_59;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  v12 = a2[5];
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v13 = a2[5], (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v13 = v12 & (v12 << 8 >> 8);
  if ( v13 > 0x7FFFFFFFD8LL )
  {
    v21 = 40;
    goto LABEL_16;
  }
  v14 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v20 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v20);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v14);
  v21 = _arch_copy_from_user(&v49, v12 & 0xFF7FFFFFFFFFFFFFLL, 40);
  v22 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v24 - 4096);
  _WriteStatusReg(TTBR1_EL1, v24);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v22);
  if ( v21 )
  {
LABEL_16:
    if ( v21 < 0x29 )
    {
      memset((char *)&v49 - v21 + 40, 0, v21);
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_mgr_acquire_hw",
        1463,
        "copy failed");
      result = 4294967282LL;
      goto LABEL_59;
    }
    _fortify_panic(15, 0, v21);
    goto LABEL_67;
  }
  mutex_lock(a1);
  v2 = 0;
  v4 = 0;
  while ( 1 )
  {
    v5 = &a1[v4];
    mutex_lock(&a1[v4 + 64]);
    if ( !a1[v4 + 160] )
      break;
    mutex_unlock(v5 + 64);
    --v2;
    v4 += 208;
    if ( v2 == -24 )
      goto LABEL_19;
  }
  v3 = -v2;
  v5[160] = 1;
  mutex_unlock(v5 + 64);
  if ( -(int)v2 >= 24 )
  {
LABEL_19:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_acquire_hw",
      1470,
      "No free ctx space in hw_mgr");
    mutex_unlock(a1);
    result = 4294967282LL;
    goto LABEL_59;
  }
  if ( (unsigned int)v3 >= 0x19 )
  {
LABEL_67:
    __break(0x5512u);
    v48 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_jpeg_mgr_acquire_hw__alloc_tag;
    v27 = _kvmalloc_node_noprof(528, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v48;
    goto LABEL_26;
  }
  v5 = &a1[v4];
  v2 = (__int64)&a1[v4 + 56];
  unique_tbl = cam_packet_util_get_unique_tbl(&a1[v4 + 248], (__int64 *)&a1[v4 + 256]);
  if ( unique_tbl )
  {
    v26 = unique_tbl;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_acquire_hw",
      1479,
      "Failed at allocating mem for unique buf tbl");
LABEL_52:
    if ( v2 )
    {
      v43 = &a1[v4];
      mutex_lock(&a1[v4 + 64]);
      if ( (a1[v4 + 160] & 1) != 0 )
      {
        v43[160] = 0;
        *((_QWORD *)v43 + 27) = 0;
        *((_QWORD *)v43 + 28) = 0;
        *((_QWORD *)v43 + 29) = 0;
        *((_QWORD *)v43 + 30) = 0;
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          512,
          1,
          "cam_jpeg_mgr_release_ctx",
          659,
          "ctx is already un-used: %pK",
          (const void *)v2);
      }
      mutex_unlock(v43 + 64);
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_mgr_release_ctx",
        653,
        "invalid ctx_data %pK",
        nullptr);
    }
    mutex_unlock(a1);
    result = v26;
    goto LABEL_59;
  }
  v6 = &unk_2FD000;
  if ( mem_trace_en == 1 )
    v27 = cam_mem_trace_alloc(528, 0xCC0u, 0, "cam_jpeg_mgr_acquire_hw", 0x5CEu);
  else
    v27 = _kvmalloc_node_noprof(528, 0, 3520, 0xFFFFFFFFLL);
LABEL_26:
  v28 = &a1[v4];
  *(_QWORD *)&a1[v4 + 200] = v27;
  if ( !v27 )
  {
    v26 = -12;
LABEL_51:
    cam_packet_util_put_unique_tbl(*((_QWORD **)v5 + 31), *((_QWORD **)v5 + 32));
    *((_QWORD *)v5 + 31) = 0;
    *((_QWORD *)v5 + 32) = 0;
    goto LABEL_52;
  }
  mutex_lock(v28 + 8);
  v29 = v52;
  v30 = v53;
  v28[16] = v51;
  v28[17] = v29;
  v32 = v49;
  v31 = v50;
  v28[18] = v30;
  v28[14] = v32;
  v28[15] = v31;
  mutex_unlock(v28 + 8);
  v33 = *((unsigned int *)v28 + 28);
  if ( (unsigned int)v33 > 1 )
  {
    v26 = -22;
    goto LABEL_48;
  }
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
  {
    v46 = v3;
    v47 = *((unsigned int *)v28 + 28);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_mgr_acquire_hw",
      1503,
      "ctx_id: %u, dev_type: %u",
      v46,
      v33);
    v33 = v47;
  }
  v34 = &a1[16 * v33];
  v35 = *((_DWORD *)v34 + 1302);
  v36 = v34 + 5208;
  if ( v35 )
  {
    *(_DWORD *)v36 = v35 + 1;
  }
  else
  {
    _ZF = (_DWORD)v33 == 0;
    LODWORD(s[16]) = 0;
    v39 = 0x616D646765706ALL;
    v40 = *(_QWORD *)&a1[8 * v33 + 5240];
    if ( _ZF )
      v39 = 0x636E656765706ALL;
    LODWORD(s[32]) = 0;
    s[0] = v39;
    s[17] = v2;
    if ( v40 )
      s[20] = v40;
    HIDWORD(s[16]) = 0;
    s[18] = 0;
    LODWORD(s[19]) = 1;
    LODWORD(s[28]) = 0;
    v41 = cam_cdm_acquire((__int64)s);
    if ( v41 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_mgr_acquire_hw",
        1528,
        "Failed to acquire the CDM HW %d",
        v41);
      goto LABEL_47;
    }
    v44 = *(_DWORD *)v36;
    v45 = s[32];
    *((_QWORD *)v36 + 1) = s[31];
    *(_DWORD *)v36 = v44 + 1;
    *((_DWORD *)v36 + 1) = v45;
    if ( !v44 && (unsigned int)cam_cdm_stream_on(*((_DWORD *)v36 + 1)) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_mgr_acquire_hw",
        1543,
        "Can not start cdm (%d)!",
        *((_DWORD *)v36 + 1));
      goto LABEL_38;
    }
  }
  mutex_lock(v28 + 8);
  *(_QWORD *)v2 = *a2;
  a2[6] = v2;
  mutex_unlock(v28 + 8);
  v37 = &a1[v4];
  *((_QWORD *)v37 + 19) = a2[2];
  *((_QWORD *)v37 + 26) = a2[23];
  if ( inline_copy_to_user_4(a2[5], &v49, 40) )
  {
    v38 = *(_DWORD *)v36;
    if ( *(_DWORD *)v36 != 1 )
    {
LABEL_40:
      *(_DWORD *)v36 = v38 - 1;
LABEL_47:
      v26 = -14;
LABEL_48:
      v42 = (_QWORD *)v28[25];
      if ( v6[2904] == 1 )
        cam_mem_trace_free(v42, 0);
      else
        kvfree(v42);
      goto LABEL_51;
    }
    cam_cdm_stream_off(*((_DWORD *)v36 + 1));
LABEL_38:
    v38 = *(_DWORD *)v36;
    if ( *(_DWORD *)v36 == 1 )
    {
      cam_cdm_release(*((_DWORD *)v36 + 1));
      v38 = *(_DWORD *)v36;
    }
    goto LABEL_40;
  }
  mutex_unlock(a1);
  result = 0;
  if ( (debug_mdl & 0x200) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200,
      4,
      "cam_jpeg_mgr_acquire_hw",
      1566,
      "success ctx_data= %pK",
      (const void *)v2);
    result = 0;
  }
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return result;
}
