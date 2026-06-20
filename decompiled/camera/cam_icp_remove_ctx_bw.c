void *__fastcall cam_icp_remove_ctx_bw(__int64 a1, __int64 a2)
{
  void *result; // x0
  const char **v5; // x28
  unsigned int v6; // w7
  int v7; // w21
  unsigned __int64 v8; // x22
  const char *v9; // x10
  const char *v10; // x12
  int v11; // w10
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x23
  _QWORD *v15; // x27
  __int64 v16; // x20
  unsigned int v17; // w8
  const char **v18; // x8
  const char *v19; // x11
  const char *v20; // x10
  const char *v21; // x26
  __int64 v22; // x24
  int v23; // w8
  const char *v24; // x26
  const char *v25; // x0
  const char *v26; // x0
  int v27; // w20
  __int64 v28; // x21
  unsigned __int64 v29; // x8
  _QWORD *v30; // x10
  unsigned __int64 v31; // x12
  unsigned __int64 v32; // x11
  int v33; // w8
  int v34; // w22
  __int64 v35; // x8
  _DWORD *v36; // x9
  __int64 v37; // x0
  __int64 v38; // x0
  const char *v39; // [xsp+28h] [xbp-2A8h]
  unsigned int v40; // [xsp+34h] [xbp-29Ch]
  const char *v41; // [xsp+40h] [xbp-290h]
  _QWORD s[81]; // [xsp+48h] [xbp-288h] BYREF

  s[79] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = memset(s, 0, 0x278u);
  if ( !*(_QWORD *)(a2 + 80) )
  {
    result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       256,
                       2,
                       "cam_icp_remove_ctx_bw",
                       594,
                       "%s: NULL acquire info",
                       (const char *)(a2 + 29824));
LABEL_65:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (debug_mdl & 0x2000100) == 0 || debug_priority )
  {
    if ( (*(_BYTE *)(a2 + 29792) & 1) != 0 )
      goto LABEL_5;
LABEL_62:
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
      result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         debug_mdl & 0x2000100,
                         4,
                         "cam_icp_remove_ctx_bw",
                         607,
                         "%s: BW vote already removed",
                         (const char *)(a2 + 29824));
    goto LABEL_65;
  }
  result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     debug_mdl & 0x2000100,
                     4,
                     "cam_icp_remove_ctx_bw",
                     603,
                     "%s: ubw = %lld cbw = %lld curr_fc = %u bc = %u",
                     (const char *)(a2 + 29824),
                     *(_QWORD *)(a2 + 29248),
                     *(_QWORD *)(a2 + 29256),
                     *(_DWORD *)(a2 + 29232),
                     *(_DWORD *)(a2 + 29240));
  if ( (*(_BYTE *)(a2 + 29792) & 1) == 0 )
    goto LABEL_62;
LABEL_5:
  v5 = *(const char ***)(a2 + 16);
  v6 = *((_DWORD *)v5 + 145);
  v7 = *((_DWORD *)v5 + 2);
  if ( v6 < 2 )
  {
    v8 = 1;
    goto LABEL_11;
  }
  if ( v6 != 2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_get_bw_device_share_ratio",
      573,
      "[%s] Number of devices %u not supported for geting bw device share ratio",
      a1 + 112);
    result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_icp_remove_ctx_bw",
                       618,
                       "%s: Fail to get device share ratio",
                       (const char *)(a2 + 29824));
    goto LABEL_65;
  }
  v8 = 2;
LABEL_11:
  if ( *(_DWORD *)(a2 + 29228) == 1 )
  {
    v9 = v5[6];
    v10 = &v5[7][-*(_QWORD *)(a2 + 29256)];
    v5[7] = v10;
    v5[6] = &v9[-*(_QWORD *)(a2 + 29248)];
    if ( v7 == 2 )
      v11 = 34;
    else
      v11 = 163;
    *(_DWORD *)(a2 + 29232) = 0;
    *(_DWORD *)(a2 + 29240) = 0;
    if ( v7 == 3 )
      v11 = 256;
    *(_QWORD *)(a2 + 29248) = 0;
    *(_QWORD *)(a2 + 29256) = 0;
    v12 = (unsigned __int64)v5[6];
    v13 = (unsigned __int64)v5[7];
    LODWORD(s[4]) = v11;
    HIDWORD(s[3]) = 1;
    LODWORD(s[2]) = 1;
    s[5] = v12 / v8;
    s[6] = v13 / v8;
    s[7] = v13 / v8;
LABEL_46:
    HIDWORD(s[78]) = 1;
    if ( v10 )
    {
      v33 = 0;
    }
    else
    {
      LODWORD(s[0]) = 0;
      LODWORD(s[1]) = 2;
      v33 = 1;
    }
    LODWORD(s[78]) = v33;
    if ( *((_DWORD *)v5 + 145) )
    {
      v34 = 0;
      while ( 1 )
      {
        v35 = *(_QWORD *)&v5[2][8 * v34];
        if ( !v35 )
          break;
        v36 = *(_DWORD **)(v35 + 88);
        v37 = *(_QWORD *)(v35 + 112);
        if ( *(v36 - 1) != -1055839300 )
          __break(0x8229u);
        result = (void *)((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v36)(v37, 3, s, 632);
        if ( (_DWORD)result )
          result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                             3,
                             0x2000000,
                             1,
                             "cam_icp_remove_ctx_bw",
                             767,
                             "%s: Failed in updating cpas vote for %s cell idx: %u, rc=%d",
                             (const char *)(a2 + 29824),
                             *v5,
                             v34,
                             (_DWORD)result);
        if ( (unsigned int)++v34 >= *((_DWORD *)v5 + 145) )
          goto LABEL_57;
      }
      result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         256,
                         1,
                         "cam_icp_remove_ctx_bw",
                         759,
                         "%s: Device intf for %s[%u] is NULL",
                         (const char *)(a2 + 29824),
                         *v5,
                         v34);
    }
    else
    {
LABEL_57:
      *(_BYTE *)(a2 + 29792) = 0;
      if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
        result = (void *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                           3,
                           debug_mdl & 0x2000100,
                           4,
                           "cam_icp_remove_ctx_bw",
                           774,
                           "%s: X :curr_fc = %u bc = %u",
                           (const char *)(a2 + 29824),
                           *(_DWORD *)(a2 + 29232),
                           *(_DWORD *)(a2 + 29240));
    }
    goto LABEL_65;
  }
  v40 = *((_DWORD *)v5 + 145);
  if ( *(_DWORD *)(a2 + 29304) )
  {
    v14 = 0;
    v15 = v5 + 13;
    v16 = a2 + 29316;
    v41 = nullptr;
    while ( 1 )
    {
      switch ( v7 )
      {
        case 2:
          v17 = *(_DWORD *)(v16 + 4) - 32;
          break;
        case 4:
          v17 = *(_DWORD *)(v16 + 4) - 160;
          break;
        case 3:
          v17 = *(_DWORD *)v16;
          break;
        default:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_get_axi_path_index",
            551,
            "Invalid hw dev type not supported: %u",
            v7);
          if ( v14 == 12 )
            goto LABEL_66;
          goto LABEL_21;
      }
      if ( v14 == 12 )
        goto LABEL_66;
      if ( (v17 & 0x80000000) == 0 )
      {
        if ( v17 < 0xC )
        {
          v18 = &v5[5 * v17 + 9];
          v19 = v18[3];
          v20 = v18[4];
          v18[2] -= *(_QWORD *)(v16 + 12);
          v21 = &v19[-*(_QWORD *)(v16 + 20)];
          v18[3] = v21;
          v18[4] = &v20[-*(_QWORD *)(v16 + 28)];
          v22 = debug_mdl & 0x2000100;
          v23 = debug_priority;
          if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
          {
            v39 = cam_cpas_axi_util_path_type_to_string(*(_DWORD *)(v16 + 4));
            v26 = cam_cpas_axi_util_trans_type_to_string(*(_DWORD *)v16);
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v22,
              4,
              "cam_icp_remove_ctx_bw",
              697,
              "%s: Removing ctx bw from path_type: %s, transac_type: %s, camnoc_bw = %lld mnoc_ab_bw = %lld, mnoc_ib_bw = %lld",
              (const char *)(a2 + 29824),
              v39,
              v26,
              *(_QWORD *)(v16 + 12),
              *(_QWORD *)(v16 + 20),
              *(_QWORD *)(v16 + 28));
            v23 = debug_priority;
            v22 = debug_mdl & 0x2000100;
          }
          v41 = &v41[(_QWORD)v21];
          if ( v22 && !v23 )
          {
            v24 = cam_cpas_axi_util_path_type_to_string(*((_DWORD *)v15 - 6));
            v25 = cam_cpas_axi_util_trans_type_to_string(*((_DWORD *)v15 - 7));
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v22,
              4,
              "cam_icp_remove_ctx_bw",
              708,
              "%s: Final HW bw for path_type: %s, transac_type: %s, camnoc_bw = %lld mnoc_ab_bw = %lld, mnoc_ib_bw = %lld",
              (const char *)(a2 + 29824),
              v24,
              v25,
              *(v15 - 2),
              *(v15 - 1),
              *v15);
          }
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000000,
            2,
            "cam_icp_validate_bw_path_idx",
            531,
            "Invalid path: %u IPE start offset: %d, OFE start offset: %d max: %d",
            *(_DWORD *)(v16 + 4),
            32,
            160,
            12);
        }
      }
LABEL_21:
      ++v14;
      v15 += 5;
      v16 += 40;
      if ( v14 >= *(unsigned int *)(a2 + 29304) )
        goto LABEL_39;
    }
  }
  v41 = nullptr;
LABEL_39:
  memset((void *)(a2 + 29312), 0, 0x1E0u);
  *(_DWORD *)(a2 + 29232) = 0;
  *(_DWORD *)(a2 + 29240) = 0;
  LODWORD(s[2]) = *((_DWORD *)v5 + 16);
  v27 = s[2];
  v28 = 40LL * LODWORD(s[2]);
  if ( LODWORD(s[2]) < 0x10 )
  {
    result = memcpy(&s[3], v5 + 9, 40LL * LODWORD(s[2]));
    if ( v40 >= 2 && v27 )
    {
      v29 = 0;
      while ( v29 != 600 )
      {
        v30 = &s[v29 / 8];
        v29 += 40LL;
        v31 = v30[6];
        v32 = v30[5] / v8;
        v30[7] /= v8;
        v30[5] = v32;
        v30[6] = v31 / v8;
        if ( v28 == v29 )
          goto LABEL_45;
      }
LABEL_66:
      __break(0x5512u);
    }
LABEL_45:
    v10 = v41;
    goto LABEL_46;
  }
  v38 = _fortify_panic(17, 608, 40LL * LODWORD(s[2]));
  return (void *)cam_icp_mgr_abort_handle(v38);
}
