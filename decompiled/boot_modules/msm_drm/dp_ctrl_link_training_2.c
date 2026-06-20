__int64 __fastcall dp_ctrl_link_training_2(__int64 a1)
{
  _DWORD *v2; // x8
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  __int64 result; // x0
  int v6; // w8
  __int64 v7; // x0
  _DWORD *v8; // x8
  unsigned int v9; // w20
  char v10; // w27
  int v11; // w25
  unsigned __int64 v12; // x26
  __int64 v13; // x0
  __int64 v14; // x1
  void (__fastcall *v15)(__int64, __int64); // x9
  __int64 v16; // x0
  _DWORD *v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  void (__fastcall *v21)(__int64, int *); // x8
  unsigned int v22; // w24
  __int64 v23; // x0
  __int64 v24; // x8
  int v25; // w9
  int v26; // w9
  unsigned int v27; // w20
  __int64 v28; // x0
  __int64 v29; // x8
  unsigned __int64 v30; // x21
  int v31; // [xsp+0h] [xbp-10h] BYREF
  __int16 v32; // [xsp+4h] [xbp-Ch]
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD **)(a1 + 136);
  v32 = 0;
  v31 = 0;
  *v2 &= ~0x40u;
  **(_DWORD **)(a1 + 136) &= ~0x20u;
  **(_DWORD **)(a1 + 136) |= 0x10u;
  if ( *(_BYTE *)(a1 + 261) == 1 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      ipc_log_context,
      "[d][%-4d]simulation enabled, skip channel equalization\n",
      *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]simulation enabled, skip channel equalization\n",
        *(_DWORD *)(StatusReg + 1800));
LABEL_4:
    result = 0;
    v6 = 32;
    goto LABEL_10;
  }
  v7 = *(_QWORD *)(a1 + 176);
  v8 = *(_DWORD **)(v7 + 56);
  if ( *(v8 - 1) != -1041116529 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v8)(v7, 0);
  __dsb(0xEu);
  v9 = *(unsigned __int8 *)(a1 + 280);
  if ( !*(_DWORD *)(a1 + 264) )
  {
    v10 = 0;
    v11 = 6;
    v12 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v13 = *(_QWORD *)(a1 + 176);
      v14 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 124LL);
      v15 = *(void (__fastcall **)(__int64, __int64))(v13 + 152);
      if ( *((_DWORD *)v15 - 1) != -922222210 )
        __break(0x8229u);
      v15(v13, v14);
      if ( !v10 )
      {
        v16 = *(_QWORD *)(a1 + 176);
        v17 = *(_DWORD **)(v16 + 96);
        if ( *(v17 - 1) != -1041116529 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v17)(v16, v9);
        result = dp_ctrl_update_sink_pattern(a1, v9);
        v10 = v9;
        if ( (_DWORD)result )
          goto LABEL_9;
      }
      result = dp_ctrl_update_sink_vx_px(a1);
      if ( (_DWORD)result )
        goto LABEL_9;
      drm_dp_link_train_channel_eq_delay(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 24LL), *(_QWORD *)(a1 + 144));
      v18 = drm_dp_dpcd_read_link_status(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 24LL), &v31);
      if ( (_DWORD)v18 != 6 )
      {
        v22 = v18;
        v23 = get_ipc_log_context(v18);
        ipc_log_string(v23, "[e][%-4d]DP link status read failed, err: %d\n", *(_DWORD *)(v12 + 1800), v22);
        printk(&unk_23E603, "dp_ctrl_read_link_status");
        if ( v22 )
        {
          result = v22;
          goto LABEL_9;
        }
      }
      if ( (drm_dp_clock_recovery_ok(&v31, *(unsigned int *)(*(_QWORD *)(a1 + 152) + 128LL)) & 1) == 0 )
        goto LABEL_8;
      v19 = drm_dp_channel_eq_ok(&v31, *(unsigned int *)(*(_QWORD *)(a1 + 152) + 128LL));
      if ( (v19 & 1) != 0 )
        goto LABEL_4;
      if ( !--v11 )
        break;
      v20 = *(_QWORD *)(a1 + 152);
      v21 = *(void (__fastcall **)(__int64, int *))(v20 + 168);
      if ( *((_DWORD *)v21 - 1) != -1192390094 )
        __break(0x8228u);
      v21(v20, &v31);
      if ( *(_DWORD *)(a1 + 264) )
        goto LABEL_8;
    }
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 144) + 72LL) != 20 )
      goto LABEL_8;
    v24 = *(_QWORD *)(a1 + 152);
    v25 = *(unsigned __int8 *)(v24 + 128);
    if ( v25 == 2 )
    {
      v26 = 1;
    }
    else
    {
      if ( v25 != 4 )
      {
        if ( *(unsigned __int8 *)(a1 + 268) == v25 )
          v27 = -11;
        else
          v27 = -22;
        goto LABEL_38;
      }
      v26 = 2;
    }
    *(_DWORD *)(v24 + 128) = v26;
    v27 = -11;
LABEL_38:
    v28 = get_ipc_log_context(v19);
    v29 = *(_QWORD *)(a1 + 152);
    v30 = _ReadStatusReg(SP_EL0);
    ipc_log_string(v28, "[d][%-4d]new lane count=%d\n", *(_DWORD *)(v30 + 1800), *(_DWORD *)(v29 + 128));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]new lane count=%d\n",
        *(_DWORD *)(v30 + 1800),
        *(_DWORD *)(*(_QWORD *)(a1 + 152) + 128LL));
    v6 = 64;
    result = v27;
    goto LABEL_10;
  }
LABEL_8:
  result = 4294967274LL;
LABEL_9:
  v6 = 64;
LABEL_10:
  **(_DWORD **)(a1 + 136) &= ~0x10u;
  **(_DWORD **)(a1 + 136) |= v6;
  _ReadStatusReg(SP_EL0);
  return result;
}
