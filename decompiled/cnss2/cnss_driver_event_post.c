__int64 __fastcall cnss_driver_event_post(__int64 a1, unsigned int a2, int a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x24
  char v7; // w22
  const char *v9; // x1
  const char *v10; // x6
  __int64 result; // x0
  const char *v12; // x8
  __int64 v13; // x7
  const char *v14; // x1
  __int64 v15; // x1
  __int64 v16; // x21
  const char *v17; // x1
  __int64 v18; // x0
  __int64 v19; // x2
  __int64 *v20; // x1
  __int64 v21; // x9
  __int64 v22; // x0
  int v23; // w0
  int v24; // w22
  const char *v25; // x1
  __int64 v26; // x1
  unsigned int v27; // w20
  unsigned int v28; // w20
  const char *v29; // x1
  unsigned int v36; // w8
  unsigned int v37; // w8
  unsigned int v40; // w8
  unsigned int v41; // w8
  char v42; // [xsp+0h] [xbp-20h]

  if ( !a1 )
    return 4294967277LL;
  StatusReg = _ReadStatusReg(SP_EL0);
  v7 = a3;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      v9 = "soft_irq";
    else
      v9 = (const char *)(StatusReg + 2320);
    if ( a2 <= 0x19 )
      goto LABEL_4;
LABEL_10:
    v10 = "UNKNOWN";
    goto LABEL_11;
  }
  v9 = "irq";
  if ( a2 > 0x19 )
    goto LABEL_10;
LABEL_4:
  v10 = off_5ADF0[a2];
LABEL_11:
  v12 = "-sync";
  if ( !a3 )
    v12 = (const char *)&unk_4DEF5;
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v9,
    "cnss_driver_event_post",
    7u,
    7u,
    "Posting event: %s(%d)%s, state: 0x%lx flags: 0x%0x\n",
    (__int64)v10,
    a2,
    (char)v12);
  if ( a2 < 0x19 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 || (_ReadStatusReg(DAIF) & 0x80) != 0 )
      v15 = 2336;
    else
      v15 = 3520;
    v16 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, v15, 72);
    if ( v16 )
    {
      _X9 = (unsigned int *)(a1 + 6264);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v36 = __ldxr(_X9);
        v37 = v36 + 1;
      }
      while ( __stlxr(v37, _X9) );
      __dmb(0xBu);
      if ( v37 == 1 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v17 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v17 = "soft_irq";
        }
        else
        {
          v17 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v17,
          "cnss_pm_stay_awake",
          7u,
          7u,
          "PM stay awake, state: 0x%lx, count: %d\n",
          *(_QWORD *)(a1 + 552),
          *(unsigned int *)(a1 + 6264),
          v42);
        pm_stay_awake(*(_QWORD *)a1 + 16LL);
      }
      *(_QWORD *)(v16 + 64) = a4;
      *(_DWORD *)(v16 + 16) = a2;
      *(_DWORD *)(v16 + 24) = 0;
      _init_swait_queue_head(v16 + 32, "&x->wait", &init_completion___key);
      *(_DWORD *)(v16 + 56) = 2989;
      *(_BYTE *)(v16 + 20) = v7 & 1;
      v18 = raw_spin_lock_irqsave(a1 + 640);
      v19 = a1 + 560;
      v20 = *(__int64 **)(a1 + 568);
      v21 = v18;
      if ( v16 == a1 + 560 || v20 == (__int64 *)v16 || *v20 != v19 )
      {
        _list_add_valid_or_report(v16, v20);
      }
      else
      {
        *(_QWORD *)(a1 + 568) = v16;
        *(_QWORD *)v16 = v19;
        *(_QWORD *)(v16 + 8) = v20;
        *v20 = v16;
      }
      raw_spin_unlock_irqrestore(a1 + 640, v21);
      queue_work_on(32, *(_QWORD *)(a1 + 680), a1 + 648);
      if ( (v7 & 1) != 0 )
      {
        v22 = v16 + 24;
        if ( (v7 & 4) != 0 )
        {
          wait_for_completion(v22);
          v24 = 0;
        }
        else
        {
          if ( (v7 & 2) != 0 )
            v23 = wait_for_completion_killable(v22);
          else
            v23 = wait_for_completion_interruptible(v22);
          v24 = v23;
        }
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v25 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v25 = "soft_irq";
        }
        else
        {
          v25 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v25,
          "cnss_driver_event_post",
          7u,
          7u,
          "Completed event: %s(%d), state: 0x%lx, ret: %d/%d\n",
          (__int64)off_5AD10[a2],
          a2,
          *(_QWORD *)(a1 + 552));
        v26 = raw_spin_lock_irqsave(a1 + 640);
        if ( v24 == -512 && *(_DWORD *)(v16 + 56) == 2989 )
        {
          *(_BYTE *)(v16 + 20) = 0;
          raw_spin_unlock_irqrestore(a1 + 640, v26);
          result = 4294967292LL;
        }
        else
        {
          raw_spin_unlock_irqrestore(a1 + 640, v26);
          v27 = *(_DWORD *)(v16 + 56);
          kfree(v16);
          result = v27;
        }
      }
      else
      {
        result = 0;
      }
      _X9 = (unsigned int *)(a1 + 6264);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v40 = __ldxr(_X9);
        v41 = v40 - 1;
      }
      while ( __stlxr(v41, _X9) );
      __dmb(0xBu);
      if ( (v41 & 0x80000000) != 0 )
      {
        __break(0x800u);
      }
      else if ( !v41 )
      {
        v28 = result;
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v29 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v29 = "soft_irq";
        }
        else
        {
          v29 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v29,
          "cnss_pm_relax",
          7u,
          7u,
          "PM relax, state: 0x%lx, count: %d\n",
          *(_QWORD *)(a1 + 552),
          *(unsigned int *)(a1 + 6264),
          v42);
        pm_relax(*(_QWORD *)a1 + 16LL);
        return v28;
      }
    }
    else
    {
      return 4294967284LL;
    }
  }
  else
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v14 = "soft_irq";
    }
    else
    {
      v14 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "cnss_driver_event_post",
      3u,
      3u,
      "Invalid Event type: %d, can't post",
      a2,
      v13,
      v42);
    return 4294967274LL;
  }
  return result;
}
