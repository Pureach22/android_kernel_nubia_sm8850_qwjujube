__int64 adci_fn()
{
  unsigned int v0; // w0
  __int64 v1; // x1
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x0
  unsigned int v5; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v6[4]; // [xsp+10h] [xbp-20h] BYREF

  v6[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  memset(v6, 0, 24);
  v0 = si_object_do_invoke(oic, 1u, 8, (__int64)v6, &v5);
  if ( v0 )
  {
    printk(&unk_B534, v0);
  }
  else if ( v5 == 2 )
  {
    printk(&unk_B5D7, v1);
  }
  if ( (((__int64 (*)(void))kthread_should_stop)() & 1) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_DWORD *)(StatusReg + 48) = 2;
    __dmb(0xBu);
    if ( (((__int64 (*)(void))kthread_should_stop)() & 1) == 0 )
    {
      do
      {
        v3 = schedule();
        *(_DWORD *)(StatusReg + 48) = 2;
        __dmb(0xBu);
      }
      while ( (kthread_should_stop(v3) & 1) == 0 );
    }
    *(_DWORD *)(StatusReg + 48) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
