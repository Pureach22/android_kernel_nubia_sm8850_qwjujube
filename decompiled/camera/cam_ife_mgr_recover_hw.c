__int64 __fastcall cam_ife_mgr_recover_hw(__int64 a1, int *a2)
{
  __int64 v2; // x20
  _QWORD *v3; // x27
  unsigned __int64 v6; // x8
  int v7; // w21
  unsigned __int64 v8; // x25
  __int64 v9; // x9
  _DWORD *v10; // x26
  int v11; // w6
  unsigned int v12; // w23
  __int64 v13; // x7
  const char *v14; // x5
  __int64 v15; // x4
  unsigned int v16; // w8
  unsigned int v17; // w0
  int v18; // w6
  __int64 v19; // x28
  __int64 v20; // x22
  unsigned __int64 v21; // x24
  unsigned int started; // w0
  __int64 *v23; // x24
  unsigned int v24; // w0
  __int64 *v25; // x24
  unsigned int v26; // w0
  unsigned int v27; // w0
  int v28; // w8
  __int64 v29; // x1
  __int64 v30; // x6
  __int64 v31; // x7
  const char *v32; // x5
  __int64 v33; // x4
  int v34; // w8
  __int64 v35; // x1
  _QWORD v37[2]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v38[4]; // [xsp+10h] [xbp-20h] BYREF

  v38[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = (unsigned int)a2[26];
  v7 = *a2;
  v37[1] = 0;
  memset(v38, 0, 24);
  v37[0] = 0;
  if ( !(_DWORD)v6 )
  {
    v2 = 0;
    goto LABEL_10;
  }
  v8 = 0;
  LOBYTE(v9) = 0;
  v10 = a2 + 27;
  do
  {
    if ( v8 == 8 )
    {
      while ( 1 )
      {
LABEL_60:
        __break(0x5512u);
LABEL_61:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v9 & 8,
          4,
          "cam_ife_mgr_recover_hw",
          16981,
          "RESET: CSID PATH");
        if ( !a2[26] )
          goto LABEL_62;
LABEL_43:
        v2 = *v3;
        v17 = cam_ife_hw_mgr_reset_csid(*v3, 1);
        if ( v17 )
          break;
        if ( (unsigned int)a2[26] < 2 )
          goto LABEL_62;
        v2 = *((_QWORD *)a2 + 6);
        v17 = cam_ife_hw_mgr_reset_csid(v2, 1);
        if ( v17 )
          break;
        if ( (unsigned int)a2[26] < 3 )
          goto LABEL_62;
        v2 = *((_QWORD *)a2 + 7);
        v17 = cam_ife_hw_mgr_reset_csid(v2, 1);
        if ( v17 )
          break;
        if ( (unsigned int)a2[26] < 4 )
          goto LABEL_62;
        v2 = *((_QWORD *)a2 + 8);
        v17 = cam_ife_hw_mgr_reset_csid(v2, 1);
        if ( v17 )
          break;
        if ( (unsigned int)a2[26] < 5 )
          goto LABEL_62;
        v2 = *((_QWORD *)a2 + 9);
        v17 = cam_ife_hw_mgr_reset_csid(v2, 1);
        if ( v17 )
          break;
        if ( (unsigned int)a2[26] < 6 )
          goto LABEL_62;
        v2 = *((_QWORD *)a2 + 10);
        v17 = cam_ife_hw_mgr_reset_csid(v2, 1);
        if ( v17 )
          break;
        if ( (unsigned int)a2[26] < 7 )
          goto LABEL_62;
        v2 = *((_QWORD *)a2 + 11);
        v17 = cam_ife_hw_mgr_reset_csid(v2, 1);
        if ( v17 )
          break;
        if ( (unsigned int)a2[26] < 8 )
          goto LABEL_62;
        v2 = *((_QWORD *)a2 + 12);
        v17 = cam_ife_hw_mgr_reset_csid(v2, 1);
        if ( v17 )
          break;
        if ( (unsigned int)a2[26] <= 8 )
          goto LABEL_62;
      }
      v12 = v17;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_recover_hw",
        16988,
        "Failed RESET, ctx_idx: %u",
        *(_DWORD *)(v2 + 56));
      goto LABEL_135;
    }
    v2 = *(_QWORD *)&v10[2 * v8 - 17];
    if ( v10[v8] != *(_DWORD *)(v2 + 9436) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_ife_mgr_recover_hw",
        &print_fmt_cam_log_event[21],
        "recovery for ctx:%u error-type:%d cancelled");
      v6 = (unsigned int)a2[26];
      LOBYTE(v9) = 1;
    }
    ++v8;
  }
  while ( v8 < v6 );
  if ( (v9 & 1) != 0 )
  {
LABEL_134:
    v12 = 0;
    goto LABEL_135;
  }
LABEL_10:
  v10 = &unk_393000;
  v8 = (unsigned __int64)&unk_393000;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_recover_hw",
      16957,
      "ErrorType = %d",
      v7);
  v3 = a2 + 10;
  if ( !*((_QWORD *)a2 + 5) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_recover_hw",
      16961,
      "No context is affected but recovery called");
    goto LABEL_134;
  }
  v11 = a2[26];
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_recover_hw",
      16966,
      "STOP: Number of affected context: %d",
      v11);
    if ( !a2[26] )
      goto LABEL_38;
LABEL_17:
    v37[0] = *v3;
    v12 = cam_ife_mgr_stop_hw_in_overflow(v37);
    if ( !v12 )
    {
      v16 = a2[26];
      if ( v16 < 2 )
        goto LABEL_39;
      v37[0] = *((_QWORD *)a2 + 6);
      v12 = cam_ife_mgr_stop_hw_in_overflow(v37);
      if ( !v12 )
      {
        v16 = a2[26];
        if ( v16 < 3 )
          goto LABEL_39;
        v37[0] = *((_QWORD *)a2 + 7);
        v12 = cam_ife_mgr_stop_hw_in_overflow(v37);
        if ( !v12 )
        {
          v16 = a2[26];
          if ( v16 < 4 )
            goto LABEL_39;
          v37[0] = *((_QWORD *)a2 + 8);
          v12 = cam_ife_mgr_stop_hw_in_overflow(v37);
          if ( !v12 )
          {
            v16 = a2[26];
            if ( v16 < 5 )
              goto LABEL_39;
            v37[0] = *((_QWORD *)a2 + 9);
            v12 = cam_ife_mgr_stop_hw_in_overflow(v37);
            if ( !v12 )
            {
              v16 = a2[26];
              if ( v16 < 6 )
                goto LABEL_39;
              v37[0] = *((_QWORD *)a2 + 10);
              v12 = cam_ife_mgr_stop_hw_in_overflow(v37);
              if ( !v12 )
              {
                v16 = a2[26];
                if ( v16 < 7 )
                  goto LABEL_39;
                v37[0] = *((_QWORD *)a2 + 11);
                v12 = cam_ife_mgr_stop_hw_in_overflow(v37);
                if ( !v12 )
                {
                  v16 = a2[26];
                  if ( v16 < 8 )
                    goto LABEL_39;
                  v37[0] = *((_QWORD *)a2 + 12);
                  v12 = cam_ife_mgr_stop_hw_in_overflow(v37);
                  if ( !v12 )
                  {
                    v16 = a2[26];
                    if ( v16 > 8 )
                      goto LABEL_60;
                    goto LABEL_39;
                  }
                }
              }
            }
          }
        }
      }
    }
    v13 = *(unsigned int *)(v2 + 56);
    v14 = "CTX stop failed(%d) ctx_idx: %u";
    v15 = 16973;
LABEL_19:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_recover_hw",
      v15,
      v14,
      v12,
      v13);
    goto LABEL_135;
  }
  if ( v11 )
    goto LABEL_17;
LABEL_38:
  v16 = 0;
LABEL_39:
  if ( !dword_3A8504 )
    goto LABEL_134;
  LOBYTE(v9) = debug_mdl;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    goto LABEL_61;
  if ( v16 )
    goto LABEL_43;
LABEL_62:
  if ( (*((_QWORD *)v10 + 458) & 8) != 0 && (LODWORD(v9) = *(_DWORD *)(v8 + 3676), !(_DWORD)v9) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      *((_QWORD *)v10 + 458) & 8LL,
      4,
      "cam_ife_mgr_recover_hw",
      16993,
      "RESET: Calling VFE reset");
    if ( a2[1] )
LABEL_65:
      cam_ife_mgr_reset_vfe_hw(a1, 0);
  }
  else if ( a2[1] )
  {
    goto LABEL_65;
  }
  if ( a2[2] )
    cam_ife_mgr_reset_vfe_hw(a1, 1);
  if ( a2[3] )
    cam_ife_mgr_reset_vfe_hw(a1, 2);
  if ( a2[4] )
    cam_ife_mgr_reset_vfe_hw(a1, 3);
  if ( a2[5] )
    cam_ife_mgr_reset_vfe_hw(a1, 4);
  if ( a2[6] )
    cam_ife_mgr_reset_vfe_hw(a1, 5);
  if ( a2[7] )
    cam_ife_mgr_reset_vfe_hw(a1, 6);
  if ( a2[8] )
    cam_ife_mgr_reset_vfe_hw(a1, 7);
  v18 = a2[26];
  if ( (*((_QWORD *)v10 + 458) & 8) != 0 )
  {
    LODWORD(v9) = *(_DWORD *)(v8 + 3676);
    if ( !(_DWORD)v9 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *((_QWORD *)v10 + 458) & 8LL,
        4,
        "cam_ife_mgr_recover_hw",
        17001,
        "START: Number of affected context: %d",
        v18);
      if ( !a2[26] )
        goto LABEL_129;
LABEL_83:
      v19 = 0;
      a1 = 9376;
      while ( 1 )
      {
        if ( v19 == 8 )
          goto LABEL_60;
        v2 = v3[v19];
        v38[0] = v2;
        if ( !v2 || (*(_BYTE *)(v2 + 9376) & 1) == 0 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_mgr_restart_hw",
            8773,
            "Invalid context is used");
          v12 = -1;
          goto LABEL_123;
        }
        if ( (*((_QWORD *)v10 + 458) & 8) != 0 && !*(_DWORD *)(v8 + 3676) )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            *((_QWORD *)v10 + 458) & 8LL,
            4,
            "cam_ife_mgr_restart_hw",
            8777,
            "START IFE OUT ... in ctx id:%u",
            *(_DWORD *)(v2 + 56));
        cam_tasklet_start(*(_QWORD *)(v2 + 16));
        if ( *(_DWORD *)(v2 + 8512) )
        {
          v20 = 0;
          v21 = 0;
          while ( 1 )
          {
            started = cam_ife_hw_mgr_start_hw_res(*(_QWORD *)(v2 + 272) + v20, v2);
            if ( started )
              break;
            ++v21;
            v20 += 128;
            if ( v21 >= *(unsigned int *)(v2 + 8512) )
              goto LABEL_94;
          }
          v31 = *(unsigned int *)(v2 + 56);
          v12 = started;
          v32 = "Can not start IFE OUT (%d), ctx_idx: %u";
          v33 = 8787;
          v30 = (unsigned int)v21;
LABEL_119:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_mgr_restart_hw",
            v33,
            v32,
            v30,
            v31);
LABEL_120:
          cam_ife_mgr_stop_hw_in_overflow(v38);
          if ( (*((_QWORD *)v10 + 458) & 8) != 0 && !*(_DWORD *)(v8 + 3676) )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              *((_QWORD *)v10 + 458) & 8LL,
              4,
              "cam_ife_mgr_restart_hw",
              8829,
              "Exit...(rc=%d), ctx_idx: %u",
              v12,
              *(_DWORD *)(v2 + 56));
LABEL_123:
          v13 = *(unsigned int *)(v2 + 56);
          v14 = "CTX start failed(%d) ctx_idx: %u";
          v15 = 17010;
          goto LABEL_19;
        }
LABEL_94:
        if ( (*((_QWORD *)v10 + 458) & 8) != 0 && !*(_DWORD *)(v8 + 3676) )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            *((_QWORD *)v10 + 458) & 8LL,
            4,
            "cam_ife_mgr_restart_hw",
            8792,
            "START IFE SRC ... in ctx id:%u",
            *(_DWORD *)(v2 + 56));
        v23 = (__int64 *)(v2 + 256);
        while ( 1 )
        {
          v23 = (__int64 *)*v23;
          if ( v23 == (__int64 *)(v2 + 256) )
            break;
          v24 = cam_ife_hw_mgr_start_hw_res(v23, v2);
          if ( v24 )
          {
            v30 = *((unsigned int *)v23 + 5);
            v31 = *(unsigned int *)(v2 + 56);
            v12 = v24;
            v32 = "Can not start IFE BUS RD (%d), ctx_idx: %u";
            v33 = 8799;
            goto LABEL_119;
          }
        }
        v25 = (__int64 *)(v2 + 224);
        while ( 1 )
        {
          v25 = (__int64 *)*v25;
          if ( v25 == (__int64 *)(v2 + 224) )
            break;
          v26 = cam_ife_hw_mgr_start_hw_res(v25, v2);
          if ( v26 )
          {
            v30 = *((unsigned int *)v25 + 5);
            v31 = *(unsigned int *)(v2 + 56);
            v12 = v26;
            v32 = "Can not start IFE MUX (%d), ctx_idx: %u";
            v33 = 8809;
            goto LABEL_119;
          }
        }
        if ( (*((_QWORD *)v10 + 458) & 8) != 0 && !*(_DWORD *)(v8 + 3676) )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            *((_QWORD *)v10 + 458) & 8LL,
            4,
            "cam_ife_mgr_restart_hw",
            8814,
            "START CSID HW ... in ctx id:%u",
            *(_DWORD *)(v2 + 56));
        v27 = cam_ife_mgr_csid_start_hw(v2, 0, 12, 0, 0, 0, 0);
        if ( v27 )
        {
          v12 = v27;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_mgr_restart_hw",
            8819,
            "Error in starting CSID HW in ctx id:%u",
            *(_DWORD *)(v2 + 56));
          goto LABEL_120;
        }
        v9 = *((_QWORD *)v10 + 458);
        v28 = *(_DWORD *)(v8 + 3676);
        a1 = 9376;
        v29 = v9 & 8;
        if ( (v9 & 8) != 0 && !v28 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v29,
            4,
            "cam_ife_mgr_restart_hw",
            8824,
            "Exit...(success), ctx_idx: %u",
            *(_DWORD *)(v2 + 56));
          v9 = *((_QWORD *)v10 + 458);
          v28 = *(_DWORD *)(v8 + 3676);
          v29 = v9 & 8;
          if ( (v9 & 8) != 0 )
          {
LABEL_112:
            if ( !v28 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v29,
                4,
                "cam_ife_mgr_recover_hw",
                17014,
                "Started resources rc (%d) ctx_idx: %u",
                0,
                *(_DWORD *)(v2 + 56));
          }
        }
        else if ( (v9 & 8) != 0 )
        {
          goto LABEL_112;
        }
        if ( ++v19 >= (unsigned __int64)(unsigned int)a2[26] )
          goto LABEL_129;
      }
    }
  }
  if ( v18 )
    goto LABEL_83;
LABEL_129:
  *(_DWORD *)(v2 + 8844) = 0;
  v34 = *(_DWORD *)(v8 + 3676);
  v35 = *((_QWORD *)v10 + 458) & 8LL;
  if ( (*((_QWORD *)v10 + 458) & 8) != 0 && !v34 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v35,
      4,
      "cam_ife_mgr_recover_hw",
      17018,
      "Recovery Done rc (%d)",
      0);
    v34 = *(_DWORD *)(v8 + 3676);
    v35 = *((_QWORD *)v10 + 458) & 8LL;
    v12 = 0;
    if ( v35 )
      goto LABEL_132;
  }
  else
  {
    v12 = 0;
    if ( !v35 )
      goto LABEL_135;
LABEL_132:
    if ( !v34 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v35,
        4,
        "cam_ife_mgr_recover_hw",
        17020,
        "Exit: ErrorType = %d",
        v7);
      goto LABEL_134;
    }
  }
LABEL_135:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(a2, 0);
  else
    kvfree(a2);
  _ReadStatusReg(SP_EL0);
  return v12;
}
