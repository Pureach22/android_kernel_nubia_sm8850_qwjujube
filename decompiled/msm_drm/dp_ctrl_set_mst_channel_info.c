__int64 __fastcall dp_ctrl_set_mst_channel_info(__int64 result, unsigned int a2, int a3, int a4)
{
  __int64 v4; // x8
  __int64 ipc_log_context; // x0

  if ( result && a2 < 2 )
  {
    v4 = result + 8LL * a2;
    *(_DWORD *)(v4 + 284) = a3;
    *(_DWORD *)(v4 + 288) = a4;
  }
  else
  {
    ipc_log_context = get_ipc_log_context(result);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_ctrl_set_mst_channel_info");
  }
  return result;
}
