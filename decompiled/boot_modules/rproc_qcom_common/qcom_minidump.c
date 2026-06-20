__int64 __fastcall qcom_minidump(unsigned __int64 a1, size_t a2, unsigned int a3, unsigned __int64 a4)
{
  size_t v4; // x23
  size_t *v5; // x25
  unsigned __int64 v6; // x26
  unsigned __int64 v7; // x27
  _DWORD *v12; // x0
  _DWORD *v13; // x20
  __int64 v14; // x19
  __int64 v15; // x23
  __int64 v16; // x2
  __int64 v17; // x0
  __int64 v18; // x22
  __int64 v19; // x19
  const char *v20; // x0
  const char *v21; // x24
  __int64 result; // x0
  __int64 v23; // x19
  __int64 v24; // x20
  size_t v25; // x19
  __int64 v26; // x8
  size_t v27; // x0
  __int64 v28; // x22
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x19
  __int16 v31; // w9
  unsigned __int64 v32; // x20
  size_t v33; // x1
  int v34; // w0
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x1
  _QWORD *v37; // x20
  unsigned __int64 v38; // x19
  int v39; // w0
  _DWORD *v40; // x8
  __int64 v41; // x4
  size_t **v42; // x19
  size_t **v43; // x8
  size_t *v44; // x21
  size_t *v45; // x0
  int v46; // w2
  unsigned __int64 StatusReg; // x19
  __int64 v48; // x20
  size_t v49; // [xsp+8h] [xbp-48h]
  size_t v50; // [xsp+10h] [xbp-40h]
  unsigned __int64 v51; // [xsp+18h] [xbp-38h]
  _QWORD v52[2]; // [xsp+20h] [xbp-30h] BYREF
  __int64 v53; // [xsp+30h] [xbp-20h]
  __int64 v54; // [xsp+38h] [xbp-18h]
  __int64 v55; // [xsp+40h] [xbp-10h]
  __int64 v56; // [xsp+48h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = (_DWORD *)qcom_smem_get(0xFFFFFFFFLL, 602, 0);
  if ( (unsigned __int64)v12 > 0xFFFFFFFFFFFFF000LL || !*v12 )
  {
    result = dev_err(a1 + 56, "Minidump TOC not found in SMEM\n");
    goto LABEL_22;
  }
  if ( a3 >= 0x1F )
  {
    __break(0x5512u);
    goto LABEL_119;
  }
  v13 = &v12[8 * a3];
  if ( !*((_QWORD *)v13 + 5) || v13[4] != 1 || v13[5] != 1162756684 )
  {
    result = rproc_coredump(a1);
    goto LABEL_22;
  }
  if ( v13[6] != 1146048069 )
    dev_err(a1 + 56, "encryption_status != MINIDUMP_SS_ENCR_DONE\n");
  rproc_coredump_cleanup(a1);
  v54 = 0;
  v55 = 0;
  v5 = (size_t *)(a1 + 1256);
  v52[1] = 0;
  v53 = 0;
  v52[0] = 0;
  if ( *(_QWORD *)(a1 + 1256) != a1 + 1256 )
  {
    __break(0x800u);
    dev_err(a1 + 56, "dump segment list already populated\n");
    v46 = -117;
    goto LABEL_114;
  }
  v14 = (int)v13[8];
  v15 = 40 * v14;
  if ( arm64_use_ng_mappings )
    v16 = 0x68000000000F13LL;
  else
    v16 = 0x68000000000713LL;
  v17 = ioremap_prot(*((_QWORD *)v13 + 5), 40 * v14, v16);
  if ( !v17 )
  {
    v46 = -14;
LABEL_114:
    result = dev_err(a1 + 56, "Failed with error: %d while adding minidump entries\n", v46);
    goto LABEL_106;
  }
  v18 = v17;
  v50 = a2;
  if ( (int)v14 < 1 )
    goto LABEL_27;
  v19 = 0;
  while ( 1 )
  {
    _memcpy_fromio(v52, v18 + v19, 40);
    if ( HIDWORD(v53) == 1447119945 )
      break;
LABEL_16:
    v19 += 40;
    if ( v15 == v19 )
      goto LABEL_27;
  }
  v20 = (const char *)kstrndup(v52, 15, 3264);
  if ( !v20 )
  {
    iounmap(v18);
    v46 = -12;
    goto LABEL_114;
  }
  v21 = v20;
  if ( v13[6] == 1146048069 )
  {
    rproc_coredump_add_custom_segment(a1, v54, (unsigned int)v55, a4, v20);
    goto LABEL_16;
  }
  if ( !v19 )
  {
    v23 = v54;
    v24 = (unsigned int)v55;
    if ( !strcmp(v20, "md_dbg_buf") )
      rproc_coredump_add_custom_segment(a1, v23, v24, a4, v21);
  }
LABEL_27:
  result = iounmap(v18);
  if ( *(_BYTE *)(a1 + 1276) != 2 )
  {
    result = rproc_coredump(a1);
    goto LABEL_106;
  }
  v51 = a1;
  v52[0] = 1;
  v25 = *(_QWORD *)(a1 + 1256);
  if ( (size_t *)v25 == v5 )
    goto LABEL_106;
  if ( !*(_DWORD *)(a1 + 976) )
    goto LABEL_106;
  LOWORD(a1) = 2;
  v4 = 9;
  v26 = 192;
  do
  {
    a2 = v4;
    v6 = v26;
    v27 = strlen(*(const char **)(v25 + 32));
    v7 = *(_QWORD *)(v25 + 24);
    v25 = *(_QWORD *)v25;
    v4 += v27 + 1;
    LOWORD(a1) = a1 + 1;
    v26 = v6 + v7 + 64;
  }
  while ( (size_t *)v25 != v5 );
  a4 = v26 + v4;
  v49 = v27;
  result = vmalloc_noprof(v26 + v4);
  v28 = result;
  if ( !result )
    goto LABEL_106;
  while ( 2 )
  {
    if ( a4 <= 0x3F )
      goto LABEL_120;
    v29 = a4 & 0xFFFFFFFFFFFFFFFELL;
    *(_QWORD *)(v28 + 48) = 0;
    *(_QWORD *)(v28 + 56) = 0;
    *(_QWORD *)(v28 + 32) = 0;
    *(_QWORD *)(v28 + 40) = 0;
    *(_QWORD *)(v28 + 16) = 0;
    *(_QWORD *)(v28 + 24) = 0;
    *(_QWORD *)v28 = 0x10102464C457FLL;
    *(_QWORD *)(v28 + 8) = 0;
    if ( (a4 & 0xFFFFFFFFFFFFFFFELL) == 0x10 )
      goto LABEL_117;
    v30 = a4 & 0xFFFFFFFFFFFFFFF8LL;
    *(_WORD *)(v28 + 16) = 4;
    if ( (a4 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
      goto LABEL_117;
    v31 = *(_WORD *)(v51 + 1278);
    *(_QWORD *)(v28 + 24) = *(_QWORD *)(v51 + 1096);
    if ( v30 == 40
      || (a4 & 0xFFFFFFFFFFFFFFF8LL) == 0x28
      || (*(_QWORD *)(v28 + 40) = 64, v29 == 18)
      || (a4 & 0xFFFFFFFFFFFFFFFELL) == 0x12
      || (v32 = a4 & 0xFFFFFFFFFFFFFFFCLL, *(_WORD *)(v28 + 18) = v31, (a4 & 0xFFFFFFFFFFFFFFFCLL) == 0x14)
      || (*(_DWORD *)(v28 + 20) = 1, v29 == 52)
      || (a4 & 0xFFFFFFFFFFFFFFFELL) == 0x34
      || (*(_WORD *)(v28 + 52) = 64, v29 == 58)
      || (a4 & 0xFFFFFFFFFFFFFFFELL) == 0x3A
      || (*(_WORD *)(v28 + 58) = 64, v29 == 60)
      || (a4 & 0xFFFFFFFFFFFFFFFELL) == 0x3C
      || (*(_WORD *)(v28 + 60) = a1, v29 == 62)
      || (a4 & 0xFFFFFFFFFFFFFFFELL) == 0x3E )
    {
LABEL_117:
      __break(1u);
    }
    *(_WORD *)(v28 + 62) = 1;
    if ( a4 - 64 <= 0x3F )
    {
LABEL_119:
      _fortify_panic(15);
LABEL_120:
      _fortify_panic(15);
LABEL_121:
      _fortify_panic(15);
      StatusReg = _ReadStatusReg(SP_EL0);
      v48 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &qcom_rproc_minidump__alloc_tag;
      result = vmalloc_noprof(a4);
      v28 = result;
      *(_QWORD *)(StatusReg + 80) = v48;
      if ( !result )
        goto LABEL_106;
      continue;
    }
    break;
  }
  *(_QWORD *)(v28 + 112) = 0;
  *(_QWORD *)(v28 + 120) = 0;
  *(_QWORD *)(v28 + 96) = 0;
  *(_QWORD *)(v28 + 104) = 0;
  *(_QWORD *)(v28 + 80) = 0;
  *(_QWORD *)(v28 + 88) = 0;
  *(_QWORD *)(v28 + 64) = 0;
  *(_QWORD *)(v28 + 72) = 0;
  if ( (a4 & 0xFFFFFFFFFFFFFFF8LL) == 0x28 || (a4 & 0xFFFFFFFFFFFFFFFELL) == 0x3C )
    goto LABEL_117;
  a1 = *(_QWORD *)(v28 + 40) + ((unsigned __int64)*(unsigned __int16 *)(v28 + 60) << 6);
  if ( a4 >= a1 )
    v33 = a4 - a1;
  else
    v33 = 0;
  if ( v33 < v4 )
    goto LABEL_121;
  memset((void *)(v28 + a1), 0, v4);
  if ( a4 - 128 <= 0x3F )
    goto LABEL_119;
  *(_QWORD *)(v28 + 176) = 0;
  *(_QWORD *)(v28 + 184) = 0;
  *(_QWORD *)(v28 + 160) = 0;
  *(_QWORD *)(v28 + 168) = 0;
  *(_QWORD *)(v28 + 144) = 0;
  *(_QWORD *)(v28 + 152) = 0;
  *(_QWORD *)(v28 + 128) = 0;
  *(_QWORD *)(v28 + 136) = 0;
  if ( v32 == 132 )
    goto LABEL_117;
  if ( (a4 & 0xFFFFFFFFFFFFFFFCLL) == 0x84 )
    goto LABEL_117;
  *(_DWORD *)(v28 + 132) = 3;
  if ( v30 == 152 )
    goto LABEL_117;
  if ( (a4 & 0xFFFFFFFFFFFFFFF8LL) == 0x98 )
    goto LABEL_117;
  *(_QWORD *)(v28 + 152) = a1;
  if ( v30 == 160 )
    goto LABEL_117;
  if ( (a4 & 0xFFFFFFFFFFFFFFF8LL) == 0xA0 )
    goto LABEL_117;
  *(_QWORD *)(v28 + 160) = v4;
  if ( v30 == 184 )
    goto LABEL_117;
  if ( v30 == 136 )
    goto LABEL_117;
  v34 = elf_strtbl_add("STR_TBL");
  if ( v32 == 128 || (a4 & 0xFFFFFFFFFFFFFFFCLL) == 0x80 )
    goto LABEL_117;
  v4 = *v5;
  *(_DWORD *)(v28 + 128) = v34;
  if ( (size_t *)v4 != v5 )
  {
    if ( (a4 & 0xFFFFFFFFFFFFFFF8LL) == 0xA0 )
      goto LABEL_117;
    v35 = v49 + v6 + a2 + v7;
    v7 = 192;
    a2 = *(_QWORD *)(v28 + 160) + a1;
    v6 = v35 - 183;
    do
    {
      v36 = a4 >= v7 ? a4 - v7 : 0LL;
      if ( v36 <= 0x3F )
        goto LABEL_119;
      v37 = (_QWORD *)(v28 + v7);
      v37[6] = 0;
      v37[7] = 0;
      v37[4] = 0;
      v37[5] = 0;
      v37[2] = 0;
      v37[3] = 0;
      *v37 = 0;
      v37[1] = 0;
      if ( (__int64)(v7 + 4) < 0 )
        goto LABEL_117;
      if ( a4 < v7 + 4 )
        goto LABEL_117;
      if ( v6 + 52 < 4 )
        goto LABEL_117;
      *(_DWORD *)(v28 + v7 + 4) = 1;
      if ( (__int64)(v7 + 24) < 0 )
        goto LABEL_117;
      if ( a4 < v7 + 24 )
        goto LABEL_117;
      if ( v6 + 32 < 8 )
        goto LABEL_117;
      *(_QWORD *)(v28 + v7 + 24) = a2;
      if ( (__int64)(v7 + 16) < 0 )
        goto LABEL_117;
      if ( a4 < v7 + 16 )
        goto LABEL_117;
      if ( v6 + 40 < 8 )
        goto LABEL_117;
      a1 = v28 + v7;
      v38 = v7 + 32;
      *(_QWORD *)(v28 + v7 + 16) = *(_QWORD *)(v4 + 16);
      if ( (__int64)(v7 + 32) < 0 )
        goto LABEL_117;
      if ( a4 < v38 )
        goto LABEL_117;
      if ( v6 + 24 < 8 )
        goto LABEL_117;
      *(_QWORD *)(a1 + 32) = *(_QWORD *)(v4 + 24);
      if ( (__int64)(v7 + 56) < 0 )
        goto LABEL_117;
      if ( a4 < v7 + 56 )
        goto LABEL_117;
      if ( v6 < 8 )
        goto LABEL_117;
      *(_QWORD *)(v28 + v7 + 56) = 0;
      if ( (__int64)(v7 + 8) < 0 )
        goto LABEL_117;
      if ( a4 < v7 + 8 )
        goto LABEL_117;
      if ( v6 + 48 < 8 )
        goto LABEL_117;
      *(_QWORD *)(v28 + v7 + 8) = 1;
      v39 = elf_strtbl_add(*(char **)(v4 + 32));
      if ( (v7 & 0x8000000000000000LL) != 0 || a4 < v7 || v6 + 56 < 4 )
        goto LABEL_117;
      *(_DWORD *)v37 = v39;
      v40 = *(_DWORD **)(v4 + 40);
      v41 = *(_QWORD *)(v4 + 24);
      if ( *(v40 - 1) != -837451724 )
        __break(0x8228u);
      ((void (__fastcall *)(unsigned __int64, size_t, size_t, _QWORD, __int64))v40)(v51, v4, v28 + a2, 0, v41);
      if ( a4 < v38 || v6 + 24 < 8 )
        goto LABEL_117;
      v4 = *(_QWORD *)v4;
      v7 += 64LL;
      v6 -= 64LL;
      a2 += *(_QWORD *)(a1 + 32);
    }
    while ( (size_t *)v4 != v5 );
  }
  result = dev_coredumpv(v50, v28, a4, 3264);
LABEL_106:
  v42 = (size_t **)*v5;
  if ( (size_t *)*v5 != v5 )
  {
    do
    {
      v44 = *v42;
      v43 = (size_t **)v42[1];
      if ( *v43 == (size_t *)v42 && (size_t **)v44[1] == v42 )
      {
        v44[1] = (size_t)v43;
        *v43 = v44;
      }
      else
      {
        _list_del_entry_valid_or_report(v42);
      }
      v45 = v42[4];
      *v42 = (size_t *)0xDEAD000000000100LL;
      v42[1] = (size_t *)0xDEAD000000000122LL;
      kfree(v45);
      result = kfree(v42);
      v42 = (size_t **)v44;
    }
    while ( v44 != v5 );
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
