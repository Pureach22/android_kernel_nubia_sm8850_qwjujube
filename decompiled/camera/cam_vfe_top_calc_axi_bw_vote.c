__int64 __fastcall cam_vfe_top_calc_axi_bw_vote(
        __int64 a1,
        char a2,
        unsigned int **a3,
        unsigned __int64 *a4,
        unsigned __int64 *a5,
        __int64 a6)
{
  unsigned int v6; // w27
  const char *v7; // x5
  __int64 v8; // x4
  __int64 v9; // x6
  __int64 v10; // x7
  unsigned int *v12; // x25
  void *v16; // x0
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x5
  __int64 v22; // x26
  unsigned int v23; // w24
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x8
  unsigned __int64 v30; // x22
  _QWORD *v31; // x26
  __int64 v32; // x28
  __int64 v34; // x8
  const char *v35; // x0
  unsigned int v36; // w8
  __int64 v37; // x8
  __int64 v38; // x8
  unsigned __int64 *v39; // x28
  __int64 v40; // x7
  _BOOL4 v41; // w19
  __int64 v42; // x9
  unsigned __int64 v43; // x8
  unsigned __int64 v44; // x9
  unsigned __int64 v45; // x10
  unsigned int v46; // w8
  unsigned __int64 v47; // x8
  int v48; // w9
  int v49; // w10
  unsigned __int64 v50; // x22
  _DWORD *v51; // x26
  __int64 v52; // x28
  const char *v53; // x0
  unsigned __int64 v54; // x7
  int v55; // w8
  int v56; // w9
  const char *v57; // x11
  __int64 v58; // x8
  const char *v59; // [xsp+38h] [xbp-38h]
  const char *v60; // [xsp+40h] [xbp-30h]
  const char *v61; // [xsp+40h] [xbp-30h]
  int v62; // [xsp+48h] [xbp-28h]
  const char *v63; // [xsp+48h] [xbp-28h]
  int v64; // [xsp+54h] [xbp-1Ch]
  int v65; // [xsp+54h] [xbp-1Ch]

  v6 = *(_DWORD *)(a1 + 1064);
  if ( v6 >= 8 )
  {
    v7 = "Number of Mux exceeds max, # Mux: %d > Limit: %d";
    v8 = 277;
    v9 = v6;
    v10 = 7;
LABEL_3:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      0x2000000,
      1,
      "cam_vfe_top_calc_axi_bw_vote",
      v8,
      v7,
      v9,
      v10);
    return 4294967274LL;
  }
  v12 = (unsigned int *)(a1 + 1680);
  v16 = memset((void *)(a1 + 1680), 0, 0x260u);
  if ( v6 )
  {
    v22 = a1 + 1688;
    if ( *(_DWORD *)(a1 + 10380) == 1 )
    {
      v9 = *(unsigned int *)(a1 + 2288);
      if ( (unsigned int)v9 >= 0x10 )
        goto LABEL_37;
      v16 = memcpy((void *)(a1 + 1688), (const void *)(a1 + 2296), 40 * v9);
      v23 = *(_DWORD *)(a1 + 2288);
      v6 = *(_DWORD *)(a1 + 1064);
      if ( v6 < 2 )
      {
LABEL_41:
        *v12 = v23;
        if ( v23 )
        {
          v30 = 0;
          v31 = (_QWORD *)(a1 + 1720);
          while ( 1 )
          {
            v32 = debug_mdl & 0x2000008;
            if ( (debug_mdl & 0x2000008) != 0 && debug_priority == 0 )
            {
              if ( v30 > 0xE )
                goto LABEL_115;
              v64 = *(_DWORD *)(a1 + 10288);
              v62 = *(_DWORD *)(a1 + 1068);
              v60 = cam_cpas_axi_util_path_type_to_string(*((_DWORD *)v31 - 6));
              v59 = cam_cpas_axi_util_trans_type_to_string(*((_DWORD *)v31 - 7));
              v35 = cam_cpas_axi_util_drv_vote_lvl_to_string(*((_DWORD *)v31 - 5));
              v16 = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                              3,
                              v32,
                              4,
                              "cam_vfe_top_calc_axi_bw_vote",
                              321,
                              "ife[%d] : New BW Vote : counter[%d] [%s][%s][%s] [%llu %llu %llu]",
                              v62,
                              v64,
                              v60,
                              v59,
                              v35,
                              *(v31 - 2),
                              *(v31 - 1),
                              *v31);
            }
            else if ( v30 > 0xE )
            {
              goto LABEL_115;
            }
            ++v30;
            *a4 += *(v31 - 2);
            v34 = *(v31 - 1);
            v31 += 5;
            *a5 += v34;
            if ( v30 >= *v12 )
              goto LABEL_52;
          }
        }
        goto LABEL_52;
      }
    }
    else
    {
      v23 = 0;
      if ( v6 < 2 )
        goto LABEL_41;
    }
    if ( *(_DWORD *)(a1 + 10384) == 1 )
    {
      v24 = *(unsigned int *)(a1 + 2896);
      v9 = (unsigned int)v24 + v23;
      if ( (unsigned int)v9 > 0xF )
        goto LABEL_37;
      if ( v23 > 0xF )
        goto LABEL_115;
      v16 = memcpy((void *)(v22 + 40LL * v23), (const void *)(a1 + 2904), 40 * v24);
      v6 = *(_DWORD *)(a1 + 1064);
      v23 += *(_DWORD *)(a1 + 2896);
    }
    if ( v6 < 3 )
      goto LABEL_41;
    if ( *(_DWORD *)(a1 + 10388) == 1 )
    {
      v25 = *(unsigned int *)(a1 + 3504);
      v9 = (unsigned int)v25 + v23;
      if ( (unsigned int)v9 > 0xF )
        goto LABEL_37;
      if ( v23 > 0xF )
        goto LABEL_115;
      v16 = memcpy((void *)(v22 + 40LL * v23), (const void *)(a1 + 3512), 40 * v25);
      v6 = *(_DWORD *)(a1 + 1064);
      v23 += *(_DWORD *)(a1 + 3504);
    }
    if ( v6 < 4 )
      goto LABEL_41;
    if ( *(_DWORD *)(a1 + 10392) == 1 )
    {
      v26 = *(unsigned int *)(a1 + 4112);
      v9 = (unsigned int)v26 + v23;
      if ( (unsigned int)v9 > 0xF )
        goto LABEL_37;
      if ( v23 > 0xF )
        goto LABEL_115;
      v16 = memcpy((void *)(v22 + 40LL * v23), (const void *)(a1 + 4120), 40 * v26);
      v6 = *(_DWORD *)(a1 + 1064);
      v23 += *(_DWORD *)(a1 + 4112);
    }
    if ( v6 < 5 )
      goto LABEL_41;
    if ( *(_DWORD *)(a1 + 10396) == 1 )
    {
      v27 = *(unsigned int *)(a1 + 4720);
      v9 = (unsigned int)v27 + v23;
      if ( (unsigned int)v9 > 0xF )
        goto LABEL_37;
      if ( v23 > 0xF )
        goto LABEL_115;
      v16 = memcpy((void *)(v22 + 40LL * v23), (const void *)(a1 + 4728), 40 * v27);
      v6 = *(_DWORD *)(a1 + 1064);
      v23 += *(_DWORD *)(a1 + 4720);
    }
    if ( v6 < 6 )
      goto LABEL_41;
    if ( *(_DWORD *)(a1 + 10400) != 1 )
      goto LABEL_34;
    v28 = *(unsigned int *)(a1 + 5328);
    v9 = (unsigned int)v28 + v23;
    if ( (unsigned int)v9 <= 0xF )
    {
      if ( v23 > 0xF )
        goto LABEL_115;
      v16 = memcpy((void *)(v22 + 40LL * v23), (const void *)(a1 + 5336), 40 * v28);
      v6 = *(_DWORD *)(a1 + 1064);
      v23 += *(_DWORD *)(a1 + 5328);
LABEL_34:
      if ( v6 < 7 )
        goto LABEL_41;
      if ( *(_DWORD *)(a1 + 10404) == 1 )
      {
        v29 = *(unsigned int *)(a1 + 5936);
        v9 = (unsigned int)v29 + v23;
        if ( (unsigned int)v9 > 0xF )
          goto LABEL_37;
        if ( v23 > 0xF )
        {
LABEL_115:
          __break(0x5512u);
          return cam_vfe_top_set_axi_bw_vote(v16, v17, v18, v19, v20, v21);
        }
        v16 = memcpy((void *)(v22 + 40LL * v23), (const void *)(a1 + 5944), 40 * v29);
        v6 = *(_DWORD *)(a1 + 1064);
        v23 += *(_DWORD *)(a1 + 5936);
      }
      if ( v6 <= 7 )
        goto LABEL_41;
      goto LABEL_115;
    }
LABEL_37:
    v7 = "Required paths(%d) more than max(%d)";
    v8 = 292;
    v10 = 15;
    goto LABEL_3;
  }
LABEL_52:
  if ( *(_DWORD *)(a1 + 10288) > 6u )
    goto LABEL_115;
  v36 = *(_DWORD *)(a1 + 10288);
  if ( v36 > 6 )
    goto LABEL_115;
  v16 = memcpy((void *)(a1 + 6544 + 608LL * v36), v12, 0x260u);
  v37 = *(unsigned int *)(a1 + 10288);
  if ( (unsigned int)v37 > 5 )
    goto LABEL_115;
  *(_QWORD *)(a1 + 10192 + 8 * v37) = *a4;
  v38 = *(unsigned int *)(a1 + 10288);
  if ( (unsigned int)v38 > 5 )
    goto LABEL_115;
  v39 = (unsigned __int64 *)(a1 + 10240);
  *(_QWORD *)(a1 + 10240 + 8 * v38) = *a5;
  v40 = *(_QWORD *)(a1 + 10352);
  *(_DWORD *)(a1 + 10288) = (*(_DWORD *)(a1 + 10288) + 1) % 6u;
  v41 = *a4 == v40 && *a5 == *(_QWORD *)(a1 + 10360);
  v17 = debug_mdl & 0x2000008;
  if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
  {
    v42 = a6;
    if ( (a2 & 1) != 0 )
      v42 = -1;
    v16 = (void *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, unsigned __int64, _QWORD, unsigned __int64, _BOOL4, int, __int64))cam_print_log)(
                    3,
                    v17,
                    4,
                    "cam_vfe_top_calc_axi_bw_vote",
                    343,
                    "ife[%d] : total applied_camnoc=%lld, new_camnoc=%lld applied_mnoc=%lld, new_mnoc=%lld unchanged=%d, "
                    "start_stop=%d req_id=%ld",
                    *(unsigned int *)(a1 + 1068),
                    v40,
                    *a4,
                    *(_QWORD *)(a1 + 10360),
                    *a5,
                    v41,
                    a2 & 1,
                    v42);
    if ( v41 )
      goto LABEL_63;
  }
  else if ( v41 )
  {
LABEL_63:
    if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x2000008,
        4,
        "cam_vfe_top_calc_axi_bw_vote",
        346,
        "BW config unchanged");
    *a3 = nullptr;
    *(_DWORD *)(a1 + 10372) = 1;
    return 0;
  }
  if ( (a2 & 1) != 0 )
  {
    memset((void *)(a1 + 6544), 0, 0xE40u);
    *(_QWORD *)(a1 + 10192) = 0;
    *(_QWORD *)(a1 + 10200) = 0;
    *(_QWORD *)(a1 + 10208) = 0;
    *(_QWORD *)(a1 + 10216) = 0;
    *(_QWORD *)(a1 + 10224) = 0;
    *(_QWORD *)(a1 + 10232) = 0;
    *v39 = 0;
    *(_QWORD *)(a1 + 10248) = 0;
    *(_QWORD *)(a1 + 10256) = 0;
    *(_QWORD *)(a1 + 10264) = 0;
    *(_QWORD *)(a1 + 10272) = 0;
    *(_QWORD *)(a1 + 10280) = 0;
    *(_DWORD *)(a1 + 10288) = 0;
    v16 = memcpy((void *)(a1 + 6544), v12, 0x260u);
    *(_QWORD *)(a1 + 10192) = *a4;
    v43 = *a5;
    *(_DWORD *)(a1 + 10288) = 1;
    *(_QWORD *)(a1 + 10240) = v43;
  }
  else
  {
    v44 = *(_QWORD *)(a1 + 10200);
    v45 = *(_QWORD *)(a1 + 10248);
    if ( v44 >= *(_QWORD *)(a1 + 10192) || v45 >= *v39 )
    {
      v46 = 1;
    }
    else
    {
      v46 = 0;
      v44 = *(_QWORD *)(a1 + 10192);
      v45 = *v39;
    }
    if ( *(_QWORD *)(a1 + 10208) >= v44 || *(_QWORD *)(a1 + 10256) >= v45 )
    {
      v46 = 2;
      v44 = *(_QWORD *)(a1 + 10208);
      v45 = *(_QWORD *)(a1 + 10256);
    }
    if ( *(_QWORD *)(a1 + 10216) >= v44 || *(_QWORD *)(a1 + 10264) >= v45 )
    {
      v46 = 3;
      v44 = *(_QWORD *)(a1 + 10216);
      v45 = *(_QWORD *)(a1 + 10264);
    }
    if ( *(_QWORD *)(a1 + 10224) >= v44 || *(_QWORD *)(a1 + 10272) >= v45 )
    {
      v46 = 4;
      v44 = *(_QWORD *)(a1 + 10224);
      v45 = *(_QWORD *)(a1 + 10272);
    }
    if ( *(_QWORD *)(a1 + 10232) >= v44 || *(_QWORD *)(a1 + 10280) >= v45 )
    {
      v46 = 5;
      v44 = *(_QWORD *)(a1 + 10232);
      v45 = *(_QWORD *)(a1 + 10280);
    }
    *a4 = v44;
    *a5 = v45;
    v12 = (unsigned int *)(a1 + 6544 + 608LL * v46);
    if ( !(*a4 | v45) )
      v16 = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      0x2000000,
                      2,
                      "cam_vfe_top_calc_axi_bw_vote",
                      379,
                      "to_be_applied_axi_vote is 0, req_id:%llu",
                      a6);
  }
  v47 = *v12;
  if ( (_DWORD)v47 )
  {
    v48 = debug_mdl;
    v49 = debug_priority;
    v50 = 0;
    v51 = v12 + 5;
    do
    {
      v52 = v48 & 0x2000008;
      if ( (v48 & 0x2000008) != 0 && !v49 )
      {
        if ( v50 > 0xE )
          goto LABEL_115;
        v65 = *(_DWORD *)(a1 + 1068);
        v63 = cam_cpas_axi_util_path_type_to_string(*(v51 - 1));
        v61 = cam_cpas_axi_util_trans_type_to_string(*(v51 - 2));
        v53 = cam_cpas_axi_util_drv_vote_lvl_to_string(*v51);
        v16 = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        v52,
                        4,
                        "cam_vfe_top_calc_axi_bw_vote",
                        394,
                        "ife[%d] : Apply BW Vote : [%s][%s][%s] [%llu %llu %llu]",
                        v65,
                        v63,
                        v61,
                        v53,
                        *(_QWORD *)(v51 + 1),
                        *(_QWORD *)(v51 + 3),
                        *(_QWORD *)(v51 + 5));
        v48 = debug_mdl;
        v47 = *v12;
        v49 = debug_priority;
      }
      ++v50;
      v51 += 10;
    }
    while ( v50 < v47 );
  }
  v54 = *(_QWORD *)(a1 + 10352);
  if ( *a4 == v54 && *a5 == *(_QWORD *)(a1 + 10360) )
  {
    if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000008,
        4,
        "cam_vfe_top_calc_axi_bw_vote",
        400,
        "VFE:%d Final BW Unchanged after delay",
        *(_DWORD *)(a1 + 1068));
    *(_DWORD *)(a1 + 10372) = 1;
    *a3 = nullptr;
    return 0;
  }
  else
  {
    v55 = 2;
    if ( *a4 <= v54 )
    {
      if ( *a5 > *(_QWORD *)(a1 + 10360) )
        v55 = 2;
      else
        v55 = 3;
    }
    v56 = debug_mdl;
    *(_DWORD *)(a1 + 10372) = v55;
    if ( (v56 & 0x2000008) != 0 && !debug_priority )
    {
      v57 = "INCREASE";
      if ( v55 == 3 )
        v57 = "DECREASE";
      v58 = a6;
      if ( (a2 & 1) != 0 )
        v58 = -1;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v56 & 0x2000008,
        4,
        "cam_vfe_top_calc_axi_bw_vote",
        417,
        "ife[%d] : Delayed update: total applied_camnoc=%lld, new_camnoc=%lld applied_mnoc=%lld, new_mnoc=%lld start_stop"
        "=%d bw_state=%s req_id=%ld",
        *(_DWORD *)(a1 + 1068),
        v54,
        *a4,
        *(_QWORD *)(a1 + 10360),
        *a5,
        a2 & 1,
        v57,
        v58);
    }
    *a3 = v12;
    return 0;
  }
}
