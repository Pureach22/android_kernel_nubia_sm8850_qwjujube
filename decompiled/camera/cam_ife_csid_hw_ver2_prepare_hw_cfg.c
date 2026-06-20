__int64 __fastcall cam_ife_csid_hw_ver2_prepare_hw_cfg(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned int v4; // w10
  int v5; // w7
  __int64 v9; // x9
  unsigned __int64 v10; // x8
  __int64 v11; // x8
  int v12; // w8
  __int64 *v13; // x8
  __int64 v14; // x9
  __int64 v15; // x9
  __int64 v16; // x26
  __int64 v17; // x9
  __int64 v18; // x9
  __int64 v19; // x9
  __int64 v20; // x24
  __int64 v21; // x25
  __int64 v22; // x8
  _DWORD *v23; // x8
  int v24; // w11
  _DWORD *v25; // x8
  int v26; // w9
  int v27; // w8
  __int64 v28; // x1
  __int64 v29; // x7
  const char *v30; // x5
  int v31; // w9
  int v32; // w10
  __int64 v33; // x6
  unsigned int v34; // w27
  __int64 v35; // x4
  int v36; // w9
  char v37; // w12
  int v38; // w11
  int v39; // w8
  char v40; // w11
  unsigned int v41; // w7
  __int64 v42; // x28
  unsigned int v43; // w8
  int v44; // w26
  unsigned int format_rdi; // w0
  unsigned int v46; // w21
  unsigned int v47; // w0
  unsigned int v48; // w0
  unsigned int v49; // w0
  unsigned int v50; // w0
  unsigned int v51; // w0
  const char *v52; // x3
  const char *v53; // x5
  __int64 v54; // x4
  unsigned int v55; // w0
  unsigned int format_ipp_ppp; // w0
  __int64 result; // x0
  __int64 v58; // x25
  int v59; // w11
  __int64 v60; // x26
  int v61; // w12
  int v62; // w10
  _BOOL4 v64; // w13
  int v65; // w12
  _DWORD *v66; // x13
  int v67; // w14
  _DWORD *v68; // x27
  __int64 v69; // x7
  int v70; // w13
  __int64 v71; // x20
  __int64 v72; // x22
  _DWORD *v73; // x21
  int v74; // w16
  int v75; // w13
  __int64 v76; // x7
  unsigned int v77; // w10
  int v78; // w11
  const char *v79; // x5
  __int64 v80; // x1
  __int64 v81; // x6
  __int64 v82; // x4
  unsigned int v83; // w24
  unsigned int v84; // w24
  unsigned int v85; // w27
  unsigned int v86; // w27
  int v87; // [xsp+0h] [xbp-40h]
  int v88; // [xsp+8h] [xbp-38h]
  int v89; // [xsp+10h] [xbp-30h]
  int v90; // [xsp+18h] [xbp-28h]
  int v91; // [xsp+20h] [xbp-20h]

  v5 = *(_DWORD *)(a1 + 2128);
  if ( v5 )
  {
    v9 = debug_mdl;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v83 = a4;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_hw_ver2_prepare_config_rx",
        4450,
        "CSID %d Rx already reserved cnt %d",
        *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL));
      v5 = *(_DWORD *)(a1 + 2128);
      a4 = v83;
    }
    LODWORD(v10) = v5 + 1;
    *(_DWORD *)(a1 + 2128) = v5 + 1;
    if ( a4 >= 5 )
      goto LABEL_166;
    goto LABEL_23;
  }
  *(_DWORD *)(a1 + 2080) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 20LL);
  *(_DWORD *)(a1 + 2072) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 12LL);
  *(_DWORD *)(a1 + 2076) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 16LL);
  *(_DWORD *)(a1 + 32192) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 8LL);
  *(_BYTE *)(a1 + 2124) = *(_BYTE *)(*(_QWORD *)(a3 + 8) + 217LL);
  v11 = *(_QWORD *)(a3 + 8);
  if ( *(_BYTE *)(v11 + 220) == 1 )
  {
    *(_DWORD *)(a1 + 2096) = 1;
    v11 = *(_QWORD *)(a3 + 8);
  }
  v12 = *(_DWORD *)(v11 + 8);
  if ( v12 > 16392 )
  {
    if ( v12 == 16393 )
    {
      v13 = (__int64 *)(a1 + 2084);
      v14 = 0x200000001LL;
      goto LABEL_19;
    }
    if ( v12 == 16394 )
    {
      v13 = (__int64 *)(a1 + 2084);
      v14 = 0x300000001LL;
      goto LABEL_19;
    }
  }
  else
  {
    if ( v12 == 0x4000 )
    {
      *(_DWORD *)(a1 + 2068) = 0;
      *(_DWORD *)(a1 + 2084) = 0;
      goto LABEL_20;
    }
    if ( v12 == 16392 )
    {
      v13 = (__int64 *)(a1 + 2084);
      v14 = 0x100000001LL;
LABEL_19:
      *v13 = v14;
      goto LABEL_20;
    }
  }
  *(_DWORD *)(a1 + 2084) = 0;
  *(_DWORD *)(a1 + 2068) = *(unsigned __int8 *)(*(_QWORD *)(a3 + 8) + 8LL);
LABEL_20:
  v9 = debug_mdl;
  LODWORD(v10) = 1;
  *(_DWORD *)(a1 + 2128) = 1;
  if ( (v9 & 8) != 0 && (LODWORD(v10) = debug_priority) == 0 )
  {
    v84 = a4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v9 & 8,
      4,
      "cam_ife_csid_hw_ver2_prepare_config_rx",
      4497,
      "CSID:%u Rx lane param: cfg:%u type:%u num:%u res:%u rx reserve count: %u",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      *(_DWORD *)(*(_QWORD *)(a3 + 8) + 20LL),
      *(_DWORD *)(*(_QWORD *)(a3 + 8) + 12LL),
      *(_DWORD *)(*(_QWORD *)(a3 + 8) + 16LL),
      *(_DWORD *)(*(_QWORD *)(a3 + 8) + 8LL),
      1);
    a4 = v84;
    if ( v84 >= 5 )
      goto LABEL_166;
  }
  else if ( a4 >= 5 )
  {
LABEL_166:
    __break(0x5512u);
LABEL_167:
    v76 = *(unsigned int *)(a3 + 4);
    v79 = "CSID[%u] res_id: %u epoch factor: 0x%x factor %u";
    v81 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
    v80 = v4 & 8;
    v88 = *(_DWORD *)(*(_QWORD *)(v9 + 120) + 820LL);
    v82 = 4533;
    v87 = v10;
    goto LABEL_168;
  }
LABEL_23:
  LODWORD(v10) = *(_DWORD *)(a3 + 4);
  if ( (unsigned int)v10 > 0xC )
    goto LABEL_166;
  v15 = *(_QWORD *)(a3 + 8);
  v16 = **(_QWORD **)(a1 + 31136);
  if ( *(_DWORD *)(v15 + 56) )
  {
    *(_DWORD *)(a2 + 124) = *(_DWORD *)(v15 + 60);
    v17 = *(_QWORD *)(a3 + 8);
    if ( *(_DWORD *)(v17 + 56) >= 2u )
    {
      *(_DWORD *)(a2 + 128) = *(_DWORD *)(v17 + 64);
      v18 = *(_QWORD *)(a3 + 8);
      if ( *(_DWORD *)(v18 + 56) >= 3u )
      {
        *(_DWORD *)(a2 + 132) = *(_DWORD *)(v18 + 68);
        v19 = *(_QWORD *)(a3 + 8);
        v4 = *(_DWORD *)(v19 + 56);
        if ( v4 >= 4 )
        {
          *(_DWORD *)(a2 + 136) = *(_DWORD *)(v19 + 72);
          v9 = *(unsigned int *)(*(_QWORD *)(a3 + 8) + 56LL);
          if ( (unsigned int)v9 > 4 )
            goto LABEL_166;
        }
      }
    }
  }
  *(_DWORD *)(a2 + 120) = a4;
  *(_DWORD *)(a2 + 240) = *(_DWORD *)(a3 + 24);
  *(_DWORD *)(a2 + 164) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 116LL);
  v9 = *(unsigned int *)(*(_QWORD *)(a3 + 8) + 108LL);
  *(_DWORD *)(a2 + 156) = v9;
  v4 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 112LL);
  *(_DWORD *)(a2 + 160) = v4;
  *(_BYTE *)(a2 + 246) = *(_BYTE *)(a3 + 56);
  *(_BYTE *)(a2 + 247) = *(_BYTE *)(a3 + 57);
  *(_DWORD *)(a2 + 184) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 148LL);
  *(_DWORD *)(a2 + 188) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 152LL);
  *(_DWORD *)(a2 + 192) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 156LL);
  *(_DWORD *)(a2 + 200) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 160LL);
  *(_BYTE *)(a2 + 116) = *(_BYTE *)(a3 + 52);
  v20 = a1 + 152LL * (unsigned int)v10;
  *(_DWORD *)(a2 + 112) = *(_DWORD *)(a3 + 48);
  v10 = *(unsigned int *)(v20 + 4);
  if ( (unsigned int)v10 > 0xB )
    goto LABEL_166;
  v21 = *(_QWORD *)(v16 + 8 * v10 + 136);
  v22 = *(_QWORD *)(a3 + 16);
  if ( v22 )
    v23 = (_DWORD *)(v22 + 4);
  else
    v23 = (_DWORD *)(v21 + 588);
  *(_DWORD *)(a2 + 140) = *v23;
  v24 = *(_DWORD *)(a3 + 24);
  v25 = *(_DWORD **)(a3 + 8);
  if ( v24 == 2 )
  {
    v36 = v25[24];
    v37 = debug_mdl;
    *(_DWORD *)(a2 + 144) = v36;
    v28 = v37 & 8;
    v4 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 100LL);
    *(_DWORD *)(a2 + 148) = v4;
    v38 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 104LL);
    v39 = debug_priority;
    *(_DWORD *)(a2 + 152) = v38;
    if ( (v37 & 8) != 0 && !v39 )
    {
      v86 = a4;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v28,
        4,
        "cam_ife_csid_hw_ver2_prepare_config_path_data",
        4340,
        "CSID:%u res:%d slave:start:0x%x end:0x%x width 0x%x",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
        *(_DWORD *)(a3 + 4),
        v36,
        v4,
        v38);
      v39 = debug_priority;
      a4 = v86;
      v28 = debug_mdl & 8;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_50;
    }
    else if ( (v37 & 8) == 0 )
    {
      goto LABEL_50;
    }
    if ( v39 )
      goto LABEL_50;
    v29 = *(unsigned int *)(a3 + 4);
    v30 = "CSID:%u res:%d slave:line start:0x%x line end:0x%x";
    v31 = *(_DWORD *)(a2 + 156);
    v32 = *(_DWORD *)(a2 + 160);
    v33 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
    v34 = a4;
    v35 = 4344;
    goto LABEL_47;
  }
  if ( v24 == 1 )
  {
    v26 = v25[21];
    *(_DWORD *)(a2 + 144) = v26;
    v4 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 88LL);
    *(_DWORD *)(a2 + 148) = v4;
    *(_DWORD *)(a2 + 152) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 92LL);
    if ( *(_DWORD *)(a3 + 4) <= 4u )
    {
      v4 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 100LL);
      *(_DWORD *)(a2 + 148) = v4;
      *(_DWORD *)(a2 + 152) = v4 - v26 + 1;
    }
    v27 = debug_priority;
    v28 = debug_mdl & 8;
    if ( (debug_mdl & 8) == 0 || debug_priority )
    {
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_50;
      goto LABEL_40;
    }
    v85 = a4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v28,
      4,
      "cam_ife_csid_hw_ver2_prepare_config_path_data",
      4328,
      "CSID:%u res:%d master:startpixel 0x%x endpixel:0x%x",
      *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
      *(_DWORD *)(a3 + 4),
      v26,
      v4);
    v27 = debug_priority;
    a4 = v85;
    v28 = debug_mdl & 8;
    if ( (debug_mdl & 8) != 0 )
    {
LABEL_40:
      if ( v27 )
        goto LABEL_50;
      v29 = *(unsigned int *)(a3 + 4);
      v30 = "CSID:%u res:%d master:line start:0x%x line end:0x%x";
      v31 = *(_DWORD *)(a2 + 156);
      v32 = *(_DWORD *)(a2 + 160);
      v33 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
      v34 = a4;
      v35 = 4332;
LABEL_47:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, int, int, int))cam_print_log)(
        3,
        v28,
        4,
        "cam_ife_csid_hw_ver2_prepare_config_path_data",
        v35,
        v30,
        v33,
        v29,
        v31,
        v32,
        v89,
        v90);
LABEL_174:
      a4 = v34;
    }
  }
  else
  {
    v40 = debug_mdl;
    *(_DWORD *)(a2 + 152) = v25[23];
    *(_DWORD *)(a2 + 144) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 84LL);
    *(_DWORD *)(a2 + 148) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 88LL);
    if ( (v40 & 8) != 0 && !debug_priority )
    {
      v34 = a4;
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int))cam_print_log)(
        3,
        v40 & 8,
        4,
        "cam_ife_csid_hw_ver2_prepare_config_path_data",
        4355,
        "CSID:%u res:%d left width %d start: %d stop:%d start line :%d end line %d",
        *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL),
        *(unsigned int *)(a3 + 4),
        *(_DWORD *)(*(_QWORD *)(a3 + 8) + 92LL),
        *(_DWORD *)(*(_QWORD *)(a3 + 8) + 84LL),
        *(_DWORD *)(*(_QWORD *)(a3 + 8) + 88LL),
        v9,
        v4);
      goto LABEL_174;
    }
  }
LABEL_50:
  v41 = *(_DWORD *)(a3 + 4);
  if ( v41 > 0xB )
    goto LABEL_117;
  v42 = a1 + 1824 + 56LL * a4;
  if ( ((1 << v41) & 0x1F) == 0 )
  {
    if ( ((1 << v41) & 0xC60) != 0 )
    {
      if ( *(_BYTE *)(v42 + 8) == 1
        && *(_DWORD *)(v42 + 4) != 0xFFFF
        && (v47 = cam_ife_csid_get_format_ipp_ppp(*(_DWORD *)(a2 + 124), (int *)(a2 + 48))) != 0 )
      {
        v46 = v47;
      }
      else if ( *(_BYTE *)(v42 + 20) == 1
             && *(_DWORD *)(v42 + 16) != 0xFFFF
             && (v50 = cam_ife_csid_get_format_ipp_ppp(*(_DWORD *)(a2 + 128), (int *)(a2 + 64))) != 0 )
      {
        v46 = v50;
      }
      else if ( *(_BYTE *)(v42 + 32) == 1
             && *(_DWORD *)(v42 + 28) != 0xFFFF
             && (v55 = cam_ife_csid_get_format_ipp_ppp(*(_DWORD *)(a2 + 132), (int *)(a2 + 80))) != 0 )
      {
        v46 = v55;
      }
      else
      {
        if ( *(_BYTE *)(v42 + 44) != 1 )
          goto LABEL_97;
        if ( *(_DWORD *)(v42 + 40) == 0xFFFF )
          goto LABEL_97;
        format_ipp_ppp = cam_ife_csid_get_format_ipp_ppp(*(_DWORD *)(a2 + 136), (int *)(a2 + 96));
        if ( !format_ipp_ppp )
          goto LABEL_97;
        v46 = format_ipp_ppp;
      }
      v52 = "cam_ife_csid_hw_ver2_prepare_config_path_data";
      v53 = "Invalid format cfg at idx: %d for res_id: 0x%x, in_fmt: 0x%x";
      v54 = 4415;
      goto LABEL_95;
    }
LABEL_117:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_hw_ver2_prepare_config_path_data",
      4425,
      "CSID[%u] Invalid Res id %u",
      *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL));
    v46 = -22;
    goto LABEL_96;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(v16 + 120) + 828LL) & 0x20) == 0 )
  {
    v43 = *(_DWORD *)(a2 + 140);
    v44 = 0;
    if ( v43 <= 0x11 )
    {
      LOBYTE(v4) = 56;
      if ( ((1 << v43) & 0x3C038) != 0 )
        v44 = (*(unsigned __int8 *)(v21 + 584) >> 1) & 1;
    }
    if ( (debug_mdl & 8) != 0 )
    {
      LOBYTE(v4) = debug_priority;
      if ( !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_hw_ver2_need_unpack_mipi",
          4270,
          "CSID[%u], RDI_%u format %u need_unpack %u sfe_shdr %u",
          *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL),
          v41,
          v43,
          v44,
          *(unsigned __int8 *)(a3 + 58));
    }
    *(_BYTE *)(a2 + 252) = v44;
    *(_BYTE *)(a3 + 121) = v44;
  }
  if ( *(_BYTE *)(v42 + 8) == 1 && *(_DWORD *)(v42 + 4) != 0xFFFF )
  {
    format_rdi = cam_ife_csid_get_format_rdi(
                   *(_DWORD *)(a2 + 124),
                   *(_DWORD *)(a2 + 140),
                   a2 + 48,
                   *(_DWORD *)(v21 + 356) != 0,
                   *(_BYTE *)(a2 + 252));
    if ( format_rdi )
    {
      v46 = format_rdi;
LABEL_85:
      v52 = "cam_ife_csid_hw_ver2_prepare_config_path_data";
      v53 = "Invalid format cfg at idx: %d for res_id: 0x%x, in_fmt: 0x%x, out_fmt: 0x%x, mipi_pack_supported: %s, csid_unpack_msb: %s";
      v54 = 4395;
LABEL_95:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        v52,
        v54,
        v53);
LABEL_96:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_hw_ver2_prepare_hw_cfg",
        4563,
        "CSID[%u] path data config failed",
        *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
      return v46;
    }
  }
  if ( *(_BYTE *)(v42 + 20) == 1 && *(_DWORD *)(v42 + 16) != 0xFFFF )
  {
    v48 = cam_ife_csid_get_format_rdi(
            *(_DWORD *)(a2 + 128),
            *(_DWORD *)(a2 + 140),
            a2 + 64,
            *(_DWORD *)(v21 + 356) != 0,
            *(_BYTE *)(a2 + 252));
    if ( v48 )
    {
      v46 = v48;
      goto LABEL_85;
    }
  }
  if ( *(_BYTE *)(v42 + 32) == 1 && *(_DWORD *)(v42 + 28) != 0xFFFF )
  {
    v49 = cam_ife_csid_get_format_rdi(
            *(_DWORD *)(a2 + 132),
            *(_DWORD *)(a2 + 140),
            a2 + 80,
            *(_DWORD *)(v21 + 356) != 0,
            *(_BYTE *)(a2 + 252));
    if ( v49 )
    {
      v46 = v49;
      goto LABEL_85;
    }
  }
  if ( *(_BYTE *)(v42 + 44) == 1 && *(_DWORD *)(v42 + 40) != 0xFFFF )
  {
    v51 = cam_ife_csid_get_format_rdi(
            *(_DWORD *)(a2 + 136),
            *(_DWORD *)(a2 + 140),
            a2 + 96,
            *(_DWORD *)(v21 + 356) != 0,
            *(_BYTE *)(a2 + 252));
    if ( v51 )
    {
      v46 = v51;
      goto LABEL_85;
    }
  }
LABEL_97:
  v10 = *(_QWORD *)(v20 + 24);
  v9 = *(unsigned int *)(v10 + 120);
  if ( (unsigned int)v9 >= 5 )
    goto LABEL_166;
  v58 = a1 + 1824 + 56LL * (unsigned int)v9;
  v9 = **(_QWORD **)(a1 + 31136);
  if ( *(_BYTE *)(v58 + 20) == 1 && *(_BYTE *)(v58 + 8) == 1 )
  {
    v59 = *(_DWORD *)(v10 + 48);
    v60 = v58 + 12;
    v61 = *(_DWORD *)(*(_QWORD *)(v9 + 120) + 824LL);
    v62 = *(_DWORD *)(v10 + 64);
    v64 = v62 == v61 || v59 == v61;
    if ( *(_BYTE *)(v58 + 32) != 1 )
      goto LABEL_118;
    if ( *(_DWORD *)(v10 + 80) == v61 )
      v64 = 1;
    if ( *(_BYTE *)(v58 + 44) == 1 )
    {
      if ( *(_DWORD *)(v10 + 96) == v61 )
        LOBYTE(v64) = 1;
      if ( !v64 )
      {
        if ( *(_DWORD *)(v58 + 12) != *(_DWORD *)v58 )
          goto LABEL_144;
        v66 = (_DWORD *)(v58 + 16);
        v65 = *(_DWORD *)(v58 + 16);
        v68 = (_DWORD *)(v58 + 4);
        v67 = *(_DWORD *)(v58 + 4);
        if ( v65 != v67 || v62 == v59 )
        {
LABEL_133:
          v74 = *(_DWORD *)(v58 + 28);
          v60 = v58 + 24;
          if ( v74 == v67 && *(_DWORD *)(v10 + 80) != v59 )
          {
            v71 = 0;
            v72 = 2;
          }
          else if ( v74 == v65 && *(_DWORD *)(v10 + 80) != v62 )
          {
            v71 = 1;
            v72 = 2;
            v68 = v66;
          }
          else
          {
            if ( *(_BYTE *)(v58 + 44) != 1 )
              goto LABEL_144;
            v75 = *(_DWORD *)(v58 + 40);
            v60 = v58 + 36;
            if ( v75 == v67 && *(_DWORD *)(v10 + 96) != v59 )
            {
              v71 = 0;
              v68 = (_DWORD *)(v58 + 4);
              v72 = 3;
            }
            else if ( v75 == v65 && *(_DWORD *)(v10 + 96) != v62 )
            {
              v68 = (_DWORD *)(v58 + 16);
              v71 = 1;
              v72 = 3;
            }
            else
            {
              if ( v75 != v74 || *(_DWORD *)(v10 + 96) == *(_DWORD *)(v10 + 80) )
                goto LABEL_144;
              v71 = 2;
              v72 = 3;
              v68 = (_DWORD *)(v58 + 28);
            }
          }
          goto LABEL_130;
        }
        goto LABEL_129;
      }
    }
    else
    {
LABEL_118:
      if ( !v64 )
        goto LABEL_126;
    }
    v69 = v59 == v61;
    if ( v59 == v61 )
      v70 = *(_DWORD *)(v10 + 64);
    else
      v70 = *(_DWORD *)(v10 + 48);
    if ( v59 == v61 && v62 == v61 )
    {
      v70 = *(_DWORD *)(v10 + 80);
      if ( v70 == v61 )
      {
        v70 = *(_DWORD *)(v10 + 96);
        if ( v70 == v61 )
        {
LABEL_126:
          if ( *(_DWORD *)(v58 + 12) != *(_DWORD *)v58 )
            goto LABEL_144;
          v66 = (_DWORD *)(v58 + 16);
          v65 = *(_DWORD *)(v58 + 16);
          v68 = (_DWORD *)(v58 + 4);
          v67 = *(_DWORD *)(v58 + 4);
          if ( v65 != v67 || v62 == v59 )
          {
            if ( !*(_BYTE *)(v58 + 32) )
              goto LABEL_144;
            goto LABEL_133;
          }
LABEL_129:
          v71 = 0;
          v72 = 1;
LABEL_130:
          v73 = (_DWORD *)(v10 + 48);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_csid_ver2_decode_format_validate",
            210,
            "CSID:%u Wrong multi VC-DT configuration",
            *(_DWORD *)(*(_QWORD *)(a1 + 31120) + 4LL));
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_csid_ver2_decode_format_validate",
            220,
            "CSID:%u fmt %d fmt1 %d vc %d vc1 %d dt%d %d dt%d %d",
            *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL),
            (unsigned int)v73[4 * v72],
            v73[4 * v71],
            *(_DWORD *)v58,
            *(_DWORD *)(v58 + 12),
            v72,
            *(_DWORD *)(v60 + 4),
            v71,
            *v68);
LABEL_159:
          v52 = "cam_ife_csid_ver2_decode_format_validate";
          v53 = "Invalid decode fmt cfg CSID[%u] res [id %d name %s] rc %d";
          v54 = 231;
          v46 = -22;
          goto LABEL_95;
        }
        v69 = 3;
      }
      else
      {
        v69 = 2;
      }
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, int, int, int, int))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_decode_format_validate",
      193,
      "CSID:%u payload decode_fmt_%d mismatch: 0x%x",
      *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL),
      v69,
      v70,
      v88,
      v89,
      v90,
      v91);
    goto LABEL_159;
  }
LABEL_144:
  v76 = *(unsigned int *)(a3 + 4);
  if ( (unsigned int)v76 >= 6 && (unsigned int)(v76 - 10) > 1 )
  {
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v79 = "CSID[%u] No CAMIF epoch update for res: %u";
      v80 = debug_mdl & 8;
      v81 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
      v82 = 4537;
LABEL_168:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, int))cam_print_log)(
        3,
        v80,
        4,
        "cam_ife_csid_ver2_prepare_camif_config",
        v82,
        v79,
        v81,
        v76,
        v87,
        v88);
      return 0;
    }
  }
  else
  {
    v77 = *(_DWORD *)(a2 + 160);
    v78 = *(_DWORD *)(a2 + 184);
    LODWORD(v10) = *(_DWORD *)(*(_QWORD *)(v9 + 120) + 820LL) * (v77 - *(_DWORD *)(a2 + 156)) / 0x64;
    if ( (unsigned int)v10 >= v77 )
      LODWORD(v10) = *(_DWORD *)(a2 + 160);
    *(_DWORD *)(a2 + 232) = v10;
    if ( v78 || *(_DWORD *)(a2 + 192) )
    {
      LODWORD(v10) = (unsigned int)v10 >> 1;
      *(_DWORD *)(a2 + 232) = v10;
    }
    LOBYTE(v4) = debug_mdl;
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      goto LABEL_167;
  }
  return result;
}
