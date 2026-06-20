__int64 __fastcall _power_off_iris4_controller(__int64 a1)
{
  __int64 result; // x0
  int v3; // w22
  int v4; // w22
  __int64 v5; // x8
  unsigned int (__fastcall *v6)(__int64, const char *); // x8
  __int64 v7; // x8
  unsigned int (__fastcall *v8)(__int64, const char *); // x8
  __int64 v9; // x8
  unsigned int (__fastcall *v10)(__int64, const char *); // x8
  __int64 v11; // x8
  unsigned int (__fastcall *v12)(__int64, const char *); // x8
  __int64 v13; // x8
  unsigned int (__fastcall *v14)(__int64, const char *); // x8
  __int64 v15; // x8
  unsigned int (__fastcall *v16)(__int64, const char *); // x8
  __int64 v17; // x8
  unsigned int (__fastcall *v18)(__int64, const char *); // x8
  __int64 v19; // x8
  unsigned int (__fastcall *v20)(__int64, const char *); // x8
  __int64 v21; // x8
  unsigned int (__fastcall *v22)(__int64, const char *); // x8
  __int64 v23; // x8
  unsigned int (__fastcall *v24)(__int64, const char *); // x8
  __int64 v25; // x8
  unsigned int (__fastcall *v26)(__int64, const char *); // x8
  __int64 v27; // x8
  unsigned int (__fastcall *v28)(__int64, const char *); // x8
  __int64 v29; // x8
  unsigned int (__fastcall *v30)(__int64, const char *); // x8
  __int64 v31; // x8
  __int64 (__fastcall *v32)(__int64, const char *); // x8
  unsigned int v33; // w19
  int v34; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  result = _write_register(a1, 0xA0168u, 3u);
  if ( (_DWORD)result )
    goto LABEL_4;
  result = _write_register_masked(a1, 0xB005Cu, 1, 1);
  if ( (_DWORD)result )
    goto LABEL_4;
  result = _read_register(a1, 0xB0060u, &v34);
  if ( (_DWORD)result )
    goto LABEL_4;
  v3 = 0;
  while ( (v34 & 3) == 2 )
  {
    result = _write_register_masked(a1, 0xB005Cu, 0, 1);
    if ( (_DWORD)result )
      goto LABEL_4;
    usleep_range_state(10, 20, 2);
    result = _write_register_masked(a1, 0xB005Cu, 1, 1);
    if ( (_DWORD)result )
      goto LABEL_4;
    result = _read_register(a1, 0xB0060u, &v34);
    if ( (_DWORD)result )
      goto LABEL_4;
    if ( ++v3 == 1000 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_88C2E, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
      v3 = 1000;
      break;
    }
  }
  if ( (unsigned int)_read_register_with_poll_timeout(a1, 0xB0060u, 1, 1, 0xC8u, 0x7D0u) && (msm_vidc_debug & 1) != 0 )
    printk(&unk_88C2E, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
  result = _write_register_masked(a1, 0xB005Cu, 0, 1);
  if ( (_DWORD)result )
    goto LABEL_4;
  result = _write_register_masked(a1, 0xE002Cu, 1, 1);
  if ( (_DWORD)result )
    goto LABEL_4;
  result = _read_register(a1, 0xE0030u, &v34);
  if ( (_DWORD)result )
    goto LABEL_4;
  v4 = v3 - 1;
  while ( (v34 & 1) == 0 && (v34 & 6) != 0 )
  {
    result = _write_register_masked(a1, 0xE002Cu, 0, 1);
    if ( (_DWORD)result )
      goto LABEL_4;
    usleep_range_state(10, 20, 2);
    result = _write_register_masked(a1, 0xE002Cu, 1, 1);
    if ( (_DWORD)result )
      goto LABEL_4;
    result = _read_register(a1, 0xE0030u, &v34);
    if ( (_DWORD)result )
      goto LABEL_4;
    if ( (unsigned int)++v4 >= 0x3E7 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_905ED, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
      break;
    }
  }
  if ( (unsigned int)_read_register_with_poll_timeout(a1, 0xE0030u, 1, 1, 0xC8u, 0x7D0u) && (msm_vidc_debug & 1) != 0 )
    printk(&unk_905ED, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
  result = _write_register_masked(a1, 0xE002Cu, 0, 1);
  if ( (_DWORD)result )
    goto LABEL_4;
  result = _write_register(a1, 0xB0054u, 0);
  if ( (_DWORD)result )
    goto LABEL_4;
  if ( (unsigned int)_read_register_with_poll_timeout(a1, 0xB0058u, -1, 0, 0xC8u, 0x7D0u) && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_87E37, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
    if ( a1 )
      goto LABEL_37;
LABEL_101:
    result = _write_register_masked(0, 0xE0010u, 1, 1);
    if ( !(_DWORD)result )
    {
      usleep_range_state(400, 500, 2);
      result = 0;
    }
    goto LABEL_4;
  }
  if ( !a1 )
    goto LABEL_101;
LABEL_37:
  v5 = *(_QWORD *)(a1 + 6552);
  if ( v5 )
  {
    v6 = *(unsigned int (__fastcall **)(__int64, const char *))(v5 + 64);
    if ( v6 )
    {
      if ( *((_DWORD *)v6 - 1) != 841426229 )
        __break(0x8228u);
      if ( v6(a1, "iris-ctl") && (msm_vidc_debug & 1) != 0 )
        printk(&unk_975FF, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
    }
  }
  result = _write_register_masked(a1, 0xE0010u, 1, 1);
  if ( !(_DWORD)result )
  {
    v7 = *(_QWORD *)(a1 + 6552);
    if ( !v7 )
      goto LABEL_118;
    v8 = *(unsigned int (__fastcall **)(__int64, const char *))(v7 + 112);
    if ( !v8 )
      goto LABEL_51;
    if ( *((_DWORD *)v8 - 1) != 841426229 )
      __break(0x8228u);
    if ( v8(a1, "gcc_video_axi1_clk") && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_95F7B, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
      v9 = *(_QWORD *)(a1 + 6552);
      if ( !v9 )
        goto LABEL_118;
    }
    else
    {
LABEL_51:
      v9 = *(_QWORD *)(a1 + 6552);
      if ( !v9 )
        goto LABEL_118;
    }
    v10 = *(unsigned int (__fastcall **)(__int64, const char *))(v9 + 112);
    if ( !v10 )
      goto LABEL_57;
    if ( *((_DWORD *)v10 - 1) != 841426229 )
      __break(0x8228u);
    if ( v10(a1, "gcc_video_axi0_clk") && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_942CC, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
      v11 = *(_QWORD *)(a1 + 6552);
      if ( !v11 )
        goto LABEL_118;
    }
    else
    {
LABEL_57:
      v11 = *(_QWORD *)(a1 + 6552);
      if ( !v11 )
        goto LABEL_118;
    }
    v12 = *(unsigned int (__fastcall **)(__int64, const char *))(v11 + 112);
    if ( !v12 )
      goto LABEL_63;
    if ( *((_DWORD *)v12 - 1) != 841426229 )
      __break(0x8228u);
    if ( v12(a1, "video_cc_mvs0c_freerun_clk") && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_87E73, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
      v13 = *(_QWORD *)(a1 + 6552);
      if ( !v13 )
        goto LABEL_118;
    }
    else
    {
LABEL_63:
      v13 = *(_QWORD *)(a1 + 6552);
      if ( !v13 )
        goto LABEL_118;
    }
    v14 = *(unsigned int (__fastcall **)(__int64, const char *))(v13 + 112);
    if ( !v14 )
      goto LABEL_69;
    if ( *((_DWORD *)v14 - 1) != 841426229 )
      __break(0x8228u);
    if ( v14(a1, "video_cc_mvs0_freerun_clk") && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_87EC7, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
      v15 = *(_QWORD *)(a1 + 6552);
      if ( !v15 )
        goto LABEL_118;
    }
    else
    {
LABEL_69:
      v15 = *(_QWORD *)(a1 + 6552);
      if ( !v15 )
        goto LABEL_118;
    }
    v16 = *(unsigned int (__fastcall **)(__int64, const char *))(v15 + 112);
    if ( !v16 )
      goto LABEL_75;
    if ( *((_DWORD *)v16 - 1) != 841426229 )
      __break(0x8228u);
    if ( v16(a1, "video_cc_mvs0c_clk") && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_92B58, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
      v17 = *(_QWORD *)(a1 + 6552);
      if ( !v17 )
        goto LABEL_118;
    }
    else
    {
LABEL_75:
      v17 = *(_QWORD *)(a1 + 6552);
      if ( !v17 )
        goto LABEL_118;
    }
    v18 = *(unsigned int (__fastcall **)(__int64, const char *))(v17 + 32);
    if ( !v18 )
      goto LABEL_81;
    if ( *((_DWORD *)v18 - 1) != 841426229 )
      __break(0x8228u);
    if ( v18(a1, "video_axi1_reset") && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_8B0EE, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
      v19 = *(_QWORD *)(a1 + 6552);
      if ( !v19 )
        goto LABEL_118;
    }
    else
    {
LABEL_81:
      v19 = *(_QWORD *)(a1 + 6552);
      if ( !v19 )
        goto LABEL_118;
    }
    v20 = *(unsigned int (__fastcall **)(__int64, const char *))(v19 + 32);
    if ( !v20 )
      goto LABEL_87;
    if ( *((_DWORD *)v20 - 1) != 841426229 )
      __break(0x8228u);
    if ( v20(a1, "video_axi0_reset") && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_8989C, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
      v21 = *(_QWORD *)(a1 + 6552);
      if ( !v21 )
        goto LABEL_118;
    }
    else
    {
LABEL_87:
      v21 = *(_QWORD *)(a1 + 6552);
      if ( !v21 )
        goto LABEL_118;
    }
    v22 = *(unsigned int (__fastcall **)(__int64, const char *))(v21 + 32);
    if ( !v22 )
      goto LABEL_93;
    if ( *((_DWORD *)v22 - 1) != 841426229 )
      __break(0x8228u);
    if ( v22(a1, "video_mvs0c_freerun_reset") && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_81DDB, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
      v23 = *(_QWORD *)(a1 + 6552);
      if ( !v23 )
        goto LABEL_118;
    }
    else
    {
LABEL_93:
      v23 = *(_QWORD *)(a1 + 6552);
      if ( !v23 )
        goto LABEL_118;
    }
    v24 = *(unsigned int (__fastcall **)(__int64, const char *))(v23 + 32);
    if ( v24 )
    {
      if ( *((_DWORD *)v24 - 1) != 841426229 )
        __break(0x8228u);
      if ( v24(a1, "video_mvs0_freerun_reset") && (msm_vidc_debug & 1) != 0 )
        printk(&unk_94318, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
    }
LABEL_118:
    usleep_range_state(400, 500, 2);
    v25 = *(_QWORD *)(a1 + 6552);
    if ( v25 )
    {
      v26 = *(unsigned int (__fastcall **)(__int64, const char *))(v25 + 40);
      if ( !v26 )
        goto LABEL_124;
      if ( *((_DWORD *)v26 - 1) != 841426229 )
        __break(0x8228u);
      if ( v26(a1, "video_mvs0_freerun_reset") && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_83F59, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
        v27 = *(_QWORD *)(a1 + 6552);
        if ( !v27 )
          goto LABEL_149;
      }
      else
      {
LABEL_124:
        v27 = *(_QWORD *)(a1 + 6552);
        if ( !v27 )
          goto LABEL_149;
      }
      v28 = *(unsigned int (__fastcall **)(__int64, const char *))(v27 + 40);
      if ( !v28 )
        goto LABEL_130;
      if ( *((_DWORD *)v28 - 1) != 841426229 )
        __break(0x8228u);
      if ( v28(a1, "video_mvs0c_freerun_reset") && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_88C7C, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
        v29 = *(_QWORD *)(a1 + 6552);
        if ( !v29 )
          goto LABEL_149;
      }
      else
      {
LABEL_130:
        v29 = *(_QWORD *)(a1 + 6552);
        if ( !v29 )
          goto LABEL_149;
      }
      v30 = *(unsigned int (__fastcall **)(__int64, const char *))(v29 + 40);
      if ( !v30 )
        goto LABEL_136;
      if ( *((_DWORD *)v30 - 1) != 841426229 )
        __break(0x8228u);
      if ( v30(a1, "video_axi0_reset") && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_898DB, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
        v31 = *(_QWORD *)(a1 + 6552);
        if ( !v31 )
          goto LABEL_149;
      }
      else
      {
LABEL_136:
        v31 = *(_QWORD *)(a1 + 6552);
        if ( !v31 )
          goto LABEL_149;
      }
      v32 = *(__int64 (__fastcall **)(__int64, const char *))(v31 + 40);
      if ( v32 )
      {
        if ( *((_DWORD *)v32 - 1) != 841426229 )
          __break(0x8228u);
        result = v32(a1, "video_axi1_reset");
        if ( (_DWORD)result )
        {
          v33 = result;
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_8B12D, "err ", 0xFFFFFFFFLL, "codec", "__power_off_iris4_controller");
          result = v33;
        }
        goto LABEL_4;
      }
    }
LABEL_149:
    result = 0;
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
