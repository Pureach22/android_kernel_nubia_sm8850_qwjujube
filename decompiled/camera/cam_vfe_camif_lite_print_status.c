__int64 __fastcall cam_vfe_camif_lite_print_status(int *a1, int a2, __int64 a3)
{
  int v3; // w21
  int v5; // w23
  int v6; // w24
  __int64 v8; // x22
  __int64 result; // x0
  int v10; // w20
  const char *v11; // x5
  __int64 v12; // x4
  const char *v13; // x5
  __int64 v14; // x4

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             1,
             "cam_vfe_camif_lite_print_status",
             855,
             "Invalid params");
  v3 = a1[4];
  v5 = *a1;
  v6 = a1[2];
  v8 = *(_QWORD *)(*(_QWORD *)(a3 + 40) + 3296LL);
  if ( (*(_BYTE *)(v8 + 24) & 1) != 0 )
  {
    if ( a2 != 3 )
    {
      if ( a2 != 1 )
        goto LABEL_95;
      if ( (v5 & 0x100) != 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_camif_lite_print_status",
          959,
          "RDI3 FRAME DROP");
        if ( (v5 & 0x80) == 0 )
        {
LABEL_7:
          if ( (v5 & 0x40) == 0 )
            goto LABEL_8;
          goto LABEL_53;
        }
      }
      else if ( (v5 & 0x80) == 0 )
      {
        goto LABEL_7;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        962,
        "RDI2 FRAME DROP");
      if ( (v5 & 0x40) == 0 )
      {
LABEL_8:
        if ( (v5 & 0x20) == 0 )
          goto LABEL_9;
        goto LABEL_54;
      }
LABEL_53:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        965,
        "RDI1 FRAME DROP");
      if ( (v5 & 0x20) == 0 )
      {
LABEL_9:
        if ( (v5 & 8) == 0 )
          goto LABEL_10;
        goto LABEL_55;
      }
LABEL_54:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        968,
        "RDI0 FRAME DROP");
      if ( (v5 & 8) == 0 )
      {
LABEL_10:
        if ( (v5 & 4) == 0 )
          goto LABEL_11;
        goto LABEL_56;
      }
LABEL_55:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        971,
        "RDI3 OVERFLOW");
      if ( (v5 & 4) == 0 )
      {
LABEL_11:
        if ( (v5 & 2) == 0 )
          goto LABEL_12;
        goto LABEL_57;
      }
LABEL_56:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        974,
        "RDI2 OVERFLOW");
      if ( (v5 & 2) == 0 )
      {
LABEL_12:
        if ( (v5 & 1) == 0 )
          goto LABEL_13;
        goto LABEL_58;
      }
LABEL_57:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        977,
        "RDI1 OVERFLOW");
      if ( (v5 & 1) == 0 )
      {
LABEL_13:
        if ( v3 )
          goto LABEL_14;
LABEL_59:
        v11 = "RDI hang";
        v12 = 998;
LABEL_69:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_camif_lite_print_status",
          v12,
          v11);
        cam_vfe_camif_lite_overflow_debug_info(a3);
        goto LABEL_95;
      }
LABEL_58:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        980,
        "RDI0 OVERFLOW");
      if ( v3 )
      {
LABEL_14:
        if ( (v3 & 1) != 0 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            8,
            3,
            "cam_vfe_camif_lite_print_status",
            985,
            "RDI0 BUS OVERFLOW");
          if ( (v3 & 2) == 0 )
          {
LABEL_16:
            if ( (v3 & 4) == 0 )
              goto LABEL_17;
            goto LABEL_87;
          }
        }
        else if ( (v3 & 2) == 0 )
        {
          goto LABEL_16;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_camif_lite_print_status",
          988,
          "RDI1 BUS OVERFLOW");
        if ( (v3 & 4) == 0 )
        {
LABEL_17:
          if ( (v3 & 8) == 0 )
            goto LABEL_95;
          goto LABEL_88;
        }
LABEL_87:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_camif_lite_print_status",
          991,
          "RDI2 BUS OVERFLOW");
        if ( (v3 & 8) == 0 )
          goto LABEL_95;
LABEL_88:
        v13 = "RDI3 BUS OVERFLOW";
        v14 = 994;
        goto LABEL_94;
      }
      goto LABEL_59;
    }
    if ( (v6 & 0x100) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        1005,
        "RDI0 CAMIF VIOLATION");
      if ( (v6 & 0x200) == 0 )
      {
LABEL_39:
        if ( (v6 & 0x400) == 0 )
          goto LABEL_40;
        goto LABEL_72;
      }
    }
    else if ( (v6 & 0x200) == 0 )
    {
      goto LABEL_39;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_print_status",
      1008,
      "RDI1 CAMIF VIOLATION");
    if ( (v6 & 0x400) == 0 )
    {
LABEL_40:
      if ( (v6 & 0x800) == 0 )
        goto LABEL_95;
LABEL_73:
      v13 = "RDI3 CAMIF VIOLATION";
      v14 = 1014;
LABEL_94:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        v14,
        v13);
      goto LABEL_95;
    }
LABEL_72:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_print_status",
      1011,
      "RDI2 CAMIF VIOLATION");
    if ( (v6 & 0x800) == 0 )
      goto LABEL_95;
    goto LABEL_73;
  }
  if ( a2 != 3 )
  {
    if ( a2 != 1 )
      goto LABEL_95;
    if ( (v5 & 0x200000) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        870,
        "RDI2 FRAME DROP");
      if ( (v5 & 0x400000) == 0 )
      {
LABEL_24:
        if ( (v5 & 0x800000) == 0 )
          goto LABEL_25;
        goto LABEL_62;
      }
    }
    else if ( (v5 & 0x400000) == 0 )
    {
      goto LABEL_24;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_print_status",
      873,
      "RDI1 FRAME DROP");
    if ( (v5 & 0x800000) == 0 )
    {
LABEL_25:
      if ( (v5 & 0x1000000) == 0 )
        goto LABEL_26;
      goto LABEL_63;
    }
LABEL_62:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_print_status",
      876,
      "RDI0 FRAME DROP");
    if ( (v5 & 0x1000000) == 0 )
    {
LABEL_26:
      if ( (v5 & 0x8000000) == 0 )
        goto LABEL_27;
      goto LABEL_64;
    }
LABEL_63:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_print_status",
      879,
      "PD PIPE FRAME DROP");
    if ( (v5 & 0x8000000) == 0 )
    {
LABEL_27:
      if ( (v5 & 0x10000000) == 0 )
        goto LABEL_28;
      goto LABEL_65;
    }
LABEL_64:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_print_status",
      882,
      "RDI2 OVERFLOW");
    if ( (v5 & 0x10000000) == 0 )
    {
LABEL_28:
      if ( (v5 & 0x20000000) == 0 )
        goto LABEL_29;
      goto LABEL_66;
    }
LABEL_65:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_print_status",
      885,
      "RDI1 OVERFLOW");
    if ( (v5 & 0x20000000) == 0 )
    {
LABEL_29:
      if ( (v5 & 0x40000000) == 0 )
        goto LABEL_30;
      goto LABEL_67;
    }
LABEL_66:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_print_status",
      888,
      "RDI0 OVERFLOW");
    if ( (v5 & 0x40000000) == 0 )
    {
LABEL_30:
      if ( v3 )
        goto LABEL_31;
      goto LABEL_68;
    }
LABEL_67:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_print_status",
      891,
      "PD PIPE OVERFLOW");
    cam_cpas_log_votes(0);
    if ( v3 )
    {
LABEL_31:
      if ( (v3 & 0x800) != 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_camif_lite_print_status",
          898,
          "CAMIF PD BUS OVERFLOW");
        if ( (v3 & 0x400000) == 0 )
        {
LABEL_33:
          if ( (v3 & 0x800000) == 0 )
            goto LABEL_34;
          goto LABEL_91;
        }
      }
      else if ( (v3 & 0x400000) == 0 )
      {
        goto LABEL_33;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        901,
        "LCR BUS OVERFLOW");
      if ( (v3 & 0x800000) == 0 )
      {
LABEL_34:
        if ( (v3 & 0x1000000) == 0 )
          goto LABEL_35;
        goto LABEL_92;
      }
LABEL_91:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        904,
        "RDI0 BUS OVERFLOW");
      if ( (v3 & 0x1000000) == 0 )
      {
LABEL_35:
        if ( (v3 & 0x2000000) == 0 )
          goto LABEL_95;
LABEL_93:
        v13 = "RDI2 BUS OVERFLOW";
        v14 = 910;
        goto LABEL_94;
      }
LABEL_92:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        907,
        "RDI1 BUS OVERFLOW");
      if ( (v3 & 0x2000000) == 0 )
        goto LABEL_95;
      goto LABEL_93;
    }
LABEL_68:
    v11 = "PDLIB / LCR Module hang";
    v12 = 914;
    goto LABEL_69;
  }
  v10 = a1[3];
  if ( (v6 & 0x2000) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_print_status",
      921,
      "PD CAMIF VIOLATION");
    if ( (v6 & 0x4000) == 0 )
    {
LABEL_44:
      if ( (v6 & 0x8000) == 0 )
        goto LABEL_45;
      goto LABEL_76;
    }
  }
  else if ( (v6 & 0x4000) == 0 )
  {
    goto LABEL_44;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_lite_print_status",
    924,
    "PD VIOLATION");
  if ( (v6 & 0x8000) == 0 )
  {
LABEL_45:
    if ( (v6 & 0x10000) == 0 )
      goto LABEL_46;
    goto LABEL_77;
  }
LABEL_76:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_lite_print_status",
    927,
    "LCR CAMIF VIOLATION");
  if ( (v6 & 0x10000) == 0 )
  {
LABEL_46:
    if ( (v6 & 0x20000) == 0 )
      goto LABEL_47;
    goto LABEL_78;
  }
LABEL_77:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_lite_print_status",
    930,
    "LCR VIOLATION");
  if ( (v6 & 0x20000) == 0 )
  {
LABEL_47:
    if ( (v6 & 0x40000) == 0 )
      goto LABEL_48;
    goto LABEL_79;
  }
LABEL_78:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_lite_print_status",
    933,
    "RDI0 CAMIF VIOLATION");
  if ( (v6 & 0x40000) == 0 )
  {
LABEL_48:
    if ( (v6 & 0x80000) == 0 )
      goto LABEL_49;
LABEL_80:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_print_status",
      939,
      "RDI2 CAMIF VIOLATION");
    if ( !v10 )
      goto LABEL_95;
LABEL_81:
    if ( (v10 & 0x3F00) != 0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        945,
        "LCR VIOLATION Module ID:%d",
        v10 & 0x3F00);
    if ( (v10 & 0xF0000) != 0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_lite_print_status",
        950,
        "PD VIOLATION Module ID:%d",
        v10 & 0xF0000);
    goto LABEL_95;
  }
LABEL_79:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_lite_print_status",
    936,
    "RDI1 CAMIF VIOLATION");
  if ( (v6 & 0x80000) != 0 )
    goto LABEL_80;
LABEL_49:
  if ( v10 )
    goto LABEL_81;
LABEL_95:
  cam_cpas_dump_camnoc_buff_fill_info();
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             3,
             "cam_vfe_camif_lite_print_status",
             1020,
             "ife_clk_src:%lld",
             *(_QWORD *)(v8 + 32));
  if ( a2 == 1 )
  {
    if ( v3 )
      return cam_cpas_log_votes(0);
  }
  return result;
}
