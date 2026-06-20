__int64 __fastcall dp_catalog_panel_config_dto(__int64 a1, char a2)
{
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 (__fastcall *v5)(__int64, __int64, __int64); // x8
  __int64 v7; // x0
  unsigned int v8; // w9
  __int64 (__fastcall *v9)(__int64, __int64, __int64, __int64); // x8
  __int64 v10; // x3
  __int64 v12; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 204) >= 2u )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream_id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 204));
      return printk(&unk_272496, "dp_catalog_panel_config_dto");
    }
    else
    {
      v3 = -544;
      if ( (*(_DWORD *)(a1 + 204) & 1) != 0 )
        v3 = -480;
      v4 = *(_QWORD *)(a1 + v3);
      v5 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 456);
      v7 = a1 - 576;
      if ( *((_DWORD *)v5 - 1) != -1879227436 )
        __break(0x8228u);
      v8 = v5(v7, v4, 124) & 0xFFFFFFFD;
      v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 448);
      if ( (a2 & 1) != 0 )
        v10 = 2;
      else
        v10 = v8;
      if ( *((_DWORD *)v9 - 1) != -626862723 )
        __break(0x8228u);
      return v9(a1 - 576, v4, 124, v10);
    }
  }
  else
  {
    v12 = get_ipc_log_context(0);
    ipc_log_string(v12, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_panel_config_dto");
  }
}
