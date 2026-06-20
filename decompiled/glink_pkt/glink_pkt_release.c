__int64 __fastcall glink_pkt_release(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x20
  int v12; // w8

  v1 = *(_QWORD *)(a1 + 656);
  v2 = glink_pkt_ilctxt;
  StatusReg = _ReadStatusReg(SP_EL0);
  _X20 = (unsigned int *)(v1 + 216);
  ipc_log_string(
    v2,
    "[%s]: for %s by %s:%d ref_cnt[%d]\n",
    "glink_pkt_release",
    *(const char **)(v1 + 600),
    (const char *)(StatusReg + 2320),
    *(_DWORD *)(StatusReg + 1800),
    *(_DWORD *)(v1 + 216));
  __asm { PRFM            #0x11, [X20] }
  do
    v12 = __ldxr(_X20);
  while ( __stlxr(v12 - 1, _X20) );
  if ( v12 <= 1 )
    refcount_warn_saturate(v1 + 216, 4);
  if ( *_X20 == 1 )
  {
    glink_pkt_clear_queues(v1 - 912);
    v5 = raw_spin_lock_irqsave(v1 + 236);
    *(_DWORD *)(v1 + 312) = 0;
    _wake_up(v1 + 288, 1, 1, 0);
    raw_spin_unlock_irqrestore(v1 + 236, v5);
    if ( *(_BYTE *)(v1 + 317) == 1 )
    {
      mutex_lock(v1 + 320);
      if ( *(_BYTE *)(v1 + 584) == 1 )
      {
        unregister_rpmsg_driver(v1 + 368);
        *(_BYTE *)(v1 + 584) = 0;
      }
      mutex_unlock(v1 + 320);
    }
  }
  put_device(v1 - 912);
  return 0;
}
