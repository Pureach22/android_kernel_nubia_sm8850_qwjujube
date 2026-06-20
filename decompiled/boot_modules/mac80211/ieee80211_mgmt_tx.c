__int64 __fastcall ieee80211_mgmt_tx(__int64 unlock, __int64 a2, __int64 a3, __int64 *a4)
{
  __int64 v4; // x21
  __int64 v5; // x25
  __int64 v8; // x23
  __int64 v9; // x28
  int v10; // w9
  unsigned int v11; // w8
  __int64 v12; // x22
  int v13; // w19
  int v15; // w10
  char v16; // w26
  char *v17; // x8
  __int64 v18; // x9
  char v19; // w24
  __int64 bss; // x0
  unsigned int v21; // w8
  __int64 result; // x0
  int v23; // w9
  __int64 v24; // x24
  __int64 lock; // x0
  __int64 v26; // x9
  int v27; // w13
  int v28; // w14
  __int64 v29; // x12
  __int64 *v30; // x8
  __int64 v31; // x11
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x25
  __int64 v35; // x24
  __int64 v36; // x9
  int v37; // w21
  __int64 v38; // x19
  __int64 *v39; // x22
  const void *v40; // x27
  __int64 v41; // x28
  void *v42; // x26
  void *v43; // x0
  __int64 v44; // x1
  unsigned int v45; // w8
  __int64 v46; // x0
  int v47; // w8
  __int64 v48; // x8
  int v49; // w10
  __int64 v50; // x8
  char v51; // w8
  __int64 v52; // x9
  __int64 v53; // x10
  int v54; // w8
  __int64 v55; // x21
  unsigned int v56; // w0
  unsigned int v57; // w19
  __int64 v58; // x25
  char v59; // [xsp+Ch] [xbp-14h]
  __int64 v60; // [xsp+10h] [xbp-10h]
  __int64 v61; // [xsp+18h] [xbp-8h]
  __int64 v62; // [xsp+18h] [xbp-8h]

  v4 = *(_QWORD *)(a2 + 1600);
  v5 = *(_QWORD *)(a3 + 16);
  v8 = a2;
  v9 = a2 + 4096;
  if ( *(_BYTE *)(a3 + 33) )
    v10 = 4;
  else
    v10 = 2097153;
  v11 = *(_DWORD *)(a2 + 4704);
  v12 = a2 - 16;
  if ( *(_BYTE *)(a3 + 32) )
    v13 = v10 | 0x8000000;
  else
    v13 = v10;
  if ( v11 > 0xA )
  {
LABEL_25:
    if ( v11 != 1 )
      return 4294967201LL;
    v17 = (char *)(a2 + 4713);
LABEL_27:
    v19 = *v17;
    _rcu_read_lock(unlock, a2);
    bss = sta_info_get_bss(v12, v5 + 4);
    if ( bss )
      v16 = *(_BYTE *)(bss + 2715);
    else
      v16 = 0;
    if ( (*(_WORD *)v5 & 0xFC) == 0xD0
      && ((v21 = *(unsigned __int8 *)(v5 + 24), v21 > 0xF) || ((1 << v21) & 0x8011) == 0) )
    {
      if ( !bss
        || (v23 = *(_DWORD *)(a3 + 48), (v23 & 0x80000000) == 0)
        && (((unsigned __int64)*(unsigned __int16 *)(bss + 2872) >> v23) & 1) == 0 )
      {
        _rcu_read_unlock(bss);
        return 4294967229LL;
      }
      v61 = *(unsigned int *)(a3 + 48);
      unlock = _rcu_read_unlock(bss);
      v18 = v61;
      if ( (v19 & 1) == 0 )
        goto LABEL_34;
    }
    else
    {
      unlock = _rcu_read_unlock(bss);
      v18 = 0xFFFFFFFFLL;
      if ( (v19 & 1) == 0 )
        goto LABEL_34;
    }
    goto LABEL_45;
  }
  if ( ((1 << v11) & 0x218) != 0 )
  {
    v17 = (char *)(*(_QWORD *)(a2 + 2016) + 317LL);
    goto LABEL_27;
  }
  if ( ((1 << v11) & 0x104) == 0 )
  {
    if ( v11 == 10 )
      goto LABEL_24;
    goto LABEL_25;
  }
  if ( (*(_BYTE *)(a2 + 2461) & 8) != 0 )
  {
    if ( *(_BYTE *)(a3 + 8) == 1 && *(_DWORD *)(a3 + 12) && *(_QWORD *)(*(_QWORD *)(v4 + 464) + 472LL) )
    {
      if ( *(_DWORD *)(a2 + 4786) != *(_DWORD *)(v5 + 16)
        || *(unsigned __int16 *)(a2 + 4790) != *(unsigned __int16 *)(v5 + 20) )
      {
        goto LABEL_24;
      }
      if ( (*(_BYTE *)(a2 + 2461) & 8) == 0 )
        goto LABEL_21;
    }
    v15 = *(unsigned __int16 *)(a2 + 4790);
    a2 = v5 + 4;
    if ( *(_DWORD *)(v5 + 4) ^ *(_DWORD *)(v9 + 690) | *(unsigned __int16 *)(v5 + 8) ^ v15
      || (unlock = sta_info_get_bss(v12, a2)) == 0 )
    {
LABEL_21:
      v16 = 0;
    }
    else
    {
      v16 = *(_BYTE *)(unlock + 2715);
    }
    v18 = 0xFFFFFFFFLL;
LABEL_45:
    v62 = v18;
    if ( *(_QWORD *)a3 || (v16 & 1) == 0 )
    {
      lock = _rcu_read_lock(unlock, a2);
      v26 = 0;
      while ( 1 )
      {
        v29 = *(_QWORD *)(v8 + 5664 + 8 * v26);
        if ( v29 )
        {
          v30 = *(__int64 **)(v29 + 832);
          if ( v30 )
          {
            if ( (v16 & 1) != 0 )
            {
              v24 = *(_QWORD *)a3;
              v27 = *(_DWORD *)(v5 + 10);
              v28 = *(unsigned __int16 *)(v5 + 14);
              if ( *(_QWORD *)a3 == *v30 && !(v27 ^ *(_DWORD *)(v9 + 1730) | v28 ^ *(unsigned __int16 *)(v8 + 5830)) )
              {
                v31 = (unsigned int)v26;
                goto LABEL_98;
              }
            }
            else
            {
              v27 = *(_DWORD *)(v5 + 10);
              v28 = *(unsigned __int16 *)(v5 + 14);
            }
            if ( !(v27 ^ *(_DWORD *)(v29 + 28) | v28 ^ *(unsigned __int16 *)(v29 + 32)) )
              break;
          }
        }
        if ( ++v26 == 15 )
        {
          _rcu_read_unlock(lock);
LABEL_59:
          v18 = v62;
          goto LABEL_60;
        }
      }
      if ( *(_WORD *)(v8 + 5784) )
      {
        v49 = *(_DWORD *)(a3 + 48);
        v24 = *(_QWORD *)a3;
        v31 = v62;
        if ( (v49 & 0x80000000) == 0 && v49 == (_DWORD)v26 )
        {
          if ( v24 == *v30 )
            v31 = (unsigned int)v26;
          else
            v31 = (unsigned int)v62;
        }
      }
      else
      {
        v24 = *(_QWORD *)a3;
        v31 = v62;
      }
LABEL_98:
      v62 = v31;
      if ( !v24 )
      {
        _rcu_read_unlock(lock);
        goto LABEL_62;
      }
      v58 = *v30;
      _rcu_read_unlock(lock);
      if ( v24 != v58 )
        goto LABEL_59;
    }
    LOBYTE(v24) = 0;
    goto LABEL_62;
  }
LABEL_24:
  v18 = 0xFFFFFFFFLL;
LABEL_34:
  if ( !*(_QWORD *)a3 )
    return 4294967274LL;
LABEL_60:
  if ( *(_BYTE *)(a3 + 8) != 1 )
    return 4294967280LL;
  LOBYTE(v24) = 1;
  v62 = v18;
LABEL_62:
  v32 = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v4 + 104) + *(_DWORD *)(a3 + 24)), 2080);
  if ( !v32 )
    return 4294967284LL;
  v33 = *(int *)(v4 + 104);
  v34 = v32;
  v59 = v24;
  v35 = v9;
  v36 = *(_QWORD *)(v32 + 224) + v33;
  v60 = v4;
  v37 = v13;
  LODWORD(v33) = *(_DWORD *)(v32 + 208) + v33;
  *(_QWORD *)(v32 + 224) = v36;
  v38 = v12;
  *(_DWORD *)(v32 + 208) = v33;
  v39 = a4;
  v40 = *(const void **)(a3 + 16);
  v41 = *(_QWORD *)(a3 + 24);
  v42 = (void *)skb_put(v32, (unsigned int)v41);
  v43 = memcpy(v42, v40, (unsigned int)v41);
  if ( *(_BYTE *)(v35 + 1526) == 1 )
  {
    v45 = *(_DWORD *)(v8 + 4704);
    if ( v45 <= 7 && ((1 << v45) & 0x8A) != 0 && *(_DWORD *)(a3 + 36) )
    {
      v46 = _rcu_read_lock(v43, v44);
      v47 = *(_DWORD *)(v8 + 4704);
      if ( v47 == 3 )
      {
        v48 = 4136;
      }
      else
      {
        if ( v47 != 1 )
        {
LABEL_84:
          _rcu_read_unlock(v46);
          goto LABEL_85;
        }
        v48 = 2424;
      }
      v50 = *(_QWORD *)(v8 + v48);
      if ( v50 && *(int *)(a3 + 36) >= 1 )
      {
        v51 = *(_BYTE *)(v50 + 36);
        v52 = 0;
        do
        {
          v53 = *(unsigned __int16 *)(*(_QWORD *)(a3 + 40) + 2 * v52++);
          *((_BYTE *)v42 + v53) = v51;
        }
        while ( v52 < *(int *)(a3 + 36) );
      }
      goto LABEL_84;
    }
  }
LABEL_85:
  v54 = *(_DWORD *)(v34 + 80);
  *(_DWORD *)(v34 + 40) = v37;
  *(_DWORD *)(v34 + 80) = v54 | 0x400;
  *(_QWORD *)(v34 + 16) = *(_QWORD *)(v8 + 1592);
  if ( (*(_BYTE *)(a3 + 33) & 1) != 0 )
  {
    v55 = v60;
    *v39 = 0xFFFFFFFFLL;
  }
  else
  {
    v55 = v60;
    v56 = ieee80211_attach_ack_skb(v60, v34, v39, 0xCC0u);
    if ( v56 )
    {
      v57 = v56;
      sk_skb_reason_drop(0);
      return v57;
    }
  }
  if ( (v59 & 1) != 0 )
  {
    *(_DWORD *)(v34 + 40) |= 0x2002000u;
    if ( (*(_QWORD *)(v55 + 96) & 0x40000) != 0 )
      *(_DWORD *)(v34 + 44) = *(_DWORD *)(v34 + 44) & 0xFFE1FFFF | ((*(_BYTE *)(v55 + 141) & 0xF) << 17);
    result = ieee80211_start_roc_work(v55, v38, *(_QWORD *)a3, *(_DWORD *)(a3 + 12), v39, v34, 1u);
    if ( (_DWORD)result )
    {
      v57 = result;
      ieee80211_free_txskb(v55);
      return v57;
    }
  }
  else
  {
    ieee80211_tx_skb_tid(v38, v34, 7, v62);
    return 0;
  }
  return result;
}
