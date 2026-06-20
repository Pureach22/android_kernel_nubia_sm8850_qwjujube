__int64 __fastcall lpass_bt_swr_core_vote(__int64 *a1, char a2)
{
  __int64 v3; // x0
  __int64 v5; // x0
  __int64 v6; // x19
  void *v7; // x0

  if ( !a1 )
  {
    if ( !(unsigned int)__ratelimit(&lpass_bt_swr_core_vote__rs, "lpass_bt_swr_core_vote") )
      return 4294967274LL;
    v7 = &unk_71D3;
LABEL_18:
    printk(v7, "lpass_bt_swr_core_vote");
    return 4294967274LL;
  }
  if ( (a2 & 1) != 0 && (a1[19] & 1) == 0 )
  {
    v7 = &unk_721F;
    goto LABEL_18;
  }
  v3 = *a1;
  if ( (a2 & 1) != 0 )
  {
    _pm_runtime_resume(v3, 4);
    mutex_lock(a1 + 1);
    if ( *((_BYTE *)a1 + 152) == 1 && (!a1[20] || *((_DWORD *)a1 + 44)) && (!a1[21] || *((_DWORD *)a1 + 45)) )
    {
      mutex_unlock(a1 + 1);
      return 0;
    }
    else
    {
      mutex_unlock(a1 + 1);
      return 4294966774LL;
    }
  }
  else
  {
    v5 = _pm_runtime_suspend(v3, 13);
    v6 = *a1;
    *(_QWORD *)(v6 + 520) = ktime_get_mono_fast_ns(v5);
    return 0;
  }
}
