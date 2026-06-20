__int64 __fastcall wcd939x_event_notify(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v4; // x19
  unsigned __int64 v5; // x20
  int v6; // w8
  bool v7; // w8
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x19
  __int64 v11; // x20
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
  __int64 v43; // [xsp+0h] [xbp-20h] BYREF
  __int64 v44; // [xsp+8h] [xbp-18h] BYREF
  __int64 v45; // [xsp+10h] [xbp-10h]
  __int64 v46; // [xsp+18h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a3 + 152);
  v4 = *(_QWORD *)(v3 + 16);
  if ( (unsigned __int16)a2 > 2u )
  {
    switch ( (unsigned __int16)a2 )
    {
      case 3u:
        v6 = *(unsigned __int8 *)(v3 + 3232);
        *(_BYTE *)(v3 + 3216) = 0;
        if ( v6 == 1 )
          blocking_notifier_call_chain(v3 + 3240, 0);
        *(_BYTE *)(*(_QWORD *)(v3 + 256) + 896LL) = 1;
        v7 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 256) + 112LL) + 88LL)
          && (snd_soc_component_read(v4, 12308) & 0x20) == 0;
        v9 = *(_QWORD *)(v3 + 256);
        *(_BYTE *)(v3 + 3230) = v7;
        wcd939x_mbhc_ssr_down(v9, v4);
        v10 = *(_QWORD *)v3;
        if ( *(_QWORD *)v3 )
        {
          v11 = *(_QWORD *)(v10 + 152);
          if ( v11 )
          {
            if ( *(_QWORD *)(v11 + 24) )
            {
              v44 = 30;
              v45 = 33;
              v43 = 0x7700000063LL;
              wcd_usbss_register_update(&v43, 1, 1);
              wcd_usbss_register_update(&v44, 0, 2);
              HIDWORD(v44) = HIDWORD(v44) & 0xFFFFFFF1 | 8;
              HIDWORD(v45) = HIDWORD(v45) & 0xFFFFFFF1 | 8;
              wcd_usbss_register_update(&v44, 1, 2);
              if ( (unsigned int)msm_cdc_pinctrl_select_sleep_state(*(_QWORD *)(v11 + 24)) )
              {
                if ( (unsigned int)__ratelimit(&wcd939x_reset_low__rs_479, "wcd939x_reset_low") )
                  dev_err(v10, "%s: wcd sleep state request fail!\n", "wcd939x_reset_low");
              }
              else
              {
                usleep_range_state(20, 30, 2);
              }
            }
            else if ( (unsigned int)__ratelimit(&wcd939x_reset_low__rs, "wcd939x_reset_low") )
            {
              dev_err(v10, "%s: reset gpio device node not specified\n", "wcd939x_reset_low");
            }
          }
        }
        break;
      case 4u:
        wcd939x_reset(*(_QWORD *)v3);
        usleep_range_state(10000, 10010, 2);
        wcd939x_get_logical_addr(*(_QWORD *)(v3 + 48));
        wcd939x_get_logical_addr(*(_QWORD *)(v3 + 40));
        wcd939x_init_reg(v4);
        regcache_mark_dirty(*(_QWORD *)(v3 + 32));
        regcache_sync(*(_QWORD *)(v3 + 32));
        v8 = *(_QWORD *)(v3 + 256);
        if ( (unsigned int)wcd939x_mbhc_post_ssr_init(v8, v4) )
        {
          if ( (unsigned int)__ratelimit(&wcd939x_event_notify__rs, "wcd939x_event_notify") )
            dev_err(*(_QWORD *)(v4 + 24), "%s: mbhc initialization failed\n", "wcd939x_event_notify");
        }
        else
        {
          wcd939x_mbhc_hs_detect(v4, *(_QWORD *)(v8 + 112));
        }
        *(_BYTE *)(*(_QWORD *)(v3 + 256) + 896LL) = 0;
        v12 = *(unsigned __int8 *)(v3 + 3232);
        *(_BYTE *)(v3 + 3216) = 1;
        if ( v12 == 1 )
          blocking_notifier_call_chain(v3 + 3240, 1);
        if ( *(_BYTE *)(v3 + 3230) == 1 )
        {
          v13 = -500;
          do
            _const_udelay(4295000);
          while ( !__CFADD__(v13++, 1) );
        }
        break;
      case 7u:
        v5 = a2 >> 16;
        snd_soc_component_update_bits(*(_QWORD *)(v3 + 16), 13319, 6, 2 * (unsigned int)(a2 >> 16));
        if ( (_DWORD)v5 == 2 )
          *(_BYTE *)(v3 + 3231) = 2;
        else
          *(_BYTE *)(v3 + 3231) = (_DWORD)v5 == 1;
        break;
    }
    goto LABEL_49;
  }
  if ( (unsigned __int16)a2 == 1 )
  {
    if ( (*(_QWORD *)(v3 + 376) & 1) != 0 )
    {
      snd_soc_component_update_bits(*(_QWORD *)(v3 + 16), 12303, 64, 0);
      _X8 = (unsigned __int64 *)(v3 + 376);
      __asm { PRFM            #0x11, [X8] }
      do
        v21 = __ldxr(_X8);
      while ( __stxr(v21 | 0x200, _X8) );
      _X8 = (unsigned __int64 *)(v3 + 376);
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr(_X8);
      while ( __stxr(v24 & 0xFFFFFFFFFFFFFFFELL, _X8) );
      if ( (*(_QWORD *)(v3 + 376) & 2) == 0 )
      {
LABEL_21:
        if ( (*(_QWORD *)(v3 + 376) & 4) == 0 )
          goto LABEL_22;
        goto LABEL_33;
      }
    }
    else if ( (*(_QWORD *)(v3 + 376) & 2) == 0 )
    {
      goto LABEL_21;
    }
    snd_soc_component_update_bits(v4, 12303, 32, 0);
    _X8 = (unsigned __int64 *)(v3 + 376);
    __asm { PRFM            #0x11, [X8] }
    do
      v27 = __ldxr(_X8);
    while ( __stxr(v27 | 0x400, _X8) );
    _X8 = (unsigned __int64 *)(v3 + 376);
    __asm { PRFM            #0x11, [X8] }
    do
      v30 = __ldxr(_X8);
    while ( __stxr(v30 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    if ( (*(_QWORD *)(v3 + 376) & 4) == 0 )
    {
LABEL_22:
      if ( (*(_QWORD *)(v3 + 376) & 8) == 0 )
        goto LABEL_49;
      goto LABEL_34;
    }
LABEL_33:
    snd_soc_component_update_bits(v4, 12305, 64, 0);
    _X8 = (unsigned __int64 *)(v3 + 376);
    __asm { PRFM            #0x11, [X8] }
    do
      v33 = __ldxr(_X8);
    while ( __stxr(v33 | 0x800, _X8) );
    _X8 = (unsigned __int64 *)(v3 + 376);
    __asm { PRFM            #0x11, [X8] }
    do
      v36 = __ldxr(_X8);
    while ( __stxr(v36 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    if ( (*(_QWORD *)(v3 + 376) & 8) == 0 )
      goto LABEL_49;
LABEL_34:
    snd_soc_component_update_bits(v4, 12305, 32, 0);
    _X8 = (unsigned __int64 *)(v3 + 376);
    __asm { PRFM            #0x11, [X8] }
    do
      v39 = __ldxr(_X8);
    while ( __stxr(v39 | 0x1000, _X8) );
    _X8 = (unsigned __int64 *)(v3 + 376);
    __asm { PRFM            #0x11, [X8] }
    do
      v42 = __ldxr(_X8);
    while ( __stxr(v42 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
    goto LABEL_49;
  }
  if ( (unsigned __int16)a2 == 2 )
  {
    snd_soc_component_update_bits(*(_QWORD *)(v3 + 16), 12297, 128, 0);
    snd_soc_component_update_bits(v4, 12297, 64, 0);
    snd_soc_component_update_bits(v4, 12298, 128, 0);
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return 0;
}
