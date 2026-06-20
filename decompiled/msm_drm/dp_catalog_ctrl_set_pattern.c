__int64 __fastcall dp_catalog_ctrl_set_pattern(__int64 a1, int a2)
{
  int v2; // w8
  __int64 v4; // x21
  int v5; // w23
  __int64 v7; // x22
  __int64 v8; // x0
  unsigned __int64 StatusReg; // x24
  void (__fastcall *v10)(__int64, __int64, __int64, __int64); // x8
  __int64 v11; // x23
  __int64 (__fastcall *v12)(__int64, __int64, __int64); // x8
  __int64 result; // x0
  __int64 (__fastcall *v14)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v15)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v16)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v17)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v18)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v19)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v20)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v21)(__int64, __int64, __int64); // x8
  __int64 (__fastcall *v22)(__int64, __int64, __int64); // x8
  __int64 v23; // x0
  __int64 v24; // x0
  void *v25; // x0
  __int64 ipc_log_context; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v25 = &unk_275B6D;
    return printk(v25, "dp_catalog_ctrl_set_pattern");
  }
  v2 = a2 - 1;
  if ( (unsigned int)(a2 - 1) >= 7 || ((0x47u >> v2) & 1) == 0 )
  {
    v24 = get_ipc_log_context(a1);
    ipc_log_string(v24, "[e][%-4d]invalid pattern\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v25 = &unk_25243C;
    return printk(v25, "dp_catalog_ctrl_set_pattern");
  }
  v4 = *(_QWORD *)(a1 - 208);
  v5 = dword_280C28[v2];
  v7 = a1 - 232;
  v8 = get_ipc_log_context(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(v8, "[d][%-4d]hw: bit=%d train=%d\n", *(_DWORD *)(StatusReg + 1800), v5, a2);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]hw: bit=%d train=%d\n", *(_DWORD *)(StatusReg + 1800), v5, a2);
  v10 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 - 104);
  if ( *((_DWORD *)v10 - 1) != -626862723 )
    __break(0x8228u);
  v10(v7, v4, 4, 1LL << v5);
  v11 = 1LL << ((unsigned __int8)v5 + 3);
  v12 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
  if ( *((_DWORD *)v12 - 1) != -1879227436 )
    __break(0x8228u);
  result = v12(v7, v4, 64);
  if ( ((unsigned int)v11 & (unsigned int)result) == 0 )
  {
    v14 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
    if ( *((_DWORD *)v14 - 1) != -1879227436 )
      __break(0x8228u);
    result = v14(v7, v4, 64);
    if ( ((unsigned int)v11 & (unsigned int)result) == 0 )
    {
      v15 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
      if ( *((_DWORD *)v15 - 1) != -1879227436 )
        __break(0x8228u);
      result = v15(v7, v4, 64);
      if ( ((unsigned int)v11 & (unsigned int)result) == 0 )
      {
        v16 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
        if ( *((_DWORD *)v16 - 1) != -1879227436 )
          __break(0x8228u);
        result = v16(v7, v4, 64);
        if ( ((unsigned int)v11 & (unsigned int)result) == 0 )
        {
          v17 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
          if ( *((_DWORD *)v17 - 1) != -1879227436 )
            __break(0x8228u);
          result = v17(v7, v4, 64);
          if ( ((unsigned int)v11 & (unsigned int)result) == 0 )
          {
            v18 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
            if ( *((_DWORD *)v18 - 1) != -1879227436 )
              __break(0x8228u);
            result = v18(v7, v4, 64);
            if ( ((unsigned int)v11 & (unsigned int)result) == 0 )
            {
              v19 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
              if ( *((_DWORD *)v19 - 1) != -1879227436 )
                __break(0x8228u);
              result = v19(v7, v4, 64);
              if ( ((unsigned int)v11 & (unsigned int)result) == 0 )
              {
                v20 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
                if ( *((_DWORD *)v20 - 1) != -1879227436 )
                  __break(0x8228u);
                result = v20(v7, v4, 64);
                if ( ((unsigned int)v11 & (unsigned int)result) == 0 )
                {
                  v21 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
                  if ( *((_DWORD *)v21 - 1) != -1879227436 )
                    __break(0x8228u);
                  result = v21(v7, v4, 64);
                  if ( ((unsigned int)v11 & (unsigned int)result) == 0 )
                  {
                    v22 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
                    if ( *((_DWORD *)v22 - 1) != -1879227436 )
                      __break(0x8228u);
                    result = v22(v7, v4, 64);
                    if ( ((unsigned int)v11 & (unsigned int)result) != 0 )
                    {
                      v23 = get_ipc_log_context(result);
                      ipc_log_string(v23, "[e][%-4d]set link_train=%d failed\n", *(_DWORD *)(StatusReg + 1800), a2);
                      return printk(&unk_26EFB3, "dp_catalog_ctrl_set_pattern");
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
