__int64 __fastcall dp_catalog_ctrl_state_ctrl(__int64 a1, unsigned int a2)
{
  __int64 v2; // x3
  __int64 v3; // x1
  __int64 (__fastcall *v4)(__int64, __int64, __int64, __int64); // x8
  __int64 v5; // x0
  __int64 result; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v2 = a2;
    v3 = *(_QWORD *)(a1 - 208);
    v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
    v5 = a1 - 232;
    if ( *((_DWORD *)v4 - 1) != -626862723 )
      __break(0x8228u);
    result = v4(v5, v3, 4, v2);
    __dsb(0xEu);
  }
  else
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_state_ctrl");
  }
  return result;
}
