__int64 __fastcall dp_ctrl_abort(__int64 result, char a2)
{
  __int64 ipc_log_context; // x0

  if ( result )
  {
    *(_DWORD *)(result + 264) = a2 & 1;
  }
  else
  {
    ipc_log_context = get_ipc_log_context((unsigned __int8)result);
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid input data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_23AC6D, "dp_ctrl_abort");
  }
  return result;
}
