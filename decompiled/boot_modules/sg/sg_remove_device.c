__int64 __fastcall sg_remove_device(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 lock_irqsave; // x21
  _QWORD *i; // x23
  __int64 v5; // x21
  unsigned int v12; // w8
  signed int v13; // w8
  int v15; // w8

  v1 = *(_QWORD *)(result + 152);
  if ( v1 )
  {
    v2 = *(_QWORD *)(result + 96);
    _X9 = (unsigned int *)(v1 + 112);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v12 = __ldxr(_X9);
      v13 = v12 + 1;
    }
    while ( __stlxr(v13, _X9) );
    __dmb(0xBu);
    if ( v13 <= 1 )
    {
      lock_irqsave = raw_read_lock_irqsave(v1 + 104);
      for ( i = *(_QWORD **)(v1 + 88); i != (_QWORD *)(v1 + 88); i = (_QWORD *)*i )
      {
        _wake_up(i + 3, 1, 0, 0);
        kill_fasync(i + 20, 29, 6);
      }
      _wake_up(v1 + 8, 1, 0, 0);
      raw_read_unlock_irqrestore(v1 + 104, lock_irqsave);
      sysfs_remove_link(v2, "generic");
      device_destroy(&sg_sysfs_class, *(_DWORD *)(v1 + 84) | 0x1500000u);
      cdev_del(*(_QWORD *)(v1 + 160));
      result = v1 + 168;
      *(_QWORD *)(v1 + 160) = 0;
      __asm { PRFM            #0x11, [X0] }
      do
        v15 = __ldxr((unsigned int *)result);
      while ( __stlxr(v15 - 1, (unsigned int *)result) );
      if ( v15 == 1 )
      {
        __dmb(9u);
        blk_put_queue(*(_QWORD *)(*(_QWORD *)v1 + 8LL));
        v5 = raw_write_lock_irqsave(&sg_index_lock);
        idr_remove(&sg_index_idr, *(unsigned int *)(v1 + 84));
        raw_write_unlock_irqrestore(&sg_index_lock, v5);
        return kfree(v1);
      }
      else if ( v15 <= 0 )
      {
        return refcount_warn_saturate();
      }
    }
  }
  return result;
}
