__int64 __fastcall cam_ife_csid_ver2_deinit_hw(__int64 a1, unsigned int *a2, int a3)
{
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x7
  __int64 result; // x0
  const char *v7; // x5
  __int64 v8; // x6
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x4
  unsigned int *v13; // x8
  unsigned int v14; // w0
  unsigned int v15; // w9
  unsigned int v16; // w21
  __int64 v17; // x8
  int v18; // w9
  __int64 v19; // x22
  __int64 *v20; // x8
  __int64 v21; // x24
  __int64 v22; // x25
  __int64 v23; // x23
  __int64 v24; // x0
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x1
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x8

  if ( !a1 || !a2 || a3 != 152 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_deinit_hw",
      7052,
      "CSID:Invalid arguments");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(a1 + 3680);
  v4 = *(_QWORD *)(v3 + 31128);
  if ( !*(_DWORD *)(v4 + 92) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "cam_ife_csid_ver2_deinit_hw",
      7062,
      "CSID:%u already powered down",
      *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL));
    return 4294967274LL;
  }
  v5 = *a2;
  if ( (_DWORD)v5 != 3 )
  {
    v7 = "CSID:%u Invalid Res type %d";
    v8 = *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL);
    v9 = 8;
    v10 = 1;
    v11 = 7069;
    goto LABEL_13;
  }
  if ( a2[2] == 2 )
  {
    result = 4294967274LL;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v5 = a2[1];
      v7 = "CSID:%u Res:%d already in De-init state";
      v8 = *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL);
      v9 = debug_mdl & 8;
      v10 = 4;
      v11 = 7076;
LABEL_13:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        v9,
        v10,
        "cam_ife_csid_ver2_deinit_hw",
        v11,
        v7,
        v8,
        v5);
      return 4294967274LL;
    }
    return result;
  }
  mutex_lock(v4);
  v13 = a2;
  if ( a2[2] != 3 )
  {
    v15 = a2[1];
    if ( v15 < 7 || v15 - 10 <= 1 )
    {
      v14 = cam_ife_csid_ver2_disable_path(1, v3, a2, 0);
      v13 = a2;
      goto LABEL_19;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_deinit_hw",
      7099,
      "CSID:%u Invalid res type%d",
      *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
      *a2);
    v13 = a2;
  }
  v14 = 0;
LABEL_19:
  v16 = v14;
  v13[2] = 2;
  v17 = *(_QWORD *)(v3 + 31128);
  v18 = *(_DWORD *)(v17 + 88);
  if ( v18 )
  {
    *(_DWORD *)(v17 + 88) = v18 - 1;
    v19 = *(_QWORD *)(v3 + 31128);
    if ( !*(_DWORD *)(v19 + 88) )
    {
      v20 = *(__int64 **)(v3 + 31136);
      v21 = *(_QWORD *)(v19 + 3392);
      v22 = *v20;
      v23 = *(_QWORD *)(*v20 + 232);
      ((void (__fastcall *)(__int64, __int64))cam_ife_csid_ver2_disable_csi2)(1, v3);
      v24 = cam_io_w_mb(0, *(_QWORD *)(v19 + 384) + *(unsigned int *)(*(_QWORD *)(v22 + 120) + 52LL));
      v27 = *(unsigned int *)(v3 + 32208);
      if ( (_DWORD)v27 )
      {
        v24 = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v3 + 30984));
        if ( (_DWORD)v24 )
          v24 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  2,
                  "cam_ife_csid_ver2_disable_core",
                  7005,
                  "CSID:%d Failed to unsubscribe reset irq",
                  *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL));
        *(_DWORD *)(v3 + 32208) = 0;
      }
      if ( v23 && (*(_BYTE *)(v21 + 12) & 1) == 0 )
      {
        v28 = *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL);
        if ( (unsigned int)v28 > 7
          || (v24 = cam_io_w_mb(*(unsigned int *)(v23 + 100), *(_QWORD *)(v19 + 408) + *(unsigned int *)(v23 + 4 * v28)),
              v29 = *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL),
              (unsigned int)v29 > 7) )
        {
          __break(0x5512u);
          return cam_ife_csid_ver2_disable_path(v24, v27, v25, v26);
        }
        cam_io_w_mb(*(unsigned int *)(v23 + 104), *(_QWORD *)(v19 + 408) + *(unsigned int *)(v23 + 4 * v29 + 32));
      }
      raw_spin_lock_bh(v3 + 30968);
      v30 = *(_QWORD *)(v3 + 31128);
      *(_BYTE *)(v3 + 2148) = 0;
      *(_DWORD *)(v30 + 92) = 0;
      *(_BYTE *)(v3 + 2159) = 0;
      raw_spin_unlock_bh(v3 + 30968);
      if ( (unsigned int)cam_ife_csid_disable_soc_resources(v19 + 96) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_disable_core",
          7035,
          "CSID:%u Disable CSID SOC failed",
          *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL));
      *(_QWORD *)(v3 + 2136) = 0;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "cam_ife_csid_ver2_disable_core",
      6976,
      "CSID[%u] Unbalanced disable_hw",
      *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL));
  }
  mutex_unlock(*(_QWORD *)(v3 + 31128));
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_deinit_hw",
      7108,
      "De-Init CSID %d Path: %d",
      *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
      a2[1]);
  return v16;
}
