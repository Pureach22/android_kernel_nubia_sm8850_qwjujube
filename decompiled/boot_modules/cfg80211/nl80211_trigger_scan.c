__int64 __fastcall nl80211_trigger_scan(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x20
  __int64 v3; // x19
  _QWORD *v6; // x23
  char *v7; // x27
  __int64 v8; // x25
  int num_supported_channels; // w0
  __int64 v10; // x28
  _WORD *v11; // x9
  int v12; // w8
  int v13; // w11
  unsigned __int16 *v14; // x9
  unsigned int v15; // w10
  __int64 v16; // x10
  _WORD *v17; // x8
  unsigned __int16 v18; // w8
  __int64 v19; // x21
  __int64 v20; // x10
  __int64 v21; // x26
  __int64 v22; // x8
  __int64 v23; // x24
  bool v24; // cf
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x23
  __int64 v27; // x0
  __int64 channel_khz; // x0
  unsigned __int64 v29; // x9
  __int64 v30; // x8
  char *v31; // x25
  char v32; // t1
  unsigned __int64 v33; // x8
  __int64 v34; // x8
  unsigned int v35; // w8
  unsigned int v36; // w8
  __int64 v37; // x1
  unsigned __int64 v38; // x8
  int v39; // w8
  unsigned __int64 v40; // x9
  __int64 v41; // x8
  _WORD *v42; // x9
  __int64 v43; // x8
  unsigned int v44; // w9
  unsigned int v45; // w8
  unsigned int v46; // w19
  _WORD *v47; // x8
  unsigned __int16 v48; // w9
  __int64 v49; // x8
  unsigned __int64 v50; // x9
  __int64 v51; // x8
  __int64 v52; // x8
  __int64 v53; // x8
  __int64 v54; // x8
  __int64 v55; // x8
  __int64 v56; // x3
  _WORD *v57; // x8
  int v58; // w21
  __int64 v59; // x8
  unsigned int v60; // w8
  __int64 v61; // x10
  __int64 v62; // x8
  _QWORD *v63; // x8
  __int64 v64; // x9
  __int16 v65; // w8
  int v66; // w9
  __int64 v67; // x8
  __int16 v68; // w9
  int v69; // w8
  __int64 v70; // x8
  char v71; // w8
  __int64 v72; // x1
  __int64 v73; // x2
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-28h]
  int v75; // [xsp+10h] [xbp-20h]
  __int64 v76; // [xsp+18h] [xbp-18h]
  __int64 v77; // [xsp+20h] [xbp-10h]
  __int64 v78; // [xsp+20h] [xbp-10h]
  unsigned __int64 v79; // [xsp+28h] [xbp-8h]

  v2 = a2[7];
  if ( *(_DWORD *)(v2 + 8) == 12 )
    return 4294967201LL;
  v3 = a2[6];
  if ( !*(_QWORD *)(*(_QWORD *)v3 + 320LL) )
    return 4294967201LL;
  if ( *(_QWORD *)(v3 + 224) || *(_QWORD *)(v3 + 240) )
    return 4294967280LL;
  v6 = (_QWORD *)a2[4];
  v7 = (char *)v6[292];
  if ( v7 )
  {
    if ( (*(char *)(v3 + 1109) & 0x80000000) == 0 )
      return 4294967201LL;
    v8 = v6[292];
    goto LABEL_12;
  }
  v8 = v6[44];
  if ( v8 )
  {
LABEL_12:
    num_supported_channels = validate_scan_freqs(v8);
    if ( !num_supported_channels )
      return 4294967274LL;
    LODWORD(v10) = 0;
    goto LABEL_14;
  }
  num_supported_channels = ieee80211_get_num_supported_channels(v3 + 992);
  v6 = (_QWORD *)a2[4];
  LODWORD(v10) = 1;
LABEL_14:
  v11 = (_WORD *)v6[45];
  if ( v11 && (v12 = (unsigned __int16)(*v11 - 4), (unsigned int)v12 >= 4) )
  {
    v13 = 0;
    v14 = v11 + 2;
    do
    {
      v15 = *v14;
      if ( v15 < 4 )
        break;
      if ( v12 < v15 )
        break;
      ++v13;
      v16 = (v15 + 3) & 0x1FFFC;
      v12 -= v16;
      v14 = (unsigned __int16 *)((char *)v14 + v16);
    }
    while ( v12 > 3 );
    if ( v13 > *(unsigned __int8 *)(v3 + 1128) )
      return 4294967274LL;
  }
  else
  {
    v13 = 0;
  }
  v17 = (_WORD *)v6[42];
  if ( v17 )
  {
    v18 = *v17 - 4;
    if ( *(unsigned __int16 *)(v3 + 1132) < (unsigned int)v18 )
      return 4294967274LL;
    v76 = v3 + 992;
    v19 = v18;
  }
  else
  {
    v76 = v3 + 992;
    v19 = 0;
  }
  v20 = 8LL * num_supported_channels + 160;
  LODWORD(v21) = num_supported_channels;
  v75 = v13;
  v22 = 33LL * v13;
  if ( (unsigned __int64)(8LL * num_supported_channels) >= 0xFFFFFFFFFFFFFF60LL )
    v20 = -1;
  if ( num_supported_channels < 0 )
    v23 = -1;
  else
    v23 = v20;
  if ( !is_mul_ok(v13, 0x21u) )
    v22 = -1;
  v24 = __CFADD__(v23, v22);
  v25 = v23 + v22;
  if ( v24 )
    v26 = -1;
  else
    v26 = v25;
  if ( __CFADD__(v26, v19) )
    v27 = -1;
  else
    v27 = v26 + v19;
  v79 = v27;
  channel_khz = _kmalloc_noprof(v27, 3520);
  v77 = channel_khz;
  if ( !channel_khz )
    return 4294967284LL;
  while ( 1 )
  {
    v29 = v79;
    if ( v79 >= 0xC && (v79 & 0xFFFFFFFFFFFFFFFCLL) != 0xC )
    {
      *(_DWORD *)(v77 + 12) = v21;
      if ( v75 )
      {
        v29 = v79;
        *(_QWORD *)v77 = v77 + v23;
      }
      if ( v29 >= 8 && (v29 & 0xFFFFFFFFFFFFFFFCLL) != 8 )
      {
        *(_DWORD *)(v77 + 8) = v75;
        if ( !v19 )
          goto LABEL_52;
        if ( v29 >= 0x10 && (v29 & 0xFFFFFFFFFFFFFFF8LL) != 0x10 )
          break;
      }
    }
LABEL_169:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v78 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &nl80211_trigger_scan__alloc_tag;
    channel_khz = _kmalloc_noprof(channel_khz, 3520);
    *(_QWORD *)(StatusReg + 80) = v78;
    v77 = channel_khz;
    if ( !channel_khz )
      return 4294967284LL;
  }
  *(_QWORD *)(v77 + 16) = v77 + v26;
LABEL_52:
  if ( (_DWORD)v10 )
  {
    v7 = nullptr;
    LODWORD(v10) = 0;
    v26 = v3 + 1320;
    v23 = v77 + 160;
    do
    {
      v30 = *(_QWORD *)(v26 + 8LL * (_QWORD)v7);
      if ( v30 && *(int *)(v30 + 20) >= 1 )
      {
        v19 = 0;
        v21 = 12;
        do
        {
          v31 = (char *)(*(_QWORD *)v30 + v21);
          v32 = *v31;
          v8 = (__int64)(v31 - 12);
          if ( (v32 & 1) == 0 )
          {
            channel_khz = cfg80211_wdev_channel_allowed(v2, v8);
            if ( (channel_khz & 1) != 0 )
            {
              if ( (int)v10 < -20 )
                goto LABEL_169;
              v33 = 8LL * (int)v10 + 160;
              if ( v79 < v33 || v79 - v33 < 8 )
                goto LABEL_169;
              *(_QWORD *)(v23 + 8LL * (int)v10) = v8;
              LODWORD(v10) = v10 + 1;
            }
          }
          v30 = *(_QWORD *)(v26 + 8LL * (_QWORD)v7);
          ++v19;
          v21 += 64;
        }
        while ( v19 < *(int *)(v30 + 20) );
      }
      ++v7;
      v19 = (unsigned int)v10;
    }
    while ( v7 != (_BYTE *)&_ksymtab___cfg80211_alloc_event_skb + 6 );
  }
  else
  {
    v26 = (unsigned __int16)(*(_WORD *)v8 - 4);
    if ( (unsigned int)v26 < 4 )
      goto LABEL_100;
    v19 = 0;
    v23 = v8 + 4;
    LODWORD(v10) = 1000;
    v21 = v77 + 160;
    do
    {
      v35 = *(unsigned __int16 *)v23;
      if ( v35 < 4 || (unsigned int)v26 < v35 )
        break;
      v36 = *(_DWORD *)(v23 + 4);
      if ( v7 )
        v37 = v36;
      else
        v37 = 1000 * v36;
      channel_khz = ieee80211_get_channel_khz(v76, v37);
      if ( !channel_khz )
        goto LABEL_100;
      v8 = channel_khz;
      if ( (*(_BYTE *)(channel_khz + 12) & 1) == 0 )
      {
        channel_khz = cfg80211_wdev_channel_allowed(v2, channel_khz);
        if ( (channel_khz & 1) != 0 )
        {
          if ( (int)v19 < -20 )
            goto LABEL_169;
          v38 = 8LL * (int)v19 + 160;
          if ( v79 < v38 || v79 - v38 < 8 )
            goto LABEL_169;
          *(_QWORD *)(v21 + 8LL * (int)v19) = v8;
          v19 = (unsigned int)(v19 + 1);
        }
      }
      v34 = (*(unsigned __int16 *)v23 + 3) & 0x1FFFC;
      v26 = (unsigned int)(v26 - v34);
      v23 += v34;
    }
    while ( (int)v26 > 3 );
  }
  if ( (_DWORD)v19 )
  {
    v21 = v77;
    if ( (v79 & 0xFFFFFFFFFFFFFFFCLL) != 0xC )
    {
      v39 = 0;
      *(_DWORD *)(v77 + 12) = v19;
      v19 = v77 + 160;
      v26 = v79 & 0xFFFFFFFFFFFFFFFCLL;
      while ( v39 >= -20 )
      {
        v40 = 8LL * v39 + 160;
        if ( v79 < v40 || v79 - v40 < 8 )
          break;
        v23 = v39;
        v8 = *(_QWORD *)(v19 + 8LL * v39);
        channel_khz = cfg80211_off_channel_oper_allowed(v2, v8);
        if ( (channel_khz & 1) == 0 )
        {
          channel_khz = cfg80211_wdev_on_sub_chan(v2, v8, 1);
          if ( (channel_khz & 1) == 0 )
          {
            LODWORD(channel_khz) = -16;
            goto LABEL_102;
          }
        }
        if ( v26 == 12 )
          goto LABEL_169;
        v39 = v23 + 1;
        if ( (unsigned int)(v23 + 1) >= *(_DWORD *)(v77 + 12) )
        {
          v41 = a2[4];
          if ( v75 )
          {
            v42 = *(_WORD **)(v41 + 360);
            v19 = (unsigned __int16)(*v42 - 4);
            if ( (unsigned int)v19 >= 4 )
            {
              v26 = 0;
              v23 = (__int64)(v42 + 2);
              v7 = "et/wireless/chan.c";
              do
              {
                v44 = *(unsigned __int16 *)v23;
                v45 = v44 - 4;
                if ( v44 < 4 || (unsigned int)v19 < v44 )
                  break;
                if ( v45 > 0x20 )
                  goto LABEL_100;
                v10 = 33LL * (int)v26;
                *(_BYTE *)(*(_QWORD *)v77 + v10 + 32) = v45;
                v8 = (unsigned int)*(unsigned __int16 *)v23 - 4;
                if ( (unsigned int)v8 >= 0x21 && (nl80211_trigger_scan___already_done & 1) == 0 )
                {
                  nl80211_trigger_scan___already_done = 1;
                  _warn_printk(
                    "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                    (unsigned __int16)v8,
                    "field \"request->ssids[i].ssid\" at ../soc-repo/net/wireless/nl80211.c:9520",
                    0x20u);
                  __break(0x800u);
                }
                channel_khz = (__int64)memcpy(
                                         (void *)(*(_QWORD *)v77 + v10),
                                         (const void *)(v23 + 4),
                                         (unsigned __int16)v8);
                v26 = (unsigned int)(v26 + 1);
                v43 = (*(unsigned __int16 *)v23 + 3) & 0x1FFFC;
                v19 = (unsigned int)(v19 - v43);
                v23 += v43;
              }
              while ( (int)v19 > 3 );
              v41 = a2[4];
              v21 = v77;
            }
          }
          v47 = *(_WORD **)(v41 + 336);
          if ( v47 )
          {
            if ( v79 < 0x18 )
              goto LABEL_169;
            if ( (v79 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
              goto LABEL_169;
            v48 = *v47 - 4;
            *(_QWORD *)(v21 + 24) = v48;
            if ( (v79 & 0xFFFFFFFFFFFFFFF8LL) == 0x10 )
              goto LABEL_169;
            channel_khz = (__int64)memcpy(*(void **)(v21 + 16), (const void *)(*(_QWORD *)(a2[4] + 336LL) + 4LL), v48);
          }
          v49 = *(_QWORD *)(v3 + 1320);
          v50 = v79;
          v8 = v21 + 40;
          if ( v49 )
          {
            if ( v79 < 0x28 || (v79 & 0xFFFFFFFFFFFFFFFCLL) == 0x28 )
              goto LABEL_169;
            v50 = v79;
            *(_DWORD *)v8 = ~(-1 << *(_DWORD *)(v49 + 24));
          }
          v51 = *(_QWORD *)(v3 + 1328);
          if ( v51 )
          {
            if ( v50 < 0x2C || (v50 & 0xFFFFFFFFFFFFFFFCLL) == 0x2C )
              goto LABEL_169;
            *(_DWORD *)(v21 + 44) = ~(-1 << *(_DWORD *)(v51 + 24));
          }
          v52 = *(_QWORD *)(v3 + 1336);
          if ( v52 )
          {
            if ( v50 < 0x30 || (v50 & 0xFFFFFFFFFFFFFFFCLL) == 0x30 )
              goto LABEL_169;
            *(_DWORD *)(v21 + 48) = ~(-1 << *(_DWORD *)(v52 + 24));
          }
          v53 = *(_QWORD *)(v3 + 1344);
          if ( v53 )
          {
            if ( v50 < 0x34 || (v50 & 0xFFFFFFFFFFFFFFFCLL) == 0x34 )
              goto LABEL_169;
            *(_DWORD *)(v21 + 52) = ~(-1 << *(_DWORD *)(v53 + 24));
          }
          v54 = *(_QWORD *)(v3 + 1352);
          if ( v54 )
          {
            if ( v50 < 0x38 || (v50 & 0xFFFFFFFFFFFFFFFCLL) == 0x38 )
              goto LABEL_169;
            *(_DWORD *)(v21 + 56) = ~(-1 << *(_DWORD *)(v54 + 24));
          }
          v55 = *(_QWORD *)(v3 + 1360);
          if ( v55 )
          {
            if ( v50 < 0x3C || (v50 & 0xFFFFFFFFFFFFFFFCLL) == 0x3C )
              goto LABEL_169;
            *(_DWORD *)(v21 + 60) = ~(-1 << *(_DWORD *)(v55 + 24));
          }
          v56 = a2[4];
          v57 = *(_WORD **)(v56 + 1000);
          if ( v57 )
          {
            v58 = (unsigned __int16)(*v57 - 4);
            v50 = v79;
            if ( (unsigned int)v58 >= 4 )
            {
              v26 = v3 + 1320;
              v23 = (__int64)(v57 + 2);
              do
              {
                v60 = *(unsigned __int16 *)v23;
                if ( v60 < 4 || v58 < v60 )
                  break;
                v61 = *(_WORD *)(v23 + 2) & 0x3FFF;
                if ( (unsigned int)v61 > 5 )
                  goto LABEL_101;
                channel_khz = *(_QWORD *)(v26 + 8 * v61);
                if ( channel_khz )
                {
                  channel_khz = ieee80211_get_ratemask(channel_khz, v23 + 4, (unsigned __int16)(v60 - 4), v8 + 4 * v61);
                  if ( (_DWORD)channel_khz )
                    goto LABEL_102;
                  v60 = *(unsigned __int16 *)v23;
                }
                v59 = (v60 + 3) & 0x1FFFC;
                v58 -= v59;
                v23 += v59;
              }
              while ( v58 > 3 );
              v56 = a2[4];
              v50 = v79;
            }
          }
          v62 = *(_QWORD *)(v56 + 1880);
          v19 = v76;
          if ( v62 )
          {
            if ( v50 < 0x20 )
              goto LABEL_169;
            if ( (v79 & 0xFFFFFFFFFFFFFFFELL) == 0x20 )
              goto LABEL_169;
            *(_WORD *)(v21 + 32) = *(_WORD *)(v62 + 4);
            if ( v79 < 0x23 )
              goto LABEL_169;
            *(_BYTE *)(v21 + 34) = *(_QWORD *)(a2[4] + 1888LL) != 0;
          }
          channel_khz = nl80211_check_scan_flags(v76, v2, v21);
          if ( (_DWORD)channel_khz )
            goto LABEL_102;
          if ( v79 >= 0x82 )
          {
            v63 = (_QWORD *)a2[4];
            *(_BYTE *)(v21 + 129) = v63[135] != 0;
            v64 = v63[245];
            if ( v64 )
            {
              v65 = *(_WORD *)(v64 + 8);
              v66 = *(_DWORD *)(v64 + 4);
              *(_WORD *)(v21 + 88) = v65;
              *(_DWORD *)(v21 + 84) = v66;
            }
            else
            {
              if ( (v79 & 0xFFFFFFFFFFFFFFFCLL) == 0x24 )
                goto LABEL_169;
              if ( (*(_BYTE *)(v21 + 36) & 8) != 0 || (v67 = v63[6]) == 0 )
              {
                v69 = -1;
                *(_WORD *)(v21 + 88) = -1;
              }
              else
              {
                v68 = *(_WORD *)(v67 + 8);
                v69 = *(_DWORD *)(v67 + 4);
                *(_WORD *)(v21 + 88) = v68;
              }
              *(_DWORD *)(v21 + 84) = v69;
            }
            v70 = *(_QWORD *)(a2[4] + 2504LL);
            v71 = v70 ? *(_BYTE *)(v70 + 4) : -1;
            if ( v79 >= 0x91 )
            {
              *(_BYTE *)(v21 + 144) = v71;
              if ( (v79 & 0xFFFFFFFFFFFFFFF8LL) != 0x40 )
              {
                *(_QWORD *)(v21 + 64) = v2;
                if ( (v79 & 0xFFFFFFFFFFFFFFF8LL) != 0x60 )
                {
                  *(_QWORD *)(v21 + 96) = v76;
                  if ( (v79 & 0xFFFFFFFFFFFFFFF8LL) != 0x68 )
                  {
                    *(_QWORD *)(v21 + 104) = jiffies;
                    *(_QWORD *)(v3 + 224) = v21;
                    LODWORD(channel_khz) = cfg80211_scan(v3);
                    if ( (_DWORD)channel_khz )
                      goto LABEL_102;
                    nl80211_send_scan_start(v3, v2);
                    dev_hold(*(_QWORD *)(v2 + 32), v72, v73);
                    return 0;
                  }
                }
              }
            }
          }
          goto LABEL_169;
        }
      }
    }
    goto LABEL_169;
  }
LABEL_100:
  v21 = v77;
LABEL_101:
  LODWORD(channel_khz) = -22;
LABEL_102:
  *(_QWORD *)(v3 + 224) = 0;
  v46 = channel_khz;
  kfree(v21);
  return v46;
}
