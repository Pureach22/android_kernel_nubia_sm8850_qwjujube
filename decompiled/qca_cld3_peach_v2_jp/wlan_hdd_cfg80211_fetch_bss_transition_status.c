__int64 __fastcall wlan_hdd_cfg80211_fetch_bss_transition_status(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  void *v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x23
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x20
  unsigned int v39; // w19
  unsigned __int8 v40; // w22
  int v41; // w25
  __int64 v42; // x21
  unsigned __int16 *v43; // x26
  _QWORD *v44; // x23
  unsigned int v45; // w9
  __int64 v46; // x8
  __int64 v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x20
  __int64 v57; // x22
  __int64 v58; // x19
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  _WORD *v67; // x22
  __int64 v68; // x23
  int v69; // w20
  _QWORD *v70; // x21
  __int64 v71; // x24
  _QWORD *v72; // x21
  __int64 *v73; // [xsp+0h] [xbp-210h] BYREF
  _QWORD v74[15]; // [xsp+8h] [xbp-208h] BYREF
  __int64 v75; // [xsp+80h] [xbp-190h] BYREF
  __int64 v76; // [xsp+88h] [xbp-188h]
  __int64 v77; // [xsp+90h] [xbp-180h]
  _QWORD s[47]; // [xsp+98h] [xbp-178h] BYREF

  s[46] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v73 = nullptr;
  result = _osif_vdev_sync_op_start(v8, &v73, (__int64)"wlan_hdd_cfg80211_fetch_bss_transition_status");
  if ( (_DWORD)result )
    goto LABEL_14;
  v10 = memset(s, 0, 0x170u);
  v76 = 0;
  v77 = 0;
  v75 = 0;
  memset(v74, 0, sizeof(v74));
  if ( a1 )
  {
    v19 = *(_QWORD *)(a2 + 32);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "__wlan_hdd_cfg80211_fetch_bss_transition_status");
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      v28 = "%s: Command not allowed in FTM mode";
    }
    else
    {
      v29 = _wlan_hdd_validate_context(
              a1 + 1536,
              (__int64)"__wlan_hdd_cfg80211_fetch_bss_transition_status",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27);
      if ( v29 )
      {
LABEL_13:
        v39 = v29;
        _osif_vdev_sync_op_stop((__int64)v73, (__int64)"wlan_hdd_cfg80211_fetch_bss_transition_status");
        result = v39;
LABEL_14:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      v38 = *(_QWORD *)(v19 + 55512);
      if ( *(_DWORD *)(v19 + 2728) || !hdd_cm_is_vdev_associated(*(_DWORD **)(v19 + 55512)) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Command is either not invoked for STA mode (device mode: %d) or STA is not associated (Connection state: %d)",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "__wlan_hdd_cfg80211_fetch_bss_transition_status");
        goto LABEL_12;
      }
      if ( (unsigned int)_nla_parse(s, 45, a3, a4, &btm_params_policy, 31, 0) )
      {
LABEL_10:
        v28 = "%s: Attribute parse failed";
      }
      else
      {
        if ( s[36] && s[37] )
        {
          v40 = *(_BYTE *)(s[36] + 4LL);
          v41 = (unsigned __int16)(*(_WORD *)s[37] - 4);
          if ( (unsigned int)v41 < 4 )
          {
            LOWORD(v42) = 0;
          }
          else
          {
            v42 = 0;
            v43 = (unsigned __int16 *)(s[37] + 4LL);
            v44 = v74;
            do
            {
              v45 = *v43;
              if ( v45 < 4 || v41 < v45 )
                break;
              if ( ((__int16)v43[1] & 0x80000000) == 0 )
              {
                do_trace_netlink_extack("NLA_F_NESTED is missing");
                goto LABEL_10;
              }
              if ( (unsigned int)_nla_parse(&v75, 2, v43 + 2, (unsigned __int16)(v45 - 4), &btm_cand_list_policy, 31, 0) )
                goto LABEL_10;
              if ( !v76 )
              {
                v28 = "%s: Missing BSSID attribute";
                goto LABEL_5;
              }
              qdf_mem_copy(v44, (const void *)(v76 + 4), 6u);
              if ( v42 == 9 )
              {
                LOWORD(v42) = 10;
                break;
              }
              v44 = (_QWORD *)((char *)v44 + 12);
              ++v42;
              v46 = (*v43 + 3) & 0x1FFFC;
              v41 -= v46;
              v43 = (unsigned __int16 *)((char *)v43 + v46);
            }
            while ( v41 > 3 );
          }
          if ( !(unsigned int)sme_get_bss_transition_status(
                                *(_QWORD *)(a1 + 1552),
                                v40,
                                (unsigned __int8 *)(v38 + 300),
                                (unsigned __int8 *)v74,
                                v42,
                                (*(_BYTE *)(a1 + 4784) & 3) != 0,
                                v20,
                                v21,
                                v22,
                                v23,
                                v24,
                                v25,
                                v26,
                                v27) )
          {
            v47 = _cfg80211_alloc_reply_skb(a1, 103, 197, 10 * (unsigned int)(unsigned __int16)v42 + 16);
            if ( !v47 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: reply buffer alloc failed",
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                "__wlan_hdd_cfg80211_fetch_bss_transition_status");
              v29 = -12;
              goto LABEL_13;
            }
            v56 = *(_QWORD *)(v47 + 216);
            v57 = *(unsigned int *)(v47 + 208);
            v58 = v47;
            if ( (nla_put(v47, 32805, 0, 0) & 0x80000000) == 0 )
            {
              v67 = (_WORD *)(v56 + v57);
              if ( v67 )
              {
                if ( (_WORD)v42 )
                {
                  v68 = (unsigned __int16)v42;
                  v69 = 0;
                  v70 = v74;
                  v71 = v68;
                  while ( 1 )
                  {
                    if ( !*((_DWORD *)v70 + 2) )
                    {
                      if ( (unsigned int)wlan_hdd_fill_btm_resp(v58) )
                        goto LABEL_12;
                      ++v69;
                    }
                    --v71;
                    v70 = (_QWORD *)((char *)v70 + 12);
                    if ( !v71 )
                    {
                      v72 = v74;
                      while ( 1 )
                      {
                        if ( *((_DWORD *)v72 + 2) )
                        {
                          if ( (unsigned int)wlan_hdd_fill_btm_resp(v58) )
                            goto LABEL_12;
                          ++v69;
                        }
                        --v68;
                        v72 = (_QWORD *)((char *)v72 + 12);
                        if ( !v68 )
                          goto LABEL_51;
                      }
                    }
                  }
                }
LABEL_51:
                *v67 = *(_WORD *)(v58 + 216) + *(_DWORD *)(v58 + 208) - (_WORD)v67;
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: exit",
                  v59,
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  "__wlan_hdd_cfg80211_fetch_bss_transition_status");
                v29 = cfg80211_vendor_cmd_reply(v58);
                goto LABEL_13;
              }
            }
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: nla_nest_start failed",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "__wlan_hdd_cfg80211_fetch_bss_transition_status");
            sk_skb_reason_drop(0, v58, 2);
          }
          goto LABEL_12;
        }
        v28 = "%s: Missing attributes";
      }
    }
LABEL_5:
    qdf_trace_msg(
      0x33u,
      2u,
      v28,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "__wlan_hdd_cfg80211_fetch_bss_transition_status");
LABEL_12:
    v29 = -22;
    goto LABEL_13;
  }
  __break(0x800u);
  return wlan_hdd_fill_btm_resp(v10);
}
