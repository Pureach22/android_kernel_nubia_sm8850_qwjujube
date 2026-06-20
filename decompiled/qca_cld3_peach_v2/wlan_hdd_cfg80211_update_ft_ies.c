__int64 __fastcall wlan_hdd_cfg80211_update_ft_ies(__int64 a1, __int64 a2, __int64 a3)
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
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w19
  __int64 v49; // x0
  _QWORD v50[2]; // [xsp+0h] [xbp-10h] BYREF

  v50[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v50, "wlan_hdd_cfg80211_update_ft_ies");
  if ( (_DWORD)result )
  {
LABEL_12:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v7, v8, v9, v10, v11, v12, v13, v14, "__wlan_hdd_cfg80211_update_ft_ies");
    v15 = _wlan_hdd_validate_context(a1 + 1536, "__wlan_hdd_cfg80211_update_ft_ies");
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
          "__wlan_hdd_cfg80211_update_ft_ies");
        LODWORD(v15) = -22;
      }
      else if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                                *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL),
                                "__wlan_hdd_cfg80211_update_ft_ies") )
      {
        LODWORD(v15) = -22;
      }
      else
      {
        qdf_mtrace(51, 51, 0x37u, *(_BYTE *)(*(_QWORD *)(a2 + 55520) + 8LL), 0);
        if ( (hdd_cm_is_vdev_associated(*(_QWORD *)(a2 + 55520)) & 1) == 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Called with Ie of length = %zu when not associated",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "__wlan_hdd_cfg80211_update_ft_ies",
            *(_QWORD *)(a3 + 16));
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Should be Re-assoc Req IEs",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "__wlan_hdd_cfg80211_update_ft_ies");
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: called with Ie of length = %zu",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "__wlan_hdd_cfg80211_update_ft_ies",
          *(_QWORD *)(a3 + 16));
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: exit",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "__wlan_hdd_cfg80211_update_ft_ies");
        LODWORD(v15) = 0;
      }
    }
    v48 = v15;
    _osif_vdev_sync_op_stop(v50[0], "wlan_hdd_cfg80211_update_ft_ies");
    result = v48;
    goto LABEL_12;
  }
  __break(0x800u);
  v49 = MEMORY[0x758C30C]();
  return wlan_hdd_cfg80211_channel_switch(v49);
}
