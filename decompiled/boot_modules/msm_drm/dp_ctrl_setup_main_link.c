__int64 __fastcall dp_ctrl_setup_main_link(__int64 a1)
{
  void (*v2)(void); // x8
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x0
  int v7; // w0
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x0
  unsigned int v11; // w20
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 (*v14)(void); // x8
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned __int64 v17; // x22
  __int64 v18; // x8
  __int64 result; // x0
  void (*v20)(void); // x8
  __int64 v21; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x22
  int v24; // w2
  void *v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  int v28; // w2
  __int64 v29; // [xsp+8h] [xbp-28h] BYREF
  __int64 v30; // [xsp+10h] [xbp-20h]
  __int64 v31; // [xsp+18h] [xbp-18h]
  _BYTE v32[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+28h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (**(_BYTE **)(a1 + 152) & 8) != 0 )
  {
    result = 0;
    goto LABEL_16;
  }
  v2 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 104LL);
  if ( *((_DWORD *)v2 - 1) != -91942776 )
    __break(0x8228u);
  v2();
  if ( *(_BYTE *)(a1 + 259) == 1 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 24LL);
    LOBYTE(v29) = 1;
    drm_dp_dpcd_write(v3, 288, &v29, 1);
  }
  v4 = *(_QWORD *)(a1 + 152);
  v29 = 0;
  v30 = 0;
  *(_BYTE *)(v4 + 125) = 0;
  *(_BYTE *)(*(_QWORD *)(a1 + 152) + 124LL) = 0;
  v5 = *(_QWORD *)(a1 + 152);
  v6 = *(unsigned int *)(v5 + 132);
  LODWORD(v30) = *(_DWORD *)(v5 + 128);
  v7 = drm_dp_bw_code_to_link_rate(v6);
  v9 = *(_QWORD *)(a1 + 136);
  v8 = *(_QWORD *)(a1 + 144);
  HIDWORD(v29) = v7;
  v10 = *(_QWORD *)(v9 + 24);
  v31 = *(_QWORD *)(v8 + 88);
  v11 = dp_link_configure(v10, (__int64)&v29);
  if ( !v11 )
  {
    v12 = *(_QWORD *)(a1 + 136);
    v32[0] = 0;
    if ( (int)drm_dp_dpcd_write(*(_QWORD *)(v12 + 24), 263, v32, 1) >= 1
      && (v13 = *(_QWORD *)(a1 + 136), v32[0] = 1, (int)drm_dp_dpcd_write(*(_QWORD *)(v13 + 24), 264, v32, 1) >= 1) )
    {
      v20 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 240LL);
      if ( *((_DWORD *)v20 - 1) != 289804815 )
        __break(0x8228u);
      v20();
      v21 = dp_ctrl_link_training_1(a1);
      v11 = v21;
      ipc_log_context = get_ipc_log_context(v21);
      StatusReg = _ReadStatusReg(SP_EL0);
      v24 = *(_DWORD *)(StatusReg + 1800);
      if ( v11 )
      {
        ipc_log_string(ipc_log_context, "[e][%-4d]link training #1 failed\n", v24);
        v25 = &unk_267CD3;
      }
      else
      {
        ipc_log_string(ipc_log_context, "[i][%-4d]link training #1 successful\n", v24);
        if ( (_drm_debug & 4) != 0 )
          printk(&unk_21C3CD, *(unsigned int *)(StatusReg + 1800));
        else
          printk(&unk_2793F8, "dp_ctrl_link_train");
        v26 = dp_ctrl_link_training_2(a1);
        v11 = v26;
        v27 = get_ipc_log_context(v26);
        v28 = *(_DWORD *)(StatusReg + 1800);
        if ( !v11 )
        {
          ipc_log_string(v27, "[i][%-4d]link training #2 successful\n", v28);
          if ( (_drm_debug & 4) != 0 )
            printk(&unk_272778, *(unsigned int *)(StatusReg + 1800));
          else
            printk(&unk_245183, "dp_ctrl_link_train");
          v11 = 0;
          goto LABEL_10;
        }
        ipc_log_string(v27, "[e][%-4d]link training #2 failed\n", v28);
        v25 = &unk_279432;
      }
      printk(v25, "dp_ctrl_link_train");
    }
    else
    {
      v11 = -22;
    }
  }
LABEL_10:
  v14 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 176) + 56LL);
  if ( *((_DWORD *)v14 - 1) != -1041116529 )
    __break(0x8228u);
  v15 = v14();
  __dsb(0xEu);
  v16 = get_ipc_log_context(v15);
  v17 = _ReadStatusReg(SP_EL0);
  ipc_log_string(v16, "[d][%-4d]sink: pattern=%x\n", *(_DWORD *)(v17 + 1800), 0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]sink: pattern=%x\n", *(_DWORD *)(v17 + 1800), 0);
  v18 = *(_QWORD *)(a1 + 136);
  v32[0] = 0;
  drm_dp_dpcd_write(*(_QWORD *)(v18 + 24), 258, v32, 1);
  drm_dp_link_train_channel_eq_delay(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 24LL), *(_QWORD *)(a1 + 144));
  result = v11;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
