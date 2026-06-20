__int64 __fastcall audio_notifier_register(const char *a1, int a2, __int64 a3)
{
  __int64 v6; // x19
  size_t v7; // x0
  unsigned __int64 v8; // x2
  unsigned int v9; // w0
  __int64 *v10; // x1
  unsigned int v11; // w20
  void *v12; // x0

  if ( !a1 )
  {
    if ( !(unsigned int)__ratelimit(&audio_notifier_register__rs, "audio_notifier_register") )
      return 4294967274LL;
    v12 = &unk_82B1;
LABEL_24:
    printk(v12, "audio_notifier_register");
    return 4294967274LL;
  }
  if ( !a3 )
  {
    if ( !(unsigned int)__ratelimit(&audio_notifier_register__rs_3, "audio_notifier_register") )
      return 4294967274LL;
    v12 = &unk_84E2;
    goto LABEL_24;
  }
  v6 = _kmalloc_cache_noprof(srcu_notifier_chain_register, 3264, 56);
  if ( v6 )
  {
    *(_QWORD *)v6 = v6;
    *(_QWORD *)(v6 + 8) = v6;
    *(_QWORD *)(v6 + 16) = a3;
    v7 = strnlen(a1, 0x14u);
    if ( v7 == -1 )
    {
      _fortify_panic(2, -1, 0);
    }
    else
    {
      if ( v7 == 20 )
        v8 = 20;
      else
        v8 = v7 + 1;
      if ( v8 < 0x15 )
      {
        sized_strscpy(v6 + 24, a1);
        *(_DWORD *)(v6 + 44) = -2;
        *(_DWORD *)(v6 + 48) = a2;
        mutex_lock(&notifier_mutex);
        v9 = audio_notifier_reg_client(v6);
        if ( (v9 & 0x80000000) != 0 )
        {
          v11 = v9;
          mutex_unlock(&notifier_mutex);
          if ( (unsigned int)__ratelimit(&audio_notifier_register__rs_7, "audio_notifier_register") )
            printk(&unk_83DF, "audio_notifier_register");
          kfree(v6);
          return v11;
        }
        v10 = (__int64 *)off_68;
        if ( (_UNKNOWN **)v6 != &client_list && off_68 != (_UNKNOWN **)v6 && *off_68 == (_UNKNOWN *)&client_list )
        {
          v11 = v9;
          off_68 = (_UNKNOWN **)v6;
          *(_QWORD *)v6 = &client_list;
          *(_QWORD *)(v6 + 8) = v10;
          *v10 = v6;
LABEL_14:
          mutex_unlock(&notifier_mutex);
          return v11;
        }
LABEL_27:
        v11 = v9;
        _list_add_valid_or_report(v6, v10, &client_list);
        goto LABEL_14;
      }
    }
    v9 = _fortify_panic(7, 20, v8);
    goto LABEL_27;
  }
  return 4294967284LL;
}
