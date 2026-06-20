__int64 __fastcall ieee80211_sta_work(__int64 result)
{
  __int64 v1; // x21
  __int64 v2; // x22
  __int64 v3; // x26
  __int64 v4; // x19
  __int64 v5; // x28
  __int64 v6; // x8
  __int16 v7; // w10
  int v8; // w9
  __int64 v9; // x9
  __int64 v10; // x1
  __int64 v11; // x8
  __int64 v12; // x1
  __int64 v13; // x8
  __int64 v14; // x1
  __int64 v15; // x27
  __int64 v16; // x1
  int v17; // w8
  int *v18; // x9
  int v19; // w9
  __int64 v20; // x20
  __int64 v21; // x1
  __int64 v22; // x0
  __int64 v23; // x8
  int v24; // w11
  int v25; // w8
  __int64 v26; // x25
  __int64 v27; // x3
  __int64 v28; // x8
  int v29; // w24
  __int64 v30; // x2
  __int64 elem_match; // x0
  __int64 v32; // x11
  __int64 v33; // x9
  int v34; // w8
  __int64 v35; // x12
  char v36; // w11
  __int64 v37; // x11
  __int64 v38; // x15
  int v39; // w14
  __int64 v40; // x16
  unsigned int ***v41; // x17
  unsigned int **v42; // x14
  __int64 v43; // x16
  __int64 v44; // x16
  __int64 v45; // x15
  __int64 v46; // x0
  __int64 v47; // x17
  __int64 v48; // x10
  __int64 v49; // x8
  __int64 v50; // x10
  __int64 v51; // x0
  __int64 v52; // x24
  __int64 v53; // x0
  __int64 v54; // x8
  int v55; // w10
  unsigned int v56; // w8
  unsigned int v57; // w24
  __int64 v58; // x0
  __int64 v59; // x26
  __int16 v60; // w10
  int v61; // w9
  __int64 v62; // x0
  __int16 v63; // w24
  __int16 v64; // w8
  __int16 v65; // w10
  int v66; // w9
  _BYTE *v67; // x0
  size_t v68; // x2
  __int16 v69; // w9
  __int64 v70; // x5
  __int64 v71; // x6
  __int64 v72; // x24
  __int64 v73; // x22
  __int64 v74; // x1
  __int64 v75; // x0
  unsigned int v76; // w26
  __int64 v77; // x25
  void *v78; // x0
  unsigned int v79; // w25
  __int64 v80; // x0
  __int64 v81; // x8
  unsigned int v82; // w25
  void *v83; // x0
  __int64 v84; // x24
  __int64 v85; // x0
  int v86; // w8
  unsigned __int64 StatusReg; // x24
  __int64 v88; // x25
  __int64 v89; // x0
  __int64 v90; // [xsp+10h] [xbp-70h]
  __int64 v91; // [xsp+18h] [xbp-68h]
  __int64 v92; // [xsp+20h] [xbp-60h]
  _BYTE *v93; // [xsp+28h] [xbp-58h]
  __int16 v94; // [xsp+28h] [xbp-58h]
  __int64 v95; // [xsp+30h] [xbp-50h]
  __int64 v96; // [xsp+30h] [xbp-50h]
  __int16 v97; // [xsp+3Ch] [xbp-44h] BYREF
  __int64 v98; // [xsp+40h] [xbp-40h] BYREF
  __int64 v99; // [xsp+48h] [xbp-38h]
  __int64 v100; // [xsp+50h] [xbp-30h]
  __int64 v101; // [xsp+58h] [xbp-28h] BYREF
  __int64 v102; // [xsp+60h] [xbp-20h]
  __int64 v103; // [xsp+68h] [xbp-18h]
  __int16 v104; // [xsp+70h] [xbp-10h]
  __int64 v105; // [xsp+78h] [xbp-8h]

  v4 = result;
  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(result + 1616);
  if ( *(_BYTE *)(result + 2507) != 1 )
    goto LABEL_19;
  v6 = *(_QWORD *)(result + 2480);
  v7 = *(_WORD *)(result + 2508);
  v8 = *(unsigned __int8 *)(result + 2506);
  *(_BYTE *)(result + 2507) = 0;
  if ( v6 && (v7 & 0xFC) == 0xB0 )
  {
    if ( v8 )
    {
      v9 = 25;
      if ( *(_WORD *)(v6 + 20) == 3 )
        v9 = 500;
      *(_QWORD *)(v6 + 8) = jiffies + v9;
      v10 = *(_QWORD *)(*(_QWORD *)(result + 2480) + 8LL);
      if ( !*(_QWORD *)(result + 2272) || v10 - *(_QWORD *)(result + 2280) < 0 )
        result = mod_timer(result + 2264, v10);
    }
    else
    {
      *(_QWORD *)(v6 + 8) = jiffies - 1LL;
    }
    *(_BYTE *)(*(_QWORD *)(v4 + 2480) + 42LL) = 1;
LABEL_19:
    v13 = *(_QWORD *)(v4 + 2480);
    if ( !v13 )
      goto LABEL_28;
    goto LABEL_20;
  }
  v11 = *(_QWORD *)(result + 2488);
  if ( !v11 || (*(_BYTE *)(v11 + 1040) & 1) != 0 || (v7 & 0xDC | 0x20) != 0x20 )
    goto LABEL_19;
  if ( v8 )
  {
    *(_QWORD *)(v11 + 984) = jiffies + 25LL;
    v12 = *(_QWORD *)(*(_QWORD *)(result + 2488) + 984LL);
    if ( !*(_QWORD *)(result + 2272) || v12 - *(_QWORD *)(result + 2280) < 0 )
      result = mod_timer(result + 2264, v12);
  }
  else
  {
    *(_QWORD *)(v11 + 984) = jiffies - 1LL;
  }
  *(_BYTE *)(*(_QWORD *)(v4 + 2488) + 1039LL) = 1;
  v13 = *(_QWORD *)(v4 + 2480);
  if ( v13 )
  {
LABEL_20:
    if ( *(_BYTE *)(v13 + 42) == 1 )
    {
      if ( (__int64)(*(_QWORD *)(v13 + 8) - jiffies) < 0 )
      {
        if ( (*(_BYTE *)(v13 + 39) & 1) != 0 || *(_BYTE *)(v13 + 40) == 1 )
        {
          result = ieee80211_destroy_auth_data(v4, 0);
        }
        else
        {
          result = ieee80211_auth_0(v4);
          if ( (_DWORD)result )
          {
            v23 = *(_QWORD *)(v4 + 2480);
            WORD2(v98) = 0;
            v24 = *(_DWORD *)(v23 + 48);
            LOWORD(v23) = *(_WORD *)(v23 + 52);
            v102 = 0x200000000LL;
            v103 = 0;
            v101 = 1;
            LODWORD(v98) = v24;
            WORD2(v98) = v23;
            ieee80211_destroy_auth_data(v4, 0);
            cfg80211_auth_timeout(*(_QWORD *)(v4 + 1608), &v98);
            result = drv_event_callback(*(_QWORD *)(v4 + 1616), v4, &v101);
          }
        }
      }
      else
      {
        v14 = *(_QWORD *)(v13 + 8);
        if ( !*(_QWORD *)(v4 + 2272) || v14 - *(_QWORD *)(v4 + 2280) < 0 )
          result = mod_timer(v4 + 2264, v14);
      }
    }
  }
LABEL_28:
  v15 = *(_QWORD *)(v4 + 2488);
  if ( !v15 || *(_BYTE *)(v15 + 1039) != 1 )
    goto LABEL_35;
  if ( (__int64)(*(_QWORD *)(v15 + 984) - jiffies) >= 0 )
  {
    v16 = *(_QWORD *)(v15 + 984);
LABEL_32:
    if ( !*(_QWORD *)(v4 + 2272) || v16 - *(_QWORD *)(v4 + 2280) < 0 )
      result = mod_timer(v4 + 2264, v16);
LABEL_35:
    if ( (*(_BYTE *)(v4 + 2500) & 2) == 0 )
      goto LABEL_65;
    goto LABEL_36;
  }
  v20 = v4 + 4096;
  if ( *(_BYTE *)(v15 + 1037) != 1 || *(_BYTE *)(v4 + 4179) == 1 )
  {
    v25 = *(_DWORD *)(v15 + 992);
    v26 = *(_QWORD *)(v4 + 1616);
    *(_BYTE *)(v15 + 1040) = 0;
    v27 = (unsigned int)(v25 + 1);
    *(_DWORD *)(v15 + 992) = v27;
    if ( (int)v27 < 4 )
    {
      printk(&unk_B9B2D, v4 + 1640, v15 + 960, v27);
      v20 = *(_QWORD *)(v4 + 1616);
      v1 = *(_QWORD *)(v4 + 2488);
      v29 = *(_DWORD *)(v4 + 4720);
      if ( *(_BYTE *)(v4 + 5848) == 1 )
      {
        if ( v29 == 2 )
        {
          LOBYTE(v29) = 8;
        }
        else if ( v29 == 3 )
        {
          LOBYTE(v29) = 9;
        }
      }
      v30 = *(_QWORD *)(v1 + 1152);
      v97 = 0;
      LODWORD(v99) = 0;
      v98 = 0;
      v101 = 0;
      v102 = 0;
      if ( v30 )
      {
        elem_match = cfg80211_find_elem_match(127, v1 + 1168, v30, 0, 0, 0);
        v32 = *(_QWORD *)(v1 + 1152);
        v3 = elem_match;
      }
      else
      {
        v32 = 0;
        v3 = 0;
      }
      v33 = 0;
      v2 = 0;
      v34 = 0;
      v35 = v32 + *(unsigned int *)(v20 + 104) + *(unsigned __int8 *)(v1 + 1034) + 16LL * (*(_QWORD *)(v1 + 1144) != 0);
      if ( (unsigned __int8)v29 == 4 )
        v36 = 3;
      else
        v36 = v29;
      v37 = 1LL << v36;
      v38 = v35 + 61;
      do
      {
        v41 = (unsigned int ***)(v1 + (v33 << 6));
        v42 = *v41;
        if ( *v41 )
        {
          v43 = **v42;
          if ( (unsigned int)v43 > 5 )
            goto LABEL_131;
          v44 = *(_QWORD *)(*(_QWORD *)(v20 + 72) + 8 * v43 + 328);
          v45 = (__int64)v41[4]
              + v38
              + (unsigned int)(*(_DWORD *)(v44 + 24) + 4)
              + (unsigned int)(2 * *(_DWORD *)(v44 + 20) + 2);
          if ( (unsigned __int8)v29 >= 0xCu )
          {
            __break(0x800u);
          }
          else
          {
            v46 = *(unsigned __int16 *)(v44 + 92);
            if ( *(_WORD *)(v44 + 92) )
            {
              v47 = *(_QWORD *)(v44 + 96);
              while ( ((unsigned __int16)v37 & *(_WORD *)v47) == 0 )
              {
                --v46;
                v47 += 128;
                if ( !v46 )
                  goto LABEL_79;
              }
              if ( v47 )
                v45 += *(unsigned int *)(v47 + 120);
            }
          }
LABEL_79:
          ++v34;
          v39 = *((_WORD *)v42 + 35) & 0x10;
          if ( *(_DWORD *)(v44 + 16) == 3 )
            v40 = 108;
          else
            v40 = 103;
          v2 = v39 | (unsigned int)v2;
          v38 = v45 + v40 + 67;
        }
        ++v33;
      }
      while ( v33 != 15 );
      v48 = v38 + (unsigned int)(13 * v34 - 13);
      v49 = *(unsigned int *)(v1 + 1044);
      v50 = v48 + 13;
      if ( *(_WORD *)(v4 + 5800) )
        v51 = v50;
      else
        v51 = v38;
      if ( (unsigned int)v49 <= 0xE )
      {
        v52 = *(_QWORD *)(v4 + 8 * v49 + 4568);
        if ( !v52 || !*(_QWORD *)(v1 + (v49 << 6)) )
        {
          __break(0x800u);
          goto LABEL_45;
        }
        v53 = _alloc_skb(v51, 3264, 0, 0xFFFFFFFFLL);
        if ( !v53 )
          goto LABEL_45;
        v54 = *(int *)(v20 + 104);
        v55 = *(_DWORD *)(v53 + 208);
        v92 = v26;
        *(_QWORD *)(v53 + 224) += v54;
        *(_DWORD *)(v53 + 208) = v55 + v54;
        v56 = *(unsigned __int16 *)(v4 + 2500);
        if ( (*(_QWORD *)(v20 + 96) & 0x400000000000LL) != 0
          && *(_DWORD *)(v52 + 552) >= 4u
          && v3
          && *(unsigned __int8 *)(v3 + 1) >= 3u )
        {
          *(_BYTE *)(v3 + 4) |= 0x40u;
        }
        v90 = v52;
        v91 = v3;
        v57 = v56 >> 3;
        v96 = v53;
        v58 = skb_put(v53, 24);
        *(_QWORD *)(v58 + 8) = 0;
        *(_QWORD *)(v58 + 16) = 0;
        v59 = v58;
        *(_QWORD *)v58 = 0;
        v60 = *(_WORD *)(v4 + 4806);
        *(_DWORD *)(v58 + 4) = *(_DWORD *)(v4 + 4802);
        *(_WORD *)(v58 + 8) = v60;
        v61 = *(_DWORD *)(v4 + 5842);
        *(_WORD *)(v58 + 14) = *(_WORD *)(v4 + 5846);
        *(_DWORD *)(v58 + 10) = v61;
        LOWORD(v61) = *(_WORD *)(v4 + 4806);
        *(_DWORD *)(v58 + 16) = *(_DWORD *)(v4 + 4802);
        *(_WORD *)(v58 + 20) = v61;
        v62 = *(unsigned __int16 *)(v20 + 12);
        if ( *(_BYTE *)(v1 + 1041) == 1 )
          LOWORD(v62) = ieee80211_encode_usf(v62);
        v63 = v57 & 0x1000;
        v94 = v62;
        if ( *(_DWORD *)(v1 + 996) | *(unsigned __int16 *)(v1 + 1000) )
        {
          skb_put(v96, 10);
          v64 = 32;
          *(_WORD *)v59 = 32;
          *(_WORD *)(v59 + 26) = v94;
          v65 = *(_WORD *)(v1 + 1000);
          *(_DWORD *)(v59 + 28) = *(_DWORD *)(v1 + 996);
          *(_WORD *)(v59 + 32) = v65;
        }
        else
        {
          skb_put(v96, 4);
          v64 = 0;
          *(_WORD *)v59 = 0;
          *(_WORD *)(v59 + 26) = v94;
        }
        v66 = *(unsigned __int8 *)(v1 + 1034);
        WORD1(v98) = v64;
        v67 = (_BYTE *)skb_put(v96, (unsigned int)(v66 + 2));
        *v67 = 0;
        v68 = *(unsigned __int8 *)(v1 + 1034);
        v93 = v67;
        v67[1] = v68;
        memcpy(v67 + 2, (const void *)(v1 + 1002), v68);
        v69 = v63 | v2;
        v70 = *(_QWORD *)(v1 + 1152);
        v71 = *(unsigned int *)(v1 + 1044);
        v72 = v1 + 1168;
        v97 = v69 | (*(_DWORD *)(v90 + 552) < 5u);
        v73 = ieee80211_assoc_link_elems(v4, v96, &v97, v91, v1 + 1168, v70, v71);
        *(_WORD *)(v59 + 24) = v97;
        v74 = *(_QWORD *)(v1 + 1152);
        if ( v74 )
        {
          v75 = ieee80211_ie_split_vendor(v1 + 1168, v74, v73);
          v76 = v75 - v73;
          v77 = v75;
          v78 = (void *)skb_put(v96, (unsigned int)(v75 - v73));
          memcpy(v78, (const void *)(v72 + v73), v76);
          v73 = v77;
        }
        v3 = v92;
        if ( *(_BYTE *)(v1 + 1035) == 1 )
        {
          if ( *(_BYTE *)(v1 + 1036) == 1 )
            v79 = *(_DWORD *)(v4 + 2516) | (32 * *(_DWORD *)(v4 + 2520));
          else
            v79 = 0;
          v80 = skb_put(v96, 9);
          ieee80211_add_wmm_info_ie(v80, v79);
        }
        v81 = *(_QWORD *)(v1 + 1152);
        if ( v81 )
        {
          v82 = v81 - v73;
          v83 = (void *)skb_put(v96, (unsigned int)(v81 - v73));
          memcpy(v83, (const void *)(v72 + v73), v82);
        }
        v84 = v96;
        if ( *(_QWORD *)(v1 + 1144) && (fils_encrypt_assoc_req(v96, v1) & 0x80000000) != 0 )
          goto LABEL_132;
        v2 = *(_QWORD *)(v96 + 216) + *(unsigned int *)(v96 + 208);
        kfree(*(_QWORD *)(v4 + 2944));
        v85 = kmemdup_noprof(v93, v2 - (_QWORD)v93);
        *(_QWORD *)(v4 + 2944) = v85;
        if ( !v85 )
          goto LABEL_132;
        goto LABEL_123;
      }
    }
    else
    {
      printk(&unk_B8709, v4 + 1640, v15 + 960, v27);
      v28 = *(unsigned int *)(v15 + 1044);
      if ( (unsigned int)v28 < 0xF )
      {
        cfg80211_unlink_bss(*(_QWORD *)(v26 + 72), *(_QWORD *)(v15 + (v28 << 6)));
        goto LABEL_45;
      }
    }
LABEL_131:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v88 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ieee80211_send_assoc__alloc_tag;
    v89 = kmemdup_noprof(v93, v2 - (_QWORD)v93);
    *(_QWORD *)(StatusReg + 80) = v88;
    v84 = v95;
    *(_QWORD *)(v4 + 2944) = v89;
    if ( !v89 )
    {
LABEL_132:
      consume_skb(v84);
      goto LABEL_45;
    }
LABEL_123:
    *(_QWORD *)(v4 + 2952) = v2 - (_QWORD)v93;
    LODWORD(v99) = *(_DWORD *)(v1 + 1044);
    drv_mgd_prepare_tx(v20, v4, &v98);
    v86 = *(_DWORD *)(v84 + 40);
    *(_DWORD *)(v84 + 40) = v86 | 0x10000;
    if ( (*(_QWORD *)(v20 + 96) & 0x10000) != 0 )
      *(_DWORD *)(v84 + 40) = v86 | 0x110001;
    result = ieee80211_tx_skb_tid(v4, v84, 7, 0xFFFFFFFFLL);
    if ( (*(_QWORD *)(v3 + 96) & 0x10000) != 0 )
    {
      result = round_jiffies_up(jiffies + 125LL);
      v16 = result;
      *(_QWORD *)(v15 + 984) = result;
    }
    else
    {
      v16 = jiffies + 50LL;
      *(_QWORD *)(v15 + 984) = jiffies + 50LL;
    }
    *(_BYTE *)(v15 + 1039) = 1;
    goto LABEL_32;
  }
LABEL_45:
  v101 = 1;
  v102 = 0x200000001LL;
  v103 = 0;
  ieee80211_destroy_assoc_data(v4, 2);
  result = drv_event_callback(*(_QWORD *)(v4 + 1616), v4, &v101);
  if ( (*(_BYTE *)(v4 + 2500) & 2) == 0 )
    goto LABEL_65;
LABEL_36:
  if ( (*(_BYTE *)(v4 + 2477) & 8) != 0 )
  {
    v17 = *(_DWORD *)(v4 + 2472);
    v18 = (int *)&max_nullfunc_tries;
    if ( (*(_QWORD *)(v5 + 96) & 0x10000LL) == 0 )
      v18 = &max_probe_tries;
    if ( v17 )
    {
      v19 = *v18;
      if ( *(_BYTE *)(v4 + 2476) == 1 )
      {
        if ( v17 >= v19 )
          goto LABEL_52;
LABEL_51:
        result = ieee80211_mgd_probe_ap_send(v4);
        goto LABEL_65;
      }
      v21 = *(_QWORD *)(v4 + 2464);
      if ( jiffies - v21 >= 0 )
      {
        if ( (*(_QWORD *)(v5 + 96) & 0x10000) != 0 )
        {
LABEL_52:
          v104 = 0;
          v102 = 0;
          v103 = 0;
          v101 = 0;
          ieee80211_set_disassoc(v4, 0xC0u, 4u, 0, (__int64)&v101);
          v22 = *(_QWORD *)(v4 + 1608);
          v98 = 1;
          v99 = 3;
          v100 = 4;
          cfg80211_tx_mlme_mgmt(v22, &v101, 26, 0);
          result = drv_event_callback(*(_QWORD *)(v4 + 1616), v4, &v98);
          goto LABEL_65;
        }
        if ( v17 >= v19 )
        {
          result = ieee80211_sta_connection_lost(v4, 4u, 0);
          goto LABEL_65;
        }
        goto LABEL_51;
      }
      if ( !*(_QWORD *)(v4 + 2272) || v21 - *(_QWORD *)(v4 + 2280) < 0 )
        result = mod_timer(v4 + 2264, v21);
    }
    else
    {
      result = ieee80211_reset_ap_probe(v4);
    }
  }
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return result;
}
