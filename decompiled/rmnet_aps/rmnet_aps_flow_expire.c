__int64 rmnet_aps_flow_expire()
{
  __int64 v0; // x21
  __int64 v1; // x1
  _QWORD *v2; // x8
  __int64 v3; // x19
  __int64 v5; // x9
  _UNKNOWN **v6; // x25
  int v7; // w26
  __int64 result; // x0
  __int64 v9; // [xsp+Ch] [xbp-14h] BYREF
  int v10; // [xsp+14h] [xbp-Ch]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = jiffies;
  mutex_lock(&rmnet_aps_mutex);
  if ( rmnet_aps_active == 1 )
  {
    raw_spin_lock_bh(&rmnet_aps_lock);
    v2 = aps_flow_list;
    if ( aps_flow_list != (_UNKNOWN *)&aps_flow_list )
    {
      v3 = v0;
      do
      {
        v5 = v2[7];
        v6 = (_UNKNOWN **)*v2;
        if ( v5 )
        {
          if ( v0 - v5 < 0 )
          {
            if ( v5 - v3 < 0 || v3 == v0 )
              v3 = v2[7];
          }
          else
          {
            v7 = *((_DWORD *)v2 + 5);
            rmnet_aps_remove_flow(v2 - 4, v1);
            if ( HIDWORD(aps_client_genl_info) )
            {
              v9 = 0x100000005LL;
              v10 = v7;
              if ( (unsigned int)rmnet_aps_send_msg((__int64)&aps_client_genl_info, 1u, 2u, 0xCu, (__int64)&v9, 0x820u) )
                HIDWORD(aps_client_genl_info) = 0;
            }
          }
        }
        v2 = v6;
      }
      while ( v6 != &aps_flow_list );
      if ( v3 != v0 )
        mod_timer(&rmnet_aps_timer);
    }
    raw_spin_unlock_bh(&rmnet_aps_lock);
  }
  result = mutex_unlock(&rmnet_aps_mutex);
  _ReadStatusReg(SP_EL0);
  return result;
}
