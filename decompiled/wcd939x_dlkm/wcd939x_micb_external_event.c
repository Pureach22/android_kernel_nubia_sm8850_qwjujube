__int64 __fastcall wcd939x_micb_external_event(__int64 a1, unsigned int a2, char a3)
{
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v6; // x8
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  unsigned int v11; // w19

  result = 4294967274LL;
  if ( a1 && a2 - 5 >= 0xFFFFFFFC )
  {
    v5 = *(_QWORD *)(a1 + 152);
    if ( v5 )
    {
      v6 = *(_QWORD *)(v5 + 48);
      if ( (a3 & 1) != 0 )
      {
        if ( v6 )
        {
          mutex_lock(v5 + 152);
          swr_device_wakeup_vote(*(_QWORD *)(v5 + 48));
          mutex_unlock(v5 + 152);
        }
        else if ( (unsigned int)__ratelimit(&wcd939x_wakeup__rs_45, "wcd939x_wakeup") )
        {
          printk(&unk_19691, "wcd939x_wakeup");
        }
        v8 = *(_QWORD *)(v5 + 16);
        v9 = a2;
        v10 = 2;
      }
      else
      {
        if ( v6 )
        {
          mutex_lock(v5 + 152);
          swr_device_wakeup_vote(*(_QWORD *)(v5 + 48));
          mutex_unlock(v5 + 152);
        }
        else if ( (unsigned int)__ratelimit(&wcd939x_wakeup__rs_45, "wcd939x_wakeup") )
        {
          printk(&unk_19691, "wcd939x_wakeup");
        }
        v8 = *(_QWORD *)(v5 + 16);
        v9 = a2;
        v10 = 3;
      }
      v11 = wcd939x_micbias_control(v8, v9, v10, 0);
      if ( *(_QWORD *)(v5 + 48) )
      {
        mutex_lock(v5 + 152);
        swr_device_wakeup_unvote(*(_QWORD *)(v5 + 48));
        mutex_unlock(v5 + 152);
      }
      else if ( (unsigned int)__ratelimit(&wcd939x_wakeup__rs_45, "wcd939x_wakeup") )
      {
        printk(&unk_19691, "wcd939x_wakeup");
      }
      return v11;
    }
    else
    {
      return 4294967274LL;
    }
  }
  return result;
}
