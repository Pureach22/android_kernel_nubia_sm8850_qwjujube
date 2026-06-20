__int64 __fastcall ieee80211_stop_tx_ba_session(__int64 a1, unsigned __int16 a2)
{
  __int64 v3; // x22
  int v4; // w21
  __int64 v6; // x19
  __int64 v8; // x9
  __int64 v9; // x8
  unsigned int v10; // w20
  __int64 v11; // x20
  unsigned __int64 v18; // x10

  v3 = *(_QWORD *)(*(_QWORD *)(a1 - 2608) + 1616LL);
  if ( !*(_QWORD *)(*(_QWORD *)(v3 + 464) + 384LL) )
    return 4294967274LL;
  v4 = a2;
  if ( a2 > 0xFu )
    return 4294967274LL;
  v6 = a1 - 2540;
  raw_spin_lock_bh(a1 - 2540);
  v8 = *(_QWORD *)(a1 + 8LL * a2 - 1784);
  if ( !v8 )
  {
    v10 = -2;
    goto LABEL_10;
  }
  v9 = a1;
  if ( *(unsigned __int8 *)(a1 - 1356) == a2 )
  {
    v11 = *(_QWORD *)(a1 + 8LL * a2 - 1784);
    _warn_printk("Requested to stop BA session on reserved tid=%d", v4);
    v8 = v11;
    v9 = a1;
    __break(0x800u);
    if ( (*(_QWORD *)(v11 + 128) & 8) == 0 )
    {
LABEL_7:
      _X9 = (unsigned __int64 *)(v8 + 128);
      __asm { PRFM            #0x11, [X9] }
      do
        v18 = __ldxr(_X9);
      while ( __stxr(v18 | 0x20, _X9) );
      wiphy_work_queue(*(_QWORD *)(v3 + 72), v9 - 1808);
    }
  }
  else if ( (*(_QWORD *)(v8 + 128) & 8) == 0 )
  {
    goto LABEL_7;
  }
  v10 = 0;
LABEL_10:
  raw_spin_unlock_bh(v6);
  return v10;
}
