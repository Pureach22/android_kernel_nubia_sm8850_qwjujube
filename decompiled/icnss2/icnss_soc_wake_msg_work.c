__int64 __fastcall icnss_soc_wake_msg_work(__int64 a1)
{
  __int64 v2; // x27
  _QWORD *v3; // x24
  _QWORD *v4; // x26
  _QWORD *v5; // x8
  __int64 v6; // x9
  __int64 v7; // x4
  const char *v8; // x2
  const char *v9; // x3
  int v10; // w2
  __int64 v11; // x8
  _BYTE *v12; // x27
  unsigned int v13; // w8
  unsigned int v20; // w10
  unsigned int v21; // w8
  unsigned int v22; // w9
  unsigned int v25; // w10
  int v26; // w25
  const char *v27; // x2
  __int64 v28; // x4
  const char *v29; // x3
  __int64 v30; // x0
  int v31; // w8
  int v32; // w0
  unsigned int v35; // w9
  __int64 result; // x0
  unsigned int v39; // w8
  unsigned int v40; // w8
  unsigned int v43; // w8
  unsigned int v44; // w8
  __int64 v45; // [xsp+8h] [xbp-8h]

  while ( 1 )
  {
    _X9 = (unsigned int *)(a1 + 1176);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v39 = __ldxr(_X9);
      v40 = v39 + 1;
    }
    while ( __stlxr(v40, _X9) );
    __dmb(0xBu);
    if ( v40 == 1 )
    {
      ipc_log_string(
        icnss_ipc_log_long_context,
        "icnss2: PM stay awake, state: 0x%lx, count: %d\n",
        *(_QWORD *)(a1 + 88),
        *(_DWORD *)(a1 + 1176));
      pm_stay_awake(*(_QWORD *)(a1 - 1736) + 16LL);
      ++*(_DWORD *)(a1 + 812);
    }
    v2 = raw_spin_lock_irqsave(a1 - 100);
    v4 = (_QWORD *)(a1 - 120);
    v3 = *(_QWORD **)(a1 - 120);
    if ( v3 == (_QWORD *)(a1 - 120) )
      break;
    v45 = a1 - 1744;
    while ( 1 )
    {
      v5 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v5 == v3 && (v6 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
      {
        *(_QWORD *)(v6 + 8) = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      raw_spin_unlock_irqrestore(a1 - 100, v2);
      v7 = *((unsigned int *)v3 + 4);
      v8 = "UNKNOWN";
      if ( (unsigned int)v7 <= 2 )
        v8 = off_A88C8[v7];
      if ( *((_BYTE *)v3 + 20) )
        v9 = "-sync";
      else
        v9 = (const char *)&unk_12DBF3;
      ipc_log_string(icnss_ipc_soc_wake_context, "icnss2: Processing event: %s%s(%d), state: 0x%lx\n", v8, v9);
      v10 = *((_DWORD *)v3 + 4);
      if ( v10 == 1 )
      {
        v12 = (char *)v3 + 20;
        if ( a1 != 1744 )
        {
          v21 = *(_DWORD *)(a1 + 3744);
          do
          {
            v22 = v21 - 1;
            if ( (int)(v21 - 1) < 0 )
              goto LABEL_39;
            _X12 = (unsigned int *)(a1 + 3744);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v25 = __ldxr(_X12);
              if ( v25 != v21 )
                break;
              if ( !__stlxr(v22, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v25 == v21;
            v21 = v25;
          }
          while ( !_ZF );
          if ( v22 )
          {
LABEL_39:
            ipc_log_string(
              icnss_ipc_soc_wake_context,
              "icnss2: Wake release not called. Ref count: %d",
              *(unsigned int *)(a1 + 3744));
            goto LABEL_40;
          }
          v32 = icnss_send_smp2p(v45, 5, 1u);
LABEL_55:
          v26 = v32;
          goto LABEL_41;
        }
        v26 = -19;
        v11 = 1;
LABEL_45:
        v27 = "UNKNOWN";
        ++*(_DWORD *)(a1 + 556 + 8 * v11 + 4);
        v28 = *((unsigned int *)v3 + 4);
        if ( (unsigned int)v28 <= 2 )
          v27 = off_A88C8[v28];
        if ( *v12 )
          v29 = "-sync";
        else
          v29 = (const char *)&unk_12DBF3;
        ipc_log_string(
          icnss_ipc_soc_wake_context,
          "icnss2: Event Processed: %s%s(%d), ret: %d, state: 0x%lx\n",
          v27,
          v29);
        v30 = raw_spin_lock_irqsave(a1 - 100);
        v31 = (unsigned __int8)*v12;
        v2 = v30;
        if ( v31 == 1 )
        {
          *((_DWORD *)v3 + 14) = v26;
          complete(v3 + 3);
        }
        else
        {
          raw_spin_unlock_irqrestore(a1 - 100, v30);
          kfree(v3);
          v2 = raw_spin_lock_irqsave(a1 - 100);
        }
        goto LABEL_6;
      }
      if ( !v10 )
        break;
      printk("%sicnss2: Invalid Event type: %d", byte_130B32, v10);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Invalid Event type: %d",
        (const char *)&unk_12DBF3,
        *((_DWORD *)v3 + 4));
      kfree(v3);
LABEL_6:
      v3 = (_QWORD *)*v4;
      if ( (_QWORD *)*v4 == v4 )
        goto LABEL_61;
    }
    v11 = a1 - 1744;
    v12 = (char *)v3 + 20;
    if ( a1 == 1744 )
    {
      v26 = -19;
      goto LABEL_45;
    }
    v13 = *(_DWORD *)(a1 + 3744);
    while ( v13 )
    {
      _X12 = (unsigned int *)(a1 + 3744);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v20 = __ldxr(_X12);
        if ( v20 != v13 )
          break;
        if ( !__stlxr(v13 + 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v20 == v13;
      v13 = v20;
      if ( _ZF )
      {
        ipc_log_string(
          icnss_ipc_soc_wake_context,
          "icnss2: SOC awake after posting work, Ref count: %d",
          *(unsigned int *)(a1 + 3744));
        goto LABEL_40;
      }
    }
    v32 = icnss_send_smp2p(v45, 4, 1u);
    if ( v32 )
      goto LABEL_55;
    _X8 = (unsigned int *)(a1 + 3744);
    __asm { PRFM            #0x11, [X8] }
    do
      v35 = __ldxr(_X8);
    while ( __stxr(v35 + 1, _X8) );
LABEL_40:
    v26 = 0;
LABEL_41:
    v11 = *((unsigned int *)v3 + 4);
    if ( (unsigned int)v11 < 2 )
      goto LABEL_45;
    __break(0x5512u);
  }
LABEL_61:
  result = raw_spin_unlock_irqrestore(a1 - 100, v2);
  _X9 = (unsigned int *)(a1 + 1176);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v43 = __ldxr(_X9);
    v44 = v43 - 1;
  }
  while ( __stlxr(v44, _X9) );
  __dmb(0xBu);
  if ( (v44 & 0x80000000) != 0 )
  {
    __break(0x800u);
  }
  else if ( !v44 )
  {
    ipc_log_string(
      icnss_ipc_log_long_context,
      "icnss2: PM relax, state: 0x%lx, count: %d\n",
      *(_QWORD *)(a1 + 88),
      *(_DWORD *)(a1 + 1176));
    result = pm_relax(*(_QWORD *)(a1 - 1736) + 16LL);
    ++*(_DWORD *)(a1 + 816);
  }
  return result;
}
