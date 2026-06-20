__int64 __fastcall ieee80211_report_used_skb(__int64 unlock, __int64 a2, char a3, __int64 a4)
{
  _QWORD *v7; // x21
  unsigned int v8; // w26
  __int16 *v9; // x27
  int v10; // w25
  unsigned int v11; // w22
  int v12; // w8
  unsigned __int64 v13; // x0
  __int64 updated; // x0
  int v15; // w8
  __int64 lock; // x0
  __int64 v17; // x9
  _QWORD *v18; // x8
  __int64 v19; // x8
  _QWORD *v20; // x22
  _BYTE *v21; // x8
  int v22; // w24
  __int64 v23; // x23
  __int64 v24; // x25
  __int64 v25; // x23
  __int64 v26; // x0
  __int64 v27; // x1
  __int64 result; // x0
  __int64 v29; // x0
  _QWORD *v30; // x1
  __int64 v31; // x8
  __int64 v32; // x25
  _WORD *v33; // x27
  char v34; // w28
  unsigned int v35; // w8
  __int64 v36; // x9
  int v37; // w10
  unsigned int v38; // w9
  int v39; // w10
  unsigned int v40; // w9
  unsigned int v41; // w1
  __int64 v42; // x10
  __int64 v43; // x0
  __int64 v44; // x1
  __int64 v45; // x2
  __int64 v46; // x3
  __int64 v47; // x9
  _QWORD *v48; // x8
  int v49; // w9
  __int64 v50; // [xsp+8h] [xbp-38h] BYREF
  __int64 v51; // [xsp+10h] [xbp-30h]
  __int64 v52; // [xsp+18h] [xbp-28h]
  _WORD *v53; // [xsp+20h] [xbp-20h]
  __int64 v54; // [xsp+28h] [xbp-18h]
  char v55; // [xsp+30h] [xbp-10h]
  _BYTE v56[7]; // [xsp+31h] [xbp-Fh] BYREF
  __int64 v57; // [xsp+38h] [xbp-8h]

  v7 = (_QWORD *)unlock;
  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_DWORD *)(a2 + 40);
  v9 = *(__int16 **)(a2 + 224);
  v10 = (*(_DWORD *)(a2 + 44) >> 19) & 0xFFC;
  if ( (a3 & 1) != 0 )
    v11 = 0;
  else
    v11 = (v8 >> 9) & 1;
  v12 = *(_DWORD *)(a2 + 40);
  if ( v10 )
  {
    _rcu_read_lock(unlock, a2);
    v13 = sta_info_get_by_addrs((__int64)v7, v9 + 2, (__int64)(v9 + 5));
    updated = ieee80211_sta_update_pending_airtime((__int64)v7, v13, *(_BYTE *)(a2 + 124), v10, 1);
    unlock = _rcu_read_unlock(updated);
    v12 = *(_DWORD *)(a2 + 40);
  }
  if ( (v12 & 0x100000) != 0 )
  {
    lock = _rcu_read_lock(unlock, a2);
    v19 = *(_QWORD *)(a2 + 16);
    if ( v19 )
    {
      v20 = v7 + 577;
      while ( 1 )
      {
        v20 = (_QWORD *)*v20;
        if ( v20 == v7 + 577 )
          goto LABEL_37;
        if ( v19 == v20[201] )
        {
          if ( !v20 )
            goto LABEL_37;
          goto LABEL_19;
        }
      }
    }
    v20 = (_QWORD *)v7[672];
    if ( !v20 )
    {
LABEL_37:
      *(_QWORD *)(a2 + 16) = 0;
      goto LABEL_38;
    }
LABEL_19:
    if ( (a3 & 1) != 0 )
      goto LABEL_38;
    if ( (*v9 & 0xC) != 8
      || *(_DWORD *)(a2 + 116)
      || (v21 = (_BYTE *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 184)),
          *(_DWORD *)(a2 + 112) <= (unsigned int)((_DWORD)v21 - *(_DWORD *)(a2 + 224) + 2))
      || *((_WORD *)v21 - 1) != 3465
      || *v21 != 2
      || v21[1] != 12
      || v21[2] != 3 )
    {
      lock = ieee80211_s1g_is_twt_setup(a2);
      if ( (lock & 1) != 0 )
      {
        if ( (v8 & 0x200) != 0 )
          goto LABEL_38;
        lock = skb_clone(a2, 2080);
        if ( !lock )
          goto LABEL_38;
        skb_queue_tail(v20 + 251);
        v29 = v7[9];
        v30 = v20 + 245;
        goto LABEL_73;
      }
      lock = ieee80211_mgd_conn_tx_status((__int64)v20, *v9, (v8 & 0x200) != 0);
LABEL_38:
      _rcu_read_unlock(lock);
LABEL_39:
      if ( (a3 & 1) != 0 )
        goto LABEL_42;
LABEL_40:
      if ( !*(_QWORD *)(a2 + 96) )
        goto LABEL_42;
      goto LABEL_41;
    }
    v22 = *(_DWORD *)(a2 + 40);
    raw_spin_lock(v20 + 342);
    if ( v20[340] != a2 || (v23 = v20[341]) == 0 )
    {
      lock = raw_spin_unlock(v20 + 342);
      goto LABEL_38;
    }
    v20[340] = 0;
    v20[341] = 0;
    raw_spin_unlock(v20 + 342);
    if ( (v7[12] & 0x10000) != 0 )
    {
      if ( (v22 & 0x200) == 0 )
      {
LABEL_31:
        lock = ieee80211_subif_start_xmit(v23, *(_QWORD *)(a2 + 16));
        goto LABEL_38;
      }
    }
    else
    {
      __break(0x800u);
      if ( (v22 & 0x200) == 0 )
        goto LABEL_31;
    }
    lock = dev_kfree_skb_any_reason(v23, 2);
    goto LABEL_38;
  }
  v15 = *(_DWORD *)(a2 + 44);
  if ( (v15 & 8) == 0 )
  {
    if ( (v15 & 0x1FFF0) == 0 )
      goto LABEL_39;
    lock = _rcu_read_lock(unlock, a2);
    v17 = *(_QWORD *)(a2 + 16);
    if ( v17 )
    {
      v18 = v7 + 577;
      while ( 1 )
      {
        v18 = (_QWORD *)*v18;
        if ( v18 == v7 + 577 )
          break;
        if ( v17 == v18[201] )
          goto LABEL_59;
      }
      v18 = nullptr;
    }
    else
    {
      v18 = (_QWORD *)v7[672];
    }
LABEL_59:
    v38 = *(_DWORD *)(a2 + 44);
    v39 = (unsigned __int8)v38 >> 4;
    if ( v39 == 2 )
    {
      if ( !v18 || (v18[204] & 1) == 0 || !v11 || *((_DWORD *)v18 + 1180) != 2 )
        goto LABEL_38;
      v30 = v18 + 391;
      v29 = *(_QWORD *)(v18[202] + 72LL);
      goto LABEL_73;
    }
    if ( v39 != 1 || !v18 || (v18[204] & 1) == 0 || !v11 || *((_DWORD *)v18 + 1180) != 2 )
      goto LABEL_38;
    v40 = (unsigned __int16)(v38 >> 4);
    v41 = (v40 >> 6) & 0x7F;
    if ( ((v40 >> 4) & 0x1FF) >= 0x3C )
    {
      lock = _warn_printk("bad SMPS status link: %d\n", v41);
      __break(0x800u);
      goto LABEL_38;
    }
    v42 = v18[v41 + 571];
    if ( v42 )
    {
      v30 = (_QWORD *)(v42 + 816);
      *(_DWORD *)(v42 + 444) = (v40 >> 4) & 3;
      v29 = *(_QWORD *)(v18[202] + 72LL);
LABEL_73:
      lock = wiphy_work_queue(v29, v30);
      goto LABEL_38;
    }
    goto LABEL_38;
  }
  v24 = raw_spin_lock_irqsave(v7 + 671);
  v25 = idr_remove(v7 + 668, ((unsigned __int64)*(unsigned int *)(a2 + 44) >> 4) & 0x1FFF);
  v26 = raw_spin_unlock_irqrestore(v7 + 671, v24);
  if ( !v25 )
    goto LABEL_39;
  if ( (*(_BYTE *)(a2 + 42) & 0x20) == 0 )
  {
    if ( (a3 & 1) != 0 )
    {
      dev_kfree_skb_any_reason(v25, 2);
      goto LABEL_42;
    }
    skb_complete_wifi_ack(v25, v11);
    if ( *(_QWORD *)(a2 + 96) )
    {
LABEL_41:
      *(_DWORD *)(a2 + 129) = *(_DWORD *)(a2 + 129) & 0xFFFFE7FF | (((v8 >> 9) & 1) << 12) | 0x800;
      goto LABEL_42;
    }
    goto LABEL_42;
  }
  v31 = *(unsigned int *)(v25 + 112);
  v32 = *(_QWORD *)(v25 + 48);
  v33 = *(_WORD **)(v25 + 224);
  v34 = *(_BYTE *)(a2 + 70);
  v55 = v11;
  v54 = v31;
  v35 = *(_DWORD *)(a2 + 112);
  v50 = v32;
  v51 = 0;
  v52 = 0;
  v53 = v33;
  memset(v56, 0, sizeof(v56));
  if ( v35 >= 0x19 )
  {
    v36 = *(_QWORD *)(a2 + 224);
    if ( (*(_WORD *)v36 & 0xFC) == 0xD0 )
    {
      v37 = *(unsigned __int8 *)(v36 + 24);
      if ( v37 != 4 )
      {
        if ( v37 != 11 || v35 < 0x26 || *(_BYTE *)(v36 + 25) != 1 )
          goto LABEL_79;
LABEL_78:
        v51 = *(_QWORD *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 16LL);
        v52 = a4;
        goto LABEL_79;
      }
      if ( v35 >= 0x2C && *(_BYTE *)(v36 + 25) == 33 )
        goto LABEL_78;
    }
  }
LABEL_79:
  v43 = _rcu_read_lock(v26, v27);
  v47 = *(_QWORD *)(v25 + 16);
  if ( v47 )
  {
    v48 = v7 + 577;
    while ( 1 )
    {
      v48 = (_QWORD *)*v48;
      if ( v48 == v7 + 577 )
        break;
      if ( v47 == v48[201] )
        goto LABEL_85;
    }
  }
  else
  {
    v48 = (_QWORD *)v7[672];
LABEL_85:
    if ( v48 )
    {
      v49 = *(unsigned __int16 *)(v25 + 180);
      if ( v49 == 51080 || v49 == *((unsigned __int16 *)v48 + 970) )
      {
        v43 = cfg80211_control_port_tx_status(
                v48 + 2,
                v32,
                *(_QWORD *)(v25 + 224),
                *(unsigned int *)(v25 + 112),
                v11,
                2080);
      }
      else if ( (*v33 & 0x7C) == 0x48 )
      {
        v43 = cfg80211_probe_status(v48[201], v33 + 2, v32, v11, *(unsigned int *)(a2 + 60), v34 & 1, 2080);
      }
      else if ( (*v33 & 0xC) != 0 )
      {
        v43 = printk(&unk_B96ED, v44, v45, v46);
      }
      else
      {
        v43 = cfg80211_mgmt_tx_status_ext(v48 + 2, &v50, 2080);
      }
    }
  }
  _rcu_read_unlock(v43);
  dev_kfree_skb_any_reason(v25, 2);
  if ( (a3 & 1) == 0 )
    goto LABEL_40;
LABEL_42:
  result = *(_QWORD *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 8LL);
  if ( result )
  {
    result = kfree_skb_list_reason(result, 2);
    *(_QWORD *)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 8LL) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
