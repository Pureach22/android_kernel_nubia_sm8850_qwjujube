__int64 __fastcall simple_amp_event_notify(__int64 a1, __int16 a2)
{
  __int64 v2; // x20
  int v4; // w0
  int v5; // w21
  int v6; // w0
  int v7; // w21
  __int64 v8; // x21
  __int64 result; // x0
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v2 = a1 - 192;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == 192 )
  {
    result = 4294967274LL;
  }
  else
  {
    if ( a2 == 4 )
    {
      v4 = gpiod_direction_output(*(_QWORD *)(a1 - 56), 1);
      if ( v4 < 0 )
      {
        v5 = v4;
        if ( (unsigned int)__ratelimit(&simple_amp_gpio_set__rs, "simple_amp_gpio_set") )
          dev_err(*(_QWORD *)(a1 - 184), "%s: failed to set GPIO: %d\n", "simple_amp_gpio_set", v5);
      }
      usleep_range_state(500, 510, 2);
      v6 = gpiod_direction_output(*(_QWORD *)(a1 - 56), 0);
      if ( v6 < 0 )
      {
        v7 = v6;
        if ( (unsigned int)__ratelimit(&simple_amp_gpio_set__rs, "simple_amp_gpio_set") )
          dev_err(*(_QWORD *)(a1 - 184), "%s: failed to set GPIO: %d\n", "simple_amp_gpio_set", v7);
      }
      usleep_range_state(20000, 20010, 2);
      v8 = *(_QWORD *)(a1 - 176);
      v10[0] = 0;
      if ( (unsigned int)swr_get_logical_dev_num(v8, *(_QWORD *)(v8 + 984), v10) )
      {
        usleep_range_state(1000, 1100, 2);
        if ( (unsigned int)swr_get_logical_dev_num(v8, *(_QWORD *)(v8 + 984), v10) )
        {
          usleep_range_state(1000, 1100, 2);
          if ( (unsigned int)swr_get_logical_dev_num(v8, *(_QWORD *)(v8 + 984), v10) )
          {
            usleep_range_state(1000, 1100, 2);
            if ( (unsigned int)swr_get_logical_dev_num(v8, *(_QWORD *)(v8 + 984), v10) )
            {
              usleep_range_state(1000, 1100, 2);
              if ( (unsigned int)swr_get_logical_dev_num(v8, *(_QWORD *)(v8 + 984), v10) )
              {
                usleep_range_state(1000, 1100, 2);
                swr_get_logical_dev_num(v8, *(_QWORD *)(v8 + 984), v10);
              }
            }
          }
        }
      }
      *(_BYTE *)(v8 + 64) = v10[0];
      *(_BYTE *)(*(_QWORD *)(a1 - 176) + 1010LL) = 0;
      *(_BYTE *)(*(_QWORD *)(a1 - 176) + 1011LL) = 0;
      simple_amp_func_configuration(v2);
      regcache_mark_dirty(*(_QWORD *)(a1 - 192));
      regcache_sync(*(_QWORD *)(a1 - 192));
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
