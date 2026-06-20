__int64 __fastcall wcd938x_event_notify(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v4; // x19
  int v5; // w8
  bool v6; // w8
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x19
  __int64 v10; // x8
  __int64 v11; // x0
  int v12; // w8
  __int64 v13; // x19
  unsigned __int64 v21; // x9
  unsigned __int64 v24; // x10
  unsigned __int64 v27; // x9
  unsigned __int64 v30; // x10
  unsigned __int64 v33; // x9
  unsigned __int64 v36; // x10
  unsigned __int64 v39; // x9
  unsigned __int64 v42; // x10

  v3 = *(_QWORD *)(a3 + 152);
  v4 = *(_QWORD *)(v3 + 16);
  if ( (unsigned __int16)a2 > 2u )
  {
    switch ( (unsigned __int16)a2 )
    {
      case 3u:
        v5 = *(unsigned __int8 *)(v3 + 3207);
        *(_BYTE *)(v3 + 3192) = 0;
        if ( v5 == 1 )
          blocking_notifier_call_chain(v3 + 3208, 0);
        *(_BYTE *)(*(_QWORD *)(v3 + 256) + 896LL) = 1;
        v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 256) + 112LL) + 88LL)
          && (snd_soc_component_read(v4, 12308) & 0x20) == 0;
        v8 = *(_QWORD *)(v3 + 256);
        *(_BYTE *)(v3 + 3206) = v6;
        wcd938x_mbhc_ssr_down(v8, v4);
        v9 = *(_QWORD *)v3;
        if ( *(_QWORD *)v3 )
        {
          v10 = *(_QWORD *)(v9 + 152);
          if ( v10 )
          {
            v11 = *(_QWORD *)(v10 + 24);
            if ( v11 )
            {
              if ( (unsigned int)msm_cdc_pinctrl_select_sleep_state(v11) )
              {
                if ( (unsigned int)__ratelimit(&wcd938x_reset_low__rs_419, "wcd938x_reset_low") )
                  dev_err(v9, "%s: wcd sleep state request fail!\n", "wcd938x_reset_low");
              }
              else
              {
                usleep_range_state(20, 30, 2);
              }
            }
            else if ( (unsigned int)__ratelimit(&wcd938x_reset_low__rs, "wcd938x_reset_low") )
            {
              dev_err(v9, "%s: reset gpio device node not specified\n", "wcd938x_reset_low");
            }
          }
        }
        break;
      case 4u:
        wcd938x_reset(*(_QWORD *)v3);
        usleep_range_state(10000, 10010, 2);
        wcd938x_get_logical_addr(*(_QWORD *)(v3 + 48));
        wcd938x_get_logical_addr(*(_QWORD *)(v3 + 40));
        wcd938x_init_reg(v4);
        regcache_mark_dirty(*(_QWORD *)(v3 + 32));
        regcache_sync(*(_QWORD *)(v3 + 32));
        v7 = *(_QWORD *)(v3 + 256);
        if ( (unsigned int)wcd938x_mbhc_post_ssr_init(v7, v4) )
        {
          if ( (unsigned int)__ratelimit(&wcd938x_event_notify__rs, "wcd938x_event_notify") )
            dev_err(*(_QWORD *)(v4 + 24), "%s: mbhc initialization failed\n", "wcd938x_event_notify");
        }
        else
        {
          wcd938x_mbhc_hs_detect(v4, *(_QWORD *)(v7 + 112));
        }
        *(_BYTE *)(*(_QWORD *)(v3 + 256) + 896LL) = 0;
        v12 = *(unsigned __int8 *)(v3 + 3207);
        *(_BYTE *)(v3 + 3192) = 1;
        if ( v12 == 1 )
          blocking_notifier_call_chain(v3 + 3208, 1);
        if ( *(_BYTE *)(v3 + 3206) == 1 )
        {
          v13 = -500;
          do
            _const_udelay(4295000);
          while ( !__CFADD__(v13++, 1) );
        }
        break;
      case 7u:
        snd_soc_component_update_bits(*(_QWORD *)(v3 + 16), 13319, 6, (a2 >> 15) & 0xFFFFFFFE);
        break;
    }
    return 0;
  }
  if ( (unsigned __int16)a2 == 1 )
  {
    if ( (*(_QWORD *)(v3 + 352) & 1) != 0 )
    {
      snd_soc_component_update_bits(*(_QWORD *)(v3 + 16), 12303, 64, 0);
      _X8 = (unsigned __int64 *)(v3 + 352);
      __asm { PRFM            #0x11, [X8] }
      do
        v21 = __ldxr(_X8);
      while ( __stxr(v21 | 0x200, _X8) );
      _X8 = (unsigned __int64 *)(v3 + 352);
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr(_X8);
      while ( __stxr(v24 & 0xFFFFFFFFFFFFFFFELL, _X8) );
      if ( (*(_QWORD *)(v3 + 352) & 2) == 0 )
      {
LABEL_19:
        if ( (*(_QWORD *)(v3 + 352) & 4) == 0 )
          goto LABEL_20;
        goto LABEL_31;
      }
    }
    else if ( (*(_QWORD *)(v3 + 352) & 2) == 0 )
    {
      goto LABEL_19;
    }
    snd_soc_component_update_bits(v4, 12303, 32, 0);
    _X8 = (unsigned __int64 *)(v3 + 352);
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stxr(v27 | 0x400, _X8) );
    _X8 = (unsigned __int64 *)(v3 + 352);
    __asm { PRFM            #0x11, [X8] }
    do
      v30 = __ldxr(_X8);
    while ( __stxr(v30 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    if ( (*(_QWORD *)(v3 + 352) & 4) == 0 )
    {
LABEL_20:
      if ( (*(_QWORD *)(v3 + 352) & 8) == 0 )
        return 0;
      goto LABEL_32;
    }
LABEL_31:
    snd_soc_component_update_bits(v4, 12305, 64, 0);
    _X8 = (unsigned __int64 *)(v3 + 352);
    __asm { PRFM            #0x11, [X8] }
    do
      v33 = __ldxr(_X8);
    while ( __stxr(v33 | 0x800, _X8) );
    _X8 = (unsigned __int64 *)(v3 + 352);
    __asm { PRFM            #0x11, [X8] }
    do
      v36 = __ldxr(_X8);
    while ( __stxr(v36 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    if ( (*(_QWORD *)(v3 + 352) & 8) == 0 )
      return 0;
LABEL_32:
    snd_soc_component_update_bits(v4, 12305, 32, 0);
    _X8 = (unsigned __int64 *)(v3 + 352);
    __asm { PRFM            #0x11, [X8] }
    do
      v39 = __ldxr(_X8);
    while ( __stxr(v39 | 0x1000, _X8) );
    _X8 = (unsigned __int64 *)(v3 + 352);
    __asm { PRFM            #0x11, [X8] }
    do
      v42 = __ldxr(_X8);
    while ( __stxr(v42 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
    return 0;
  }
  if ( (unsigned __int16)a2 == 2 )
  {
    snd_soc_component_update_bits(*(_QWORD *)(v3 + 16), 12297, 192, 0);
    snd_soc_component_update_bits(v4, 12298, 128, 0);
    snd_soc_component_update_bits(v4, 12584, 128, 0);
  }
  return 0;
}
