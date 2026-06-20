__int64 __fastcall dp_link_send_psm_request(__int64 a1)
{
  __int64 ipc_log_context; // x0

  if ( a1 )
    return 0;
  ipc_log_context = get_ipc_log_context((unsigned __int8)a1);
  ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  printk(&unk_275B6D, "dp_link_send_psm_request");
  return 4294967274LL;
}
