__int64 __fastcall cam_vfe_camif_ver3_handle_irq_bottom_half(_DWORD *a1, __int64 *a2)
{
  __int64 v4; // x9
  int v5; // w10
  __int64 v6; // x9
  __int64 *v7; // x20
  int v8; // w27
  unsigned int v9; // w6
  unsigned int v10; // w10
  int v11; // w8
  __int64 v12; // x26
  __int64 v13; // x0
  int v14; // w8
  unsigned int v15; // w22
  void (__fastcall *v16)(__int64, __int64, __int64 *); // x8
  __int64 v17; // x0
  int v18; // w9
  void (__fastcall *v19)(__int64, __int64, __int64 *); // x8
  __int64 v20; // x10
  __int64 v21; // x0
  void (__fastcall *v22)(__int64, __int64, __int64 *); // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 v27; // x6
  _DWORD *v28; // x8
  __int64 v29; // x0
  int v30; // w0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x1
  __int64 v34; // x6
  _DWORD *v35; // x8
  __int64 v36; // x0
  char v37; // w25
  __int64 v38; // x0
  __int64 **v39; // x1
  __int64 v40; // x9
  __int64 *v41; // x2
  char v42; // w8
  const char *v43; // x5
  __int64 v44; // x1
  __int64 v45; // x2
  __int64 v46; // x4
  __int64 v47; // x23
  int v48; // w21
  __int64 v50; // [xsp+8h] [xbp-58h] BYREF
  int v51; // [xsp+10h] [xbp-50h]
  __int64 v52; // [xsp+18h] [xbp-48h] BYREF
  unsigned __int64 v53; // [xsp+20h] [xbp-40h]
  __int64 v54; // [xsp+28h] [xbp-38h]
  __int64 v55; // [xsp+30h] [xbp-30h]
  __int64 *v56; // [xsp+38h] [xbp-28h]
  __int64 v57; // [xsp+40h] [xbp-20h] BYREF
  __int64 v58; // [xsp+48h] [xbp-18h]
  int v59; // [xsp+50h] [xbp-10h]
  __int64 v60; // [xsp+58h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  v56 = nullptr;
  v53 = 0;
  v54 = 0;
  v52 = 0;
  v51 = 0;
  v50 = 0;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_handle_irq_bottom_half",
      1373,
      "Invalid params handle_priv:%pK, evt_payload_priv:%pK",
      a1,
      a2);
    v15 = -1;
    goto LABEL_79;
  }
  v4 = a2[3];
  v5 = *((_DWORD *)a2 + 8);
  v57 = a2[2];
  v58 = v4;
  v6 = *((_QWORD *)a1 + 2);
  v7 = *((__int64 **)a1 + 3);
  v59 = v5;
  v8 = HIDWORD(v57);
  HIDWORD(v54) = 2;
  v9 = *(_DWORD *)(v6 + 4);
  v10 = a1[1];
  v11 = *(_DWORD *)(v7[4] + 60);
  v12 = *(_QWORD *)(v7[5] + 3296);
  LODWORD(v52) = *a1;
  v53 = __PAIR64__(v9, v10);
  v54 = 0x200000000LL;
  if ( (v11 & HIDWORD(v57)) != 0 )
  {
    if ( *((_BYTE *)v7 + 22720) == 1 && *((_DWORD *)v7 + 5681) <= 2u )
    {
      if ( (unsigned int)__ratelimit(
                           &cam_vfe_camif_ver3_handle_irq_bottom_half__rs,
                           "cam_vfe_camif_ver3_handle_irq_bottom_half") )
        v13 = 3;
      else
        v13 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v13,
        8,
        3,
        "cam_vfe_camif_ver3_handle_irq_bottom_half",
        1401,
        "VFE:%d Received SOF",
        HIDWORD(v53));
      v14 = *((_DWORD *)v7 + 5681) + 1;
      *((_DWORD *)v7 + 5681) = v14;
      if ( v14 == 2 )
      {
        *((_BYTE *)v7 + 22720) = 0;
        *((_DWORD *)v7 + 5681) = 0;
      }
    }
    else
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_camif_ver3_handle_irq_bottom_half",
          1412,
          "VFE:%d Received SOF",
          v9);
      v7[2844] = a2[5];
      v7[2845] = a2[6];
    }
    v16 = (void (__fastcall *)(__int64, __int64, __int64 *))v7[12];
    if ( v16 )
    {
      v17 = v7[13];
      if ( *((_DWORD *)v16 - 1) != 414296116 )
        __break(0x8228u);
      v16(v17, 1, &v52);
    }
    v15 = 0;
  }
  else
  {
    v15 = -1;
  }
  if ( (*(_DWORD *)(v7[4] + 64) & v8) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_ver3_handle_irq_bottom_half",
        1428,
        "VFE:%d Received EPOCH",
        HIDWORD(v53));
    v18 = *((_DWORD *)a2 + 9);
    v7[2846] = a2[5];
    v19 = (void (__fastcall *)(__int64, __int64, __int64 *))v7[12];
    v20 = a2[6];
    LODWORD(v54) = v18;
    v7[2847] = v20;
    if ( v19 )
    {
      v21 = v7[13];
      if ( *((_DWORD *)v19 - 1) != 414296116 )
        __break(0x8228u);
      v19(v21, 3, &v52);
    }
    v15 = 0;
  }
  if ( (*(_DWORD *)(v7[4] + 72) & v8) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_ver3_handle_irq_bottom_half",
        1444,
        "VFE:%d Received EOF",
        HIDWORD(v53));
    v7[2848] = a2[5];
    v22 = (void (__fastcall *)(__int64, __int64, __int64 *))v7[12];
    v7[2849] = a2[6];
    if ( v22 )
    {
      v23 = v7[13];
      if ( *((_DWORD *)v22 - 1) != 414296116 )
        __break(0x8228u);
      v22(v23, 4, &v52);
    }
    v15 = 0;
  }
  if ( (*(_DWORD *)(v7[4] + 76) & (unsigned int)v57) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_handle_irq_bottom_half",
      1459,
      "VFE:%d Overflow",
      HIDWORD(v53));
    v24 = ktime_get_with_offset(1);
    v25 = ns_to_timespec64(v24);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_handle_irq_bottom_half",
      1464,
      "current monotonic timestamp:[%lld.%09lld]",
      v25,
      v26);
    v56 = &v50;
    v27 = *(_QWORD *)(v12 + 32);
    LODWORD(v50) = 1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_handle_irq_bottom_half",
      1471,
      "ife_clk_src:%lld",
      v27);
    cam_vfe_camif_ver3_print_status(&v57, 1, v7);
    if ( (v7[2841] & 2) != 0 )
      cam_vfe_camif_ver3_reg_dump(a1);
    v28 = (_DWORD *)v7[12];
    if ( v28 )
    {
      v29 = v7[13];
      if ( *(v28 - 1) != 414296116 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64 *))v28)(v29, 0, &v52);
    }
    v15 = 1;
  }
  if ( (*(_DWORD *)(v7[4] + 88) & (unsigned int)v57) != 0
    && (v30 = cam_io_r_mb(*v7 + *(unsigned int *)(v7[3] + 72)), (debug_mdl & 8) != 0)
    && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_ver3_handle_irq_bottom_half",
      1489,
      "VFE:%d Frame id change to: %u",
      HIDWORD(v53),
      v30);
    if ( !(_DWORD)v58 )
      goto LABEL_59;
  }
  else if ( !(_DWORD)v58 )
  {
    goto LABEL_59;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_camif_ver3_handle_irq_bottom_half",
    1493,
    "VFE:%d Violation",
    HIDWORD(v53));
  v31 = ktime_get_with_offset(1);
  v32 = ns_to_timespec64(v31);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_handle_irq_bottom_half",
    1498,
    "current monotonic timestamp:[%lld.%09lld]",
    v32,
    v33);
  v56 = &v50;
  v34 = *(_QWORD *)(v12 + 32);
  LODWORD(v50) = 3;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_handle_irq_bottom_half",
    1505,
    "ife_clk_src:%lld",
    v34);
  cam_vfe_camif_ver3_print_status(&v57, 3, v7);
  if ( (v7[2841] & 2) != 0 )
    cam_vfe_camif_ver3_reg_dump(a1);
  v35 = (_DWORD *)v7[12];
  if ( v35 )
  {
    v36 = v7[13];
    if ( *(v35 - 1) != 414296116 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64 *))v35)(v36, 0, &v52);
  }
  v15 = 3;
LABEL_59:
  if ( (v7[2841] & 1) != 0 )
  {
    v37 = debug_mdl;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v47 = *v7;
      v48 = HIDWORD(v53);
      cam_io_r(*v7 + *(unsigned int *)(v7[3] + 84));
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v37 & 8,
        4,
        "cam_vfe_camif_ver3_handle_irq_bottom_half",
        1521,
        "VFE:%d VFE_DIAG_SENSOR_STATUS: 0x%X",
        v48,
        v47);
      if ( v7 )
        goto LABEL_63;
LABEL_75:
      v43 = "Invalid param core_info NULL";
      v44 = 8;
      v45 = 1;
      v46 = 98;
LABEL_76:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        v44,
        v45,
        "cam_vfe_camif_ver3_put_evt_payload",
        v46,
        v43);
      v42 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_79;
      goto LABEL_77;
    }
  }
  if ( !v7 )
    goto LABEL_75;
LABEL_63:
  a2[9] = 0;
  a2[10] = 0;
  a2[7] = 0;
  a2[8] = 0;
  a2[5] = 0;
  a2[6] = 0;
  a2[3] = 0;
  a2[4] = 0;
  a2[1] = 0;
  a2[2] = 0;
  *a2 = 0;
  v38 = raw_spin_lock_irqsave(v7 + 2835);
  v39 = (__int64 **)v7[2834];
  v40 = v38;
  v41 = v7 + 2833;
  if ( v7 + 2833 == a2 || v39 == (__int64 **)a2 || *v39 != v41 )
  {
    _list_add_valid_or_report(a2);
  }
  else
  {
    v7[2834] = (__int64)a2;
    *a2 = (__int64)v41;
    a2[1] = (__int64)v39;
    *v39 = a2;
  }
  raw_spin_unlock_irqrestore(v7 + 2835, v40);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v43 = "Done";
    v44 = debug_mdl & 8;
    v45 = 4;
    v46 = 112;
    goto LABEL_76;
  }
  v42 = debug_mdl;
  if ( (debug_mdl & 8) == 0 )
    goto LABEL_79;
LABEL_77:
  if ( !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v42 & 8,
      4,
      "cam_vfe_camif_ver3_handle_irq_bottom_half",
      1526,
      "returning status = %d",
      v15);
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return v15;
}
