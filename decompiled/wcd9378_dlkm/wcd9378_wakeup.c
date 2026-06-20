__int64 __fastcall wcd9378_wakeup(__int64 a1, char a2)
{
  __int64 v4; // x0
  unsigned int v5; // w0
  unsigned int v6; // w20
  void *v8; // x0

  if ( !a1 )
  {
    v8 = &unk_13A71;
LABEL_10:
    printk(v8, "wcd9378_wakeup");
    return (unsigned int)-22;
  }
  if ( !*(_QWORD *)(a1 + 64) )
  {
    v8 = &unk_13EA9;
    goto LABEL_10;
  }
  mutex_lock(a1 + 184);
  v4 = *(_QWORD *)(a1 + 64);
  if ( (a2 & 1) != 0 )
    v5 = swr_device_wakeup_vote(v4);
  else
    v5 = swr_device_wakeup_unvote(v4);
  v6 = v5;
  mutex_unlock(a1 + 184);
  return v6;
}
