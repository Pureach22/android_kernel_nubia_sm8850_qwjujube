__int64 __fastcall dp_mst_set_state(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x19
  __int64 v9; // x0
  unsigned __int64 v10; // x19
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  char v15; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a1 + 40);
  if ( v8 )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_set_state", 2208, 8, 4369, a2, -1059143953, a8, v15);
    *(_DWORD *)(v8 + 4232) = a2;
    ipc_log_context = get_ipc_log_context();
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[i][%-4d]mst power state:%d\n", *(_DWORD *)(StatusReg + 1800), a2);
    if ( (_drm_debug & 4) != 0 )
      return printk(&unk_226E0B, *(unsigned int *)(StatusReg + 1800));
    else
      return printk(&unk_23471C, "dp_mst_set_state");
  }
  else
  {
    v9 = get_ipc_log_context();
    v10 = _ReadStatusReg(SP_EL0);
    result = ipc_log_string(v9, "[d][%-4d]mst not initialized\n", *(_DWORD *)(v10 + 1800));
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mst not initialized\n", *(_DWORD *)(v10 + 1800));
  }
  return result;
}
