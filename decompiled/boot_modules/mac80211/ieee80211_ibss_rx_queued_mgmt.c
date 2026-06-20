__int64 __fastcall ieee80211_ibss_rx_queued_mgmt(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x27
  unsigned int v4; // w8
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v8; // x21
  __int64 v9; // x20
  unsigned int v10; // w28
  __int64 v11; // x1
  __int64 v12; // x25
  __int64 v13; // x28
  __int64 v14; // x0
  __int64 v15; // x10
  __int64 v16; // x0
  __int64 v17; // x26
  int v18; // w28
  _BOOL4 v19; // w28
  __int64 v20; // x20
  __int64 v22; // x0
  __int64 v23; // x19
  __int64 (__fastcall *v24)(_QWORD); // x8
  __int64 v25; // x24
  int v26; // w21
  __int16 v27; // w8
  unsigned int v28; // w9
  size_t v29; // x2
  __int64 v30; // x21
  int v31; // w8
  __int64 v32; // x21
  __int64 v33; // x8
  __int64 v34; // x22
  __int64 v35; // x9
  __int64 v36; // x8
  int v37; // w10
  int v38; // w8
  __int64 v39; // x26
  __int64 v40; // x26
  unsigned int v41; // w8
  int v42; // w26
  __int64 v43; // x28
  char v44; // w3
  __int64 v45; // x0
  __int64 v46; // x25
  unsigned __int64 v47; // x26
  size_t v48; // x2
  unsigned __int64 tsf; // x0
  int v50; // w8
  __int64 v51; // x26
  __int64 *v52; // x8
  __int64 v53; // x10
  __int64 v54; // x11
  __int16 v55; // w9
  __int64 v56; // x8
  int v57; // w26
  unsigned int *v58; // x9
  __int64 v59; // x8
  __int64 *v60; // x8
  __int64 v61; // x9
  bool v63; // w9
  char v64; // w26
  unsigned int rates; // w0
  __int64 v66; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v68; // x24
  __int64 v69; // x8
  __int64 v70; // [xsp+20h] [xbp-C0h]
  unsigned int v71; // [xsp+2Ch] [xbp-B4h]
  int v72; // [xsp+2Ch] [xbp-B4h]
  __int64 v73; // [xsp+30h] [xbp-B0h]
  __int64 v74; // [xsp+38h] [xbp-A8h]
  __int64 v75; // [xsp+40h] [xbp-A0h]
  __int64 v76; // [xsp+40h] [xbp-A0h]
  unsigned int v77; // [xsp+4Ch] [xbp-94h]
  __int64 v78; // [xsp+50h] [xbp-90h]
  __int64 v79; // [xsp+58h] [xbp-88h]
  __int64 v80; // [xsp+60h] [xbp-80h] BYREF
  int v81; // [xsp+68h] [xbp-78h]
  __int64 v82; // [xsp+70h] [xbp-70h] BYREF
  __int64 v83; // [xsp+78h] [xbp-68h]
  __int64 v84; // [xsp+80h] [xbp-60h]
  _QWORD v85[4]; // [xsp+88h] [xbp-58h] BYREF
  __int64 v86; // [xsp+A8h] [xbp-38h]
  _QWORD v87[3]; // [xsp+B0h] [xbp-30h] BYREF
  __int16 v88; // [xsp+C8h] [xbp-18h]
  __int64 v89; // [xsp+D0h] [xbp-10h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)(result + 2384) )
    goto LABEL_107;
  v2 = *(_QWORD *)(a2 + 224);
  v3 = result + 2346;
  v4 = ((*(_WORD *)v2 & 0xF0u) - 64) >> 4;
  if ( v4 > 6 )
  {
    if ( v4 == 7 )
    {
      if ( *(_DWORD *)(a2 + 112) >= 0x1Eu && !*(_WORD *)(v2 + 24) && *(_WORD *)(v2 + 26) == 1 )
        result = ieee80211_send_auth(result, 2, 0, 0, 0, 0, v2 + 10, result + 2346, 0, 0, 0, 0);
    }
    else if ( v4 == 8 )
    {
      if ( *(_DWORD *)(a2 + 112) >= 0x1Au )
        result = sta_info_destroy_addr();
    }
    else if ( v4 == 9 && !*(_BYTE *)(v2 + 24) && *(_DWORD *)(a2 + 112) - 26 >= 0 )
    {
      v84 = (unsigned int)(*(_DWORD *)(a2 + 112) - 26);
      v20 = result;
      LOBYTE(v85[0]) = 1;
      v82 = 5;
      v83 = v2 + 26;
      memset((char *)v85 + 1, 0, 24);
      v85[3] = 0;
      v86 = 0xFFFFFFFFLL;
      v22 = ieee802_11_parse_elems_full(&v82);
      if ( v22
        && !*(_BYTE *)(v22 + 760)
        && *(_DWORD *)(a2 + 112) >= 0x1Au
        && *(_BYTE *)(v2 + 25) == 4
        && (*(_BYTE *)(v3 + 3292) & 1) == 0 )
      {
        v23 = v22;
        ieee80211_ibss_process_chanswitch(v20, v22);
        v22 = v23;
      }
      goto LABEL_106;
    }
  }
  else
  {
    if ( v4 )
    {
      if ( v4 != 1 && v4 != 4 )
        goto LABEL_107;
      v5 = *(unsigned int *)(a2 + 112);
      if ( (unsigned int)v5 < 0x24 )
        goto LABEL_107;
      v6 = result;
      v82 = 5;
      v83 = v2 + 36;
      v84 = v5 - 36;
      memset(v85, 0, sizeof(v85));
      v86 = 0xFFFFFFFFLL;
      result = ieee802_11_parse_elems_full(&v82);
      if ( !result )
        goto LABEL_107;
      v8 = *(_QWORD *)(v6 + 1616);
      v9 = result;
      v10 = *(unsigned __int8 *)(a2 + 76);
      result = ieee80211_get_channel_khz(*(_QWORD *)(v8 + 72), 1000 * (*(_WORD *)(a2 + 68) & 0x1FFFu));
      if ( !result )
      {
LABEL_105:
        v22 = v9;
LABEL_106:
        result = kfree(v22);
        goto LABEL_107;
      }
      v12 = result;
      if ( *(_DWORD *)(v6 + 4720) != 1
        || *(_DWORD *)v3 ^ *(_DWORD *)(v2 + 16) | *(unsigned __int16 *)(v6 + 2350) ^ *(unsigned __int16 *)(v2 + 20) )
      {
LABEL_74:
        v45 = ieee80211_bss_info_update(v8, a2 + 40, v2, v5, v12);
        if ( v45 )
        {
          v46 = v45;
          if ( (*(_WORD *)(v45 - 26) & 2) != 0 )
          {
            v47 = *(_QWORD *)(v2 + 24);
            if ( *(_BYTE *)(v6 + 2341) != 1 || *(_QWORD *)(v6 + 2400) == *(_QWORD *)(v45 - 96) )
            {
              v48 = *(unsigned __int8 *)(v9 + 697);
              if ( (_DWORD)v48 == *(unsigned __int8 *)(v6 + 2384)
                && !bcmp(*(const void **)(v9 + 48), (const void *)(v6 + 2352), v48)
                && (*(_BYTE *)(v3 + 3292) & 1) == 0
                && (ieee80211_ibss_process_chanswitch(v6, v9) & 1) == 0
                && *(_DWORD *)v3 ^ *(_DWORD *)(v46 - 24)
                 | *(unsigned __int16 *)(v6 + 2350) ^ *(unsigned __int16 *)(v46 - 20)
                && (*(_BYTE *)(v6 + 2340) & 1) == 0 )
              {
                if ( (*(_BYTE *)(a2 + 66) & 3) != 0 )
                  tsf = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))ieee80211_calculate_rx_timestamp)(
                          v8,
                          a2 + 40,
                          (unsigned int)(v5 + 4),
                          24);
                else
                  tsf = drv_get_tsf(v8, v6);
                if ( v47 > tsf )
                {
                  ieee80211_sta_join_ibss(v6, v46);
                  rates = ieee80211_sta_get_rates(v6, v9, v10, 0);
                  v66 = ieee80211_ibss_add_sta(v6, v2 + 16, v2 + 10, rates);
                  _rcu_read_unlock(v66);
                }
              }
            }
          }
          ieee80211_rx_bss_put(v8, v46);
        }
        goto LABEL_105;
      }
      v77 = v10;
      v13 = *(unsigned __int8 *)(a2 + 76);
      if ( (unsigned int)v13 < 6 )
      {
        v74 = *(_QWORD *)(v6 + 1616);
        v73 = *(_QWORD *)(*(_QWORD *)(v74 + 72) + 8 * v13 + 328);
        if ( !v73 )
        {
          __break(0x800u);
          goto LABEL_73;
        }
        _rcu_read_lock(result, v11);
        v14 = sta_info_get(v6, v2 + 10);
        v15 = v14;
        if ( *(_QWORD *)(v9 + 56) )
        {
          v75 = v14;
          v16 = ieee80211_sta_get_rates(v6, v9, (unsigned int)v13, 0);
          v71 = v16;
          if ( v75 )
          {
            v17 = v75 + 4 * v13;
            v18 = *(_DWORD *)(v17 + 2900);
            v14 = ieee80211_mandatory_rates(v73);
            v15 = v75;
            *(_DWORD *)(v17 + 2900) = v14 | v71;
            v19 = ((unsigned int)v14 | v71) != v18;
            goto LABEL_58;
          }
          _rcu_read_unlock(v16);
          v14 = ieee80211_ibss_add_sta(v6, v2 + 16, v2 + 10, v71);
          v15 = v14;
        }
        if ( !v15 )
          goto LABEL_72;
        v19 = 0;
LABEL_58:
        v39 = v6;
        if ( (*(_BYTE *)(v15 + 2698) & 1) == 0
          && (*(_QWORD *)(v9 + 112) || *(_QWORD *)(v9 + 400))
          && *(unsigned __int16 *)(v74 + 128) >= 4u )
        {
          v40 = v15;
          *(_BYTE *)(v15 + 2698) = 1;
          v14 = ieee80211_check_fast_xmit(v15);
          v15 = v40;
          v39 = v6;
        }
        if ( *(_QWORD *)(v9 + 136) )
        {
          if ( *(_QWORD *)(v9 + 128) )
          {
            v41 = *(_DWORD *)(v39 + 2408);
            if ( v41 > 7 || ((1 << v41) & 0xC1) == 0 )
            {
              v50 = *(_DWORD *)(v15 + 3112);
              v84 = 0;
              v85[0] = 0;
              v72 = v50;
              v82 = 0;
              v83 = 0;
              v70 = v39;
              v51 = v15;
              cfg80211_chandef_create(&v82, v12, 0);
              ieee80211_chandef_ht_oper(*(_QWORD *)(v9 + 136), &v82);
              v52 = *(__int64 **)(v9 + 128);
              v76 = v51;
              v54 = v52[1];
              v53 = v52[2];
              v55 = *((_WORD *)v52 + 12);
              v56 = *v52;
              v88 = v55;
              v87[1] = v54;
              v87[2] = v53;
              v87[0] = v56;
              v57 = v19 | ieee80211_ht_cap_ie_to_sta_ht_cap(v70, v73, (__int64)v87, v51 + 1640);
              if ( *(_QWORD *)(v9 + 152) && (v58 = *(unsigned int **)(v9 + 144)) != nullptr )
              {
                v59 = v6;
                if ( (unsigned int)(*(_DWORD *)(v6 + 2408) - 1) >= 2 )
                {
                  v78 = *(_QWORD *)(v76 + 2948);
                  v79 = *(_QWORD *)(v76 + 2956);
                  ieee80211_chandef_vht_oper(v74, *v58);
                  v60 = *(__int64 **)(v9 + 144);
                  v61 = *v60;
                  v81 = *((_DWORD *)v60 + 2);
                  v80 = v61;
                  ieee80211_vht_cap_ie_to_sta_vht_cap(v6, v73, &v80, 0, v76 + 1640);
                  v59 = v6;
                  v63 = v78 != *(_QWORD *)(v76 + 2948) || v79 != *(_QWORD *)(v76 + 2956);
                  LOBYTE(v57) = v63 | v57;
                }
              }
              else
              {
                v59 = v6;
              }
              v64 = (v72 != *(_DWORD *)(v76 + 3112)) | v57;
              v14 = cfg80211_chandef_compatible(v59 + 2400, &v82);
              if ( !v14 )
                __break(0x800u);
              v15 = v76;
              if ( (v64 & 1) == 0 )
                goto LABEL_72;
              goto LABEL_68;
            }
          }
        }
        if ( v19 )
        {
LABEL_68:
          v42 = *(unsigned __int8 *)(v15 + 3110);
          *(_BYTE *)(v15 + 3110) = 0;
          v43 = v15;
          rate_control_rate_init(v15);
          if ( *(unsigned __int8 *)(v43 + 3110) == v42 )
            v44 = 4;
          else
            v44 = 12;
          v14 = drv_sta_rc_update(v74, v6, v43 + 2688, v44);
        }
LABEL_72:
        _rcu_read_unlock(v14);
LABEL_73:
        v10 = v77;
        goto LABEL_74;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        v68 = result;
        ++*(_DWORD *)(StatusReg + 16);
        result = _traceiter_drv_tx_last_beacon(0, v9);
        v69 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v69;
        if ( !v69 || (result = v68, !*(_QWORD *)(StatusReg + 16)) )
        {
          preempt_schedule_notrace(result);
          result = v68;
        }
      }
    }
    else
    {
      if ( *(_DWORD *)(result + 2520) != 1 )
        goto LABEL_107;
      v5 = *(unsigned int *)(a2 + 112);
      if ( (int)v5 < 26 )
        goto LABEL_107;
      v6 = *(_QWORD *)(result + 2440);
      if ( !v6 )
        goto LABEL_107;
      v9 = *(_QWORD *)(result + 1616);
    }
    v24 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v9 + 464) + 376LL);
    if ( v24 )
    {
      v25 = result;
      if ( *((_DWORD *)v24 - 1) != -1244592371 )
        __break(0x8228u);
      v26 = v24(v9);
      result = v25;
    }
    else
    {
      v26 = 0;
    }
    if ( v26 || (*(_BYTE *)(v2 + 4) & 1) == 0 )
    {
      v27 = *(_WORD *)(v2 + 20);
      v28 = *(_DWORD *)(v2 + 16);
      if ( (!(*(_DWORD *)v3 ^ v28 | (unsigned __int16)(*(_WORD *)(result + 2350) ^ v27))
         || (*(_DWORD *)&v27 & v28 & HIWORD(v28)) == 0xFFFF)
        && !*(_BYTE *)(v2 + 24) )
      {
        v29 = *(unsigned __int8 *)(v2 + 25);
        if ( v2 + 26 + v29 <= v2 + v5 )
        {
          if ( !*(_BYTE *)(v2 + 25)
            || (_DWORD)v29 == *(unsigned __int8 *)(result + 2384)
            && (v30 = result, v31 = bcmp((const void *)(v2 + 26), (const void *)(result + 2352), v29),
                              result = v30,
                              !v31) )
          {
            v32 = result;
            result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v6 + 16) + *(_DWORD *)(v9 + 1508)), 2080);
            if ( result )
            {
              v33 = *(int *)(v9 + 1508);
              v34 = result;
              v35 = *(_QWORD *)(result + 224) + v33;
              LODWORD(v33) = *(_DWORD *)(result + 208) + v33;
              *(_QWORD *)(result + 224) = v35;
              *(_DWORD *)(result + 208) = v33;
              skb_put_data();
              v36 = *(_QWORD *)(v34 + 224);
              v37 = *(_DWORD *)(v2 + 10);
              *(_WORD *)(v36 + 8) = *(_WORD *)(v2 + 14);
              *(_DWORD *)(v36 + 4) = v37;
              v38 = *(_DWORD *)(v34 + 40);
              *(_DWORD *)(v34 + 40) = v38 | 0x10000;
              if ( !*(_BYTE *)(v2 + 25) )
                *(_DWORD *)(v34 + 40) = v38 | 0x10004;
              result = ieee80211_tx_skb_tid(v32, v34, 7, 0xFFFFFFFFLL);
            }
          }
        }
      }
    }
  }
LABEL_107:
  _ReadStatusReg(SP_EL0);
  return result;
}
