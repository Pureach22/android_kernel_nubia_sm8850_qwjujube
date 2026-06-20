__int64 __fastcall cam_cpas_hw_start(__int64 a1, _QWORD *a2, int a3)
{
  __int64 v3; // x23
  _DWORD *v7; // x22
  const void *v8; // x1
  __int64 v9; // x24
  __int64 v10; // x25
  __int64 v11; // x20
  unsigned int *v12; // x21
  __int64 v13; // x8
  __int64 result; // x0
  unsigned int v15; // w22
  unsigned int vote_all_paths; // w0
  const char *v17; // x5
  __int64 v18; // x4
  int v19; // w0
  int v20; // w8
  int v21; // w9
  const char *v22; // x6
  const char *v23; // x7
  int v24; // w0
  unsigned int v25; // w0
  _DWORD *v26; // x8
  int v27; // w0
  __int64 (__fastcall *v28)(__int64, __int64, __int64); // x8
  int v29; // w0
  __int64 (__fastcall *v30)(_QWORD); // x8
  unsigned int v31; // w0
  int v32; // [xsp+2Ch] [xbp-284h] BYREF
  _QWORD v33[2]; // [xsp+30h] [xbp-280h] BYREF
  unsigned int s[152]; // [xsp+40h] [xbp-270h] BYREF
  __int64 v35; // [xsp+2A0h] [xbp-10h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v32 = 2;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_start",
      2827,
      "Invalid arguments %pK %pK",
      (const void *)a1,
      a2);
    result = 4294967274LL;
    goto LABEL_21;
  }
  if ( a3 != 24 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_start",
      2833,
      "HW_CAPS size mismatch %zd %d",
      0x18u,
      a3);
LABEL_20:
    result = 4294967274LL;
    goto LABEL_21;
  }
  v7 = (_DWORD *)a2[1];
  if ( !v7 )
    goto LABEL_20;
  v8 = (const void *)a2[2];
  if ( !v8 )
    goto LABEL_20;
  if ( !v7[2] )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_start",
      2850,
      "Invalid vote ahb[%d]",
      0);
    result = 4294967274LL;
    goto LABEL_21;
  }
  v9 = *(_QWORD *)(a1 + 3680);
  v10 = *(_QWORD *)(a1 + 3392);
  v11 = *(unsigned int *)a2;
  v12 = s;
  memcpy(s, v8, sizeof(s));
  if ( !s[0] )
  {
LABEL_17:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_start",
      2865,
      "Zero start vote");
    result = 4294967274LL;
    goto LABEL_21;
  }
  v13 = 0;
  while ( 1 )
  {
    if ( v13 == 600 )
      goto LABEL_89;
    if ( (unsigned __int64)(v13 - 584) < 0xFFFFFFFFFFFFFDA0LL )
      break;
    if ( *(_QWORD *)((char *)&s[6] + v13) )
      goto LABEL_23;
    if ( (unsigned __int64)(v13 - 576) < 0xFFFFFFFFFFFFFDA0LL )
      break;
    if ( *(_QWORD *)((char *)&s[8] + v13) )
    {
LABEL_23:
      if ( (unsigned int)v11 > 0x2A )
        goto LABEL_20;
      mutex_lock(a1);
      v3 = v9 + 48LL * (unsigned int)v11;
      mutex_lock(v3 + 664);
      v12 = *(unsigned int **)(v9 + 8 * v11 + 320);
      if ( (v12[42] & 1) == 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_hw_start",
          2878,
          "client=[%d] is not registered",
          v11);
        goto LABEL_28;
      }
      if ( *((_BYTE *)v12 + 169) == 1 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_hw_start",
          2886,
          "client=[%d][%s][%d] is in start state",
          v11,
          *(const char **)(v9 + 8 * v11 + 320),
          v12[32]);
LABEL_28:
        v15 = -1;
LABEL_29:
        mutex_unlock(v3 + 664);
        mutex_unlock(a1);
        result = v15;
        goto LABEL_21;
      }
      if ( (debug_mdl & 4) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 4,
          4,
          "cam_cpas_hw_start",
          2895,
          "AHB :client=[%d][%s][%d] type[%d], level[%d], applied[%d]",
          v11,
          *(const char **)(v9 + 8 * v11 + 320),
          v12[32],
          *v7,
          v7[2],
          v12[43]);
      v15 = cam_cpas_util_apply_client_ahb_vote(a1, v12, v7, &v32);
      if ( v15 )
        goto LABEL_29;
      cam_cpas_dump_axi_vote_info((__int64)v12, "CPAS Start Vote", s);
      if ( s[4] == 512 )
        vote_all_paths = cam_cpas_util_create_vote_all_paths(v12, s, 1);
      else
        vote_all_paths = cam_cpas_util_translate_client_paths(s);
      if ( vote_all_paths )
      {
        v17 = "Unable to create or translate paths rc: %d";
        v18 = 2915;
        v15 = vote_all_paths;
LABEL_39:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_hw_start",
          v18,
          v17);
LABEL_40:
        v33[0] = 0;
        v33[1] = 0;
        v19 = cam_cpas_util_apply_client_ahb_vote(a1, v12, v33, 0);
        if ( v19 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_hw_start",
            3023,
            "Removing AHB vote failed, rc=%d",
            v19);
        goto LABEL_29;
      }
      cam_cpas_dump_axi_vote_info((__int64)v12, "CPAS Start Translated Vote", s);
      if ( !*(_DWORD *)(v9 + 2792) )
      {
        if ( *(_BYTE *)(v9 + 159432) == 1 )
          *(_WORD *)(v10 + 1609) = 0;
        if ( *(_BYTE *)(v9 + 159433) == 1 )
          *(_BYTE *)(v10 + 1610) = 0;
        if ( debug_drv )
        {
          if ( *(_BYTE *)(v10 + 1609) )
            v22 = "Y";
          else
            v22 = "N";
          if ( *(_BYTE *)(v10 + 1610) )
            v23 = "Y";
          else
            v23 = "N";
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, const char *))cam_print_log)(
            3,
            4,
            3,
            "cam_cpas_hw_start",
            2933,
            "DRV enable[DDR CLK]:[%s %s]",
            v22,
            v23);
        }
        v15 = cam_cpas_util_apply_default_axi_vote(a1, 1);
        if ( v15 )
          goto LABEL_40;
        *(_DWORD *)(v9 + 8104) = 1;
        v24 = ((__int64 (__fastcall *)(__int64))cam_soc_util_regulators_enabled)(a1 + 96);
        if ( v24 >= 1 && (debug_mdl & 4) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_hw_start",
            2943,
            "Regulators already enabled %d",
            v24);
        v25 = cam_cpas_soc_enable_resources(a1 + 96);
        if ( v25 )
        {
          v15 = v25;
          *(_DWORD *)(v9 + 8104) = 0;
          v17 = "enable_resorce failed, rc=%d";
          v18 = 2949;
          goto LABEL_39;
        }
        v26 = *(_DWORD **)(v9 + 8064);
        if ( v26 )
        {
          if ( *(v26 - 1) != -1708089619 )
            __break(0x8228u);
          v27 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v26)(a1, 1, 0);
          if ( v27 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              2,
              "cam_cpas_hw_start",
              2956,
              "failed in qchannel_handshake rc=%d",
              v27);
            v28 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v9 + 8064);
            if ( *((_DWORD *)v28 - 1) != -1708089619 )
              __break(0x8228u);
            v29 = v28(a1, 1, 1);
            if ( v29 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                4,
                1,
                "cam_cpas_hw_start",
                2964,
                "failed in qchannel_handshake, hw blocks may not work rc=%d",
                v29);
          }
        }
        v30 = *(__int64 (__fastcall **)(_QWORD))(v9 + 8032);
        if ( v30 )
        {
          if ( *((_DWORD *)v30 - 1) != -818937679 )
            __break(0x8228u);
          v31 = v30(a1);
          if ( v31 )
          {
            v15 = v31;
            *(_DWORD *)(v9 + 8104) = 0;
            cam_cpas_soc_disable_resources(a1 + 96, 1u, 1u);
            v17 = "failed in power_on settings rc=%d";
            v18 = 2978;
            goto LABEL_39;
          }
        }
        if ( (debug_mdl & 4) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_hw_start",
            2983,
            "soc_access_count=%d\n",
            *(_DWORD *)(v9 + 8104));
        if ( *(_BYTE *)(v10 + 1608) == 1 )
          cam_cpas_reset_niu_priorities(a1);
        cam_smmu_reset_cb_page_fault_cnt();
        *(_DWORD *)(a1 + 92) = 1;
      }
      v15 = cam_cpas_util_apply_client_axi_vote(a1, v12, s, 1);
      if ( !v15 )
      {
        *((_BYTE *)v12 + 169) = 1;
        v20 = *(_DWORD *)(v9 + 2792);
        v21 = debug_drv;
        *(_DWORD *)(v9 + 2792) = v20 + 1;
        if ( v21 && !v20 )
        {
          cam_cpas_log_vote(a1, 0);
          cam_cpas_dump_full_tree_state(a1, "StartFirstClient");
        }
        LOBYTE(v13) = debug_mdl;
        if ( (debug_mdl & 4) != 0 && !debug_priority )
          goto LABEL_90;
        goto LABEL_49;
      }
      goto LABEL_40;
    }
    if ( (unsigned __int64)(v13 - 568) < 0xFFFFFFFFFFFFFDA0LL )
      break;
    if ( *(_QWORD *)((char *)&s[10] + v13) )
      goto LABEL_23;
    v13 += 40;
    if ( 40LL * s[0] == v13 )
      goto LABEL_17;
  }
  __break(1u);
LABEL_89:
  __break(0x5512u);
LABEL_90:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    v13 & 4,
    4,
    "cam_cpas_hw_start",
    3011,
    "client=[%d][%s][%d] streamon_clients=%d",
    v11,
    (const char *)v12,
    v12[32],
    *(_DWORD *)(v9 + 2792));
LABEL_49:
  mutex_unlock(v3 + 664);
  mutex_unlock(a1);
  result = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
