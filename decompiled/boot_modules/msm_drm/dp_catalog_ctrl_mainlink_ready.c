__int64 __fastcall dp_catalog_ctrl_mainlink_ready(__int64 a1)
{
  __int64 v1; // x20
  __int64 (__fastcall *v2)(__int64, __int64, __int64); // x8
  __int64 v3; // x21
  __int64 v5; // x0
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v7)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v8)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v9)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v10)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v11)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v12)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v13)(__int64, __int64, __int64); // x8
  __int64 ipc_log_context; // x0
  void *v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v16 = &unk_275B6D;
LABEL_32:
    printk(v16, "dp_catalog_ctrl_mainlink_ready");
    return 0;
  }
  v1 = *(_QWORD *)(a1 - 208);
  v2 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
  v3 = a1 - 232;
  v5 = a1 - 232;
  if ( *((_DWORD *)v2 - 1) != -1879227436 )
    __break(0x8228u);
  if ( (v2(v5, v1, 64) & 1) == 0 )
  {
    usleep_range_state(1000, 1010, 2);
    v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
    if ( *((_DWORD *)v6 - 1) != -1879227436 )
      __break(0x8228u);
    if ( (v6(v3, v1, 64) & 1) == 0 )
    {
      usleep_range_state(1000, 1010, 2);
      v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
      if ( *((_DWORD *)v7 - 1) != -1879227436 )
        __break(0x8228u);
      if ( (v7(v3, v1, 64) & 1) == 0 )
      {
        usleep_range_state(1000, 1010, 2);
        v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
        if ( *((_DWORD *)v8 - 1) != -1879227436 )
          __break(0x8228u);
        if ( (v8(v3, v1, 64) & 1) == 0 )
        {
          usleep_range_state(1000, 1010, 2);
          v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
          if ( *((_DWORD *)v9 - 1) != -1879227436 )
            __break(0x8228u);
          if ( (v9(v3, v1, 64) & 1) == 0 )
          {
            usleep_range_state(1000, 1010, 2);
            v10 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
            if ( *((_DWORD *)v10 - 1) != -1879227436 )
              __break(0x8228u);
            if ( (v10(v3, v1, 64) & 1) == 0 )
            {
              usleep_range_state(1000, 1010, 2);
              v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
              if ( *((_DWORD *)v11 - 1) != -1879227436 )
                __break(0x8228u);
              if ( (v11(v3, v1, 64) & 1) == 0 )
              {
                usleep_range_state(1000, 1010, 2);
                v12 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
                if ( *((_DWORD *)v12 - 1) != -1879227436 )
                  __break(0x8228u);
                if ( (v12(v3, v1, 64) & 1) == 0 )
                {
                  usleep_range_state(1000, 1010, 2);
                  v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
                  if ( *((_DWORD *)v13 - 1) != -1879227436 )
                    __break(0x8228u);
                  if ( (v13(v3, v1, 64) & 1) == 0 )
                  {
                    v17 = usleep_range_state(1000, 1010, 2);
                    v18 = get_ipc_log_context(v17);
                    ipc_log_string(v18, "[e][%-4d]mainlink not ready\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
                    v16 = &unk_24B521;
                    goto LABEL_32;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}
