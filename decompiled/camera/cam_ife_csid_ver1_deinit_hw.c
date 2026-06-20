__int64 __fastcall cam_ife_csid_ver1_deinit_hw(__int64 a1, unsigned int *a2, int a3)
{
  __int64 v3; // x7
  __int64 v4; // x19
  unsigned int v5; // w8
  __int64 result; // x0
  const char *v7; // x5
  __int64 v8; // x6
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x4
  __int64 v12; // x7
  __int64 v13; // x21
  unsigned int *v14; // x22
  __int64 v15; // x8
  unsigned int *v16; // x20
  __int64 v17; // x23
  int v18; // w0
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 v21; // x0
  __int64 v22; // x9
  unsigned int v23; // w21
  const char *v24; // x3
  const char *v25; // x5
  __int64 v26; // x6
  __int64 v27; // x4
  int v28; // w0
  unsigned int v29; // w8
  int v30; // w0
  __int64 v31; // x8
  int v32; // w9
  __int64 v33; // x0
  int v34; // w22
  __int64 v35; // x22
  __int64 v36; // x23
  __int64 v37; // x0

  if ( !a1 || !a2 || a3 != 152 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_deinit_hw",
      2943,
      "CSID:Invalid arguments");
    return 4294967274LL;
  }
  v3 = *a2;
  v4 = *(_QWORD *)(a1 + 3680);
  if ( (_DWORD)v3 != 3 )
  {
    v7 = "CSID:%d Invalid Res type %d";
    v8 = *(unsigned int *)(*(_QWORD *)v4 + 4LL);
    v9 = 8;
    v10 = 1;
    v11 = 2954;
    goto LABEL_11;
  }
  v5 = a2[2];
  if ( v5 != 2 )
  {
    v12 = a2[1];
    if ( (unsigned int)v12 > 9 )
    {
      v16 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver1_deinit_hw",
        2984,
        "CSID:%d Invalid res type%d",
        *(_DWORD *)(*(_QWORD *)v4 + 4LL),
        3);
      v23 = 0;
LABEL_45:
      mutex_lock(*(_QWORD *)(v4 + 8));
      v31 = *(_QWORD *)(v4 + 8);
      v32 = *(_DWORD *)(v31 + 88);
      if ( v32 )
      {
        *(_DWORD *)(v31 + 88) = v32 - 1;
        v33 = *(_QWORD *)(v4 + 8);
        v34 = *(_DWORD *)(v33 + 88);
        mutex_unlock(v33);
        if ( !v34 )
        {
          v35 = *(_QWORD *)(v4 + 8);
          v36 = **(_QWORD **)(v4 + 16);
          cam_ife_csid_ver1_disable_csi2(v4);
          cam_ife_csid_ver1_global_reset(v4);
          cam_io_w_mb(0, *(_QWORD *)(v35 + 384) + *(unsigned int *)(*(_QWORD *)(v36 + 96) + 28LL));
          if ( (unsigned int)cam_ife_csid_disable_soc_resources(v35 + 96) )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_csid_ver1_disable_hw",
              2922,
              "CSID:%d Disable CSID SOC failed",
              *(_DWORD *)(*(_QWORD *)v4 + 4LL));
          v37 = raw_spin_lock_irqsave(v4 + 28396);
          *(_BYTE *)(v4 + 28312) = 0;
          raw_spin_unlock_irqrestore(v4 + 28396, v37);
          *(_DWORD *)(*(_QWORD *)(v4 + 8) + 92LL) = 0;
          *(_DWORD *)(v4 + 48) = 0;
        }
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          2,
          "cam_ife_csid_ver1_disable_hw",
          2895,
          "Unbalanced disable_hw");
        mutex_unlock(*(_QWORD *)(v4 + 8));
      }
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_ver1_deinit_hw",
          2991,
          "De-Init CSID %d Path: %d",
          *(_DWORD *)(*(_QWORD *)v4 + 4LL),
          v16[1]);
      return v23;
    }
    if ( ((1 << v12) & 0x1F) != 0 )
    {
      if ( v5 == 3 )
      {
        v13 = **(_QWORD **)(v4 + 16);
        v14 = *(unsigned int **)(v13 + 8 * v12 + 24);
        if ( v14 )
        {
          v15 = *(_QWORD *)(v4 + 8);
LABEL_36:
          v16 = a2;
          v17 = *(_QWORD *)(v15 + 384);
          if ( v14[74] )
            cam_io_w_mb(0, v17 + v14[38]);
          v28 = cam_io_r_mb(v17 + v14[4]);
          v29 = v14[66];
          if ( (v29 & v28) == 0 )
            goto LABEL_41;
          v20 = v14[4];
          v21 = v28 & ~v29;
LABEL_40:
          cam_io_w_mb(v21, v17 + v20);
          v30 = cam_io_r_mb(v17 + v14[24]);
          cam_io_w_mb(v30 & (unsigned int)~*(_DWORD *)(*(_QWORD *)(v13 + 96) + 220LL), v17 + v14[24]);
LABEL_41:
          v23 = 0;
          v16[2] = 2;
          goto LABEL_45;
        }
        v16 = a2;
        v24 = "cam_ife_csid_ver1_deinit_rdi_path";
        v25 = "CSID:%d RDI:%d is not supported on HW";
        v26 = *(unsigned int *)(*(_QWORD *)v4 + 4LL);
        v27 = 740;
        goto LABEL_43;
      }
      v16 = a2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, unsigned int *, int, _DWORD, unsigned int))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver1_deinit_rdi_path",
        728,
        "CSID:%d %s path res type:%d res_id:%d Invalid state%d",
        *(unsigned int *)(*(_QWORD *)v4 + 4LL),
        a2 + 32,
        3,
        v12,
        v5);
LABEL_44:
      v23 = -22;
      goto LABEL_45;
    }
    if ( ((1 << v12) & 0x380) != 0 )
    {
      if ( v5 != 3 )
      {
        v16 = a2;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, unsigned int *, int, _DWORD, unsigned int))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver1_deinit_udi_path",
          789,
          "CSID:%d %s path res type:%d res_id:%d Invalid state%d",
          *(unsigned int *)(*(_QWORD *)v4 + 4LL),
          a2 + 32,
          3,
          v12,
          v5);
        goto LABEL_44;
      }
      v13 = **(_QWORD **)(v4 + 16);
      v14 = *(unsigned int **)(v13 + 8LL * (unsigned int)(v12 - 7) + 64);
      if ( v14 )
      {
        v16 = a2;
        v17 = *(_QWORD *)(*(_QWORD *)(v4 + 8) + 384LL);
        if ( v14[74] )
          cam_io_w_mb(0, v17 + v14[38]);
        v18 = cam_io_r_mb(v17 + v14[4]);
        v19 = 1LL << v14[66];
        if ( ((unsigned int)v19 & v18) == 0 )
          goto LABEL_41;
        v20 = v14[4];
        v21 = v18 & (unsigned int)~(_DWORD)v19;
        goto LABEL_40;
      }
      v16 = a2;
      v24 = "cam_ife_csid_ver1_deinit_udi_path";
      v25 = "CSID:%d RDI:%d is not supported on HW";
      v26 = *(unsigned int *)(*(_QWORD *)v4 + 4LL);
      v27 = 802;
LABEL_43:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        8,
        1,
        v24,
        v27,
        v25,
        v26);
      goto LABEL_44;
    }
    if ( v5 != 3 )
    {
      v16 = a2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, unsigned int *, int, _DWORD, unsigned int))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver1_deinit_pxl_path",
        848,
        "CSID:%d %s path res type:%d res_id:%d Invalid state%d",
        *(unsigned int *)(*(_QWORD *)v4 + 4LL),
        a2 + 32,
        3,
        v12,
        v5);
      goto LABEL_44;
    }
    v15 = *(_QWORD *)(v4 + 8);
    v13 = **(_QWORD **)(v4 + 16);
    if ( (_DWORD)v12 == 5 )
    {
      v22 = 8;
    }
    else
    {
      if ( (_DWORD)v12 != 6 )
      {
LABEL_42:
        v16 = a2;
        v24 = "cam_ife_csid_ver1_deinit_pxl_path";
        v25 = "CSID:%d PIX:%d is not supported on HW";
        v26 = *(unsigned int *)(*(_QWORD *)v4 + 4LL);
        v27 = 863;
        goto LABEL_43;
      }
      v22 = 16;
    }
    v14 = *(unsigned int **)(v13 + v22);
    if ( v14 )
      goto LABEL_36;
    goto LABEL_42;
  }
  result = 4294967274LL;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v3 = a2[1];
    v7 = "CSID:%d Res:%d already in De-init state";
    v8 = *(unsigned int *)(*(_QWORD *)v4 + 4LL);
    v9 = debug_mdl & 8;
    v10 = 4;
    v11 = 2961;
LABEL_11:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      v9,
      v10,
      "cam_ife_csid_ver1_deinit_hw",
      v11,
      v7,
      v8,
      v3);
    return 4294967274LL;
  }
  return result;
}
