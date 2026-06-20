__int64 __fastcall glink_pkt_open(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  int v4; // w22
  unsigned __int64 StatusReg; // x24
  __int64 v8; // x1
  unsigned int v14; // w8
  int v16; // w8

  v2 = *(_QWORD *)(a1 + 656);
  v4 = _msecs_to_jiffies((unsigned int)(1000 * *(_DWORD *)(v2 + 616)));
  _X19 = (unsigned int *)(v2 + 216);
  __asm { PRFM            #0x11, [X19] }
  do
    v14 = __ldxr(_X19);
  while ( __stxr(v14 + 1, _X19) );
  if ( v14 )
  {
    if ( (((v14 + 1) | v14) & 0x80000000) == 0 )
      goto LABEL_3;
    v8 = 1;
  }
  else
  {
    v8 = 2;
  }
  refcount_warn_saturate(v2 + 216, v8);
LABEL_3:
  get_device(v2 - 912);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    glink_pkt_ilctxt,
    "[%s]: begin for %s by %s:%d ref_cnt[%d]\n",
    "glink_pkt_open",
    *(const char **)(v2 + 600),
    (const char *)(StatusReg + 2320),
    *(_DWORD *)(StatusReg + 1800),
    *(_DWORD *)(v2 + 216));
  if ( *(_BYTE *)(v2 + 317) == 1 )
  {
    mutex_lock(v2 + 320);
    if ( (*(_BYTE *)(v2 + 584) & 1) == 0 && !(unsigned int)_register_rpmsg_driver(v2 + 368, &_this_module) )
      *(_BYTE *)(v2 + 584) = 1;
    mutex_unlock(v2 + 320);
  }
  if ( (int)wait_for_completion_interruptible_timeout(v2 + 184, v4) <= 0 )
  {
    if ( *(_BYTE *)(v2 + 317) == 1 )
    {
      mutex_lock(v2 + 320);
      if ( *(_BYTE *)(v2 + 584) == 1 )
      {
        unregister_rpmsg_driver(v2 + 368);
        *(_BYTE *)(v2 + 584) = 0;
      }
      mutex_unlock(v2 + 320);
    }
    __asm { PRFM            #0x11, [X19] }
    do
      v16 = __ldxr(_X19);
    while ( __stlxr(v16 - 1, _X19) );
    if ( v16 <= 1 )
      refcount_warn_saturate(v2 + 216, 4);
    put_device(v2 - 912);
    ipc_log_string(
      glink_pkt_ilctxt,
      "[%s]: timeout for %s by %s:%d\n",
      "glink_pkt_open",
      *(const char **)(v2 + 600),
      (const char *)(StatusReg + 2320),
      *(_DWORD *)(StatusReg + 1800));
    return 4294967186LL;
  }
  else
  {
    *(_QWORD *)(a2 + 32) = v2 - 912;
    ipc_log_string(
      glink_pkt_ilctxt,
      "[%s]: end for %s by %s:%d ref_cnt[%d]\n",
      "glink_pkt_open",
      *(const char **)(v2 + 600),
      (const char *)(StatusReg + 2320),
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(v2 + 216));
    return 0;
  }
}
