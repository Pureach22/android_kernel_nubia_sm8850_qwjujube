__int64 __fastcall dp_hdcp2p2_reauthenticate(__int64 a1)
{
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    *(_DWORD *)(a1 + 88) = 0;
    *(_DWORD *)(a1 + 80) = 0;
    return dp_hdcp2p2_authenticate();
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_hdcp2p2_reauthenticate");
    return 4294967274LL;
  }
}
