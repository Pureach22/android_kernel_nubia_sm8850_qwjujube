__int64 __fastcall audio_notify_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 property; // x0
  __int64 v6; // x0
  _QWORD *v7; // x23
  _UNKNOWN **v8; // x26
  __int64 result; // x0
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  adsp_private = 0;
  v2 = devm_kmalloc(a1 + 16, 16, 3520);
  if ( v2 )
  {
    v3 = v2;
    *(_BYTE *)(v2 + 8) = 0;
    v4 = *(_QWORD *)(a1 + 760);
    *(_QWORD *)(a1 + 168) = v3;
    property = of_find_property(v4, "qcom,rproc-handle", &v10);
    if ( property )
    {
      v6 = rproc_get_by_phandle(bswap32(**(_DWORD **)(property + 16)));
      *(_QWORD *)v3 = v6;
      if ( v6 )
      {
        adsp_private = a1;
        _mutex_init(&notifier_mutex, "&notifier_mutex", &audio_notifier_subsys_init___key);
        if ( dword_188 >= -1 )
          srcu_init_notifier_head(&unk_1A8);
        if ( dword_3C8 >= -1 )
          srcu_init_notifier_head(&unk_3E8);
        if ( dword_608 >= -1 )
          srcu_init_notifier_head(&unk_628);
        if ( dword_848 >= -1 )
          srcu_init_notifier_head(&unk_868);
        if ( dword_608 == -1 )
          dword_608 = 0;
        if ( dword_848 == -1 )
          dword_848 = 0;
        mutex_lock(&notifier_mutex);
        if ( dword_608 == -2 && dword_848 == -2 )
        {
          v7 = client_list;
          if ( client_list != (_UNKNOWN *)&client_list )
          {
            do
            {
              v8 = (_UNKNOWN **)*v7;
              if ( (audio_notifier_reg_client((__int64)v7) & 0x80000000) != 0
                && (unsigned int)__ratelimit(&audio_notifier_reg_all_clients__rs, "audio_notifier_reg_all_clients") )
              {
                printk(&unk_824F, "audio_notifier_reg_all_clients");
              }
              v7 = v8;
            }
            while ( v8 != &client_list );
          }
        }
        mutex_unlock(&notifier_mutex);
        result = 0;
        *(_BYTE *)(v3 + 8) = 1;
      }
      else
      {
        if ( (unsigned int)__ratelimit(&audio_notify_probe__rs, "audio_notify_probe") )
          dev_info(a1 + 16, "remotproc handle NULL\n");
        result = 4294966779LL;
      }
    }
    else
    {
      dev_err(a1 + 16, "Missing remotproc handle\n");
      result = 4294967274LL;
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
