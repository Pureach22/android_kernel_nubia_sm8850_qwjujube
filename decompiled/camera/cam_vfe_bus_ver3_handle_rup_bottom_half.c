__int64 __fastcall cam_vfe_bus_ver3_handle_rup_bottom_half(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w20
  __int64 v4; // x8
  int v5; // w6
  char v6; // w9
  __int64 result; // x0
  __int64 v8; // x0
  void (__fastcall *v9)(__int64, __int64, __int64 *); // x8
  __int64 v10; // x0
  void (__fastcall *v11)(__int64, __int64, __int64 *); // x8
  __int64 v12; // x0
  void (__fastcall *v13)(__int64, __int64, __int64 *); // x8
  int v14; // w8
  __int64 v15; // x0
  void (__fastcall *v16)(__int64, __int64, __int64 *); // x8
  __int64 v17; // x0
  void (__fastcall *v18)(__int64, __int64, __int64 *); // x8
  __int64 v19; // x0
  void (__fastcall *v20)(__int64, __int64, __int64 *); // x8
  __int64 v21; // x0
  void (__fastcall *v22)(__int64, __int64, __int64 *); // x8
  __int64 v23; // x9
  __int64 v24; // x0
  void (__fastcall *v25)(__int64, __int64, __int64 *); // x9
  __int64 v26; // [xsp+18h] [xbp-38h] BYREF
  __int64 v27; // [xsp+20h] [xbp-30h]
  __int64 v28; // [xsp+28h] [xbp-28h]
  __int64 v29; // [xsp+30h] [xbp-20h]
  __int64 v30; // [xsp+38h] [xbp-18h]
  _QWORD v31[2]; // [xsp+40h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v26 = 0;
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_handle_rup_bottom_half",
      761,
      "Invalid params");
    result = 0xFFFFFFFFLL;
    goto LABEL_78;
  }
  v2 = *(_QWORD *)(a1 + 24);
  v31[0] = a2;
  if ( !*(_QWORD *)(*(_QWORD *)(v2 + 16) + 34680LL) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_ver3_handle_rup_bottom_half",
      770,
      "VFE:%u Callback to HW MGR not found",
      *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL));
    result = 0xFFFFFFFFLL;
    goto LABEL_78;
  }
  v3 = *(_DWORD *)(a2 + 40);
  HIDWORD(v28) = 2;
  v4 = *(_QWORD *)(v2 + 16);
  LODWORD(v26) = 4;
  v5 = *(_DWORD *)(v4 + 8);
  v6 = *(_BYTE *)(v4 + 34665);
  HIDWORD(v27) = v5;
  if ( (v6 & 1) != 0 )
  {
    if ( (v3 & 1) != 0 )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_handle_rup_bottom_half",
          832,
          "VFE:%u Received RDI0 RUP",
          v5);
        v4 = *(_QWORD *)(v2 + 16);
      }
      v8 = *(_QWORD *)(v2 + 96);
      v9 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v4 + 34680);
      LODWORD(v27) = 3;
      if ( *((_DWORD *)v9 - 1) != 414296116 )
        __break(0x8228u);
      v9(v8, 2, &v26);
      if ( (v3 & 2) == 0 )
      {
LABEL_7:
        if ( (v3 & 4) == 0 )
          goto LABEL_8;
        goto LABEL_28;
      }
    }
    else if ( (v3 & 2) == 0 )
    {
      goto LABEL_7;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_handle_rup_bottom_half",
        841,
        "VFE:%u Received RDI1 RUP",
        HIDWORD(v27));
    v10 = *(_QWORD *)(v2 + 96);
    v11 = *(void (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)(v2 + 16) + 34680LL);
    LODWORD(v27) = 4;
    if ( *((_DWORD *)v11 - 1) != 414296116 )
      __break(0x8228u);
    v11(v10, 2, &v26);
    if ( (v3 & 4) == 0 )
    {
LABEL_8:
      if ( (v3 & 8) == 0 )
        goto LABEL_74;
      goto LABEL_34;
    }
LABEL_28:
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_handle_rup_bottom_half",
        850,
        "VFE:%u Received RDI2 RUP",
        HIDWORD(v27));
    v12 = *(_QWORD *)(v2 + 96);
    v13 = *(void (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)(v2 + 16) + 34680LL);
    LODWORD(v27) = 5;
    if ( *((_DWORD *)v13 - 1) != 414296116 )
      __break(0x8228u);
    v13(v12, 2, &v26);
    if ( (v3 & 8) == 0 )
      goto LABEL_74;
LABEL_34:
    v14 = 6;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_handle_rup_bottom_half",
        859,
        "VFE:%u Received RDI3 RUP",
        HIDWORD(v27));
      v14 = 6;
    }
LABEL_71:
    v23 = *(_QWORD *)(v2 + 16);
    v24 = *(_QWORD *)(v2 + 96);
    LODWORD(v27) = v14;
    v25 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v23 + 34680);
    if ( *((_DWORD *)v25 - 1) != 414296116 )
      __break(0x8229u);
    v25(v24, 2, &v26);
    goto LABEL_74;
  }
  if ( (v3 & 1) != 0 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_handle_rup_bottom_half",
        783,
        "VFE:%u Received CAMIF RUP",
        v5);
      v4 = *(_QWORD *)(v2 + 16);
    }
    v15 = *(_QWORD *)(v2 + 96);
    v16 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v4 + 34680);
    LODWORD(v27) = 0;
    if ( *((_DWORD *)v16 - 1) != 414296116 )
      __break(0x8228u);
    v16(v15, 2, &v26);
    if ( (v3 & 2) == 0 )
    {
LABEL_14:
      if ( (v3 & 4) == 0 )
        goto LABEL_51;
      goto LABEL_49;
    }
  }
  else if ( (v3 & 2) == 0 )
  {
    goto LABEL_14;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_ver3_handle_rup_bottom_half",
      792,
      "VFE:%u Received PDLIB RUP",
      HIDWORD(v27));
  v17 = *(_QWORD *)(v2 + 96);
  v18 = *(void (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)(v2 + 16) + 34680LL);
  LODWORD(v27) = 8;
  if ( *((_DWORD *)v18 - 1) != 414296116 )
    __break(0x8228u);
  v18(v17, 2, &v26);
  if ( (v3 & 4) == 0 )
  {
LABEL_51:
    if ( (v3 & 8) == 0 )
      goto LABEL_52;
    goto LABEL_56;
  }
LABEL_49:
  if ( (debug_mdl & 8) == 0 || debug_priority )
    goto LABEL_51;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_vfe_bus_ver3_handle_rup_bottom_half",
    801,
    "VFE:%u Received LCR RUP",
    HIDWORD(v27));
  if ( (v3 & 8) == 0 )
  {
LABEL_52:
    if ( (v3 & 0x10) == 0 )
      goto LABEL_53;
LABEL_62:
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_handle_rup_bottom_half",
        814,
        "VFE:%u Received RDI1 RUP",
        HIDWORD(v27));
    v21 = *(_QWORD *)(v2 + 96);
    v22 = *(void (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)(v2 + 16) + 34680LL);
    LODWORD(v27) = 4;
    if ( *((_DWORD *)v22 - 1) != 414296116 )
      __break(0x8228u);
    v22(v21, 2, &v26);
    if ( (v3 & 0x20) == 0 )
      goto LABEL_74;
    goto LABEL_68;
  }
LABEL_56:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_ver3_handle_rup_bottom_half",
      805,
      "VFE:%u Received RDI0 RUP",
      HIDWORD(v27));
  v19 = *(_QWORD *)(v2 + 96);
  v20 = *(void (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)(v2 + 16) + 34680LL);
  LODWORD(v27) = 3;
  if ( *((_DWORD *)v20 - 1) != 414296116 )
    __break(0x8228u);
  v20(v19, 2, &v26);
  if ( (v3 & 0x10) != 0 )
    goto LABEL_62;
LABEL_53:
  if ( (v3 & 0x20) != 0 )
  {
LABEL_68:
    v14 = 5;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_bus_ver3_handle_rup_bottom_half",
        823,
        "VFE:%u Received RDI2 RUP",
        HIDWORD(v27));
      v14 = 5;
    }
    goto LABEL_71;
  }
LABEL_74:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_ver3_handle_rup_bottom_half",
      871,
      "VFE:%u Bus RUP IRQ status_0:0x%X rc:%d",
      HIDWORD(v27),
      2,
      v3);
  cam_vfe_bus_ver3_put_evt_payload(*(_QWORD *)(v2 + 16), v31);
  result = 0;
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return result;
}
