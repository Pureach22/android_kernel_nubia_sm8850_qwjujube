__int64 __fastcall msm_minidump_driver_probe(__int64 *a1)
{
  unsigned __int64 StatusReg; // x22
  __int64 (*v4)(void); // x8
  unsigned int v5; // w0
  __int64 v6; // x1
  const char *v7; // x21
  unsigned __int64 v8; // x19
  __int64 v9; // x20
  unsigned int v10; // w19
  void *v11; // x8
  void *v12; // x0
  __int64 v13; // x24
  __int64 v14; // x25
  __int64 v15; // x26
  int v16; // w0
  size_t v17; // x0
  unsigned __int64 v18; // x2
  size_t v19; // x0
  int v20; // w0
  __int64 v21; // x8
  unsigned __int64 v22; // x12
  __int64 v23; // x9
  __int64 v24; // x8
  size_t v25; // x0
  __int64 v26; // x8
  _DWORD *v27; // x8
  __int64 (__fastcall *v28)(_QWORD); // x8
  __int64 v29; // x24

  if ( (debug_symbol_available() & 1) == 0 )
    return 4294966779LL;
  md_core_0 = *a1;
  v4 = *(__int64 (**)(void))md_core_0;
  if ( *(_DWORD *)(*(_QWORD *)md_core_0 - 4LL) != 1874538549 )
    __break(0x8228u);
  v5 = v4();
  if ( v5 )
  {
    v11 = &unk_113D2E;
    goto LABEL_10;
  }
  v7 = (const char *)debug_symbol_lookup_name("linux_banner");
  v8 = ((unsigned int)strlen(v7) & 0xFFFFFFFC) + 27884;
  v9 = _kmalloc_noprof(v8, 3520);
  while ( 1 )
  {
    minidump_elfheader = v9;
    if ( !v9 )
    {
      v10 = -12;
LABEL_105:
      v12 = &unk_113075;
      goto LABEL_106;
    }
    qword_10028 = v9 + 64;
    qword_10030 = v9 + 12928;
    if ( v8 <= 3 )
      goto LABEL_115;
    *(_DWORD *)v9 = 1179403647;
    if ( v8 == 4 )
      goto LABEL_114;
    *(_WORD *)(v9 + 4) = 258;
    if ( v8 < 6 )
      goto LABEL_114;
    *(_WORD *)(v9 + 6) = 1;
    if ( v8 < 0x10 )
      goto LABEL_114;
    v13 = (unsigned int)v8 & 0xFFFFFFFE;
    if ( v13 == 16 )
      goto LABEL_114;
    *(_WORD *)(v9 + 16) = 4;
    if ( v8 < 0x12 )
      goto LABEL_114;
    if ( v13 == 18 )
      goto LABEL_114;
    if ( (v8 & 0xFFFFFFFE) == 0x12 )
      goto LABEL_114;
    *(_WORD *)(v9 + 18) = 183;
    if ( v8 < 0x14 )
      goto LABEL_114;
    v14 = (unsigned int)v8 & 0xFFFFFFFC;
    if ( v14 == 20 )
      goto LABEL_114;
    *(_DWORD *)(v9 + 20) = 1;
    if ( v8 < 0x34 )
      goto LABEL_114;
    if ( v13 == 52 )
      goto LABEL_114;
    if ( (v8 & 0xFFFFFFFE) == 0x34 )
      goto LABEL_114;
    v15 = (unsigned int)v8 & 0xFFFFFFF8;
    *(_WORD *)(v9 + 52) = 64;
    if ( v15 == 32 )
      goto LABEL_114;
    *(_QWORD *)(v9 + 32) = 12928;
    if ( v8 < 0x36 )
      goto LABEL_114;
    if ( v13 == 54 )
      goto LABEL_114;
    if ( (v8 & 0xFFFFFFFE) == 0x36 )
      goto LABEL_114;
    *(_WORD *)(v9 + 54) = 56;
    if ( v15 == 40 )
      goto LABEL_114;
    if ( (v8 & 0xFFFFFFF8) == 0x28 )
      goto LABEL_114;
    *(_QWORD *)(v9 + 40) = 64;
    if ( v8 < 0x3A )
      goto LABEL_114;
    if ( v13 == 58 )
      goto LABEL_114;
    if ( (v8 & 0xFFFFFFFE) == 0x3A )
      goto LABEL_114;
    *(_WORD *)(v9 + 58) = 64;
    if ( v8 < 0x3E )
      goto LABEL_114;
    if ( v13 == 62 )
      goto LABEL_114;
    if ( (v8 & 0xFFFFFFFE) == 0x3E )
      goto LABEL_114;
    *(_WORD *)(v9 + 62) = 1;
    qword_10038 = v8;
    qword_10040 = 1;
    if ( v8 < 0x84 )
      goto LABEL_114;
    if ( v14 == 132 )
      goto LABEL_114;
    if ( (v8 & 0xFFFFFFFC) == 0x84 )
      goto LABEL_114;
    *(_DWORD *)(v9 + 132) = 3;
    if ( v8 < 0x98 )
      goto LABEL_114;
    if ( v15 == 152 )
      goto LABEL_114;
    if ( (v8 & 0xFFFFFFF8) == 0x98 )
      goto LABEL_114;
    *(_QWORD *)(v9 + 152) = 24184;
    if ( v8 < 0xA0 )
      goto LABEL_114;
    if ( v15 == 160 )
      goto LABEL_114;
    if ( (v8 & 0xFFFFFFF8) == 0xA0 )
      goto LABEL_114;
    *(_QWORD *)(v9 + 160) = 3216;
    if ( v8 < 0xB8 )
      goto LABEL_114;
    if ( v15 == 184 )
      goto LABEL_114;
    if ( (v8 & 0xFFFFFFF8) == 0xB8 )
      goto LABEL_114;
    *(_QWORD *)(v9 + 184) = 0;
    if ( v15 == 136 )
      goto LABEL_114;
    if ( (v8 & 0xFFFFFFF8) == 0x88 )
      goto LABEL_114;
    *(_QWORD *)(v9 + 136) = 0;
    v16 = set_section_name((__int64)"STR_TBL");
    if ( v14 == 128 || (v8 & 0xFFFFFFFC) == 0x80 )
      goto LABEL_114;
    *(_DWORD *)(v9 + 128) = v16;
    if ( v8 >= 0x6B08 )
      StatusReg = v8 - 27400;
    else
      StatusReg = 0;
    v17 = strnlen(v7, 0xC90u);
    if ( v17 == -1 )
      goto LABEL_116;
    v18 = v17 == 3216 ? 3216LL : v17 + 1;
    if ( v18 <= StatusReg )
      break;
LABEL_117:
    _fortify_panic(7, StatusReg, v18);
    StatusReg = _ReadStatusReg(SP_EL0);
    v29 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &msm_minidump_add_header__alloc_tag;
    v9 = _kmalloc_noprof(v8, 3520);
    *(_QWORD *)(StatusReg + 80) = v29;
  }
  sized_strscpy(v9 + 27400, v7);
  if ( v8 < 0xC4 )
    goto LABEL_114;
  if ( v14 == 196 )
    goto LABEL_114;
  if ( (v8 & 0xFFFFFFFC) == 0xC4 )
    goto LABEL_114;
  *(_DWORD *)(v9 + 196) = 1;
  if ( v8 < 0xD8 )
    goto LABEL_114;
  if ( v15 == 216 )
    goto LABEL_114;
  if ( (v8 & 0xFFFFFFF8) == 0xD8 )
    goto LABEL_114;
  *(_QWORD *)(v9 + 216) = 27400;
  v19 = strlen(v7);
  if ( v8 < 0xE0 )
    goto LABEL_114;
  if ( v15 == 224 )
    goto LABEL_114;
  if ( (v8 & 0xFFFFFFF8) == 0xE0 )
    goto LABEL_114;
  *(_QWORD *)(v9 + 224) = v19 + 1;
  if ( v15 == 208 )
    goto LABEL_114;
  if ( (v8 & 0xFFFFFFF8) == 0xD0 )
    goto LABEL_114;
  *(_QWORD *)(v9 + 208) = v7;
  if ( v8 < 0xF8 )
    goto LABEL_114;
  if ( v15 == 248 )
    goto LABEL_114;
  if ( (v8 & 0xFFFFFFF8) == 0xF8 )
    goto LABEL_114;
  *(_QWORD *)(v9 + 248) = 0;
  if ( v15 == 200 )
    goto LABEL_114;
  if ( (v8 & 0xFFFFFFF8) == 0xC8 )
    goto LABEL_114;
  *(_QWORD *)(v9 + 200) = 1;
  v20 = set_section_name((__int64)"linux_banner");
  if ( v14 == 192 )
    goto LABEL_114;
  if ( (v8 & 0xFFFFFFFC) == 0xC0 )
    goto LABEL_114;
  *(_DWORD *)(v9 + 192) = v20;
  if ( v8 >> 7 < 0x65 )
    goto LABEL_114;
  if ( v14 == 12928 )
    goto LABEL_114;
  if ( (v8 & 0xFFFFFFFC) == 0x3280 )
    goto LABEL_114;
  StatusReg = v8 >> 3;
  *(_DWORD *)(v9 + 12928) = 1;
  if ( v8 >> 3 < 0x651 )
    goto LABEL_114;
  if ( v15 == 12936 )
    goto LABEL_114;
  if ( (v8 & 0xFFFFFFF8) == 0x3288 )
    goto LABEL_114;
  *(_QWORD *)(v9 + 12936) = 27400;
  if ( v8 >> 4 < 0x329 )
    goto LABEL_114;
  if ( v15 == 12944 )
    goto LABEL_114;
  if ( (v8 & 0xFFFFFFF8) == 0x3290 )
    goto LABEL_114;
  *(_QWORD *)(v9 + 12944) = v7;
  if ( StatusReg < 0x653 || v15 == 12952 || (v8 & 0xFFFFFFF8) == 0x3298 )
    goto LABEL_114;
  v21 = (__int64)((_QWORD)v7 << 8) >> 8;
  v22 = (unsigned __int64)(v21 + 0x8000000000LL) >> 38;
  v23 = memstart_addr + v21 + 0x8000000000LL;
  v24 = v21 - kimage_voffset;
  if ( !v22 )
    v24 = v23;
  *(_QWORD *)(v9 + 12952) = v24;
  v25 = strlen(v7);
  if ( StatusReg < 0x655
    || v15 == 12968
    || (v8 & 0xFFFFFFF8) == 0x32A8
    || (*(_QWORD *)(v9 + 12968) = v25 + 1, v15 == 12960)
    || v8 >> 5 < 0x195
    || (v8 & 0xFFFFFFF8) == 0x32A0
    || (*(_QWORD *)(v9 + 12960) = v25 + 1, v14 == 12932)
    || v8 >> 2 < 0xCA1
    || (v8 & 0xFFFFFFFC) == 0x3284
    || (*(_DWORD *)(v9 + 12932) = 6, v13 == 56)
    || (v8 & 0xFFFFFFFE) == 0x38 )
  {
LABEL_114:
    __break(1u);
LABEL_115:
    v17 = _fortify_panic(17, v8, 4);
LABEL_116:
    _fortify_panic(2, -1, v17 + 1);
    goto LABEL_117;
  }
  v26 = md_core_0;
  *(_WORD *)(v9 + 56) = 1;
  if ( !v26 )
  {
    v10 = -22;
    goto LABEL_105;
  }
  v27 = *(_DWORD **)(v26 + 16);
  if ( *(v27 - 1) != -228464455 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _QWORD))v27)(v9 + 192, v9, (unsigned int)v8);
  atomic_store(1u, (unsigned __int8 *)&md_init_done);
  v28 = *(__int64 (__fastcall **)(_QWORD))(md_core_0 + 8);
  if ( *((_DWORD *)v28 - 1) != 1062861432 )
    __break(0x8228u);
  v5 = v28(&pending_list);
  if ( !v5 )
  {
    msm_minidump_log_init();
    printk(&unk_1139D3, 200);
    return 0;
  }
  v11 = &unk_1138B8;
LABEL_10:
  v10 = v5;
  v12 = v11;
LABEL_106:
  printk(v12, v6);
  return v10;
}
