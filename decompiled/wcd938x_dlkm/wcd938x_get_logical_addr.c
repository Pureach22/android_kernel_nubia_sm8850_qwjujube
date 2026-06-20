__int64 __fastcall wcd938x_get_logical_addr(__int64 a1)
{
  int v2; // w8
  int v3; // w20
  __int64 result; // x0
  _BYTE v5[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = -19;
  v5[0] = 0;
  do
  {
    v3 = v2;
    usleep_range_state(4000, 4010, 2);
    result = swr_get_logical_dev_num(a1, *(_QWORD *)(a1 + 984), v5);
    if ( !(_DWORD)result )
      break;
    v2 = v3 + 1;
  }
  while ( v3 );
  if ( (_DWORD)result )
  {
    result = __ratelimit(&wcd938x_get_logical_addr__rs, "wcd938x_get_logical_addr");
    if ( (_DWORD)result )
      result = dev_err(
                 a1 + 72,
                 "%s get devnum %d for dev addr %llx failed\n",
                 "wcd938x_get_logical_addr",
                 v5[0],
                 *(_QWORD *)(a1 + 984));
  }
  *(_BYTE *)(a1 + 64) = v5[0];
  _ReadStatusReg(SP_EL0);
  return result;
}
