__int64 __fastcall cam_ife_csid_ver1_reset(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x19
  unsigned int v4; // w21
  __int64 v5; // x25
  __int64 v6; // x24
  int v7; // w7
  unsigned int v8; // w9
  const char *v9; // x5
  __int64 v10; // x1
  __int64 v11; // x6
  __int64 v12; // x2
  __int64 v13; // x4
  const char *v14; // x3
  const char *v15; // x5
  __int64 v16; // x4
  _QWORD *v18; // x21
  __int64 v19; // x27
  unsigned int v20; // w0
  __int64 v21; // x8
  unsigned int v22; // w21
  int v23; // w28
  unsigned int v24; // w0
  _QWORD *v25; // x26
  __int64 v26; // x0
  __int64 v27; // x21
  _QWORD *v28; // [xsp+8h] [xbp-8h]

  v2 = *(_QWORD **)(a1 + 3680);
  mutex_lock(v2[1]);
  if ( *(_DWORD *)a2 == 1 )
  {
    v5 = v2[1];
    if ( *(_DWORD *)(v5 + 92) != 1 )
    {
      v9 = "CSID:%d Invalid hw state :%d";
      v11 = *(unsigned int *)(*v2 + 4LL);
      v10 = 8;
      v12 = 1;
      v13 = 604;
      goto LABEL_11;
    }
    v6 = *(_QWORD *)(a2 + 8);
    v7 = *(_DWORD *)(v6 + 4);
    v8 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 3);
    if ( (unsigned int)v7 >= 0xC )
    {
      if ( !v8 )
      {
LABEL_12:
        v4 = -22;
        goto LABEL_13;
      }
      v9 = "CSID:%d Invalid res id%d";
      v10 = debug_mdl & 8;
      v11 = *(unsigned int *)(*v2 + 4LL);
      v12 = 4;
      v13 = 610;
LABEL_11:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        v10,
        v12,
        "cam_ife_csid_path_reset",
        v13,
        v9,
        v11);
      goto LABEL_12;
    }
    v18 = *(_QWORD **)v2[2];
    if ( v8 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_path_reset",
        615,
        "CSID:%d reset Resource[id:%d name:%s]",
        *(unsigned int *)(*v2 + 4LL));
      v7 = *(_DWORD *)(v6 + 4);
      if ( v7 <= 5 )
      {
LABEL_19:
        if ( (unsigned int)v7 >= 4 )
        {
          if ( v7 != 5 )
            goto LABEL_36;
          v19 = v18[1];
          if ( !v19 )
            goto LABEL_36;
        }
        else
        {
          v19 = v18[(unsigned int)v7 + 3];
          if ( !v19 )
          {
LABEL_36:
            v14 = "cam_ife_csid_path_reset";
            v15 = "Invalid res %d";
            v16 = 641;
            goto LABEL_9;
          }
        }
LABEL_31:
        v20 = cam_io_r_mb(*(_QWORD *)(v5 + 384) + *(unsigned int *)(v19 + 4));
        v21 = v18[12];
        v28 = v18;
        v22 = v20;
        v23 = *(_DWORD *)(v21 + 44);
        v24 = cam_ife_csid_convert_res_to_irq_reg(*(_DWORD *)(v6 + 4));
        if ( v24 > 0x10 )
        {
          __break(0x5512u);
          return ((__int64 (*)(void))cam_ife_csid_ver1_global_reset)();
        }
        v25 = &v2[4 * v24];
        *((_DWORD *)v25 + 6626) = 0;
        cam_io_w_mb((1 << v23) | v22, *(_QWORD *)(v5 + 384) + *(unsigned int *)(v19 + 4));
        cam_io_w_mb(*(unsigned int *)(v28[12] + 176LL), *(_QWORD *)(v5 + 384) + *(unsigned int *)(v19 + 68));
        v26 = cam_common_wait_for_completion_timeout((__int64)(v25 + 3313));
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v27 = v26;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_csid_path_reset",
            662,
            "CSID:%d resource[id:%d  name:%s] reset done",
            *(_DWORD *)(*v2 + 4LL),
            *(_DWORD *)(v6 + 4),
            (const char *)(v6 + 128));
          if ( v27 )
            goto LABEL_35;
        }
        else if ( v26 )
        {
LABEL_35:
          v4 = 0;
          goto LABEL_13;
        }
        v4 = -110;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_path_reset",
          668,
          "CSID:%d Res id %d fail rc = %d",
          *(_DWORD *)(*v2 + 4LL),
          *(_DWORD *)(v6 + 4),
          -110);
        goto LABEL_13;
      }
    }
    else if ( v7 <= 5 )
    {
      goto LABEL_19;
    }
    if ( (unsigned int)(v7 - 7) >= 3 )
    {
      if ( v7 != 6 )
        goto LABEL_36;
      v19 = v18[2];
      if ( !v19 )
        goto LABEL_36;
    }
    else
    {
      v19 = v18[(unsigned int)(v7 - 7) + 8];
      if ( !v19 )
        goto LABEL_36;
    }
    goto LABEL_31;
  }
  if ( *(_DWORD *)a2 )
  {
    v14 = "cam_ife_csid_ver1_reset";
    v15 = "CSID:Invalid reset type :%d";
    v16 = 697;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      v14,
      v16,
      v15);
    goto LABEL_12;
  }
  v4 = cam_ife_csid_ver1_global_reset(v2);
LABEL_13:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver1_reset",
      704,
      "CSID[%d] reset type :%d",
      *(_DWORD *)(*v2 + 4LL),
      *(_DWORD *)a2);
  mutex_unlock(v2[1]);
  return v4;
}
