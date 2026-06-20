__int64 __fastcall cam_sfe_top_calc_axi_bw_vote(
        __int64 a1,
        char a2,
        unsigned int **a3,
        unsigned __int64 *a4,
        __int64 a5)
{
  unsigned int *v5; // x23
  unsigned int v6; // w26
  const char *v7; // x5
  __int64 v8; // x1
  __int64 v9; // x4
  __int64 v10; // x6
  __int64 v11; // x7
  unsigned int *v13; // x24
  __int64 v16; // x1
  __int64 v17; // x25
  unsigned int v18; // w19
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x8
  unsigned __int64 v24; // x19
  _DWORD *v25; // x25
  __int64 v26; // x27
  __int64 v28; // x8
  const char *v29; // x0
  unsigned int v30; // w19
  unsigned __int64 *v31; // x28
  unsigned int v32; // w8
  __int64 v33; // x27
  unsigned __int64 v34; // x26
  __int64 v35; // x8
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x8
  unsigned __int64 v38; // x8
  unsigned __int64 v39; // x9
  unsigned __int64 v40; // x10
  unsigned __int64 v41; // x11
  bool v42; // cf
  unsigned int v43; // w9
  bool v44; // cf
  bool v45; // cf
  unsigned __int64 v46; // x10
  bool v47; // cf
  unsigned __int64 v48; // x11
  int v49; // w9
  int v50; // w10
  unsigned __int64 v51; // x23
  _DWORD *v52; // x25
  const char *v53; // x0
  __int64 v54; // x27
  unsigned __int64 v55; // x8
  unsigned __int64 v56; // x7
  int v57; // w9
  const char *v58; // x10
  __int64 v59; // x8
  const char *v60; // [xsp+30h] [xbp-40h]
  const char *v61; // [xsp+38h] [xbp-38h]
  const char *v62; // [xsp+38h] [xbp-38h]
  int v63; // [xsp+40h] [xbp-30h]
  const char *v64; // [xsp+40h] [xbp-30h]
  unsigned int v65; // [xsp+4Ch] [xbp-24h]
  int v66; // [xsp+4Ch] [xbp-24h]
  int *v70; // [xsp+68h] [xbp-8h]

  v5 = (unsigned int *)(a1 + 23496);
  v6 = *(_DWORD *)(a1 + 23496);
  if ( v6 >= 7 )
  {
    v7 = "Invalid number of ports %d, max %d";
    v8 = 0x40000000;
    v9 = 422;
    v10 = v6;
    v11 = 6;
LABEL_3:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      v8,
      1,
      "cam_sfe_top_calc_axi_bw_vote",
      v9,
      v7,
      v10,
      v11);
    return 4294967274LL;
  }
  v13 = (unsigned int *)(a1 + 23576);
  v70 = (int *)(a1 + 31580);
  memset((void *)(a1 + 23576), 0, 0x260u);
  if ( v6 )
  {
    v17 = a1 + 23584;
    if ( v70[1] == 1 )
    {
      v10 = v5[172];
      if ( (unsigned int)v10 >= 0x10 )
        goto LABEL_32;
      memcpy((void *)(a1 + 23584), (const void *)(a1 + 24192), 40 * v10);
      v18 = v5[172];
      v6 = *v5;
      if ( *v5 < 2 )
      {
LABEL_36:
        *v13 = v18;
        if ( v18 )
        {
          v24 = 0;
          v25 = v5 + 23;
          while ( 1 )
          {
            v26 = debug_mdl & 0x2000008;
            if ( (debug_mdl & 0x2000008) != 0 && debug_priority == 0 )
            {
              if ( v24 > 0xE )
                goto LABEL_99;
              v65 = v5[16];
              v63 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4LL);
              v61 = cam_cpas_axi_util_path_type_to_string(v25[1]);
              v60 = cam_cpas_axi_util_trans_type_to_string(*v25);
              v29 = cam_cpas_axi_util_drv_vote_lvl_to_string(v25[2]);
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v26,
                4,
                "cam_sfe_top_calc_axi_bw_vote",
                467,
                "sfe[%d] : New BW Vote : counter[%d] [%s][%s][%s] [%llu %llu %llu]",
                v63,
                v65,
                v61,
                v60,
                v29,
                *(_QWORD *)(v25 + 3),
                *(_QWORD *)(v25 + 5),
                *(_QWORD *)(v25 + 7));
            }
            else if ( v24 > 0xE )
            {
              goto LABEL_99;
            }
            v28 = *(_QWORD *)(v25 + 3);
            ++v24;
            v25 += 10;
            *a4 += v28;
            if ( v24 >= *v13 )
              goto LABEL_47;
          }
        }
        goto LABEL_47;
      }
    }
    else
    {
      v18 = 0;
      if ( v6 < 2 )
        goto LABEL_36;
    }
    if ( v70[2] == 1 )
    {
      v19 = v5[324];
      v10 = (unsigned int)v19 + v18;
      if ( (unsigned int)v10 > 0xF )
        goto LABEL_32;
      if ( v18 > 0xF )
        goto LABEL_99;
      memcpy((void *)(v17 + 40LL * v18), (const void *)(a1 + 24800), 40 * v19);
      v6 = *v5;
      v18 += v5[324];
    }
    if ( v6 < 3 )
      goto LABEL_36;
    if ( v70[3] == 1 )
    {
      v20 = v5[476];
      v10 = (unsigned int)v20 + v18;
      if ( (unsigned int)v10 > 0xF )
        goto LABEL_32;
      if ( v18 > 0xF )
        goto LABEL_99;
      memcpy((void *)(v17 + 40LL * v18), (const void *)(a1 + 25408), 40 * v20);
      v6 = *v5;
      v18 += v5[476];
    }
    if ( v6 < 4 )
      goto LABEL_36;
    if ( v70[4] == 1 )
    {
      v21 = v5[628];
      v10 = (unsigned int)v21 + v18;
      if ( (unsigned int)v10 > 0xF )
        goto LABEL_32;
      if ( v18 > 0xF )
        goto LABEL_99;
      memcpy((void *)(v17 + 40LL * v18), (const void *)(a1 + 26016), 40 * v21);
      v6 = *v5;
      v18 += v5[628];
    }
    if ( v6 < 5 )
      goto LABEL_36;
    if ( v70[5] != 1 )
      goto LABEL_29;
    v22 = v5[780];
    v10 = (unsigned int)v22 + v18;
    if ( (unsigned int)v10 <= 0xF )
    {
      if ( v18 > 0xF )
        goto LABEL_99;
      memcpy((void *)(v17 + 40LL * v18), (const void *)(a1 + 26624), 40 * v22);
      v6 = *v5;
      v18 += v5[780];
LABEL_29:
      if ( v6 < 6 )
        goto LABEL_36;
      if ( v70[6] == 1 )
      {
        v23 = v5[932];
        v10 = (unsigned int)v23 + v18;
        if ( (unsigned int)v10 > 0xF )
          goto LABEL_32;
        if ( v18 > 0xF )
        {
LABEL_99:
          __break(0x5512u);
LABEL_100:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            v16,
            4,
            "cam_sfe_top_calc_axi_bw_vote",
            487,
            "BW config unchanged");
LABEL_58:
          *a3 = nullptr;
          *v70 = 1;
          return 0;
        }
        memcpy((void *)(v17 + 40LL * v18), (const void *)(a1 + 27232), 40 * v23);
        v6 = *v5;
        v18 += v5[932];
      }
      if ( v6 <= 6 )
        goto LABEL_36;
      goto LABEL_99;
    }
LABEL_32:
    v7 = "Required paths(%d) more than max(%d)";
    v8 = 0x2000000;
    v9 = 438;
    v11 = 15;
    goto LABEL_3;
  }
LABEL_47:
  if ( v5[16] > 6 )
    goto LABEL_99;
  v30 = v5[16];
  if ( v30 > 6 )
    goto LABEL_99;
  memcpy((void *)(a1 + 27832 + 608LL * v30), v5 + 20, 0x260u);
  if ( v30 == 6 )
    goto LABEL_99;
  v31 = (unsigned __int64 *)(a1 + 31480);
  if ( v30 < 5 )
    v32 = v30 + 1;
  else
    v32 = v30 - 5;
  v31[v30] = *a4;
  v5[16] = v32;
  v33 = *(_QWORD *)(a1 + 23568);
  v34 = *a4;
  v16 = debug_mdl & 0x2000008;
  if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
  {
    v35 = a5;
    if ( (a2 & 1) != 0 )
      v35 = -1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, unsigned __int64, bool, int, __int64))cam_print_log)(
      3,
      v16,
      4,
      "cam_sfe_top_calc_axi_bw_vote",
      484,
      "applied_total=%lld, new_total=%lld unchanged=%d, start_stop=%d req_id=%ld",
      *(_QWORD *)(a1 + 23568),
      *a4,
      v34 == v33,
      a2 & 1,
      v35);
    if ( v34 == v33 )
    {
LABEL_56:
      v16 = debug_mdl & 0x2000008;
      if ( (debug_mdl & 0x2000008) == 0 || debug_priority )
        goto LABEL_58;
      goto LABEL_100;
    }
  }
  else if ( v34 == v33 )
  {
    goto LABEL_56;
  }
  if ( (a2 & 1) == 0 )
  {
    v38 = *(_QWORD *)(a1 + 31480);
    v39 = *(_QWORD *)(a1 + 31488);
    v40 = *(_QWORD *)(a1 + 31496);
    v41 = *(_QWORD *)(a1 + 31504);
    v42 = v39 >= v38;
    if ( v39 > v38 )
      v38 = *(_QWORD *)(a1 + 31488);
    v43 = v42;
    v44 = v40 >= v38;
    if ( v40 > v38 )
      v38 = *(_QWORD *)(a1 + 31496);
    if ( v44 )
      v43 = 2;
    v45 = v41 >= v38;
    v46 = *(_QWORD *)(a1 + 31512);
    if ( v41 > v38 )
      v38 = *(_QWORD *)(a1 + 31504);
    if ( v45 )
      v43 = 3;
    v47 = v46 >= v38;
    v48 = *(_QWORD *)(a1 + 31520);
    if ( v46 > v38 )
      v38 = *(_QWORD *)(a1 + 31512);
    if ( v47 )
      v43 = 4;
    if ( v48 >= v38 )
      v43 = 5;
    if ( v48 > v38 )
      v38 = *(_QWORD *)(a1 + 31520);
    v13 = (unsigned int *)(a1 + 27832 + 608LL * v43);
    *a4 = v38;
    if ( v38 || (v16 = debug_mdl & 0x2000008, (debug_mdl & 0x2000008) == 0) || debug_priority )
    {
      v37 = *v13;
      if ( !(_DWORD)v37 )
        goto LABEL_102;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v16,
        4,
        "cam_sfe_top_calc_axi_bw_vote",
        514,
        "to_be_applied_axi_vote is 0, req_id:%llu",
        a5);
      v37 = *v13;
      if ( !(_DWORD)v37 )
        goto LABEL_102;
    }
LABEL_93:
    v49 = debug_mdl;
    v50 = debug_priority;
    v51 = 0;
    v52 = v13 + 5;
    while ( 1 )
    {
      v54 = v49 & 0x2000008;
      if ( (v49 & 0x2000008) != 0 && !v50 )
      {
        if ( v51 > 0xE )
          goto LABEL_99;
        v66 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4LL);
        v64 = cam_cpas_axi_util_path_type_to_string(*(v52 - 1));
        v62 = cam_cpas_axi_util_trans_type_to_string(*(v52 - 2));
        v53 = cam_cpas_axi_util_drv_vote_lvl_to_string(*v52);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v54,
          4,
          "cam_sfe_top_calc_axi_bw_vote",
          529,
          "sfe[%d] : Apply BW Vote : [%s][%s][%s] [%llu %llu %llu]",
          v66,
          v64,
          v62,
          v53,
          *(_QWORD *)(v52 + 1),
          *(_QWORD *)(v52 + 3),
          *(_QWORD *)(v52 + 5));
        v49 = debug_mdl;
        v37 = *v13;
        v50 = debug_priority;
      }
      ++v51;
      v52 += 10;
      if ( v51 >= v37 )
        goto LABEL_102;
    }
  }
  memset((void *)(a1 + 27832), 0, 0xE40u);
  *v31 = 0;
  *(_QWORD *)(a1 + 31488) = 0;
  *(_QWORD *)(a1 + 31496) = 0;
  *(_QWORD *)(a1 + 31504) = 0;
  *(_QWORD *)(a1 + 31512) = 0;
  *(_QWORD *)(a1 + 31520) = 0;
  v5[16] = 0;
  memcpy((void *)(a1 + 27832), v5 + 20, 0x260u);
  v36 = *a4;
  v5[16] = 1;
  *v31 = v36;
  v37 = *v13;
  if ( (_DWORD)v37 )
    goto LABEL_93;
LABEL_102:
  v55 = *a4;
  v56 = *(_QWORD *)(a1 + 23568);
  if ( *a4 == v56 )
  {
    if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000008,
        4,
        "cam_sfe_top_calc_axi_bw_vote",
        534,
        "SFE:%d Final BW Unchanged after delay",
        *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4LL));
    *v70 = 1;
    *a3 = nullptr;
    return 0;
  }
  else
  {
    if ( *a4 > v56 )
      v57 = 2;
    else
      v57 = 3;
    *v70 = v57;
    if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
    {
      v58 = "DECREASE";
      if ( v55 > v56 )
        v58 = "INCREASE";
      v59 = a5;
      if ( (a2 & 1) != 0 )
        v59 = -1;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, unsigned __int64, unsigned __int64, int, const char *, __int64))cam_print_log)(
        3,
        debug_mdl & 0x2000008,
        4,
        "cam_sfe_top_calc_axi_bw_vote",
        549,
        "sfe[%d] : Delayed update: applied_total=%lld new_total=%lld, start_stop=%d bw_state=%s req_id=%ld",
        *(unsigned int *)(*(_QWORD *)(a1 + 8) + 4LL),
        v56,
        *a4,
        a2 & 1,
        v58,
        v59);
    }
    *a3 = v13;
    return 0;
  }
}
