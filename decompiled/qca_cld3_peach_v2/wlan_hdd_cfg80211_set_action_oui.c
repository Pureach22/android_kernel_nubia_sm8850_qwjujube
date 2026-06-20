__int64 __fastcall wlan_hdd_cfg80211_set_action_oui(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x25
  __int64 v19; // x0
  unsigned int conparam; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w0
  _QWORD *v30; // x20
  unsigned int v31; // w19
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  const char *v40; // x2
  unsigned int v41; // w4
  unsigned int v42; // w5
  unsigned int v43; // w1
  int v44; // w26
  unsigned int v45; // w21
  _WORD *v46; // x27
  unsigned int v47; // w8
  __int64 v48; // x8
  __int64 v49; // x20
  __int64 v50; // x20
  __int64 v56; // [xsp+0h] [xbp-B0h] BYREF
  _QWORD v57[8]; // [xsp+8h] [xbp-A8h] BYREF
  int v58; // [xsp+48h] [xbp-68h]
  __int64 v59; // [xsp+50h] [xbp-60h] BYREF
  _WORD *v60; // [xsp+58h] [xbp-58h]
  _WORD *v61; // [xsp+60h] [xbp-50h]
  _WORD *v62; // [xsp+68h] [xbp-48h]
  __int64 v63; // [xsp+70h] [xbp-40h]
  __int64 v64; // [xsp+78h] [xbp-38h]
  __int64 v65; // [xsp+80h] [xbp-30h]
  __int64 v66; // [xsp+88h] [xbp-28h] BYREF
  __int64 v67; // [xsp+90h] [xbp-20h]
  _WORD *v68; // [xsp+98h] [xbp-18h]
  __int64 v69; // [xsp+A0h] [xbp-10h]
  __int64 v70; // [xsp+A8h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v56 = 0;
  result = _osif_vdev_sync_op_start(v8, &v56, "wlan_hdd_cfg80211_set_action_oui");
  if ( (_DWORD)result )
    goto LABEL_9;
  if ( a1 )
  {
    v18 = *(_QWORD *)(a2 + 32);
    v68 = nullptr;
    v69 = 0;
    v66 = 0;
    v67 = 0;
    v64 = 0;
    v65 = 0;
    v62 = nullptr;
    v63 = 0;
    v60 = nullptr;
    v61 = nullptr;
    v59 = 0;
    v58 = 0;
    memset(v57, 0, sizeof(v57));
    v19 = qdf_trace_msg(
            0x33u,
            8u,
            "%s: enter(%s)",
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            "_wlan_hdd_cfg80211_set_action_oui",
            v18 + 296);
    conparam = hdd_get_conparam(v19);
    if ( (conparam & 0xFFFFFFFE) == 4 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM/Monitor mode %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "_wlan_hdd_cfg80211_set_action_oui",
        conparam);
      v29 = -1;
      goto LABEL_8;
    }
    if ( (unsigned int)_hdd_validate_adapter(v18 + 2688, "_wlan_hdd_cfg80211_set_action_oui") )
    {
LABEL_6:
      v29 = -22;
      goto LABEL_8;
    }
    v30 = (_QWORD *)(a1 + 1536);
    v29 = _wlan_hdd_validate_context(a1 + 1536, "_wlan_hdd_cfg80211_set_action_oui");
    if ( v29 )
      goto LABEL_8;
    if ( (unsigned int)_nla_parse(&v66, 3, a3, a4, &wlan_hdd_cfg80211_set_action_oui_policy, 31, 0) )
    {
      v40 = "%s: invalid attribute";
    }
    else
    {
      if ( v67 && v69 )
      {
        v41 = *(_DWORD *)(v67 + 4);
        v42 = *(unsigned __int8 *)(v69 + 4);
        if ( v41 > 1 || v42 >= 2 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid oui id %d or oui op %d",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "_wlan_hdd_cfg80211_set_action_oui");
          goto LABEL_6;
        }
        if ( v41 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: only ID type enable is supported",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "_wlan_hdd_cfg80211_set_action_oui");
          v29 = -95;
          goto LABEL_8;
        }
        if ( v42 != 1 )
        {
          if ( v68 )
          {
            v44 = (unsigned __int16)(*v68 - 4);
            if ( (unsigned int)v44 >= 4 )
            {
              v45 = 0;
              v46 = v68 + 2;
              do
              {
                v47 = (unsigned __int16)*v46;
                if ( v47 < 4 || v44 < v47 )
                  break;
                qdf_mem_set(v57, 0x44u, 0);
                if ( (unsigned int)_nla_parse(
                                     &v59,
                                     6,
                                     v46 + 2,
                                     (unsigned __int16)(*v46 - 4),
                                     &wlan_hdd_action_oui_ext_policy,
                                     31,
                                     0) )
                {
                  v50 = jiffies;
                  if ( wlan_hdd_cfg80211_set_action_oui___last_ticks - jiffies + 125 < 0 )
                  {
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: nla_parse failed",
                      v32,
                      v33,
                      v34,
                      v35,
                      v36,
                      v37,
                      v38,
                      v39,
                      "_wlan_hdd_cfg80211_set_action_oui");
                    wlan_hdd_cfg80211_set_action_oui___last_ticks = v50;
                  }
                  goto LABEL_6;
                }
                if ( v45 == 100 )
                {
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: MAX OUI can be handled : %d",
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    v39,
                    "_wlan_hdd_cfg80211_set_action_oui",
                    100);
                  break;
                }
                if ( v60
                  && (unsigned int)((__int64 (__fastcall *)(__int64, _WORD *, _QWORD, _QWORD *))wlan_action_oui_add_token)(
                                     1,
                                     v60 + 2,
                                     (unsigned __int16)(*v60 - 4),
                                     v57) )
                {
                  goto LABEL_6;
                }
                if ( v61 )
                {
                  if ( (unsigned int)((__int64 (__fastcall *)(__int64, _WORD *, _QWORD, _QWORD *))wlan_action_oui_add_token)(
                                       4,
                                       v61 + 2,
                                       (unsigned __int16)(*v61 - 4),
                                       v57) )
                    goto LABEL_6;
                  if ( !v62 )
                  {
                    v40 = "%s: data mask missing";
                    goto LABEL_19;
                  }
                  if ( v61
                    && (unsigned int)((__int64 (__fastcall *)(__int64, _WORD *, _QWORD, _QWORD *))wlan_action_oui_add_token)(
                                       256,
                                       v62 + 2,
                                       (unsigned __int16)(*v62 - 4),
                                       v57) )
                  {
                    goto LABEL_6;
                  }
                }
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: save data for %d action oui",
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  "_wlan_hdd_cfg80211_set_action_oui",
                  v45);
                if ( (unsigned int)ucfg_action_oui_extension_store(*v30, v57) )
                  goto LABEL_6;
                ++v45;
                v48 = ((unsigned __int16)*v46 + 3) & 0x1FFFC;
                v44 -= v48;
                v46 = (_WORD *)((char *)v46 + v48);
              }
              while ( v44 > 3 );
            }
          }
          else
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: oui extension list not present",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              "_wlan_hdd_cfg80211_set_action_oui");
          }
          v49 = *(_QWORD *)(a1 + 1536);
          wlan_mlme_disable_ht_dynamic_smps(v49);
          wlan_mlme_disable_he_dynamic_smps(v49);
          sme_set_vdev_ies_per_band(*(_QWORD *)(a1 + 1552), *(unsigned __int8 *)(*(_QWORD *)(v18 + 55520) + 8LL), 0);
          v29 = 0;
          goto LABEL_8;
        }
        v29 = ucfg_action_oui_cleanup(*v30, 27);
        if ( !v29 )
        {
LABEL_8:
          v31 = v29;
          _osif_vdev_sync_op_stop(v56, "wlan_hdd_cfg80211_set_action_oui");
          result = v31;
LABEL_9:
          _ReadStatusReg(SP_EL0);
          return result;
        }
        v40 = "%s: action oui cleanup failure";
        v43 = 8;
        goto LABEL_20;
      }
      v40 = "%s: OUI or OUI OP not present";
    }
LABEL_19:
    v43 = 2;
LABEL_20:
    qdf_trace_msg(0x33u, v43, v40, v32, v33, v34, v35, v36, v37, v38, v39, "_wlan_hdd_cfg80211_set_action_oui");
    goto LABEL_6;
  }
  __break(0x800u);
  __asm { PRFM            #8, loc_2FFAAC }
  return hdd_cfg80211_wiphy_alloc();
}
