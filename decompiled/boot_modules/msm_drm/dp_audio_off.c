__int64 __fastcall dp_audio_off(__int64 a1, char a2)
{
  __int64 v4; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x23
  unsigned int v7; // w19
  __int64 v8; // x0
  unsigned __int64 v9; // x19
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 device_by_node; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  void *v16; // x0
  __int64 v17; // x0
  unsigned __int64 v18; // x19
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  _QWORD v24[11]; // [xsp+8h] [xbp-58h] BYREF

  v24[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 - 204) )
    {
      v4 = cancel_delayed_work_sync(a1 - 152);
      if ( (v4 & 1) != 0 )
      {
        ipc_log_context = get_ipc_log_context(v4);
        StatusReg = _ReadStatusReg(SP_EL0);
        v4 = ipc_log_string(
               ipc_log_context,
               "[d][%-4d]pending notification work completed\n",
               *(_DWORD *)(StatusReg + 1800));
        if ( (_drm_debug & 4) != 0 )
          v4 = _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "[msm-dp-debug][%-4d]pending notification work completed\n",
                 *(_DWORD *)(StatusReg + 1800));
      }
      if ( (a2 & 1) != 0 || (v4 = dp_audio_notify(a1 - 352, 0), (v7 = v4) == 0) )
      {
        v8 = get_ipc_log_context(v4);
        v9 = _ReadStatusReg(SP_EL0);
        ipc_log_string(v8, "[d][%-4d]success\n", *(_DWORD *)(v9 + 1800));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]success\n", *(_DWORD *)(v9 + 1800));
        v7 = 0;
      }
      dp_audio_config(a1 - 352, 0);
      *(_DWORD *)(a1 - 204) = 0;
      v10 = *(_QWORD *)(a1 - 344);
      *(_BYTE *)(a1 - 200) = 0;
      v11 = *(_QWORD *)(v10 + 760);
      if ( !v11 )
      {
        v20 = get_ipc_log_context(0);
        ipc_log_string(v20, "[e][%-4d]cannot find audio dev.of_node\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        v16 = &unk_211486;
        goto LABEL_24;
      }
      memset(v24, 0, 80);
      v12 = _of_parse_phandle_with_args(v11, "qcom,ext-disp", 0, 0, 0, v24);
      if ( (_DWORD)v12 || (v12 = v24[0]) == 0 )
      {
        v21 = get_ipc_log_context(v12);
        ipc_log_string(
          v21,
          "[e][%-4d]cannot parse %s handle\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          "qcom,ext-disp");
        v16 = &unk_230CA7;
        goto LABEL_24;
      }
      device_by_node = of_find_device_by_node();
      *(_QWORD *)(a1 - 352) = device_by_node;
      if ( !device_by_node )
      {
        v22 = get_ipc_log_context(0);
        ipc_log_string(
          v22,
          "[e][%-4d]cannot find %s pdev\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          "qcom,ext-disp");
        v16 = &unk_2613F9;
        goto LABEL_24;
      }
      v14 = msm_ext_disp_deregister_intf(device_by_node, a1 - 328);
      if ( (_DWORD)v14 )
      {
        v15 = get_ipc_log_context(v14);
        ipc_log_string(v15, "[e][%-4d]failed to deregister disp\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        v16 = &unk_229D9F;
LABEL_24:
        printk(v16, "dp_audio_deregister_ext_disp");
      }
    }
    else
    {
      v17 = get_ipc_log_context(a1);
      v18 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v17, "[d][%-4d]audio already off\n", *(_DWORD *)(v18 + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]audio already off\n", *(_DWORD *)(v18 + 1800));
      v7 = 0;
    }
  }
  else
  {
    v19 = get_ipc_log_context(0);
    ipc_log_string(v19, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_audio_off");
    v7 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
