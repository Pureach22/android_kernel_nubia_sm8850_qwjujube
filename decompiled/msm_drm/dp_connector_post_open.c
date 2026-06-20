void __fastcall dp_connector_post_open(__int64 a1, __int64 a2)
{
  void (__fastcall *v2)(_QWORD); // x8
  __int64 ipc_log_context; // x0

  if ( a2 )
  {
    v2 = *(void (__fastcall **)(_QWORD))(a2 + 168);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != 124150616 )
        __break(0x8228u);
      v2(a2);
    }
  }
  else
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_connector_post_open");
  }
}
