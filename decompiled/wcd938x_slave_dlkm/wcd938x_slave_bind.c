__int64 __fastcall wcd938x_slave_bind(__int64 a1)
{
  __int64 v2; // x20
  int logical_dev_num; // w0
  _BOOL4 v4; // w8
  int v5; // w0
  int v6; // w0
  int v7; // w0
  __int64 result; // x0
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  if ( !a1 || (v2 = a1 - 72, a1 == 72) )
  {
    if ( (unsigned int)__ratelimit(&wcd938x_slave_bind__rs, "wcd938x_slave_bind") )
      printk(&unk_6D79, "wcd938x_slave_bind");
    result = 4294967274LL;
  }
  else
  {
    usleep_range_state(100, 110, 2);
    logical_dev_num = swr_get_logical_dev_num(v2, *(_QWORD *)(a1 + 912), v9);
    v4 = logical_dev_num == 0;
    if ( logical_dev_num )
    {
      usleep_range_state(100, 110, 2);
      v5 = swr_get_logical_dev_num(v2, *(_QWORD *)(a1 + 912), v9);
      v4 = v5 == 0;
      if ( v5 )
      {
        usleep_range_state(100, 110, 2);
        v6 = swr_get_logical_dev_num(v2, *(_QWORD *)(a1 + 912), v9);
        v4 = v6 == 0;
        if ( v6 )
        {
          usleep_range_state(100, 110, 2);
          v7 = swr_get_logical_dev_num(v2, *(_QWORD *)(a1 + 912), v9);
          v4 = v7 == 0;
          if ( v7 )
          {
            usleep_range_state(100, 110, 2);
            v4 = swr_get_logical_dev_num(v2, *(_QWORD *)(a1 + 912), v9) == 0;
          }
        }
      }
    }
    if ( v4 )
    {
      result = 0;
      *(_BYTE *)(a1 - 8) = v9[0];
    }
    else
    {
      result = 4294966779LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
