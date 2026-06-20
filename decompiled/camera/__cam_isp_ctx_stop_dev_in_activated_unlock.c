__int64 __fastcall _cam_isp_ctx_stop_dev_in_activated_unlock(__int64 a1, __int64 a2)
{
  __int64 v3; // x22
  __int64 v4; // x8
  __int64 *v5; // x10
  void (__fastcall *v6)(__int64, __int64 *); // x8
  __int64 v7; // x0
  char v8; // w21
  __int64 v9; // x8
  void (__fastcall *v10)(_QWORD); // x8
  unsigned int *v11; // x22
  unsigned int v12; // w21
  unsigned int *v13; // x26
  unsigned int **v14; // x8
  __int64 v15; // x9
  __int64 v16; // x24
  unsigned __int64 v17; // x25
  __int64 v18; // x20
  __int64 v19; // x8
  unsigned int v20; // w0
  signed int v21; // w0
  __int64 v22; // x20
  unsigned int *v23; // x1
  unsigned int *v24; // x22
  unsigned int *v25; // x26
  unsigned int **v26; // x8
  __int64 v27; // x9
  __int64 v28; // x24
  unsigned __int64 v29; // x25
  __int64 v30; // x20
  __int64 v31; // x8
  unsigned int v32; // w0
  signed int v33; // w0
  __int64 v34; // x20
  unsigned int *v35; // x1
  unsigned int *v36; // x22
  unsigned int *v37; // x26
  unsigned int **v38; // x8
  __int64 v39; // x9
  __int64 v40; // x24
  unsigned __int64 v41; // x25
  __int64 v42; // x20
  __int64 v43; // x8
  unsigned int v44; // w0
  signed int v45; // w0
  __int64 v46; // x20
  unsigned int *v47; // x1
  _QWORD *v48; // x8
  __int64 v49; // x9
  const char *v51; // x0
  __int64 v52; // [xsp+20h] [xbp-50h]
  __int64 v53; // [xsp+28h] [xbp-48h]
  __int64 v54; // [xsp+30h] [xbp-40h]
  unsigned int **v56; // [xsp+40h] [xbp-30h]
  unsigned int **v57; // [xsp+40h] [xbp-30h]
  unsigned int **v58; // [xsp+40h] [xbp-30h]
  int v59; // [xsp+4Ch] [xbp-24h] BYREF
  __int64 v60; // [xsp+50h] [xbp-20h] BYREF
  __int64 v61; // [xsp+58h] [xbp-18h] BYREF
  __int64 *v62; // [xsp+60h] [xbp-10h]
  __int64 v63; // [xsp+68h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 256);
  v61 = 0;
  v62 = nullptr;
  v60 = 0;
  raw_spin_lock_bh(a1 + 120);
  *(_DWORD *)(v3 + 20) = 6;
  raw_spin_unlock_bh(a1 + 120);
  v4 = *(_QWORD *)(v3 + 37296);
  v52 = v3 + 37296;
  if ( v4 )
  {
    v5 = *(__int64 **)(a1 + 208);
    WORD2(v60) = 0;
    LODWORD(v60) = 1;
    v61 = v4;
    v62 = &v60;
    v6 = (void (__fastcall *)(__int64, __int64 *))v5[6];
    v7 = *v5;
    if ( *((_DWORD *)v6 - 1) != 1863972096 )
      __break(0x8228u);
    v6(v7, &v61);
  }
  v8 = debug_mdl;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v51 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(v3 + 20));
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v8 & 8,
      4,
      "__cam_isp_ctx_stop_dev_in_activated_unlock",
      9610,
      "next Substate[%s], ctx_idx: %u, link: 0x%x",
      v51,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  }
  v9 = *(_QWORD *)(a1 + 216);
  v53 = v3;
  v54 = v3 + 42112;
  if ( v9 && (v10 = *(void (__fastcall **)(_QWORD))(v9 + 32)) != nullptr )
  {
    v59 = *(_DWORD *)(a1 + 64);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_stop_dev_in_activated_unlock",
        9619,
        "Notify CRM about device stop ctx %u link 0x%x",
        *(unsigned int *)(a1 + 32));
      v10 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 216) + 32LL);
    }
    if ( *((_DWORD *)v10 - 1) != 680652839 )
      __break(0x8228u);
    v10(&v59);
  }
  else if ( (*(_BYTE *)(v3 + 45737) & 1) == 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_stop_dev_in_activated_unlock",
      9623,
      "cb not present, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  }
  v11 = *(unsigned int **)(a1 + 144);
  v56 = (unsigned int **)(a1 + 144);
  if ( v11 != (unsigned int *)(a1 + 144) )
  {
    v12 = 0;
    v13 = (unsigned int *)(a1 + 176);
    while ( 1 )
    {
      v14 = *((unsigned int ***)v11 + 1);
      if ( *v14 == v11 && (v15 = *(_QWORD *)v11, *(unsigned int **)(*(_QWORD *)v11 + 8LL) == v11) )
      {
        *(_QWORD *)(v15 + 8) = v14;
        *v14 = (unsigned int *)v15;
      }
      else
      {
        _list_del_entry_valid_or_report(v11);
      }
      *(_QWORD *)v11 = v11;
      *((_QWORD *)v11 + 1) = v11;
      cam_smmu_buffer_tracker_putref(v11 + 28);
      v16 = *((_QWORD *)v11 + 4);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_stop_dev_in_activated_unlock",
          9632,
          "signal fence in pending list. fence num %d ctx:%u, link: 0x%x",
          *(_DWORD *)(v16 + 32),
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
        if ( !*(_DWORD *)(v16 + 32) )
          goto LABEL_36;
      }
      else if ( !*(_DWORD *)(v16 + 32) )
      {
        goto LABEL_36;
      }
      v17 = 0;
      v18 = 20;
      do
      {
        v19 = *(_QWORD *)(v16 + 24);
        v20 = *(_DWORD *)(v19 + v18 - 4);
        if ( v20 != -1 )
        {
          cam_sync_signal(v20, 4u, 0x3Au);
          v19 = *(_QWORD *)(v16 + 24);
        }
        v21 = *(_DWORD *)(v19 + v18);
        if ( v21 >= 1 )
        {
          v12 = cam_sync_signal(v21, 4u, 0x3Au);
          if ( v12 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "__cam_isp_ctx_stop_dev_in_activated_unlock",
              9651,
              "Early sync=%d for req=%llu failed with rc=%d ctx:%u link[0x%x]",
              *(_DWORD *)(*(_QWORD *)(v16 + 24) + v18),
              *((_QWORD *)v11 + 3),
              v12,
              *(_DWORD *)(a1 + 32),
              *(_DWORD *)(a1 + 64));
          *(_DWORD *)(*(_QWORD *)(v16 + 24) + v18) = -1;
        }
        ++v17;
        v18 += 64;
      }
      while ( v17 < *(unsigned int *)(v16 + 32) );
LABEL_36:
      v22 = *((_QWORD *)v11 + 4);
      if ( (debug_mdl & 8) == 0 || debug_priority )
      {
        if ( !*((_QWORD *)v11 + 17) )
          goto LABEL_40;
LABEL_39:
        cam_mem_put_kref(*(_DWORD *)(v22 + 4328));
        cam_common_mem_free(*((_QWORD *)v11 + 17));
        *((_QWORD *)v11 + 17) = 0;
        goto LABEL_40;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_move_req_to_free_list",
        1404,
        "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
        *((_QWORD *)v11 + 3),
        *((_QWORD *)v11 + 17),
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      if ( *((_QWORD *)v11 + 17) )
        goto LABEL_39;
LABEL_40:
      v23 = *(unsigned int **)(a1 + 184);
      if ( v13 == v11 || v23 == v11 || *(unsigned int **)v23 != v13 )
      {
        _list_add_valid_or_report(v11);
      }
      else
      {
        *(_QWORD *)(a1 + 184) = v11;
        *(_QWORD *)v11 = v13;
        *((_QWORD *)v11 + 1) = v23;
        *(_QWORD *)v23 = v11;
      }
      v11 = *v56;
      if ( *v56 == (unsigned int *)v56 )
        goto LABEL_50;
    }
  }
  v12 = 0;
LABEL_50:
  v24 = *(unsigned int **)(a1 + 160);
  v57 = (unsigned int **)(a1 + 160);
  if ( v24 != (unsigned int *)(a1 + 160) )
  {
    v25 = (unsigned int *)(a1 + 176);
    do
    {
      v26 = *((unsigned int ***)v24 + 1);
      if ( *v26 == v24 && (v27 = *(_QWORD *)v24, *(unsigned int **)(*(_QWORD *)v24 + 8LL) == v24) )
      {
        *(_QWORD *)(v27 + 8) = v26;
        *v26 = (unsigned int *)v27;
      }
      else
      {
        _list_del_entry_valid_or_report(v24);
      }
      *(_QWORD *)v24 = v24;
      *((_QWORD *)v24 + 1) = v24;
      cam_smmu_buffer_tracker_putref(v24 + 28);
      v28 = *((_QWORD *)v24 + 4);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_stop_dev_in_activated_unlock",
          9668,
          "signal fence in wait list. fence num %d ctx: %u, link: 0x%x",
          *(_DWORD *)(v28 + 32),
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
        if ( !*(_DWORD *)(v28 + 32) )
          goto LABEL_68;
      }
      else if ( !*(_DWORD *)(v28 + 32) )
      {
        goto LABEL_68;
      }
      v29 = 0;
      v30 = 20;
      do
      {
        v31 = *(_QWORD *)(v28 + 24);
        v32 = *(_DWORD *)(v31 + v30 - 4);
        if ( v32 != -1 )
        {
          cam_sync_signal(v32, 4u, 0x3Au);
          v31 = *(_QWORD *)(v28 + 24);
        }
        v33 = *(_DWORD *)(v31 + v30);
        if ( v33 >= 1 )
        {
          v12 = cam_sync_signal(v33, 4u, 0x3Au);
          if ( v12 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "__cam_isp_ctx_stop_dev_in_activated_unlock",
              9687,
              "Early sync=%d for req=%llu failed with rc=%d ctx:%u link[0x%x]",
              *(_DWORD *)(*(_QWORD *)(v28 + 24) + v30),
              *((_QWORD *)v24 + 3),
              v12,
              *(_DWORD *)(a1 + 32),
              *(_DWORD *)(a1 + 64));
          *(_DWORD *)(*(_QWORD *)(v28 + 24) + v30) = -1;
        }
        ++v29;
        v30 += 64;
      }
      while ( v29 < *(unsigned int *)(v28 + 32) );
LABEL_68:
      v34 = *((_QWORD *)v24 + 4);
      if ( (debug_mdl & 8) == 0 || debug_priority )
      {
        if ( !*((_QWORD *)v24 + 17) )
          goto LABEL_72;
LABEL_71:
        cam_mem_put_kref(*(_DWORD *)(v34 + 4328));
        cam_common_mem_free(*((_QWORD *)v24 + 17));
        *((_QWORD *)v24 + 17) = 0;
        goto LABEL_72;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_move_req_to_free_list",
        1404,
        "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
        *((_QWORD *)v24 + 3),
        *((_QWORD *)v24 + 17),
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      if ( *((_QWORD *)v24 + 17) )
        goto LABEL_71;
LABEL_72:
      v35 = *(unsigned int **)(a1 + 184);
      if ( v25 == v24 || v35 == v24 || *(unsigned int **)v35 != v25 )
      {
        _list_add_valid_or_report(v24);
      }
      else
      {
        *(_QWORD *)(a1 + 184) = v24;
        *(_QWORD *)v24 = v25;
        *((_QWORD *)v24 + 1) = v35;
        *(_QWORD *)v35 = v24;
      }
      v24 = *v57;
    }
    while ( *v57 != (unsigned int *)v57 );
  }
  v36 = *(unsigned int **)(a1 + 128);
  v58 = (unsigned int **)(a1 + 128);
  if ( v36 != (unsigned int *)(a1 + 128) )
  {
    v37 = (unsigned int *)(a1 + 176);
    do
    {
      v38 = *((unsigned int ***)v36 + 1);
      if ( *v38 == v36 && (v39 = *(_QWORD *)v36, *(unsigned int **)(*(_QWORD *)v36 + 8LL) == v36) )
      {
        *(_QWORD *)(v39 + 8) = v38;
        *v38 = (unsigned int *)v39;
      }
      else
      {
        _list_del_entry_valid_or_report(v36);
      }
      *(_QWORD *)v36 = v36;
      *((_QWORD *)v36 + 1) = v36;
      cam_smmu_buffer_tracker_putref(v36 + 28);
      v40 = *((_QWORD *)v36 + 4);
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_stop_dev_in_activated_unlock",
          9705,
          "signal fence in active list. fence num %d ctx: %u, link: 0x%x",
          *(_DWORD *)(v40 + 32),
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64));
        if ( !*(_DWORD *)(v40 + 32) )
          goto LABEL_99;
      }
      else if ( !*(_DWORD *)(v40 + 32) )
      {
        goto LABEL_99;
      }
      v41 = 0;
      v42 = 20;
      do
      {
        v43 = *(_QWORD *)(v40 + 24);
        v44 = *(_DWORD *)(v43 + v42 - 4);
        if ( v44 != -1 )
        {
          cam_sync_signal(v44, 4u, 0x3Au);
          v43 = *(_QWORD *)(v40 + 24);
        }
        v45 = *(_DWORD *)(v43 + v42);
        if ( v45 >= 1 )
        {
          v12 = cam_sync_signal(v45, 4u, 0x3Au);
          if ( v12 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "__cam_isp_ctx_stop_dev_in_activated_unlock",
              9724,
              "Early sync=%d for req=%llu failed with rc=%d ctx:%u link[0x%x]",
              *(_DWORD *)(*(_QWORD *)(v40 + 24) + v42),
              *((_QWORD *)v36 + 3),
              v12,
              *(_DWORD *)(a1 + 32),
              *(_DWORD *)(a1 + 64));
          *(_DWORD *)(*(_QWORD *)(v40 + 24) + v42) = -1;
        }
        ++v41;
        v42 += 64;
      }
      while ( v41 < *(unsigned int *)(v40 + 32) );
LABEL_99:
      v46 = *((_QWORD *)v36 + 4);
      if ( (debug_mdl & 8) == 0 || debug_priority )
      {
        if ( !*((_QWORD *)v36 + 17) )
          goto LABEL_103;
LABEL_102:
        cam_mem_put_kref(*(_DWORD *)(v46 + 4328));
        cam_common_mem_free(*((_QWORD *)v36 + 17));
        *((_QWORD *)v36 + 17) = 0;
        goto LABEL_103;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_move_req_to_free_list",
        1404,
        "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
        *((_QWORD *)v36 + 3),
        *((_QWORD *)v36 + 17),
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      if ( *((_QWORD *)v36 + 17) )
        goto LABEL_102;
LABEL_103:
      v47 = *(unsigned int **)(a1 + 184);
      if ( v37 == v36 || v47 == v36 || *(unsigned int **)v47 != v37 )
      {
        _list_add_valid_or_report(v36);
      }
      else
      {
        *(_QWORD *)(a1 + 184) = v36;
        *(_QWORD *)v36 = v37;
        *((_QWORD *)v36 + 1) = v47;
        *(_QWORD *)v47 = v36;
      }
      v36 = *v58;
    }
    while ( *v58 != (unsigned int *)v58 );
  }
  *(_QWORD *)(v53 + 8) = 0;
  *(_QWORD *)(v53 + 37328) = 0;
  *(_QWORD *)(v53 + 37336) = 0;
  *(_DWORD *)(v52 + 24) = 0;
  *(_QWORD *)(v52 + 56) = 0;
  *(_QWORD *)(v52 + 96) = 0;
  *(_DWORD *)(v52 + 80) = 0;
  *(_DWORD *)(v52 + 92) = 0;
  *(_BYTE *)(v54 + 3634) = 0;
  *(_BYTE *)(v54 + 3642) = 0;
  *(_DWORD *)(v53 + 24) = 0;
  *(_DWORD *)(v54 + 3460) = 0;
  *(_DWORD *)(v54 + 3472) = 0;
  *(_QWORD *)(v52 + 104) = -1;
  *(_QWORD *)(v54 + 3120) = -1;
  v48 = *(_QWORD **)(*(_QWORD *)(a1 + 256) + 45720LL);
  v49 = *(_QWORD *)(a1 + 256) + 45720LL;
  for ( *(_QWORD *)(*(_QWORD *)(a1 + 256) + 45712LL) = 0; v48 != (_QWORD *)v49; v48 = (_QWORD *)*v48 )
    *((_DWORD *)v48 - 2) = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_reset_fcg_tracker",
      6799,
      "Reset FCG skip info on ctx %u link: %x",
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  *(_QWORD *)v54 = -1;
  *(_QWORD *)(v54 + 8) = -1;
  *(_QWORD *)(v54 + 16) = -1;
  *(_QWORD *)(v54 + 24) = -1;
  *(_QWORD *)(v54 + 32) = -1;
  *(_QWORD *)(v54 + 40) = -1;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_stop_dev_in_activated_unlock",
      9757,
      "Stop device success next state %d on ctx %u link: 0x%x",
      *(_DWORD *)(a1 + 240),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    if ( a2 )
      goto LABEL_121;
    goto LABEL_120;
  }
  if ( !a2 )
  {
LABEL_120:
    *(_QWORD *)(a1 + 216) = 0;
    *(_DWORD *)(a1 + 64) = -1;
    *(_DWORD *)(a1 + 240) = 2;
    v12 = 0;
  }
LABEL_121:
  _ReadStatusReg(SP_EL0);
  return v12;
}
