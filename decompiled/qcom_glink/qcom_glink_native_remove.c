__int64 __fastcall qcom_glink_native_remove(_QWORD *a1)
{
  __int64 v2; // x20
  __int64 v3; // x20
  __int64 next; // x0
  _QWORD *v5; // x0
  _QWORD *v6; // x21
  int v7; // w0
  __int64 j; // x0
  int v15; // w8
  __int64 k; // x0
  int v19; // w8
  __int64 result; // x0
  int i; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = raw_spin_lock_irqsave(a1 + 19);
  *((_BYTE *)a1 + 249) = 1;
  _wake_up(a1 + 28, 3, 0, 0);
  raw_spin_unlock_irqrestore(a1 + 19, v2);
  v3 = raw_spin_lock_irqsave((char *)a1 + 156);
  for ( i = 0; ; ++i )
  {
    next = idr_get_next(a1 + 20, &i);
    if ( !next )
      break;
    _wake_up(next + 400, 3, 0, 0);
  }
  raw_spin_unlock_irqrestore((char *)a1 + 156, v3);
  cancel_work_sync(a1 + 12);
  v5 = (_QWORD *)a1[17];
  if ( v5 != a1 + 17 )
  {
    do
    {
      v6 = (_QWORD *)*v5;
      kfree(v5);
      v5 = v6;
    }
    while ( v6 != a1 + 17 );
  }
  v7 = device_for_each_child(*a1, 0, qcom_glink_remove_device);
  if ( v7 )
    dev_warn(*a1, "Can't remove GLINK devices: %d\n", v7);
  i = 0;
  for ( j = idr_get_next(a1 + 20, &i); j; j = idr_get_next(a1 + 20, &i) )
  {
    _X0 = (unsigned int *)(j + 120);
    __asm { PRFM            #0x11, [X0] }
    do
      v15 = __ldxr(_X0);
    while ( __stlxr(v15 - 1, _X0) );
    if ( v15 == 1 )
    {
      __dmb(9u);
      qcom_glink_channel_release(_X0);
    }
    else if ( v15 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    ++i;
  }
  i = 0;
  for ( k = idr_get_next(a1 + 23, &i); k; k = idr_get_next(a1 + 23, &i) )
  {
    _X0 = (unsigned int *)(k + 120);
    __asm { PRFM            #0x11, [X0] }
    do
      v19 = __ldxr(_X0);
    while ( __stlxr(v19 - 1, _X0) );
    if ( v19 == 1 )
    {
      __dmb(9u);
      qcom_glink_channel_release(_X0);
    }
    else if ( v19 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    ++i;
  }
  idr_destroy(a1 + 20);
  idr_destroy(a1 + 23);
  kthread_flush_worker(a1 + 4);
  result = kthread_stop(a1[11]);
  _ReadStatusReg(SP_EL0);
  return result;
}
