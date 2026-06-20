__int64 __fastcall rmnet_perf_ingress_rx_handler_tcp(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 v3; // x0
  unsigned int v4; // w11
  int v5; // w12
  int v6; // w9
  unsigned int v7; // w8
  char v8; // w13
  unsigned int v9; // w21
  __int64 v10; // x10
  unsigned __int64 v11; // x20
  _QWORD v12[6]; // [xsp+0h] [xbp-30h] BYREF

  v12[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v12, 0, 40);
  result = rmnet_perf_ingress_handle_tcp_common(a1, (__int64)v12);
  if ( (result & 1) != 0 )
  {
    _rcu_read_lock();
    v3 = rmnet_perf_quickack_tuple_find((__int64)v12, a1, 0);
    if ( v3 )
    {
      if ( jiffies - *(_QWORD *)(v3 + 72) <= 0x1F4u )
      {
        v4 = *(_DWORD *)(*(_QWORD *)(a1 + 216) + *(unsigned __int16 *)(a1 + 182) + 4LL);
        v5 = *(_DWORD *)(v3 + 80);
        v6 = *(_DWORD *)(v3 + 84);
        v7 = *(_DWORD *)(v3 + 92);
        v8 = *(_BYTE *)(v3 + 100);
        *(_QWORD *)(v3 + 72) = jiffies;
        if ( (v8 & 1) == 0 )
        {
          v9 = bswap32(v4);
          if ( ((v5 - v9) & 0x80000000) != 0 )
          {
            v10 = *(_QWORD *)(a1 + 216) + *(unsigned __int16 *)(a1 + 182);
            if ( v9
               - v6
               + *(_DWORD *)(a1 + 224)
               + *(_DWORD *)(a1 + 112)
               - (_DWORD)v10
               - ((*(unsigned __int16 *)(v10 + 12) >> 2) & 0x3C) > v7 )
            {
              v11 = v3;
              rmnet_perf_quickack_force();
              v3 = v11;
            }
            *(_DWORD *)(v3 + 80) = v9;
          }
        }
      }
    }
    result = _rcu_read_unlock();
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
