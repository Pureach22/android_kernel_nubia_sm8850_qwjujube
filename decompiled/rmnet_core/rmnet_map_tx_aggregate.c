__int64 __fastcall rmnet_map_tx_aggregate(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x22
  _QWORD *v6; // x20
  void (*v7)(void); // x8
  __int64 v8; // x24
  __int64 v9; // x28
  int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x11
  _DWORD *v15; // x0
  unsigned int v16; // w8
  void (__fastcall *v17)(_QWORD); // x8
  void (*v18)(void); // x8
  __int64 v19; // x1
  __int64 result; // x0
  char v21; // w8
  _QWORD *v22; // x8
  __int64 pages_entry; // x21
  __int64 v24; // x0
  __int64 (__fastcall *v25)(_QWORD); // x8
  __int64 v26; // x8
  unsigned int v33; // w10
  unsigned int v36; // w24
  unsigned int v37; // w24
  int v38; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v39; // [xsp+8h] [xbp-18h] BYREF
  __int64 v40; // [xsp+10h] [xbp-10h]
  __int64 v41; // [xsp+18h] [xbp-8h]

  v3 = a2 + 200LL * (a3 & 1);
  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_spin_lock_bh(v3 + 2208);
  v6 = (_QWORD *)(v3 + 2080);
  while ( 1 )
  {
    v9 = *(_QWORD *)(v3 + 2096);
    v8 = *(_QWORD *)(v3 + 2104);
    ktime_get_real_ts64(v3 + 2096);
    if ( (*(_BYTE *)(a2 + 11) & 0x10) != 0 )
    {
      v10 = *(_DWORD *)(a1 + 144);
      if ( v10 == 14286874 || (v10 & 0xFFFF0200) == 0x9B6D0200 )
        break;
    }
    v12 = *(_QWORD *)(v3 + 2096);
    v11 = *(_QWORD *)(v3 + 2104);
    if ( !*(_QWORD *)(v3 + 2216) )
    {
      v39 = 0;
      v40 = 0;
      set_normalized_timespec64(&v39, v12 - v9, v11 - v8);
      if ( v39 <= 0 && v40 <= rmnet_agg_bypass_time && *(unsigned __int16 *)(v3 + 2072) - *(_DWORD *)(a1 + 112) > 0 )
      {
        v21 = *(_BYTE *)(v3 + 2075);
        v38 = 2;
        LODWORD(v39) = 0;
        if ( (v21 & 1) == 0 )
          goto LABEL_48;
        v22 = *(_QWORD **)(v3 + 2256);
        if ( !v22 )
          goto LABEL_48;
        pages_entry = v22[2];
        if ( *(_DWORD *)(pages_entry + 52) == 1 )
          goto LABEL_46;
        v22 = (_QWORD *)*v22;
        *(_QWORD *)(v3 + 2256) = v22;
        if ( !v22 )
          goto LABEL_48;
        pages_entry = v22[2];
        if ( *(_DWORD *)(pages_entry + 52) == 1 )
          goto LABEL_46;
        v22 = (_QWORD *)*v22;
        *(_QWORD *)(v3 + 2256) = v22;
        if ( !v22 )
          goto LABEL_48;
        pages_entry = v22[2];
        if ( *(_DWORD *)(pages_entry + 52) == 1 )
          goto LABEL_46;
        v22 = (_QWORD *)*v22;
        *(_QWORD *)(v3 + 2256) = v22;
        if ( !v22 )
          goto LABEL_48;
        pages_entry = v22[2];
        if ( *(_DWORD *)(pages_entry + 52) == 1 )
          goto LABEL_46;
        v22 = (_QWORD *)*v22;
        *(_QWORD *)(v3 + 2256) = v22;
        if ( !v22 )
          goto LABEL_48;
        pages_entry = v22[2];
        if ( *(_DWORD *)(pages_entry + 52) == 1 )
        {
LABEL_46:
          _X9 = (unsigned int *)(pages_entry + 52);
          __asm { PRFM            #0x11, [X9] }
          do
            v33 = __ldxr(_X9);
          while ( __stxr(v33 + 1, _X9) );
          ++**(_QWORD **)(v3 + 2264);
          *(_QWORD *)(v3 + 2256) = *v22;
          if ( !pages_entry )
            goto LABEL_48;
          goto LABEL_49;
        }
        v22 = (_QWORD *)*v22;
        *(_QWORD *)(v3 + 2256) = v22;
        if ( v22 )
        {
          pages_entry = v22[2];
          if ( *(_DWORD *)(pages_entry + 52) == 1 )
            goto LABEL_46;
          *(_QWORD *)(v3 + 2256) = *v22;
        }
LABEL_48:
        pages_entry = rmnet_mem_get_pages_entry(2080, *(unsigned __int8 *)(v3 + 2237), &v39, &v38, 2);
        ++*(_QWORD *)(*(_QWORD *)(v3 + 2264) + 8LL);
        if ( pages_entry )
        {
LABEL_49:
          v24 = build_skb(
                  ((pages_entry << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL,
                  4096LL << *(_BYTE *)(v3 + 2237));
          if ( v24 )
          {
            *(_QWORD *)(v3 + 2216) = v24;
            ((void (*)(void))rmnet_map_linearize_copy)();
            *(_QWORD *)(*(_QWORD *)(v3 + 2216) + 16LL) = *(_QWORD *)(a1 + 16);
            *(_WORD *)(*(_QWORD *)(v3 + 2216) + 180LL) = -1792;
            *(_BYTE *)(v3 + 2236) = 1;
            ktime_get_real_ts64(v3 + 2080);
            goto LABEL_28;
          }
          v26 = *(_QWORD *)(pages_entry + 8);
          if ( (v26 & 1) != 0 )
            pages_entry = v26 - 1;
          _X8 = (unsigned int *)(pages_entry + 52);
          __asm { PRFM            #0x11, [X8] }
          do
          {
            v36 = __ldxr(_X8);
            v37 = v36 - 1;
          }
          while ( __stlxr(v37, _X8) );
          __dmb(0xBu);
          if ( !v37 )
            _folio_put(pages_entry);
        }
        *(_QWORD *)(v3 + 2216) = 0;
        *(_BYTE *)(v3 + 2236) = 0;
        *v6 = 0;
        *(_QWORD *)(v3 + 2088) = 0;
      }
      *(_WORD *)(a1 + 180) = -1792;
      v17 = *(void (__fastcall **)(_QWORD))(v3 + 2224);
      if ( *((_DWORD *)v17 - 1) != -1282094308 )
        __break(0x8228u);
      v17(a1);
      goto LABEL_30;
    }
    v13 = *(_QWORD *)(v3 + 2080);
    v14 = *(_QWORD *)(v3 + 2088);
    v39 = 0;
    v40 = 0;
    set_normalized_timespec64(&v39, v12 - v13, v11 - v14);
    v15 = *(_DWORD **)(v3 + 2216);
    if ( v15[29] )
      v16 = 0;
    else
      v16 = v15[53] - v15[52];
    if ( *(_DWORD *)(a1 + 112) <= v16
      && *(unsigned __int8 *)(v3 + 2236) < (unsigned int)*(unsigned __int8 *)(v3 + 2074)
      && v39 <= 0
      && v40 <= rmnet_agg_time_limit )
    {
      ((void (*)(void))rmnet_map_linearize_copy)();
      ++*(_BYTE *)(v3 + 2236);
LABEL_28:
      dev_kfree_skb_any_reason(a1, 1);
      if ( *(_DWORD *)(v3 + 2232) != -115 )
      {
        v19 = *(unsigned int *)(v3 + 2076);
        *(_DWORD *)(v3 + 2232) = -115;
        hrtimer_start_range_ns(v3 + 2112, v19, 0, 1);
      }
LABEL_30:
      result = raw_spin_unlock_bh(v3 + 2208);
      goto LABEL_55;
    }
    if ( v15 )
    {
      v7 = *(void (**)(void))(v3 + 2224);
      *(_QWORD *)(v3 + 2216) = 0;
      *(_BYTE *)(v3 + 2236) = 0;
      *v6 = 0;
      *(_QWORD *)(v3 + 2088) = 0;
      *(_DWORD *)(v3 + 2232) = 0;
      if ( *((_DWORD *)v7 - 1) != -1282094308 )
        __break(0x8228u);
      v7();
      raw_spin_unlock_bh(v3 + 2208);
      hrtimer_cancel(v3 + 2112);
    }
    else
    {
      raw_spin_unlock_bh(v3 + 2208);
    }
    raw_spin_lock_bh(v3 + 2208);
  }
  if ( *(_QWORD *)(v3 + 2216) )
  {
    v18 = *(void (**)(void))(v3 + 2224);
    *(_QWORD *)(v3 + 2216) = 0;
    *(_BYTE *)(v3 + 2236) = 0;
    *v6 = 0;
    *(_QWORD *)(v3 + 2088) = 0;
    *(_DWORD *)(v3 + 2232) = 0;
    if ( *((_DWORD *)v18 - 1) != -1282094308 )
      __break(0x8228u);
    v18();
    raw_spin_unlock_bh(v3 + 2208);
    hrtimer_cancel(v3 + 2112);
  }
  else
  {
    raw_spin_unlock_bh(v3 + 2208);
  }
  *(_WORD *)(a1 + 180) = -1792;
  v25 = *(__int64 (__fastcall **)(_QWORD))(v3 + 2224);
  if ( *((_DWORD *)v25 - 1) != -1282094308 )
    __break(0x8228u);
  result = v25(a1);
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
