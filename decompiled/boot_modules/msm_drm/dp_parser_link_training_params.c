__int64 __fastcall dp_parser_link_training_params(__int64 *a1)
{
  __int64 v1; // x21
  __int64 *v2; // x19
  __int64 v4; // x0
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x19
  __int64 result; // x0
  int v8; // w21
  __int64 ipc_log_context; // x0
  int v10; // w2

  v1 = *a1;
  v2 = a1 + 100;
  v4 = parse_lt_param(*a1 + 16, a1 + 100, "qcom,hbr2-3-voltage-swing");
  if ( (_DWORD)v4
    || (v4 = parse_lt_param(v1 + 16, a1 + 101, "qcom,hbr2-3-pre-emphasis"), (_DWORD)v4)
    || (v4 = parse_lt_param(v1 + 16, a1 + 102, "qcom,hbr-rbr-voltage-swing"), (_DWORD)v4)
    || (v4 = parse_lt_param(v1 + 16, a1 + 103, "qcom,hbr-rbr-pre-emphasis"), (_DWORD)v4) )
  {
    v8 = v4;
    ipc_log_context = get_ipc_log_context(v4);
    v10 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
    if ( v8 == -22 )
    {
      ipc_log_string(ipc_log_context, "[w][%-4d]link training parameters not found - using default values\n", v10);
      printk(&unk_218298, "dp_parser_link_training_params");
    }
    else
    {
      ipc_log_string(ipc_log_context, "[e][%-4d]link training parameters parsing failure ret: %d\n", v10, v8);
      printk(&unk_26790B, "dp_parser_link_training_params");
    }
    devm_kfree(*a1 + 16);
    devm_kfree(*a1 + 16);
    devm_kfree(*a1 + 16);
    result = devm_kfree(*a1 + 16);
    *((_BYTE *)v2 + 32) = 0;
    v2[2] = 0;
    v2[3] = 0;
    *v2 = 0;
    v2[1] = 0;
  }
  else
  {
    *((_BYTE *)a1 + 832) = 1;
    v5 = get_ipc_log_context(v4);
    StatusReg = _ReadStatusReg(SP_EL0);
    result = ipc_log_string(v5, "[d][%-4d]link training parameters parsing success\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(
               0,
               0,
               0,
               "[msm-dp-debug][%-4d]link training parameters parsing success\n",
               *(_DWORD *)(StatusReg + 1800));
  }
  return result;
}
