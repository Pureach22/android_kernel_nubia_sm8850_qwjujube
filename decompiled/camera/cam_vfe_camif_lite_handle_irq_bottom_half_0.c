__int64 __fastcall cam_vfe_camif_lite_handle_irq_bottom_half_0(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v5; // x25
  __int64 v6; // x8
  __int64 v7; // x9
  int v8; // w10
  __int64 v9; // x8
  unsigned int v10; // w7
  unsigned int v11; // w6
  int v12; // w26
  void (__fastcall *v13)(__int64, __int64, __int64 *); // x8
  __int64 v14; // x0
  unsigned int v15; // w22
  void (__fastcall *v16)(__int64, __int64, __int64 *); // x8
  __int64 v17; // x0
  void (__fastcall *v18)(__int64, __int64, __int64 *); // x8
  __int64 v19; // x0
  int v20; // w26
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x1
  int v24; // w8
  _DWORD *v25; // x8
  __int64 v26; // x0
  _DWORD *v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x2
  _QWORD *v31; // x1
  __int64 v32; // x9
  char v33; // w8
  const char *v34; // x5
  __int64 v35; // x1
  __int64 v36; // x2
  __int64 v37; // x4
  __int64 v39; // [xsp+28h] [xbp-58h] BYREF
  int v40; // [xsp+30h] [xbp-50h]
  __int64 v41; // [xsp+38h] [xbp-48h] BYREF
  unsigned __int64 v42; // [xsp+40h] [xbp-40h]
  __int64 v43; // [xsp+48h] [xbp-38h]
  __int64 v44; // [xsp+50h] [xbp-30h]
  __int64 *v45; // [xsp+58h] [xbp-28h]
  __int64 v46; // [xsp+60h] [xbp-20h] BYREF
  __int64 v47; // [xsp+68h] [xbp-18h]
  int v48; // [xsp+70h] [xbp-10h]
  __int64 v49; // [xsp+78h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  v45 = nullptr;
  v42 = 0;
  v43 = 0;
  v41 = 0;
  v40 = 0;
  v39 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      1089,
      "Invalid params");
    v15 = 4;
    goto LABEL_73;
  }
  v3 = *(_QWORD *)(a1 + 24);
  v5 = *(_QWORD *)(*(_QWORD *)(v3 + 40) + 3296LL);
  if ( !v5 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      1099,
      "Invalid soc_private");
    v15 = -19;
    goto LABEL_73;
  }
  v6 = *(_QWORD *)(a2 + 16);
  v7 = *(_QWORD *)(a2 + 24);
  v8 = *(_DWORD *)(a2 + 32);
  HIDWORD(v43) = 2;
  v46 = v6;
  v47 = v7;
  v9 = *(_QWORD *)(a1 + 16);
  v48 = v8;
  LODWORD(v7) = *(_DWORD *)a1;
  v10 = *(_DWORD *)(a1 + 4);
  v11 = *(_DWORD *)(v9 + 4);
  HIDWORD(v43) = 2;
  v42 = __PAIR64__(v11, v10);
  LODWORD(v41) = v7;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v12 = HIDWORD(v46);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      1117,
      "VFE:%d CAMIF LITE:%d %s IRQ status_0: 0x%X status_1: 0x%X status_2: 0x%X",
      v11,
      v10,
      (const char *)(a1 + 128),
      v46,
      HIDWORD(v46),
      v47);
  }
  else
  {
    v12 = HIDWORD(v46);
  }
  if ( (*(_DWORD *)(*(_QWORD *)(v3 + 32) + 20LL) & v12) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_lite_handle_irq_bottom_half",
        1123,
        "VFE:%d CAMIF LITE:%d %s Received SOF",
        HIDWORD(v42),
        v42,
        (const char *)(a1 + 128));
    *(_QWORD *)(v3 + 22688) = *(_QWORD *)(a2 + 40);
    v13 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v3 + 96);
    *(_QWORD *)(v3 + 22696) = *(_QWORD *)(a2 + 48);
    if ( v13 )
    {
      v14 = *(_QWORD *)(v3 + 104);
      if ( *((_DWORD *)v13 - 1) != 414296116 )
        __break(0x8228u);
      v13(v14, 1, &v41);
    }
    v15 = 0;
  }
  else
  {
    v15 = 4;
  }
  if ( (*(_DWORD *)(*(_QWORD *)(v3 + 32) + 24LL) & v12) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_lite_handle_irq_bottom_half",
        1139,
        "VFE:%d CAMIF LITE:%d %s Received EPOCH",
        HIDWORD(v42),
        v42,
        (const char *)(a1 + 128));
    *(_QWORD *)(v3 + 22704) = *(_QWORD *)(a2 + 40);
    v16 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v3 + 96);
    *(_QWORD *)(v3 + 22712) = *(_QWORD *)(a2 + 48);
    if ( v16 )
    {
      v17 = *(_QWORD *)(v3 + 104);
      if ( *((_DWORD *)v16 - 1) != 414296116 )
        __break(0x8228u);
      v16(v17, 3, &v41);
    }
    v15 = 0;
  }
  if ( (*(_DWORD *)(*(_QWORD *)(v3 + 32) + 32LL) & v12) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_lite_handle_irq_bottom_half",
        1155,
        "VFE:%d CAMIF LITE:%d %s Received EOF",
        HIDWORD(v42),
        v42,
        (const char *)(a1 + 128));
    *(_QWORD *)(v3 + 22720) = *(_QWORD *)(a2 + 40);
    v18 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v3 + 96);
    *(_QWORD *)(v3 + 22728) = *(_QWORD *)(a2 + 48);
    if ( v18 )
    {
      v19 = *(_QWORD *)(v3 + 104);
      if ( *((_DWORD *)v18 - 1) != 414296116 )
        __break(0x8228u);
      v18(v19, 4, &v41);
    }
    v15 = 0;
  }
  v20 = *(_DWORD *)(*(_QWORD *)(v3 + 32) + 36LL) & v46;
  if ( v20 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      1171,
      "VFE:%d Overflow",
      *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL));
    LODWORD(v39) = 1;
    v45 = &v39;
    v21 = ktime_get_with_offset(1);
    v22 = ns_to_timespec64(v21);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      1178,
      "current monotonic timestamp:[%lld.%09lld]",
      v22,
      v23);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      1182,
      "ERROR timestamp:[%lld.%09lld]",
      *(_QWORD *)(v3 + 22736),
      *(_QWORD *)(v3 + 22744));
    if ( *(_BYTE *)(a1 + 144) == 1 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_handle_irq_bottom_half",
        1192,
        "SOF timestamp:[%lld.%09lld] EPOCH timestamp:[%lld.%09lld] EOF timestamp:[%lld.%09lld]",
        *(_QWORD *)(v3 + 22688),
        *(_QWORD *)(v3 + 22696),
        *(_QWORD *)(v3 + 22704),
        *(_QWORD *)(v3 + 22712),
        *(_QWORD *)(v3 + 22720),
        *(_QWORD *)(v3 + 22728));
    if ( (v20 & 0x38000000) != 0 )
    {
      if ( (v20 & 0x10000000) != 0 )
        v24 = 12295;
      else
        v24 = 12296;
      if ( (v20 & 0x20000000) != 0 )
        v24 = 12294;
      LODWORD(v42) = v24;
    }
    v25 = *(_DWORD **)(v3 + 96);
    if ( v25 )
    {
      v26 = *(_QWORD *)(v3 + 104);
      if ( *(v25 - 1) != 414296116 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64 *))v25)(v26, 0, &v41);
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      1210,
      "ife_clk_src:%lld",
      *(_QWORD *)(v5 + 32));
    v15 = 1;
    cam_vfe_camif_lite_print_status(&v46, 1, v3);
    if ( (*(_BYTE *)(v3 + 156) & 2) != 0 )
      cam_vfe_camif_lite_reg_dump(a1);
  }
  if ( (_DWORD)v47 )
  {
    v15 = 3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      1221,
      "VFE:%d Violation",
      *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL));
    v27 = *(_DWORD **)(v3 + 96);
    LODWORD(v39) = 3;
    v45 = &v39;
    if ( v27 )
    {
      v28 = *(_QWORD *)(v3 + 104);
      if ( *(v27 - 1) != 414296116 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64 *))v27)(v28, 0, &v41);
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      1233,
      "ife_clk_src:%lld",
      *(_QWORD *)(v5 + 32));
    cam_vfe_camif_lite_print_status(&v46, 3, v3);
    if ( (*(_BYTE *)(v3 + 156) & 2) != 0 )
      cam_vfe_camif_lite_reg_dump(a1);
  }
  if ( !v3 )
  {
    v34 = "Invalid param core_info NULL";
    v35 = 8;
    v36 = 1;
    v37 = 80;
    goto LABEL_70;
  }
  *(_QWORD *)(a2 + 72) = 0;
  *(_QWORD *)(a2 + 80) = 0;
  *(_QWORD *)(a2 + 56) = 0;
  *(_QWORD *)(a2 + 64) = 0;
  *(_QWORD *)(a2 + 40) = 0;
  *(_QWORD *)(a2 + 48) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)(a2 + 32) = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)a2 = 0;
  v29 = raw_spin_lock_irqsave(v3 + 152);
  v30 = v3 + 136;
  v31 = *(_QWORD **)(v3 + 144);
  v32 = v29;
  if ( v3 + 136 == a2 || v31 == (_QWORD *)a2 || *v31 != v30 )
  {
    _list_add_valid_or_report(a2);
  }
  else
  {
    *(_QWORD *)(v3 + 144) = a2;
    *(_QWORD *)a2 = v30;
    *(_QWORD *)(a2 + 8) = v31;
    *v31 = a2;
  }
  raw_spin_unlock_irqrestore(v3 + 152, v32);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v34 = "Done";
    v35 = debug_mdl & 8;
    v36 = 4;
    v37 = 94;
LABEL_70:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v35,
      v36,
      "cam_vfe_camif_lite_put_evt_payload",
      v37,
      v34);
    v33 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_73;
    goto LABEL_71;
  }
  v33 = debug_mdl;
  if ( (debug_mdl & 8) == 0 )
    goto LABEL_73;
LABEL_71:
  if ( !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v33 & 8,
      4,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      1244,
      "returning status = %d",
      v15);
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return v15;
}
