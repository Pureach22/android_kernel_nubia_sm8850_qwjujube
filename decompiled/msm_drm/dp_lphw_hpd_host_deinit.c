__int64 __fastcall dp_lphw_hpd_host_deinit(__int64 a1)
{
  __int64 (*v2)(void); // x8
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    enable_irq(*(unsigned int *)(a1 + 344));
    v2 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 80) + 8LL);
    if ( *((_DWORD *)v2 - 1) != 1657962687 )
      __break(0x8228u);
    return v2();
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_lphw_hpd_host_deinit");
  }
}
