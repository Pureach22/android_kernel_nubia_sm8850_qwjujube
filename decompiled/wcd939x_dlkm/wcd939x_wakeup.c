__int64 __fastcall wcd939x_wakeup(__int64 a1, char a2)
{
  __int64 v4; // x0
  unsigned int v5; // w0
  void *v6; // x0
  unsigned int v8; // w20

  if ( !a1 )
  {
    if ( !(unsigned int)__ratelimit(&wcd939x_wakeup__rs, "wcd939x_wakeup") )
      return 4294967274LL;
    v6 = &unk_19152;
LABEL_13:
    printk(v6, "wcd939x_wakeup");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(a1 + 48) )
  {
    if ( !(unsigned int)__ratelimit(&wcd939x_wakeup__rs_45, "wcd939x_wakeup") )
      return 4294967274LL;
    v6 = &unk_19691;
    goto LABEL_13;
  }
  mutex_lock(a1 + 152);
  v4 = *(_QWORD *)(a1 + 48);
  if ( (a2 & 1) != 0 )
    v5 = swr_device_wakeup_vote(v4);
  else
    v5 = swr_device_wakeup_unvote(v4);
  v8 = v5;
  mutex_unlock(a1 + 152);
  return v8;
}
