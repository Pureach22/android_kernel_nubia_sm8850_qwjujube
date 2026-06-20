__int64 __fastcall dp_ctrl_link_training_1(__int64 a1)
{
  _DWORD *v2; // x8
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  __int64 result; // x0
  int v6; // w8
  void (*v7)(void); // x8
  int v8; // w24
  __int64 v9; // x8
  unsigned int v10; // w9
  char v11; // w11
  unsigned int v12; // w10
  unsigned __int64 v13; // x13
  int v14; // w13
  int v15; // w28
  char v16; // w27
  unsigned __int64 v17; // x25
  void (*v18)(void); // x8
  void (*v19)(void); // x9
  __int64 (*v20)(void); // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x9
  int v27; // w8
  __int64 v28; // x0
  unsigned int v29; // w27
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned int v32; // w21
  void *v33; // x0
  char v34[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v35; // [xsp+10h] [xbp-10h] BYREF
  __int16 v36; // [xsp+14h] [xbp-Ch]
  __int64 v37; // [xsp+18h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD **)(a1 + 136);
  v36 = 0;
  v35 = 0;
  *v2 &= ~8u;
  **(_DWORD **)(a1 + 136) &= ~4u;
  **(_DWORD **)(a1 + 136) |= 2u;
  if ( *(_BYTE *)(a1 + 261) == 1 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[d][%-4d]simulation enabled, skip clock recovery\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]simulation enabled, skip clock recovery\n",
        *(_DWORD *)(StatusReg + 1800));
LABEL_4:
    result = 0;
    v6 = 4;
  }
  else
  {
    v7 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 56LL);
    if ( *((_DWORD *)v7 - 1) != -1041116529 )
      __break(0x8228u);
    v7();
    __dsb(0xEu);
    v8 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 152) + 124LL);
    if ( !*(_DWORD *)(a1 + 264) )
    {
      v15 = 0;
      v16 = 1;
      v17 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v19 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 152LL);
        if ( *((_DWORD *)v19 - 1) != -922222210 )
          __break(0x8229u);
        v19();
        if ( (v16 & 1) != 0 )
        {
          v20 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 176) + 96LL);
          if ( *((_DWORD *)v20 - 1) != -1041116529 )
            __break(0x8228u);
          v21 = v20();
          v22 = get_ipc_log_context(v21);
          ipc_log_string(v22, "[d][%-4d]sink: pattern=%x\n", *(_DWORD *)(v17 + 1800), 1);
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]sink: pattern=%x\n", *(_DWORD *)(v17 + 1800), 1);
          v23 = *(_QWORD *)(a1 + 136);
          v34[0] = 33;
          if ( (int)drm_dp_dpcd_write(*(_QWORD *)(v23 + 24), 258, v34, 1) < 1 )
            goto LABEL_8;
        }
        result = dp_ctrl_update_sink_vx_px(a1);
        if ( (_DWORD)result )
          goto LABEL_9;
        drm_dp_link_train_clock_recovery_delay(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 24LL), *(_QWORD *)(a1 + 144));
        v24 = drm_dp_dpcd_read_link_status(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 24LL), &v35);
        if ( (_DWORD)v24 != 6 )
        {
          v29 = v24;
          v30 = get_ipc_log_context(v24);
          ipc_log_string(v30, "[e][%-4d]DP link status read failed, err: %d\n", *(_DWORD *)(v17 + 1800), v29);
          printk(&unk_23E603, "dp_ctrl_read_link_status");
          result = v29;
          if ( v29 )
            goto LABEL_9;
        }
        v25 = drm_dp_clock_recovery_ok(&v35, *(unsigned int *)(*(_QWORD *)(a1 + 152) + 128LL));
        if ( (v25 & 1) != 0 )
          goto LABEL_4;
        v26 = *(_QWORD *)(a1 + 152);
        v27 = *(unsigned __int8 *)(v26 + 124);
        if ( v27 == *(unsigned __int8 *)(v26 + 126) )
          break;
        if ( v8 == v27 )
        {
          if ( ++v15 >= 5 )
          {
            v31 = get_ipc_log_context(v25);
            ipc_log_string(v31, "[e][%-4d]max tries reached\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
            v32 = -110;
            v33 = &unk_2375BC;
LABEL_48:
            printk(v33, "dp_ctrl_link_training_1");
            result = v32;
            goto LABEL_9;
          }
        }
        else
        {
          v15 = 0;
          v8 = *(unsigned __int8 *)(v26 + 124);
        }
        v28 = get_ipc_log_context(v25);
        ipc_log_string(v28, "[d][%-4d]clock recovery not done, adjusting vx px\n", *(_DWORD *)(v17 + 1800));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]clock recovery not done, adjusting vx px\n",
            *(_DWORD *)(v17 + 1800));
        v18 = *(void (**)(void))(*(_QWORD *)(a1 + 152) + 168LL);
        if ( *((_DWORD *)v18 - 1) != -1192390094 )
          __break(0x8228u);
        v18();
        v16 = 0;
        if ( *(_DWORD *)(a1 + 264) )
          goto LABEL_8;
      }
      if ( !(unsigned int)__ratelimit(&dp_ctrl_link_training_1__rs, "dp_ctrl_link_training_1") )
        goto LABEL_8;
      _ReadStatusReg(SP_EL0);
      v32 = -22;
      v33 = &unk_27602D;
      goto LABEL_48;
    }
LABEL_8:
    result = 4294967274LL;
LABEL_9:
    v9 = *(_QWORD *)(a1 + 152);
    if ( *(_DWORD *)(v9 + 132) == 6 )
    {
      v10 = *(_DWORD *)(v9 + 128);
      if ( v10 )
      {
        v11 = 0;
        v12 = 0;
        while ( 1 )
        {
          if ( v12 > 0xD || (v13 = (unsigned __int64)v12 >> 1, (_DWORD)v13 == 6) )
            __break(1u);
          if ( ((*((unsigned __int8 *)&v35 + v13) >> (v11 & 4)) & 1) == 0 )
            break;
          ++v12;
          v11 += 4;
          v14 = (unsigned __int8)v12;
          if ( v10 <= (unsigned __int8)v12 )
          {
            if ( !(_BYTE)v12 )
              goto LABEL_18;
            goto LABEL_17;
          }
        }
        v14 = (unsigned __int8)v12;
        if ( (_BYTE)v12 )
        {
LABEL_17:
          *(_DWORD *)(v9 + 128) = v14;
          result = 4294967285LL;
          *(_DWORD *)(*(_QWORD *)(a1 + 152) + 132LL) = *(unsigned __int8 *)(a1 + 269);
        }
      }
    }
LABEL_18:
    v6 = 8;
  }
  **(_DWORD **)(a1 + 136) &= ~2u;
  **(_DWORD **)(a1 + 136) |= v6;
  _ReadStatusReg(SP_EL0);
  return result;
}
