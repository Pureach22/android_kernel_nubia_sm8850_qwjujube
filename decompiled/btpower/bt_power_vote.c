__int64 bt_power_vote()
{
  __int64 v0; // x0
  __int64 v1; // x22
  int v2; // w24
  __int64 v3; // x25
  int v4; // w0
  __int64 v5; // x0

  mutex_lock(pwr_data + 720);
  v0 = skb_dequeue(pwr_data + 696);
  if ( !v0 )
    return mutex_unlock(pwr_data + 720);
  v1 = v0;
  v2 = 0;
  while ( 1 )
  {
    v3 = **(unsigned int **)(v1 + 224);
    skb_pull(v1, 4);
    mutex_unlock(pwr_data + 720);
    mutex_lock(pwr_data + 224);
    mutex_unlock(pwr_data + 224);
    mutex_lock(pwr_data + 224);
    mutex_unlock(pwr_data + 224);
    mutex_lock(pwr_data + 224);
    mutex_unlock(pwr_data + 224);
    mutex_lock(pwr_data + 224);
    mutex_unlock(pwr_data + 224);
    printk(&unk_10FC7, "bt_power_vote");
    if ( (v3 & 0xFFFFFFFD) == 1 )
    {
      v4 = (_DWORD)v3 == 1 ? 1 : 2;
      v2 = power_disable(v4);
    }
    else if ( (v3 & 0xFFFFFFFD) != 0 )
    {
      if ( (v3 & 0xFFFFFFFE) == 4 )
      {
        v2 = btpower_retenion(v3);
      }
      else if ( (unsigned int)(v3 - 6) <= 3 )
      {
        v2 = btpower_access_ctrl(v3);
        printk(&unk_10FF9, "bt_power_vote");
      }
    }
    else
    {
      v2 = btpower_on(v3);
    }
    mutex_lock(pwr_data + 224);
    mutex_unlock(pwr_data + 224);
    mutex_lock(pwr_data + 224);
    mutex_unlock(pwr_data + 224);
    mutex_lock(pwr_data + 224);
    mutex_unlock(pwr_data + 224);
    mutex_lock(pwr_data + 224);
    mutex_unlock(pwr_data + 224);
    v5 = printk(&unk_11877, "bt_power_vote");
    if ( (unsigned int)v3 >= 0xA )
      break;
    *(_DWORD *)(pwr_data + 4 * v3 + 624) = v2;
    sk_skb_reason_drop(0, v1, 2);
    _wake_up(pwr_data + 24LL * (unsigned int)v3 + 384, 1, 1, 0);
    mutex_lock(pwr_data + 720);
    v1 = skb_dequeue(pwr_data + 696);
    if ( !v1 )
      return mutex_unlock(pwr_data + 720);
  }
  __break(0x5512u);
  return bt_power_populate_dt_pinfo(v5);
}
