__int64 __fastcall wlan_hdd_cfg80211_conditional_chan_switch(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
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
  __int64 v18; // x23
  __int64 *v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w19
  unsigned int v47; // w20
  unsigned int v48; // w21
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int *v57; // x23
  __int64 v58; // x20
  __int64 v59; // x24
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int v68; // w19
  __int64 *v69; // [xsp+0h] [xbp-30h] BYREF
  _BYTE v70[4]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v71; // [xsp+10h] [xbp-20h] BYREF
  unsigned __int16 *v72; // [xsp+18h] [xbp-18h]
  __int64 v73; // [xsp+20h] [xbp-10h]
  __int64 v74; // [xsp+28h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v69 = nullptr;
  result = _osif_vdev_sync_op_start(v8, &v69, (__int64)"wlan_hdd_cfg80211_conditional_chan_switch");
  if ( (_DWORD)result )
    goto LABEL_13;
  if ( a1 )
  {
    v18 = *(_QWORD *)(a2 + 32);
    v72 = nullptr;
    v73 = 0;
    v19 = (__int64 *)(a1 + 1536);
    v71 = 0;
    v70[0] = 0;
    qdf_trace_msg(
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
      "__wlan_hdd_cfg80211_conditional_chan_switch",
      v18 + 296);
    v28 = _wlan_hdd_validate_context(
            (__int64)v19,
            (__int64)"__wlan_hdd_cfg80211_conditional_chan_switch",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27);
    if ( !v28 )
    {
      if ( (unsigned int)ucfg_mlme_get_dfs_master_capability(*v19, v70) )
      {
        v37 = "%s: Failed to get dfs master capability";
        goto LABEL_10;
      }
      if ( (v70[0] & 1) == 0 )
      {
        v37 = "%s: DFS master capability is not present in the driver";
        goto LABEL_10;
      }
      if ( (unsigned int)hdd_get_conparam() != 5 )
      {
        if ( *(_DWORD *)(v18 + 2728) != 1 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid device mode %d",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "__wlan_hdd_cfg80211_conditional_chan_switch");
          goto LABEL_11;
        }
        if ( (unsigned int)_nla_parse(&v71, 2, a3, a4, &conditional_chan_switch_policy, 31, 0) )
        {
          v37 = "%s: Invalid ATTR";
        }
        else
        {
          if ( v72 )
          {
            v47 = *v72 - 4;
            if ( v47 < 0x19C )
            {
              v48 = (unsigned __int16)v47 >> 2;
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: freq_len=%d",
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                "__wlan_hdd_cfg80211_conditional_chan_switch",
                (unsigned __int16)v47 >> 2);
              v57 = (unsigned int *)(v72 + 2);
              if ( (unsigned __int16)v47 >= 4u )
              {
                v58 = 0;
                if ( v48 <= 1 )
                  v59 = 1;
                else
                  v59 = v48;
                do
                {
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: freq[%d]=%d",
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    v55,
                    v56,
                    "__wlan_hdd_cfg80211_conditional_chan_switch",
                    (unsigned int)v58,
                    v57[v58]);
                  ++v58;
                }
                while ( v59 != v58 );
              }
              v28 = wlan_hdd_request_pre_cac(v19, *v57);
              if ( v28 )
              {
                v68 = v28;
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: pre cac request failed with reason:%d",
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  v67,
                  "__wlan_hdd_cfg80211_conditional_chan_switch",
                  v28);
                v28 = v68;
              }
            }
            else
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: insufficient space to hold channels",
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                "__wlan_hdd_cfg80211_conditional_chan_switch");
              v28 = -12;
            }
            goto LABEL_12;
          }
          v37 = "%s: Frequency list is missing";
        }
LABEL_10:
        qdf_trace_msg(
          0x33u,
          2u,
          v37,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "__wlan_hdd_cfg80211_conditional_chan_switch");
LABEL_11:
        v28 = -22;
        goto LABEL_12;
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "__wlan_hdd_cfg80211_conditional_chan_switch");
      v28 = -1;
    }
LABEL_12:
    v46 = v28;
    _osif_vdev_sync_op_stop((__int64)v69, (__int64)"wlan_hdd_cfg80211_conditional_chan_switch");
    result = v46;
LABEL_13:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x800u);
  return hdd_store_sar_config();
}
