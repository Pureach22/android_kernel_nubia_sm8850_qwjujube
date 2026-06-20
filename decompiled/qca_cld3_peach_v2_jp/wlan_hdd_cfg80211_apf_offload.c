__int64 __fastcall wlan_hdd_cfg80211_apf_offload(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
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
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 *v27; // x22
  int v28; // w0
  const char *v29; // x2
  unsigned int v30; // w19
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  const char *v39; // x2
  int v40; // w20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int apf_capabilities; // w0
  __int64 v58; // x0
  __int64 v59; // x1
  int v60; // w19
  __int64 *v61; // [xsp+0h] [xbp-50h] BYREF
  __int64 v62; // [xsp+8h] [xbp-48h] BYREF
  __int64 v63; // [xsp+10h] [xbp-40h]
  __int64 v64; // [xsp+18h] [xbp-38h]
  __int64 v65; // [xsp+20h] [xbp-30h]
  __int64 v66; // [xsp+28h] [xbp-28h]
  __int64 v67; // [xsp+30h] [xbp-20h]
  __int64 v68; // [xsp+38h] [xbp-18h]
  __int64 v69; // [xsp+40h] [xbp-10h]
  __int64 v70; // [xsp+48h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v61 = nullptr;
  result = _osif_vdev_sync_op_start(v8, &v61, (__int64)"wlan_hdd_cfg80211_apf_offload");
  if ( (_DWORD)result )
    goto LABEL_10;
  if ( a1 )
  {
    v18 = *(_QWORD *)(a2 + 32);
    v68 = 0;
    v69 = 0;
    v66 = 0;
    v67 = 0;
    v64 = 0;
    v65 = 0;
    v62 = 0;
    v63 = 0;
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
      "__wlan_hdd_cfg80211_apf_offload",
      v18 + 296);
    if ( v18 == -2688 )
    {
      v29 = "%s: Adapter is null";
      goto LABEL_8;
    }
    v27 = (__int64 *)(a1 + 1536);
    v28 = _wlan_hdd_validate_context(
            (__int64)v27,
            (__int64)"__wlan_hdd_cfg80211_apf_offload",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26);
    if ( v28 )
    {
LABEL_9:
      v30 = v28;
      _osif_vdev_sync_op_stop((__int64)v61, (__int64)"wlan_hdd_cfg80211_apf_offload");
      result = v30;
LABEL_10:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      v29 = "%s: Command not allowed in FTM mode";
LABEL_8:
      qdf_trace_msg(0x33u, 2u, v29, v19, v20, v21, v22, v23, v24, v25, v26, "__wlan_hdd_cfg80211_apf_offload");
      v28 = -22;
      goto LABEL_9;
    }
    if ( (ucfg_pmo_is_apf_enabled(*v27) & 1) != 0 )
    {
      if ( (*(_DWORD *)(v18 + 2728) | 2) == 2 )
      {
        if ( (unsigned int)_nla_parse(&v62, 7, a3, a4, &wlan_hdd_apf_offload_policy, 31, 0) )
        {
          v29 = "%s: Invalid ATTR";
          goto LABEL_8;
        }
        if ( !v63 )
        {
          v29 = "%s: attr apf sub-command failed";
          goto LABEL_8;
        }
        v40 = *(_DWORD *)(v63 + 4);
        raw_spin_lock(v18 + 54976);
        if ( *(_BYTE *)(v18 + 54953) == 1 )
        {
          raw_spin_unlock(v18 + 54976);
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Another cmd in progress for same session!",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "__wlan_hdd_cfg80211_apf_offload");
          v28 = -11;
          goto LABEL_9;
        }
        *(_BYTE *)(v18 + 54953) = 1;
        raw_spin_unlock(v18 + 54976);
        if ( v40 <= 3 )
        {
          switch ( v40 )
          {
            case 1:
              apf_capabilities = hdd_set_reset_apf_offload(v27, &v62, v18 + 2688);
              goto LABEL_37;
            case 2:
              apf_capabilities = hdd_get_apf_capabilities(v27);
              goto LABEL_37;
            case 3:
              apf_capabilities = hdd_apf_write_memory(v18 + 2688, &v62);
LABEL_37:
              v60 = apf_capabilities;
              goto LABEL_38;
          }
LABEL_33:
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Unknown APF Sub-command: %d",
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            "__wlan_hdd_cfg80211_apf_offload",
            (unsigned int)v40);
          v60 = -524;
LABEL_38:
          raw_spin_lock(v18 + 54976);
          *(_BYTE *)(v18 + 54953) = 0;
          raw_spin_unlock(v18 + 54976);
          v28 = v60;
          goto LABEL_9;
        }
        switch ( v40 )
        {
          case 4:
            apf_capabilities = hdd_apf_read_memory(v18 + 2688, &v62);
            goto LABEL_37;
          case 5:
            v58 = v18 + 2688;
            v59 = 1;
            break;
          case 6:
            v58 = v18 + 2688;
            v59 = 0;
            break;
          default:
            goto LABEL_33;
        }
        apf_capabilities = hdd_enable_disable_apf(v58, v59);
        goto LABEL_37;
      }
      v39 = "%s: APF only supported in STA or P2P CLI modes!";
    }
    else
    {
      v39 = "%s: APF is not supported or disabled through INI";
    }
    qdf_trace_msg(0x33u, 2u, v39, v31, v32, v33, v34, v35, v36, v37, v38, "__wlan_hdd_cfg80211_apf_offload");
    v28 = -524;
    goto LABEL_9;
  }
  __break(0x800u);
  return ((__int64 (*)(void))hdd_set_reset_apf_offload)();
}
