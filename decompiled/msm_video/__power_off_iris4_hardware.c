__int64 __fastcall _power_off_iris4_hardware(__int64 a1)
{
  int v2; // w0
  __int64 result; // x0
  __int64 v4; // x22
  unsigned int v5; // w24
  __int64 v6; // x26
  bool v7; // w23
  int v8; // w25
  __int64 v9; // x27
  int v10; // w21
  __int64 v11; // x8
  unsigned int (__fastcall *v12)(__int64, const char *); // x8
  __int64 v13; // x8
  unsigned int (__fastcall *v14)(__int64, const char *); // x8
  __int64 v15; // x8
  unsigned int v16; // w23
  __int64 v17; // x25
  bool v18; // w22
  int v19; // w24
  __int64 v20; // x26
  __int64 v21; // x8
  unsigned int (__fastcall *v22)(__int64, const char *); // x8
  __int64 v23; // x8
  unsigned int (__fastcall *v24)(__int64, const char *); // x8
  __int64 v25; // x8
  unsigned int (__fastcall *v26)(__int64, const char *); // x8
  __int64 v27; // x8
  unsigned int (__fastcall *v28)(__int64, const char *); // x8
  __int64 v29; // x8
  __int64 (__fastcall *v30)(__int64, const char *); // x8
  int v31; // [xsp+0h] [xbp-10h] BYREF
  int v32; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  if ( (is_core_sub_state(a1, 8) & 1) != 0 )
  {
    v32 = 0;
    v2 = _read_register(a1, 0xB0080u, &v32);
    if ( !(v2 | v32 & 2) )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_8C7CD, "high", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
      goto LABEL_5;
    }
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8321F, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
  }
  result = _read_register(a1, 0xB0088u, &v31);
  if ( (_DWORD)result )
    goto LABEL_116;
  if ( (v31 & 1) != 0 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8B03E, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
    result = _write_register(a1, 0xB0088u, 0);
    if ( (_DWORD)result )
      goto LABEL_116;
  }
  if ( (unsigned int)_read_register_with_poll_timeout(a1, 0x70u, 28931, 28931, 0x7D0u, 0x4E20u)
    && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_8BCF7, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
  }
  result = _write_register_masked(a1, 0xE0000u, 1, 1);
  if ( (_DWORD)result )
    goto LABEL_116;
  result = _read_register(a1, 0xE0004u, &v31);
  if ( (_DWORD)result )
    goto LABEL_116;
  v10 = 1000;
  while ( (v31 & 1) == 0 && (v31 & 6) != 0 )
  {
    result = _write_register_masked(a1, 0xE0000u, 0, 1);
    if ( (_DWORD)result )
      goto LABEL_116;
    usleep_range_state(10, 20, 2);
    result = _write_register_masked(a1, 0xE0000u, 1, 1);
    if ( (_DWORD)result )
      goto LABEL_116;
    result = _read_register(a1, 0xE0004u, &v31);
    if ( (_DWORD)result )
      goto LABEL_116;
    if ( !--v10 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_85640, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
      break;
    }
  }
  if ( (unsigned int)_read_register_with_poll_timeout(a1, 0xE0004u, 1, 1, 0xC8u, 0x7D0u) && (msm_vidc_debug & 1) != 0 )
    printk(&unk_9059F, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
  result = _write_register_masked(a1, 0xE0000u, 0, 1);
  if ( (_DWORD)result )
    goto LABEL_116;
  result = _write_register(a1, 0x1F000u, 0x70103u);
  if ( (_DWORD)result )
    goto LABEL_116;
  if ( (unsigned int)_read_register_with_poll_timeout(a1, 0x1F004u, -1, 459011, 0xC8u, 0x7D0u)
    && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_91FB1, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
  }
  result = _write_register(a1, 0x1F008u, 0x70103u);
  if ( (_DWORD)result )
    goto LABEL_116;
  result = _write_register(a1, 0x1F008u, 0);
  if ( (_DWORD)result )
    goto LABEL_116;
  result = _write_register(a1, 0x1F000u, 0);
  if ( (_DWORD)result )
    goto LABEL_116;
  if ( (unsigned int)_read_register_with_poll_timeout(a1, 0x1F004u, -1, 0, 0xC8u, 0x7D0u) && (msm_vidc_debug & 1) != 0 )
    printk(&unk_96A5F, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
  result = _write_register(a1, 0xA0160u, 3u);
  if ( (_DWORD)result )
    goto LABEL_116;
  result = _write_register(a1, 0xA0160u, 2u);
  if ( (_DWORD)result )
    goto LABEL_116;
  result = _write_register(a1, 0xA0160u, 0);
  if ( (_DWORD)result )
    goto LABEL_116;
LABEL_5:
  result = _read_register(a1, 0xB0008u, &v31);
  if ( (_DWORD)result )
    goto LABEL_116;
  v4 = *(_QWORD *)(a1 + 3912);
  v5 = *(_DWORD *)(v4 + 40);
  if ( v5 )
  {
    v6 = *(_QWORD *)(v4 + 32);
    v7 = 0;
    v8 = 0;
    while ( 1 )
    {
      v9 = v6 + 16LL * v8;
      if ( !strcmp(*(const char **)v9, "vpp1") && (*(_BYTE *)(v9 + 9) & 1) == 0 )
        break;
      v7 = ++v8 >= v5;
      if ( v5 == v8 )
        goto LABEL_12;
    }
    if ( (msm_vidc_debug & 2) == 0 )
    {
LABEL_12:
      if ( !v7 )
        goto LABEL_70;
      goto LABEL_13;
    }
    printk(&unk_8C79B, "high", 0xFFFFFFFFLL, "codec", "is_hw_enabled");
    if ( !v7 )
      goto LABEL_70;
    v4 = *(_QWORD *)(a1 + 3912);
  }
LABEL_13:
  if ( *(_DWORD *)(v4 + 328) == 4 )
  {
    if ( !a1 || (v31 & 0x10000000) != 0 )
      goto LABEL_70;
  }
  else if ( !a1 )
  {
    goto LABEL_70;
  }
  v11 = *(_QWORD *)(a1 + 6552);
  if ( !v11 )
    goto LABEL_70;
  v12 = *(unsigned int (__fastcall **)(__int64, const char *))(v11 + 64);
  if ( !v12 )
    goto LABEL_63;
  if ( *((_DWORD *)v12 - 1) != 841426229 )
    __break(0x8228u);
  if ( v12(a1, "vpp1") && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_96AA3, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
    v13 = *(_QWORD *)(a1 + 6552);
    if ( !v13 )
      goto LABEL_70;
  }
  else
  {
LABEL_63:
    v13 = *(_QWORD *)(a1 + 6552);
    if ( !v13 )
      goto LABEL_70;
  }
  v14 = *(unsigned int (__fastcall **)(__int64, const char *))(v13 + 112);
  if ( v14 )
  {
    if ( *((_DWORD *)v14 - 1) != 841426229 )
      __break(0x8228u);
    if ( v14(a1, "video_cc_mvs0_vpp1_clk") && (msm_vidc_debug & 1) != 0 )
      printk(&unk_92B12, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
  }
LABEL_70:
  v15 = *(_QWORD *)(a1 + 3912);
  v16 = *(_DWORD *)(v15 + 40);
  if ( v16 )
  {
    v17 = *(_QWORD *)(v15 + 32);
    v18 = 0;
    v19 = 0;
    while ( 1 )
    {
      v20 = v17 + 16LL * v19;
      if ( !strcmp(*(const char **)v20, "vpp0") && (*(_BYTE *)(v20 + 9) & 1) == 0 )
        break;
      v18 = ++v19 >= v16;
      if ( v16 == v19 )
        goto LABEL_76;
    }
    if ( (msm_vidc_debug & 2) == 0 )
    {
LABEL_76:
      if ( !v18 )
        goto LABEL_95;
      goto LABEL_77;
    }
    printk(&unk_8C79B, "high", 0xFFFFFFFFLL, "codec", "is_hw_enabled");
    if ( v18 )
      goto LABEL_77;
LABEL_95:
    if ( !a1 )
      goto LABEL_115;
    goto LABEL_96;
  }
LABEL_77:
  if ( (v31 & 0x20000000) != 0 )
    goto LABEL_95;
  if ( !a1 )
    goto LABEL_115;
  v21 = *(_QWORD *)(a1 + 6552);
  if ( !v21 )
    goto LABEL_96;
  v22 = *(unsigned int (__fastcall **)(__int64, const char *))(v21 + 64);
  if ( !v22 )
    goto LABEL_85;
  if ( *((_DWORD *)v22 - 1) != 841426229 )
    __break(0x8228u);
  if ( v22(a1, "vpp0") && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_8BD44, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
    v23 = *(_QWORD *)(a1 + 6552);
    if ( !v23 )
      goto LABEL_96;
  }
  else
  {
LABEL_85:
    v23 = *(_QWORD *)(a1 + 6552);
    if ( !v23 )
      goto LABEL_96;
  }
  v24 = *(unsigned int (__fastcall **)(__int64, const char *))(v23 + 112);
  if ( v24 )
  {
    if ( *((_DWORD *)v24 - 1) != 841426229 )
      __break(0x8228u);
    if ( v24(a1, "video_cc_mvs0_vpp0_clk") && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8BD82, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
  }
LABEL_96:
  v25 = *(_QWORD *)(a1 + 6552);
  if ( !v25 )
    goto LABEL_115;
  v26 = *(unsigned int (__fastcall **)(__int64, const char *))(v25 + 64);
  if ( !v26 )
    goto LABEL_102;
  if ( *((_DWORD *)v26 - 1) != 841426229 )
    __break(0x8228u);
  if ( v26(a1, "vcodec") && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_8BDC8, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
    v27 = *(_QWORD *)(a1 + 6552);
    if ( !v27 )
      goto LABEL_115;
  }
  else
  {
LABEL_102:
    v27 = *(_QWORD *)(a1 + 6552);
    if ( !v27 )
      goto LABEL_115;
  }
  v28 = *(unsigned int (__fastcall **)(__int64, const char *))(v27 + 112);
  if ( !v28 )
    goto LABEL_108;
  if ( *((_DWORD *)v28 - 1) != 841426229 )
    __break(0x8228u);
  if ( !v28(a1, "video_cc_mvs0_clk") || (msm_vidc_debug & 1) == 0 )
  {
LABEL_108:
    v29 = *(_QWORD *)(a1 + 6552);
    if ( v29 )
      goto LABEL_109;
LABEL_115:
    result = 0;
    goto LABEL_116;
  }
  printk(&unk_975B4, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
  v29 = *(_QWORD *)(a1 + 6552);
  if ( !v29 )
    goto LABEL_115;
LABEL_109:
  v30 = *(__int64 (__fastcall **)(__int64, const char *))(v29 + 112);
  if ( !v30 )
    goto LABEL_115;
  if ( *((_DWORD *)v30 - 1) != 841426229 )
    __break(0x8228u);
  result = v30(a1, "video_cc_mvs0b_clk");
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8B0A2, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_hardware");
    goto LABEL_115;
  }
LABEL_116:
  _ReadStatusReg(SP_EL0);
  return result;
}
