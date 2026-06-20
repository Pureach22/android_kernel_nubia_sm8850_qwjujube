__int64 __fastcall cam_ife_mgr_stop_hw(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x19
  __int64 v4; // x26
  int v5; // w22
  unsigned int v6; // w20
  char v7; // w8
  __int64 result; // x0
  int v9; // w8
  unsigned int v10; // w21
  int v11; // w23
  __int64 v12; // x8
  _QWORD *v13; // x20
  int v14; // w0
  __int64 v15; // x2
  int v16; // w0
  _QWORD *v17; // x22
  __int64 v18; // x8
  __int64 v19; // x9
  unsigned int (__fastcall *v20)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v21; // x0
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x22
  __int64 v24; // x23
  unsigned int v25; // w6
  __int64 v26; // x20
  unsigned __int64 v27; // x21
  _QWORD *i; // x20
  __int64 v29; // x20
  unsigned __int64 v30; // x21
  _QWORD *j; // x20
  _QWORD *k; // x20
  _QWORD *v33; // x8
  _QWORD *v34; // x8
  unsigned int v40; // w9
  unsigned int v43; // w8
  unsigned int v44; // w8
  __int64 v45; // [xsp+18h] [xbp-18h] BYREF
  __int64 v46; // [xsp+20h] [xbp-10h]
  __int64 v47; // [xsp+28h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_stop_hw",
      8481,
      "Invalid arguments");
    result = 4294967274LL;
    goto LABEL_168;
  }
  v2 = *a2;
  if ( !*a2 || (*(_BYTE *)(v2 + 9376) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_stop_hw",
      8487,
      "Invalid context is used");
    result = 0xFFFFFFFFLL;
    goto LABEL_168;
  }
  if ( !*(_DWORD *)(v2 + 8716) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_stop_hw",
      8492,
      "number of bases are zero, ctx id:%u",
      *(_DWORD *)(v2 + 56));
    result = 4294967274LL;
    goto LABEL_168;
  }
  _X8 = (unsigned int *)(v2 + 9436);
  __asm { PRFM            #0x11, [X8] }
  do
    v40 = __ldxr(_X8);
  while ( __stxr(v40 + 1, _X8) );
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v13 = a2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_stop_hw",
      8499,
      " Enter...ctx id:%u",
      *(_DWORD *)(v2 + 56));
    a2 = v13;
  }
  v4 = a2[1];
  if ( (*(_BYTE *)(v4 + 4) & 1) == 0 )
  {
    *(_BYTE *)(v2 + 9984) = 0;
    memset((void *)(v2 + 9536), 0, 0x1C0u);
  }
  if ( *(_DWORD *)v4 )
  {
    v5 = *(unsigned __int8 *)(v2 + 9381) ^ 1;
    if ( *(_BYTE *)(v2 + 9381) )
      v6 = 0;
    else
      v6 = 2;
    v7 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
    {
LABEL_23:
      v9 = *(_DWORD *)(v2 + 8716);
      if ( v9 )
        goto LABEL_24;
LABEL_52:
      v11 = 0;
      v10 = 0;
      goto LABEL_71;
    }
  }
  else
  {
    v5 = 0;
    v6 = 0;
    v7 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_23;
  }
  if ( debug_priority )
    goto LABEL_23;
  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    v7 & 8,
    4,
    "cam_ife_mgr_stop_hw",
    8517,
    "Halting CSIDs, ctx id:%u",
    *(_DWORD *)(v2 + 56));
  v9 = *(_DWORD *)(v2 + 8716);
  if ( !v9 )
    goto LABEL_52;
LABEL_24:
  if ( !*(_DWORD *)(v2 + 8588) )
  {
    v12 = 8584;
    v11 = 0;
LABEL_70:
    v10 = *(_DWORD *)(v2 + v12);
    goto LABEL_71;
  }
  if ( v9 == 1 )
  {
    v10 = 0;
    v11 = 1;
    goto LABEL_71;
  }
  if ( !*(_DWORD *)(v2 + 8600) )
  {
    v12 = 8596;
    v11 = 1;
    goto LABEL_70;
  }
  if ( v9 == 2 )
  {
    v10 = 0;
    v11 = 2;
    goto LABEL_71;
  }
  if ( !*(_DWORD *)(v2 + 8612) )
  {
    v12 = 8608;
    v11 = 2;
    goto LABEL_70;
  }
  if ( v9 == 3 )
  {
    v10 = 0;
    v11 = 3;
    goto LABEL_71;
  }
  if ( !*(_DWORD *)(v2 + 8624) )
  {
    v12 = 8620;
    v11 = 3;
    goto LABEL_70;
  }
  if ( v9 == 4 )
  {
    v10 = 0;
    v11 = 4;
    goto LABEL_71;
  }
  if ( !*(_DWORD *)(v2 + 8636) )
  {
    v12 = 8632;
    v11 = 4;
    goto LABEL_70;
  }
  if ( v9 == 5 )
  {
    v10 = 0;
    v11 = 5;
    goto LABEL_71;
  }
  if ( !*(_DWORD *)(v2 + 8648) )
  {
    v12 = 8644;
    v11 = 5;
    goto LABEL_70;
  }
  if ( v9 == 6 )
  {
    v10 = 0;
    v11 = 6;
    goto LABEL_71;
  }
  if ( !*(_DWORD *)(v2 + 8660) )
  {
    v12 = 8656;
    v11 = 6;
    goto LABEL_70;
  }
  if ( v9 == 7 )
  {
    v10 = 0;
    v11 = 7;
    goto LABEL_71;
  }
  if ( !*(_DWORD *)(v2 + 8672) )
  {
    v12 = 8668;
    v11 = 7;
    goto LABEL_70;
  }
  if ( v9 == 8 )
  {
    v10 = 0;
    v11 = 8;
    goto LABEL_71;
  }
  if ( !*(_DWORD *)(v2 + 8684) )
  {
    v12 = 8680;
    v11 = 8;
    goto LABEL_70;
  }
  if ( v9 == 9 )
  {
    v10 = 0;
    v11 = 9;
    goto LABEL_71;
  }
  if ( !*(_DWORD *)(v2 + 8696) )
  {
    v12 = 8692;
    v11 = 9;
    goto LABEL_70;
  }
  if ( v9 == 10 )
  {
    v10 = 0;
    v11 = 10;
    goto LABEL_71;
  }
  if ( !*(_DWORD *)(v2 + 8708) )
  {
    v12 = 8704;
    v11 = 10;
    goto LABEL_70;
  }
  if ( v9 != 11 )
    goto LABEL_173;
  v10 = 0;
  v11 = 11;
LABEL_71:
  v14 = cam_cdm_reset_hw(*(_DWORD *)(v2 + 8720));
  if ( v14 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "cam_ife_mgr_stop_hw",
      8530,
      "CDM: %u reset failed rc: %d in ctx: %u",
      *(_DWORD *)(v2 + 8744),
      v14,
      *(_DWORD *)(v2 + 56));
  if ( *(_DWORD *)(v2 + 8844) )
  {
    if ( (*(_BYTE *)(v2 + 9390) & 1) == 0 )
    {
      v15 = *(unsigned int *)(v2 + 9140);
      *(_BYTE *)(v2 + 9390) = 1;
      v16 = cam_ife_mgr_handle_reg_dump(v2, v2 + 8900, v15, 15);
      if ( v16 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_mgr_stop_hw",
          8542,
          "Reg dump on error failed rc: %d in ctx: %u",
          v16,
          *(_DWORD *)(v2 + 56));
    }
  }
  if ( v11 == *(_DWORD *)(v2 + 8716) )
    v10 = *(_DWORD *)(v2 + 8584);
  if ( v5 )
  {
    if ( *(_BYTE *)(v2 + 9379) == 1 )
    {
      v17 = *(_QWORD **)(v2 + 208);
      if ( v17 != (_QWORD *)(v2 + 208) )
      {
        v45 = 0;
        v46 = 0;
        do
        {
          v18 = v17[5];
          if ( v18 && *(_DWORD *)(v18 + 8) == 4 && *(_DWORD *)v18 == 3 && *(_DWORD *)(v18 + 4) == 5 )
          {
            v19 = *(_QWORD *)(v18 + 16);
            v46 = v17[5];
            LODWORD(v45) = 0;
            v20 = *(unsigned int (__fastcall **)(__int64, __int64, __int64 *, __int64))(v19 + 88);
            v21 = *(_QWORD *)(v19 + 112);
            if ( *((_DWORD *)v20 - 1) != -1055839300 )
              __break(0x8228u);
            if ( v20(v21, 42, &v45, 16) )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_ife_mgr_csid_change_halt_mode",
                2458,
                "Halt update failed, ctx_idx: %u",
                *(_DWORD *)(v2 + 56));
          }
          v17 = (_QWORD *)*v17;
        }
        while ( v17 != (_QWORD *)(v2 + 208) );
      }
    }
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_stop_hw",
      8560,
      "Stopping master CSID idx %d, ctx id:%u",
      v10,
      *(_DWORD *)(v2 + 56));
  cam_ife_mgr_csid_stop_hw(v2, v2 + 208, v10, v6, *(unsigned __int8 *)(v4 + 6), *(unsigned __int8 *)(v4 + 4));
  v22 = *(unsigned int *)(v2 + 8716);
  if ( (_DWORD)v22 )
  {
    v23 = 0;
    v24 = 8584;
    while ( v23 != 11 )
    {
      v25 = *(_DWORD *)(v2 + v24);
      if ( v25 != v10 )
      {
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_mgr_stop_hw",
            8572,
            "Stopping CSID idx %d i %d master %d ctx id:%u",
            v25,
            v23,
            v10,
            *(_DWORD *)(v2 + 56));
          v25 = *(_DWORD *)(v2 + v24);
        }
        cam_ife_mgr_csid_stop_hw(v2, v2 + 208, v25, v6, *(unsigned __int8 *)(v4 + 6), *(unsigned __int8 *)(v4 + 4));
        v22 = *(unsigned int *)(v2 + 8716);
      }
      ++v23;
      v24 += 12;
      if ( v23 >= v22 )
        goto LABEL_104;
    }
LABEL_173:
    __break(0x5512u);
  }
LABEL_104:
  if ( *(_BYTE *)(v4 + 4) == 1 )
    cam_ife_mgr_finish_clk_bw_update(v2, 0, 1);
  else
    *(_BYTE *)(v2 + 9985) = 0;
  if ( *(_DWORD *)(v2 + 9312) == 2 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_stop_hw",
        8589,
        "Going to stop SFE Out, ctx id:%u",
        *(_DWORD *)(v2 + 56));
      if ( *(_DWORD *)(v2 + 8516) )
      {
LABEL_111:
        v26 = 0;
        v27 = 0;
        do
        {
          cam_ife_hw_mgr_stop_hw_res(*(_QWORD *)(v2 + 280) + v26);
          ++v27;
          v26 += 128;
        }
        while ( v27 < *(unsigned int *)(v2 + 8516) );
      }
    }
    else if ( *(_DWORD *)(v2 + 8516) )
    {
      goto LABEL_111;
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_stop_hw",
        8595,
        "Going to stop SFE SRC resources, ctx id:%u",
        *(_DWORD *)(v2 + 56));
    for ( i = *(_QWORD **)(v2 + 240); i != (_QWORD *)(v2 + 240); i = (_QWORD *)*i )
      cam_ife_hw_mgr_stop_hw_res(i);
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_stop_hw",
      8602,
      "Going to stop IFE out resources, ctx id:%u",
      *(_DWORD *)(v2 + 56));
    if ( *(_DWORD *)(v2 + 8512) )
    {
LABEL_121:
      v29 = 0;
      v30 = 0;
      do
      {
        cam_ife_hw_mgr_stop_hw_res(*(_QWORD *)(v2 + 272) + v29);
        ++v30;
        v29 += 128;
      }
      while ( v30 < *(unsigned int *)(v2 + 8512) );
    }
  }
  else if ( *(_DWORD *)(v2 + 8512) )
  {
    goto LABEL_121;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_stop_hw",
      8608,
      "Going to stop IFE Mux, ctx id:%u",
      *(_DWORD *)(v2 + 56));
  for ( j = *(_QWORD **)(v2 + 224); j != (_QWORD *)(v2 + 224); j = (_QWORD *)*j )
    cam_ife_hw_mgr_stop_hw_res(j);
  for ( k = *(_QWORD **)(v2 + 256); k != (_QWORD *)(v2 + 256); k = (_QWORD *)*k )
    cam_ife_hw_mgr_stop_hw_res(k);
  cam_tasklet_stop(*(_QWORD *)(v2 + 16));
  if ( (*(_BYTE *)(v4 + 4) & 1) == 0 )
  {
    v33 = *(_QWORD **)(v2 + 9360);
    *(_DWORD *)(v2 + 9440) = 0;
    *(_DWORD *)(v2 + 9988) = 0;
    if ( v33 )
    {
      v33[16] = 0;
      v33[17] = 0;
      v33[14] = 0;
      v33[15] = 0;
      v33[12] = 0;
      v33[13] = 0;
      v33[10] = 0;
      v33[11] = 0;
      v33[8] = 0;
      v33[9] = 0;
      v33[6] = 0;
      v33[7] = 0;
      v33[4] = 0;
      v33[5] = 0;
      v33[2] = 0;
      v33[3] = 0;
      *v33 = 0;
      v33[1] = 0;
    }
    v34 = *(_QWORD **)(v2 + 9368);
    if ( v34 )
    {
      v34[10] = 0;
      v34[11] = 0;
      v34[8] = 0;
      v34[9] = 0;
      v34[6] = 0;
      v34[7] = 0;
      v34[4] = 0;
      v34[5] = 0;
      v34[2] = 0;
      v34[3] = 0;
      *v34 = 0;
      v34[1] = 0;
    }
  }
  cam_ife_mgr_bw_control(v2, 0);
  if ( !*(_DWORD *)(v2 + 8848) && !cam_common_wait_for_completion_timeout(v2 + 8864) )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "cam_ife_mgr_stop_hw",
      8645,
      "config done completion timeout for last applied req_id=%llu ctx_index %u",
      *(_QWORD *)(v2 + 9304),
      *(_DWORD *)(v2 + 56));
  if ( dword_3A88C8 )
  {
    if ( *(_DWORD *)(v2 + 60) != 8 )
      cam_ife_hw_mgr_print_debug_reg(v2, 0, 6);
    if ( *(_DWORD *)(v2 + 64) != 8 )
      cam_ife_hw_mgr_print_debug_reg(v2, 0, 6);
  }
  if ( (*(_BYTE *)(v4 + 5) & 1) == 0 )
  {
    if ( (unsigned int)cam_cdm_stream_off(*(_DWORD *)(v2 + 8720)) )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_stop_hw",
        8663,
        "CDM stream off failed %d, ctx_id: %u",
        *(_DWORD *)(v2 + 8720),
        *(_DWORD *)(v2 + 56));
    cam_ife_hw_mgr_deinit_hw(v2);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_stop_hw",
        8668,
        "Stop success for ctx id:%u rc :%d",
        *(_DWORD *)(v2 + 56),
        0);
    mutex_lock(&unk_394A30);
    _X10 = &dword_394A60;
    __asm { PRFM            #0x11, [X10] }
    do
    {
      v43 = __ldxr((unsigned int *)&dword_394A60);
      v44 = v43 - 1;
    }
    while ( __stlxr(v44, (unsigned int *)&dword_394A60) );
    __dmb(0xBu);
    if ( !v44 && (unsigned int)cam_ife_notify_safe_lut_scm(0) )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_stop_hw",
        8676,
        "SAFE SCM call failed:Check TZ/HYP dependency, ctx_id: %u",
        *(_DWORD *)(v2 + 56));
    mutex_unlock(&unk_394A30);
  }
  if ( (*(_BYTE *)(v4 + 4) & 1) == 0 && (*(_BYTE *)(v2 + 9401) & 1) == 0 )
  {
    if ( *(_DWORD *)(v2 + 9140) )
    {
      cam_mem_put_cpu_buf(*(_DWORD *)(v2 + 8900));
      if ( *(_DWORD *)(v2 + 9140) >= 2u )
      {
        cam_mem_put_cpu_buf(*(_DWORD *)(v2 + 8924));
        if ( *(_DWORD *)(v2 + 9140) >= 3u )
        {
          cam_mem_put_cpu_buf(*(_DWORD *)(v2 + 8948));
          if ( *(_DWORD *)(v2 + 9140) >= 4u )
          {
            cam_mem_put_cpu_buf(*(_DWORD *)(v2 + 8972));
            if ( *(_DWORD *)(v2 + 9140) >= 5u )
            {
              cam_mem_put_cpu_buf(*(_DWORD *)(v2 + 8996));
              if ( *(_DWORD *)(v2 + 9140) >= 6u )
              {
                cam_mem_put_cpu_buf(*(_DWORD *)(v2 + 9020));
                if ( *(_DWORD *)(v2 + 9140) >= 7u )
                {
                  cam_mem_put_cpu_buf(*(_DWORD *)(v2 + 9044));
                  if ( *(_DWORD *)(v2 + 9140) >= 8u )
                  {
                    cam_mem_put_cpu_buf(*(_DWORD *)(v2 + 9068));
                    if ( *(_DWORD *)(v2 + 9140) >= 9u )
                    {
                      cam_mem_put_cpu_buf(*(_DWORD *)(v2 + 9092));
                      if ( *(_DWORD *)(v2 + 9140) >= 0xAu )
                      {
                        cam_mem_put_cpu_buf(*(_DWORD *)(v2 + 9116));
                        if ( *(_DWORD *)(v2 + 9140) > 0xAu )
                          goto LABEL_173;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    *(_DWORD *)(v2 + 9140) = 0;
  }
  result = 0;
  *(_BYTE *)(v2 + 9401) = 0;
  *(_WORD *)(v2 + 9389) = 0;
LABEL_168:
  _ReadStatusReg(SP_EL0);
  return result;
}
