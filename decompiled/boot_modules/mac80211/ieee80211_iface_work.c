void __fastcall ieee80211_iface_work(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x22
  unsigned __int16 *v7; // x24
  int v8; // w8
  unsigned int v9; // w9
  int v10; // w8
  unsigned int v11; // w25
  unsigned int v12; // w26
  __int64 v13; // x0
  _QWORD *v14; // x0
  __int64 v15; // x8
  int v16; // w8
  int v17; // w25
  _QWORD *bss; // x0
  int v19; // w8
  __int64 v20; // x0
  __int64 v21; // x21
  __int64 v22; // x8
  int v23; // w8

  v2 = *(_QWORD *)(a2 - 344);
  if ( (*(_QWORD *)(a2 - 328) & 1) == 0
    || (*(_QWORD *)(v2 + 4696) & 1) != 0
    || (*(_BYTE *)(v2 + 1470) & 1) != 0
    || (*(_BYTE *)(v2 + 1468) & 1) != 0
    || (*(_BYTE *)(v2 + 1465) & 1) != 0 )
  {
    return;
  }
  v4 = a2 - 1960;
  v5 = skb_dequeue(a2 + 24);
  if ( v5 )
  {
    v6 = v5;
    while ( 1 )
    {
      if ( *(_WORD *)(v6 + 180) == 3465 )
      {
        ieee80211_process_tdls_channel_switch(v4, v6);
        goto LABEL_10;
      }
      v7 = *(unsigned __int16 **)(v6 + 224);
      v8 = *v7;
      if ( (v8 & 0xFC) != 0xD0 )
        goto LABEL_26;
      v9 = *((unsigned __int8 *)v7 + 24);
      if ( v9 > 0x15 )
        break;
      if ( v9 == 3 )
      {
        v17 = *(_DWORD *)(v6 + 112);
        bss = (_QWORD *)sta_info_get_bss(v4, v7 + 5);
        if ( bss )
        {
          v19 = *((unsigned __int8 *)v7 + 25);
          if ( v19 == 2 )
          {
            ieee80211_process_delba(v4, bss, (__int64)v7);
          }
          else if ( v19 == 1 )
          {
            ieee80211_process_addba_resp(v2, (__int64)bss, (__int64)v7);
          }
          else
          {
            if ( *((_BYTE *)v7 + 25) )
              goto LABEL_57;
            ieee80211_process_addba_request(v2, (__int64)bss, (__int64)v7, v17);
          }
        }
        goto LABEL_10;
      }
      if ( v9 != 21 )
        goto LABEL_26;
      v10 = *((unsigned __int8 *)v7 + 25);
      if ( v10 != 1 )
      {
        if ( v10 == 2 )
        {
          v11 = *(unsigned __int8 *)(v6 + 76);
          v12 = *((unsigned __int8 *)v7 + 26);
          v13 = sta_info_get_bss(v4, v7 + 5);
          if ( v13 )
            ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))ieee80211_vht_handle_opmode)(
              v4,
              v13 + 1640,
              v12,
              v11);
          goto LABEL_10;
        }
LABEL_57:
        __break(0x800u);
        goto LABEL_10;
      }
      ieee80211_process_mu_groups(v4, a2 + 1656, *(_QWORD *)(v6 + 224));
LABEL_10:
      sk_skb_reason_drop(0);
      v6 = skb_dequeue(a2 + 24);
      if ( !v6 )
        goto LABEL_58;
    }
    if ( v9 == 22 )
    {
      if ( (*((_BYTE *)v7 + 25) & 0xFE) == 6 )
        ieee80211_s1g_rx_twt_action(v4, v6);
      goto LABEL_10;
    }
    if ( v9 == 37 )
    {
      if ( *(_DWORD *)(a2 + 2760) == 2 )
      {
        if ( *((_BYTE *)v7 + 25) == 1 )
        {
          ieee80211_process_neg_ttlm_res(v4, *(_QWORD *)(v6 + 224), *(unsigned int *)(v6 + 112));
        }
        else if ( !*((_BYTE *)v7 + 25) )
        {
          ieee80211_process_neg_ttlm_req(v4, *(_QWORD *)(v6 + 224), *(unsigned int *)(v6 + 112));
        }
      }
      goto LABEL_10;
    }
LABEL_26:
    if ( (~v8 & 0xC) != 0 )
    {
      if ( (v8 & 0x8C) == 0x88 )
      {
        if ( (v8 & 0x40) != 0 )
          __break(0x800u);
        if ( (v7[11] & 0xF) == 0 )
          __break(0x800u);
        v14 = (_QWORD *)sta_info_get_bss(v4, v7 + 5);
        if ( v14 )
        {
          v15 = 12;
          if ( (~*v7 & 0x300) == 0 )
            v15 = 15;
          _ieee80211_stop_rx_ba_session(v14, v7[v15] & 0xF, 0, 0x26u, 1);
        }
      }
      else
      {
        v16 = *(_DWORD *)(a2 + 2760);
        if ( v16 == 1 )
        {
          ieee80211_ibss_rx_queued_mgmt(v4, v6);
        }
        else if ( v16 != 7 )
        {
          if ( v16 == 2 )
          {
            ieee80211_sta_rx_queued_mgmt(v4, v6);
          }
          else
          {
            _warn_printk("frame for unexpected interface type");
            __break(0x800u);
          }
        }
      }
      goto LABEL_10;
    }
    if ( *(_DWORD *)(a2 + 2760) != 2 )
      goto LABEL_57;
    ieee80211_sta_rx_queued_ext(v4, v6);
    goto LABEL_10;
  }
LABEL_58:
  v20 = skb_dequeue(a2 + 48);
  if ( v20 )
  {
    v21 = v20;
    do
    {
      v22 = *(_QWORD *)(v21 + 224);
      if ( (*(_WORD *)v22 & 0xFC) == 0xD0 && *(_BYTE *)(v22 + 24) == 22 && (*(_BYTE *)(v22 + 25) & 0xFE) == 6 )
        ieee80211_s1g_status_twt_action(v4, v21);
      sk_skb_reason_drop(0);
      v21 = skb_dequeue(a2 + 48);
    }
    while ( v21 );
  }
  v23 = *(_DWORD *)(a2 + 2760);
  switch ( v23 )
  {
    case 1:
      ieee80211_ibss_work(v4);
      break;
    case 11:
      ieee80211_ocb_work(v4);
      break;
    case 2:
      ieee80211_sta_work(v4);
      break;
  }
}
