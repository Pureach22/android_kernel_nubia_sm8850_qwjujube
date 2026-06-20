__int64 rmnet_aps_adjust_prio()
{
  _QWORD *v0; // x8
  unsigned __int64 v1; // x10
  __int64 v2; // x11
  char v3; // w20
  unsigned __int64 v4; // x12
  int v5; // w10
  unsigned int v6; // w13
  int v7; // w12
  __int64 v8; // x12
  __int64 v9; // x13
  int v10; // w11
  unsigned int v11; // w14
  int v12; // w13
  __int64 result; // x0

  mutex_lock(&rmnet_aps_mutex);
  if ( rmnet_aps_active != 1 )
    return mutex_unlock(&rmnet_aps_mutex);
  raw_spin_lock_bh(&rmnet_aps_lock);
  list_sort(0, &aps_flow_list, rmnet_aps_rate_cmp);
  v0 = aps_flow_list;
  if ( aps_flow_list == (_UNKNOWN *)&aps_flow_list )
  {
    raw_spin_unlock_bh(&rmnet_aps_lock);
    return mutex_unlock(&rmnet_aps_mutex);
  }
  v1 = 0;
  v2 = 0;
  v3 = 0;
  do
  {
    if ( *((_BYTE *)v0 + 33) )
    {
      v4 = v0[8] + v1;
      if ( v4 >> 19 > 0x176 )
      {
        v7 = *((_DWORD *)v0 + 12);
        *((_BYTE *)v0 + 72) = 0;
        v6 = v7 & 0xFFFFFEFF;
      }
      else
      {
        v5 = *((_DWORD *)v0 + 12);
        *((_BYTE *)v0 + 72) = 1;
        v6 = v5 | 0x100;
        v1 = v4;
      }
      *((_DWORD *)v0 + 12) = v6;
    }
    v8 = v0[8];
    if ( *((_BYTE *)v0 + 34) )
    {
      v9 = v8 + v2;
      if ( (unsigned __int64)(v8 + v2) >> 20 > 0x4A )
      {
        v12 = *((_DWORD *)v0 + 12);
        *((_BYTE *)v0 + 73) = 0;
        v11 = v12 & 0xFFFFFDFF;
      }
      else
      {
        v10 = *((_DWORD *)v0 + 12);
        *((_BYTE *)v0 + 73) = 1;
        v11 = v10 | 0x200;
        v2 = v9;
      }
      *((_DWORD *)v0 + 12) = v11;
    }
    if ( v8 )
    {
      v3 = 1;
      v0[8] = 0;
    }
    v0 = (_QWORD *)*v0;
  }
  while ( v0 != &aps_flow_list );
  raw_spin_unlock_bh(&rmnet_aps_lock);
  result = mutex_unlock(&rmnet_aps_mutex);
  if ( (v3 & 1) != 0 )
    return queue_delayed_work_on(32, system_wq, &rmnet_aps_rate_work, 750);
  return result;
}
