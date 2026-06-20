__int64 __fastcall cam_ife_hw_mgr_handle_hw_buf_done(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  _DWORD *v3; // x19
  __int64 v4; // x23
  int v5; // w8
  int v6; // w25
  int v7; // w24
  __int64 v8; // x23
  __int64 v9; // x27
  __int64 v10; // x28
  unsigned __int64 v11; // x26
  char v12; // w0
  unsigned __int64 v13; // x8
  int v14; // w26
  unsigned int v15; // w8
  __int64 v16; // x23
  __int64 v17; // x25
  __int64 v18; // x26
  unsigned __int64 v19; // x27
  char is_expanded_memory; // w0
  bool v21; // zf
  int v22; // w8
  __int64 v23; // x25
  __int64 v24; // x27
  unsigned __int64 v25; // x28
  char v26; // w0
  int v27; // w8
  int v28; // w6
  int v29; // w8
  int v30; // w9
  int v31; // w8
  __int64 v32; // x0
  const char *v34; // x6
  const char *v35; // x10
  const char *v36; // x15
  __int64 v37; // x23
  __int64 v38; // x24
  int v39; // w9
  unsigned int v40; // w8
  __int64 v41; // x9
  unsigned __int64 v42; // x8
  __int64 v43; // x24
  __int64 v44; // x20
  __int64 v45; // [xsp+30h] [xbp-30h]
  _DWORD v46[4]; // [xsp+38h] [xbp-28h] BYREF
  __int64 v47; // [xsp+48h] [xbp-18h]
  __int64 v48; // [xsp+50h] [xbp-10h]
  __int64 v49; // [xsp+58h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 32);
  v47 = 0;
  v48 = 0;
  if ( !v2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_handle_hw_buf_done",
      18234,
      "No additional buf done data failed to process for HW: %u, ctx_idx: %u",
      *(_DWORD *)(a2 + 20),
      *(_DWORD *)(a1 + 56));
    v15 = -22;
LABEL_51:
    _ReadStatusReg(SP_EL0);
    return v15;
  }
  v3 = *(_DWORD **)(a1 + 24);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    if ( *(_DWORD *)(a2 + 20) == 7 )
      v34 = "SFE";
    else
      v34 = "IFE";
    v35 = "N";
    if ( *(_BYTE *)(v2 + 12) )
      v36 = "Y";
    else
      v36 = "N";
    if ( *(_BYTE *)(v2 + 13) )
      v35 = "Y";
    v37 = a2;
    v38 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_handle_hw_buf_done",
      18248,
      "Buf done for %s: %d res_id: 0x%x last consumed addr: 0x%x ctx: %u is_hw_ctxt_comp: %s is_early_done: %s",
      v34,
      *(_DWORD *)(a2 + 12),
      *(_DWORD *)(a2 + 8),
      *(_DWORD *)(v2 + 8),
      *(_DWORD *)(a1 + 56),
      v36,
      v35);
    a2 = v37;
    a1 = v38;
  }
  v4 = a1 + 0x2000;
  if ( dword_3A852C )
  {
    v39 = *(_DWORD *)(a2 + 20);
    if ( v39 == 2 )
    {
      v40 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8496) + (unsigned __int8)dword_3A852C);
      if ( v40 == 255 )
        goto LABEL_5;
      v41 = 272;
    }
    else
    {
      if ( v39 != 7 )
        goto LABEL_5;
      v40 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8504) + (unsigned __int8)dword_3A852C);
      if ( v40 == 255 )
        goto LABEL_5;
      v41 = 280;
    }
    v42 = *(_QWORD *)(a1 + v41) + ((unsigned __int64)v40 << 7);
    if ( v42 && *(_DWORD *)(v42 + 116) == *(_DWORD *)(v2 + 4) )
    {
      v45 = a1;
      v43 = a2;
      ((void (*)(void))cam_ife_mgr_read_perf_cnts)();
      a1 = v45;
      a2 = v43;
    }
  }
LABEL_5:
  if ( (*(_BYTE *)(v4 + 1196) & 1) == 0 && *(_BYTE *)(v4 + 1195) != 1 )
    goto LABEL_41;
  v5 = *(_DWORD *)(a2 + 20);
  v6 = *(_DWORD *)(a2 + 8);
  v7 = *(_DWORD *)(v2 + 8);
  if ( v5 == 7 )
  {
    if ( (unsigned int)(v6 - 24576) <= 2 )
    {
      v16 = *(_QWORD *)(a1 + 9360) + 40LL * (unsigned int)(v6 - 24576);
      if ( *(_BYTE *)(v16 + 48) == 1 )
      {
        v17 = a1;
        v18 = a2;
        v19 = *(_QWORD *)(v16 + 32) + *(unsigned int *)(v16 + 44);
        is_expanded_memory = cam_smmu_is_expanded_memory();
        a2 = v18;
        v21 = (is_expanded_memory & 1) == 0;
        a1 = v17;
        v22 = v21 ? v19 : v19 >> 8;
        if ( v7 == v22 )
        {
          v15 = 0;
          if ( (debug_mdl & 8) == 0 || debug_priority )
            goto LABEL_51;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_hw_mgr_check_sfe_scratch_buf_done",
            18184,
            "SFE RDI: 0x%x buf done for scratch - skip ctx notify",
            *(_DWORD *)(v16 + 40));
          goto LABEL_50;
        }
      }
    }
LABEL_41:
    v28 = *(_DWORD *)(a2 + 8);
    v29 = *(_DWORD *)(v2 + 8);
    v30 = *(_DWORD *)(a2 + 20);
    v46[1] = v28;
    v46[3] = v29;
    v31 = *(_DWORD *)(v2 + 4);
    v46[0] = v30;
    LOBYTE(v30) = *(_BYTE *)(v2 + 13);
    v46[2] = v31;
    LOBYTE(v48) = v30;
    v15 = *(_DWORD *)(a1 + 8844);
    if ( !v15 )
    {
      if ( !v28 || !v3 )
        goto LABEL_51;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v44 = a1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_handle_hw_buf_done",
          18294,
          "Notify ISP context for %u handles in ctx: %u",
          v28,
          *(_DWORD *)(a1 + 56));
        a1 = v44;
      }
      v32 = *(_QWORD *)(a1 + 32);
      if ( *(v3 - 1) != 414296116 )
        __break(0x8233u);
      ((void (__fastcall *)(__int64, __int64, _DWORD *))v3)(v32, 5, v46);
    }
    goto LABEL_50;
  }
  if ( v5 != 2 )
    goto LABEL_41;
  v8 = *(_QWORD *)(a1 + 9368);
  if ( !*(_DWORD *)v8 )
    goto LABEL_41;
  if ( *(_DWORD *)(v8 + 32) != v6 )
  {
    v14 = 0;
    goto LABEL_30;
  }
  v9 = a2;
  v10 = a1;
  v11 = *(_QWORD *)(v8 + 24) + *(unsigned int *)(v8 + 36);
  v12 = cam_smmu_is_expanded_memory();
  v13 = v11 >> 8;
  if ( (v12 & 1) == 0 )
    LODWORD(v13) = v11;
  if ( v7 != (_DWORD)v13 )
  {
    v14 = 0;
    goto LABEL_29;
  }
  v14 = -11;
  if ( (debug_mdl & 8) == 0 )
  {
LABEL_29:
    a1 = v10;
    a2 = v9;
    goto LABEL_30;
  }
  a1 = v10;
  a2 = v9;
  if ( !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_hw_mgr_check_ife_scratch_buf_done",
      &print_fmt_cam_notify_frame_skip[5],
      "IFE res:0x%x buf done for scratch - skip ctx notify");
    a2 = v9;
    a1 = v10;
  }
LABEL_30:
  if ( *(_DWORD *)v8 < 2u )
    goto LABEL_40;
  if ( *(_DWORD *)(v8 + 72) == v6 )
  {
    v23 = a1;
    v24 = a2;
    v25 = *(_QWORD *)(v8 + 64) + *(unsigned int *)(v8 + 76);
    v26 = cam_smmu_is_expanded_memory();
    a2 = v24;
    v21 = (v26 & 1) == 0;
    a1 = v23;
    v27 = v21 ? v25 : v25 >> 8;
    if ( v7 == v27 )
    {
      v14 = -11;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_hw_mgr_check_ife_scratch_buf_done",
          &print_fmt_cam_notify_frame_skip[5],
          "IFE res:0x%x buf done for scratch - skip ctx notify");
        a2 = v24;
        a1 = v23;
      }
    }
  }
  if ( *(_DWORD *)v8 <= 2u )
  {
LABEL_40:
    if ( !v14 )
      goto LABEL_41;
LABEL_50:
    v15 = 0;
    goto LABEL_51;
  }
  __break(0x5512u);
  return cam_ife_mgr_read_perf_cnts(a1, a2);
}
