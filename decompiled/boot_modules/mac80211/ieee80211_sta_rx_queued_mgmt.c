__int64 __fastcall ieee80211_sta_rx_queued_mgmt(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // x19
  unsigned __int64 v7; // x8
  __int16 v8; // w22
  __int64 v9; // x20
  __int64 v10; // x8
  unsigned int v11; // w8
  __int64 v12; // x25
  __int64 v13; // x20
  __int64 v14; // x21
  __int64 v15; // x8
  int v16; // w9
  int v17; // w11
  int v18; // w8
  int v19; // w27
  unsigned int v20; // w23
  __int64 v21; // x10
  __int64 v22; // x24
  unsigned int v23; // w25
  __int64 v24; // x0
  __int64 v25; // x22
  __int64 v26; // x0
  __int64 v27; // x20
  __int64 v28; // x8
  __int64 v29; // x3
  unsigned int v30; // w21
  unsigned int v31; // w22
  unsigned int v32; // w6
  _QWORD *v33; // x23
  __int64 v34; // x1
  int v35; // w9
  __int64 v37; // x1
  __int64 v38; // x2
  __int64 v39; // x19
  __int64 v40; // x0
  __int64 v41; // x3
  __int64 v42; // x4
  __int64 v43; // x5
  __int64 v44; // x20
  int v45; // w8
  int v46; // w9
  __int64 v47; // x21
  unsigned int v48; // w22
  void *v49; // x0
  __int64 v50; // x21
  __int64 v51; // x22
  __int16 v53; // w9
  unsigned int v54; // w10
  __int64 v55; // x23
  int v56; // w8
  int v57; // w9
  __int64 v58; // x23
  __int64 v59; // x21
  unsigned int v60; // w22
  int v62; // w8
  __int64 v63; // x9
  __int64 v64; // x8
  __int64 v65; // x22
  __int64 v66; // x2
  __int64 v67; // x3
  __int64 v68; // x9
  __int64 v69; // x8
  __int16 *v70; // x9
  __int16 v71; // w9
  __int64 v72; // x19
  __int64 v73; // x2
  __int64 v74; // x19
  unsigned int v75; // w26
  const char *v76; // x2
  __int64 v77; // x3
  _WORD *v78; // x8
  __int64 v79; // x9
  bool v80; // zf
  unsigned __int16 *v81; // x9
  unsigned __int64 v82; // x10
  __int16 v83; // w9
  __int64 v84; // x11
  unsigned __int16 *v85; // x9
  unsigned __int64 v86; // x10
  __int16 v87; // w9
  __int64 v88; // x11
  __int64 v89; // x10
  unsigned __int16 *v90; // x10
  unsigned __int64 v91; // x9
  __int16 v92; // w9
  __int64 v93; // x11
  __int64 v94; // x0
  __int64 v95; // x9
  __int64 v96; // x3
  unsigned int v97; // w24
  unsigned int v98; // w19
  __int64 v99; // x23
  __int64 v100; // x1
  __int64 v101; // x0
  __int64 v102; // x0
  __int64 v103; // x2
  __int64 v104; // x3
  __int64 v105; // x9
  __int64 v106; // x14
  _QWORD *v107; // x17
  _BYTE *v108; // x16
  int v109; // w17
  int v110; // w9
  __int64 v111; // x9
  __int64 v112; // x10
  __int64 v113; // x0
  __int64 v114; // [xsp+0h] [xbp-220h] BYREF
  int v115; // [xsp+8h] [xbp-218h]
  __int64 v116; // [xsp+10h] [xbp-210h] BYREF
  __int64 v117; // [xsp+18h] [xbp-208h]
  __int64 v118; // [xsp+20h] [xbp-200h]
  __int64 v119; // [xsp+28h] [xbp-1F8h] BYREF
  __int64 v120; // [xsp+30h] [xbp-1F0h]
  __int64 v121; // [xsp+38h] [xbp-1E8h]
  __int64 v122; // [xsp+40h] [xbp-1E0h]
  __int64 v123; // [xsp+48h] [xbp-1D8h]
  __int64 v124; // [xsp+50h] [xbp-1D0h]
  __int64 v125; // [xsp+58h] [xbp-1C8h]
  int v126; // [xsp+60h] [xbp-1C0h]
  int v127; // [xsp+64h] [xbp-1BCh]
  __int64 v128; // [xsp+68h] [xbp-1B8h] BYREF
  int v129; // [xsp+70h] [xbp-1B0h] BYREF
  __int16 v130; // [xsp+74h] [xbp-1ACh]
  _QWORD s[53]; // [xsp+78h] [xbp-1A8h] BYREF

  s[51] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 224);
  v7 = *(unsigned __int8 *)(a2 + 86);
  v8 = *(_WORD *)v6;
  if ( (v7 & 1) != 0 )
  {
    v10 = (v7 >> 1) & 0xF;
    if ( (_DWORD)v10 == 15 )
      goto LABEL_175;
    v9 = *(_QWORD *)(result + 8 * v10 + 4568);
    if ( !v9 )
      goto LABEL_111;
  }
  else
  {
    v9 = result + 3616;
  }
  v11 = ((v8 & 0xF0u) - 16) >> 4;
  if ( v11 > 8 )
  {
    if ( ((v8 & 0xF0u) - 16) >> 4 > 0xA )
    {
      if ( v11 != 11 )
      {
        if ( v11 != 12
          || (*(_BYTE *)(result + 2477) & 8) == 0
          || *(_DWORD *)(result + 4802) ^ *(_DWORD *)(v6 + 16)
           | *(unsigned __int16 *)(result + 4806) ^ *(unsigned __int16 *)(v6 + 20) )
        {
          goto LABEL_111;
        }
        v35 = *(unsigned __int8 *)(v6 + 24);
        if ( v35 == 9 || v35 == 4 )
        {
          if ( *(_DWORD *)(a2 + 112) - 30 < 0 )
            goto LABEL_111;
          s[2] = (unsigned int)(*(_DWORD *)(a2 + 112) - 30);
          *(_QWORD *)((char *)&s[3] + 1) = 0;
          *(_OWORD *)((char *)&s[4] + 1) = 0u;
          s[0] = 5;
          s[1] = v6 + 30;
          LOBYTE(s[3]) = 1;
          s[6] = 0;
          s[7] = 0xFFFFFFFFLL;
          v26 = ieee802_11_parse_elems_full(s);
          if ( !v26 || *(_BYTE *)(v26 + 760) )
            goto LABEL_22;
          v62 = *(unsigned __int8 *)(v6 + 24);
          v63 = v6 + 26;
          v39 = v26;
          *(_QWORD *)(v26 + 280) = v63;
          v40 = v9;
          v41 = v39;
          v37 = *(_QWORD *)(a2 + 40);
          v38 = *(unsigned int *)(a2 + 56);
          if ( v62 == 9 )
            v43 = 2;
          else
            v43 = 3;
          v42 = v39;
        }
        else
        {
          if ( *(_BYTE *)(v6 + 24) || *(_DWORD *)(a2 + 112) - 26 < 0 )
            goto LABEL_111;
          s[2] = (unsigned int)(*(_DWORD *)(a2 + 112) - 26);
          *(_OWORD *)((char *)&s[3] + 1) = 0u;
          *(_QWORD *)((char *)&s[5] + 1) = 0;
          s[0] = 5;
          s[1] = v6 + 26;
          LOBYTE(s[3]) = 1;
          s[6] = 0;
          s[7] = 0xFFFFFFFFLL;
          v26 = ieee802_11_parse_elems_full(s);
          if ( !v26 || *(_BYTE *)(v26 + 760) )
            goto LABEL_22;
          v37 = *(_QWORD *)(a2 + 40);
          v38 = *(unsigned int *)(a2 + 56);
          v39 = v26;
          v40 = v9;
          v41 = v39;
          v42 = v39;
          v43 = 2;
        }
        ieee80211_sta_process_chanswitch(v40, v37, v38, v41, v42, v43);
        v26 = v39;
LABEL_22:
        result = kfree(v26);
        goto LABEL_111;
      }
      v44 = *(unsigned int *)(a2 + 112);
      if ( (unsigned int)v44 < 0x1A )
        goto LABEL_111;
      v56 = *(unsigned __int16 *)(v6 + 20);
      v57 = *(_DWORD *)(v6 + 16);
      if ( !(*(_DWORD *)(v6 + 10) ^ v57 | (unsigned __int16)(*(_WORD *)(v6 + 14) ^ v56)) )
      {
        if ( (*(_BYTE *)(result + 2477) & 8) == 0
          || *(_DWORD *)(result + 4802) ^ v57 | *(unsigned __int16 *)(result + 4806) ^ v56 )
        {
          v58 = *(_QWORD *)(result + 2488);
          if ( v58 && !(*(_DWORD *)(v58 + 960) ^ v57 | *(unsigned __int16 *)(v58 + 964) ^ v56) )
          {
            v59 = result;
            v60 = *(unsigned __int16 *)(v6 + 24);
            ieee80211_get_reason_code_string(*(_WORD *)(v6 + 24));
            printk(&unk_BAF67, v59 + 1640, v58 + 960, v60);
            ieee80211_destroy_assoc_data(v59, 3);
            result = cfg80211_rx_mlme_mgmt(*(_QWORD *)(v59 + 1608), v6, v44);
          }
          goto LABEL_111;
        }
        v47 = result;
        v48 = *(unsigned __int16 *)(v6 + 24);
        ieee80211_get_reason_code_string(*(_WORD *)(v6 + 24));
        v49 = &unk_BD029;
        goto LABEL_101;
      }
    }
    else
    {
      if ( v11 != 9 )
      {
        if ( v11 != 10 )
          goto LABEL_111;
        v27 = *(unsigned int *)(a2 + 112);
        s[1] = 0;
        s[2] = 0;
        s[0] = 1;
        LODWORD(v120) = 0;
        v119 = 11534336;
        if ( (unsigned int)v27 < 0x1E )
          goto LABEL_111;
        v28 = *(_QWORD *)(result + 2480);
        if ( !v28
          || (*(_BYTE *)(v28 + 39) & 1) != 0
          || *(_DWORD *)(v6 + 16) ^ *(_DWORD *)(v28 + 48)
           | *(unsigned __int16 *)(v6 + 20) ^ *(unsigned __int16 *)(v28 + 52) )
        {
          goto LABEL_111;
        }
        v29 = *(unsigned __int16 *)(v6 + 24);
        v30 = *(unsigned __int16 *)(v6 + 26);
        if ( (_DWORD)v29 == *(unsigned __int16 *)(v28 + 20) )
        {
          v31 = *(unsigned __int16 *)(v6 + 28);
          v32 = *(unsigned __int16 *)(v28 + 22);
          if ( (_DWORD)v29 == 3 )
          {
            if ( v30 <= 2 && v30 >= v32 )
            {
              if ( *(_WORD *)(v6 + 28) )
              {
                v33 = (_QWORD *)result;
                cfg80211_rx_mlme_mgmt(*(_QWORD *)(result + 1608), v6, v27);
                if ( v31 == 76 || v30 == 1 && (v31 & 0xFFFE) == 0x7E )
                {
                  *(_BYTE *)(v33[310] + 40LL) = 1;
                  *(_QWORD *)(v33[310] + 8LL) = jiffies + 500LL;
                  *(_BYTE *)(v33[310] + 42LL) = 1;
                  v34 = *(_QWORD *)(v33[310] + 8LL);
                  if ( v33[284] )
                  {
                    result = (__int64)v33;
                    if ( v34 - v33[285] >= 0 )
                      goto LABEL_110;
                  }
                  mod_timer(v33 + 283, v34);
                  goto LABEL_41;
                }
LABEL_144:
                printk(&unk_BA0DB, v33 + 205, v6 + 10, v31);
                ieee80211_destroy_auth_data(v33, 0);
                v94 = v33[202];
                HIDWORD(s[1]) = 1;
                LOWORD(s[2]) = v31;
                drv_event_callback(v94, v33, s);
LABEL_41:
                result = (__int64)v33;
LABEL_110:
                result = drv_mgd_complete_tx(*(_QWORD *)(result + 1616), result, &v119);
                goto LABEL_111;
              }
              goto LABEL_92;
            }
          }
          else if ( v30 == v32 )
          {
            if ( *(_WORD *)(v6 + 28) )
            {
              v33 = (_QWORD *)result;
              cfg80211_rx_mlme_mgmt(*(_QWORD *)(result + 1608), v6, v27);
              goto LABEL_144;
            }
            if ( (unsigned int)v29 > 6 )
              goto LABEL_106;
            if ( ((1 << v29) & 0x75) != 0 )
              goto LABEL_92;
            if ( (_DWORD)v29 == 1 )
            {
              if ( v30 != 4 )
              {
                result = ieee80211_auth_challenge();
                goto LABEL_111;
              }
            }
            else
            {
LABEL_106:
              if ( (_DWORD)v29 != 128 )
              {
                if ( (ieee80211_rx_mgmt_auth___already_done & 1) == 0 )
                {
                  v72 = result;
                  ieee80211_rx_mgmt_auth___already_done = 1;
                  _warn_printk("invalid auth alg %d", v29);
                  result = v72;
                  __break(0x800u);
                }
                goto LABEL_110;
              }
            }
LABEL_92:
            v64 = *(_QWORD *)(result + 1616);
            v65 = result;
            HIDWORD(s[1]) = 0;
            BYTE4(v119) = 1;
            drv_event_callback(v64, result, s);
            v68 = *(_QWORD *)(v65 + 2480);
            if ( *(_WORD *)(v68 + 20) != 3 )
              goto LABEL_95;
            v69 = v65;
            if ( v30 == 2 )
            {
              if ( *(_WORD *)(v68 + 22) == 2 )
              {
LABEL_95:
                result = ieee80211_mark_sta_auth(v65);
                v69 = v65;
                if ( (result & 1) == 0 )
                  goto LABEL_111;
                goto LABEL_96;
              }
              printk(&unk_BB596, v65 + 1640, v66, v67);
              v69 = v65;
              *(_BYTE *)(*(_QWORD *)(v65 + 2480) + 41LL) = 1;
            }
LABEL_96:
            cfg80211_rx_mlme_mgmt(*(_QWORD *)(v69 + 1608), v6, v27);
            result = v65;
            goto LABEL_110;
          }
        }
        v73 = v6 + 10;
        v74 = result;
        printk(&unk_B92D6, result + 1640, v73, v29);
        result = v74;
        goto LABEL_110;
      }
      v44 = *(unsigned int *)(a2 + 112);
      if ( (unsigned int)v44 < 0x1A )
        goto LABEL_111;
      if ( (*(_BYTE *)(result + 2477) & 8) == 0 )
        goto LABEL_111;
      v45 = *(unsigned __int16 *)(v6 + 20);
      v46 = *(_DWORD *)(v6 + 16);
      if ( *(_DWORD *)(result + 4802) ^ v46 | (unsigned __int16)(*(_WORD *)(result + 4806) ^ v45) )
        goto LABEL_111;
      if ( !(*(_DWORD *)(v6 + 10) ^ v46 | *(unsigned __int16 *)(v6 + 14) ^ v45) )
      {
        v47 = result;
        v48 = *(unsigned __int16 *)(v6 + 24);
        ieee80211_get_reason_code_string(*(_WORD *)(v6 + 24));
        v49 = &unk_BB9B1;
LABEL_101:
        printk(v49, v47 + 1640, v47 + 4802, v48);
        ieee80211_set_disassoc(v47, 0, 0, 0, 0);
        result = ieee80211_report_disconnect(v47, v6, v44, 0, v48, 0);
        goto LABEL_111;
      }
    }
    result = ieee80211_tdls_handle_disconnect();
    goto LABEL_111;
  }
  if ( ((v8 & 0xF0u) - 16) >> 4 > 3 )
  {
    if ( v11 == 4 )
    {
      v50 = *(_QWORD *)v9;
      v51 = *(unsigned int *)(a2 + 112);
      result = ieee80211_get_channel_khz(
                 *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v9 + 1616LL) + 72LL),
                 1000 * (*(_WORD *)(a2 + 68) & 0x1FFFu));
      if ( result )
      {
        v53 = *(_WORD *)(v6 + 8);
        v54 = *(_DWORD *)(v6 + 4);
        if ( (!(*(_DWORD *)(v50 + 5842) ^ v54 | (unsigned __int16)(*(_WORD *)(v50 + 5846) ^ v53))
           || *(_DWORD *)result == 3 && (*(_DWORD *)&v53 & HIWORD(v54) & v54) == 0xFFFF)
          && (unsigned int)v51 >= 0x24 )
        {
          v55 = *(_QWORD *)(*(_QWORD *)v9 + 1616LL);
          result = ieee80211_get_channel_khz(
                     *(_QWORD *)(v55 + 72),
                     ((*(unsigned __int16 *)(a2 + 68) << 18 >> 31) & 0x1F4) + 1000 * (*(_WORD *)(a2 + 68) & 0x1FFFu));
          if ( result )
          {
            result = ieee80211_bss_info_update(v55, a2 + 40, v6, v51, result);
            if ( result )
            {
              *(_QWORD *)(*(_QWORD *)(v9 + 944) + 80LL) = *(_QWORD *)(result + 56);
              result = ieee80211_rx_bss_put(v55, result);
            }
          }
          if ( (*(_BYTE *)(v50 + 2477) & 8) != 0
            && !(*(_DWORD *)(v9 + 536) ^ *(_DWORD *)(v6 + 16)
               | *(unsigned __int16 *)(v9 + 540) ^ *(unsigned __int16 *)(v6 + 20)) )
          {
            result = ieee80211_reset_ap_probe(v50);
          }
        }
      }
    }
    else if ( v11 == 7 )
    {
      result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64))ieee80211_rx_mgmt_beacon)(
                 v9,
                 *(_QWORD *)(a2 + 224),
                 *(unsigned int *)(a2 + 112),
                 a2 + 40);
    }
    goto LABEL_111;
  }
  if ( v11 && v11 != 2 )
    goto LABEL_111;
  v12 = *(unsigned int *)(a2 + 112);
  v13 = result;
  v14 = *(_QWORD *)(result + 2488);
  v125 = 0;
  v128 = v12;
  v123 = 0;
  v124 = 0;
  v121 = 0;
  v122 = 0;
  v119 = 0;
  v120 = 0;
  v126 = -1;
  v127 = 1;
  v117 = 1;
  v118 = 0;
  v116 = 1;
  v115 = 0;
  v114 = 0;
  result = (__int64)memset(s, 0, 0x198u);
  LODWORD(s[4]) = -1;
  if ( !v14 )
    goto LABEL_111;
  v15 = *(unsigned int *)(v14 + 1044);
  v130 = 0;
  v129 = 0;
  if ( (unsigned int)v15 < 0xF )
  {
    v16 = *(_DWORD *)(v14 + 960);
    v17 = *(_DWORD *)(v6 + 16) ^ v16;
    LODWORD(v119) = *(_DWORD *)(v14 + (v15 << 6) + 48);
    v18 = *(unsigned __int16 *)(v14 + 964);
    if ( v17 | (unsigned __int16)(*(_WORD *)(v6 + 20) ^ v18)
      || (unsigned int)v12 < 0x1E
      || *(_DWORD *)(v6 + 10) ^ v16 | *(unsigned __int16 *)(v6 + 14) ^ v18 )
    {
      goto LABEL_111;
    }
    v19 = v8 & 0xFC;
    v20 = *(unsigned __int16 *)(v6 + 26);
    v21 = *(_QWORD *)(v14 + 1144);
    if ( *(_BYTE *)(v14 + 1041) )
      v22 = v6 + 28;
    else
      v22 = v6 + 30;
    WORD1(v114) = 32 * ((v8 & 0xFC) == 48);
    if ( !v21 )
    {
LABEL_20:
      v23 = v12 + v6 - v22;
      v120 = v22;
      v121 = v23;
      v24 = ieee802_11_parse_elems_full(&v119);
      v25 = v24;
      if ( !v24 )
      {
LABEL_21:
        drv_mgd_complete_tx(*(_QWORD *)(v13 + 1616), v13, &v114);
        v26 = v25;
        goto LABEL_22;
      }
      v70 = *(__int16 **)(v24 + 424);
      if ( v70 )
      {
        v71 = *v70;
      }
      else if ( (*(_BYTE *)(v14 + 1041) & 1) != 0 )
      {
        v71 = 0;
      }
      else
      {
        v71 = *(_WORD *)(v6 + 28);
      }
      v75 = v71 & 0x7FF;
      if ( v19 == 48 )
        v76 = (const char *)&unk_B8A10;
      else
        v76 = "A";
      printk(&unk_BBCC6, v13 + 1640, v76, v14 + 960);
      v78 = (_WORD *)v13;
      *(_BYTE *)(v13 + 2497) = 0;
      if ( v20 )
      {
        if ( v20 == 30 )
        {
          v95 = *(_QWORD *)(v25 + 328);
          if ( v95 )
          {
            if ( *(_BYTE *)v95 == 3 )
            {
              cfg80211_assoc_comeback(*(_QWORD *)(v13 + 1608), v14 + 960, *(unsigned int *)(v95 + 1));
              v96 = *(unsigned int *)(*(_QWORD *)(v25 + 328) + 1LL);
              v97 = (_DWORD)v96 << 10;
              v98 = ((_DWORD)v96 << 10) / 0x3E8u;
              printk(&unk_B8E7B, v13 + 1640, v14 + 960, v96);
              v99 = jiffies;
              v100 = _msecs_to_jiffies(v98) + v99;
              *(_QWORD *)(v14 + 984) = v100;
              *(_WORD *)(v14 + 1039) = 257;
              if ( v97 >= 0xC738 && (!*(_QWORD *)(v13 + 2272) || v100 - *(_QWORD *)(v13 + 2280) < 0) )
                mod_timer(v13 + 2264, v100);
              goto LABEL_21;
            }
          }
        }
        printk(&unk_B8EC8, v13 + 1640, v14 + 960, v20);
        v101 = *(_QWORD *)(v13 + 1616);
        HIDWORD(v117) = 1;
        LOWORD(v118) = v20;
        drv_event_callback(v101, v13, &v116);
        goto LABEL_156;
      }
      if ( v75 - 2008 <= 0xFFFFF828 )
      {
        printk(&unk_BB5B0, v13 + 1640, v75, v77);
        v78 = (_WORD *)v13;
        LOWORD(v75) = 0;
        *(_BYTE *)(v13 + 2497) = 1;
        if ( *(_WORD *)(v13 + 5800) )
          goto LABEL_119;
      }
      else if ( *(_WORD *)(v13 + 5800) )
      {
LABEL_119:
        v79 = *(_QWORD *)(v25 + 448);
        if ( !v79 )
        {
          printk(&unk_BB5E8, v78 + 820, v14 + 960, v77);
          goto LABEL_174;
        }
        v80 = *(_DWORD *)(v14 + 960) == *(_DWORD *)(v79 + 3)
           && *(unsigned __int16 *)(v14 + 964) == *(unsigned __int16 *)(v79 + 7);
        if ( !v80 )
        {
          printk(&unk_B7FE5, v78 + 820, v79 + 3, v14 + 960);
LABEL_174:
          ieee80211_destroy_assoc_data(v13, 3);
          goto LABEL_21;
        }
        v81 = *(unsigned __int16 **)(v25 + 448);
        v82 = *v81;
        if ( (v82 & 0x80) != 0 )
        {
          v84 = 9;
          if ( (v82 & 0x10) != 0 )
            v84 = 10;
          v83 = *(unsigned __int16 *)((char *)v81 + v84 + ((v82 >> 5) & 1) + ((v82 >> 5) & 2));
        }
        else
        {
          v83 = 0;
        }
        v78[2367] = v83;
        v85 = *(unsigned __int16 **)(v25 + 448);
        v86 = *v85;
        if ( (v86 & 0x40) != 0 )
        {
          v80 = (v86 & 0x10) == 0;
          v88 = 9;
          v89 = (v86 >> 5) & 1;
          if ( !v80 )
            v88 = 10;
          v87 = *(unsigned __int16 *)((char *)v85 + v88 + v89);
        }
        else
        {
          v87 = 4268;
        }
        v78[2368] = v87;
        v90 = *(unsigned __int16 **)(v25 + 448);
        v91 = *v90;
        if ( (v91 & 0x100) != 0 )
        {
          v93 = 9;
          if ( (v91 & 0x10) != 0 )
            v93 = 10;
          v92 = *(unsigned __int16 *)((char *)v90 + v93 + ((v91 >> 5) & 1) + ((v91 >> 5) & 2) + ((v91 >> 6) & 2));
        }
        else
        {
          v92 = 0;
        }
        v78[2369] = v92;
      }
      v78[2366] = v75;
      if ( (ieee80211_assoc_success(v78, v6, v25, v22, v23) & 1) == 0 )
      {
        ieee80211_destroy_assoc_data(v13, 2);
        goto LABEL_21;
      }
      v102 = *(_QWORD *)(v13 + 1616);
      HIDWORD(v117) = 0;
      drv_event_callback(v102, v13, &v116);
      printk(&unk_B9331, v13 + 1640, v103, v104);
      BYTE4(v114) = 1;
LABEL_156:
      v105 = 0;
      v106 = 4568;
      do
      {
        if ( *(_QWORD *)v14 )
        {
          v107 = &s[v105];
          v107[7] = *(_QWORD *)v14;
          *((_DWORD *)v107 + 12) = *(_DWORD *)(v14 + 8);
          *((_WORD *)v107 + 26) = *(_WORD *)(v14 + 12);
          v108 = *(_BYTE **)(v13 + v106);
          *((_WORD *)v107 + 32) = *(_WORD *)(v14 + 56);
          if ( v108 )
          {
            if ( v108[896] )
              v109 = (unsigned __int8)ieee80211_ac_to_qos_mask;
            else
              v109 = 0;
            LODWORD(s[4]) = v109;
            if ( v108[910] == 1 )
            {
              v109 |= 2u;
              LODWORD(s[4]) = v109;
            }
            if ( v108[924] == 1 )
            {
              v109 |= 8u;
              LODWORD(s[4]) = v109;
            }
            if ( v108[938] == 1 )
              LODWORD(s[4]) = v109 | 4;
          }
        }
        v105 += 3;
        v106 += 8;
        v14 += 64;
      }
      while ( v105 != 45 );
      if ( *(_WORD *)(v13 + 5800) )
      {
        v110 = *(_DWORD *)(v13 + 4802);
        v130 = *(_WORD *)(v13 + 4806);
        v129 = v110;
        s[5] = &v129;
      }
      ieee80211_destroy_assoc_data(v13, v20 != 0);
      v111 = *(_QWORD *)(v13 + 2944);
      v112 = *(_QWORD *)(v13 + 2952);
      v113 = *(_QWORD *)(v13 + 1608);
      s[0] = v6;
      s[1] = v128;
      s[2] = v111;
      s[3] = v112;
      cfg80211_rx_assoc_resp(v113, s);
      goto LABEL_21;
    }
    result = fils_decrypt_assoc_resp(v13, v6, &v128, v14);
    if ( (result & 0x80000000) == 0 )
    {
      LODWORD(v12) = v128;
      goto LABEL_20;
    }
LABEL_111:
    _ReadStatusReg(SP_EL0);
    return result;
  }
LABEL_175:
  __break(0x5512u);
  return ieee80211_sta_process_chanswitch(result, a2, a3, a4, a5, a6);
}
