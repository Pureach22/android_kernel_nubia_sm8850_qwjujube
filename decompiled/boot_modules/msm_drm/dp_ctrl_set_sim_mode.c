__int64 __fastcall dp_ctrl_set_sim_mode(__int64 result, char a2)
{
  __int64 v2; // x19
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20

  if ( result )
  {
    v2 = result;
    *(_BYTE *)(result + 261) = a2 & 1;
    ipc_log_context = get_ipc_log_context(result);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      ipc_log_context,
      "[i][%-4d]sim_mode=%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(unsigned __int8 *)(v2 + 261));
    if ( (_drm_debug & 4) != 0 )
      return printk(&unk_26B85F, *(unsigned int *)(StatusReg + 1800));
    else
      return printk(&unk_264994, "dp_ctrl_set_sim_mode");
  }
  return result;
}
