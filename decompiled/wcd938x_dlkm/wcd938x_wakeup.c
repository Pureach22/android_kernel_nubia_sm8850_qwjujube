__int64 __fastcall wcd938x_wakeup(__int64 a1, char a2)
{
  __int64 v4; // x0
  unsigned int v5; // w0
  void *v6; // x0
  unsigned int v8; // w20

  if ( !a1 )
  {
    if ( !(unsigned int)__ratelimit(&wcd938x_wakeup__rs, "wcd938x_wakeup") )
      return 4294967274LL;
    v6 = &unk_12EB6;
LABEL_13:
    printk(v6, "wcd938x_wakeup");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(a1 + 48) )
  {
    if ( !(unsigned int)__ratelimit(&wcd938x_wakeup__rs_41, "wcd938x_wakeup") )
      return 4294967274LL;
    v6 = &unk_132E2;
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
