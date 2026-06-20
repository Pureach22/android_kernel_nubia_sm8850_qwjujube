__int64 __fastcall cam_ife_csid_ver1_stop(__int64 a1, int *a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v7; // x24
  __int64 v8; // x21
  __int64 v9; // x22
  int v10; // w0
  unsigned __int64 v11; // x20
  unsigned int v12; // w27
  const char *v13; // x28
  unsigned int v14; // w26
  unsigned int v15; // w7
  int v16; // w8
  __int64 v17; // x21
  int v18; // w22
  const char *v19; // x3
  int v20; // w6
  __int64 v21; // x4
  int v22; // w8
  int v23; // w8
  __int64 v24; // x21
  __int64 v25; // x8
  unsigned int *v26; // x25
  __int64 v27; // x8
  __int64 v28; // x25
  int v29; // w0
  const char *v30; // x3
  __int64 v31; // x6
  __int64 v32; // x4
  unsigned int v33; // w28
  unsigned int v34; // w0
  unsigned int v35; // w8
  __int64 v36; // x4
  __int64 v37; // x28
  unsigned __int64 v38; // x20
  __int64 result; // x0
  __int64 v40; // x8
  __int64 v41; // x26
  __int64 v42; // x22
  __int64 v43; // x23
  __int64 v44; // x8
  __int64 v45; // x21
  unsigned int v46; // w21
  unsigned __int64 v47; // x8
  __int64 v48; // x10
  unsigned int v49; // [xsp+20h] [xbp-20h]
  __int64 v50; // [xsp+28h] [xbp-18h]
  __int64 v51; // [xsp+28h] [xbp-18h]
  int v52; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v53; // [xsp+38h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 || (_DWORD)a3 != 24 )
  {
    v36 = 3233;
LABEL_76:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_stop",
      v36,
      "CSID: Invalid args");
    result = 4294967274LL;
    goto LABEL_83;
  }
  if ( !a2[4] )
  {
    v36 = 3240;
    goto LABEL_76;
  }
  v7 = *(_QWORD *)(a1 + 3680);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_stop",
      3248,
      "CSID:%d num_res %d",
      *(unsigned int *)(*(_QWORD *)v7 + 4LL));
  if ( *(_BYTE *)(v7 + 28319) != 1 )
    goto LABEL_16;
  v8 = *(_QWORD *)(v7 + 8);
  v9 = **(_QWORD **)(v7 + 16);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_tpg_stop",
      1368,
      "CSID:%d stop CSID TPG",
      *(_DWORD *)(*(_QWORD *)v7 + 4LL));
    if ( *(_DWORD *)(v7 + 76) )
      goto LABEL_12;
  }
  else if ( *(_DWORD *)(v7 + 76) )
  {
LABEL_12:
    v10 = cam_ife_csid_disable_ife_force_clock_on(v8 + 96, *(_DWORD *)(*(_QWORD *)(v9 + 88) + 76LL), a3, a4, a5, a6);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver1_tpg_stop",
        1374,
        "Dual isp case: Disable IFE force clk. rc %d",
        v10);
  }
  cam_io_w_mb(0, *(_QWORD *)(v8 + 384) + **(unsigned int **)(v9 + 88));
  *(_WORD *)(v7 + 28319) = 0;
LABEL_16:
  if ( !a2[4] )
  {
    result = 0;
    goto LABEL_82;
  }
  v11 = 0;
  v12 = 0;
  do
  {
    v13 = *(const char **)(*((_QWORD *)a2 + 1) + 8 * v11);
    v14 = *((_DWORD *)v13 + 1);
    v15 = v14;
    if ( (debug_mdl & 8) != 0 && (v15 = *((_DWORD *)v13 + 1), !debug_priority) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver1_stop",
        3257,
        "CSID:%d res_type %d Resource[id:%d name:%s]",
        *(_DWORD *)(*(_QWORD *)v7 + 4LL),
        *(_DWORD *)v13,
        v14,
        v13 + 128);
      v15 = *((_DWORD *)v13 + 1);
      if ( v15 > 9 )
      {
LABEL_58:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver1_stop",
          3281,
          "Invalid res_id: %u",
          v15);
        goto LABEL_19;
      }
    }
    else if ( v15 > 9 )
    {
      goto LABEL_58;
    }
    if ( ((1 << v15) & 0x1F) != 0 )
    {
      v16 = *((_DWORD *)v13 + 2);
      if ( v16 != 4 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver1_stop_rdi_path",
          994,
          "CSID:%d %s path res type:%d res_id:%d Invalid state%d",
          *(_DWORD *)(*(_QWORD *)v7 + 4LL),
          v13 + 128,
          *(_DWORD *)v13,
          v15,
          v16);
        goto LABEL_19;
      }
      v17 = *(_QWORD *)(**(_QWORD **)(v7 + 16) + 8LL * v15 + 24);
      if ( v17 )
      {
        v18 = *a2;
        if ( (*a2 & 0xFFFFFFFD) != 0 )
        {
          v19 = "cam_ife_csid_ver1_stop_rdi_path";
          v20 = *(_DWORD *)(*(_QWORD *)v7 + 4LL);
          v21 = 1020;
LABEL_33:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            v19,
            v21,
            "CSID:%d un supported stop command:%d",
            v20,
            v18);
          goto LABEL_19;
        }
LABEL_42:
        v28 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 384LL);
        cam_io_w_mb(0, v28 + *(unsigned int *)(v17 + 4));
        v29 = cam_io_r_mb(v28 + *(unsigned int *)(v17 + 24));
        cam_io_w_mb(v29 & 0xFFFFFFFC | v18, v28 + *(unsigned int *)(v17 + 24));
        goto LABEL_19;
      }
      v30 = "cam_ife_csid_ver1_stop_rdi_path";
      v31 = *(unsigned int *)(*(_QWORD *)v7 + 4LL);
      v32 = 1011;
      goto LABEL_47;
    }
    if ( ((1 << v15) & 0x380) != 0 )
    {
      v22 = *((_DWORD *)v13 + 2);
      if ( v22 != 4 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver1_stop_udi_path",
          1052,
          "CSID:%d %s path res type:%d res_id:%d Invalid state%d",
          *(_DWORD *)(*(_QWORD *)v7 + 4LL),
          v13 + 128,
          *(_DWORD *)v13,
          v15,
          v22);
        goto LABEL_19;
      }
      v17 = *(_QWORD *)(**(_QWORD **)(v7 + 16) + 8LL * (v15 - 7) + 64);
      if ( v17 )
      {
        v18 = *a2;
        if ( (*a2 & 0xFFFFFFFD) != 0 )
        {
          v19 = "cam_ife_csid_ver1_stop_udi_path";
          v20 = *(_DWORD *)(*(_QWORD *)v7 + 4LL);
          v21 = 1080;
          goto LABEL_33;
        }
        goto LABEL_42;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver1_stop_udi_path",
        1071,
        "CSID:%d RDI:%d is not supported on HW",
        *(unsigned int *)(*(_QWORD *)v7 + 4LL));
    }
    else
    {
      v23 = *((_DWORD *)v13 + 2);
      if ( v23 != 4 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver1_stop_pxl_path",
          910,
          "CSID:%d %s path res type:%d res_id:%d Invalid state%d",
          *(_DWORD *)(*(_QWORD *)v7 + 4LL),
          v13 + 128,
          *(_DWORD *)v13,
          v15,
          v23);
        goto LABEL_19;
      }
      v24 = *(_QWORD *)(v7 + 8);
      v18 = *a2;
      v25 = **(_QWORD **)(v7 + 16);
      if ( v15 == 5 )
      {
        v26 = *(unsigned int **)(v25 + 8);
        if ( !v26 )
          goto LABEL_46;
      }
      else if ( v15 != 6 || (v26 = *(unsigned int **)(v25 + 16)) == nullptr )
      {
LABEL_46:
        v30 = "cam_ife_csid_ver1_stop_pxl_path";
        v31 = *(unsigned int *)(*(_QWORD *)v7 + 4LL);
        v32 = 931;
LABEL_47:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          1,
          v30,
          v32,
          "CSID:%d PIX:%d is not supported on HW",
          v31);
        goto LABEL_19;
      }
      v50 = *((_QWORD *)v13 + 3);
      if ( v18 == 2 )
      {
        v27 = 62;
      }
      else
      {
        if ( v18 )
        {
          v19 = "cam_ife_csid_ver1_stop_pxl_path";
          v20 = *(_DWORD *)(*(_QWORD *)v7 + 4LL);
          v21 = 943;
          goto LABEL_33;
        }
        v27 = 60;
      }
      v33 = v26[v27];
      cam_io_w_mb(0, *(_QWORD *)(v24 + 384) + v26[1]);
      v34 = cam_io_r_mb(*(_QWORD *)(v24 + 384) + v26[6]);
      v35 = *(_DWORD *)(v50 + 60);
      if ( v35 > 1 )
      {
        v49 = v34;
        if ( v18 != 2 )
          goto LABEL_19;
      }
      else
      {
        v49 = v34 & 0xFFFFFFFC | v33;
        cam_io_w_mb(v49, *(_QWORD *)(v24 + 384) + v26[6]);
        v35 = *(_DWORD *)(v50 + 60);
        if ( v18 != 2 )
          goto LABEL_19;
      }
      if ( v35 == 2 )
        cam_io_w_mb(v49 & 0xFFFFFFF0 | (v26[53] << v26[57]) | v33, *(_QWORD *)(v24 + 384) + v26[6]);
    }
LABEL_19:
    ++v11;
    v12 |= 1 << v14;
  }
  while ( v11 < (unsigned int)a2[4] );
  v37 = *(_QWORD *)(v7 + 8);
  v38 = 0;
  result = 0;
  v40 = **(_QWORD **)(v7 + 16);
  v41 = v40 + 16;
  v42 = v40 + 8;
  v43 = v40 + 24;
  v51 = v40 + 64;
  while ( 2 )
  {
    if ( (v12 & 1) == 0 )
      goto LABEL_61;
    v44 = v42;
    v52 = 0;
    if ( (_DWORD)v38 == 5 || (v44 = v41, (_DWORD)v38 == 6) || (v44 = v43, v38 < 5) )
    {
LABEL_68:
      v45 = *(unsigned int *)(*(_QWORD *)v44 + 72LL);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_poll_stop_status",
          3113,
          "start polling CSID:%d res_id:%d",
          *(_DWORD *)(*(_QWORD *)v7 + 4LL),
          v38);
      result = cam_common_read_poll_timeout((const void *)(*(_QWORD *)(v37 + 384) + v45), 0x3E8u, 100000, 1u, 1, &v52);
      if ( (result & 0x80000000) != 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_poll_stop_status",
          3124,
          "CSID:%d res:%d halt failed rc %d",
          *(_DWORD *)(*(_QWORD *)v7 + 4LL),
          v38,
          result);
        result = 4294967186LL;
LABEL_79:
        if ( !a2[4] )
          goto LABEL_82;
        goto LABEL_80;
      }
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v46 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_poll_stop_status",
          3130,
          "End polling CSID:%d res_id:%d",
          *(_DWORD *)(*(_QWORD *)v7 + 4LL),
          v38);
        result = v46;
      }
LABEL_61:
      ++v38;
      v12 >>= 1;
      v43 += 8;
      if ( v38 == 12 )
        goto LABEL_79;
      continue;
    }
    break;
  }
  if ( (unsigned int)(v38 - 7) <= 2 )
  {
    v44 = v51 + 8 * (v38 - 7);
    goto LABEL_68;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_poll_stop_status",
    3107,
    "Invalid res_id: %u",
    v38);
  result = 4294967274LL;
  if ( !a2[4] )
    goto LABEL_82;
LABEL_80:
  v47 = 0;
  do
  {
    v48 = *(_QWORD *)(*((_QWORD *)a2 + 1) + 8 * v47++);
    *(_DWORD *)(v48 + 8) = 3;
  }
  while ( v47 < (unsigned int)a2[4] );
LABEL_82:
  *(_DWORD *)(v7 + 48) = 0;
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return result;
}
