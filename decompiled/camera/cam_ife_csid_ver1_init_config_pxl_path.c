__int64 __fastcall cam_ife_csid_ver1_init_config_pxl_path(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  _QWORD *v5; // x10
  int v6; // w9
  _QWORD *v7; // x23
  unsigned int *v8; // x22
  unsigned int *v9; // x27
  _DWORD *v10; // x25
  __int64 v11; // x24
  __int64 v12; // x28
  unsigned int format_ipp_ppp; // w0
  int v14; // w8
  int v15; // w9
  unsigned int v16; // w10
  unsigned int v17; // w21
  unsigned int v18; // w9
  __int64 result; // x0
  int v20; // w28
  int v21; // w21
  int v22; // w9
  int v23; // w27
  int v24; // w21
  unsigned int v25; // w8
  unsigned int v26; // w0
  unsigned int v27; // w20
  int v28; // w21
  unsigned int v29; // [xsp+4h] [xbp-1Ch]
  _QWORD v30[3]; // [xsp+8h] [xbp-18h] BYREF

  v30[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 8);
  v5 = *(_QWORD **)(a1 + 16);
  v6 = *(_DWORD *)(a2 + 4);
  v30[0] = 0;
  v30[1] = 0;
  v7 = (_QWORD *)*v5;
  if ( v6 == 5 )
  {
    v8 = (unsigned int *)v7[1];
    if ( v8 )
      goto LABEL_4;
LABEL_21:
    result = 4294967274LL;
LABEL_49:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v6 != 6 )
    goto LABEL_21;
  v8 = (unsigned int *)v7[2];
  if ( !v8 )
    goto LABEL_21;
LABEL_4:
  v9 = *(unsigned int **)(a2 + 24);
  if ( *v9 < 5 )
  {
    v10 = (_DWORD *)v7[12];
    v11 = *(_QWORD *)(v4 + 384);
    v12 = a1 + 56LL * *v9 + 27016;
    format_ipp_ppp = cam_ife_csid_get_format_ipp_ppp(v9[1], (int *)v30);
    v14 = *(_DWORD *)(a1 + 28332);
    v15 = (*(_DWORD *)(v12 + 4) << v10[17])
        | (*(_DWORD *)v12 << v10[16])
        | (*v9 << v10[15])
        | (LODWORD(v30[0]) << v10[13]);
    if ( (v14 & 0x100) == 0 && v10[48] && *((_BYTE *)v9 + 64) == 1 )
      v15 |= 1 << v8[70];
    if ( v10[45] )
      v15 |= (*((unsigned __int8 *)v9 + 65) << v8[47]) | (*((unsigned __int8 *)v9 + 65) << v8[48]);
    v16 = v8[72];
    v17 = (1 << v8[69])
        | (1 << v8[44])
        | (*((unsigned __int8 *)v9 + 64) << v8[46])
        | (*((unsigned __int8 *)v9 + 64) << v8[45])
        | v15;
    if ( (v16 & 1) != 0 && v9[10] )
      v17 |= 1 << v8[49];
    if ( (v16 & 4) != 0 && v9[11] )
      v17 |= 1 << v8[50];
    v18 = v9[12];
    if ( (v16 & 2) != 0 )
    {
      if ( v18 )
      {
        v17 |= 1 << v8[52];
        goto LABEL_26;
      }
    }
    else if ( v18 )
    {
LABEL_25:
      if ( !v16 )
      {
LABEL_27:
        v29 = format_ipp_ppp;
        if ( (v14 & 0x80) != 0 )
          v17 |= 1 << v8[66];
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_csid_ver1_init_config_pxl_path",
            2564,
            "CSID[%u] cfg0_addr val %x",
            *(_DWORD *)(*(_QWORD *)a1 + 4LL),
            v17);
        cam_io_w_mb(v17, v11 + v8[4]);
        if ( *(_BYTE *)(v12 + 20) == 1 )
          cam_io_w_mb(
            (*(_DWORD *)(v12 + 16) << v10[31]) | (*(_DWORD *)(v12 + 12) << v10[30]) | (unsigned int)(1 << v10[33]),
            v11 + v8[41]);
        cam_io_w_mb((unsigned int)(v10[47] << v10[12]), v11 + v8[5]);
        if ( *((_BYTE *)v9 + 64) == 1 )
        {
          v20 = v10[62] & v9[3];
          v21 = (v10[61] & v9[4]) << v10[20];
          cam_io_w_mb(v20 | (unsigned int)v21, v11 + v8[11]);
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_csid_ver1_init_config_pxl_path",
              2593,
              "CSID:%d Horizontal crop config val: 0x%x",
              *(_DWORD *)(*(_QWORD *)a1 + 4LL),
              v20 | v21);
          v22 = v10[63] & v9[7];
          v23 = v10[64] & v9[6];
          v24 = v22 << *(_DWORD *)(v7[12] + 80LL);
          cam_io_w_mb(v23 | (unsigned int)v24, v11 + v8[12]);
          if ( (debug_mdl & 8) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_csid_ver1_init_config_pxl_path",
              2600,
              "CSID:%d Vertical Crop config val: 0x%x",
              *(_DWORD *)(*(_QWORD *)a1 + 4LL),
              v23 | v24);
        }
        cam_io_w_mb(1, v11 + v8[8]);
        cam_io_w_mb(0, v11 + v8[7]);
        cam_io_w_mb(1, v11 + v8[10]);
        cam_io_w_mb(0, v11 + v8[9]);
        cam_io_w_mb(0, v11 + v8[13]);
        cam_io_w_mb(1, v11 + v8[14]);
        cam_io_w_mb(0, v11 + v8[15]);
        cam_io_w_mb(1, v11 + v8[16]);
        v25 = v8[74];
        if ( v25 )
          cam_io_w_mb(v8[73] | v25, v11 + v8[38]);
        if ( (*(_BYTE *)(a1 + 28332) & 0x80) != 0 )
        {
          v26 = cam_io_r_mb(v11 + v8[24]);
          cam_io_w_mb(*(_DWORD *)(v7[12] + 220LL) | v26, v11 + v8[24]);
        }
        v27 = cam_io_r_mb(v11 + v8[4]);
        v28 = 1 << v10[14];
        cam_io_w_mb(v28 | v27, v11 + v8[4]);
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_csid_ver1_init_config_pxl_path",
            2635,
            "%s cfg0 0x%x",
            (const char *)(a2 + 128),
            v28 | v27);
        result = v29;
        *(_DWORD *)(a2 + 8) = 3;
        goto LABEL_49;
      }
LABEL_26:
      v17 |= 1 << v8[51];
      goto LABEL_27;
    }
    if ( !v9[11] )
    {
      if ( !v16 || !v9[10] )
        goto LABEL_27;
      goto LABEL_26;
    }
    goto LABEL_25;
  }
  __break(0x5512u);
  return cam_ife_csid_ver1_hw_reset(a1);
}
