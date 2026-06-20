__int64 __fastcall dp_audio_on(__int64 a1)
{
  __int64 *v1; // x19
  __int64 v3; // x9
  __int64 v4; // x10
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 device_by_node; // x0
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x0
  unsigned __int64 v11; // x19
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v14; // x0
  void *v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  _QWORD v19[11]; // [xsp+8h] [xbp-58h] BYREF

  v19[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    StatusReg = _ReadStatusReg(SP_EL0);
LABEL_15:
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(StatusReg + 1800));
    printk(&unk_275B6D, "dp_audio_on");
    result = 4294967274LL;
    goto LABEL_16;
  }
  v1 = (__int64 *)(a1 - 352);
  if ( (unsigned __int64)(a1 - 352) >= 0xFFFFFFFFFFFFF001LL )
  {
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    goto LABEL_15;
  }
  v3 = *(_QWORD *)(a1 - 216);
  *(_QWORD *)(a1 - 328) = 44;
  LODWORD(v3) = *(_DWORD *)(v3 + 912);
  *(_QWORD *)(a1 - 224) = a1;
  *(_QWORD *)(a1 - 288) = dp_audio_info_setup;
  *(_DWORD *)(a1 - 320) = v3;
  v4 = *(_QWORD *)(a1 - 344);
  *(_QWORD *)(a1 - 280) = dp_audio_get_edid_blk;
  *(_QWORD *)(a1 - 272) = dp_audio_get_cable_status;
  *(_QWORD *)(a1 - 264) = dp_audio_get_intf_id;
  *(_QWORD *)(a1 - 256) = dp_audio_teardown_done;
  *(_QWORD *)(a1 - 248) = dp_audio_ack_done;
  *(_QWORD *)(a1 - 240) = dp_audio_codec_ready;
  *(_QWORD *)(a1 - 232) = v4;
  v5 = *(_QWORD *)(v4 + 760);
  if ( !v5 )
  {
    v14 = get_ipc_log_context(0);
    ipc_log_string(v14, "[e][%-4d]cannot find audio dev.of_node\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v15 = &unk_211486;
LABEL_20:
    printk(v15, "dp_audio_register_ext_disp");
    goto LABEL_8;
  }
  memset(v19, 0, 80);
  v6 = _of_parse_phandle_with_args(v5, "qcom,ext-disp", 0, 0, 0, v19);
  if ( (_DWORD)v6 || (v6 = v19[0]) == 0 )
  {
    v16 = get_ipc_log_context(v6);
    ipc_log_string(
      v16,
      "[e][%-4d]cannot parse %s handle\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      "qcom,ext-disp");
    v15 = &unk_230CA7;
    goto LABEL_20;
  }
  device_by_node = of_find_device_by_node();
  *v1 = device_by_node;
  if ( !device_by_node )
  {
    v17 = get_ipc_log_context(0);
    ipc_log_string(v17, "[e][%-4d]cannot find %s pdev\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), "qcom,ext-disp");
    v15 = &unk_2613F9;
    goto LABEL_20;
  }
  v8 = msm_ext_disp_register_intf(device_by_node, a1 - 328);
  if ( (_DWORD)v8 )
  {
    v18 = get_ipc_log_context(v8);
    ipc_log_string(v18, "[e][%-4d]failed to register disp\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v15 = &unk_26142A;
    goto LABEL_20;
  }
LABEL_8:
  *(_DWORD *)(a1 - 204) = 1;
  result = dp_audio_config(v1, 1);
  if ( !(_DWORD)result )
  {
    result = dp_audio_notify(v1, 1);
    if ( !(_DWORD)result )
    {
      v10 = get_ipc_log_context(result);
      v11 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v10, "[d][%-4d]success\n", *(_DWORD *)(v11 + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]success\n", *(_DWORD *)(v11 + 1800));
      result = 0;
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
