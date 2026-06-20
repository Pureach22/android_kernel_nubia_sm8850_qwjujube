__int64 __fastcall dp_link_send_test_response(__int64 a1)
{
  __int64 ipc_log_context; // x0

  if ( a1 )
    return drm_dp_dpcd_write(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 24LL), 608, a1 + 4, 1);
  ipc_log_context = get_ipc_log_context(0);
  ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  return printk(&unk_275B6D, "dp_link_send_test_response");
}
