__int64 __fastcall dp_connector_get_modes(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _DWORD *v5; // x20
  _DWORD *v6; // x8
  __int64 v7; // x1
  unsigned int v8; // w0
  unsigned int v9; // w19
  __int64 v10; // x0
  __int64 ipc_log_context; // x0
  __int64 v12; // x0

  result = 0;
  if ( a1 && a2 )
  {
    if ( *(_QWORD *)(a1 + 2768) )
    {
      v5 = (_DWORD *)_kmalloc_cache_noprof(_wake_up, 3520, 800);
      if ( v5 )
      {
        if ( *(_BYTE *)(a2 + 32) != 1 )
        {
          ipc_log_context = get_ipc_log_context();
          ipc_log_string(ipc_log_context, "[e][%-4d]No sink connected\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
          printk(&unk_245653, "dp_connector_get_modes");
          v9 = 0;
          goto LABEL_12;
        }
        v6 = *(_DWORD **)(a2 + 128);
        v7 = *(_QWORD *)(a1 + 2768);
        if ( *(v6 - 1) != -723972362 )
          __break(0x8228u);
        v8 = ((__int64 (__fastcall *)(__int64, __int64, _DWORD *))v6)(a2, v7, v5);
        if ( v8 )
        {
          if ( !v5[12] )
          {
LABEL_11:
            v9 = v8;
LABEL_12:
            kfree(v5);
            return v9;
          }
        }
        else
        {
          v12 = get_ipc_log_context();
          ipc_log_string(
            v12,
            "[w][%-4d]failed to get DP sink modes, adding failsafe",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
          printk(&unk_230F45, "dp_connector_get_modes");
          memcpy(v5, &init_failsafe_mode_fail_safe, 0x300u);
        }
        v8 = dp_connector_add_custom_mode(a1, v5);
        goto LABEL_11;
      }
    }
    else
    {
      v10 = get_ipc_log_context();
      ipc_log_string(v10, "[e][%-4d]invalid dp panel\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_2238C5, "dp_connector_get_modes");
    }
    return 0;
  }
  return result;
}
