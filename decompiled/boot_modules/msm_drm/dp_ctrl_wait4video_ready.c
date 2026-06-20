__int64 __fastcall dp_ctrl_wait4video_ready(__int64 a1)
{
  __int64 v1; // x19
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  int v4; // w2
  __int64 result; // x0

  v1 = wait_for_completion_timeout(a1 + 224, 125);
  ipc_log_context = get_ipc_log_context(v1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = *(_DWORD *)(StatusReg + 1800);
  if ( v1 )
  {
    result = ipc_log_string(ipc_log_context, "[d][%-4d]SEND_VIDEO triggered\n", v4);
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]SEND_VIDEO triggered\n", *(_DWORD *)(StatusReg + 1800));
  }
  else
  {
    ipc_log_string(ipc_log_context, "[w][%-4d]SEND_VIDEO time out\n", v4);
    return printk(&unk_211418, "dp_ctrl_wait4video_ready");
  }
  return result;
}
