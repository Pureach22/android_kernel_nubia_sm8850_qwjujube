__int64 __fastcall _ieee80211_beacon_get(
        unsigned __int64 a1,
        _DWORD *a2,
        __int64 a3,
        char a4,
        unsigned int a5,
        int a6,
        _QWORD *a7)
{
  __int64 v7; // x22
  __int64 v8; // x27
  unsigned __int64 v11; // x21
  _DWORD *v14; // x19
  unsigned __int64 v15; // x20
  __int64 lock; // x0
  __int64 v17; // x26
  _BYTE *v18; // x8
  _BYTE *v19; // x24
  _BYTE *v20; // x28
  __int64 v21; // x7
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  bool v25; // cf
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned int v28; // w8
  __int64 v29; // x23
  bool v30; // zf
  int v31; // w11
  __int64 v32; // x8
  __int64 *v33; // x9
  int v34; // w8
  __int64 v35; // x7
  __int64 v37; // x10
  unsigned __int64 v38; // x12
  __int64 v39; // x8
  unsigned __int64 v40; // x14
  char v41; // w9
  int v42; // w13
  __int64 v43; // x11
  unsigned __int64 v44; // x13
  __int64 v45; // x8
  __int64 v46; // x9
  size_t v47; // x27
  const void *v48; // x25
  void *v49; // x0
  unsigned __int64 StatusReg; // x26
  __int64 v51; // x28
  unsigned __int64 v52; // [xsp+8h] [xbp-8h]

  v11 = a5;
  v14 = a2;
  v15 = a1;
  lock = _rcu_read_lock(a1, a2);
  if ( (unsigned int)v11 >= 0x10 )
  {
    __break(0x5512u);
LABEL_77:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v51 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ieee80211_beacon_get_ap_ema_list__alloc_tag;
    v52 = 24LL * **(unsigned __int8 **)(v8 + 40) + 8;
    lock = _kmalloc_noprof(v52, 2336);
    v19 = (_BYTE *)lock;
    *(_QWORD *)(StatusReg + 80) = v51;
    if ( lock )
    {
LABEL_14:
      *v19 = 0;
      v20 = v19 + 8;
      if ( **(_BYTE **)(v8 + 40) )
      {
        v21 = 0;
        while ( 1 )
        {
          lock = ieee80211_beacon_get_ap(v15, v14, v11, &v20[24 * (unsigned __int8)v21 + 8], a4 & 1, v8, v7, v21);
          LODWORD(v21) = (unsigned __int8)*v19;
          v22 = v52;
          v23 = 24LL * (unsigned __int8)*v19 + 8;
          v25 = v52 >= v23;
          v24 = v52 - v23;
          v25 = v25 && v24 >= 8;
          if ( !v25 )
            goto LABEL_77;
          v26 = 24LL * (unsigned __int8)*v19 + 8;
          v25 = v52 >= v26;
          v27 = v52 - v26;
          if ( !v25 || v27 < 8 )
            goto LABEL_77;
          *(_QWORD *)&v20[24 * (unsigned __int8)*v19] = lock;
          if ( !lock )
            break;
          v21 = (unsigned int)(v21 + 1);
          *v19 = v21;
          v28 = **(unsigned __int8 **)(v8 + 40);
          if ( v28 <= (unsigned __int8)v21 )
          {
            v22 = v52;
LABEL_65:
            if ( v28 == (unsigned __int8)v21 )
              goto LABEL_74;
            if ( !(_BYTE)v21 )
            {
LABEL_72:
              lock = kfree(v19);
              goto LABEL_73;
            }
            v14 = nullptr;
            v15 = v22 - 8;
            v11 = 8;
            while ( v22 >= v11 && v15 >= 8 && v22 >= v11 )
            {
              sk_skb_reason_drop(0);
              v14 = (_DWORD *)((char *)v14 + 1);
              v22 = v52;
              v11 += 24LL;
              v15 -= 24LL;
              if ( (unsigned __int64)v14 >= (unsigned __int8)*v19 )
                goto LABEL_72;
            }
            goto LABEL_77;
          }
        }
        v28 = **(unsigned __int8 **)(v8 + 40);
        goto LABEL_65;
      }
    }
LABEL_74:
    v17 = 0;
    *a7 = v19;
    goto LABEL_44;
  }
  v11 = *(_QWORD *)&v14[2 * (unsigned int)v11 - 38];
  if ( !v11 )
    goto LABEL_43;
  v17 = 0;
  v7 = *(_QWORD *)(*(_QWORD *)(v11 + 944) + 832LL);
  if ( (*((_QWORD *)v14 - 386) & 1) == 0 || !v7 )
    goto LABEL_44;
  if ( a3 )
  {
    *(_WORD *)(a3 + 8) = 0;
    *(_QWORD *)a3 = 0;
  }
  if ( *v14 == 1 )
  {
    v29 = *((_QWORD *)v14 - 285);
    if ( v29 )
    {
      if ( !*(_WORD *)(v29 + 32) )
        goto LABEL_62;
      if ( (a4 & 1) == 0 )
      {
        v30 = --*(_BYTE *)(v29 + 36) == 0;
        if ( v30 )
          __break(0x800u);
      }
      v31 = *v14;
      v32 = 16;
      if ( *v14 == 1 )
      {
        v33 = (__int64 *)v29;
      }
      else
      {
        v33 = (__int64 *)v29;
        if ( v31 != 7 )
        {
          if ( v31 != 3 )
            goto LABEL_62;
          v33 = (__int64 *)(v29 + 8);
          v32 = 20;
        }
      }
      v37 = *v33;
      v38 = *(int *)(v29 + v32);
      v39 = *(_QWORD *)(v11 + 544);
      v40 = *(unsigned __int16 *)(v29 + 32);
      v41 = *(_BYTE *)(v29 + 36);
      v42 = *(unsigned __int8 *)(*(_QWORD *)(v11 + 944) + 830LL);
      if ( *(_WORD *)(v29 + 32) )
      {
        if ( v40 >= v38 )
        {
LABEL_75:
          __break(0x800u);
LABEL_62:
          lock = _netdev_alloc_skb(
                   0,
                   (unsigned int)(*(_DWORD *)(v29 + 16) + *(_DWORD *)(v15 + 1508) + *(_DWORD *)(v15 + 108)),
                   2080);
          v17 = lock;
          if ( lock )
          {
            v45 = *(int *)(v15 + 1508);
            v46 = *(_QWORD *)(lock + 224) + v45;
            LODWORD(v45) = *(_DWORD *)(lock + 208) + v45;
            *(_QWORD *)(lock + 224) = v46;
            *(_DWORD *)(lock + 208) = v45;
            v47 = *(unsigned int *)(v29 + 16);
            v48 = *(const void **)v29;
            v49 = (void *)skb_put(lock, (unsigned int)v47);
            memcpy(v49, v48, v47);
            **(_WORD **)(v17 + 224) = 128;
            lock = ieee80211_beacon_get_finish(v15, v14, v11, a3, v29, v17, v7, 0);
          }
          goto LABEL_44;
        }
        *(_BYTE *)(v37 + v40) = v41;
        v31 = *v14;
      }
      v30 = v31 == 3;
      v43 = v39 + 24;
      if ( v30 && v39 )
        *(_BYTE *)(v43 + *(unsigned __int16 *)(v39 + 20)) = v41;
      if ( !v42 )
        goto LABEL_62;
      v44 = *(unsigned __int16 *)(v29 + 34);
      if ( !*(_WORD *)(v29 + 34) )
        goto LABEL_59;
      if ( v44 < v38 )
      {
        *(_BYTE *)(v37 + v44) = v41;
LABEL_59:
        if ( *v14 == 3 && v39 )
          *(_BYTE *)(v43 + *(unsigned __int16 *)(v39 + 22)) = v41;
        goto LABEL_62;
      }
      goto LABEL_75;
    }
LABEL_43:
    v17 = 0;
    goto LABEL_44;
  }
  if ( *v14 == 3 )
  {
    v8 = *(_QWORD *)(v11 + 536);
    if ( v8 )
    {
      v18 = *(_BYTE **)(v8 + 40);
      if ( a7 )
      {
        if ( v18 && *v18 )
        {
          v52 = 24LL * **(unsigned __int8 **)(v8 + 40) + 8;
          lock = _kmalloc_noprof(v52, 2336);
          v19 = (_BYTE *)lock;
          if ( lock )
            goto LABEL_14;
        }
        else
        {
LABEL_73:
          v19 = nullptr;
        }
        goto LABEL_74;
      }
      if ( !v18 || (v34 = (unsigned __int8)*v18) == 0 )
      {
        v35 = 0;
LABEL_46:
        lock = ieee80211_beacon_get_ap(v15, v14, v11, a3, a4 & 1, *(_QWORD *)(v11 + 536), v7, v35);
        v17 = lock;
        goto LABEL_44;
      }
      if ( v34 > a6 )
      {
        if ( a6 >= 0 )
          v35 = (unsigned int)a6;
        else
          v35 = (unsigned int)v34;
        goto LABEL_46;
      }
    }
    goto LABEL_43;
  }
  v17 = 0;
  __break(0x800u);
LABEL_44:
  _rcu_read_unlock(lock);
  return v17;
}
