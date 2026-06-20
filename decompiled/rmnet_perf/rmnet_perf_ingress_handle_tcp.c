__int64 __fastcall rmnet_perf_ingress_handle_tcp(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  _QWORD v4[6]; // [xsp+0h] [xbp-30h] BYREF

  v4[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v4, 0, 40);
  result = rmnet_perf_ingress_handle_tcp_common(a1, v4);
  if ( (result & 1) != 0 )
  {
    _rcu_read_lock();
    v3 = rmnet_perf_quickack_tuple_find(v4, a1, 0);
    if ( v3 && jiffies - *(_QWORD *)(v3 + 72) <= 0x1F4u )
    {
      if ( *(_BYTE *)(v3 + 100) == 1 )
      {
        *(_BYTE *)(a1 + 42) = 1;
      }
      else
      {
        *(_DWORD *)(a1 + 52) = *(_DWORD *)(v3 + 80) - *(_DWORD *)(v3 + 84);
        *(_DWORD *)(a1 + 56) = *(_DWORD *)(v3 + 92);
        *(_DWORD *)(a1 + 60) = *(_DWORD *)(v3 + 96);
      }
    }
    result = _rcu_read_unlock();
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
