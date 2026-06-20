__int64 __fastcall cam_ife_csid_ver2_path_irq_subscribe(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 v4; // x22
  __int64 v5; // x23
  __int64 v6; // x25
  _DWORD *v7; // x26
  _QWORD *v8; // x28
  __int64 v11; // x8
  _QWORD *v12; // x27
  __int64 v13; // x8
  unsigned int v14; // w9
  __int64 v15; // x9
  __int64 v16; // x24
  _DWORD *v17; // x20
  int v18; // w10
  int v19; // w6
  char v20; // w10
  __int64 v21; // x8
  int v22; // w9
  int v23; // w0
  int v24; // w0
  int v25; // w0
  int v26; // w0
  int v27; // w0
  __int64 result; // x0
  unsigned int v29; // w21
  int v30; // [xsp+8h] [xbp-38h]
  unsigned __int64 StatusReg; // [xsp+18h] [xbp-28h]
  __int64 v32; // [xsp+20h] [xbp-20h]
  int v33; // [xsp+2Ch] [xbp-14h] BYREF
  int v34; // [xsp+30h] [xbp-10h] BYREF
  int v35; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+38h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 31136);
  v33 = a4;
  v34 = a3;
  v12 = *(_QWORD **)v11;
  v13 = *(unsigned int *)(*(_QWORD *)v11 + 656LL);
  if ( !(_DWORD)v13 )
    goto LABEL_33;
  v14 = *(_DWORD *)(a2 + 4);
  if ( v14 > 0xB )
    goto LABEL_43;
  v8 = v12 + 17;
  v7 = *(_DWORD **)(a2 + 24);
  LODWORD(v5) = a4;
  v15 = v12[v14 + 17];
  LODWORD(v4) = a3;
  if ( *(_DWORD *)(v15 + 556) )
  {
    v6 = 0;
    goto LABEL_5;
  }
  if ( (_DWORD)v13 == 1 )
  {
LABEL_33:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_path_irq_subscribe",
      5467,
      "csid[%d] %s Invalid top index %s index %d",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      (const char *)(a2 + 128),
      -1,
      v30);
    result = 4294967274LL;
    goto LABEL_46;
  }
  if ( !*(_DWORD *)(v15 + 560) )
  {
    if ( (_DWORD)v13 != 2 )
      goto LABEL_43;
    goto LABEL_33;
  }
  v6 = 1;
LABEL_5:
  v16 = 4LL * *(unsigned int *)(*v12 + 32 * v6);
  v17 = (_DWORD *)vmalloc_noprof(v16);
  if ( !v17 )
  {
LABEL_45:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_path_irq_subscribe",
      5474,
      "csid top_irq_mask allocation failed");
    result = 4294967284LL;
    goto LABEL_46;
  }
  while ( 1 )
  {
    v13 = *(unsigned int *)(a2 + 4);
    if ( (unsigned int)v13 > 0xB )
      goto LABEL_43;
    if ( v16 )
      break;
LABEL_44:
    __break(1u);
    v16 = 4 * v13;
    StatusReg = _ReadStatusReg(SP_EL0);
    v32 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_ife_csid_ver2_path_irq_subscribe__alloc_tag;
    v17 = (_DWORD *)vmalloc_noprof(4 * v13);
    *(_QWORD *)(StatusReg + 80) = v32;
    if ( !v17 )
      goto LABEL_45;
  }
  v18 = *(unsigned __int8 *)(a1 + 2216);
  *v17 = *(_DWORD *)(v8[v13] + 4 * v6 + 556);
  if ( v18 == 1 && *(_DWORD *)(a1 + 2220) == (_DWORD)v13 )
  {
    LODWORD(v4) = v4 | 0x200;
    v19 = *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL);
    v34 = v4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_csid_ver2_path_irq_subscribe",
      5485,
      "CSID[%u] Enabling input EOF for res: %s for perf counter usage",
      v19,
      (const char *)(a2 + 128));
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_path_irq_subscribe",
      5490,
      "Path IRQ masks for CSID[%u] %s, dbg: 0x%x, err: 0x%x",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      (const char *)(a2 + 128),
      v4,
      v5);
  if ( *(_DWORD *)(a2 + 4) != 5 || (*(_BYTE *)(v12[22] + 584LL) & 0x80) == 0 || *(int *)(a1 + 32232) > 0 )
    goto LABEL_20;
  v20 = *(_BYTE *)(a1 + 2164);
  v21 = *(_QWORD *)(**(_QWORD **)(a1 + 31136) + 240LL);
  v22 = *(_DWORD *)(v21 + 20);
  v35 = v22;
  if ( (v20 & 1) == 0 )
    v35 = *(_DWORD *)(v21 + 16) | v22;
  v23 = cam_irq_controller_subscribe_irq(
          *(_QWORD *)(a1 + 8 * v6 + 30984),
          0,
          (__int64)&v35,
          a2,
          (__int64)cam_ife_csid_ver2_mc_top_half,
          (__int64)cam_ife_csid_ver2_ipp_bottom_half,
          *(_QWORD *)(a1 + 32200),
          tasklet_bh_api,
          0);
  *(_DWORD *)(a1 + 32232) = v23;
  if ( v23 >= 1 )
  {
LABEL_20:
    v4 = a1 + 30984;
    v24 = cam_irq_controller_subscribe_irq(
            *(_QWORD *)(a1 + 30984 + 8 * v6),
            0,
            (__int64)v17,
            a2,
            (__int64)cam_ife_csid_ver2_handle_path_irq,
            0,
            0,
            nullptr,
            0);
    v7[51] = v24;
    if ( !v24 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_path_irq_subscribe",
        5513,
        "CSID[%u] subscribe top irq fail %s",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
        (const char *)(a2 + 128));
      v29 = -22;
      goto LABEL_40;
    }
    v13 = *(unsigned int *)(a2 + 4);
    if ( (unsigned int)v13 > 0xB )
      goto LABEL_43;
    v5 = a1 + 31016;
    v25 = cam_irq_controller_register_dependent(
            *(_QWORD *)(v4 + 8 * v6),
            *(_QWORD *)(a1 + 31016 + 8 * v13),
            (__int64)v17);
    if ( v25 )
      goto LABEL_39;
    v13 = *(unsigned int *)(a2 + 4);
    if ( (unsigned int)v13 > 0xB )
      goto LABEL_43;
    v26 = cam_irq_controller_subscribe_irq(
            *(_QWORD *)(v5 + 8 * v13),
            1u,
            (__int64)&v34,
            a2,
            (__int64)cam_ife_csid_ver2_path_top_half,
            (__int64)off_44C5D8[v13],
            *(_QWORD *)(a1 + 32200),
            tasklet_bh_api,
            0);
    v7[52] = v26;
    if ( v26 )
    {
      v13 = *(unsigned int *)(a2 + 4);
      if ( (unsigned int)v13 > 0xB )
        goto LABEL_43;
      v27 = cam_irq_controller_subscribe_irq(
              *(_QWORD *)(v5 + 8 * v13),
              0,
              (__int64)&v33,
              a2,
              (__int64)cam_ife_csid_ver2_path_err_top_half,
              (__int64)off_44C5D8[v13],
              *(_QWORD *)(a1 + 32200),
              tasklet_bh_api,
              0);
      v7[53] = v27;
      if ( v27 )
      {
        vfree(v17);
        result = 0;
        goto LABEL_46;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_path_irq_subscribe",
        5555,
        "CSID[%u] subscribe error irq fail %s",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
        (const char *)(a2 + 128));
      v13 = *(unsigned int *)(a2 + 4);
      if ( (unsigned int)v13 >= 0xC )
      {
LABEL_43:
        __break(0x5512u);
        goto LABEL_44;
      }
      ((void (__fastcall *)(_QWORD, _QWORD))cam_irq_controller_unsubscribe_irq)(
        *(_QWORD *)(v5 + 8 * v13),
        (unsigned int)v7[52]);
      v7[52] = 0;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_path_irq_subscribe",
        5537,
        "CSID[%u] subscribe path irq fail %s",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
        (const char *)(a2 + 128));
    }
    v13 = *(unsigned int *)(a2 + 4);
    if ( (unsigned int)v13 <= 0xB )
    {
      ((void (__fastcall *)(_QWORD, _QWORD))cam_irq_controller_unregister_dependent)(
        *(_QWORD *)(v4 + 8 * v6),
        *(_QWORD *)(v5 + 8 * v13));
      v25 = -22;
LABEL_39:
      v29 = v25;
      ((void (__fastcall *)(_QWORD, _QWORD))cam_irq_controller_unsubscribe_irq)(
        *(_QWORD *)(v4 + 8 * v6),
        (unsigned int)v7[51]);
      v7[51] = 0;
LABEL_40:
      ((void (__fastcall *)(_QWORD, _QWORD))cam_irq_controller_unsubscribe_irq)(
        *(_QWORD *)(v4 + 8 * v6),
        *(unsigned int *)(a1 + 32232));
      *(_DWORD *)(a1 + 32232) = 0;
      goto LABEL_41;
    }
    goto LABEL_43;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver2_mc_irq_subscribe",
    5438,
    "csid[%d] MC subscribe top irq fail %s",
    *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL));
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver2_path_irq_subscribe",
    5498,
    "CSID[%u] Failed to subscribe MC top irq",
    *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
  v29 = -22;
LABEL_41:
  vfree(v17);
  result = v29;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
