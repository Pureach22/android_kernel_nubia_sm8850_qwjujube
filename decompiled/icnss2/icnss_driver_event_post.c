__int64 __fastcall icnss_driver_event_post(__int64 a1, unsigned int a2, int a3, __int64 a4)
{
  __int64 v6; // x0
  const char *v9; // x2
  __int64 result; // x0
  __int64 v11; // x6
  unsigned __int64 StatusReg; // x21
  __int64 v13; // x1
  __int64 v14; // x21
  __int64 v15; // x0
  __int64 v16; // x2
  __int64 *v17; // x1
  __int64 v18; // x9
  __int64 v19; // x1
  __int64 v20; // x0
  int v21; // w22
  __int64 v22; // x1
  unsigned int v23; // w20
  unsigned int v24; // w20
  unsigned int v31; // w8
  unsigned int v32; // w8
  unsigned int v35; // w8
  unsigned int v36; // w8

  if ( !a1 )
    return 4294967277LL;
  v6 = icnss_ipc_log_context;
  if ( a2 > 0x12 )
    v9 = "UNKNOWN";
  else
    v9 = off_A8830[a2];
  v11 = *(_QWORD *)(a1 + 1832);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v6,
    "icnss2: Posting event: %s(%d), %s, flags: 0x%x, state: 0x%lx\n",
    v9,
    a2,
    (const char *)(StatusReg + 2320),
    a3,
    v11);
  if ( a2 >= 0x12 )
  {
    printk("%sicnss2: Invalid Event type: %d, can't post", byte_130B32, a2);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Invalid Event type: %d, can't post", (const char *)&unk_12DBF3, a2);
    return 4294967274LL;
  }
  else
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0
      || *(_DWORD *)(StatusReg + 16)
      || (_ReadStatusReg(DAIF) & 0x80) != 0
      || *(_DWORD *)(StatusReg + 1412) )
    {
      v13 = 2336;
    }
    else
    {
      v13 = 3520;
    }
    v14 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, v13, 72);
    if ( v14 )
    {
      _X9 = (unsigned int *)(a1 + 2920);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v31 = __ldxr(_X9);
        v32 = v31 + 1;
      }
      while ( __stlxr(v32, _X9) );
      __dmb(0xBu);
      if ( v32 == 1 )
      {
        ipc_log_string(
          icnss_ipc_log_long_context,
          "icnss2: PM stay awake, state: 0x%lx, count: %d\n",
          *(_QWORD *)(a1 + 1832),
          *(_DWORD *)(a1 + 2920));
        pm_stay_awake(*(_QWORD *)(a1 + 8) + 16LL);
        ++*(_DWORD *)(a1 + 2556);
      }
      *(_QWORD *)(v14 + 64) = a4;
      *(_DWORD *)(v14 + 16) = a2;
      *(_DWORD *)(v14 + 24) = 0;
      _init_swait_queue_head(v14 + 32, "&x->wait", &init_completion___key);
      *(_DWORD *)(v14 + 56) = 2989;
      *(_BYTE *)(v14 + 20) = a3 & 1;
      v15 = raw_spin_lock_irqsave(a1 + 1640);
      v16 = a1 + 1608;
      v17 = *(__int64 **)(a1 + 1616);
      v18 = v15;
      if ( v14 == a1 + 1608 || v17 == (__int64 *)v14 || *v17 != v16 )
      {
        _list_add_valid_or_report(v14, v17);
      }
      else
      {
        *(_QWORD *)(a1 + 1616) = v14;
        *(_QWORD *)v14 = v16;
        *(_QWORD *)(v14 + 8) = v17;
        *v17 = v14;
      }
      raw_spin_unlock_irqrestore(a1 + 1640, v18);
      v19 = *(_QWORD *)(a1 + 1776);
      ++*(_DWORD *)(a1 + 8LL * a2 + 2156);
      queue_work_on(32, v19, a1 + 1680);
      if ( (a3 & 1) != 0 )
      {
        v20 = v14 + 24;
        if ( (a3 & 2) != 0 )
        {
          wait_for_completion(v20);
          v21 = 0;
        }
        else
        {
          v21 = wait_for_completion_interruptible(v20);
        }
        ipc_log_string(
          icnss_ipc_log_context,
          "icnss2: Completed event: %s(%d), state: 0x%lx, ret: %d/%d\n",
          off_A8410[a2],
          a2,
          *(_QWORD *)(a1 + 1832),
          v21,
          *(_DWORD *)(v14 + 56));
        v22 = raw_spin_lock_irqsave(a1 + 1640);
        if ( v21 == -512 && *(_DWORD *)(v14 + 56) == 2989 )
        {
          *(_BYTE *)(v14 + 20) = 0;
          raw_spin_unlock_irqrestore(a1 + 1640, v22);
          result = 4294967292LL;
        }
        else
        {
          raw_spin_unlock_irqrestore(a1 + 1640, v22);
          v23 = *(_DWORD *)(v14 + 56);
          kfree(v14);
          result = v23;
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
        v35 = __ldxr(_X9);
        v36 = v35 - 1;
      }
      while ( __stlxr(v36, _X9) );
      __dmb(0xBu);
      if ( (v36 & 0x80000000) != 0 )
      {
        __break(0x800u);
      }
      else if ( !v36 )
      {
        v24 = result;
        ipc_log_string(
          icnss_ipc_log_long_context,
          "icnss2: PM relax, state: 0x%lx, count: %d\n",
          *(_QWORD *)(a1 + 1832),
          *(_DWORD *)(a1 + 2920));
        pm_relax(*(_QWORD *)(a1 + 8) + 16LL);
        ++*(_DWORD *)(a1 + 2560);
        return v24;
      }
    }
    else
    {
      return 4294967284LL;
    }
  }
  return result;
}
