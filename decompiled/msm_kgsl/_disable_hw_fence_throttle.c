__int64 __fastcall disable_hw_fence_throttle(_QWORD *a1, char a2)
{
  __int64 v5; // x23
  __int64 result; // x0
  unsigned int v7; // w8
  unsigned int v9; // w10
  unsigned __int64 v16; // x10
  unsigned __int64 v19; // x10
  unsigned __int64 v22; // x10

  _X21 = (unsigned int *)a1 + 5103;
  raw_spin_lock(a1 + 2894);
  a1[2898] = 0;
  _X21[695] = 0;
  v5 = a1[2900];
  if ( (v5 & 2) == 0 )
  {
    if ( (a2 & 1) == 0 )
      goto LABEL_5;
    goto LABEL_4;
  }
  _X8 = a1 + 2900;
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  _X8 = a1 + 2900;
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  if ( (a2 & 1) != 0 )
  {
LABEL_4:
    _X8 = a1 + 2900;
    __asm { PRFM            #0x11, [X8] }
    do
      v22 = __ldxr(_X8);
    while ( __stxr(v22 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  }
LABEL_5:
  result = raw_spin_unlock(a1 + 2894);
  if ( (v5 & 2) != 0 )
  {
    v7 = *_X21;
    while ( (int)(v7 - 1) >= 0 )
    {
      __asm { PRFM            #0x11, [X21] }
      while ( 1 )
      {
        v9 = __ldxr(_X21);
        if ( v9 != v7 )
          break;
        if ( !__stlxr(v7 - 1, _X21) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v9 == v7;
      v7 = v9;
      if ( _ZF )
        goto LABEL_16;
    }
    _warn_printk("GPU halt refcount unbalanced\n");
    __break(0x800u);
LABEL_16:
    kthread_queue_work(a1[3050], a1 + 3051);
    return _wake_up(a1 + 2895, 3, 0, 0);
  }
  return result;
}
