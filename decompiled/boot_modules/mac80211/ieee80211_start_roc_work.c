__int64 __fastcall ieee80211_start_roc_work(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 *a5,
        __int64 a6,
        unsigned int a7)
{
  __int64 v15; // x0
  __int64 v16; // x20
  __int64 v17; // x8
  unsigned int v18; // w26
  __int64 v19; // x0
  __int64 *v20; // x24
  __int64 **v21; // x21
  char v22; // w8
  __int64 v23; // x25
  __int64 v24; // x0
  __int64 v25; // x27
  __int64 v26; // x0
  unsigned int v27; // w28
  __int64 v28; // x2
  __int64 *v29; // x1
  unsigned int v30; // w0
  unsigned int v31; // w19
  __int64 v32; // x2
  __int64 v33; // x0
  __int64 *v34; // x1
  __int64 v35; // x0
  __int64 v36; // x2
  __int64 v37; // x2
  __int64 *v38; // x22
  __int64 v39; // x20
  __int64 **v40; // x23
  __int64 v41; // x24
  __int64 v42; // x0
  __int64 v43; // x8

  if ( *(_WORD *)(a3 + 8) || (*(_BYTE *)(a1 + 1400) & 1) == 0 && !*(_QWORD *)(*(_QWORD *)(a1 + 464) + 472LL) )
    return 4294967201LL;
  v15 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
  v16 = v15;
  if ( !v15 )
    return 4294967284LL;
  v17 = a6;
  *(_QWORD *)(v15 + 56) = a6;
  if ( a4 )
    v18 = a4;
  else
    v18 = 10;
  *(_DWORD *)(v15 + 48) = v18;
  *(_DWORD *)(v15 + 52) = v18;
  *(_DWORD *)(v15 + 80) = a7;
  *(_QWORD *)(v15 + 16) = a2;
  *(_QWORD *)(v15 + 24) = a3;
  if ( v17 )
  {
    *(_QWORD *)(v15 + 72) = *a5;
  }
  else
  {
    v19 = ieee80211_mgmt_tx_cookie(a1);
    *(_QWORD *)(v16 + 64) = v19;
    *a5 = v19;
  }
  v20 = *(__int64 **)(a1 + 5264);
  v21 = (__int64 **)(a1 + 5264);
  if ( v20 != (__int64 *)(a1 + 5264) || *(_QWORD *)(a1 + 4696) )
    goto LABEL_16;
  if ( (ieee80211_is_radar_required(a1) & 1) != 0 )
  {
    v20 = *v21;
LABEL_16:
    if ( v20 == (__int64 *)v21 )
    {
LABEL_36:
      v29 = *(__int64 **)(a1 + 5272);
      if ( (__int64 **)v16 == v21 || (__int64 *)v16 == v29 || (__int64 **)*v29 != v21 )
      {
        _list_add_valid_or_report(v16, v29);
        return 0;
      }
      else
      {
        *(_QWORD *)(a1 + 5272) = v16;
        *(_QWORD *)v16 = v21;
        *(_QWORD *)(v16 + 8) = v29;
        *v29 = v16;
        return 0;
      }
    }
    v22 = 1;
    while ( 1 )
    {
      if ( v20[3] != a3 || v20[2] != a2 )
        goto LABEL_20;
      if ( (v20[4] & 1) == 0 )
      {
        v32 = *v20;
        v33 = v16;
        v34 = v20;
        goto LABEL_44;
      }
      if ( (v22 & 1) != 0 )
      {
        v23 = jiffies;
        if ( !*(_QWORD *)(*(_QWORD *)(a1 + 464) + 472LL) )
        {
          if ( *(_DWORD *)(v16 + 48) + (unsigned int)jiffies_to_msecs(jiffies - v20[5]) <= *(unsigned __int16 *)(*(_QWORD *)(a1 + 72) + 264LL) )
          {
            v37 = *v20;
            if ( *(__int64 **)(*v20 + 8) != v20 || (__int64 *)v16 == v20 || v16 == v37 )
            {
              _list_add_valid_or_report(v16, v20);
            }
            else
            {
              *(_QWORD *)(v37 + 8) = v16;
              *(_QWORD *)v16 = v37;
              *(_QWORD *)(v16 + 8) = v20;
              *v20 = v16;
            }
            *(_BYTE *)(v16 + 36) = *((_BYTE *)v20 + 36);
            ieee80211_handle_roc_started(v16, v23);
            v38 = *v21;
            if ( *v21 == (__int64 *)v21 )
              return 0;
            v39 = 0x7FFFFFFFFFFFFFFFLL;
            do
            {
              if ( *((_BYTE *)v38 + 32) != 1 )
                break;
              v40 = (__int64 **)*v38;
              v41 = v38[5];
              v42 = _msecs_to_jiffies(*((unsigned int *)v38 + 12));
              if ( (*((_BYTE *)v38 + 33) & 1) != 0
                || (*((_BYTE *)v38 + 34) & 1) != 0
                || (v43 = v42 + v41 - v23, v43 <= 0) )
              {
                ieee80211_roc_notify_destroy(v38);
              }
              else if ( v39 >= v43 )
              {
                v39 = v42 + v41 - v23;
              }
              v38 = (__int64 *)v40;
            }
            while ( v40 != v21 );
            if ( v39 == 0x7FFFFFFFFFFFFFFFLL )
              return 0;
            v35 = *(_QWORD *)(a1 + 72);
            v36 = v39;
LABEL_46:
            wiphy_delayed_work_queue(v35, a1 + 5192, v36);
            return 0;
          }
          goto LABEL_19;
        }
        if ( *((_BYTE *)v20 + 34) == 1 )
        {
          v24 = *((unsigned int *)v20 + 12);
LABEL_29:
          v25 = v20[5];
          v26 = _msecs_to_jiffies(v24);
          v27 = *(_DWORD *)(v16 + 48);
          if ( v27 <= (unsigned int)jiffies_to_msecs(v25 - v23 + v26) )
          {
            v28 = *v20;
            if ( *(__int64 **)(*v20 + 8) != v20 || (__int64 *)v16 == v20 || v28 == v16 )
            {
              _list_add_valid_or_report(v16, v20);
            }
            else
            {
              *(_QWORD *)(v28 + 8) = v16;
              *(_QWORD *)v16 = v28;
              *(_QWORD *)(v16 + 8) = v20;
              *v20 = v16;
            }
            if ( *((_BYTE *)v20 + 34) == 1 )
            {
              *(_BYTE *)(v16 + 34) = 1;
              ieee80211_handle_roc_started(v16, v23);
              return 0;
            }
            return 0;
          }
          goto LABEL_19;
        }
        v24 = *((unsigned int *)v20 + 12);
        if ( *(_DWORD *)(v16 + 48) <= (unsigned int)v24 )
          goto LABEL_29;
      }
LABEL_19:
      v22 = 0;
LABEL_20:
      v20 = (__int64 *)*v20;
      if ( v20 == (__int64 *)v21 )
        goto LABEL_36;
    }
  }
  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 464) + 472LL) )
  {
    _list_add(v16, *(_QWORD *)(a1 + 5272), a1 + 5264);
    v35 = *(_QWORD *)(a1 + 72);
    v36 = 0;
    goto LABEL_46;
  }
  v30 = drv_remain_on_channel(a1, a2, a3, v18, a7);
  if ( v30 )
  {
    v31 = v30;
    kfree(v16);
    return v31;
  }
  else
  {
    v34 = *(__int64 **)(a1 + 5272);
    v33 = v16;
    v32 = a1 + 5264;
    *(_BYTE *)(v16 + 32) = 1;
LABEL_44:
    _list_add(v33, v34, v32);
    return 0;
  }
}
