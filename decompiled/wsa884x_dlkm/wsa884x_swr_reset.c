__int64 __fastcall wsa884x_swr_reset(_QWORD *a1)
{
  __int64 v2; // x20
  __int64 result; // x0
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[2];
  v4[0] = 0;
  if ( (unsigned int)swr_get_logical_dev_num(v2, *(_QWORD *)(v2 + 984), v4) )
  {
    usleep_range_state(1000, 1100, 2);
    if ( (unsigned int)swr_get_logical_dev_num(v2, *(_QWORD *)(v2 + 984), v4) )
    {
      usleep_range_state(1000, 1100, 2);
      if ( (unsigned int)swr_get_logical_dev_num(v2, *(_QWORD *)(v2 + 984), v4) )
      {
        usleep_range_state(1000, 1100, 2);
        if ( (unsigned int)swr_get_logical_dev_num(v2, *(_QWORD *)(v2 + 984), v4) )
        {
          usleep_range_state(1000, 1100, 2);
          if ( (unsigned int)swr_get_logical_dev_num(v2, *(_QWORD *)(v2 + 984), v4) )
          {
            usleep_range_state(1000, 1100, 2);
            swr_get_logical_dev_num(v2, *(_QWORD *)(v2 + 984), v4);
          }
        }
      }
    }
  }
  *(_BYTE *)(v2 + 64) = v4[0];
  mutex_lock(a1 + 16);
  regcache_mark_dirty(*a1);
  regcache_sync(*a1);
  result = mutex_unlock(a1 + 16);
  _ReadStatusReg(SP_EL0);
  return result;
}
