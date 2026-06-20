__int64 __fastcall cam_vfe_camif_ver3_print_status(int *a1, int a2, __int64 a3)
{
  int v3; // w22
  int v7; // w21
  _BOOL4 v8; // w22
  __int64 result; // x0
  int v10; // w23
  int v11; // w8
  int v12; // w22
  int v13; // w23
  int v14; // w24
  int v15; // w0
  int v16; // w22
  int v17; // w23
  int v18; // w24
  int v19; // w0
  int v20; // w22
  int v21; // w23
  int v22; // w24
  int v23; // w0
  int v24; // w22
  int v25; // w0
  int v26; // w21
  const char *v27; // x5
  __int64 v28; // x4
  __int64 v29; // x21
  int v30; // w8

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             1,
             "cam_vfe_camif_ver3_print_status",
             958,
             "Invalid params");
  v3 = a1[4];
  if ( a2 == 1 )
  {
    v7 = *a1;
    if ( (*a1 & 0x200) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        968,
        "DSP OVERFLOW");
      if ( (v7 & 0x2000000) == 0 )
      {
LABEL_5:
        if ( (v7 & 0x80000000) == 0 )
          goto LABEL_6;
        goto LABEL_45;
      }
    }
    else if ( (v7 & 0x2000000) == 0 )
    {
      goto LABEL_5;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_print_status",
      971,
      "PIXEL PIPE FRAME DROP");
    if ( (v7 & 0x80000000) == 0 )
    {
LABEL_6:
      if ( v3 )
        goto LABEL_7;
      goto LABEL_46;
    }
LABEL_45:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_print_status",
      974,
      "PIXEL PIPE OVERFLOW");
    if ( v3 )
    {
LABEL_7:
      if ( (v3 & 1) != 0 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_camif_ver3_print_status",
          979,
          "VID Y 1:1 BUS OVERFLOW");
        if ( (v3 & 2) == 0 )
        {
LABEL_9:
          if ( (v3 & 4) == 0 )
            goto LABEL_10;
          goto LABEL_49;
        }
      }
      else if ( (v3 & 2) == 0 )
      {
        goto LABEL_9;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        982,
        "VID C 1:1 BUS OVERFLOW");
      if ( (v3 & 4) == 0 )
      {
LABEL_10:
        if ( (v3 & 8) == 0 )
          goto LABEL_11;
        goto LABEL_50;
      }
LABEL_49:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        985,
        "VID YC 4:1 BUS OVERFLOW");
      if ( (v3 & 8) == 0 )
      {
LABEL_11:
        if ( (v3 & 0x10) == 0 )
          goto LABEL_12;
        goto LABEL_51;
      }
LABEL_50:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        988,
        "VID YC 16:1 BUS OVERFLOW");
      if ( (v3 & 0x10) == 0 )
      {
LABEL_12:
        if ( (v3 & 0x20) == 0 )
          goto LABEL_13;
        goto LABEL_52;
      }
LABEL_51:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        991,
        "DISP Y 1:1 BUS OVERFLOW");
      if ( (v3 & 0x20) == 0 )
      {
LABEL_13:
        if ( (v3 & 0x40) == 0 )
          goto LABEL_14;
        goto LABEL_53;
      }
LABEL_52:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        994,
        "DISP C 1:1 BUS OVERFLOW");
      if ( (v3 & 0x40) == 0 )
      {
LABEL_14:
        if ( (v3 & 0x80) == 0 )
          goto LABEL_15;
        goto LABEL_54;
      }
LABEL_53:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        997,
        "DISP YC 4:1 BUS OVERFLOW");
      if ( (v3 & 0x80) == 0 )
      {
LABEL_15:
        if ( (v3 & 0x100) == 0 )
          goto LABEL_16;
        goto LABEL_55;
      }
LABEL_54:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1000,
        "DISP YC 16:1 BUS OVERFLOW");
      if ( (v3 & 0x100) == 0 )
      {
LABEL_16:
        if ( (v3 & 0x200) == 0 )
          goto LABEL_17;
        goto LABEL_56;
      }
LABEL_55:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1003,
        "FD Y BUS OVERFLOW");
      if ( (v3 & 0x200) == 0 )
      {
LABEL_17:
        if ( (v3 & 0x400) == 0 )
          goto LABEL_18;
        goto LABEL_57;
      }
LABEL_56:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1006,
        "FD C BUS OVERFLOW");
      if ( (v3 & 0x400) == 0 )
      {
LABEL_18:
        if ( (v3 & 0x1000) == 0 )
          goto LABEL_19;
        goto LABEL_58;
      }
LABEL_57:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1009,
        "PIXEL RAW DUMP BUS OVERFLOW");
      if ( (v3 & 0x1000) == 0 )
      {
LABEL_19:
        if ( (v3 & 0x2000) == 0 )
          goto LABEL_20;
        goto LABEL_59;
      }
LABEL_58:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1012,
        "STATS HDR BE BUS OVERFLOW");
      if ( (v3 & 0x2000) == 0 )
      {
LABEL_20:
        if ( (v3 & 0x4000) == 0 )
          goto LABEL_21;
        goto LABEL_60;
      }
LABEL_59:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1015,
        "STATS HDR BHIST BUS OVERFLOW");
      if ( (v3 & 0x4000) == 0 )
      {
LABEL_21:
        if ( (v3 & 0x8000) == 0 )
          goto LABEL_22;
        goto LABEL_61;
      }
LABEL_60:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1018,
        "STATS TINTLESS BG BUS OVERFLOW");
      if ( (v3 & 0x8000) == 0 )
      {
LABEL_22:
        if ( (v3 & 0x10000) == 0 )
          goto LABEL_23;
        goto LABEL_62;
      }
LABEL_61:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1021,
        "STATS AWB BG BUS OVERFLOW");
      if ( (v3 & 0x10000) == 0 )
      {
LABEL_23:
        if ( (v3 & 0x20000) == 0 )
          goto LABEL_24;
        goto LABEL_63;
      }
LABEL_62:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1024,
        "STATS BHIST BUS OVERFLOW");
      if ( (v3 & 0x20000) == 0 )
      {
LABEL_24:
        if ( (v3 & 0x40000) == 0 )
          goto LABEL_25;
        goto LABEL_64;
      }
LABEL_63:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1027,
        "STATS RS BUS OVERFLOW");
      if ( (v3 & 0x40000) == 0 )
      {
LABEL_25:
        if ( (v3 & 0x80000) == 0 )
          goto LABEL_26;
        goto LABEL_65;
      }
LABEL_64:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1030,
        "STATS CS BUS OVERFLOW");
      if ( (v3 & 0x80000) == 0 )
      {
LABEL_26:
        if ( (v3 & 0x100000) == 0 )
          goto LABEL_27;
        goto LABEL_66;
      }
LABEL_65:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1033,
        "STATS IHIST BUS OVERFLOW");
      if ( (v3 & 0x100000) == 0 )
      {
LABEL_27:
        if ( (v3 & 0x200000) == 0 )
        {
LABEL_28:
          v8 = 1;
          goto LABEL_133;
        }
        goto LABEL_67;
      }
LABEL_66:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1036,
        "STATS BAF BUS OVERFLOW");
      if ( (v3 & 0x200000) == 0 )
        goto LABEL_28;
LABEL_67:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_camif_ver3_print_status",
        1039,
        "PDAF BUS OVERFLOW");
      v8 = 1;
      goto LABEL_133;
    }
LABEL_46:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_print_status",
      1044,
      "PIXEL PIPE Module hang");
    v12 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 100LL));
    v13 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 104LL));
    v14 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 108LL));
    v15 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 112LL));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_overflow_debug_info",
      916,
      "status_0: 0x%X status_1: 0x%X status_2: 0x%X status_3: 0x%X",
      v12,
      v13,
      v14,
      v15);
    v16 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 116LL));
    v17 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 120LL));
    v18 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 124LL));
    v19 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 128LL));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_overflow_debug_info",
      928,
      "status_4: 0x%X status_5: 0x%X status_6: 0x%X status_7: 0x%X",
      v16,
      v17,
      v18,
      v19);
    v20 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 132LL));
    v21 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 136LL));
    v22 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 140LL));
    v23 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 144LL));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_overflow_debug_info",
      940,
      "status_8: 0x%X status_9: 0x%X status_10: 0x%X status_11: 0x%X",
      v20,
      v21,
      v22,
      v23);
    v24 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 148LL));
    v25 = cam_io_r(*(_QWORD *)a3 + *(unsigned int *)(*(_QWORD *)(a3 + 24) + 152LL));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_overflow_debug_info",
      947,
      "status_12: 0x%X status_13: 0x%X",
      v24,
      v25);
    v8 = 0;
    goto LABEL_133;
  }
  v8 = v3 != 0;
  if ( a2 != 3 )
    goto LABEL_133;
  v10 = a1[2];
  if ( (v10 & 0x80) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_print_status",
      1052,
      "DSP IFE PROTOCOL VIOLATION");
    if ( (v10 & 0x100) == 0 )
    {
LABEL_33:
      if ( (v10 & 0x200) == 0 )
        goto LABEL_34;
      goto LABEL_70;
    }
  }
  else if ( (v10 & 0x100) == 0 )
  {
    goto LABEL_33;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_print_status",
    1055,
    "IFE DSP TX PROTOCOL VIOLATION");
  if ( (v10 & 0x200) == 0 )
  {
LABEL_34:
    if ( (v10 & 0x400) == 0 )
      goto LABEL_35;
    goto LABEL_71;
  }
LABEL_70:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_print_status",
    1058,
    "DSP IFE RX PROTOCOL VIOLATION");
  if ( (v10 & 0x400) == 0 )
  {
LABEL_35:
    if ( (v10 & 0x800) == 0 )
      goto LABEL_36;
    goto LABEL_72;
  }
LABEL_71:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_print_status",
    1061,
    "PP PREPROCESS VIOLATION");
  if ( (v10 & 0x800) == 0 )
  {
LABEL_36:
    if ( (v10 & 0x1000) == 0 )
      goto LABEL_37;
    goto LABEL_73;
  }
LABEL_72:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_print_status",
    1064,
    "PP CAMIF VIOLATION");
  if ( (v10 & 0x1000) == 0 )
  {
LABEL_37:
    if ( (v10 & 0x100000) == 0 )
      goto LABEL_38;
    goto LABEL_74;
  }
LABEL_73:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_print_status",
    1067,
    "PP VIOLATION");
  if ( (v10 & 0x100000) == 0 )
  {
LABEL_38:
    if ( (v10 & 0x200000) == 0 )
      goto LABEL_39;
    goto LABEL_75;
  }
LABEL_74:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_print_status",
    1071,
    "DSP_TX_VIOLATION:overflow on DSP interface TX path FIFO");
  if ( (v10 & 0x200000) == 0 )
  {
LABEL_39:
    if ( (v10 & 0x10000000) == 0 )
      goto LABEL_40;
    goto LABEL_76;
  }
LABEL_75:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_print_status",
    1075,
    "DSP_RX_VIOLATION:overflow on DSP interface RX path FIFO");
  if ( (v10 & 0x10000000) == 0 )
  {
LABEL_40:
    if ( (v10 & 0x20000000) == 0 )
      goto LABEL_41;
LABEL_77:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_print_status",
      1082,
      "DIAG VIOLATION: HBI is less than the minimum required HBI");
    v11 = a1[3];
    if ( !v11 )
      goto LABEL_133;
LABEL_78:
    v26 = v11 & 0x3F;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_ver3_print_status",
      1090,
      "PIXEL PIPE VIOLATION Module ID:%d",
      v26);
    switch ( v26 )
    {
      case 0:
        v27 = "DEMUX";
        v28 = 1094;
        goto LABEL_132;
      case 1:
        v27 = "CHROMA_UP";
        v28 = 1097;
        goto LABEL_132;
      case 2:
        v27 = "PEDESTAL";
        v28 = 1100;
        goto LABEL_132;
      case 3:
        v27 = "LINEARIZATION";
        v28 = 1103;
        goto LABEL_132;
      case 4:
        v27 = "BPC_PDPC";
        v28 = 1106;
        goto LABEL_132;
      case 5:
        v27 = "HDR_BINCORRECT";
        v28 = 1109;
        goto LABEL_132;
      case 6:
        v27 = "ABF";
        v28 = 1112;
        goto LABEL_132;
      case 7:
        v27 = "LSC";
        v28 = 1115;
        goto LABEL_132;
      case 8:
        v27 = "DEMOSAIC";
        v28 = 1118;
        goto LABEL_132;
      case 9:
        v27 = "COLOR_CORRECT";
        v28 = 1121;
        goto LABEL_132;
      case 10:
        v27 = "GTM";
        v28 = 1124;
        goto LABEL_132;
      case 11:
        v27 = "GLUT";
        v28 = 1127;
        goto LABEL_132;
      case 12:
        v27 = "COLOR_XFORM";
        v28 = 1130;
        goto LABEL_132;
      case 13:
        v27 = "CROP_RND_CLAMP_PIXEL_RAW_OUT";
        v28 = 1133;
        goto LABEL_132;
      case 14:
        v27 = "DOWNSCALE_MN_Y_FD_OUT";
        v28 = 1136;
        goto LABEL_132;
      case 15:
        v27 = "DOWNSCALE_MN_C_FD_OUT";
        v28 = 1139;
        goto LABEL_132;
      case 16:
        v27 = "CROP_RND_CLAMP_POST_DOWNSCALE_MN_Y_FD_OUT";
        v28 = 1143;
        goto LABEL_132;
      case 17:
        v27 = "CROP_RND_CLAMP_POST_DOWNSCALE_MN_C_FD_OUT";
        v28 = 1147;
        goto LABEL_132;
      case 18:
        v27 = "DOWNSCALE_MN_Y_DISP_OUT";
        v28 = 1150;
        goto LABEL_132;
      case 19:
        v27 = "DOWNSCALE_MN_C_DISP_OUT";
        v28 = 1153;
        goto LABEL_132;
      case 20:
        v27 = "module: CROP_RND_CLAMP_POST_DOWNSCALE_MN_Y_DISP_OUT";
        v28 = 1157;
        goto LABEL_132;
      case 21:
        v27 = "CROP_RND_CLAMP_POST_DOWNSCALE_MN_C_DISP_OUT";
        v28 = 1161;
        goto LABEL_132;
      case 22:
        v27 = "DOWNSCALE_4TO1_Y_DISP_DS4_OUT";
        v28 = 1164;
        goto LABEL_132;
      case 23:
        v27 = "DOWNSCALE_4TO1_C_DISP_DS4_OUT";
        v28 = 1167;
        goto LABEL_132;
      case 24:
        v27 = "CROP_RND_CLAMP_POST_DOWNSCALE_4TO1_Y_DISP_DS4_OUT";
        v28 = 1171;
        goto LABEL_132;
      case 25:
        v27 = "CROP_RND_CLAMP_POST_DOWNSCALE_4TO1_C_DISP_DS4_OUT";
        v28 = 1175;
        goto LABEL_132;
      case 26:
        v27 = "DOWNSCALE_4TO1_Y_DISP_DS16_OUT";
        v28 = 1178;
        goto LABEL_132;
      case 27:
        v27 = "DOWNSCALE_4TO1_C_DISP_DS16_OUT";
        v28 = 1181;
        goto LABEL_132;
      case 28:
        v27 = "CROP_RND_CLAMP_POST_DOWNSCALE_4TO1_Y_DISP_DS16_OUT";
        v28 = 1185;
        goto LABEL_132;
      case 29:
        v27 = "CROP_RND_CLAMP_POST_DOWNSCALE_4TO1_C_DISP_DS16_OUT";
        v28 = 1189;
        goto LABEL_132;
      case 30:
        v27 = "DOWNSCALE_MN_Y_VID_OUT";
        v28 = 1192;
        goto LABEL_132;
      case 31:
        v27 = "DOWNSCALE_MN_C_VID_OUT";
        v28 = 1195;
        goto LABEL_132;
      case 32:
        v27 = "CROP_RND_CLAMP_POST_DOWNSCALE_MN_Y_VID_OUT";
        v28 = 1199;
        goto LABEL_132;
      case 33:
        v27 = "CROP_RND_CLAMP_POST_DOWNSCALE_MN_C_VID_OUT";
        v28 = 1203;
        goto LABEL_132;
      case 34:
        v27 = "DSX_Y_VID_OUT";
        v28 = 1206;
        goto LABEL_132;
      case 35:
        v27 = "DSX_C_VID_OUT";
        v28 = 1209;
        goto LABEL_132;
      case 36:
        v27 = "CROP_RND_CLAMP_POST_DSX_Y_VID_OUT";
        v28 = 1213;
        goto LABEL_132;
      case 37:
        v27 = "CROP_RND_CLAMP_POST_DSX_C_VID_OUT";
        v28 = 1217;
        goto LABEL_132;
      case 38:
        v27 = "DOWNSCALE_4TO1_Y_VID_DS16_OUT";
        v28 = 1221;
        goto LABEL_132;
      case 39:
        v27 = "DOWNSCALE_4TO1_C_VID_DS16_OUT";
        v28 = 1225;
        goto LABEL_132;
      case 40:
        v27 = "CROP_RND_CLAMP_POST_DOWNSCALE_4TO1_Y_VID_DS16_OUT";
        v28 = 1229;
        goto LABEL_132;
      case 41:
        v27 = "CROP_RND_CLAMP_POST_DOWNSCALE_4TO1_C_VID_DS16_OUT";
        v28 = 1233;
        goto LABEL_132;
      case 42:
        v27 = "BLS";
        v28 = 1236;
        goto LABEL_132;
      case 43:
        v27 = "STATS_TINTLESS_BG";
        v28 = 1239;
        goto LABEL_132;
      case 44:
        v27 = "STATS_HDR_BHIST";
        v28 = 1242;
        goto LABEL_132;
      case 45:
        v27 = "STATS_HDR_BE";
        v28 = 1245;
        goto LABEL_132;
      case 46:
        v27 = "STATS_AWB_BG";
        v28 = 1248;
        goto LABEL_132;
      case 47:
        v27 = "STATS_BHIST";
        v28 = 1251;
        goto LABEL_132;
      case 48:
        v27 = "STATS_BAF";
        v28 = 1254;
        goto LABEL_132;
      case 49:
        v27 = "STATS_RS";
        v28 = 1257;
        goto LABEL_132;
      case 50:
        v27 = "STATS_CS";
        v28 = 1260;
        goto LABEL_132;
      case 51:
        v27 = "STATS_IHIST";
        v28 = 1263;
LABEL_132:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          3,
          "cam_vfe_camif_ver3_print_status",
          v28,
          v27);
        break;
      default:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_camif_ver3_print_status",
          1267,
          "Invalid Module ID:%d",
          v26);
        break;
    }
    goto LABEL_133;
  }
LABEL_76:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_camif_ver3_print_status",
    1078,
    "DSP ERROR VIOLATION");
  if ( (v10 & 0x20000000) != 0 )
    goto LABEL_77;
LABEL_41:
  v11 = a1[3];
  if ( v11 )
    goto LABEL_78;
LABEL_133:
  v29 = *(_QWORD *)(*(_QWORD *)(a3 + 40) + 3296LL);
  cam_cpas_dump_camnoc_buff_fill_info();
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             3,
             "cam_vfe_camif_ver3_print_status",
             1277,
             "ife_clk_src:%lld",
             *(_QWORD *)(v29 + 32));
  if ( a2 == 1 )
  {
    v30 = (*(_BYTE *)(a3 + 84) & 3) != 0 || v8;
    if ( v30 == 1 )
      return cam_cpas_log_votes(0);
  }
  return result;
}
