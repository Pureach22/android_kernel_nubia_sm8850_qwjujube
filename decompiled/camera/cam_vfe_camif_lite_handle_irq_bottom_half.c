__int64 __fastcall cam_vfe_camif_lite_handle_irq_bottom_half(int *a1, __int64 a2)
{
  __int64 v3; // x8
  _QWORD *v4; // x26
  int v5; // w11
  int v6; // w20
  int v7; // w22
  int v8; // w23
  __int64 v9; // x27
  _DWORD *v10; // x8
  unsigned int v11; // w21
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x1
  _DWORD *v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  _QWORD *v18; // x1
  __int64 v19; // x9
  _QWORD *v20; // x2
  char v21; // w8
  const char *v22; // x5
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x4
  __int64 v27; // [xsp+0h] [xbp-40h] BYREF
  int v28; // [xsp+8h] [xbp-38h]
  __int64 v29; // [xsp+10h] [xbp-30h] BYREF
  __int64 v30; // [xsp+18h] [xbp-28h]
  __int64 v31; // [xsp+20h] [xbp-20h]
  __int64 v32; // [xsp+28h] [xbp-18h]
  __int64 *v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v33 = nullptr;
  v30 = 0;
  v31 = 0;
  v29 = 0;
  v28 = 0;
  v27 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      438,
      "Invalid params");
    v11 = 4;
    goto LABEL_47;
  }
  v3 = *((_QWORD *)a1 + 2);
  v4 = *((_QWORD **)a1 + 3);
  HIDWORD(v31) = 2;
  v5 = *a1;
  v6 = *(_DWORD *)(v3 + 4);
  v8 = *(_DWORD *)(a2 + 16);
  v7 = *(_DWORD *)(a2 + 20);
  v9 = *(_QWORD *)(v4[5] + 3296LL);
  LODWORD(v30) = a1[1];
  HIDWORD(v30) = v6;
  LODWORD(v29) = v5;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      457,
      "irq_status_0 = 0x%x irq_status_1 = 0x%x",
      v8,
      v7);
  v10 = (_DWORD *)v4[4];
  if ( (v10[2] & v8) != 0 )
  {
    v11 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_lite_handle_irq_bottom_half",
        461,
        "VFE:%d CAMIF Lite Received SOF",
        v6);
      v10 = (_DWORD *)v4[4];
      v11 = 0;
    }
  }
  else
  {
    v11 = 4;
  }
  if ( (v10[3] & v8) != 0 )
  {
    v11 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_lite_handle_irq_bottom_half",
        467,
        "VFE:%d CAMIF Lite Received EPOCH",
        v6);
      v10 = (_DWORD *)v4[4];
      v11 = 0;
    }
  }
  if ( (v10[4] & v8) != 0 )
  {
    v11 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_lite_handle_irq_bottom_half",
        473,
        "VFE:%d CAMIF Lite Received REG_UPDATE_ACK",
        v6);
      v10 = (_DWORD *)v4[4];
      v11 = 0;
    }
  }
  if ( (v10[5] & v8) != 0 )
  {
    v11 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_lite_handle_irq_bottom_half",
        479,
        "VFE:%d CAMIF Lite Received EOF",
        v6);
      v10 = (_DWORD *)v4[4];
      v11 = 0;
    }
  }
  if ( (v10[6] & v8) != 0 || (v10[7] & v7) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_lite_handle_irq_bottom_half",
        486,
        "VFE:%d CAMIF LITE Received ERROR",
        v6);
    LODWORD(v27) = 1;
    v33 = &v27;
    cam_cpas_dump_camnoc_buff_fill_info();
    v12 = ktime_get_with_offset(1);
    v13 = ns_to_timespec64(v12);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      496,
      "current monotonic timestamp:[%lld.%09lld]",
      v13,
      v14);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      500,
      "ERROR timestamp:[%lld.%09lld]",
      v4[2830],
      v4[2831]);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      502,
      "ife_clk_src:%lld",
      *(_QWORD *)(v9 + 32));
    v15 = (_DWORD *)v4[7];
    if ( v15 )
    {
      v16 = v4[8];
      if ( *(v15 - 1) != 414296116 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64 *))v15)(v16, 0, &v29);
    }
    cam_cpas_log_votes(0);
    v11 = 1;
  }
  if ( !v4 )
  {
    v22 = "Invalid param core_info NULL";
    v23 = 8;
    v24 = 1;
    v25 = 73;
    goto LABEL_44;
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
  v17 = raw_spin_lock_irqsave(v4 + 2829);
  v18 = (_QWORD *)v4[2828];
  v19 = v17;
  v20 = v4 + 2827;
  if ( v4 + 2827 == (_QWORD *)a2 || v18 == (_QWORD *)a2 || (_QWORD *)*v18 != v20 )
  {
    _list_add_valid_or_report(a2);
  }
  else
  {
    v4[2828] = a2;
    *(_QWORD *)a2 = v20;
    *(_QWORD *)(a2 + 8) = v18;
    *v18 = a2;
  }
  raw_spin_unlock_irqrestore(v4 + 2829, v19);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v22 = "Done";
    v23 = debug_mdl & 8;
    v24 = 4;
    v25 = 87;
LABEL_44:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v23,
      v24,
      "cam_vfe_camif_lite_put_evt_payload",
      v25,
      v22);
    v21 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_47;
    goto LABEL_45;
  }
  v21 = debug_mdl;
  if ( (debug_mdl & 8) == 0 )
    goto LABEL_47;
LABEL_45:
  if ( !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v21 & 8,
      4,
      "cam_vfe_camif_lite_handle_irq_bottom_half",
      516,
      "returning status = %d",
      v11);
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return v11;
}
