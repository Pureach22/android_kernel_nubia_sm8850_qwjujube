_QWORD *__fastcall cfg80211_inform_single_bss_data(__int64 a1, __int64 *a2, int a3)
{
  __int64 v3; // x19
  __int64 *v4; // x20
  int *v5; // x21
  int v6; // w22
  __int64 v7; // x23
  __int64 v8; // x26
  int v9; // w8
  __int64 ies_channel_number; // x0
  unsigned int v11; // w0
  int v12; // w23
  int _6ghz_power_type; // w0
  __int64 channel_khz; // x0
  int v15; // w8
  int v16; // w9
  __int16 v17; // w10
  int v18; // w9
  __int16 v19; // w10
  __int16 v20; // w9
  char v21; // w11
  __int64 v22; // x12
  int v23; // w10
  __int64 v24; // x8
  char v25; // w10
  unsigned __int64 v26; // x24
  unsigned __int64 v27; // x25
  __int64 v28; // x9
  size_t v29; // x2
  int v30; // w8
  char v31; // w24
  _QWORD *v32; // x0
  __int64 v33; // x3
  _QWORD *v34; // x24
  _QWORD *v35; // x23
  _DWORD *v36; // x8
  _QWORD *v37; // x26
  __int64 elem; // x0
  _QWORD *v39; // x20
  __int64 v40; // x25
  _QWORD *v41; // x27
  _QWORD *v42; // x0
  _QWORD *v43; // x1
  unsigned __int64 StatusReg; // x27
  __int64 v46; // x28
  _QWORD v47[7]; // [xsp+0h] [xbp-E0h] BYREF
  __int64 v48; // [xsp+38h] [xbp-A8h]
  __int64 v49; // [xsp+40h] [xbp-A0h]
  __int64 v50; // [xsp+48h] [xbp-98h]
  __int64 v51; // [xsp+50h] [xbp-90h]
  __int64 v52; // [xsp+58h] [xbp-88h]
  __int64 v53; // [xsp+60h] [xbp-80h]
  __int64 v54; // [xsp+68h] [xbp-78h]
  int *v55; // [xsp+70h] [xbp-70h]
  unsigned __int64 v56; // [xsp+78h] [xbp-68h] BYREF
  unsigned __int64 v57; // [xsp+80h] [xbp-60h] BYREF
  unsigned __int64 v58[2]; // [xsp+88h] [xbp-58h] BYREF
  __int64 v59; // [xsp+98h] [xbp-48h]
  __int64 v60; // [xsp+A0h] [xbp-40h]
  __int64 v61; // [xsp+A8h] [xbp-38h]
  __int64 v62; // [xsp+B0h] [xbp-30h]
  __int128 v63; // [xsp+B8h] [xbp-28h]
  __int64 v64; // [xsp+C8h] [xbp-18h]
  __int64 v65; // [xsp+D0h] [xbp-10h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_80;
  v9 = *(_DWORD *)(a1 + 128);
  v8 = *a2;
  v6 = a3;
  v4 = a2;
  v3 = a1;
  v64 = 0;
  v62 = 0;
  v63 = 0u;
  v60 = 0;
  v61 = 0;
  v58[1] = 0;
  v59 = 0;
  v57 = 0;
  v58[0] = 0;
  v55 = nullptr;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v48 = 0;
  memset(v47, 0, sizeof(v47));
  if ( v9 == 2 && *(_DWORD *)(v8 + 8) >= 0x65u || *((_DWORD *)a2 + 16) && !a2[9] )
  {
    v35 = nullptr;
    __break(0x800u);
    goto LABEL_75;
  }
  v5 = (int *)a2[2];
  if ( v5 )
    goto LABEL_10;
  v5 = *(int **)v8;
  ies_channel_number = cfg80211_get_ies_channel_number((unsigned __int8 *)a2[6], a2[7], **(_DWORD **)v8);
  if ( (ies_channel_number & 0x80000000) != 0 )
    goto LABEL_9;
  v11 = ieee80211_channel_to_freq_khz(ies_channel_number, (unsigned int)*v5);
  if ( v11 == *((unsigned __int16 *)v5 + 4) + 1000 * v5[1] )
    goto LABEL_9;
  channel_khz = ieee80211_get_channel_khz(v3, v11);
  if ( channel_khz )
  {
    v5 = (int *)channel_khz;
    if ( (*(_BYTE *)(channel_khz + 12) & 1) != 0 )
      goto LABEL_66;
    goto LABEL_10;
  }
  v35 = nullptr;
  if ( *v5 )
  {
    if ( *v5 != 3 )
    {
LABEL_9:
      if ( !v5 )
        goto LABEL_66;
LABEL_10:
      if ( *v5 != 3 )
        goto LABEL_21;
      v12 = v5[3];
      _6ghz_power_type = cfg80211_get_6ghz_power_type((unsigned __int8 *)v4[6], v4[7]);
      if ( _6ghz_power_type == 1 )
        goto LABEL_21;
      if ( _6ghz_power_type == 2 )
      {
        if ( (v12 & 0x800000) == 0 )
          goto LABEL_21;
      }
      else if ( _6ghz_power_type == 3 && (v12 & 0x400000) == 0 )
      {
        goto LABEL_21;
      }
      *((_BYTE *)v4 + 82) = 0;
      v4[11] = 2;
LABEL_21:
      v15 = *((_DWORD *)v4 + 16);
      v16 = *((_DWORD *)v4 + 6);
      v17 = *((_WORD *)v4 + 14);
      v55 = v5;
      LODWORD(v63) = v16;
      WORD2(v63) = v17;
      if ( v15 == 2 )
        v18 = 0;
      else
        v18 = *(_DWORD *)(v8 + 8);
      v19 = *((_WORD *)v4 + 21);
      LODWORD(v62) = v18;
      v20 = *((_WORD *)v4 + 20);
      v21 = *((_BYTE *)v4 + 82);
      v22 = v4[11];
      WORD2(v62) = v19;
      HIWORD(v62) = v20;
      v48 = *(_QWORD *)(v8 + 16);
      v52 = *(_QWORD *)(v8 + 24);
      LODWORD(v53) = *(_DWORD *)(v8 + 32);
      WORD2(v53) = *(_WORD *)(v8 + 36);
      BYTE6(v63) = *(_BYTE *)(v8 + 38);
      v23 = *(_DWORD *)(v8 + 39);
      BYTE14(v63) = v21;
      HIBYTE(v63) = v22;
      *(_DWORD *)((char *)&v63 + 7) = v23;
      LODWORD(v54) = v15;
      if ( v15 )
      {
        if ( v15 == 1 )
        {
          v24 = v4[9];
          v59 = v24;
          goto LABEL_29;
        }
        if ( v15 == 2 )
        {
          v24 = v4[9];
LABEL_29:
          v25 = *((_BYTE *)v4 + 80);
          v7 = *(_QWORD *)(v24 - 48);
          BYTE12(v63) = *((_BYTE *)v4 + 81);
          BYTE13(v63) = v25;
          goto LABEL_36;
        }
        v7 = 0;
LABEL_36:
        v26 = v4[7] + 32;
        v27 = _kmalloc_noprof(v26, v6 | 0x100u);
        if ( v27 )
        {
          while ( 1 )
          {
            if ( v26 < 0x18
              || (v26 & 0xFFFFFFFFFFFFFFFCLL) == 0x18
              || (v28 = v4[4], *(_DWORD *)(v27 + 24) = v4[7], *(_QWORD *)v27 = v28, v26 < 0x1D) )
            {
              __break(1u);
            }
            v29 = v4[7];
            *(_BYTE *)(v27 + 28) = 0;
            if ( v26 - 29 >= v29 )
              break;
            _fortify_panic(17, v26 - 29);
LABEL_80:
            __break(0x800u);
            StatusReg = _ReadStatusReg(SP_EL0);
            v46 = *(_QWORD *)(StatusReg + 80);
            *(_QWORD *)(StatusReg + 80) = &cfg80211_inform_single_bss_data__alloc_tag;
            v26 = v4[7] + 32;
            v27 = _kmalloc_noprof(v26, v6 | 0x100u);
            *(_QWORD *)(StatusReg + 80) = v46;
            if ( !v27 )
              goto LABEL_66;
          }
          memcpy((void *)(v27 + 29), (const void *)v4[6], v29);
          v30 = *((_DWORD *)v4 + 2);
          if ( v30 > 1 )
          {
            if ( v30 == 2 )
            {
              atomic_store(v27, v58);
              goto LABEL_50;
            }
            if ( v30 != 3 )
              goto LABEL_50;
          }
          else
          {
            if ( !v30 )
            {
LABEL_48:
              atomic_store(v27, &v57);
              goto LABEL_50;
            }
            if ( v30 != 1 )
            {
LABEL_50:
              atomic_store(v27, &v56);
              v31 = *(_QWORD *)v8 == (_QWORD)v5;
              raw_spin_lock_bh(v3 - 808);
              v32 = _cfg80211_bss_update(v3 - 992, v47, v31, v7);
              if ( !v32 )
              {
LABEL_65:
                raw_spin_unlock_bh(v3 - 808);
                goto LABEL_66;
              }
              v33 = *(_QWORD *)(v8 + 48);
              v34 = v32;
              v35 = v32 + 14;
              v36 = *(_DWORD **)(*(_QWORD *)(v3 - 992) + 288LL);
              if ( v36 )
              {
                if ( *(v36 - 1) != 1636613702 )
                  __break(0x8228u);
                v32 = (_QWORD *)((__int64 (__fastcall *)(__int64, _QWORD *, unsigned __int64, __int64))v36)(
                                  v3,
                                  v35,
                                  v27,
                                  v33);
              }
              if ( *((_DWORD *)v4 + 16) == 1 )
              {
                v37 = (_QWORD *)v4[9];
                _rcu_read_lock(v32);
                elem = ieee80211_bss_get_elem((int)v35, 0);
                if ( elem )
                {
                  v39 = v37 + 6;
                  v40 = elem;
                  v41 = v37 + 6;
                  while ( 1 )
                  {
                    v41 = (_QWORD *)*v41;
                    if ( v41 == v39 )
                      break;
                    elem = is_bss(
                             (__int64)(v41 - 6),
                             (__int64)(v34 + 23),
                             (void *)(v40 + 2),
                             *(unsigned __int8 *)(v40 + 1));
                    if ( (elem & 1) != 0 )
                    {
                      _rcu_read_unlock(elem);
                      goto LABEL_74;
                    }
                  }
                  _rcu_read_unlock(elem);
                  v42 = v34 + 20;
                  if ( (_QWORD *)v34[20] == v34 + 20 )
                  {
                    v43 = (_QWORD *)v37[7];
                    if ( v35 == v37 || v43 == v42 || (_QWORD *)*v43 != v39 )
                    {
                      _list_add_valid_or_report(v42, v43);
                    }
                    else
                    {
                      v37[7] = v42;
                      v34[20] = v39;
                      v34[21] = v43;
                      *v43 = v42;
                    }
                    goto LABEL_74;
                  }
                }
                else
                {
                  _rcu_read_unlock(0);
                }
                if ( (_cfg80211_unlink_bss(v3 - 992) & 1) != 0 )
                {
                  ++*(_DWORD *)(v3 - 776);
                  goto LABEL_65;
                }
              }
LABEL_74:
              raw_spin_unlock_bh(v3 - 808);
              goto LABEL_75;
            }
          }
          *(_BYTE *)(v27 + 28) = 1;
          goto LABEL_48;
        }
LABEL_66:
        v35 = nullptr;
        goto LABEL_75;
      }
      v7 = jiffies;
      if ( *v5 == 2 )
      {
        if ( (v20 & 2) == 0 )
          goto LABEL_36;
      }
      else if ( (v20 & 1) == 0 )
      {
        goto LABEL_36;
      }
      regulatory_hint_found_beacon(v3, (__int64)v5, v6);
      goto LABEL_36;
    }
  }
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return v35;
}
