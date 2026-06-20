__int64 __fastcall ieee80211_put_preq_ies(
        __int64 a1,
        __int64 a2,
        _QWORD *a3,
        char *a4,
        __int64 a5,
        unsigned __int8 a6,
        __int64 a7,
        _DWORD *a8,
        char a9)
{
  bool v10; // zf
  __int64 v13; // x22
  unsigned __int64 v14; // x28
  unsigned __int64 v15; // x21
  int v16; // w9
  __int64 result; // x0
  __int64 v18; // x25
  __int64 v19; // x27
  int v20; // w8
  unsigned int v21; // w26
  __int64 v22; // x0
  __int16 v23; // w9
  __int64 v24; // x0
  char v25; // w9
  int v26; // w24
  unsigned __int64 v27; // x0
  int v28; // w8
  void *v29; // x0
  __int64 v30; // x0
  __int64 v31; // x26
  unsigned __int64 v32; // x8
  unsigned int v33; // w24
  void *v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x26
  unsigned __int64 v38; // x8
  unsigned int v39; // w24
  void *v40; // x0
  __int64 v41; // x8
  unsigned __int8 *v42; // x9
  int v43; // t1
  char v44; // w24
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x26
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // x21
  unsigned __int64 v50; // x22
  void *v51; // x0
  _QWORD *v54; // [xsp+20h] [xbp-20h]
  int v56; // [xsp+34h] [xbp-Ch]

  if ( a4 )
    v10 = a5 == 0;
  else
    v10 = 1;
  v13 = 0;
  v14 = 0;
  v15 = a6;
  v16 = !v10;
  a3[12] = 0;
  a3[13] = 0;
  a3[10] = 0;
  a3[11] = 0;
  a3[9] = 0;
  a3[7] = 0;
  a3[8] = 0;
  v56 = v16;
  a3[4] = 0;
  a3[5] = 0;
  a3[2] = 0;
  a3[3] = 0;
  a3[6] = 0;
  v54 = a3 + 6;
  *a3 = 0;
  a3[1] = 0;
  do
  {
    if ( ((v15 >> v13) & 1) != 0 )
    {
      a3[v13] = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 208);
      v18 = *(_QWORD *)(a2 + 1616);
      v19 = *(_QWORD *)(*(_QWORD *)(v18 + 72) + 8 * v13 + 328);
      if ( v19 )
      {
        v20 = a8[2];
        if ( v20 == 6 )
          v21 = 32;
        else
          v21 = (v20 == 7) << 6;
        if ( v13 == 4 )
        {
          if ( *(_DWORD *)(a1 + 116) || (unsigned int)(*(_DWORD *)(a1 + 212) - *(_DWORD *)(a1 + 208)) < 0x11 )
            return 4294967191LL;
          *(_BYTE *)skb_put(a1, 1) = -39;
          *(_BYTE *)skb_put(a1, 1) = 15;
          v22 = skb_put(a1, 10);
          v23 = *(_WORD *)(v19 + 77);
          *(_QWORD *)v22 = *(_QWORD *)(v19 + 69);
          *(_WORD *)(v22 + 8) = v23;
          v24 = skb_put(a1, 5);
          v25 = *(_BYTE *)(v19 + 83);
          v14 = 0;
          *(_DWORD *)v24 = *(_DWORD *)(v19 + 79);
          *(_BYTE *)(v24 + 4) = v25;
          goto LABEL_9;
        }
        v26 = *(_DWORD *)(a7 + 4 * v13);
        result = ieee80211_put_srates_elem(a1, v19, 0, v21, (unsigned int)~v26, 1);
        if ( (_DWORD)result )
          return result;
        if ( v56 )
        {
          v27 = ieee80211_ie_split_ric(a4, a5, &ieee80211_put_preq_ies_band_before_extrates, 3, 0, 0, 0);
          v14 = v27;
          v28 = 0;
          if ( !*(_DWORD *)(a1 + 116) )
            v28 = *(_DWORD *)(a1 + 212) - *(_DWORD *)(a1 + 208);
          if ( v27 > v28 )
            return 4294967191LL;
          v29 = (void *)skb_put(a1, (unsigned int)v27);
          memcpy(v29, a4, (unsigned int)v14);
        }
        else
        {
          v14 = 0;
        }
        result = ieee80211_put_srates_elem(a1, v19, 0, v21, (unsigned int)~v26, 50);
        if ( (_DWORD)result )
          return result;
        if ( *(_QWORD *)a8 && !*(_DWORD *)(v19 + 16) )
        {
          if ( *(_DWORD *)(a1 + 116) || *(_DWORD *)(a1 + 212) - *(_DWORD *)(a1 + 208) < 3 )
            return 4294967191LL;
          *(_BYTE *)skb_put(a1, 1) = 3;
          *(_BYTE *)skb_put(a1, 1) = 1;
          v44 = ieee80211_freq_khz_to_channel((unsigned int)(1000 * *(_DWORD *)(*(_QWORD *)a8 + 4LL)));
          *(_BYTE *)skb_put(a1, 1) = v44;
          if ( (a9 & 2) != 0 )
            goto LABEL_9;
LABEL_31:
          if ( v56 )
          {
            v30 = ieee80211_ie_split_ric(a4, a5, &ieee80211_put_preq_ies_band_before_ht, 2, 0, 0, v14);
            v31 = v30;
            v32 = 0;
            if ( !*(_DWORD *)(a1 + 116) )
              v32 = *(_DWORD *)(a1 + 212) - *(_DWORD *)(a1 + 208);
            v33 = v30 - v14;
            if ( v30 - v14 > v32 )
              return 4294967191LL;
            v34 = (void *)skb_put(a1, v33);
            memcpy(v34, &a4[v14], v33);
            v14 = v31;
          }
          if ( *(_BYTE *)(v19 + 30) == 1 )
          {
            if ( *(_DWORD *)(a1 + 116) || (unsigned int)(*(_DWORD *)(a1 + 212) - *(_DWORD *)(a1 + 208)) < 0x1C )
              return 4294967191LL;
            v35 = skb_put(a1, 28);
            ieee80211_ie_build_ht_cap(v35, v19 + 28, *(unsigned __int16 *)(v19 + 28));
          }
          if ( v56 )
          {
            v36 = ieee80211_ie_split_ric(a4, a5, &ieee80211_put_preq_ies_band_before_vht, 6, 0, 0, v14);
            v37 = v36;
            v38 = 0;
            if ( !*(_DWORD *)(a1 + 116) )
              v38 = *(_DWORD *)(a1 + 212) - *(_DWORD *)(a1 + 208);
            v39 = v36 - v14;
            if ( v36 - v14 > v38 )
              return 4294967191LL;
            v40 = (void *)skb_put(a1, v39);
            memcpy(v40, &a4[v14], v39);
            v14 = v37;
          }
          v41 = *(unsigned int *)(v19 + 20);
          if ( (int)v41 >= 1 )
          {
            v42 = (unsigned __int8 *)(*(_QWORD *)v19 + 12LL);
            while ( 1 )
            {
              v43 = *v42;
              v42 += 64;
              if ( (v43 & 0xFFFFFF81) == 0 )
                break;
              if ( !--v41 )
                goto LABEL_58;
            }
            if ( *(_BYTE *)(v19 + 52) == 1 )
            {
              if ( *(_DWORD *)(a1 + 116) || (unsigned int)(*(_DWORD *)(a1 + 212) - *(_DWORD *)(a1 + 208)) < 0xE )
                return 4294967191LL;
              v45 = skb_put(a1, 14);
              ieee80211_ie_build_vht_cap(v45, v19 + 52, *(unsigned int *)(v19 + 56));
            }
          }
LABEL_58:
          if ( v56 )
          {
            v46 = ieee80211_ie_split_ric(a4, a5, &ieee80211_put_preq_ies_band_before_he, 3, 0, 0, v14);
            v47 = v46;
            v48 = 0;
            if ( !*(_DWORD *)(a1 + 116) )
              v48 = *(_DWORD *)(a1 + 212) - *(_DWORD *)(a1 + 208);
            if ( v46 - v14 > v48 )
              return 4294967191LL;
            skb_put_data_1(a1, &a4[v14], v46 - v14);
            v14 = v47;
          }
          if ( (cfg80211_any_usable_channels(*(_QWORD *)(v18 + 72), 1LL << *(_DWORD *)(v19 + 16), 0x2000) & 1) != 0 )
          {
            result = ieee80211_put_he_cap(a1, a2, v19, 0);
            if ( (_DWORD)result )
              return result;
          }
          if ( (cfg80211_any_usable_channels(*(_QWORD *)(v18 + 72), 1LL << *(_DWORD *)(v19 + 16), 1056768) & 1) != 0 )
          {
            result = ieee80211_put_eht_cap(a1, a2, v19, 0);
            if ( (_DWORD)result )
              return result;
          }
          result = ieee80211_put_he_6ghz_cap(a1, a2, 1);
          if ( (_DWORD)result )
            return result;
          goto LABEL_9;
        }
        if ( (a9 & 2) == 0 )
          goto LABEL_31;
      }
      else
      {
        v14 = 0;
        __break(0x800u);
      }
LABEL_9:
      v54[v13] = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 208) - a3[v13];
    }
    ++v13;
  }
  while ( v13 != 6 );
  if ( !v56 )
    return 0;
  if ( *(_DWORD *)(a1 + 116) )
    v49 = 0;
  else
    v49 = *(_DWORD *)(a1 + 212) - *(_DWORD *)(a1 + 208);
  v50 = a5 - v14;
  if ( a5 - v14 <= v49 || (ieee80211_put_preq_ies___already_done & 1) != 0 )
  {
    if ( v50 <= v49 )
    {
LABEL_77:
      a3[12] = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 208);
      v51 = (void *)skb_put(a1, (unsigned int)v50);
      memcpy(v51, &a4[v14], (unsigned int)(a5 - v14));
      a3[13] = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 208) - a3[12];
      return 0;
    }
  }
  else
  {
    ieee80211_put_preq_ies___already_done = 1;
    _warn_printk("not enough space for preq custom IEs\n");
    __break(0x800u);
    if ( v50 <= v49 )
      goto LABEL_77;
  }
  return 4294967191LL;
}
