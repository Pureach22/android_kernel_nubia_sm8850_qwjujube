__int64 __fastcall wlan_hdd_cfg80211_get_sar_capability(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x5
  __int64 v31; // x20
  unsigned int v32; // w21
  unsigned int v33; // w0
  int v34; // w8
  int v35; // w8
  unsigned int v36; // w0
  __int64 v37; // x4
  unsigned int v38; // w19
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v48; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v49; // [xsp+18h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 488);
  v47 = 0;
  result = _osif_psoc_sync_op_start(v2, &v47, (__int64)"wlan_hdd_cfg80211_get_sar_capability");
  if ( (_DWORD)result )
  {
LABEL_7:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v4, v5, v6, v7, v8, v9, v10, v11, "__wlan_hdd_get_sar_capability");
    if ( (unsigned int)hdd_get_conparam() == 5 || (unsigned int)hdd_get_conparam() == 4 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM/MONITOR mode",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "__wlan_hdd_get_sar_capability");
      v20 = -1;
    }
    else if ( (unsigned int)_wlan_hdd_validate_context(
                              a1 + 1536,
                              (__int64)"__wlan_hdd_get_sar_capability",
                              v12,
                              v13,
                              v14,
                              v15,
                              v16,
                              v17,
                              v18,
                              v19) )
    {
      v20 = -22;
    }
    else
    {
      v21 = _cfg80211_alloc_reply_skb(a1, 103, 197, 32);
      if ( v21 )
      {
        v30 = *(unsigned int *)(a1 + 5224);
        v31 = v21;
        if ( (unsigned int)v30 >= 6 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Unexpected SAR version received :%u, sending default to userspace",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "hdd_to_nl_sar_version",
            (unsigned int)v30);
          v30 = *(unsigned int *)(a1 + 5224);
          v32 = 1;
        }
        else
        {
          v32 = dword_A2ADD8[(unsigned int)v30];
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Sending SAR Version = %u to userspace, fw_sar_version: %d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "hdd_sar_fill_capability_response",
          v32,
          v30);
        v48 = v32;
        v33 = nla_put(v31, 1, 4, &v48);
        if ( v33 )
          goto LABEL_20;
        v34 = *(_DWORD *)(a1 + 5228);
        v35 = v34 == 1 ? 2 : v34 == 2;
        v48 = v35;
        v36 = nla_put(v31, 2, 4, &v48);
        v37 = *(unsigned int *)(a1 + 5228);
        v38 = v36;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Sending SAR Flag = %u to userspace",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "hdd_sar_fill_capability_response",
          v37);
        v33 = v38;
        if ( v38 )
        {
LABEL_20:
          v20 = v33;
          sk_skb_reason_drop(0, v31, 2);
        }
        else
        {
          v20 = cfg80211_vendor_cmd_reply(v31);
        }
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "hdd_sar_send_capability_response");
        v20 = -12;
      }
    }
    _osif_psoc_sync_op_stop(v47, (__int64)"wlan_hdd_cfg80211_get_sar_capability");
    result = v20;
    goto LABEL_7;
  }
  __break(0x800u);
  return hdd_disable_sar();
}
