_QWORD *__fastcall cam_cpas_log_vote(_QWORD *result, char a2)
{
  __int64 v2; // x19
  __int64 v3; // x23
  __int64 v4; // x26
  unsigned __int64 v5; // x8
  unsigned int v6; // w9
  unsigned int v7; // w8
  int v8; // w28
  int v9; // w22
  int v10; // w27
  unsigned int v11; // w21
  __int64 v12; // x20
  int v13; // w8
  int v14; // w9
  __int64 v15; // x23
  __int64 v16; // x24
  __int64 v17; // x19
  int v18; // w25
  int v19; // w0
  __int64 v20; // x9
  int *v21; // x10
  __int64 v22; // x8
  int v23; // w25
  int v24; // w27
  __int64 v25; // x24
  unsigned int v26; // w9
  unsigned int v33; // w13
  __int64 v34; // x28
  __int64 v35; // x20
  int v36; // w21
  __int64 v37; // x19
  int v38; // w0
  unsigned __int64 v39; // x23
  __int64 v40; // x24
  __int64 v41; // x4
  const char *v42; // x5
  __int64 v43; // x8
  __int64 v44; // x21
  __int64 v45; // x22
  unsigned int v46; // w19
  const char *v47; // x5
  __int64 v48; // x1
  __int64 v49; // x4
  unsigned __int64 v50; // x8
  int v51; // w10
  int v52; // w10
  __int64 v53; // x26
  unsigned __int64 v54; // x8
  __int64 v55; // x9
  unsigned __int64 v56; // x19
  __int64 v57; // x28
  __int64 v58; // x23
  _QWORD *v59; // x8
  const char *v60; // x7
  __int64 v61; // x27
  __int64 v62; // x19
  __int64 v63; // x23
  int *v64; // x9
  int v65; // w22
  int v66; // w28
  __int64 v67; // x24
  __int64 v68; // x28
  __int64 v69; // x19
  __int64 v70; // x23
  signed int v71; // w0
  __int64 v72; // x22
  int v73; // w0
  unsigned __int64 v74; // x22
  int v75; // w0
  unsigned __int64 v76; // x22
  int v77; // w0
  unsigned __int64 v78; // x22
  int v79; // w0
  unsigned __int64 v80; // x19
  unsigned __int64 v81; // x23
  __int64 v82; // x24
  __int64 v83; // x26
  int v84; // w0
  __int64 (__fastcall *v85)(_QWORD); // x8
  unsigned int v88; // w10
  int v89; // [xsp+8h] [xbp-2D8h]
  __int64 v90; // [xsp+20h] [xbp-2C0h]
  __int64 v91; // [xsp+70h] [xbp-270h]
  __int64 v92; // [xsp+70h] [xbp-270h]
  int v93; // [xsp+80h] [xbp-260h]
  __int64 v94; // [xsp+90h] [xbp-250h]
  int v95; // [xsp+9Ch] [xbp-244h]
  unsigned int v96; // [xsp+A0h] [xbp-240h]
  __int64 v97; // [xsp+A8h] [xbp-238h]
  __int64 v99; // [xsp+B8h] [xbp-228h]
  __int64 v100; // [xsp+B8h] [xbp-228h]
  unsigned __int64 v101; // [xsp+C0h] [xbp-220h] BYREF
  __int64 v102; // [xsp+C8h] [xbp-218h]
  char v103[512]; // [xsp+D0h] [xbp-210h] BYREF
  __int64 v104; // [xsp+2D0h] [xbp-10h]

  v104 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = result[460];
  v3 = result[424];
  v94 = (__int64)result;
  v99 = v3;
  v4 = *(_QWORD *)(*(_QWORD *)v2 + 56LL);
  if ( *(_DWORD *)(v2 + 2792) )
  {
    LODWORD(v5) = *(unsigned __int8 *)(v3 + 1608);
    if ( (_DWORD)v5 != 1
      || (LOBYTE(v5) = a2, (a2 & 1) != 0)
      || (result = (_QWORD *)cam_cpas_print_smart_qos_priority(result), LODWORD(v5) = *(_DWORD *)(v2 + 2792), (_DWORD)v5) )
    {
      v6 = *(_DWORD *)(v2 + 2824);
      if ( v6 != -1 )
      {
        if ( v6 > 7 )
          goto LABEL_114;
        v7 = *(_DWORD *)(v3 + 1368);
        if ( v7 )
        {
          v8 = *(_DWORD *)(v3 + 1380);
          v9 = *(_DWORD *)(v3 + 1384);
          v10 = 0;
          v11 = 0;
          v12 = *(_QWORD *)(v94 + 24LL * v6 + 384);
          do
          {
            if ( (*(_BYTE *)(v2 + 159425) & 1) != 0 || v8 == v11 || v9 == v11 )
            {
              v13 = *(_DWORD *)(v3 + 1372);
              v14 = *(_DWORD *)(v3 + 1376);
              v15 = v2;
              v16 = (unsigned int)(v10 + v13);
              v17 = (unsigned int)(v10 + v14);
              v18 = cam_io_r_mb(v12 + v16);
              v19 = cam_io_r_mb(v12 + v17);
              v89 = v17;
              v2 = v15;
              v3 = v99;
              result = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                   3,
                                   4,
                                   3,
                                   "cam_cpas_log_vote",
                                   3485,
                                   "i=%d, FE[offset=0x%x, value=0x%x] BE[offset=0x%x, value=0x%x]",
                                   v11,
                                   v16,
                                   v18,
                                   v89,
                                   v19);
              v7 = *(_DWORD *)(v99 + 1368);
            }
            ++v11;
            v10 += 4;
          }
          while ( v11 < v7 );
        }
      }
    }
  }
  if ( v4 )
  {
    if ( *(_DWORD *)(v2 + 2792) )
    {
      LODWORD(v5) = *(_DWORD *)(v2 + 2828);
      if ( (_DWORD)v5 != -1 )
      {
        if ( (unsigned int)v5 > 7 )
          goto LABEL_114;
        v20 = v94 + 24LL * (unsigned int)v5;
        v21 = *(int **)(v4 + 16);
        v22 = *(unsigned int *)(v4 + 8);
        v24 = *v21;
        v23 = v21[1];
        v25 = *(_QWORD *)(v20 + 384);
        v26 = *(_DWORD *)(v2 + 8104);
        while ( v26 )
        {
          _X15 = (unsigned int *)(v2 + 8104);
          __asm { PRFM            #0x11, [X15] }
          while ( 1 )
          {
            v33 = __ldxr(_X15);
            if ( v33 != v26 )
              break;
            if ( !__stlxr(v26 + 1, _X15) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v33 == v26;
          v26 = v33;
          if ( _ZF )
          {
            v91 = v2;
            if ( (_DWORD)v22 )
            {
              v34 = 16 * v22;
              v35 = 0;
              v36 = 0;
              do
              {
                v37 = v24 + v23 * (unsigned int)*(unsigned __int8 *)(*(_QWORD *)v4 + v35);
                v38 = cam_io_r_mb(v25 + v37);
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  4,
                  3,
                  "cam_cpas_log_vote",
                  3518,
                  "i=%d, VCD[index=%d, type=%d, name=%s] [offset=0x%x, value=0x%x]",
                  v36,
                  *(unsigned __int8 *)(*(_QWORD *)v4 + v35),
                  *(_DWORD *)(*(_QWORD *)v4 + v35 + 4),
                  *(const char **)(*(_QWORD *)v4 + v35 + 8),
                  v37,
                  v38);
                v35 += 16;
                ++v36;
              }
              while ( v34 != v35 );
            }
            v2 = v91;
            _X8 = (unsigned int *)(v91 + 8104);
            __asm { PRFM            #0x11, [X8] }
            do
              v88 = __ldxr(_X8);
            while ( __stxr(v88 - 1, _X8) );
            result = (_QWORD *)_wake_up(v91 + 8112, 3, 1, 0);
            break;
          }
        }
      }
    }
  }
  if ( (a2 & 1) != 0 )
    goto LABEL_113;
  LODWORD(v5) = *(_DWORD *)(v2 + 2780);
  if ( (_DWORD)v5 )
  {
    v39 = 0;
    v40 = v2 + 3096;
    while ( v39 != 6 )
    {
      if ( *(_BYTE *)(v40 + 88) == 1 )
      {
        v41 = 3541;
        v42 = "[%s] DRV applied: high [%llu %llu] low[%llu %llu] new: high [%llu %llu] low [%llu %llu]";
      }
      else
      {
        v41 = 3548;
        v42 = "Port %s HLOS applied [%llu %llu] new [%llu %llu]";
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x2000000,
        3,
        "cam_cpas_log_vote",
        v41,
        v42);
      v5 = *(unsigned int *)(v2 + 2780);
      ++v39;
      v40 += 408;
      if ( v39 >= v5 )
        goto LABEL_40;
    }
    goto LABEL_114;
  }
LABEL_40:
  if ( (*(_BYTE *)(v99 + 1036) & 1) == 0 )
  {
    if ( !*(_DWORD *)(v2 + 2784) )
      goto LABEL_50;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      3,
      "cam_cpas_log_vote",
      3574,
      "[%s] ab_bw[%lld] ib_bw[%lld] additional_bw[%lld] applied_ab[%lld] applied_ib[%lld]",
      *(const char **)(v2 + 5544),
      *(_QWORD *)(v2 + 5840),
      *(_QWORD *)(v2 + 5848),
      *(_QWORD *)(v2 + 5888),
      *(_QWORD *)(v2 + 5904),
      *(_QWORD *)(v2 + 5912));
    if ( *(_DWORD *)(v2 + 2784) <= 1u )
      goto LABEL_50;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      3,
      "cam_cpas_log_vote",
      3574,
      "[%s] ab_bw[%lld] ib_bw[%lld] additional_bw[%lld] applied_ab[%lld] applied_ib[%lld]",
      *(const char **)(v2 + 5952),
      *(_QWORD *)(v2 + 6248),
      *(_QWORD *)(v2 + 6256),
      *(_QWORD *)(v2 + 6296),
      *(_QWORD *)(v2 + 6312),
      *(_QWORD *)(v2 + 6320));
    if ( *(_DWORD *)(v2 + 2784) < 3u )
      goto LABEL_50;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      3,
      "cam_cpas_log_vote",
      3574,
      "[%s] ab_bw[%lld] ib_bw[%lld] additional_bw[%lld] applied_ab[%lld] applied_ib[%lld]",
      *(const char **)(v2 + 6360),
      *(_QWORD *)(v2 + 6656),
      *(_QWORD *)(v2 + 6664),
      *(_QWORD *)(v2 + 6704),
      *(_QWORD *)(v2 + 6720),
      *(_QWORD *)(v2 + 6728));
    if ( *(_DWORD *)(v2 + 2784) < 4u )
      goto LABEL_50;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      3,
      "cam_cpas_log_vote",
      3574,
      "[%s] ab_bw[%lld] ib_bw[%lld] additional_bw[%lld] applied_ab[%lld] applied_ib[%lld]",
      *(const char **)(v2 + 6768),
      *(_QWORD *)(v2 + 7064),
      *(_QWORD *)(v2 + 7072),
      *(_QWORD *)(v2 + 7112),
      *(_QWORD *)(v2 + 7128),
      *(_QWORD *)(v2 + 7136));
    if ( *(_DWORD *)(v2 + 2784) < 5u )
      goto LABEL_50;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      3,
      "cam_cpas_log_vote",
      3574,
      "[%s] ab_bw[%lld] ib_bw[%lld] additional_bw[%lld] applied_ab[%lld] applied_ib[%lld]",
      *(const char **)(v2 + 7176),
      *(_QWORD *)(v2 + 7472),
      *(_QWORD *)(v2 + 7480),
      *(_QWORD *)(v2 + 7520),
      *(_QWORD *)(v2 + 7536),
      *(_QWORD *)(v2 + 7544));
    if ( *(_DWORD *)(v2 + 2784) < 6u )
      goto LABEL_50;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      3,
      "cam_cpas_log_vote",
      3574,
      "[%s] ab_bw[%lld] ib_bw[%lld] additional_bw[%lld] applied_ab[%lld] applied_ib[%lld]",
      *(const char **)(v2 + 7584),
      *(_QWORD *)(v2 + 7880),
      *(_QWORD *)(v2 + 7888),
      *(_QWORD *)(v2 + 7928),
      *(_QWORD *)(v2 + 7944),
      *(_QWORD *)(v2 + 7952));
    LODWORD(v5) = *(_DWORD *)(v2 + 2784);
    if ( (unsigned int)v5 <= 6 )
      goto LABEL_50;
LABEL_114:
    __break(0x5512u);
LABEL_115:
    v47 = "No ops for print_poweron_settings";
    v48 = v5 & 4;
    v49 = 3594;
    goto LABEL_116;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    4,
    3,
    "cam_cpas_log_vote",
    3554,
    "applied camnoc axi clk sw_client[%lld]",
    *(_QWORD *)(v2 + 8152));
  if ( *(_BYTE *)(v99 + 1610) == 1 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      3,
      "cam_cpas_log_vote",
      3564,
      "applied camnoc axi clk hw_client[high low] cesta_idx0:[%lld %lld] cesta_idx1:[%lld %lld] cesta_idx2:[%lld %lld]",
      *(_QWORD *)(v2 + 8160),
      *(_QWORD *)(v2 + 8168),
      *(_QWORD *)(v2 + 8176),
      *(_QWORD *)(v2 + 8184),
      *(_QWORD *)(v2 + 0x2000),
      *(_QWORD *)(v2 + 8200));
LABEL_50:
  result = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       4,
                       3,
                       "cam_cpas_log_vote",
                       3579,
                       "ahb client curr vote level[%d]",
                       *(_DWORD *)(v2 + 2912));
  if ( (*(_BYTE *)(v2 + 159425) & 1) != 0 )
  {
    v92 = v2;
    cam_cpas_dump_full_tree_state(v94, "state_dump_on_error");
    v43 = *(_QWORD *)(v94 + 3392);
    v44 = *(_QWORD *)(v94 + 3680);
    v102 = 0;
    v100 = v43;
    v101 = 0;
    result = memset(&v103[1], 0, 0x1FFu);
    if ( *(_BYTE *)(v44 + 159425) == 1 )
    {
      v97 = *(_QWORD *)(*(_QWORD *)v44 + 56LL);
      v45 = *(_QWORD *)(v44 + 8216);
      if ( v45 == -1 )
      {
        result = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                             3,
                             4,
                             2,
                             "cam_cpas_dump_monitor_array",
                             3753,
                             "No valid entries in cpas monitor array");
      }
      else
      {
        if ( v45 > 99 )
        {
          v50 = v45 + 1;
          LODWORD(v45) = 100;
          v46 = v50 % 0x64;
        }
        else
        {
          v46 = 0;
        }
        ktime_get_real_ts64(&v101);
        result = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                             3,
                             4,
                             3,
                             "cam_cpas_dump_monitor_array",
                             3769,
                             "**** %llu:%llu:%llu.%llu : ======== Dumping monitor information ===========",
                             (_QWORD)(v101 / 0xE10
                                    - 24 * ((v101 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
                             v101 / 0x3C
                           - 60
                           * ((unsigned __int64)((v101 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
                             v101 % 0x3C,
                             v102 / 1000000);
        if ( (_DWORD)v45 )
        {
          v51 = 0;
          v93 = v45;
          while ( 1 )
          {
            v53 = v44 + 8224 + 1512LL * v46;
            v95 = v51;
            v54 = *(_QWORD *)v53;
            v55 = *(_QWORD *)(v53 + 8);
            v103[0] = 0;
            v96 = v46;
            result = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                 3,
                                 4,
                                 3,
                                 "cam_cpas_dump_monitor_array",
                                 3790,
                                 "**** %llu:%llu:%llu.%llu : Index[%d] Identifier[%s][%d] camnoc=sw : %ld, hw clients [%l"
                                 "d %ld][%ld %ld][%ld %ld], ahb=%d",
                                 (_QWORD)(v54 / 0xE10
                                        - 24 * ((v54 / 0xE10 * (unsigned __int128)0xAAAAAAAAAAAAAABuLL) >> 64)),
                                 v54 / 0x3C
                               - 60
                               * ((unsigned __int64)((v54 / 0x3C * (unsigned __int128)0x888888888888889uLL) >> 64) >> 1),
                                 v54 % 0x3C,
                                 v55 / 1000000,
                                 v46,
                                 (const char *)(v53 + 16),
                                 *(_DWORD *)(v53 + 144),
                                 *(_QWORD *)(v53 + 968),
                                 *(_QWORD *)(v53 + 976),
                                 *(_QWORD *)(v53 + 984),
                                 *(_QWORD *)(v53 + 992),
                                 *(_QWORD *)(v53 + 1000),
                                 *(_QWORD *)(v53 + 1008),
                                 *(_QWORD *)(v53 + 1016),
                                 *(_DWORD *)(v53 + 1024));
            if ( *(_DWORD *)(v44 + 2780) )
              break;
LABEL_75:
            if ( *(_DWORD *)(v44 + 2824) != -1 )
              result = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                   3,
                                   4,
                                   3,
                                   "cam_cpas_dump_monitor_array",
                                   3820,
                                   "fe_ddr=0x%x, fe_mnoc=0x%x, be_ddr=0x%x, be_mnoc=0x%x, be_shub=0x%x",
                                   *(_DWORD *)(v53 + 1028),
                                   *(_DWORD *)(v53 + 1036),
                                   *(_DWORD *)(v53 + 1032),
                                   *(_DWORD *)(v53 + 1040),
                                   *(_DWORD *)(v53 + 1044));
            if ( v97 )
            {
              if ( *(_DWORD *)(v44 + 2828) != -1 )
              {
                v5 = *(unsigned int *)(v97 + 8);
                if ( (_DWORD)v5 )
                {
                  v61 = 8 * v5;
                  v62 = 0;
                  v63 = 0;
                  v64 = *(int **)(v97 + 16);
                  v65 = *v64;
                  v66 = v64[1];
                  while ( v63 != 72 )
                  {
                    result = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                         3,
                                         4,
                                         3,
                                         "cam_cpas_dump_monitor_array",
                                         3842,
                                         "VCD[index=%d, type=%d, name=%s] [offset=0x%x, value=0x%x]",
                                         *(unsigned __int8 *)(v53 + 1432 + v63),
                                         *(_DWORD *)(*(_QWORD *)v97 + v62 + 4),
                                         *(const char **)(*(_QWORD *)v97 + v62 + 8),
                                         v65 + v66 * (unsigned int)*(unsigned __int8 *)(v53 + 1432 + v63),
                                         *(_DWORD *)(v44 + 1512LL * v96 + v63 + 9660));
                    v63 += 8;
                    v62 += 16;
                    if ( v61 == v63 )
                      goto LABEL_83;
                  }
                  goto LABEL_114;
                }
              }
            }
LABEL_83:
            v67 = 0;
            v68 = 1512LL * v96 + 9272;
            v69 = 1512LL * v96 + 9288;
            v70 = 1512LL * v96 + 9480;
            do
            {
              if ( *(_QWORD *)(*(_QWORD *)v44 + v67 * 8 + 8) )
              {
                v103[0] = 0;
                if ( *(_DWORD *)(v44 + v68) )
                {
                  v71 = scnprintf(
                          v103,
                          512,
                          " %s:[%d %d]",
                          *(const char **)(v44 + v69),
                          *(_DWORD *)(v44 + v70) & 0x7FF,
                          HIWORD(*(_DWORD *)(v44 + v70)) & 0x7F);
                  LODWORD(v5) = *(_DWORD *)(v44 + v68);
                  if ( (unsigned int)v5 >= 2 )
                  {
                    v72 = v71;
                    if ( (unsigned int)v71 > 0x200 )
                      goto LABEL_114;
                    v73 = scnprintf(
                            &v103[v71],
                            512LL - v71,
                            " %s:[%d %d]",
                            *(const char **)(v44 + v69 + 8),
                            *(_DWORD *)(v44 + v70 + 4) & 0x7FF,
                            HIWORD(*(_DWORD *)(v44 + v70 + 4)) & 0x7F);
                    LODWORD(v5) = *(_DWORD *)(v44 + v68);
                    if ( (unsigned int)v5 >= 3 )
                    {
                      v74 = v72 + v73;
                      if ( v74 > 0x200 )
                        goto LABEL_114;
                      v75 = scnprintf(
                              &v103[v74],
                              512 - v74,
                              " %s:[%d %d]",
                              *(const char **)(v44 + v69 + 16),
                              *(_DWORD *)(v44 + v70 + 8) & 0x7FF,
                              HIWORD(*(_DWORD *)(v44 + v70 + 8)) & 0x7F);
                      LODWORD(v5) = *(_DWORD *)(v44 + v68);
                      if ( (unsigned int)v5 >= 4 )
                      {
                        v76 = v74 + v75;
                        if ( v76 > 0x200 )
                          goto LABEL_114;
                        v77 = scnprintf(
                                &v103[v76],
                                512 - v76,
                                " %s:[%d %d]",
                                *(const char **)(v44 + v69 + 24),
                                *(_DWORD *)(v44 + v70 + 12) & 0x7FF,
                                HIWORD(*(_DWORD *)(v44 + v70 + 12)) & 0x7F);
                        LODWORD(v5) = *(_DWORD *)(v44 + v68);
                        if ( (unsigned int)v5 >= 5 )
                        {
                          v78 = v76 + v77;
                          if ( v78 > 0x200 )
                            goto LABEL_114;
                          v79 = scnprintf(
                                  &v103[v78],
                                  512 - v78,
                                  " %s:[%d %d]",
                                  *(const char **)(v44 + v69 + 32),
                                  *(_DWORD *)(v44 + v70 + 16) & 0x7FF,
                                  HIWORD(*(_DWORD *)(v44 + v70 + 16)) & 0x7F);
                          if ( *(_DWORD *)(v44 + v68) >= 6u )
                          {
                            v5 = v78 + v79;
                            if ( v5 > 0x200 )
                              goto LABEL_114;
                            scnprintf(
                              &v103[v5],
                              512 - v5,
                              " %s:[%d %d]",
                              *(const char **)(v44 + v69 + 40),
                              *(_DWORD *)(v44 + v70 + 20) & 0x7FF,
                              HIWORD(*(_DWORD *)(v44 + v70 + 20)) & 0x7F);
                            LODWORD(v5) = *(_DWORD *)(v44 + v68);
                            if ( (unsigned int)v5 > 6 )
                              goto LABEL_114;
                          }
                        }
                      }
                    }
                  }
                }
                result = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                     3,
                                     4,
                                     3,
                                     "cam_cpas_dump_monitor_array",
                                     3862,
                                     "%s REG[Queued Pending] %s",
                                     g_camnoc_names[v67],
                                     v103);
              }
              ++v67;
              v68 += 4;
              v69 += 48;
              v70 += 24;
            }
            while ( v67 != 4 );
            v52 = v95;
            if ( *(_BYTE *)(v100 + 1608) == 1 )
            {
              v5 = *(_QWORD *)(v100 + 1616);
              if ( *(_BYTE *)(v5 + 9) )
              {
                v80 = 0;
                v81 = 0;
                v82 = v53 + 1352;
                v83 = v53 + 1392;
                while ( v80 <= 9 && v81 <= 0x200 )
                {
                  v84 = scnprintf(
                          &v103[v81],
                          512 - v81,
                          " [%s: high 0x%x low 0x%x]",
                          *(const char **)(*(_QWORD *)(v5 + 8 * v80 + 16) + 24LL),
                          *(_DWORD *)(v83 + 4 * v80),
                          *(_DWORD *)(v82 + 4 * v80));
                  ++v80;
                  v81 += v84;
                  v5 = *(_QWORD *)(v100 + 1616);
                  if ( v80 >= *(unsigned __int8 *)(v5 + 9) )
                    goto LABEL_62;
                }
                goto LABEL_114;
              }
LABEL_62:
              result = (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                   3,
                                   4,
                                   3,
                                   "cam_cpas_dump_monitor_array",
                                   3878,
                                   "SmartQoS [Node: Pri_lut] %s",
                                   v103);
              v52 = v95;
            }
            v51 = v52 + 1;
            v46 = (v96 + 1) % 0x64;
            if ( v51 == v93 )
              goto LABEL_107;
          }
          LOBYTE(v5) = v44 + 56;
          v56 = 0;
          v57 = -816;
          v58 = v44 + 1512LL * v96;
          while ( v57 )
          {
            v59 = (_QWORD *)(v58 + v57);
            if ( *(_DWORD *)(v58 + v57 + 9264) != 1 || (*(_BYTE *)(v44 + 159432) & 1) != 0 )
            {
              result = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
                                   3,
                                   4,
                                   3,
                                   "cam_cpas_dump_monitor_array",
                                   3813,
                                   "BW [%s] : HLOS ab=%lld, ib=%lld, DRV high_ab=%lld, high_ib=%lld, low_ab=%lld, low_ib=%lld",
                                   v59[1149],
                                   v59[1159],
                                   v59[1160],
                                   v59[1159],
                                   v59[1160],
                                   v59[1162],
                                   v59[1163]);
            }
            else
            {
              if ( *(_BYTE *)(v44 + 8504 + 1512LL * v96 + v57 + 816) )
                v60 = "Y";
              else
                v60 = "N";
              result = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, const char *, _QWORD, _QWORD, _QWORD, _QWORD, __int64))cam_print_log)(
                                   3,
                                   4,
                                   3,
                                   "cam_cpas_dump_monitor_array",
                                   3802,
                                   "BW [%s] : DRV started:%s high=[%lld %lld], low=[%lld %lld]",
                                   v59[1149],
                                   v60,
                                   *(_QWORD *)(v58 + v57 + 9272),
                                   *(_QWORD *)(v58 + v57 + 9280),
                                   *(_QWORD *)(v58 + v57 + 9296),
                                   *(_QWORD *)(v58 + v57 + 9304),
                                   v90);
            }
            v5 = *(unsigned int *)(v44 + 2780);
            ++v56;
            v57 += 136;
            if ( v56 >= v5 )
              goto LABEL_75;
          }
          goto LABEL_114;
        }
      }
    }
LABEL_107:
    v85 = *(__int64 (__fastcall **)(_QWORD))(v92 + 8056);
    if ( v85 )
    {
      if ( *((_DWORD *)v85 - 1) != -818937679 )
        __break(0x8228u);
      result = (_QWORD *)v85(v94);
    }
    else
    {
      LOBYTE(v5) = debug_mdl;
      if ( (debug_mdl & 4) != 0 && !debug_priority )
        goto LABEL_115;
    }
  }
  else if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    v47 = "CPAS full state dump not enabled";
    v48 = debug_mdl & 4;
    v49 = 3582;
LABEL_116:
    result = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                         3,
                         v48,
                         4,
                         "cam_cpas_log_vote",
                         v49,
                         v47);
  }
LABEL_113:
  _ReadStatusReg(SP_EL0);
  return result;
}
