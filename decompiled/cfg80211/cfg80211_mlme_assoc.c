__int64 __fastcall cfg80211_mlme_assoc(_BYTE **a1, __int64 a2, __int64 *a3, const char **a4)
{
  __int64 v7; // x8
  __int64 v8; // x24
  __int64 *v9; // x23
  __int64 lock; // x0
  __int64 v12; // x26
  _DWORD *v13; // x25
  __int64 v14; // x8
  __int64 v15; // x8
  unsigned __int16 *v16; // x8
  unsigned __int64 v17; // x10
  unsigned int v18; // w9
  int v19; // w15
  int v20; // w12
  const char *v21; // x19
  unsigned __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x9
  unsigned __int16 *v25; // x13
  unsigned __int16 *v26; // x14
  unsigned __int64 v28; // x16
  int v29; // w17
  unsigned __int64 v30; // x15
  __int64 v31; // x0
  __int64 v32; // x15
  int v33; // w14
  __int64 v34; // x17
  __int64 v35; // x16
  __int64 result; // x0
  _DWORD *v37; // x8
  __int64 v38; // x8
  __int64 v39; // x21
  __int64 *v40; // x20
  __int64 v41; // x8
  const char *v42; // x19
  unsigned int v45; // w9
  __int64 v46; // x8
  unsigned int v49; // w10
  __int64 v50; // x8
  unsigned int v56; // w10
  __int64 v57; // x8
  unsigned int v60; // w9
  char s2[4]; // [xsp+Ch] [xbp-84h] BYREF
  _QWORD v62[16]; // [xsp+10h] [xbp-80h] BYREF

  v62[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *((char *)a3 + 792);
  v8 = *(_QWORD *)(a2 + 992);
  memset(v62, 0, 120);
  if ( v7 < 0 )
  {
LABEL_78:
    if ( (*(_BYTE *)(v8 + 164) & 1) != 0
      && ((v41 = a3[2]) == 0
       || *(_DWORD *)v41 ^ *(_DWORD *)(v8 + 280) | *(unsigned __int16 *)(v41 + 4) ^ *(unsigned __int16 *)(v8 + 284)) )
    {
      result = 4294967182LL;
    }
    else
    {
      if ( *a3
        && !(**(_DWORD **)(a2 + 1008) ^ *(_DWORD *)(*a3 + 72)
           | *(unsigned __int16 *)(*(_QWORD *)(a2 + 1008) + 4LL) ^ *(unsigned __int16 *)(*a3 + 76))
        || ((char)a3[99] & 0x80000000) == 0
        && !(**(_DWORD **)(a2 + 1008) ^ *(_DWORD *)a3[98]
           | *(unsigned __int16 *)(*(_QWORD *)(a2 + 1008) + 4LL) ^ *(unsigned __int16 *)(a3[98] + 4)) )
      {
        goto LABEL_75;
      }
      cfg80211_oper_and_ht_capa((_BYTE *)a3 + 195, a1[289]);
      cfg80211_oper_and_vht_capa((_BYTE *)a3 + 233, a1[290]);
      v37 = *((_DWORD **)*a1 + 43);
      if ( *(v37 - 1) != -1000839138 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(_BYTE **, __int64, __int64 *))v37)(a1 + 124, a2, a3);
      if ( !(_DWORD)result )
      {
        if ( *a3 )
        {
          cfg80211_ref_bss(a1 + 124);
          v38 = *a3;
          _X9 = (unsigned int *)(*a3 - 32);
          __asm { PRFM            #0x11, [X9] }
          do
            v56 = __ldxr(_X9);
          while ( __stxr(v56 + 1, _X9) );
          v57 = *(_QWORD *)(v38 + 40);
          if ( v57 )
          {
            _X8 = (unsigned int *)(v57 - 32);
            __asm { PRFM            #0x11, [X8] }
            do
              v60 = __ldxr(_X8);
            while ( __stxr(v60 + 1, _X8) );
          }
        }
        v39 = 0;
        v40 = a3 + 38;
        do
        {
          if ( v40[v39] )
          {
            cfg80211_ref_bss(a1 + 124);
            v46 = v40[v39];
            _X9 = (unsigned int *)(v46 - 32);
            __asm { PRFM            #0x11, [X9] }
            do
              v49 = __ldxr(_X9);
            while ( __stxr(v49 + 1, _X9) );
            v50 = *(_QWORD *)(v46 + 40);
            if ( v50 )
            {
              _X8 = (unsigned int *)(v50 - 32);
              __asm { PRFM            #0x11, [X8] }
              do
                v45 = __ldxr(_X8);
              while ( __stxr(v45 + 1, _X8) );
            }
          }
          v39 += 4;
        }
        while ( v39 != 60 );
        result = 0;
      }
    }
    goto LABEL_76;
  }
  if ( (unsigned int)v7 >= 0xF )
    goto LABEL_99;
  v9 = a3 + 38;
  if ( !a3[4 * v7 + 38] )
  {
    do_trace_netlink_extack("no BSS for assoc link");
    if ( a4 )
      *a4 = "no BSS for assoc link";
    goto LABEL_75;
  }
  lock = _rcu_read_lock();
  v12 = 0;
  v13 = (_DWORD *)a3 + 83;
  do
  {
    v14 = *(_QWORD *)(v13 - 7);
    if ( v14 )
    {
      if ( !(**(_DWORD **)(a2 + 1008) ^ *(_DWORD *)(v14 + 72)
           | *(unsigned __int16 *)(*(_QWORD *)(a2 + 1008) + 4LL) ^ *(unsigned __int16 *)(v14 + 76)) )
      {
        v21 = "BSSID must not be our address";
        goto LABEL_71;
      }
      v15 = *(_QWORD *)(v14 + 8);
      s2[0] = 107;
      lock = cfg80211_find_elem_match(255, (int)v15 + 29, *(_DWORD *)(v15 + 24), s2, 1u);
      if ( !lock )
      {
        v21 = "MLO BSS w/o ML element";
        goto LABEL_71;
      }
      v16 = (unsigned __int16 *)(lock + 3);
      if ( lock == -3 )
        goto LABEL_30;
      v17 = *(unsigned __int8 *)(lock + 1) - 1LL;
      if ( v17 < 2 )
        goto LABEL_30;
      v18 = *v16;
      switch ( v18 & 7 )
      {
        case 3u:
          LOBYTE(v20) = 7;
          break;
        case 1u:
          LOBYTE(v20) = (v18 & 0x10) != 0 ? 2 : 1;
          break;
        case 0u:
          v19 = (v18 & 0x10) != 0 ? 8 : 7;
          v20 = v19
              + (((unsigned __int8)(v18 & 0xE0) >> 5) & 1)
              + (((unsigned __int8)v18 >> 5) & 2)
              + ((v18 >> 6) & 2)
              + ((v18 >> 7) & 2)
              + ((v18 >> 9) & 1);
          break;
        default:
          goto LABEL_30;
      }
      if ( (unsigned __int64)(unsigned __int8)v20 + 2 > v17
        || (v18 & 7) != 0
        || *(unsigned __int8 *)(lock + 5) < (unsigned int)(unsigned __int8)v20 )
      {
LABEL_30:
        v21 = "BSS with invalid ML element";
        goto LABEL_71;
      }
      v62[v12] = v16;
      if ( (v18 & 0x10) == 0 || v12 != *(unsigned __int8 *)(lock + 12) )
      {
        v21 = "link ID mismatch";
LABEL_71:
        lock = do_trace_netlink_extack(v21);
        if ( a4 )
          *a4 = v21;
        *v13 = -22;
        goto LABEL_74;
      }
    }
    ++v12;
    v13 += 8;
  }
  while ( v12 != 15 );
  v22 = *((unsigned __int8 *)a3 + 792);
  if ( v22 > 0xE )
LABEL_99:
    __break(0x5512u);
  if ( !v62[v22] )
  {
LABEL_97:
    __break(0x800u);
    goto LABEL_74;
  }
  v23 = *((unsigned __int8 *)a3 + 792);
  v24 = 0;
  while ( 1 )
  {
    if ( (char)v23 == v24 || !*v9 )
      goto LABEL_35;
    v25 = (unsigned __int16 *)v62[v24];
    if ( !v25 )
      goto LABEL_97;
    if ( (unsigned int)v23 > 0xE )
      goto LABEL_99;
    v26 = (unsigned __int16 *)v62[v23];
    if ( *(_DWORD *)((char *)v26 + 3) != *(_DWORD *)((char *)v25 + 3)
      || *(unsigned __int16 *)((char *)v26 + 7) != *(unsigned __int16 *)((char *)v25 + 7) )
    {
      v42 = "AP MLD address mismatch";
      goto LABEL_94;
    }
    v28 = *v26;
    if ( (v28 & 0x80) != 0 )
    {
      if ( (v28 & 0x10) != 0 )
        v32 = 10;
      else
        v32 = 9;
      v29 = *(unsigned __int16 *)((char *)v26 + v32 + ((v28 >> 5) & 1) + ((v28 >> 5) & 2));
      v30 = *v25;
      if ( (v30 & 0x80) == 0 )
      {
LABEL_55:
        lock = 0;
        goto LABEL_56;
      }
    }
    else
    {
      v29 = 0;
      v30 = *v25;
      if ( (v30 & 0x80) == 0 )
        goto LABEL_55;
    }
    v31 = (v30 & 0x10) != 0 ? 10LL : 9LL;
    lock = *(unsigned __int16 *)((char *)v25 + v31 + ((v30 >> 5) & 1) + ((v30 >> 5) & 2));
LABEL_56:
    if ( v29 != (_DWORD)lock )
      break;
    if ( (v28 & 0x100) != 0 )
    {
      lock = v28 >> 5;
      if ( (v28 & 0x10) != 0 )
        v34 = 10;
      else
        v34 = 9;
      v33 = *(unsigned __int16 *)((char *)v26 + v34 + ((v28 >> 5) & 1) + ((v28 >> 5) & 2) + ((v28 >> 6) & 2));
      if ( (v30 & 0x100) == 0 )
      {
LABEL_34:
        if ( v33 )
          goto LABEL_68;
        goto LABEL_35;
      }
    }
    else
    {
      v33 = 0;
      if ( (v30 & 0x100) == 0 )
        goto LABEL_34;
    }
    lock = (v30 >> 5) & 1;
    if ( (v30 & 0x10) != 0 )
      v35 = 10;
    else
      v35 = 9;
    if ( v33 != *(unsigned __int16 *)((char *)v25 + v35 + lock + ((v30 >> 5) & 2) + ((v30 >> 6) & 2)) )
    {
LABEL_68:
      v42 = "link MLD capabilities/ops mismatch";
      goto LABEL_94;
    }
LABEL_35:
    ++v24;
    v9 += 4;
    if ( v24 == 15 )
    {
      _rcu_read_unlock(lock);
      goto LABEL_78;
    }
  }
  v42 = "link EML capabilities mismatch";
LABEL_94:
  lock = do_trace_netlink_extack(v42);
  if ( a4 )
    *a4 = v42;
  *((_DWORD *)v9 + 7) = -22;
LABEL_74:
  _rcu_read_unlock(lock);
LABEL_75:
  result = 4294967274LL;
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return result;
}
