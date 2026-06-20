__int64 __fastcall cam_vfe_rdi_handle_irq_bottom_half(int *a1, __int64 a2)
{
  __int64 v3; // x9
  _QWORD *v4; // x24
  int v5; // w12
  int v6; // w21
  int v7; // w26
  __int64 v8; // x25
  void (__fastcall *v9)(__int64, __int64, __int64 *); // x8
  __int64 v10; // x0
  unsigned int v11; // w20
  void (__fastcall *v12)(__int64, __int64, __int64 *); // x8
  __int64 v13; // x0
  __int64 v14; // x8
  int v15; // w26
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x1
  _DWORD *v19; // x8
  int v20; // w8
  _DWORD *v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  _QWORD *v24; // x1
  __int64 v25; // x9
  _QWORD *v26; // x2
  char v27; // w8
  const char *v28; // x5
  __int64 v29; // x1
  __int64 v30; // x2
  __int64 v31; // x4
  __int64 v33; // [xsp+10h] [xbp-40h] BYREF
  int v34; // [xsp+18h] [xbp-38h]
  __int64 v35; // [xsp+20h] [xbp-30h] BYREF
  __int64 v36; // [xsp+28h] [xbp-28h]
  __int64 v37; // [xsp+30h] [xbp-20h]
  __int64 v38; // [xsp+38h] [xbp-18h]
  __int64 *v39; // [xsp+40h] [xbp-10h]
  __int64 v40; // [xsp+48h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = nullptr;
  v36 = 0;
  v37 = 0;
  v35 = 0;
  v34 = 0;
  v33 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_rdi_handle_irq_bottom_half",
      421,
      "Invalid params");
    v11 = -1;
    goto LABEL_54;
  }
  v3 = *((_QWORD *)a1 + 2);
  v4 = *((_QWORD **)a1 + 3);
  HIDWORD(v37) = 2;
  v5 = *a1;
  LODWORD(v3) = *(_DWORD *)(v3 + 4);
  v6 = *(_DWORD *)(a2 + 16);
  v7 = *(_DWORD *)(a2 + 20);
  v8 = *(_QWORD *)(v4[7] + 3296LL);
  LODWORD(v36) = a1[1];
  HIDWORD(v36) = v3;
  LODWORD(v35) = v5;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_rdi_handle_irq_bottom_half",
      440,
      "irq_status_0 = %x",
      v6);
  if ( (*(_DWORD *)(v4[6] + 4LL) & v6) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_rdi_handle_irq_bottom_half",
        443,
        "Received SOF");
    v4[2831] = *(_QWORD *)(a2 + 40);
    v9 = (void (__fastcall *)(__int64, __int64, __int64 *))v4[8];
    v4[2832] = *(_QWORD *)(a2 + 48);
    if ( v9 )
    {
      v10 = v4[9];
      if ( *((_DWORD *)v9 - 1) != 414296116 )
        __break(0x8228u);
      v9(v10, 1, &v35);
    }
    v11 = 0;
  }
  else
  {
    v11 = -1;
  }
  if ( (*(_DWORD *)(v4[6] + 8LL) & v6) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_rdi_handle_irq_bottom_half",
        456,
        "Received REG UPDATE");
      v12 = (void (__fastcall *)(__int64, __int64, __int64 *))v4[8];
      if ( v12 )
        goto LABEL_21;
    }
    else
    {
      v12 = (void (__fastcall *)(__int64, __int64, __int64 *))v4[8];
      if ( v12 )
      {
LABEL_21:
        v13 = v4[9];
        if ( *((_DWORD *)v12 - 1) != 414296116 )
          __break(0x8228u);
        v12(v13, 2, &v35);
      }
    }
    v11 = 0;
  }
  v14 = v4[5];
  if ( !v14 )
    goto LABEL_41;
  v15 = *(_DWORD *)(v14 + 16) & v7;
  if ( !v15 )
    goto LABEL_41;
  v16 = ktime_get_with_offset(1);
  v17 = ns_to_timespec64(v16);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_rdi_handle_irq_bottom_half",
    475,
    "current monotonic timestamp:[%lld.%09lld]",
    v17,
    v18);
  cam_cpas_dump_camnoc_buff_fill_info();
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_rdi_handle_irq_bottom_half",
    480,
    "ife_clk_src:%lld",
    *(_QWORD *)(v8 + 32));
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_rdi_handle_irq_bottom_half",
    486,
    "ERROR timestamp:[%lld.%09lld] SOF timestamp:[%lld.%09lld]",
    v4[2833],
    v4[2834],
    v4[2831],
    v4[2832]);
  v19 = (_DWORD *)v4[5];
  if ( (*v19 & v15) != 0 )
  {
    v20 = 12294;
LABEL_35:
    LODWORD(v36) = v20;
    goto LABEL_36;
  }
  if ( (v19[1] & v15) != 0 )
  {
    v20 = 12295;
    goto LABEL_35;
  }
  if ( (v19[2] & v15) != 0 )
  {
    v20 = 12296;
    goto LABEL_35;
  }
  if ( (v19[3] & v15) != 0 )
  {
    v20 = 12297;
    goto LABEL_35;
  }
LABEL_36:
  v21 = (_DWORD *)v4[8];
  LODWORD(v33) = 1;
  v39 = &v33;
  if ( v21 )
  {
    v22 = v4[9];
    if ( *(v21 - 1) != 414296116 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64 *))v21)(v22, 0, &v35);
  }
  cam_cpas_log_votes(0);
LABEL_41:
  if ( !v4 )
  {
    v28 = "Invalid param core_info NULL";
    v29 = 8;
    v30 = 1;
    v31 = 73;
    goto LABEL_51;
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
  v23 = raw_spin_lock_irqsave(v4 + 2830);
  v24 = (_QWORD *)v4[2829];
  v25 = v23;
  v26 = v4 + 2828;
  if ( v4 + 2828 == (_QWORD *)a2 || v24 == (_QWORD *)a2 || (_QWORD *)*v24 != v26 )
  {
    _list_add_valid_or_report(a2);
  }
  else
  {
    v4[2829] = a2;
    *(_QWORD *)a2 = v26;
    *(_QWORD *)(a2 + 8) = v24;
    *v24 = a2;
  }
  raw_spin_unlock_irqrestore(v4 + 2830, v25);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v28 = "Done";
    v29 = debug_mdl & 8;
    v30 = 4;
    v31 = 87;
LABEL_51:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v29,
      v30,
      "cam_vfe_rdi_put_evt_payload",
      v31,
      v28);
    v27 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_54;
    goto LABEL_52;
  }
  v27 = debug_mdl;
  if ( (debug_mdl & 8) == 0 )
    goto LABEL_54;
LABEL_52:
  if ( !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v27 & 8,
      4,
      "cam_vfe_rdi_handle_irq_bottom_half",
      515,
      "returing status = %d",
      v11);
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return v11;
}
