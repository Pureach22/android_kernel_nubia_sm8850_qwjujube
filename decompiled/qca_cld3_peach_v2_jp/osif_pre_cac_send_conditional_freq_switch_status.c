__int64 __fastcall osif_pre_cac_send_conditional_freq_switch_status(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD **v13; // x8
  __int64 v14; // x19
  __int64 v15; // x0
  __int64 v16; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _DWORD *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  const char *v35; // x2
  int v36; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 96);
  if ( v4 )
  {
    v13 = *(_QWORD ***)(v4 + 608);
    v14 = v4;
    if ( v13 )
    {
      if ( *v13 )
      {
        v15 = _cfg80211_alloc_event_skb(**v13, *v13, 103, 197, 0, 28, 20, 3264);
        if ( v15 )
        {
          v16 = v15;
          v36 = a3 & 1;
          if ( (unsigned int)nla_put(v15, 2, 4, &v36) )
          {
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: nla put failed",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "osif_pre_cac_send_conditional_freq_switch_status");
            sk_skb_reason_drop(0, v16, 2);
          }
          else
          {
            _cfg80211_send_event_skb(v16, 3264);
            v25 = (_DWORD *)osif_pre_cac_legacy_ops;
            if ( osif_pre_cac_legacy_ops )
            {
              v25 = *(_DWORD **)osif_pre_cac_legacy_ops;
              if ( *(_QWORD *)osif_pre_cac_legacy_ops )
              {
                if ( *(v25 - 1) != -1710151299 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64, _QWORD))v25)(v14, a3 & 1);
              }
            }
          }
          goto LABEL_12;
        }
        v35 = "%s: wlan_cfg80211_vendor_event_alloc failed";
      }
      else
      {
        v35 = "%s: wireless dev is null";
      }
    }
    else
    {
      v35 = "%s: osif_priv is null";
    }
    qdf_trace_msg(0x48u, 2u, v35, v5, v6, v7, v8, v9, v10, v11, v12, "osif_pre_cac_send_conditional_freq_switch_status");
LABEL_12:
    result = wlan_objmgr_vdev_release_ref(v14, 0x60u, v25, v26, v27, v28, v29, v30, v31, v32, v33);
    goto LABEL_13;
  }
  result = qdf_trace_msg(
             0x48u,
             2u,
             "%s: vdev is null",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "osif_pre_cac_send_conditional_freq_switch_status");
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
