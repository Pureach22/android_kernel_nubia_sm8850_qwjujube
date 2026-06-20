__int64 __fastcall sde_kms_check_frame_trigger_transition(__int64 a1, __int64 a2)
{
  __int64 v3; // x10
  __int64 *v4; // x11
  __int64 v5; // x0
  int v6; // w5
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v9; // x10
  _QWORD *v10; // x20
  __int64 v11; // x11
  _QWORD *v12; // x22
  __int64 v13; // x21
  _QWORD *v14; // x23
  _QWORD *v15; // x24
  int v16; // w4
  _QWORD *v17; // x10
  __int64 v18; // x11
  int v20; // w9
  __int64 v21; // x9
  int v22; // w8
  __int64 v23; // x9
  __int64 v24; // x9
  void (__fastcall *v25)(_QWORD); // x8
  int v26; // w8
  void (__fastcall *v27)(__int64, __int64); // x8
  __int64 v28; // x0
  __int64 v29; // x1
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x3
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6
  int v36; // w7
  _QWORD *i; // x21
  __int64 v38; // x8
  __int64 v39; // x21
  __int64 v40; // x9
  int v41; // w8
  __int64 v42; // x9
  __int64 v43; // x9
  __int64 v44; // x0
  __int64 result; // x0
  __int64 v46[2]; // [xsp+0h] [xbp-10h] BYREF

  v46[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int *)(*(_QWORD *)(a2 + 8) + 860LL);
  if ( (int)v3 < 1 )
  {
    LODWORD(v7) = 0;
    v6 = 0;
  }
  else
  {
    v4 = *(__int64 **)(a2 + 32);
    v5 = 0;
    v6 = 0;
    LODWORD(v7) = 0;
    do
    {
      v8 = *v4;
      if ( *v4 && *(_BYTE *)(v4[3] + 9) == 1 )
      {
        v7 = *(_QWORD *)(v8 + 2008);
        if ( v7 )
          v7 = *(_QWORD *)(v7 + 1760);
        ++v6;
      }
      else
      {
        v8 = v5;
      }
      --v3;
      v4 += 7;
      v5 = v8;
    }
    while ( v3 );
  }
  v9 = *(unsigned int *)(a2 + 40);
  if ( (int)v9 < 1 )
    goto LABEL_26;
  v10 = *(_QWORD **)(a1 + 136);
  v11 = *(_QWORD *)(a2 + 48);
  v12 = nullptr;
  v13 = v10[7];
  do
  {
    if ( *(_QWORD *)v11 && *(_DWORD *)(*(_QWORD *)v11 + 156LL) != 15 )
      v12 = *(_QWORD **)v11;
    --v9;
    v11 += 40;
  }
  while ( v9 );
  if ( !v6 || !v12 )
  {
LABEL_26:
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "No active crtc found: active_crtc_cnt = %d\n", v6);
    goto LABEL_69;
  }
  if ( !(_DWORD)v7 && !*(_DWORD *)(a1 + 6936) )
  {
LABEL_69:
    result = 0;
    goto LABEL_70;
  }
  v14 = (_QWORD *)v10[108];
  v15 = v10 + 108;
  if ( v14 == v10 + 108 )
  {
    v16 = 0;
  }
  else
  {
    v16 = 0;
    v17 = (_QWORD *)v10[108];
    do
    {
      v18 = v17[249];
      v17 = (_QWORD *)*v17;
      v16 += *(unsigned __int8 *)(v18 + 9);
    }
    while ( v17 != v15 );
  }
  if ( v16 <= 1 && v6 < 2 )
  {
    v20 = *(_DWORD *)(a1 + 6936);
    if ( (_DWORD)v7 == 1 && v20 == 1 )
      goto LABEL_69;
    if ( v20 )
    {
      if ( v20 != 1 )
        goto LABEL_69;
      while ( v14 != v15 )
      {
        if ( *(_BYTE *)(v14[249] + 9LL) == 1 )
          sde_crtc_transition_handle_events((__int64)(v14 - 2), 0);
        v14 = (_QWORD *)*v14;
      }
      *(_DWORD *)(a1 + 6936) = 0;
      sde_kms_idle_helper(a1, v10);
      v21 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 56LL);
      if ( v21 )
      {
        v22 = *(_DWORD *)(a1 + 6936);
        *(_DWORD *)(v21 + 5912) = v22;
      }
      else
      {
        printk(&unk_25E374, "sde_kms_set_disp_op");
        v22 = *(_DWORD *)(a1 + 6936);
      }
      *(_DWORD *)(*(_QWORD *)(a1 + 1896) + 28LL) = v22;
      *(_DWORD *)(*(_QWORD *)(a1 + 3528) + 28LL) = v22;
      *(_DWORD *)(*(_QWORD *)(a1 + 3536) + 28LL) = v22;
      v23 = *(_QWORD *)(a1 + 3512);
      if ( v23 )
        *(_DWORD *)(v23 + 28) = v22;
      v24 = *(_QWORD *)(a1 + 3520);
      if ( v24 )
        *(_DWORD *)(v24 + 28) = v22;
      sde_rm_set_disp_op(a1 + 2144, *(_DWORD *)(a1 + 6936));
      v25 = (void (__fastcall *)(_QWORD))v12[409];
LABEL_66:
      v44 = v12[345];
      if ( *((_DWORD *)v25 - 1) != -1066802076 )
        __break(0x8228u);
      v25(v44);
      goto LABEL_69;
    }
    v26 = *(unsigned __int8 *)(a1 + 6928);
    *(_DWORD *)(a1 + 6936) = 1;
    if ( v26 != 1 )
    {
LABEL_59:
      sde_kms_idle_helper(a1, v10);
      v40 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 56LL);
      if ( v40 )
      {
        v41 = *(_DWORD *)(a1 + 6936);
        *(_DWORD *)(v40 + 5912) = v41;
      }
      else
      {
        printk(&unk_25E374, "sde_kms_set_disp_op");
        v41 = *(_DWORD *)(a1 + 6936);
      }
      *(_DWORD *)(*(_QWORD *)(a1 + 1896) + 28LL) = v41;
      *(_DWORD *)(*(_QWORD *)(a1 + 3528) + 28LL) = v41;
      *(_DWORD *)(*(_QWORD *)(a1 + 3536) + 28LL) = v41;
      v42 = *(_QWORD *)(a1 + 3512);
      if ( v42 )
        *(_DWORD *)(v42 + 28) = v41;
      v43 = *(_QWORD *)(a1 + 3520);
      if ( v43 )
        *(_DWORD *)(v43 + 28) = v41;
      sde_rm_set_disp_op(a1 + 2144, *(_DWORD *)(a1 + 6936));
      v25 = (void (__fastcall *)(_QWORD))v12[408];
      goto LABEL_66;
    }
    if ( (unsigned int)sde_kms_setup_hfi(v13, (__int64)v10) )
    {
      printk(&unk_21DC76, "sde_kms_check_frame_trigger_transition");
      result = 4294967274LL;
      goto LABEL_70;
    }
    v27 = (void (__fastcall *)(__int64, __int64))v12[407];
    v28 = v12[345];
    v29 = *(_QWORD *)(v13 + 5920);
    if ( *((_DWORD *)v27 - 1) != 1863972096 )
      __break(0x8228u);
    v27(v28, v29);
    hfi_kms_get_catalog_data(*(_QWORD *)(a1 + 6440), v30, v31, v32, v33, v34, v35, v36);
    for ( i = (_QWORD *)v10[105]; i != v10 + 105; i = (_QWORD *)*i )
      ((void (__fastcall *)(_QWORD *))sde_plane_post_init)(i - 1);
    v38 = *(_QWORD *)(a1 + 136);
    v46[0] = 0;
    v39 = *(_QWORD *)(a1 + 6440);
    if ( (unsigned int)sde_reg_dma_get_last_cmd_buffer(**(unsigned int **)(v38 + 64), v46) )
    {
      printk(&unk_22E6E7, "_sde_kms_send_reg_dma_last_cmd_hfi");
    }
    else
    {
      if ( !(unsigned int)hfi_kms_set_reg_dma_buffer(v39, v46[0]) )
      {
LABEL_58:
        *(_BYTE *)(a1 + 6928) = 0;
        goto LABEL_59;
      }
      printk(&unk_23BF5C, "_sde_kms_send_reg_dma_last_cmd_hfi");
    }
    printk(&unk_2388A8, "sde_kms_check_frame_trigger_transition");
    goto LABEL_58;
  }
  printk(&unk_25B1D9, "sde_kms_check_frame_trigger_transition");
  result = 0xFFFFFFFFLL;
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
