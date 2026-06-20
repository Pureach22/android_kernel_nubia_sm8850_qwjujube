__int64 __fastcall rmnet_wlan_fragment_handle(__int64 a1, __int64 a2, __int64 *a3, __int64 a4)
{
  unsigned int v4; // w20
  __int64 v5; // x24
  __int64 v11; // x23
  unsigned __int64 i; // x20
  unsigned __int64 v13; // x0
  __int64 v14; // x10
  __int64 v15; // x11
  unsigned int v16; // w8
  int v17; // w9
  __int64 v18; // x11
  __int64 v19; // x12
  unsigned __int64 *v20; // x10
  unsigned __int64 v21; // x8
  __int64 v22; // x8
  unsigned __int64 v23; // x1
  __int64 v24; // x0
  int v26; // w8
  __int64 v28; // x0
  unsigned __int64 v29; // x2
  _QWORD *v30; // x1
  __int64 v31; // x9
  __int64 v32; // x0
  int v33; // w8
  __int64 v34; // x0
  __int64 v35; // x1
  __int64 v36; // x0
  __int64 v37; // x1
  int *v38; // x0
  int v39; // w8
  int v40; // w19
  __int64 v41; // x0
  unsigned __int64 v42; // x0
  unsigned __int64 v43; // x0
  _QWORD v44[2]; // [xsp+10h] [xbp-10h] BYREF

  v4 = 1;
  v44[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
  if ( *(_DWORD *)(v5 + 28) )
    goto LABEL_2;
  rmnet_wlan_stats_update(5);
  *(_DWORD *)(v5 + 28) = 1;
  v11 = raw_spin_lock_irqsave(&rmnet_wlan_fragment_lock);
  for ( i = rmnet_wlan_fragment_hash[(unsigned int)(1640531527 * *((_DWORD *)a3 + 8)) >> 28]; i; i = *(_QWORD *)i )
  {
    if ( (*(_BYTE *)(i + 120) & 1) == 0 )
    {
      v26 = *((unsigned __int8 *)a3 + 40);
      if ( v26 == *(unsigned __int8 *)(i + 96) && *((_DWORD *)a3 + 8) == *(_DWORD *)(i + 88) )
      {
        if ( v26 == 4 )
        {
          if ( *(_DWORD *)a3 == *(_DWORD *)(i + 56) && *((_DWORD *)a3 + 4) == *(_DWORD *)(i + 72) )
            goto LABEL_11;
        }
        else if ( *a3 == *(_QWORD *)(i + 56)
               && a3[1] == *(_QWORD *)(i + 64)
               && a3[2] == *(_QWORD *)(i + 72)
               && a3[3] == *(_QWORD *)(i + 80) )
        {
          goto LABEL_11;
        }
      }
    }
  }
  v13 = _kmalloc_cache_noprof(dst_release, 2336, 128);
  i = v13;
  if ( !v13 )
  {
    raw_spin_unlock_irqrestore(&rmnet_wlan_fragment_lock, v11);
    v4 = -1;
    goto LABEL_2;
  }
  *(_DWORD *)(v13 + 16) = 0;
  *(_QWORD *)(v13 + 24) = v13 + 24;
  *(_QWORD *)(v13 + 32) = v13 + 24;
  v14 = a3[3];
  v15 = a3[4];
  v16 = 1640531527 * *((_DWORD *)a3 + 8);
  *(_QWORD *)(v13 + 72) = a3[2];
  *(_QWORD *)(v13 + 80) = v14;
  v17 = *((_DWORD *)a3 + 10);
  *(_QWORD *)(v13 + 88) = v15;
  v18 = *a3;
  v19 = a3[1];
  *(_DWORD *)(v13 + 96) = v17;
  v20 = &rmnet_wlan_fragment_hash[v16 >> 28];
  *(_QWORD *)(v13 + 56) = v18;
  *(_QWORD *)(v13 + 64) = v19;
  v21 = *v20;
  *(_QWORD *)v13 = *v20;
  *(_QWORD *)(v13 + 8) = v20;
  atomic_store(v13, v20);
  if ( v21 )
    *(_QWORD *)(v21 + 8) = v13;
  v22 = rmnet_wlan_fragment_hash_size;
  if ( !rmnet_wlan_fragment_hash_size )
  {
    queue_delayed_work_on(32, system_wq, &rmnet_wlan_fragment_work, 13);
    v22 = rmnet_wlan_fragment_hash_size;
  }
  rmnet_wlan_fragment_hash_size = v22 + 1;
LABEL_11:
  raw_spin_unlock_irqrestore(&rmnet_wlan_fragment_lock, v11);
  v23 = *(_QWORD *)(i + 104);
  *(_QWORD *)(i + 112) = jiffies;
  if ( !v23 )
  {
    if ( *((_WORD *)a3 + 19) )
    {
      v28 = raw_spin_lock_irqsave(i + 16);
      v29 = i + 24;
      v30 = *(_QWORD **)(i + 32);
      v31 = v28;
      if ( i + 24 == a1 || v30 == (_QWORD *)a1 || *v30 != v29 )
      {
        _list_add_valid_or_report(a1, v30);
      }
      else
      {
        *(_QWORD *)(i + 32) = a1;
        *(_QWORD *)a1 = v29;
        *(_QWORD *)(a1 + 8) = v30;
        *v30 = a1;
      }
      raw_spin_unlock_irqrestore(i + 16, v31);
      v32 = 8;
      goto LABEL_49;
    }
    v33 = *(unsigned __int8 *)(a2 + 5);
    if ( v33 != 6 )
    {
      if ( v33 == 50 )
      {
        v37 = *((unsigned __int16 *)a3 + 18);
        v44[0] = 0;
        v38 = (int *)skb_header_pointer(a1, v37, 8, v44);
        if ( v38 )
        {
          v39 = *v38;
          v34 = a2;
          *(_DWORD *)a2 = v39;
          goto LABEL_54;
        }
LABEL_52:
        v24 = 20;
        goto LABEL_15;
      }
      v34 = a2;
      if ( v33 != 17 )
        goto LABEL_54;
    }
    v35 = *((unsigned __int16 *)a3 + 18);
    v44[0] = 0;
    v36 = skb_header_pointer(a1, v35, 8, v44);
    if ( v36 )
    {
      *(_WORD *)a2 = *(_WORD *)(v36 + 2);
      if ( (rmnet_wlan_udp_encap_check(a1, a2, *((unsigned __int16 *)a3 + 18)) & 1) != 0 )
      {
        if ( (rmnet_wlan_udp_encap_drop_check(a2) & 1) != 0 )
        {
          sk_skb_reason_drop(0, a1, 2);
          v32 = 18;
          goto LABEL_49;
        }
        rmnet_wlan_stats_update(10);
LABEL_61:
        v43 = i;
        *(_QWORD *)(i + 104) = -22;
        v4 = 1;
        rmnet_wlan_flush_fragment_node(v43, 1);
        goto LABEL_2;
      }
      v34 = a2;
LABEL_54:
      if ( (rmnet_wlan_tuple_present(v34) & 1) != 0 )
      {
        *(_QWORD *)(i + 104) = a4;
        v40 = rmnet_wlan_deliver_skb(a1, a4);
        if ( v40 )
          v41 = 7;
        else
          v41 = 6;
        rmnet_wlan_stats_update(v41);
        v42 = i;
        v4 = 1;
        rmnet_wlan_flush_fragment_node(v42, 1);
        if ( !v40 )
        {
          v4 = 0;
          goto LABEL_3;
        }
        goto LABEL_2;
      }
      goto LABEL_61;
    }
    goto LABEL_52;
  }
  if ( v23 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( (unsigned int)rmnet_wlan_deliver_skb(a1, v23) )
    {
      v24 = 7;
LABEL_15:
      rmnet_wlan_stats_update(v24);
      goto LABEL_16;
    }
    v32 = 6;
LABEL_49:
    rmnet_wlan_stats_update(v32);
    v4 = 0;
    goto LABEL_3;
  }
LABEL_16:
  v4 = 1;
LABEL_2:
  *(_DWORD *)(v5 + 28) = 0;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return v4;
}
