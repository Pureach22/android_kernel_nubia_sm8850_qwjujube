__int64 __fastcall wcd939x_get_logical_addr(__int64 a1)
{
  __int64 result; // x0
  bool v3; // w8
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  usleep_range_state(1000, 1010, 2);
  result = swr_get_logical_dev_num(a1, *(_QWORD *)(a1 + 984), v4);
  v3 = (_DWORD)result == 0;
  if ( (_DWORD)result )
  {
    usleep_range_state(1000, 1010, 2);
    result = swr_get_logical_dev_num(a1, *(_QWORD *)(a1 + 984), v4);
    v3 = (_DWORD)result == 0;
    if ( (_DWORD)result )
    {
      usleep_range_state(1000, 1010, 2);
      result = swr_get_logical_dev_num(a1, *(_QWORD *)(a1 + 984), v4);
      v3 = (_DWORD)result == 0;
      if ( (_DWORD)result )
      {
        usleep_range_state(1000, 1010, 2);
        result = swr_get_logical_dev_num(a1, *(_QWORD *)(a1 + 984), v4);
        v3 = (_DWORD)result == 0;
        if ( (_DWORD)result )
        {
          usleep_range_state(1000, 1010, 2);
          result = swr_get_logical_dev_num(a1, *(_QWORD *)(a1 + 984), v4);
          v3 = (_DWORD)result == 0;
        }
      }
    }
  }
  if ( !v3 )
  {
    result = __ratelimit(&wcd939x_get_logical_addr__rs, "wcd939x_get_logical_addr");
    if ( (_DWORD)result )
      result = dev_err(
                 a1 + 72,
                 "%s get devnum %d for dev addr %llx failed\n",
                 "wcd939x_get_logical_addr",
                 v4[0],
                 *(_QWORD *)(a1 + 984));
  }
  *(_BYTE *)(a1 + 64) = v4[0];
  _ReadStatusReg(SP_EL0);
  return result;
}
