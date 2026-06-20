__int64 __fastcall qcedev_resume(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w0
  __int64 v3; // x3

  v1 = *(_QWORD *)(a1 + 168);
  if ( v1 )
  {
    mutex_lock(&qcedev_sent_bw_req);
    if ( *(_DWORD *)(v1 + 20) )
    {
      if ( !(unsigned int)qcedev_control_clocks(v1, 1) )
      {
        v2 = qce_set_irqs(*(_QWORD *)(v1 + 224), 1);
        if ( v2 )
        {
          printk(&unk_11E93, "qcedev_resume", v2, v3);
          qcedev_control_clocks(v1, 0);
        }
      }
    }
    mutex_unlock(&qcedev_sent_bw_req);
  }
  return 0;
}
