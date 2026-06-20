__int64 __fastcall cam_ife_csid_ver1_global_reset(__int64 a1)
{
  __int64 v1; // x23
  _QWORD *v3; // x24
  __int64 v4; // x9
  __int64 v5; // x20
  unsigned int *v6; // x9
  __int64 v7; // x8
  __int64 v8; // x0
  unsigned int *v9; // x8
  __int64 v10; // x9
  _DWORD *v11; // x8
  unsigned int v12; // w0
  int v13; // w6
  unsigned int v14; // w19
  int v16; // w6
  __int64 v17; // x24
  __int64 v18; // x25
  __int64 v19; // x20
  __int64 v20; // x0
  __int64 v21; // x7
  __int64 v22; // x6
  __int64 v23; // x1
  __int64 v24; // x4
  __int64 v25; // x0
  int v26; // w6

  v1 = *(_QWORD *)(a1 + 8);
  if ( *(_DWORD *)(v1 + 92) != 1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_prepare_reset",
      329,
      "CSID:%d Invalid HW State:%d",
      *(unsigned int *)(*(_QWORD *)a1 + 4LL));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver1_global_reset",
      563,
      "CSID[%d] prepare reset failed",
      v16);
    return 4294967274LL;
  }
  v3 = **(_QWORD ***)(a1 + 16);
  v4 = *(_QWORD *)(a1 + 8);
  if ( (debug_mdl & 8) != 0 )
  {
    v4 = *(_QWORD *)(a1 + 8);
    if ( !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver1_prepare_reset",
        334,
        "CSID:%d Csid reset",
        *(_DWORD *)(*(_QWORD *)a1 + 4LL));
      v4 = *(_QWORD *)(a1 + 8);
    }
  }
  v5 = raw_spin_lock_irqsave(v4 + 48);
  cam_io_w_mb(0, *(_QWORD *)(v1 + 384) + *(unsigned int *)(*v3 + 4LL));
  v6 = (unsigned int *)v3[12];
  if ( v6[39] )
  {
    cam_io_w_mb(0, *(_QWORD *)(v1 + 384) + *(unsigned int *)(v3[1] + 4LL));
    v6 = (unsigned int *)v3[12];
  }
  if ( v6[40] )
  {
    cam_io_w_mb(0, *(_QWORD *)(v1 + 384) + *(unsigned int *)(v3[2] + 4LL));
    v6 = (unsigned int *)v3[12];
  }
  v7 = *(_QWORD *)(v1 + 384);
  if ( v6[38] )
  {
    cam_io_w_mb(0, v7 + *(unsigned int *)(v3[3] + 4LL));
    v6 = (unsigned int *)v3[12];
    v7 = *(_QWORD *)(v1 + 384);
    if ( v6[38] >= 2 )
    {
      cam_io_w_mb(0, v7 + *(unsigned int *)(v3[4] + 4LL));
      v6 = (unsigned int *)v3[12];
      v7 = *(_QWORD *)(v1 + 384);
      if ( v6[38] >= 3 )
      {
        cam_io_w_mb(0, v7 + *(unsigned int *)(v3[5] + 4LL));
        v6 = (unsigned int *)v3[12];
        v7 = *(_QWORD *)(v1 + 384);
        if ( v6[38] >= 4 )
        {
          cam_io_w_mb(0, v7 + *(unsigned int *)(v3[6] + 4LL));
          v6 = (unsigned int *)v3[12];
          v7 = *(_QWORD *)(v1 + 384);
          if ( v6[38] >= 5 )
          {
            v8 = cam_io_w_mb(0, v7 + *(unsigned int *)(v3[7] + 4LL));
            v6 = (unsigned int *)v3[12];
            if ( v6[38] > 5 )
              goto LABEL_59;
            v7 = *(_QWORD *)(v1 + 384);
          }
        }
      }
    }
  }
  cam_io_w_mb(1, v7 + v6[8]);
  cam_io_w_mb(*(unsigned int *)(*v3 + 140LL), *(_QWORD *)(v1 + 384) + *(unsigned int *)(*v3 + 8LL));
  v9 = (unsigned int *)v3[12];
  if ( v9[39] )
  {
    cam_io_w_mb(v9[51], *(_QWORD *)(v1 + 384) + *(unsigned int *)(v3[1] + 8LL));
    v9 = (unsigned int *)v3[12];
  }
  if ( v9[40] )
  {
    cam_io_w_mb(v9[53], *(_QWORD *)(v1 + 384) + *(unsigned int *)(v3[2] + 8LL));
    v9 = (unsigned int *)v3[12];
  }
  v10 = *(_QWORD *)(v1 + 384);
  if ( v9[38] )
  {
    cam_io_w_mb(v9[52], v10 + *(unsigned int *)(v3[3] + 8LL));
    v9 = (unsigned int *)v3[12];
    v10 = *(_QWORD *)(v1 + 384);
    if ( v9[38] > 1 )
    {
      cam_io_w_mb(v9[52], v10 + *(unsigned int *)(v3[4] + 8LL));
      v9 = (unsigned int *)v3[12];
      v10 = *(_QWORD *)(v1 + 384);
      if ( v9[38] >= 3 )
      {
        cam_io_w_mb(v9[52], v10 + *(unsigned int *)(v3[5] + 8LL));
        v9 = (unsigned int *)v3[12];
        v10 = *(_QWORD *)(v1 + 384);
        if ( v9[38] >= 4 )
        {
          cam_io_w_mb(v9[52], v10 + *(unsigned int *)(v3[6] + 8LL));
          v9 = (unsigned int *)v3[12];
          v10 = *(_QWORD *)(v1 + 384);
          if ( v9[38] >= 5 )
          {
            v8 = cam_io_w_mb(v9[52], v10 + *(unsigned int *)(v3[7] + 8LL));
            v9 = (unsigned int *)v3[12];
            if ( v9[38] > 5 )
              goto LABEL_59;
            v10 = *(_QWORD *)(v1 + 384);
          }
        }
      }
    }
  }
  if ( v9[37] )
  {
    cam_io_w_mb(v9[54], v10 + *(unsigned int *)(v3[8] + 8LL));
    v9 = (unsigned int *)v3[12];
    v10 = *(_QWORD *)(v1 + 384);
    if ( v9[37] > 1 )
    {
      cam_io_w_mb(v9[54], v10 + *(unsigned int *)(v3[9] + 8LL));
      v9 = (unsigned int *)v3[12];
      v10 = *(_QWORD *)(v1 + 384);
      if ( v9[37] >= 3 )
      {
        v8 = cam_io_w_mb(v9[54], v10 + *(unsigned int *)(v3[10] + 8LL));
        v9 = (unsigned int *)v3[12];
        if ( v9[37] > 3 )
          goto LABEL_59;
        v10 = *(_QWORD *)(v1 + 384);
      }
    }
  }
  cam_io_w_mb(1, v10 + v9[10]);
  raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 8) + 48LL, v5);
  cam_io_w_mb(128, *(_QWORD *)(v1 + 384) + *(unsigned int *)(*v3 + 20LL));
  v11 = (_DWORD *)v3[12];
  if ( v11[39] )
  {
    cam_io_w_mb(1, *(_QWORD *)(v1 + 384) + *(unsigned int *)(v3[1] + 16LL));
    v11 = (_DWORD *)v3[12];
  }
  if ( v11[40] )
  {
    cam_io_w_mb(1, *(_QWORD *)(v1 + 384) + *(unsigned int *)(v3[2] + 16LL));
    v11 = (_DWORD *)v3[12];
  }
  if ( !v11[38]
    || (cam_io_w_mb(2, *(_QWORD *)(v1 + 384) + *(unsigned int *)(v3[3] + 16LL)), *(_DWORD *)(v3[12] + 152LL) < 2u)
    || (cam_io_w_mb(2, *(_QWORD *)(v1 + 384) + *(unsigned int *)(v3[4] + 16LL)), *(_DWORD *)(v3[12] + 152LL) < 3u)
    || (cam_io_w_mb(2, *(_QWORD *)(v1 + 384) + *(unsigned int *)(v3[5] + 16LL)), *(_DWORD *)(v3[12] + 152LL) < 4u)
    || (cam_io_w_mb(2, *(_QWORD *)(v1 + 384) + *(unsigned int *)(v3[6] + 16LL)), *(_DWORD *)(v3[12] + 152LL) < 5u)
    || (v8 = cam_io_w_mb(2, *(_QWORD *)(v1 + 384) + *(unsigned int *)(v3[7] + 16LL)), *(_DWORD *)(v3[12] + 152LL) <= 5u) )
  {
    v12 = cam_ife_csid_ver1_hw_reset(a1);
    if ( v12 )
    {
      v14 = v12;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver1_global_reset",
        570,
        "CSID[%d] hw reset failed",
        v13);
      return v14;
    }
    v17 = *(_QWORD *)(a1 + 8);
    v18 = **(_QWORD **)(a1 + 16);
    *(_DWORD *)(a1 + 26504) = 0;
    v19 = raw_spin_lock_irqsave(v17 + 48);
    *(_BYTE *)(a1 + 28316) = 1;
    cam_io_w_mb(1, *(_QWORD *)(v17 + 384) + *(unsigned int *)(*(_QWORD *)(v18 + 96) + 32LL));
    cam_io_w_mb(1, *(_QWORD *)(v17 + 384) + *(unsigned int *)(*(_QWORD *)(v18 + 96) + 40LL));
    cam_io_w_mb(
      *(unsigned int *)(*(_QWORD *)(v18 + 96) + 164LL),
      *(_QWORD *)(v17 + 384) + *(unsigned int *)(*(_QWORD *)(v18 + 96) + 16LL));
    cam_io_w_mb(1, *(_QWORD *)(v17 + 384) + *(unsigned int *)(*(_QWORD *)(v18 + 96) + 28LL));
    cam_io_w_mb(1, *(_QWORD *)(v17 + 384) + *(unsigned int *)(*(_QWORD *)(v18 + 96) + 40LL));
    raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 8) + 48LL, v19);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver1_sw_reset",
        521,
        "CSID[%d] top reset start",
        *(_DWORD *)(*(_QWORD *)a1 + 4LL));
    v20 = cam_common_wait_for_completion_timeout(a1 + 26504);
    if ( v20 )
    {
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_56;
      v21 = v20;
      v22 = *(unsigned int *)(*(_QWORD *)a1 + 4LL);
      v23 = debug_mdl & 8;
      v24 = 548;
    }
    else
    {
      v25 = cam_io_r_mb(*(_QWORD *)(v17 + 384) + *(unsigned int *)(*(_QWORD *)(v18 + 96) + 24LL));
      if ( (v25 & 1) == 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver1_sw_reset",
          543,
          "CSID:%d sw csid_reset fail rc = %d",
          *(_DWORD *)(*(_QWORD *)a1 + 4LL),
          0);
        *(_BYTE *)(a1 + 28316) = 0;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver1_global_reset",
          577,
          "CSID[%d] sw reset failed",
          v26);
        return 4294967186LL;
      }
      cam_io_w_mb(v25, *(_QWORD *)(v17 + 384) + *(unsigned int *)(*(_QWORD *)(v18 + 96) + 32LL));
      cam_io_w_mb(1, *(_QWORD *)(v17 + 384) + *(unsigned int *)(*(_QWORD *)(v18 + 96) + 40LL));
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_56;
      v23 = debug_mdl & 8;
      v22 = *(unsigned int *)(*(_QWORD *)a1 + 4LL);
      v24 = 538;
      v21 = 0;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      v23,
      4,
      "cam_ife_csid_ver1_sw_reset",
      v24,
      "CSID:%d sw reset completed %d",
      v22,
      v21);
LABEL_56:
    *(_BYTE *)(a1 + 28316) = 0;
    return 0;
  }
LABEL_59:
  __break(0x5512u);
  return cam_ife_csid_hw_ver1_hw_cfg(v8);
}
