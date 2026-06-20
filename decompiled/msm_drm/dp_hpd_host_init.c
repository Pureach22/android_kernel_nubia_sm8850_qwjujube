__int64 __fastcall dp_hpd_host_init(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v2)(__int64, __int64); // x8
  __int64 ipc_log_context; // x0

  if ( a2 )
  {
    v2 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 8);
    if ( *((_DWORD *)v2 - 1) != 1657962687 )
      __break(0x8228u);
    return v2(a2, 1);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_hpd_host_init");
  }
}
