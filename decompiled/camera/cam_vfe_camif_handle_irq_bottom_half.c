__int64 __fastcall cam_vfe_camif_handle_irq_bottom_half(int *a1, __int64 a2)
{
  __int64 v3; // x9
  __int64 v4; // x26
  int v6; // w11
  int v7; // w21
  int v8; // w22
  __int64 v9; // x27
  void (__fastcall *v10)(__int64, __int64, __int64 *); // x8
  __int64 v11; // x0
  unsigned int v12; // w23
  __int64 v13; // x0
  int v14; // w8
  void (__fastcall *v15)(__int64, __int64, __int64 *); // x8
  __int64 v16; // x0
  void (__fastcall *v17)(__int64, __int64, __int64 *); // x8
  __int64 v18; // x0
  void (__fastcall *v19)(__int64, __int64, __int64 *); // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x1
  _DWORD *v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x1
  _DWORD *v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  _QWORD *v32; // x1
  __int64 v33; // x9
  __int64 v34; // x2
  char v35; // w8
  const char *v36; // x5
  __int64 v37; // x1
  __int64 v38; // x2
  __int64 v39; // x4
  __int64 v41; // [xsp+0h] [xbp-40h] BYREF
  int v42; // [xsp+8h] [xbp-38h]
  __int64 v43; // [xsp+10h] [xbp-30h] BYREF
  __int64 v44; // [xsp+18h] [xbp-28h]
  __int64 v45; // [xsp+20h] [xbp-20h]
  __int64 v46; // [xsp+28h] [xbp-18h]
  __int64 *v47; // [xsp+30h] [xbp-10h]
  __int64 v48; // [xsp+38h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = nullptr;
  v44 = 0;
  v45 = 0;
  v43 = 0;
  v42 = 0;
  v41 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_handle_irq_bottom_half",
      769,
      "Invalid params");
    v12 = 4;
    goto LABEL_93;
  }
  v3 = *((_QWORD *)a1 + 2);
  v4 = *((_QWORD *)a1 + 3);
  HIDWORD(v45) = 2;
  v6 = *a1;
  LODWORD(v3) = *(_DWORD *)(v3 + 4);
  v8 = *(_DWORD *)(a2 + 16);
  v7 = *(_DWORD *)(a2 + 20);
  v9 = *(_QWORD *)(*(_QWORD *)(v4 + 40) + 3296LL);
  LODWORD(v44) = a1[1];
  HIDWORD(v44) = v3;
  LODWORD(v43) = v6;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_handle_irq_bottom_half",
      788,
      "irq_status_0 = 0x%x irq_status_1 = 0x%x",
      v8,
      v7);
  if ( (*(_DWORD *)(*(_QWORD *)(v4 + 32) + 92LL) & v8) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_handle_irq_bottom_half",
        791,
        "Received EOF");
    *(_QWORD *)(v4 + 22720) = *(_QWORD *)(a2 + 40);
    v10 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v4 + 48);
    *(_QWORD *)(v4 + 22728) = *(_QWORD *)(a2 + 48);
    if ( v10 )
    {
      v11 = *(_QWORD *)(v4 + 56);
      if ( *((_DWORD *)v10 - 1) != 414296116 )
        __break(0x8228u);
      v10(v11, 4, &v43);
    }
    v12 = 0;
  }
  else
  {
    v12 = 4;
  }
  if ( (*(_DWORD *)(*(_QWORD *)(v4 + 32) + 80LL) & v8) != 0 )
  {
    if ( *(_BYTE *)(v4 + 22664) == 1 && *(_DWORD *)(v4 + 22668) <= 2u )
    {
      if ( (unsigned int)__ratelimit(&cam_vfe_camif_handle_irq_bottom_half__rs, "cam_vfe_camif_handle_irq_bottom_half") )
        v13 = 3;
      else
        v13 = 2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        v13,
        8,
        3,
        "cam_vfe_camif_handle_irq_bottom_half",
        808,
        "Received SOF");
      v14 = *(_DWORD *)(v4 + 22668) + 1;
      *(_DWORD *)(v4 + 22668) = v14;
      if ( v14 == 2 )
      {
        *(_BYTE *)(v4 + 22664) = 0;
        *(_DWORD *)(v4 + 22668) = 0;
      }
    }
    else
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_camif_handle_irq_bottom_half",
          818,
          "Received SOF");
      *(_QWORD *)(v4 + 22688) = *(_QWORD *)(a2 + 40);
      *(_QWORD *)(v4 + 22696) = *(_QWORD *)(a2 + 48);
    }
    v15 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v4 + 48);
    if ( v15 )
    {
      v16 = *(_QWORD *)(v4 + 56);
      if ( *((_DWORD *)v15 - 1) != 414296116 )
        __break(0x8228u);
      v15(v16, 1, &v43);
    }
    v12 = 0;
  }
  if ( (*(_DWORD *)(*(_QWORD *)(v4 + 32) + 88LL) & v8) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_handle_irq_bottom_half",
        833,
        "Received REG_UPDATE_ACK");
      v17 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v4 + 48);
      if ( v17 )
        goto LABEL_38;
    }
    else
    {
      v17 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v4 + 48);
      if ( v17 )
      {
LABEL_38:
        v18 = *(_QWORD *)(v4 + 56);
        if ( *((_DWORD *)v17 - 1) != 414296116 )
          __break(0x8228u);
        v17(v18, 2, &v43);
      }
    }
    v12 = 0;
  }
  if ( (*(_DWORD *)(*(_QWORD *)(v4 + 32) + 84LL) & v8) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_handle_irq_bottom_half",
        843,
        "Received EPOCH");
    *(_QWORD *)(v4 + 22704) = *(_QWORD *)(a2 + 40);
    v19 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v4 + 48);
    *(_QWORD *)(v4 + 22712) = *(_QWORD *)(a2 + 48);
    if ( v19 )
    {
      v20 = *(_QWORD *)(v4 + 56);
      if ( *((_DWORD *)v19 - 1) != 414296116 )
        __break(0x8228u);
      v19(v20, 3, &v43);
    }
    v12 = 0;
  }
  if ( (*(_DWORD *)(*(_QWORD *)(v4 + 32) + 96LL) & v8) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_handle_irq_bottom_half",
        857,
        "Received ERROR");
    LODWORD(v41) = 1;
    v47 = &v41;
    v21 = ktime_get_with_offset(1);
    v22 = ns_to_timespec64(v21);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_handle_irq_bottom_half",
      864,
      "current monotonic timestamp:[%lld.%09lld]",
      v22,
      v23);
    v24 = *(_DWORD **)(v4 + 48);
    if ( v24 )
    {
      v25 = *(_QWORD *)(v4 + 56);
      if ( *(v24 - 1) != 414296116 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64 *))v24)(v25, 0, &v43);
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_handle_irq_bottom_half",
      871,
      "Violation status = %x",
      *(_DWORD *)(a2 + 24));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_handle_irq_bottom_half",
      876,
      "ife_clk_src:%lld",
      *(_QWORD *)(v9 + 32));
    cam_cpas_log_votes(0);
    if ( (*(_BYTE *)(v4 + 22672) & 2) != 0 )
      cam_vfe_camif_reg_dump(*((_QWORD *)a1 + 3));
    v12 = 1;
  }
  if ( (*(_DWORD *)(*(_QWORD *)(v4 + 32) + 100LL) & v7) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_handle_irq_bottom_half",
        885,
        "Received ERROR");
    LODWORD(v41) = 1;
    v47 = &v41;
    v26 = ktime_get_with_offset(1);
    v27 = ns_to_timespec64(v26);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_handle_irq_bottom_half",
      892,
      "current monotonic timestamp:[%lld.%09lld]",
      v27,
      v28);
    v29 = *(_DWORD **)(v4 + 48);
    if ( v29 )
    {
      v30 = *(_QWORD *)(v4 + 56);
      if ( *(v29 - 1) != 414296116 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64 *))v29)(v30, 0, &v43);
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_handle_irq_bottom_half",
      899,
      "Violation status = %x",
      *(_DWORD *)(a2 + 24));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_handle_irq_bottom_half",
      904,
      "ife_clk_src:%lld",
      *(_QWORD *)(v9 + 32));
    cam_cpas_log_votes(0);
    if ( (*(_BYTE *)(v4 + 22672) & 2) != 0 )
      cam_vfe_camif_reg_dump(*((_QWORD *)a1 + 3));
    v12 = 1;
  }
  if ( (*(_BYTE *)(v4 + 22672) & 1) != 0 )
  {
    cam_io_r(*(_QWORD *)v4 + *(unsigned int *)(*(_QWORD *)(v4 + 16) + 44LL));
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_handle_irq_bottom_half",
        916,
        "VFE_DIAG_SENSOR_STATUS: 0x%x",
        *(_QWORD *)v4);
      if ( v4 )
        goto LABEL_77;
LABEL_89:
      v36 = "Invalid param core_info NULL";
      v37 = 8;
      v38 = 1;
      v39 = 91;
LABEL_90:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        v37,
        v38,
        "cam_vfe_camif_put_evt_payload",
        v39,
        v36);
      v35 = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_93;
      goto LABEL_91;
    }
  }
  if ( !v4 )
    goto LABEL_89;
LABEL_77:
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
  v31 = raw_spin_lock_irqsave(v4 + 22624);
  v32 = *(_QWORD **)(v4 + 22616);
  v33 = v31;
  v34 = v4 + 22608;
  if ( v4 + 22608 == a2 || v32 == (_QWORD *)a2 || *v32 != v34 )
  {
    _list_add_valid_or_report(a2);
  }
  else
  {
    *(_QWORD *)(v4 + 22616) = a2;
    *(_QWORD *)a2 = v34;
    *(_QWORD *)(a2 + 8) = v32;
    *v32 = a2;
  }
  raw_spin_unlock_irqrestore(v4 + 22624, v33);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v36 = "Done";
    v37 = debug_mdl & 8;
    v38 = 4;
    v39 = 105;
    goto LABEL_90;
  }
  v35 = debug_mdl;
  if ( (debug_mdl & 8) == 0 )
    goto LABEL_93;
LABEL_91:
  if ( !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v35 & 8,
      4,
      "cam_vfe_camif_handle_irq_bottom_half",
      921,
      "returning status = %d",
      v12);
LABEL_93:
  _ReadStatusReg(SP_EL0);
  return v12;
}
