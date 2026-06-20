__int64 adci_shutdown()
{
  unsigned int v0; // w0
  unsigned int v1; // w19
  int v3; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v4[4]; // [xsp+10h] [xbp-20h] BYREF

  v4[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  memset(v4, 0, 24);
  v0 = si_object_do_invoke(oic, 1u, 9, (__int64)v4, &v3);
  v1 = v0;
  if ( v0 | v3 )
    printk(&unk_B503, v0);
  kthread_stop(adci_task);
  _ReadStatusReg(SP_EL0);
  return v1;
}
