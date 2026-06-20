__int64 __fastcall wsa883x_event_notify(__int64 a1, __int16 a2)
{
  _QWORD *v2; // x21
  int v4; // w0
  int active; // w0
  __int64 v6; // x20
  __int64 v7; // x19
  __int64 result; // x0
  _QWORD *v9; // x20
  unsigned __int64 v16; // x9
  _BYTE v17[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v2 = (_QWORD *)(a1 - 312);
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == 312 )
  {
    result = 4294967274LL;
  }
  else
  {
    switch ( a2 )
    {
      case 6:
        if ( (*(_QWORD *)(a1 + 64) & 1) != 0 )
        {
          _X8 = (unsigned __int64 *)(a1 + 64);
          __asm { PRFM            #0x11, [X8] }
          do
            v16 = __ldxr(_X8);
          while ( __stxr(v16 | 4, _X8) );
        }
        break;
      case 5:
        if ( (*(_QWORD *)(a1 + 64) & 1) != 0 )
        {
          v9 = (_QWORD *)(a1 - 288);
          snd_soc_component_update_bits(*(_QWORD *)(a1 - 288), 13387, 1, 1);
          snd_soc_component_update_bits(*v9, 13328, 1, 1);
          if ( (*(_BYTE *)(a1 - 276) & 1) == 0 )
          {
            wcd_enable_irq(a1 - 96, 5);
            *(_BYTE *)(a1 - 276) = 1;
          }
          usleep_range_state(3000, 3100, 2);
          if ( *(_BYTE *)(a1 - 280) == 1 && (*(_QWORD *)(a1 + 88) & 1) != 0 )
          {
            snd_soc_component_update_bits(*v9, 13421, 1, 0);
            usleep_range_state(5000, 5050, 2);
          }
        }
        break;
      case 4:
        v4 = msm_cdc_pinctrl_select_sleep_state(*(_QWORD *)(a1 - 136));
        if ( v4 )
        {
          dev_err(*(_QWORD *)(a1 - 304), "%s: Failed to turn state %d; ret=%d\n", "wsa883x_gpio_ctrl", 0, v4);
          dev_err(*(_QWORD *)(a1 - 304), "%s: Failed to disable gpio\n", "wsa883x_swr_down");
        }
        usleep_range_state(500, 510, 2);
        active = msm_cdc_pinctrl_select_active_state(*(_QWORD *)(a1 - 136));
        if ( active )
        {
          dev_err(*(_QWORD *)(a1 - 304), "%s: Failed to turn state %d; ret=%d\n", "wsa883x_gpio_ctrl", 1, active);
          dev_err(*(_QWORD *)(a1 - 304), "%s: Failed to enable gpio\n", "wsa883x_swr_up");
        }
        usleep_range_state(20000, 20010, 2);
        v17[0] = 0;
        v6 = *(_QWORD *)(a1 - 296);
        if ( (unsigned int)swr_get_logical_dev_num(v6, *(_QWORD *)(v6 + 984), v17) )
        {
          usleep_range_state(1000, 1100, 2);
          if ( (unsigned int)swr_get_logical_dev_num(v6, *(_QWORD *)(v6 + 984), v17) )
          {
            usleep_range_state(1000, 1100, 2);
            if ( (unsigned int)swr_get_logical_dev_num(v6, *(_QWORD *)(v6 + 984), v17) )
            {
              usleep_range_state(1000, 1100, 2);
              if ( (unsigned int)swr_get_logical_dev_num(v6, *(_QWORD *)(v6 + 984), v17) )
              {
                usleep_range_state(1000, 1100, 2);
                if ( (unsigned int)swr_get_logical_dev_num(v6, *(_QWORD *)(v6 + 984), v17) )
                {
                  usleep_range_state(1000, 1100, 2);
                  swr_get_logical_dev_num(v6, *(_QWORD *)(v6 + 984), v17);
                }
              }
            }
          }
        }
        v7 = a1 - 208;
        *(_BYTE *)(v6 + 64) = v17[0];
        mutex_lock(v7);
        regcache_mark_dirty(*v2);
        regcache_sync(*v2);
        mutex_unlock(v7);
        break;
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
