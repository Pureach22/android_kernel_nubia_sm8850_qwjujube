__int64 __fastcall mhi_uci_probe(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x20
  const char **v6; // x9
  const char *v7; // x3
  int v8; // w23
  __int64 v9; // x0
  unsigned __int64 v10; // x0
  unsigned int v11; // w19
  __int64 result; // x0
  unsigned __int64 v13; // x8
  __int64 v14; // x2
  unsigned __int64 v21; // x10
  __int64 v22; // x1
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v24; // [xsp+10h] [xbp-20h]
  __int64 v25; // [xsp+18h] [xbp-18h]
  __int64 v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26 = 0;
  *(_QWORD *)s = 0;
  v24 = 0;
  v4 = _kmalloc_cache_noprof(raw_spin_unlock_irq, 3520, 368);
  v5 = v4;
  if ( v4 )
  {
    _mutex_init(v4 + 48, "&uci_dev->mutex", &mhi_uci_probe___key);
    *(_QWORD *)(v5 + 32) = a1;
    if ( uci_minors[0] == -1 )
    {
      kfree(v5);
      result = 4294967268LL;
    }
    else
    {
      v6 = *(const char ***)(a1 + 136);
      v7 = v6[14];
      v8 = __clz(__rbit64(~uci_minors[0]));
      if ( !v7 )
        v7 = *v6;
      snprintf(s, 0x20u, "%s_pipe_%d", v7, *(_DWORD *)(a1 + 956));
      mutex_lock(v5 + 48);
      mutex_lock(&unk_86D0);
      v9 = qword_8700;
      *(_DWORD *)(v5 + 16) = v8 | (dword_8708 << 20);
      v10 = device_create(v9, a1 + 40);
      *(_QWORD *)(v5 + 24) = v10;
      if ( v10 < 0xFFFFFFFFFFFFF001LL )
      {
        _X9 = uci_minors;
        __asm { PRFM            #0x11, [X9] }
        do
          v21 = __ldxr((unsigned __int64 *)uci_minors);
        while ( __stxr(v21 | (1LL << v8), (unsigned __int64 *)uci_minors) );
        v22 = *(_QWORD *)(a1 + 152);
        if ( !v22 )
          v22 = *(_QWORD *)(a1 + 40);
        *(_QWORD *)(v5 + 352) = ipc_log_context_create(50, v22, 0);
        *(_DWORD *)(v5 + 360) = 2;
        if ( (unsigned int)sysfs_create_group(a1 + 40, &mhi_uci_group) )
        {
          printk(&unk_81C1, "mhi_uci_probe");
          if ( *(_QWORD *)(v5 + 352) )
          {
            if ( *(_DWORD *)(v5 + 360) <= 2u )
              ipc_log_string();
          }
        }
        *(_DWORD *)(v5 + 232) = 0;
        _mutex_init(v5 + 272, "&uci_chan->chan_lock", &mhi_uci_probe___key_49);
        _init_waitqueue_head(v5 + 208, "&uci_chan->wq", &mhi_uci_probe___key_51);
        *(_QWORD *)(v5 + 240) = v5 + 240;
        *(_QWORD *)(v5 + 248) = v5 + 240;
        *(_DWORD *)(v5 + 120) = 0;
        _mutex_init(v5 + 160, "&uci_chan->chan_lock", &mhi_uci_probe___key_49);
        _init_waitqueue_head(v5 + 96, "&uci_chan->wq", &mhi_uci_probe___key_51);
        *(_QWORD *)(v5 + 128) = v5 + 128;
        *(_QWORD *)(v5 + 136) = v5 + 128;
        v13 = *(_QWORD *)(a2 + 32);
        v14 = mhi_uci_drv;
        *(_QWORD *)(a1 + 192) = v5;
        if ( v13 >= 0xFFFF )
          v13 = 0xFFFF;
        *(_QWORD *)(v5 + 320) = v13;
        *(_QWORD *)(v5 + 328) = v13 - 32;
        *(_BYTE *)(v5 + 340) = 1;
        if ( v14 == v5 || *(__int64 **)(v14 + 8) != &mhi_uci_drv )
        {
          _list_add_valid_or_report(v5, &mhi_uci_drv);
        }
        else
        {
          *(_QWORD *)(v14 + 8) = v5;
          *(_QWORD *)v5 = v14;
          *(_QWORD *)(v5 + 8) = &mhi_uci_drv;
          mhi_uci_drv = v5;
        }
        mutex_unlock(&unk_86D0);
        mutex_unlock(v5 + 48);
        result = *(_QWORD *)(v5 + 352);
        if ( result )
        {
          if ( *(_DWORD *)(v5 + 360) <= 1u )
            ipc_log_string();
          result = 0;
        }
      }
      else
      {
        mutex_unlock(&unk_86D0);
        mutex_unlock(v5 + 48);
        v11 = *(_DWORD *)(v5 + 24);
        kfree(v5);
        result = v11;
      }
    }
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
