__int64 __fastcall a6xx_hwsched_hfi_start(__int64 a1)
{
  __int64 v2; // x20
  _DWORD *v3; // x8
  unsigned int v4; // w21
  __int64 v5; // x20
  int v7; // w3
  int v8; // w8
  unsigned __int64 v15; // x10
  unsigned __int64 v18; // x9

  v2 = to_a6xx_gmu(a1);
  v3 = *(_DWORD **)(*(_QWORD *)(to_a6xx_gmu(a1) + 40) + 8LL);
  if ( v3[6] )
    v3[16] = v3[17];
  if ( v3[18] )
    v3[28] = v3[29];
  if ( v3[30] )
    v3[40] = v3[41];
  if ( v3[42] )
    v3[52] = v3[53];
  if ( v3[54] )
    v3[64] = v3[65];
  if ( v3[66] )
    v3[76] = v3[77];
  if ( v3[78] )
    v3[88] = v3[89];
  if ( v3[90] )
    v3[100] = v3[101];
  if ( v3[102] )
    v3[112] = v3[113];
  if ( v3[114] )
    v3[124] = v3[125];
  if ( v3[126] )
    v3[136] = v3[137];
  if ( v3[138] )
    v3[148] = v3[149];
  if ( v3[150] )
    v3[160] = v3[161];
  if ( v3[162] )
    v3[172] = v3[173];
  if ( v3[174] )
    v3[184] = v3[185];
  if ( v3[186] )
    v3[196] = v3[197];
  if ( v3[198] )
    v3[208] = v3[209];
  v4 = a6xx_gmu_hfi_start(a1);
  if ( v4 )
    goto LABEL_43;
  v4 = a6xx_hfi_send_generic_req(a1, v2 + 964, 236);
  if ( v4 )
    goto LABEL_43;
  v4 = a6xx_hfi_send_generic_req(a1, v2 + 48, 640);
  if ( v4 )
    goto LABEL_43;
  v4 = a6xx_hfi_send_acd_feature_ctrl(a1);
  if ( v4 )
    goto LABEL_43;
  v4 = a6xx_hfi_send_lm_feature_ctrl(a1);
  if ( v4 )
    goto LABEL_43;
  v4 = a6xx_hfi_send_bcl_feature_ctrl(a1);
  if ( v4 )
    goto LABEL_43;
  v4 = a6xx_hfi_send_feature_ctrl(a1, 1, 1, 0);
  if ( v4 )
    goto LABEL_43;
  v4 = a6xx_hfi_send_feature_ctrl(a1, 16, 1, 0);
  if ( v4 )
    goto LABEL_43;
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x80) != 0 )
  {
    v4 = a6xx_hfi_send_feature_ctrl(a1, 23, 1, 0);
    if ( v4 )
      goto LABEL_43;
  }
  if ( *(_BYTE *)(a1 + 23968) == 1 )
  {
    v4 = a6xx_hfi_send_feature_ctrl(a1, 26, 0, 0);
    if ( v4 )
      goto LABEL_43;
  }
  if ( *(_BYTE *)(a1 + 19672) == 1 && (*(_QWORD *)(a1 + 14240) & 0x1000) == 0 )
  {
    v4 = a6xx_hfi_send_feature_ctrl(a1, 17, 1, 0);
    if ( v4 )
      goto LABEL_43;
  }
  enable_gmu_stats(a1);
  if ( *(_BYTE *)(v2 + 1312) == 1 )
    a6xx_hfi_send_set_value(a1, 119, 0, 1);
  v7 = *(_DWORD *)(v2 + 1316);
  if ( v7 )
    a6xx_hfi_send_set_value(a1, 111, 0, v7);
  v4 = a6xx_hfi_send_core_fw_start(a1);
  if ( v4 )
    goto LABEL_43;
  v4 = enable_preemption(a1);
  if ( v4 )
    goto LABEL_43;
  v4 = ((__int64 (__fastcall *)(__int64))send_start_msg)(a1);
  if ( v4 )
    goto LABEL_43;
  v8 = *(_DWORD *)(a1 + 24544) | 1;
  *(_DWORD *)(a1 + 24544) = v8;
  gmu_core_regwrite(a1, 129427, (unsigned int)~v8);
  _X8 = (unsigned __int64 *)(v2 + 1296);
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr(_X8);
  while ( __stxr(v18 | 4, _X8) );
  v4 = kgsl_pwrctrl_setup_default_votes(a1);
  if ( v4 )
  {
LABEL_43:
    v5 = to_a6xx_gmu(a1);
    *(_DWORD *)(a1 + 24544) &= ~1u;
    a6xx_hwsched_process_msgq(a1);
    a6xx_hwsched_process_dbgq(a1, 0);
    kgsl_pwrctrl_axi(a1, 0);
    _X8 = (unsigned __int64 *)(v5 + 1296);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  }
  return v4;
}
