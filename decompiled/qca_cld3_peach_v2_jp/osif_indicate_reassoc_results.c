__int64 __fastcall osif_indicate_reassoc_results(__int64 result, __int64 **a2, __int64 a3)
{
  __int64 *v3; // x9
  int v4; // w8
  __int64 v5; // x19
  __int64 v6; // x8
  __int64 channel_khz; // x23
  __int64 **v10; // x28
  __int64 bss; // x22
  unsigned int v12; // w8
  __int64 v13; // x9
  void *v14; // x0
  unsigned int v15; // w0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x26
  unsigned int v19; // w27
  __int64 v20; // x24
  unsigned int v21; // w25
  unsigned __int8 *v22; // x23
  __int64 *v23; // x22
  __int64 v24; // x28
  int v25; // w21
  unsigned int v26; // w0
  __int64 v27; // x0
  __int64 v28; // x22
  __int64 v29; // x8
  __int64 v30; // x8
  unsigned int v31; // w4
  __int64 v32; // x2
  int v33; // w0
  __int64 v34; // x0
  unsigned int v35; // w0
  __int64 v36; // [xsp+0h] [xbp-280h]
  __int64 v37; // [xsp+8h] [xbp-278h] BYREF
  __int64 v38; // [xsp+10h] [xbp-270h] BYREF
  __int64 v39; // [xsp+18h] [xbp-268h] BYREF
  __int64 v40; // [xsp+20h] [xbp-260h] BYREF
  _BYTE v41[4]; // [xsp+2Ch] [xbp-254h] BYREF
  _QWORD v42[74]; // [xsp+30h] [xbp-250h] BYREF

  v42[72] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v4 = *(_DWORD *)(a3 + 52);
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v5 = v3[4];
  if ( v4 )
    goto LABEL_2;
  v6 = *(_QWORD *)(result + 152);
  if ( !v6 || !*(_QWORD *)(v6 + 80) )
    goto LABEL_2;
  v36 = result;
  channel_khz = ieee80211_get_channel_khz(*v3, (unsigned int)(1000 * *(_DWORD *)(a3 + 48)));
  v10 = a2;
  bss = wlan_cfg80211_get_bss(**a2, channel_khz, a3 + 8, a3 + 15, *(unsigned __int8 *)(a3 + 14));
  if ( bss || (bss = wlan_cfg80211_get_bss(**v10, channel_khz, a3 + 8, 0, 0)) != 0 )
  {
    if ( (*(_BYTE *)(a3 + 1) & 0x10) != 0 )
    {
      osif_cm_get_assoc_req_ie_data(a3 + 104, &v40, &v39);
    }
    else
    {
      v12 = *(_DWORD *)(a3 + 104);
      if ( v12 > 0xA )
      {
        v13 = *(_QWORD *)(a3 + 112);
        if ( v13 )
        {
          v39 = v13 + 10;
          v40 = v12 - 10;
        }
      }
    }
    osif_cm_get_assoc_rsp_ie_data(a3 + 120, &v38, &v37);
    v14 = memset(&v42[4], 0, 0x220u);
    v42[15] = bss;
    v42[0] = v39;
    v42[1] = v40;
    v42[2] = v37;
    v42[3] = v38;
    v15 = qdf_mem_malloc_flags(v14);
    cfg80211_roamed(v5, v42, v15);
    v16 = *(_QWORD *)(v36 + 152);
    if ( v16 )
      v17 = *(_QWORD *)(v16 + 80);
    else
      v17 = 0;
    v18 = v39;
    v19 = v40;
    v20 = v37;
    v21 = v38;
    v41[0] = 0;
    result = ucfg_mlme_get_roaming_offload(v17, v41);
    if ( v41[0] != 1 )
      goto LABEL_27;
    v22 = *(unsigned __int8 **)(a3 + 144);
    v23 = *v10;
    v24 = **v10;
    v25 = v19 + v21 + v22[1] + v22[34] + *((_DWORD *)v22 + 28);
    v26 = qdf_mem_malloc_flags(result);
    v27 = _cfg80211_alloc_event_skb(v24, v23, 103, 197, 0, 12, (unsigned int)(v25 + 228), v26);
    if ( !v27 )
    {
      result = qdf_trace_msg(72, 2, "%s: cfg80211_vendor_event_alloc failed", "osif_send_roam_auth_event");
LABEL_27:
      v30 = *(_QWORD *)(a3 + 136);
      if ( v30 && *(_WORD *)(v30 + 2440) )
        result = osif_cm_set_hlp_data(v5, v36, a3);
      goto LABEL_2;
    }
    v28 = v27;
    v29 = *(_QWORD *)(v36 + 120);
    if ( !v29 )
    {
      qdf_trace_msg(72, 2, "%s: Invalid bss mac addr", "osif_send_roam_auth_event");
      goto LABEL_26;
    }
    if ( (unsigned int)nla_put(v27, 1, 6, v29 + 48)
      || (unsigned int)nla_put(v28, 2, v19, v18)
      || (unsigned int)nla_put(v28, 3, v21, v20) )
    {
LABEL_21:
      qdf_trace_msg(72, 2, "%s: nla put fail", "osif_send_roam_auth_event");
LABEL_26:
      result = sk_skb_reason_drop(0, v28, 2);
      goto LABEL_27;
    }
    if ( *v22 == 2 )
    {
      qdf_trace_msg(72, 8, "%s: Include Auth Params TLV's", "osif_send_roam_auth_event");
      LOBYTE(v42[0]) = 1;
      if ( (unsigned int)nla_put(v28, 4, 1, v42) )
        goto LABEL_21;
      if ( (wlan_crypto_get_param(v36, 7) & 0x13304860) == 0 && (unsigned int)nla_put(v28, 5, 8, v22 + 99) )
      {
        qdf_trace_msg(72, 2, "%s: non FT/non CCKM connection", "osif_send_roam_auth_event");
        qdf_trace_msg(72, 2, "%s: failed to send replay counter", "osif_send_roam_auth_event");
        goto LABEL_26;
      }
      v31 = v22[34];
      if ( v31 > 0x40
        || (v32 = v22[1], (unsigned int)v32 > 0x20)
        || (v33 = nla_put(v28, 6, v32, v22 + 2), v31 = v22[34], v33) )
      {
LABEL_38:
        qdf_trace_msg(72, 2, "%s: nla put fail, kek_len %d", "osif_send_roam_auth_event", v31);
        goto LABEL_26;
      }
      if ( (unsigned int)nla_put(v28, 7, v22[34], v22 + 35) )
      {
        v31 = v22[34];
        goto LABEL_38;
      }
      LOWORD(v42[0]) = osif_get_roam_reason(*((unsigned __int16 *)v22 + 54));
      if ( (unsigned int)nla_put(v28, 14, 2, v42) )
      {
        qdf_trace_msg(72, 2, "%s: roam reason send failure", "osif_send_roam_auth_event");
        goto LABEL_26;
      }
      if ( (unsigned int)osif_add_fils_params_roam_auth_event(v28, v22) )
        goto LABEL_26;
      osif_cm_save_gtk(v36, a3);
      qdf_trace_msg(
        72,
        8,
        "%s: replay_ctr 0x%llx kck %d kek %d",
        "osif_send_roam_auth_event",
        *(_QWORD *)(v22 + 99),
        v22[1],
        v22[34]);
    }
    else
    {
      qdf_trace_msg(72, 8, "%s: No Auth Params TLV's", "osif_send_roam_auth_event");
      LOBYTE(v42[0]) = 0;
      if ( (unsigned int)nla_put(v28, 4, 1, v42) )
        goto LABEL_21;
    }
    v34 = qdf_trace_msg(
            72,
            8,
            "%s: Auth Status = %d Subnet Change Status = %d",
            "osif_send_roam_auth_event",
            *v22,
            v22[107]);
    if ( !v22[107] || (LOBYTE(v42[0]) = v22[107], v34 = nla_put(v28, 8, 1, v42), !(_DWORD)v34) )
    {
      v35 = qdf_mem_malloc_flags(v34);
      result = _cfg80211_send_event_skb(v28, v35);
      goto LABEL_27;
    }
    goto LABEL_21;
  }
  qdf_trace_msg(
    72,
    3,
    "%s: BSS %02x:%02x:%02x:**:**:%02x is null, issue disconnect",
    "osif_indicate_reassoc_results",
    *(unsigned __int8 *)(a3 + 8),
    *(unsigned __int8 *)(a3 + 9),
    *(unsigned __int8 *)(a3 + 10),
    *(unsigned __int8 *)(a3 + 13));
  result = osif_cm_disconnect(v5, v36, 1u);
  if ( (_DWORD)result )
    result = qdf_trace_msg(72, 2, "%s: Disconnect failed with status %d", "osif_indicate_reassoc_results", result);
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
