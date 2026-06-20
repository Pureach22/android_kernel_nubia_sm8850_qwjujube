__int64 __fastcall adreno_dispatcher_idle(__int64 a1)
{
  unsigned int v3; // w20
  unsigned int v4; // w0
  unsigned int v5; // w8
  unsigned int v7; // w10
  unsigned int v14; // w8

  if ( *(_DWORD *)(a1 + 11120) == 2 )
  {
    if ( (mutex_is_locked(a1 + 19760) & 1) != 0 )
    {
      __break(0x800u);
      return (unsigned int)-35;
    }
    else
    {
      _X21 = (unsigned int *)(a1 + 20412);
      __asm { PRFM            #0x11, [X21] }
      do
        v14 = __ldxr(_X21);
      while ( __stxr(v14 + 1, _X21) );
      rt_mutex_unlock(a1 + 11088);
      kthread_flush_worker(*(_QWORD *)(a1 + 24400));
      __dmb(9u);
      if ( *(_DWORD *)(a1 + 24448) )
      {
        v3 = -35;
      }
      else
      {
        v4 = wait_for_completion_timeout(a1 + 20256, 5000);
        if ( v4 )
        {
          if ( (v4 & 0x80000000) != 0 )
          {
            v3 = v4;
            dev_err(*(_QWORD *)a1, "Dispatcher halt failed %d\n", v4);
          }
          else
          {
            v3 = 0;
          }
        }
        else
        {
          _warn_printk("Dispatcher halt timeout\n");
          __break(0x800u);
          v3 = -110;
        }
        __dmb(9u);
        if ( *(_DWORD *)(a1 + 24448) )
          v3 = -35;
      }
      rt_mutex_lock(a1 + 11088);
      v5 = *_X21;
      while ( (int)(v5 - 1) >= 0 )
      {
        __asm { PRFM            #0x11, [X21] }
        while ( 1 )
        {
          v7 = __ldxr(_X21);
          if ( v7 != v5 )
            break;
          if ( !__stlxr(v5 - 1, _X21) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v7 == v5;
        v5 = v7;
        if ( _ZF )
          goto LABEL_25;
      }
      _warn_printk("GPU halt refcount unbalanced\n");
      __break(0x800u);
LABEL_25:
      kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
    }
  }
  else
  {
    return 0;
  }
  return v3;
}
