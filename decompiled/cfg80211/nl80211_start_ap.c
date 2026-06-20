__int64 __fastcall nl80211_start_ap(__int64 a1, _QWORD *a2)
{
  unsigned int **v2; // x20
  __int64 v3; // x23
  __int64 v4; // x26
  _QWORD *v5; // x8
  __int64 v6; // x24
  __int64 v7; // x9
  unsigned int v8; // w21
  __int64 v9; // x19
  __int64 v10; // x22
  int v11; // w9
  bool v12; // zf
  __int64 v13; // x9
  unsigned int started; // w25
  __int64 v16; // x0
  __int64 v17; // x8
  _QWORD *v18; // x8
  __int64 v19; // x9
  size_t v20; // x2
  __int64 v21; // x9
  __int64 v22; // x8
  unsigned int v23; // w8
  __int64 v24; // x1
  __int64 v25; // x2
  unsigned int *v26; // x8
  __int64 v27; // x0
  bool v28; // zf
  _QWORD *v29; // x8
  __int64 v30; // x9
  __int64 v31; // x9
  int v32; // w9
  __int64 v33; // x9
  int v34; // w9
  unsigned int *v35; // x8
  unsigned int *v36; // x10
  unsigned int *v37; // x11
  int v38; // w8
  unsigned int *v39; // x0
  unsigned int *v40; // x1
  _QWORD *v41; // x1
  __int64 v42; // x8
  int v43; // w8
  __int64 v44; // x8
  unsigned __int64 v45; // x0
  __int64 v46; // x0
  _QWORD *v47; // x8
  __int64 v48; // x9
  int v49; // w9
  int v50; // w9
  unsigned int *v51; // x8
  __int64 v52; // x10
  unsigned int *v53; // x11
  size_t v54; // x24
  unsigned int *v55; // x1
  __int64 v56; // [xsp+8h] [xbp-18h] BYREF
  int v57; // [xsp+10h] [xbp-10h]
  __int64 v58; // [xsp+18h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = (_QWORD *)a2[4];
  v57 = 0;
  v6 = a2[6];
  v56 = 0;
  v7 = v5[313];
  if ( v7 )
    v8 = *(unsigned __int8 *)(v7 + 4);
  else
    v8 = 0;
  v9 = a2[7];
  v10 = *(_QWORD *)(v9 + 992);
  v11 = *(_DWORD *)(v10 + 8);
  v12 = v11 == 3 || v11 == 9;
  if ( !v12 || !*(_QWORD *)(*(_QWORD *)v6 + 112LL) )
  {
    started = -95;
    goto LABEL_14;
  }
  if ( v8 > 0xE )
  {
    __break(0x5512u);
LABEL_85:
    v41 = *(_QWORD **)(v3 + 32);
    goto LABEL_86;
  }
  v13 = v10 + 72LL * v8;
  if ( (*(_BYTE *)(v13 + 440) & 1) != 0 )
  {
    started = -16;
    goto LABEL_14;
  }
  v4 = v13 + 392;
  if ( *(_DWORD *)(v13 + 400) )
  {
    started = -114;
    goto LABEL_14;
  }
  if ( !v5[12] || !v5[13] || !v5[14] )
  {
    started = -22;
    goto LABEL_14;
  }
  v3 = (__int64)a2;
  v16 = _kmalloc_cache_noprof(unregister_netdevice_notifier, 3520, 928);
  v2 = (unsigned int **)v16;
  if ( !v16 )
  {
    started = -12;
    goto LABEL_14;
  }
  started = nl80211_parse_beacon(v6, *(_QWORD *)(v3 + 32), v16 + 32, *(_QWORD *)(v3 + 64));
  if ( started )
    goto LABEL_36;
  v17 = *(_QWORD *)(v3 + 32);
  *((_DWORD *)v2 + 52) = *(_DWORD *)(*(_QWORD *)(v17 + 96) + 4LL);
  *((_DWORD *)v2 + 53) = *(_DWORD *)(*(_QWORD *)(v17 + 104) + 4LL);
  started = cfg80211_validate_beacon_int(v6, *(unsigned int *)(*(_QWORD *)(v9 + 992) + 8LL));
  if ( started )
    goto LABEL_36;
  v18 = *(_QWORD **)(v3 + 32);
  v19 = v18[52];
  if ( !v19 )
  {
    if ( !*(_WORD *)(v10 + 1472) )
      goto LABEL_31;
LABEL_35:
    started = -22;
    goto LABEL_36;
  }
  v2[27] = (unsigned int *)(v19 + 4);
  v12 = (unsigned __int16)(*(_WORD *)v18[52] - 4) == 0;
  v20 = (unsigned __int16)(*(_WORD *)v18[52] - 4);
  v2[28] = (unsigned int *)v20;
  if ( v12 )
    goto LABEL_35;
  if ( *(_BYTE *)(v10 + 344) )
  {
    if ( (_DWORD)v20 != *(unsigned __int8 *)(v10 + 344) || bcmp((const void *)(v10 + 312), (const void *)(v19 + 4), v20) )
      goto LABEL_35;
    v18 = *(_QWORD **)(v3 + 32);
  }
LABEL_31:
  v21 = v18[126];
  if ( v21 )
    *((_DWORD *)v2 + 58) = *(_DWORD *)(v21 + 4);
  *((_BYTE *)v2 + 360) = v18[70] != 0;
  v22 = v18[53];
  if ( v22 )
  {
    v23 = *(_DWORD *)(v22 + 4);
    *((_DWORD *)v2 + 91) = v23;
    if ( v23 > 7 )
      goto LABEL_35;
    started = -22;
    v28 = (*(_BYTE *)(v6 + 1110) & 8) == 0 && v23 == 4;
    if ( v28 || (v23 | 0xFFFFFFF8) >= 0xFFFFFFFD )
      goto LABEL_36;
  }
  else
  {
    *((_DWORD *)v2 + 91) = 8;
  }
  started = nl80211_crypto_settings(v6, v3, v2 + 30, 5);
  if ( started )
    goto LABEL_36;
  v29 = *(_QWORD **)(v3 + 32);
  v30 = v29[150];
  if ( v30 )
  {
    if ( (*(_BYTE *)(v6 + 1100) & 4) == 0 )
    {
LABEL_50:
      started = -95;
      goto LABEL_36;
    }
    *((_DWORD *)v2 + 93) = *(unsigned __int16 *)(v30 + 4);
  }
  v31 = v29[162];
  if ( v31 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(v9 + 992) + 8LL) != 9 )
      goto LABEL_35;
    v32 = *(unsigned __int8 *)(v31 + 4);
    *((_BYTE *)v2 + 376) = v32;
    if ( v32 )
    {
      if ( (*(_BYTE *)(v6 + 1101) & 8) == 0 )
        goto LABEL_35;
    }
  }
  v33 = v29[163];
  if ( v33 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(v9 + 992) + 8LL) != 9 )
      goto LABEL_35;
    v34 = *(unsigned __int8 *)(v33 + 4);
    *((_BYTE *)v2 + 377) = v34 != 0;
    if ( v34 )
    {
      if ( (*(_BYTE *)(v6 + 1101) & 0x10) == 0 )
        goto LABEL_35;
    }
  }
  if ( v29[38] )
  {
    started = nl80211_parse_chandef(v6, v3, 0, (__int64)v2);
    if ( started )
      goto LABEL_36;
  }
  else
  {
    if ( *(_WORD *)(v10 + 1472) )
      goto LABEL_35;
    if ( *(_QWORD *)(v10 + 280) )
    {
      v35 = *(unsigned int **)(v10 + 304);
      v36 = *(unsigned int **)(v10 + 280);
      v37 = *(unsigned int **)(v10 + 288);
      v2[2] = *(unsigned int **)(v10 + 296);
      v2[3] = v35;
      *v2 = v36;
      v2[1] = v37;
    }
    else if ( (nl80211_get_ap_channel(v6, v2) & 1) == 0 )
    {
      goto LABEL_35;
    }
  }
  v38 = *(_DWORD *)(v10 + 8);
  v39 = v2[6];
  v40 = v2[17];
  LOBYTE(v57) = 1;
  LODWORD(v56) = v38;
  HIDWORD(v56) = cfg80211_get_6ghz_power_type(v39, v40);
  if ( (cfg80211_reg_check_beaconing(v6 + 992, (__int64)v2, (unsigned int *)&v56) & 1) == 0 )
    goto LABEL_35;
  v41 = *(_QWORD **)(v3 + 32);
  if ( v41[90] )
  {
    started = nl80211_parse_tx_bitrate_mask(v3, (int)v41, 90, (char *)v2 + 396);
    if ( started )
      goto LABEL_36;
    started = validate_beacon_tx_rate(v6, **v2, (char *)v2 + 396);
    if ( started )
      goto LABEL_36;
    v41 = *(_QWORD **)(v3 + 32);
  }
  v42 = v41[213];
  if ( v42 )
  {
    v43 = *(unsigned __int8 *)(v42 + 4);
    *((_DWORD *)v2 + 92) = v43;
    if ( v43 )
    {
      if ( v43 == 2 )
      {
        if ( (*(_BYTE *)(v6 + 1103) & 2) == 0 )
          goto LABEL_35;
      }
      else if ( v43 != 1 || (*(_BYTE *)(v6 + 1103) & 1) == 0 )
      {
        goto LABEL_35;
      }
    }
  }
  else
  {
    *((_DWORD *)v2 + 92) = 0;
  }
  v44 = v41[226];
  *((_BYTE *)v2 + 392) = v44 != 0;
  if ( v44 && !*(_QWORD *)(v6 + 1336) )
    goto LABEL_50;
  if ( v41[165] )
  {
    v45 = parse_acl_data(v6 + 992, v3);
    v2[48] = (unsigned int *)v45;
    if ( v45 > 0xFFFFFFFFFFFFF000LL )
    {
      started = v45;
      v2[48] = nullptr;
      goto LABEL_36;
    }
    goto LABEL_85;
  }
LABEL_86:
  *((_BYTE *)v2 + 812) = v41[278] != 0;
  v46 = v41[279];
  if ( v46 )
  {
    started = nl80211_parse_he_obss_pd(v46, (char *)v2 + 820);
    if ( started )
      goto LABEL_36;
    v41 = *(_QWORD **)(v3 + 32);
  }
  if ( v41[294] )
  {
    started = nl80211_parse_fils_discovery(v6, v41[294], v2 + 106);
    if ( started )
      goto LABEL_36;
    v41 = *(_QWORD **)(v3 + 32);
  }
  if ( !v41[295] )
  {
LABEL_95:
    if ( v41[306] )
    {
      started = nl80211_parse_mbssid_config(v6 + 992, v9);
      if ( started )
        goto LABEL_36;
    }
    if ( (*((_BYTE *)v2 + 913) & 1) == 0 && v2[14] )
      goto LABEL_35;
    started = nl80211_calculate_ap_params(v2);
    if ( started )
      goto LABEL_36;
    started = nl80211_validate_ap_phy_operation(v2);
    if ( started )
      goto LABEL_36;
    v47 = *(_QWORD **)(v3 + 32);
    v48 = v47[309];
    if ( v48 )
    {
      v49 = *(_DWORD *)(v48 + 4);
    }
    else
    {
      if ( !v47[261] )
      {
LABEL_109:
        v50 = *(_DWORD *)(v10 + 100);
        if ( !v50 || !v47[204] || v50 == *(_DWORD *)(v3 + 4) )
        {
          started = rdev_start_ap(v6, v9, v2);
          if ( !started )
          {
            *(_DWORD *)(v4 + 8) = *((_DWORD *)v2 + 52);
            v51 = v2[3];
            v52 = (__int64)*v2;
            v53 = v2[1];
            *(_QWORD *)(v4 + 32) = v2[2];
            *(_QWORD *)(v4 + 40) = v51;
            *(_QWORD *)(v4 + 16) = v52;
            *(_QWORD *)(v4 + 24) = v53;
            *(_BYTE *)(v10 + 344) = (unsigned __int8)v2[28];
            v54 = (size_t)v2[28];
            if ( v54 >= 0x21 && (nl80211_start_ap___already_done & 1) == 0 )
            {
              v55 = v2[28];
              nl80211_start_ap___already_done = 1;
              _warn_printk(
                "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                (size_t)v55,
                "field \"wdev->u.ap.ssid\" at ../soc-repo/net/wireless/nl80211.c:6408",
                0x20u);
              __break(0x800u);
            }
            memcpy((void *)(v10 + 312), v2[27], v54);
            if ( *(_QWORD *)(*(_QWORD *)(v3 + 32) + 1632LL) )
              *(_DWORD *)(v10 + 100) = *(_DWORD *)(v3 + 4);
            nl80211_send_ap_started(v10, v8);
            started = 0;
          }
          goto LABEL_36;
        }
        goto LABEL_35;
      }
      v49 = *((_DWORD *)v2 + 204) | 1;
    }
    *((_DWORD *)v2 + 204) = v49;
    goto LABEL_109;
  }
  started = nl80211_parse_unsol_bcast_probe_resp(v6, v41[295], v2 + 110);
  if ( !started )
  {
    v41 = *(_QWORD **)(v3 + 32);
    goto LABEL_95;
  }
LABEL_36:
  kfree(v2[48]);
  kfree(v2[13]);
  v26 = v2[113];
  if ( v26 )
  {
    v27 = *((_QWORD *)v26 + 4);
    if ( v27 )
    {
      if ( v27 != v9 )
        dev_put(v27, v24, v25);
    }
  }
  kfree(v2[14]);
  kfree(v2);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return started;
}
