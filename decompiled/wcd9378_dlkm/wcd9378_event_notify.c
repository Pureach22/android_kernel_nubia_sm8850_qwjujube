__int64 __fastcall wcd9378_event_notify(__int64 a1, unsigned __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 v4; // x19
  bool v5; // w8
  __int64 v6; // x20
  int v7; // w8
  int v8; // w22
  int logical_dev_num; // w0
  int v10; // w8
  __int64 v11; // x20
  int v12; // w22
  int v13; // w0
  __int64 v14; // x20
  __int64 v15; // x19
  __int64 v17; // x0
  __int64 v18; // x19
  __int64 v19; // x8
  __int64 v20; // x0
  unsigned __int64 v27; // x9
  unsigned __int64 v30; // x10
  unsigned __int64 v33; // x9
  unsigned __int64 v36; // x10
  unsigned __int64 v39; // x9
  unsigned __int64 v42; // x10
  _BYTE v43[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v44[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a3 + 152);
  v4 = *(_QWORD *)(v3 + 32);
  if ( (unsigned __int16)a2 > 2u )
  {
    switch ( (unsigned __int16)a2 )
    {
      case 3u:
        if ( *(_BYTE *)(v3 + 3306) == 1 )
          blocking_notifier_call_chain(v3 + 3312, 0);
        *(_BYTE *)(*(_QWORD *)(v3 + 336) + 896LL) = 1;
        v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 336) + 112LL) + 88LL)
          && (snd_soc_component_read(v4, 1075314708) & 0x20) == 0;
        v17 = *(_QWORD *)(v3 + 336);
        *(_BYTE *)(v3 + 3305) = v5;
        wcd9378_mbhc_ssr_down(v17, v4);
        v18 = *(_QWORD *)v3;
        if ( *(_QWORD *)v3 )
        {
          v19 = *(_QWORD *)(v18 + 152);
          if ( v19 )
          {
            v20 = *(_QWORD *)(v19 + 40);
            if ( v20 )
            {
              if ( (unsigned int)msm_cdc_pinctrl_select_sleep_state(v20) )
                dev_err(v18, "%s: wcd sleep state request fail!\n", "wcd9378_reset_low");
              else
                usleep_range_state(20, 30, 2);
            }
            else
            {
              dev_err(v18, "%s: reset gpio device node not specified\n", "wcd9378_reset_low");
            }
          }
        }
        break;
      case 4u:
        wcd9378_reset(*(_QWORD *)v3);
        usleep_range_state(10000, 10010, 2);
        v6 = *(_QWORD *)(v3 + 64);
        v7 = -19;
        v43[0] = 0;
        do
        {
          v8 = v7;
          usleep_range_state(4000, 4010, 2);
          logical_dev_num = swr_get_logical_dev_num(v6, *(_QWORD *)(v6 + 984), v43);
          if ( !logical_dev_num )
            break;
          v7 = v8 + 1;
        }
        while ( v8 );
        if ( logical_dev_num )
          dev_err(
            v6 + 72,
            "%s get devnum %d for dev addr %llx failed\n",
            "wcd9378_get_logical_addr",
            v43[0],
            *(_QWORD *)(v6 + 984));
        v44[0] = 0;
        *(_BYTE *)(v6 + 64) = v43[0];
        v10 = -19;
        v11 = *(_QWORD *)(v3 + 56);
        do
        {
          v12 = v10;
          usleep_range_state(4000, 4010, 2);
          v13 = swr_get_logical_dev_num(v11, *(_QWORD *)(v11 + 984), v44);
          if ( !v13 )
            break;
          v10 = v12 + 1;
        }
        while ( v12 );
        if ( v13 )
          dev_err(
            v11 + 72,
            "%s get devnum %d for dev addr %llx failed\n",
            "wcd9378_get_logical_addr",
            v44[0],
            *(_QWORD *)(v11 + 984));
        *(_BYTE *)(v11 + 64) = v44[0];
        *(_BYTE *)(*(_QWORD *)(v3 + 64) + 1010LL) = 0;
        *(_BYTE *)(*(_QWORD *)(v3 + 64) + 1011LL) = 0;
        *(_BYTE *)(*(_QWORD *)(v3 + 56) + 1010LL) = 0;
        *(_BYTE *)(*(_QWORD *)(v3 + 56) + 1011LL) = 0;
        wcd9378_init_reg(v4);
        regcache_mark_dirty(*(_QWORD *)(v3 + 48));
        regcache_sync(*(_QWORD *)(v3 + 48));
        v14 = *(_QWORD *)(v3 + 336);
        if ( (unsigned int)wcd9378_mbhc_post_ssr_init(v14, v4) )
          dev_err(*(_QWORD *)(v4 + 24), "%s: mbhc initialization failed\n", "wcd9378_event_notify");
        else
          wcd9378_mbhc_hs_detect(v4, *(_QWORD *)(v14 + 112));
        *(_BYTE *)(*(_QWORD *)(v3 + 336) + 896LL) = 0;
        if ( *(_BYTE *)(v3 + 3306) == 1 )
          blocking_notifier_call_chain(v3 + 3312, 1);
        if ( *(_BYTE *)(v3 + 3305) == 1 )
        {
          v15 = -500;
          do
            _const_udelay(4295000);
          while ( !__CFADD__(v15++, 1) );
        }
        break;
      case 7u:
        snd_soc_component_update_bits(*(_QWORD *)(v3 + 32), 1075315719, 6, (a2 >> 15) & 0xFFFFFFFE);
        break;
    }
    goto LABEL_46;
  }
  if ( (unsigned __int16)a2 == 1 )
  {
    if ( (*(_QWORD *)(v3 + 456) & 1) != 0 )
    {
      snd_soc_component_update_bits(*(_QWORD *)(v3 + 32), 1075314703, 64, 0);
      _X8 = (unsigned __int64 *)(v3 + 456);
      __asm { PRFM            #0x11, [X8] }
      do
        v27 = __ldxr(_X8);
      while ( __stxr(v27 | 0x100, _X8) );
      _X8 = (unsigned __int64 *)(v3 + 456);
      __asm { PRFM            #0x11, [X8] }
      do
        v30 = __ldxr(_X8);
      while ( __stxr(v30 & 0xFFFFFFFFFFFFFFFELL, _X8) );
      if ( (*(_QWORD *)(v3 + 456) & 2) == 0 )
      {
LABEL_35:
        if ( (*(_QWORD *)(v3 + 456) & 4) == 0 )
          goto LABEL_46;
        goto LABEL_45;
      }
    }
    else if ( (*(_QWORD *)(v3 + 456) & 2) == 0 )
    {
      goto LABEL_35;
    }
    snd_soc_component_update_bits(v4, 1075314703, 32, 0);
    _X8 = (unsigned __int64 *)(v3 + 456);
    __asm { PRFM            #0x11, [X8] }
    do
      v33 = __ldxr(_X8);
    while ( __stxr(v33 | 0x200, _X8) );
    _X8 = (unsigned __int64 *)(v3 + 456);
    __asm { PRFM            #0x11, [X8] }
    do
      v36 = __ldxr(_X8);
    while ( __stxr(v36 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    if ( (*(_QWORD *)(v3 + 456) & 4) == 0 )
      goto LABEL_46;
LABEL_45:
    snd_soc_component_update_bits(v4, 1075314705, 64, 0);
    _X8 = (unsigned __int64 *)(v3 + 456);
    __asm { PRFM            #0x11, [X8] }
    do
      v39 = __ldxr(_X8);
    while ( __stxr(v39 | 0x400, _X8) );
    _X8 = (unsigned __int64 *)(v3 + 456);
    __asm { PRFM            #0x11, [X8] }
    do
      v42 = __ldxr(_X8);
    while ( __stxr(v42 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    goto LABEL_46;
  }
  if ( (unsigned __int16)a2 == 2 )
  {
    snd_soc_component_update_bits(*(_QWORD *)(v3 + 32), 1075314697, 192, 0);
    snd_soc_component_update_bits(v4, 1075314698, 128, 0);
    snd_soc_component_update_bits(v4, 1075314984, 128, 0);
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return 0;
}
