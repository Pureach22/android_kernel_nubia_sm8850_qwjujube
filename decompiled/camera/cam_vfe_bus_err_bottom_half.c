__int64 __fastcall cam_vfe_bus_err_bottom_half(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v4; // w20
  int v5; // w11
  _DWORD *v6; // x8
  __int64 v7; // [xsp+8h] [xbp-48h] BYREF
  int v8; // [xsp+10h] [xbp-40h]
  __int64 v9; // [xsp+18h] [xbp-38h] BYREF
  __int64 v10; // [xsp+20h] [xbp-30h]
  __int64 v11; // [xsp+28h] [xbp-28h]
  __int64 v12; // [xsp+30h] [xbp-20h]
  __int64 *v13; // [xsp+38h] [xbp-18h]
  _QWORD *v14[2]; // [xsp+40h] [xbp-10h] BYREF

  result = 4294967274LL;
  v14[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
    goto LABEL_33;
  v4 = *(_DWORD *)(a2 + 20);
  v14[0] = (_QWORD *)a2;
  v12 = 0;
  v13 = nullptr;
  v10 = 0;
  v11 = 0;
  v9 = 0;
  v7 = 0;
  v8 = 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_bus_err_bottom_half",
    1395,
    "Bus Violation: debug_status_0 = 0x%x",
    v4);
  if ( (v4 & 1) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_bus_err_bottom_half",
      1398,
      "RDI 0 violation");
    if ( (v4 & 2) == 0 )
    {
LABEL_5:
      if ( (v4 & 4) == 0 )
        goto LABEL_6;
      goto LABEL_36;
    }
  }
  else if ( (v4 & 2) == 0 )
  {
    goto LABEL_5;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1401,
    "RDI 1 violation");
  if ( (v4 & 4) == 0 )
  {
LABEL_6:
    if ( (v4 & 8) == 0 )
      goto LABEL_7;
    goto LABEL_37;
  }
LABEL_36:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1404,
    "RDI 2 violation");
  if ( (v4 & 8) == 0 )
  {
LABEL_7:
    if ( (v4 & 0x10) == 0 )
      goto LABEL_8;
    goto LABEL_38;
  }
LABEL_37:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1407,
    "VID Y 1:1 UBWC violation");
  if ( (v4 & 0x10) == 0 )
  {
LABEL_8:
    if ( (v4 & 0x20) == 0 )
      goto LABEL_9;
    goto LABEL_39;
  }
LABEL_38:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1410,
    "VID C 1:1 UBWC violation");
  if ( (v4 & 0x20) == 0 )
  {
LABEL_9:
    if ( (v4 & 0x40) == 0 )
      goto LABEL_10;
    goto LABEL_40;
  }
LABEL_39:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1413,
    "VID YC 4:1 violation");
  if ( (v4 & 0x40) == 0 )
  {
LABEL_10:
    if ( (v4 & 0x80) == 0 )
      goto LABEL_11;
    goto LABEL_41;
  }
LABEL_40:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1416,
    "VID YC 16:1 violation");
  if ( (v4 & 0x80) == 0 )
  {
LABEL_11:
    if ( (v4 & 0x100) == 0 )
      goto LABEL_12;
    goto LABEL_42;
  }
LABEL_41:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1419,
    "FD Y violation");
  if ( (v4 & 0x100) == 0 )
  {
LABEL_12:
    if ( (v4 & 0x200) == 0 )
      goto LABEL_13;
    goto LABEL_43;
  }
LABEL_42:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1422,
    "FD C violation");
  if ( (v4 & 0x200) == 0 )
  {
LABEL_13:
    if ( (v4 & 0x400) == 0 )
      goto LABEL_14;
    goto LABEL_44;
  }
LABEL_43:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1425,
    "RAW DUMP violation");
  if ( (v4 & 0x400) == 0 )
  {
LABEL_14:
    if ( (v4 & 0x800) == 0 )
      goto LABEL_15;
    goto LABEL_45;
  }
LABEL_44:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1428,
    "PDAF violation");
  if ( (v4 & 0x800) == 0 )
  {
LABEL_15:
    if ( (v4 & 0x1000) == 0 )
      goto LABEL_16;
    goto LABEL_46;
  }
LABEL_45:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1431,
    "STATs HDR BE violation");
  if ( (v4 & 0x1000) == 0 )
  {
LABEL_16:
    if ( (v4 & 0x2000) == 0 )
      goto LABEL_17;
    goto LABEL_47;
  }
LABEL_46:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1434,
    "STATs HDR BHIST violation");
  if ( (v4 & 0x2000) == 0 )
  {
LABEL_17:
    if ( (v4 & 0x4000) == 0 )
      goto LABEL_18;
    goto LABEL_48;
  }
LABEL_47:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1437,
    "STATs TINTLESS BG violation");
  if ( (v4 & 0x4000) == 0 )
  {
LABEL_18:
    if ( (v4 & 0x8000) == 0 )
      goto LABEL_19;
    goto LABEL_49;
  }
LABEL_48:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1440,
    "STATs BF violation");
  if ( (v4 & 0x8000) == 0 )
  {
LABEL_19:
    if ( (v4 & 0x10000) == 0 )
      goto LABEL_20;
    goto LABEL_50;
  }
LABEL_49:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1443,
    "STATs AWB BG UBWC violation");
  if ( (v4 & 0x10000) == 0 )
  {
LABEL_20:
    if ( (v4 & 0x20000) == 0 )
      goto LABEL_21;
    goto LABEL_51;
  }
LABEL_50:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1446,
    "STATs BHIST violation");
  if ( (v4 & 0x20000) == 0 )
  {
LABEL_21:
    if ( (v4 & 0x40000) == 0 )
      goto LABEL_22;
    goto LABEL_52;
  }
LABEL_51:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1449,
    "STATs RS violation");
  if ( (v4 & 0x40000) == 0 )
  {
LABEL_22:
    if ( (v4 & 0x80000) == 0 )
      goto LABEL_23;
    goto LABEL_53;
  }
LABEL_52:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1452,
    "STATs CS violation");
  if ( (v4 & 0x80000) == 0 )
  {
LABEL_23:
    if ( (v4 & 0x100000) == 0 )
      goto LABEL_24;
    goto LABEL_54;
  }
LABEL_53:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1455,
    "STATs IHIST violation");
  if ( (v4 & 0x100000) == 0 )
  {
LABEL_24:
    if ( (v4 & 0x200000) == 0 )
      goto LABEL_25;
    goto LABEL_55;
  }
LABEL_54:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1458,
    "DISP Y 1:1 UBWC violation");
  if ( (v4 & 0x200000) == 0 )
  {
LABEL_25:
    if ( (v4 & 0x400000) == 0 )
      goto LABEL_26;
LABEL_56:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_bus_err_bottom_half",
      1464,
      "DISP YC 4:1 violation");
    if ( (v4 & 0x800000) == 0 )
      goto LABEL_28;
    goto LABEL_27;
  }
LABEL_55:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_err_bottom_half",
    1461,
    "DISP C 1:1 UBWC violation");
  if ( (v4 & 0x400000) != 0 )
    goto LABEL_56;
LABEL_26:
  if ( (v4 & 0x800000) != 0 )
LABEL_27:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_bus_err_bottom_half",
      1467,
      "DISP YC 16:1 violation");
LABEL_28:
  cam_vfe_bus_put_evt_payload(a1, v14);
  v5 = *(_DWORD *)a1;
  HIDWORD(v11) = 2;
  LODWORD(v9) = 6;
  v6 = *(_DWORD **)(a1 + 33600);
  LODWORD(v10) = 23;
  HIDWORD(v10) = v5;
  LODWORD(v7) = 3;
  v13 = &v7;
  if ( v6 )
  {
    if ( *(v6 - 1) != 414296116 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD, _QWORD, __int64 *))v6)(0, 0, &v9);
  }
  result = 0;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
