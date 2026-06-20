__int64 __fastcall cam_hw_cdm_submit_bl(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x27
  __int64 v7; // x28
  unsigned __int64 v8; // x22
  unsigned int v9; // w25
  unsigned int (*v10)(void); // x9
  unsigned int v11; // w25
  __int64 v12; // x8
  unsigned int v13; // w6
  unsigned int v14; // w7
  __int64 v15; // x25
  __int64 v16; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x12
  int v19; // w0
  unsigned int *v20; // x26
  __int64 v22; // x6
  __int64 v23; // x25
  __int64 v24; // x6
  int v25; // w25
  unsigned int v26; // w0
  const void *v27; // x6
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x7
  unsigned int v31; // w0
  unsigned __int8 *v32; // x8
  unsigned __int64 v33; // x12
  int v34; // w9
  __int64 v35; // x8
  unsigned int v36; // w0
  __int64 v37; // x0
  const char *v38; // x5
  __int64 v39; // x4
  const char *v40; // x5
  __int64 v41; // x7
  __int64 v42; // x4
  __int64 v43; // x6
  const char *v44; // x5
  __int64 v45; // x4
  __int64 v46; // [xsp+0h] [xbp-50h]
  unsigned __int64 v47; // [xsp+20h] [xbp-30h]
  __int64 v48; // [xsp+28h] [xbp-28h]
  int v49; // [xsp+30h] [xbp-20h]
  int v50; // [xsp+34h] [xbp-1Ch]
  int v51; // [xsp+34h] [xbp-1Ch]
  unsigned __int64 v52; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v53[2]; // [xsp+40h] [xbp-10h] BYREF

  v53[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 8);
  v7 = *(_QWORD *)(a1 + 3680);
  v8 = ((unsigned __int64)*(unsigned int *)(a3 + 328) >> 8) & 0xF;
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_submit_bl",
      1039,
      "Submit bl to %s%u",
      *(const char **)(a1 + 152),
      *(_DWORD *)(a1 + 116));
    if ( (unsigned int)v8 >= 4 )
      goto LABEL_4;
  }
  else if ( (unsigned int)v8 >= 4 )
  {
LABEL_4:
    v9 = -22;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_submit_bl",
      1043,
      "Invalid handle 0x%x, rc = %d",
      *(_DWORD *)(a3 + 328),
      -22);
    goto LABEL_18;
  }
  v10 = *(unsigned int (**)(void))(*(_QWORD *)(v7 + 240) + 40LL);
  v11 = *(_DWORD *)(*(_QWORD *)(v6 + 24) + 20LL) - *(_DWORD *)(*(_QWORD *)(v6 + 24) + 24LL);
  if ( *((_DWORD *)v10 - 1) != -605791253 )
    __break(0x8229u);
  if ( v11 < 4 * v10() )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_submit_bl",
      1049,
      "Insufficient memory for GenIRQ Command");
    v9 = -12;
    goto LABEL_18;
  }
  v12 = v7 + 640LL * (unsigned int)v8;
  v13 = *(_DWORD *)(*(_QWORD *)(a2 + 8) + 20LL);
  v14 = *(_DWORD *)(v12 + 2404);
  v15 = v12 + 2296;
  if ( v13 > v14 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      3,
      "cam_hw_cdm_submit_bl",
      1060,
      "requested BL more than max size, cnt=%d max=%d",
      v13,
      v14);
  mutex_lock(v15 + 56);
  mutex_lock(a3 + 280);
  if ( (*(_QWORD *)(v7 + 4856) & 0x20) != 0
    || (*(_QWORD *)(v7 + 4856) & 0x10) != 0
    || (*(_QWORD *)(v7 + 4856) & 0x100) != 0 )
  {
    mutex_unlock(a3 + 280);
    mutex_unlock(v15 + 56);
    v9 = -11;
    goto LABEL_18;
  }
  v16 = *(_QWORD *)(a2 + 8);
  v48 = v15;
  LODWORD(v17) = *(_DWORD *)(v16 + 20);
  if ( !(_DWORD)v17 )
  {
    v9 = 0;
    goto LABEL_85;
  }
  v18 = 0;
  v19 = 0;
  v20 = (unsigned int *)(v6 + 48);
  v49 = 0;
  while ( 1 )
  {
    v52 = 0;
    v53[0] = 0;
    v22 = v20[3];
    v47 = v18;
    if ( (unsigned int)(v22 - 1048577) >> 20 != 4095 )
    {
      v38 = "cmd len=: %d is invalid_ent: %d, num_cmd_ent: %d";
      v30 = (unsigned int)-v49;
      v39 = 1086;
      LODWORD(v46) = v17;
LABEL_83:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, unsigned __int64, __int64))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_submit_bl",
        v39,
        v38,
        v22,
        v30,
        v46);
      goto LABEL_84;
    }
    if ( (*(_QWORD *)(v7 + 4856) & 0x20) != 0
      || (*(_QWORD *)(v7 + 4856) & 0x10) != 0
      || (*(_QWORD *)(v7 + 4856) & 0x100) != 0 )
    {
      break;
    }
    v23 = v48;
    if ( !v19 )
    {
      v19 = cam_hw_cdm_wait_for_bl_fifo(a1, (int)v17 + v49, v8);
      if ( v19 < 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_hw_cdm_submit_bl",
          1110,
          "wait for bl fifo failed for ent: %u",
          -v49);
        v9 = -5;
        goto LABEL_85;
      }
      v16 = *(_QWORD *)(a2 + 8);
    }
    v24 = *(unsigned int *)(v16 + 16);
    if ( (_DWORD)v24 == 1 )
    {
      v27 = *(const void **)v20;
      if ( !*(_QWORD *)v20 )
      {
        v44 = "hw_iova is null for ent: %d";
        v24 = (unsigned int)-v49;
        v45 = 1129;
        goto LABEL_81;
      }
      v53[0] = *(_QWORD *)v20;
      v28 = v20[2] + v20[3];
      v52 = v28;
    }
    else
    {
      if ( (_DWORD)v24 )
      {
        v44 = "Only mem hdl/hw va type is supported %d";
        v45 = 1139;
LABEL_81:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          1,
          1,
          "cam_hw_cdm_submit_bl",
          v45,
          v44,
          v24);
        goto LABEL_84;
      }
      v25 = v19;
      v26 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD *, unsigned __int64 *, _QWORD, _QWORD))cam_mem_get_io_buf)(
              *v20,
              *(unsigned int *)(v7 + 224),
              v53,
              &v52,
              0,
              0);
      if ( v26 )
      {
        v22 = v26;
        v38 = "Getting a hwva from mem_hdl failed. rc: %d, cmd_ent: %u";
        v30 = (unsigned int)-v49;
        v39 = 1123;
        goto LABEL_83;
      }
      v28 = v52;
      v27 = (const void *)v53[0];
      v19 = v25;
      v23 = v48;
    }
    v29 = v20[2];
    if ( !v27 || !v28 || v28 < v29 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned __int64, _DWORD, _DWORD))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_submit_bl",
        1245,
        "Sanity check failed for cdm_cmd: %d, Hdl: 0x%x, len: %zu, offset: 0x%x, num_cmds: %d",
        (unsigned int)-v49,
        *v20,
        v28,
        v29,
        *(_DWORD *)(*(_QWORD *)(a2 + 8) + 20LL));
LABEL_84:
      v9 = -22;
      goto LABEL_85;
    }
    v30 = v20[3];
    if ( v28 - v29 < v30 )
    {
      v38 = "Not enough buffer cmd offset: %u cmd length: %u";
      v39 = 1149;
      v22 = (unsigned int)v29;
      goto LABEL_83;
    }
    v50 = v19;
    if ( (debug_mdl & 1) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_hw_cdm_submit_bl",
        1155,
        "Got the hwva: %pK, type: %u",
        v27,
        *(_DWORD *)(*(_QWORD *)(a2 + 8) + 16LL));
      LODWORD(v29) = v20[2];
      LODWORD(v30) = v20[3];
      LODWORD(v27) = v53[0];
    }
    if ( (cam_hw_cdm_bl_write(
            a1,
            (int)v29 + (int)v27,
            (int)v30 - 1,
            *(unsigned __int8 *)(v23 + 104),
            *((_BYTE *)v20 + 17),
            v8)
        & 1) != 0 )
    {
      v40 = "Hw bl write failed %d:%d";
      v41 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 20LL);
      v42 = 1165;
      v43 = (unsigned int)-v49;
LABEL_78:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_submit_bl",
        v42,
        v40,
        v43,
        v41);
      v9 = -5;
      goto LABEL_85;
    }
    if ( (cam_hw_cdm_commit_bl_write(a1, v8) & 1) != 0 )
    {
      v41 = *(unsigned __int8 *)(v23 + 104);
      v40 = "Commit failed for BL: %d Tag: %u";
      v43 = (unsigned int)-v49;
      v42 = 1172;
      goto LABEL_78;
    }
    if ( (debug_mdl & 1) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_hw_cdm_submit_bl",
        1179,
        "Commit success for BL: %d of %d, Tag: %u",
        v47 + 1,
        *(_DWORD *)(*(_QWORD *)(a2 + 8) + 20LL),
        *(unsigned __int8 *)(v23 + 104));
    v19 = v50 - 1;
    *(_BYTE *)(v23 + 104) = (unsigned __int8)(*(_BYTE *)(v23 + 104) + 1) % (unsigned int)(*(_DWORD *)(v23 + 108) - 1);
    if ( *((_BYTE *)v20 + 16) == 1 )
    {
      if ( v50 == 1 )
      {
        v19 = cam_hw_cdm_wait_for_bl_fifo(a1, 1u, v8);
        if ( v19 < 0 )
        {
          v40 = "wait for bl fifo failed %d:%d";
          v41 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 20LL);
          v42 = 1191;
          v43 = (unsigned int)-v49;
          goto LABEL_78;
        }
      }
      v51 = v19;
      v31 = cam_hw_cdm_submit_debug_gen_irq(a1, a2, v8);
      if ( v31 )
      {
        v9 = v31;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          2,
          "cam_hw_cdm_submit_bl",
          1208,
          "Failed in submitting the debug gen entry. rc: %d",
          v31);
LABEL_61:
        v33 = v47;
        v19 = v51;
        goto LABEL_20;
      }
      if ( (debug_mdl & 1) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_hw_cdm_submit_bl",
          1201,
          "Commit success for Dbg_GenIRQ_BL, Tag: %d",
          *(unsigned __int8 *)(v48 + 104));
      v19 = v51 - 1;
      *(_BYTE *)(v48 + 104) = (unsigned __int8)(*(_BYTE *)(v48 + 104) + 1) % (unsigned int)(*(_DWORD *)(v48 + 108) - 1);
    }
    v32 = *(unsigned __int8 **)(a2 + 8);
    v33 = v47;
    v34 = *v32;
    v35 = (unsigned int)(*((_DWORD *)v32 + 5) - 1);
    if ( v34 == 1 )
    {
      if ( v47 == v35 )
      {
        if ( !v19 )
        {
          v19 = cam_hw_cdm_wait_for_bl_fifo(a1, 1u, v8);
          if ( v19 < 0 )
          {
            v40 = "wait for bl fifo failed %d:%d";
            v41 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 20LL);
            v42 = 1220;
            v43 = (unsigned int)-v49;
            goto LABEL_78;
          }
        }
        v51 = v19;
        *(_BYTE *)(v6 + 1) = *(_DWORD *)(v7 + 4872) == 2;
        v36 = cam_hw_cdm_submit_gen_irq(a1, (int *)a2, v8);
        if ( !v36 )
        {
          v33 = v47;
          v19 = v51;
          if ( (debug_mdl & 1) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              1,
              4,
              "cam_hw_cdm_submit_bl",
              1234,
              "Commit success for GenIRQ_BL, Tag: %d",
              *(unsigned __int8 *)(v48 + 104));
            v19 = v51;
            v33 = v47;
          }
          v9 = 0;
          *(_BYTE *)(v48 + 104) = (unsigned __int8)(*(_BYTE *)(v48 + 104) + 1)
                                % (unsigned int)(*(_DWORD *)(v48 + 108) - 1);
          goto LABEL_20;
        }
        v9 = v36;
        goto LABEL_61;
      }
    }
    else if ( v47 == v35 )
    {
      v9 = 0;
      *(_BYTE *)(v48 + 112) = -1;
      goto LABEL_20;
    }
    v9 = 0;
LABEL_20:
    v16 = *(_QWORD *)(a2 + 8);
    v18 = v33 + 1;
    v20 += 6;
    v17 = *(unsigned int *)(v16 + 20);
    --v49;
    if ( v18 >= v17 )
      goto LABEL_85;
  }
  if ( (unsigned int)__ratelimit(&cam_hw_cdm_submit_bl__rs, "cam_hw_cdm_submit_bl") )
    v37 = 3;
  else
    v37 = 2;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    v37,
    1,
    1,
    "cam_hw_cdm_submit_bl",
    1101,
    "In error/reset/PF state cnt=%d total cnt=%d cdm_status 0x%x",
    -v49,
    *(_DWORD *)(*(_QWORD *)(a2 + 8) + 20LL),
    *(_QWORD *)(v7 + 4856));
  v9 = -11;
LABEL_85:
  mutex_unlock(a3 + 280);
  mutex_unlock(v48 + 56);
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v9;
}
