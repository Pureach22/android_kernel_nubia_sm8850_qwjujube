__int64 __fastcall dp_connector_update_pps(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // x10
  __int64 v5; // x0
  __int64 ipc_log_context; // x0

  if ( a1 && a3 )
  {
    if ( *(_QWORD *)(a1 + 2768) )
    {
      v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a3 + 280);
      if ( *((_DWORD *)v3 - 1) != 606029769 )
        __break(0x822Au);
      return v3(a3, a1, a2);
    }
    else
    {
      ipc_log_context = get_ipc_log_context();
      ipc_log_string(ipc_log_context, "[e][%-4d]invalid dp panel\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_2238C5, "dp_connector_update_pps");
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    v5 = get_ipc_log_context();
    ipc_log_string(v5, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_24B695, "dp_connector_update_pps");
    return 4294967274LL;
  }
}
