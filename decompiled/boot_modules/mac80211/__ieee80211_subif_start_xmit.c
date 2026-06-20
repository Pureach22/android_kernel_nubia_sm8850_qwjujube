__int64 __fastcall _ieee80211_subif_start_xmit(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, __int64 a5)
{
  unsigned int v6; // w8
  __int64 v7; // x9
  __int64 v8; // x8
  int v13; // w9
  __int64 v14; // x0
  __int64 result; // x0
  __int64 v16; // x24
  __int16 v17; // w0
  _QWORD **v18; // x8
  int v19; // w8
  __int64 v20; // x25
  __int64 *v21; // x8
  unsigned int v22; // w9
  __int64 v23; // x9
  __int64 v24; // x9
  __int64 v25; // x24
  _QWORD *v26; // x23
  _QWORD *v27; // x1
  unsigned __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x9
  __int64 v31; // x8
  unsigned __int64 v38; // x11
  unsigned __int64 v41; // x9
  int v42; // w10
  int v43; // w9
  __int64 v44; // x8
  __int64 v45; // x8
  __int64 *v46; // x8
  __int64 v47; // x1
  _QWORD *v48; // x3
  _QWORD *v49; // x21
  unsigned __int64 v50; // [xsp+0h] [xbp-20h] BYREF
  __int64 v51; // [xsp+8h] [xbp-18h] BYREF
  int v52; // [xsp+10h] [xbp-10h]
  __int16 v53; // [xsp+14h] [xbp-Ch]
  __int64 v54; // [xsp+18h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD *)(a1 + 112);
  v7 = *(_QWORD *)(a2 + 4320);
  v50 = 0;
  if ( (v7 & 1) == 0 || v6 <= 0xD )
  {
    result = sk_skb_reason_drop(0);
    goto LABEL_10;
  }
  v8 = *(_QWORD *)(a1 + 24);
  if ( v8 )
  {
    v13 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 4304) + 171LL);
    if ( ((1 << *(_BYTE *)(v8 + 18)) & 0xFFFFEFBF) != 0 && *(unsigned __int8 *)(v8 + 560) != v13 )
      *(_BYTE *)(v8 + 560) = v13;
  }
  _rcu_read_lock(a1, a2);
  if ( !(unsigned int)ieee80211_lookup_ra_sta(a2 + 2688, a1, &v50) )
  {
    if ( v50 <= 0xFFFFFFFFFFFFF000LL )
      v16 = v50;
    else
      v16 = 0;
    v50 = v16;
    v17 = ((__int64 (__fastcall *)(__int64, __int64, __int64))ieee80211_select_queue)(a2 + 2688, v16, a1);
    *(_WORD *)(a1 + 124) = v17;
    v18 = *(_QWORD ***)(*(_QWORD *)(a2 + 4304) + 2536LL);
    if ( v18 && v16 && (**v18 & 2) != 0 )
    {
      if ( *(_BYTE *)(v16 + 2926) == 1 && *(_BYTE *)(v16 + 2698) == 1 )
      {
        if ( v17 )
        {
          if ( *(unsigned __int16 *)(a1 + 180) != *(unsigned __int16 *)(a2 + 4628) )
          {
            v19 = *(_DWORD *)(a1 + 144);
            if ( !*(_QWORD *)(v16 + 8LL * (v19 & 0xF) + 904) )
              ieee80211_start_tx_ba_session((_BYTE *)(v16 + 2688), v19 & 0xF, 0);
          }
        }
      }
    }
    else if ( !v16 )
    {
      goto LABEL_32;
    }
    v20 = *(_QWORD *)(v16 + 152);
    if ( !v20
      || (v21 = *(__int64 **)(a1 + 224), v22 = *((unsigned __int8 *)v21 + 12), v22 < 6)
      || __rev16(*((unsigned __int8 *)v21 + 13) | (v22 << 8)) == *(unsigned __int16 *)(a2 + 4628)
      || (v23 = *(_QWORD *)(a1 + 24), v53 = 0, v23)
      && (*(_BYTE *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 3LL) & 0x10) != 0 )
    {
LABEL_32:
      v14 = ieee80211_tx_skb_fixup(a1, 0);
      if ( v14 )
      {
        v25 = v50;
        v26 = (_QWORD *)v14;
        while ( 1 )
        {
          v27 = v26;
          v26 = (_QWORD *)*v26;
          *v27 = 0;
          if ( *((unsigned __int16 *)v27 + 90) == *(unsigned __int16 *)(a2 + 4628) )
            a4 |= 0x20u;
          v28 = ((__int64 (__fastcall *)(__int64, _QWORD *, _QWORD, __int64, _QWORD, __int64))ieee80211_build_hdr)(
                  a2 + 2688,
                  v27,
                  a3,
                  v25,
                  a4,
                  a5);
          if ( v28 >= 0xFFFFFFFFFFFFF001LL )
            break;
          v29 = *(_QWORD *)(a2 + 160);
          v30 = *(unsigned int *)(v28 + 112);
          v31 = _ReadStatusReg(TPIDR_EL1) + v29;
          _X10 = (unsigned __int64 *)(v31 + 24);
          __asm { PRFM            #0x11, [X10] }
          do
            v38 = __ldxr(_X10);
          while ( __stxr(v38 + v30, _X10) );
          _X8 = (unsigned __int64 *)(v31 + 16);
          __asm { PRFM            #0x11, [X8] }
          do
            v41 = __ldxr(_X8);
          while ( __stxr(v41 + 1, _X8) );
          v14 = ieee80211_xmit(a2 + 2688, v25, v28);
          if ( !v26 )
            goto LABEL_9;
        }
        v14 = kfree_skb_list_reason(v26, 2);
      }
      goto LABEL_9;
    }
    if ( (*(_WORD *)(v20 + 14) & 0x80) != 0 )
    {
      v24 = *(_QWORD *)(v16 + 8LL * (*(_DWORD *)(a1 + 144) & 7) + 904);
      if ( v24 )
      {
        if ( (*(_QWORD *)(v24 + 128) & 4) == 0 )
          goto LABEL_32;
        if ( *(_WORD *)(v24 + 144) )
        {
          *(_QWORD *)(v24 + 136) = jiffies;
          v21 = *(__int64 **)(a1 + 224);
        }
      }
    }
    v42 = *(_DWORD *)(a2 + 7408);
    v43 = *((_DWORD *)v21 + 2);
    v44 = *v21;
    v52 = v43;
    v51 = v44;
    if ( v42 == 4 )
    {
      v45 = *(_QWORD *)(a2 + 4720);
      if ( !v45 )
      {
        v47 = 0;
LABEL_52:
        v14 = ieee80211_tx_skb_fixup(a1, v47);
        if ( v14 )
        {
          v48 = (_QWORD *)v14;
          do
          {
            v49 = (_QWORD *)*v48;
            *v48 = 0;
            v14 = _ieee80211_xmit_fast(a2 + 2688, v16, (__int64 *)v20, (__int64)v48, 0, (int *)&v51, (__int64)&v51 + 6);
            v48 = v49;
          }
          while ( v49 );
        }
        goto LABEL_9;
      }
      v46 = (__int64 *)(v45 + 3600);
    }
    else
    {
      v46 = (__int64 *)(a2 + 8552);
    }
    v47 = *v46;
    goto LABEL_52;
  }
  v14 = sk_skb_reason_drop(0);
LABEL_9:
  result = _rcu_read_unlock(v14);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
