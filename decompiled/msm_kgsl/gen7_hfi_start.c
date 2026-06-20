__int64 __fastcall gen7_hfi_start(__int64 a1)
{
  __int64 v2; // x20
  _DWORD *v3; // x8
  unsigned int v4; // w21
  int v5; // w8
  __int64 v6; // x20
  __int64 v8; // x20
  const char *v9; // x0
  unsigned __int64 v12; // x10
  unsigned __int64 v19; // x9
  __int64 v20; // [xsp+8h] [xbp-98h] BYREF
  int v21; // [xsp+10h] [xbp-90h]
  int v22; // [xsp+14h] [xbp-8Ch]
  __int64 v23; // [xsp+18h] [xbp-88h] BYREF
  __int64 v24; // [xsp+20h] [xbp-80h]
  __int64 v25; // [xsp+28h] [xbp-78h]
  __int64 v26; // [xsp+30h] [xbp-70h]
  __int64 v27; // [xsp+38h] [xbp-68h]
  __int64 v28; // [xsp+40h] [xbp-60h]
  __int64 v29; // [xsp+48h] [xbp-58h]
  __int64 v30; // [xsp+50h] [xbp-50h]
  __int64 v31; // [xsp+58h] [xbp-48h]
  __int64 v32; // [xsp+60h] [xbp-40h]
  __int64 v33; // [xsp+68h] [xbp-38h]
  __int64 v34; // [xsp+70h] [xbp-30h]
  __int64 v35; // [xsp+78h] [xbp-28h]
  __int64 v36; // [xsp+80h] [xbp-20h]
  __int64 v37; // [xsp+88h] [xbp-18h]
  __int64 v38; // [xsp+90h] [xbp-10h]
  __int64 v39; // [xsp+98h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = to_gen7_gmu(a1);
  v3 = *(_DWORD **)(*(_QWORD *)(to_gen7_gmu(a1) + 48) + 8LL);
  if ( v3[6] )
    v3[16] = v3[17];
  if ( v3[18] )
    v3[28] = v3[29];
  if ( v3[30] )
    v3[40] = v3[41];
  v4 = ((__int64 (__fastcall *)(__int64))gen7_hfi_send_gpu_perf_table)(a1);
  if ( v4 )
    goto LABEL_21;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v4 = gen7_hfi_send_cmd_wait_inline(a1, (int *)(v2 + 56), 0x280u, (int *)&v23);
  if ( v4 )
    goto LABEL_21;
  if ( HIDWORD(v24) )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "HFI ACK failure: Req=0x%8.8X, Result=0x%8.8X\n", v24, HIDWORD(v24));
    gmu_core_fault_snapshot(a1, 6);
    v4 = -22;
    goto LABEL_21;
  }
  v4 = gen7_hfi_send_acd_feature_ctrl(a1);
  if ( v4 )
    goto LABEL_21;
  if ( *(_BYTE *)(a1 + 20437) == 1 )
  {
    v5 = *(_DWORD *)(a1 + 23992);
    v37 = 0;
    v38 = 0;
    v21 = 1;
    v22 = v5;
    v35 = 0;
    v36 = 0;
    v33 = 0;
    v34 = 0;
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    v27 = 0;
    v28 = 0;
    v25 = 0;
    v26 = 0;
    v23 = 0;
    v24 = 0;
    v20 = 0xB0000000BLL;
    v4 = gen7_hfi_send_generic_req_v5(a1, (int *)&v20, (int *)&v23, 0x10u);
    if ( (v4 & 0x80000000) != 0 )
    {
      v8 = *(_QWORD *)(a1 + 1544);
      v9 = hfi_feature_to_string(11);
      dev_err(v8 + 16, "Unable to %s feature %s (%d)\n", "enable", v9, 11);
    }
    else if ( !v4 )
    {
      goto LABEL_14;
    }
LABEL_21:
    v6 = to_gen7_gmu(a1);
    kgsl_pwrctrl_axi(a1, 0);
    _X8 = (unsigned __int64 *)(v6 + 1096);
    __asm { PRFM            #0x11, [X8] }
    do
      v12 = __ldxr(_X8);
    while ( __stxr(v12 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    goto LABEL_22;
  }
LABEL_14:
  v4 = gen7_hfi_send_clx_feature_ctrl(a1);
  if ( v4 )
    goto LABEL_21;
  v4 = gen7_hfi_send_ifpc_feature_ctrl(a1);
  if ( v4 )
    goto LABEL_21;
  v4 = gen7_hfi_send_core_fw_start(a1);
  if ( v4 )
    goto LABEL_21;
  _X8 = (unsigned __int64 *)(v2 + 1096);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 | 4, _X8) );
  v4 = kgsl_pwrctrl_setup_default_votes(a1);
  if ( v4 )
    goto LABEL_21;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v4;
}
