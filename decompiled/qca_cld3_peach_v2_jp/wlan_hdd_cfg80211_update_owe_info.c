__int64 __fastcall wlan_hdd_cfg80211_update_owe_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int updated; // w21
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // w19
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w19
  _QWORD v51[2]; // [xsp+0h] [xbp-10h] BYREF

  v51[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v51, "wlan_hdd_cfg80211_update_owe_info");
  if ( (_DWORD)result )
  {
LABEL_18:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "__wlan_hdd_cfg80211_update_owe_info",
      a2 + 296);
    v15 = _wlan_hdd_validate_context(a1 + 1536, "__wlan_hdd_cfg80211_update_owe_info");
    if ( !(_DWORD)v15 )
    {
      if ( (unsigned int)hdd_get_conparam(v15) == 5 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Command not allowed in FTM mode",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "__wlan_hdd_cfg80211_update_owe_info");
        LODWORD(v15) = -22;
      }
      else if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                                *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL),
                                "__wlan_hdd_cfg80211_update_owe_info") )
      {
        LODWORD(v15) = -22;
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: owe_status %d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "__wlan_hdd_cfg80211_update_owe_info",
          *(unsigned __int16 *)(a3 + 6));
        if ( (*(_QWORD *)(a2 + 4328) & 1) != 0 )
        {
          while ( 1 )
          {
            updated = wlansap_update_owe_info(
                        *(_QWORD *)(a2 + 55792),
                        a3,
                        *(_QWORD *)(a3 + 8),
                        *(unsigned int *)(a3 + 16),
                        *(unsigned __int16 *)(a3 + 6));
            if ( !updated || updated == 14 )
              break;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to update OWE info vdev id %d",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "__wlan_hdd_cfg80211_update_owe_info",
              *(unsigned __int8 *)(a2 + 55528));
            if ( (unsigned __int8)~(-910593773 * ((unsigned int)(a2 + 55520 - *(_DWORD *)(a2 + 55520) - 52832) >> 4))
              || (*(_QWORD *)(a2 + 4328) & 1) == 0 )
            {
              goto LABEL_16;
            }
          }
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: update OWE info vdev id %d success",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "__wlan_hdd_cfg80211_update_owe_info",
            *(unsigned __int8 *)(a2 + 55528));
        }
        else
        {
          updated = 16;
        }
LABEL_16:
        v41 = qdf_status_to_os_return(updated);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: exit",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "__wlan_hdd_cfg80211_update_owe_info");
        LODWORD(v15) = v41;
      }
    }
    v50 = v15;
    _osif_vdev_sync_op_stop(v51[0], "wlan_hdd_cfg80211_update_owe_info");
    result = v50;
    goto LABEL_18;
  }
  __break(0x800u);
  return hdd_change_adapter_mode(result);
}
