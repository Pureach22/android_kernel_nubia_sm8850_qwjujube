__int64 __fastcall cam_ife_csid_ver1_release(__int64 a1, const char *a2, int a3)
{
  _QWORD *v3; // x19
  const char *v5; // x8
  const char *v6; // x5
  __int64 v7; // x6
  __int64 v8; // x4
  __int64 v9; // x7
  int v11; // w9
  unsigned int *v12; // x23
  unsigned int v13; // w20
  int v14; // w8
  int v15; // w8
  const char *v16; // x10

  if ( !a1 || !a2 || a3 != 152 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_release",
      1800,
      "CSID: Invalid args");
    return 4294967274LL;
  }
  v3 = *(_QWORD **)(a1 + 3680);
  if ( *(_DWORD *)a2 != 3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_release",
      1811,
      "CSID:%d Invalid res type:%d res id%d",
      *(unsigned int *)(*v3 + 4LL));
    return 4294967274LL;
  }
  mutex_lock(v3[1]);
  v5 = a2;
  if ( *(_DWORD *)a2 == 3 && *((_DWORD *)a2 + 1) >= 0xCu )
  {
    v6 = "CSID:%d Invalid res type:%d res id%d";
    v7 = *(unsigned int *)(*v3 + 4LL);
    v8 = 1821;
    v9 = 3;
  }
  else
  {
    v11 = *((_DWORD *)a2 + 2);
    if ( (v11 & 0xFFFFFFFE) != 2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_ife_csid_ver1_release",
        1832,
        "CSID:%d res type:%d Res %d in state %d",
        *(_DWORD *)(*v3 + 4LL),
        *(_DWORD *)a2,
        *((_DWORD *)a2 + 1),
        v11);
      v13 = 0;
      goto LABEL_25;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver1_release",
        1837,
        "CSID:%d res type :%d Resource id:%d",
        *(unsigned int *)(*v3 + 4LL));
      v5 = a2;
    }
    v12 = *((unsigned int **)v5 + 3);
    v9 = *v12;
    if ( (unsigned int)v9 < 4 )
    {
      cam_ife_csid_cid_release((__int64)&v3[7 * (unsigned int)v9 + 3377], *(_DWORD *)(*v3 + 4LL), v9);
      *(_QWORD *)v12 = 0;
      *((_QWORD *)v12 + 1) = 0;
      *((_QWORD *)v12 + 2) = 0;
      *((_QWORD *)v12 + 3) = 0;
      *((_QWORD *)v12 + 4) = 0;
      *((_QWORD *)v12 + 5) = 0;
      *((_QWORD *)v12 + 6) = 0;
      *((_QWORD *)v12 + 7) = 0;
      v12[16] = 0;
      v14 = *((_DWORD *)v3 + 10);
      if ( !v14 || (v15 = v14 - 1, (*((_DWORD *)v3 + 10) = v15) == 0) )
      {
        v15 = 0;
        v3[3538] = 0;
        v3[3537] = 0;
        *(_QWORD *)((char *)v3 + 28332) = 0;
        *(_QWORD *)((char *)v3 + 28340) = 0;
        *(_QWORD *)((char *)v3 + 28348) = 0;
        *(_QWORD *)((char *)v3 + 28356) = 0;
        *((_DWORD *)v3 + 7091) = 0;
        v3[3536] = 0;
        v3[3535] = 0;
        v3[3534] = 0;
        v3[3533] = 0;
        v3[3550] = 0;
        v3[4] = 0;
      }
      v16 = a2;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_csid_ver1_release",
          1867,
          "CSID:%d res type :%d Resource[id:%d name:%s] csi2_reserve_cnt:%d",
          *(_DWORD *)(*v3 + 4LL),
          *(_DWORD *)a2,
          *((_DWORD *)a2 + 1),
          a2 + 128,
          v15);
        v16 = a2;
      }
      v13 = 0;
      *((_DWORD *)v16 + 2) = 1;
      goto LABEL_25;
    }
    v6 = "CSID:%d Invalid cid:%d";
    v7 = *(unsigned int *)(*v3 + 4LL);
    v8 = 1843;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_ver1_release",
    v8,
    v6,
    v7,
    v9);
  v13 = -22;
LABEL_25:
  mutex_unlock(v3[1]);
  return v13;
}
