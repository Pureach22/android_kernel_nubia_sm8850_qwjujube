__int64 __fastcall cam_cpas_hw_stop(__int64 a1, unsigned int *a2, int a3)
{
  __int64 v3; // x28
  __int64 v7; // x22
  __int64 v8; // x20
  __int64 v9; // x21
  __int64 v10; // x25
  __int64 v11; // x7
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x11
  __int64 v15; // x12
  unsigned __int64 v16; // x8
  __int64 v17; // x13
  __int64 v18; // x14
  __int64 result; // x0
  _QWORD *v20; // x17
  unsigned int v21; // w20
  __int64 v22; // x13
  __int64 v23; // x14
  _QWORD *v24; // x0
  __int64 v25; // x24
  unsigned int v26; // w0
  const char *v27; // x5
  unsigned int v28; // w6
  __int64 v29; // x4
  unsigned int updated; // w0
  __int64 v31; // x1
  int v32; // w8
  __int64 (__fastcall *v33)(__int64, __int64); // x8
  int v34; // w0
  _DWORD *v35; // x8
  int v36; // w0
  char v37; // w24
  unsigned int v38; // w0
  __int64 v39; // x0
  __int64 v40; // x23
  int v41; // w8
  bool v42; // cc
  __int64 v43; // x23
  _DWORD *v44; // x8
  char v45; // w9
  int v46; // w0
  unsigned int v47; // w0
  int v48; // w0
  int v49; // w0
  int v50; // w0
  unsigned int v57; // w10
  __int64 v58; // [xsp+20h] [xbp-2B0h]
  _QWORD v59[5]; // [xsp+28h] [xbp-2A8h] BYREF
  __int64 v60; // [xsp+50h] [xbp-280h] BYREF
  __int64 v61; // [xsp+58h] [xbp-278h]
  _QWORD s[78]; // [xsp+60h] [xbp-270h] BYREF

  s[76] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60 = 0;
  v61 = 0;
  memset(s, 0, 0x260u);
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_stop",
      3094,
      "Invalid arguments %pK %pK",
      (const void *)a1,
      a2);
    result = 4294967274LL;
    goto LABEL_24;
  }
  if ( a3 != 4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_stop",
      3100,
      "HW_CAPS size mismatch %zd %d",
      4u,
      a3);
    goto LABEL_21;
  }
  v7 = *a2;
  if ( (unsigned int)v7 > 0x2A )
  {
LABEL_21:
    result = 4294967274LL;
    goto LABEL_24;
  }
  v8 = *(_QWORD *)(a1 + 3680);
  v9 = *(_QWORD *)(a1 + 3392);
  mutex_lock(a1);
  v10 = v8 + 48LL * (unsigned int)v7;
  mutex_lock(v10 + 664);
  v11 = *(_QWORD *)(v8 + 320 + 8 * v7);
  v12 = v11;
  if ( (debug_mdl & 4) != 0 )
  {
    v12 = *(_QWORD *)(v8 + 320 + 8 * v7);
    if ( !debug_priority )
    {
      v58 = v11;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_hw_stop",
        3120,
        "Client=[%d][%s][%d] streamon_clients=%d",
        v7,
        (const char *)v11,
        *(_DWORD *)(v11 + 128),
        *(_DWORD *)(v8 + 2792));
      v11 = v58;
      v12 = *(_QWORD *)(v8 + 320 + 8 * v7);
    }
  }
  if ( *(_BYTE *)(v12 + 168) != 1 || (*(_BYTE *)(v12 + 169) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_stop",
      3125,
      "Client=[%d][%s][%d] is not started",
      (unsigned int)v7);
    v21 = -1;
    goto LABEL_23;
  }
  if ( !v11 )
  {
    v21 = -22;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_stop",
      3132,
      "Unable to create per path votes rc: %d",
      -22);
    goto LABEL_23;
  }
  v13 = s[3];
  v14 = s[4];
  v15 = s[5];
  v16 = 0;
  v17 = 0;
  v18 = v11 + 1040;
  LODWORD(s[0]) = 0;
  while ( !*(_QWORD *)v18 )
  {
LABEL_14:
    ++v17;
    v18 += 16;
    if ( v17 == 42 )
    {
      v22 = 0;
      v23 = v11 + 1048;
      do
      {
        if ( *(_QWORD *)v23 )
        {
          if ( v16 > 0xF )
            goto LABEL_94;
          if ( v16 == 15 )
            goto LABEL_93;
          v24 = &s[5 * v16 + 1];
          *((_DWORD *)v24 + 1) = 1;
          *((_DWORD *)v24 + 2) = v22;
          v24[2] = v13;
          v24[3] = v14;
          v24[4] = v15;
          if ( *(int *)(*(_QWORD *)v23 + 16LL) >= 1 )
            *((_DWORD *)v24 + 3) = 2;
          LODWORD(s[0]) = ++v16;
        }
        ++v22;
        v23 += 16;
      }
      while ( v22 != 42 );
      v58 = v8 + 155648;
      v25 = v11;
      cam_cpas_dump_axi_vote_info(v11, "CPAS Stop Vote", (unsigned int *)s);
      v3 = v25;
      v26 = cam_cpas_util_apply_client_axi_vote(a1, v25, s, 2);
      if ( v26 )
      {
        v27 = "Failed in apply client axi vote rc: %d";
        v28 = v26;
        v29 = 3141;
      }
      else
      {
        updated = cam_cpas_hw_update_axi_floor_lvl(a1, *a2, 0, 1);
        if ( updated )
        {
          v27 = "Failed in update AXI floor lvl rc: %d";
          v28 = updated;
          v29 = 3148;
        }
        else
        {
          v31 = v25;
          *(_BYTE *)(v25 + 169) = 0;
          if ( debug_drv && *(_DWORD *)(v8 + 2792) == 1 )
          {
            cam_cpas_log_vote(a1, 0);
            cam_cpas_dump_full_tree_state(a1, "StopLastClient");
            v31 = v25;
          }
          v32 = *(_DWORD *)(v8 + 2792) - 1;
          *(_DWORD *)(v8 + 2792) = v32;
          if ( v32 )
            goto LABEL_43;
          v33 = *(__int64 (__fastcall **)(__int64, __int64))(v8 + 8040);
          if ( v33 )
          {
            if ( *((_DWORD *)v33 - 1) != -818937679 )
              __break(0x8228u);
            v34 = v33(a1, v31);
            if ( v34 )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                4,
                1,
                "cam_cpas_hw_stop",
                3166,
                "failed in power_off settings rc=%d",
                v34);
          }
          v35 = *(_DWORD **)(v8 + 8064);
          if ( !v35 )
            goto LABEL_54;
          if ( *(v35 - 1) != -1708089619 )
            __break(0x8228u);
          v36 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v35)(a1, 0, 0);
          if ( v36 )
          {
            v37 = 1;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_hw_stop",
              3174,
              "failed in qchannel_handshake rc=%d",
              v36);
          }
          else
          {
LABEL_54:
            v37 = 0;
          }
          v38 = cam_cpas_soc_disable_irq();
          if ( v38 )
          {
            v27 = "disable_irq failed, rc=%d";
            v28 = v38;
            v29 = 3182;
          }
          else
          {
            _X8 = (unsigned int *)(v8 + 8104);
            __asm { PRFM            #0x11, [X8] }
            do
              v57 = __ldxr(_X8);
            while ( __stxr(v57 - 1, _X8) );
            if ( *(int *)(v8 + 8104) >= 1 )
            {
              memset(v59, 0, sizeof(v59));
              init_wait_entry(v59, 0);
              prepare_to_wait_event(v8 + 8112, v59, 2);
              if ( *(int *)(v8 + 8104) < 1 )
              {
                finish_wait(v8 + 8112, v59);
              }
              else
              {
                v39 = 250;
                do
                {
                  v40 = schedule_timeout(v39);
                  prepare_to_wait_event(v8 + 8112, v59, 2);
                  v41 = *(_DWORD *)(v8 + 8104);
                  if ( v40 )
                    v42 = 0;
                  else
                    v42 = v41 < 1;
                  if ( v42 )
                    v39 = 1;
                  else
                    v39 = v40;
                }
                while ( v41 >= 1 && v39 );
                v43 = v39;
                finish_wait(v8 + 8112, v59);
                if ( !v43 )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    4,
                    1,
                    "cam_cpas_hw_stop",
                    3192,
                    "Wait failed: soc_access_count=%d",
                    *(_DWORD *)(v8 + 8104));
              }
            }
            v44 = *(_DWORD **)(v8 + 8064);
            v45 = v37 ^ 1;
            if ( !v44 )
              v45 = 1;
            if ( (v45 & 1) == 0 )
            {
              if ( *(v44 - 1) != -1708089619 )
                __break(0x8228u);
              v46 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v44)(a1, 0, 1);
              if ( v46 )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  4,
                  1,
                  "cam_cpas_hw_stop",
                  3200,
                  "failed in qchannel_handshake rc=%d",
                  v46);
            }
            v47 = cam_cpas_soc_disable_resources(a1 + 96, 1u, 0);
            if ( !v47 )
            {
              LOBYTE(v16) = debug_mdl;
              if ( (debug_mdl & 4) != 0 && !debug_priority )
                goto LABEL_95;
              goto LABEL_83;
            }
            v27 = "disable_resorce failed, rc=%d";
            v28 = v47;
            v29 = 3208;
          }
        }
      }
      v21 = v28;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_hw_stop",
        v29,
        v27);
      goto LABEL_23;
    }
  }
  if ( v16 > 0xF )
    goto LABEL_94;
  if ( v16 != 15 )
  {
    v20 = &s[5 * v16 + 1];
    *((_DWORD *)v20 + 1) = 0;
    *((_DWORD *)v20 + 2) = v17;
    v20[2] = v13;
    v20[3] = v14;
    v20[4] = v15;
    if ( *(int *)(*(_QWORD *)v18 + 16LL) >= 1 )
      *((_DWORD *)v20 + 3) = 2;
    LODWORD(s[0]) = ++v16;
    goto LABEL_14;
  }
LABEL_93:
  __break(1u);
LABEL_94:
  __break(0x5512u);
LABEL_95:
  ((void (*)(__int64, unsigned __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    v16 & 4,
    4,
    "cam_cpas_hw_stop",
    3212,
    "Disabled all the resources: soc_access_count=%d",
    *(_DWORD *)(v8 + 8104));
LABEL_83:
  v48 = ((__int64 (__fastcall *)(__int64))cam_soc_util_regulators_enabled)(a1 + 96);
  if ( v48 >= 1 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      2,
      "cam_cpas_hw_stop",
      3219,
      "Client=[%d][%s][%d] qchannel shut down while top gdsc is still on %d",
      v7,
      (const char *)v3,
      *(_DWORD *)(v3 + 128),
      v48);
  v49 = cam_cpas_util_apply_default_axi_vote(a1, 0);
  if ( v49 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_stop",
      3223,
      "Failed in power off default vote rc: %d",
      v49);
  v50 = cam_cpas_util_validate_stop_bw(v9, v8);
  if ( v50 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_stop",
      3227,
      "Invalid applied bw at stop rc: %d",
      v50);
  if ( (debug_mdl & 4) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_hw_stop",
      3230,
      "hlos axi floor lvl: %d, hlos axi clk lvl: %d",
      *(_DWORD *)(v58 + 3788),
      *(_DWORD *)(v58 + 3792));
  v31 = v3;
  *(_DWORD *)(a1 + 92) = 0;
LABEL_43:
  LODWORD(v60) = 0;
  LODWORD(v61) = 0;
  v21 = cam_cpas_util_apply_client_ahb_vote(a1, v31, &v60, 0);
LABEL_23:
  mutex_unlock(v10 + 664);
  mutex_unlock(a1);
  result = v21;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
