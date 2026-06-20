__int64 __fastcall gen8_hwsched_hfi_start(__int64 a1)
{
  __int64 v2; // x20
  _DWORD *v3; // x8
  unsigned int inited; // w21
  __int64 v5; // x20
  __int64 v7; // x0
  _QWORD *v8; // x0
  char v10; // w9
  __int64 v11; // x8
  int v12; // w9
  __int64 v13; // x8
  int v14; // w3
  int v15; // w8
  int v16; // w9
  __int64 v17; // x8
  int v18; // w9
  __int64 v19; // x8
  unsigned __int64 v26; // x10
  unsigned __int64 v29; // x10
  unsigned __int64 v32; // x10
  unsigned __int64 v35; // x11
  unsigned __int64 v37; // x10
  unsigned __int64 v39; // x10
  unsigned __int64 v41; // x10
  unsigned __int64 v44; // x9
  unsigned __int64 v47; // x9
  int v48; // [xsp+4h] [xbp-9Ch] BYREF
  int v49; // [xsp+8h] [xbp-98h]
  int v50; // [xsp+Ch] [xbp-94h]
  int v51; // [xsp+10h] [xbp-90h]
  int v52; // [xsp+14h] [xbp-8Ch]
  _QWORD v53[17]; // [xsp+18h] [xbp-88h] BYREF

  v53[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = to_gen8_gmu(a1);
  memset(v53, 0, 128);
  v3 = *(_DWORD **)(*(_QWORD *)(to_gen8_gmu(a1) + 48) + 8LL);
  if ( v3[6] )
    v3[16] = v3[17];
  if ( v3[18] )
    v3[28] = v3[29];
  if ( v3[30] )
    v3[40] = v3[41];
  inited = gen8_gmu_hfi_start(a1);
  if ( !inited )
  {
    v7 = to_gen8_gmu(a1);
    if ( *(_BYTE *)(a1 + 8284) == 1
      && (*(_QWORD *)(v7 + 1040) & 0x40) != 0
      && (*(_QWORD *)(v7 + 1040) & 0x80) != 0
      && (*(_QWORD *)(a1 + 1528) & 0x100) == 0 )
    {
      inited = gen8_hwsched_warmboot_init_gmu(a1);
      goto LABEL_9;
    }
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 34LL) & 8) != 0
      && (*(_QWORD *)(v2 + 1040) & 1) == 0
      && (unsigned int)gen8_hfi_send_get_value(a1, 125, 0) == 1 )
    {
      *(_BYTE *)(a1 + 8284) = 1;
    }
    v8 = (_QWORD *)to_gen8_hfi(a1);
    if ( *(_BYTE *)(a1 + 8284) == 1 )
    {
      _X8 = v8 + 117;
      v8[120] = -1;
      v8[119] = -1;
      v8[118] = -1;
      v8[117] = -1;
      _X9 = v8 + 119;
      __asm { PRFM            #0x11, [X9] }
      do
        v35 = __ldxr(_X9);
      while ( __stxr(v35 & 0xFFFFFFFFFBFFFFFFLL, _X9) );
      __asm { PRFM            #0x11, [X8] }
      do
        v37 = __ldxr(_X8);
      while ( __stxr(v37 & 0xFFFFFFFFFFFFFBFFLL, _X8) );
      __asm { PRFM            #0x11, [X8] }
      do
        v39 = __ldxr(_X8);
      while ( __stxr(v39 & 0xFFFFFFFFFFFFEFFFLL, _X8) );
      __asm { PRFM            #0x11, [X8] }
      do
        v41 = __ldxr(_X8);
      while ( __stxr(v41 & 0xFFFFFFFFBFFFFFFFLL, _X8) );
    }
    _X8 = (unsigned __int64 *)(v2 + 1040);
    __asm { PRFM            #0x11, [X8] }
    do
      v29 = __ldxr(_X8);
    while ( __stxr(v29 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
    _X8 = (unsigned __int64 *)(v2 + 1040);
    __asm { PRFM            #0x11, [X8] }
    do
      v32 = __ldxr(_X8);
    while ( __stxr(v32 & 0xFFFFFFFFFFFFFF7FLL, _X8) );
    v10 = *(_BYTE *)(a1 + 8284);
    v11 = *(_QWORD *)(v2 + 24);
    v49 = 0;
    if ( (v10 & 1) == 0
      || (v12 = *(_DWORD *)(v11 + 184),
          v13 = *(_QWORD *)(v11 + 40),
          v51 = v12,
          v52 = v13,
          v50 = 0,
          v48 = 154,
          (inited = gen8_hfi_send_generic_req_v5(a1, &v48, (int *)v53, 0x14u)) == 0) )
    {
      inited = ((__int64 (__fastcall *)(__int64))gen8_hfi_send_gpu_perf_table)(a1);
      if ( !inited )
      {
        inited = gen8_hfi_send_generic_req(a1, v2 + 56, 640);
        if ( !inited )
        {
          inited = gen8_hfi_send_gmu_dcvs_req(a1);
          if ( !inited )
          {
            inited = gen8_hfi_send_acd_feature_ctrl(a1);
            if ( !inited )
            {
              inited = gen8_hfi_send_bcl_feature_ctrl(a1);
              if ( !inited )
              {
                inited = gen8_hfi_send_clx_feature_ctrl(a1);
                if ( !inited )
                {
                  inited = gen8_hfi_send_ifpc_feature_ctrl(a1);
                  if ( !inited )
                  {
                    inited = gen8_hfi_send_minbw_feature_ctrl(a1);
                    if ( !inited )
                    {
                      inited = gen8_hfi_send_thermal_feature_ctrl(a1);
                      if ( !inited )
                      {
                        inited = gen8_hfi_send_feature_ctrl(a1, 1, 1, 0);
                        if ( !inited )
                        {
                          inited = gen8_hfi_send_feature_ctrl(a1, 16, 1, 0);
                          if ( !inited
                            && ((*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x80) == 0
                             || (inited = gen8_hfi_send_feature_ctrl(a1, 23, 1, 0)) == 0)
                            && (*(_BYTE *)(a1 + 23968) != 1 || (inited = gen8_hfi_send_feature_ctrl(a1, 26, 0, 0)) == 0)
                            && (*(_BYTE *)(a1 + 19672) != 1
                             || (*(_QWORD *)(a1 + 14240) & 0x1000) != 0
                             || (inited = gen8_hfi_send_feature_ctrl(a1, 17, 1, 0)) == 0) )
                          {
                            enable_gmu_stats_1(a1);
                            if ( *(_BYTE *)(v2 + 1056) == 1 )
                              gen8_hfi_send_set_value(a1, 119, 0, 1);
                            v14 = *(_DWORD *)(v2 + 1060);
                            if ( v14 )
                              gen8_hfi_send_set_value(a1, 111, 0, v14);
                            inited = gen8_hfi_send_core_fw_start(a1);
                            if ( !inited )
                            {
                              inited = gen8_hfi_send_hw_fence_feature_ctrl(a1);
                              if ( !inited )
                              {
                                inited = enable_preemption_1(a1);
                                if ( !inited
                                  && (*(_BYTE *)(a1 + 20440) != 1
                                   || (inited = gen8_hfi_send_feature_ctrl(a1, 24, 1, 0)) == 0)
                                  && ((*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 34LL) & 4) == 0
                                   || (inited = gen8_hfi_send_feature_ctrl(a1, 29, 1, 0)) == 0)
                                  && ((*(_QWORD *)(a1 + 22496) & 0x40) == 0
                                   || (inited = gen8_hfi_send_feature_ctrl(a1, 268435457, 1, 0)) == 0)
                                  && (*(_BYTE *)(a1 + 24528) != 1
                                   || (inited = gen8_hfi_send_feature_ctrl(a1, 268435458, 1, 0)) == 0) )
                                {
                                  inited = ((__int64 (__fastcall *)(__int64))send_start_msg_1)(a1);
                                  if ( !inited )
                                  {
                                    if ( (*(_BYTE *)(a1 + 8284) & 1) == 0
                                      || (v48 = 786442, (inited = gen8_hfi_send_generic_req(a1, (__int64)&v48, 4)) == 0) )
                                    {
                                      v15 = *(_DWORD *)(a1 + 24616) | 1;
                                      *(_DWORD *)(a1 + 24616) = v15;
                                      gmu_core_regwrite(a1, 129427, (unsigned int)~v15);
                                      _X8 = (unsigned __int64 *)(v2 + 1040);
                                      __asm { PRFM            #0x11, [X8] }
                                      do
                                        v44 = __ldxr(_X8);
                                      while ( __stxr(v44 | 4, _X8) );
                                      v16 = *(unsigned __int8 *)(a1 + 8284);
                                      v17 = *(_QWORD *)(v2 + 24);
                                      v49 = 0;
                                      if ( v16 != 1 )
                                      {
                                        if ( !v16 )
                                          goto LABEL_67;
LABEL_66:
                                        _X8 = (unsigned __int64 *)(v2 + 1040);
                                        __asm { PRFM            #0x11, [X8] }
                                        do
                                          v47 = __ldxr(_X8);
                                        while ( __stxr(v47 | 0x40, _X8) );
LABEL_67:
                                        inited = gen8_hwsched_setup_default_votes(a1);
                                        if ( !inited )
                                          goto LABEL_9;
                                        goto LABEL_8;
                                      }
                                      v18 = *(_DWORD *)(v17 + 184);
                                      v19 = *(_QWORD *)(v17 + 40);
                                      v51 = v18;
                                      v52 = v19;
                                      v50 = 2;
                                      v48 = 154;
                                      inited = gen8_hfi_send_cmd_async(a1, &v48, 0x14u);
                                      if ( !inited )
                                      {
                                        if ( (*(_BYTE *)(a1 + 8284) & 1) == 0 )
                                          goto LABEL_67;
                                        goto LABEL_66;
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
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_8:
  v5 = to_gen8_gmu(a1);
  *(_DWORD *)(a1 + 24616) &= ~1u;
  gen8_hwsched_process_msgq(a1);
  gen8_hwsched_process_dbgq(a1, 0);
  kgsl_pwrctrl_axi(a1, 0);
  _X8 = (unsigned __int64 *)(v5 + 1040);
  __asm { PRFM            #0x11, [X8] }
  do
    v26 = __ldxr(_X8);
  while ( __stxr(v26 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return inited;
}
