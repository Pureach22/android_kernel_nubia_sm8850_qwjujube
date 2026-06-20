__int64 __fastcall cam_ife_csid_ver2_release(__int64 a1, int *a2, int a3)
{
  __int64 v3; // x19
  int v5; // w7
  int *v6; // x8
  unsigned int v7; // w9
  int v9; // w9
  unsigned int *v10; // x20
  __int64 v11; // x7
  unsigned int v12; // w20
  int v13; // w8
  int v14; // w8
  int v15; // [xsp+0h] [xbp-20h]

  if ( !a1 || !a2 || a3 != 152 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_release",
      4762,
      "CSID: Invalid args");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(a1 + 3680);
  if ( *a2 != 3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_release",
      4773,
      "CSID:%u Invalid res type:%d res id%d",
      *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL));
    return 4294967274LL;
  }
  mutex_lock(*(_QWORD *)(v3 + 31128));
  v5 = *a2;
  v6 = a2;
  if ( *a2 == 3 && (v7 = a2[1], v7 >= 0xC) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned int))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_release",
      4783,
      "CSID:%u Invalid res type:%d res id%d",
      *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL),
      3,
      v7);
  }
  else
  {
    v9 = a2[2];
    if ( (v9 & 0xFFFFFFFE) != 2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_ife_csid_ver2_release",
        4794,
        "CSID:%u res type:%d Res %d in state %d",
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        v5,
        a2[1],
        v9);
      v12 = 0;
      goto LABEL_22;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_release",
        4800,
        "CSID:%u res type :%d Resource [id:%d name:%s] rx reserve count: %u",
        *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL),
        v5,
        a2[1],
        (const char *)a2 + 128,
        *(_DWORD *)(v3 + 2128));
      v6 = a2;
    }
    v10 = *((unsigned int **)v6 + 3);
    v11 = v10[30];
    if ( (unsigned int)v11 < 4 )
    {
      cam_ife_csid_cid_release(v3 + 56LL * (unsigned int)v11 + 1824, *(_DWORD *)(*(_QWORD *)(v3 + 31120) + 4LL), v11);
      memset(v10, 0, 0x108u);
      v13 = *(_DWORD *)(v3 + 2128);
      *(_DWORD *)(v3 + 32240) = 0;
      if ( !v13 || (v14 = v13 - 1, (*(_DWORD *)(v3 + 2128) = v14) == 0) )
        cam_ife_csid_ver2_reset_csid_params(v3);
      v12 = 0;
      a2[2] = 1;
      goto LABEL_22;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_release",
      4806,
      "CSID:%d Invalid cid:%d",
      *(unsigned int *)(*(_QWORD *)(v3 + 31120) + 4LL),
      v11,
      v15);
  }
  v12 = -22;
LABEL_22:
  mutex_unlock(*(_QWORD *)(v3 + 31128));
  return v12;
}
