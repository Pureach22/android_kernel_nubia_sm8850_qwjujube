__int64 __fastcall dp_ctrl_host_deinit(__int64 a1)
{
  __int64 (*v1)(void); // x8
  __int64 v2; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  __int64 result; // x0
  __int64 v6; // x0

  if ( a1 )
  {
    v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 176) + 128LL);
    if ( *((_DWORD *)v1 - 1) != 289804815 )
      __break(0x8228u);
    v2 = v1();
    ipc_log_context = get_ipc_log_context(v2);
    StatusReg = _ReadStatusReg(SP_EL0);
    result = ipc_log_string(
               ipc_log_context,
               "[d][%-4d]Host deinitialized successfully\n",
               *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(
               0,
               0,
               0,
               "[msm-dp-debug][%-4d]Host deinitialized successfully\n",
               *(_DWORD *)(StatusReg + 1800));
  }
  else
  {
    v6 = get_ipc_log_context(0);
    ipc_log_string(v6, "[e][%-4d]Invalid input data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_23AC6D, "dp_ctrl_host_deinit");
  }
  return result;
}
