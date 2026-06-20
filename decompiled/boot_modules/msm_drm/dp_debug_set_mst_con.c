__int64 __fastcall dp_debug_set_mst_con(__int64 result, int a2)
{
  __int64 v2; // x19
  __int64 v4; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21

  if ( result )
  {
    v2 = result;
    mutex_lock(result + 216);
    *(_DWORD *)(v2 - 144) = a2;
    v4 = mutex_unlock(v2 + 216);
    ipc_log_context = get_ipc_log_context(v4);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[i][%-4d]Selecting mst connector %d\n", *(_DWORD *)(StatusReg + 1800), a2);
    if ( (_drm_debug & 4) != 0 )
      return printk(&unk_2486A1, *(unsigned int *)(StatusReg + 1800));
    else
      return printk(&unk_21157E, "dp_debug_set_mst_con");
  }
  return result;
}
