__int64 __fastcall icnss_soc_wake_event_post(__int64 a1, unsigned int a2, int a3, __int64 a4)
{
  __int64 v5; // x0
  const char *v9; // x2
  __int64 v10; // x6
  unsigned __int64 StatusReg; // x21
  __int64 v12; // x1
  __int64 v13; // x21
  __int64 v14; // x0
  __int64 v15; // x2
  __int64 *v16; // x1
  __int64 v17; // x9
  __int64 v18; // x1
  __int64 result; // x0
  __int64 v20; // x0
  unsigned int v21; // w22
  const char *v22; // x8
  const char *v23; // x2
  __int64 v24; // x1
  unsigned int v25; // w20
  unsigned int v26; // w20
  unsigned int v33; // w8
  unsigned int v34; // w8
  unsigned int v37; // w8
  unsigned int v38; // w8

  if ( !a1 )
    return 4294967277LL;
  v5 = icnss_ipc_soc_wake_context;
  v9 = "UNKNOWN";
  if ( a2 <= 2 )
    v9 = off_A88C8[a2];
  v10 = *(_QWORD *)(a1 + 1832);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v5,
    "icnss2: Posting event: %s(%d), %s, flags: 0x%x, state: 0x%lx\n",
    v9,
    a2,
    (const char *)(StatusReg + 2320),
    a3,
    v10);
  if ( a2 >= 2 )
  {
    printk("%sicnss2: Invalid Event type: %d, can't post", byte_130B32, a2);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Invalid Event type: %d, can't post", (const char *)&unk_12DBF3, a2);
    return 4294967274LL;
  }
  else
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 || (_ReadStatusReg(DAIF) & 0x80) != 0 )
      v12 = 2336;
    else
      v12 = 3520;
    v13 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, v12, 72);
    if ( v13 )
    {
      _X9 = (unsigned int *)(a1 + 2920);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v33 = __ldxr(_X9);
        v34 = v33 + 1;
      }
      while ( __stlxr(v34, _X9) );
      __dmb(0xBu);
      if ( v34 == 1 )
      {
        ipc_log_string(
          icnss_ipc_log_long_context,
          "icnss2: PM stay awake, state: 0x%lx, count: %d\n",
          *(_QWORD *)(a1 + 1832),
          *(_DWORD *)(a1 + 2920));
        pm_stay_awake(*(_QWORD *)(a1 + 8) + 16LL);
        ++*(_DWORD *)(a1 + 2556);
      }
      *(_QWORD *)(v13 + 64) = a4;
      *(_DWORD *)(v13 + 16) = a2;
      *(_DWORD *)(v13 + 24) = 0;
      _init_swait_queue_head(v13 + 32, "&x->wait", &init_completion___key);
      *(_DWORD *)(v13 + 56) = 2989;
      *(_BYTE *)(v13 + 20) = a3 & 1;
      v14 = raw_spin_lock_irqsave(a1 + 1644);
      v15 = a1 + 1624;
      v16 = *(__int64 **)(a1 + 1632);
      v17 = v14;
      if ( v13 == a1 + 1624 || v16 == (__int64 *)v13 || *v16 != v15 )
      {
        _list_add_valid_or_report(v13, v16);
      }
      else
      {
        *(_QWORD *)(a1 + 1632) = v13;
        *(_QWORD *)v13 = v15;
        *(_QWORD *)(v13 + 8) = v16;
        *v16 = v13;
      }
      raw_spin_unlock_irqrestore(a1 + 1644, v17);
      v18 = *(_QWORD *)(a1 + 1784);
      ++*(_DWORD *)(a1 + 8LL * a2 + 2300);
      queue_work_on(32, v18, a1 + 1744);
      if ( (a3 & 1) != 0 )
      {
        v20 = v13 + 24;
        if ( (a3 & 2) != 0 )
        {
          wait_for_completion(v20);
          v21 = 0;
        }
        else
        {
          v21 = wait_for_completion_interruptible(v20);
        }
        v22 = "SOC_WAKE_RELEASE";
        if ( a2 != 1 )
          v22 = "UNKNOWN";
        if ( a2 )
          v23 = v22;
        else
          v23 = "SOC_WAKE_REQUEST";
        ipc_log_string(
          icnss_ipc_soc_wake_context,
          "icnss2: Completed event: %s(%d), state: 0x%lx, ret: %d/%d\n",
          v23,
          a2,
          *(_QWORD *)(a1 + 1832),
          v21,
          *(unsigned int *)(v13 + 56));
        v24 = raw_spin_lock_irqsave(a1 + 1644);
        if ( v21 == -512 && *(_DWORD *)(v13 + 56) == 2989 )
        {
          *(_BYTE *)(v13 + 20) = 0;
          raw_spin_unlock_irqrestore(a1 + 1644, v24);
          result = 4294967292LL;
        }
        else
        {
          raw_spin_unlock_irqrestore(a1 + 1644, v24);
          v25 = *(_DWORD *)(v13 + 56);
          kfree(v13);
          result = v25;
        }
      }
      else
      {
        result = 0;
      }
      _X9 = (unsigned int *)(a1 + 2920);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v37 = __ldxr(_X9);
        v38 = v37 - 1;
      }
      while ( __stlxr(v38, _X9) );
      __dmb(0xBu);
      if ( (v38 & 0x80000000) != 0 )
      {
        __break(0x800u);
      }
      else if ( !v38 )
      {
        v26 = result;
        ipc_log_string(
          icnss_ipc_log_long_context,
          "icnss2: PM relax, state: 0x%lx, count: %d\n",
          *(_QWORD *)(a1 + 1832),
          *(_DWORD *)(a1 + 2920));
        pm_relax(*(_QWORD *)(a1 + 8) + 16LL);
        ++*(_DWORD *)(a1 + 2560);
        return v26;
      }
    }
    else
    {
      return 4294967284LL;
    }
  }
  return result;
}
