__int64 __fastcall ieee80211_txq_teardown_flows(__int64 a1)
{
  unsigned int v2; // w20
  __int64 v3; // x0

  kvfree(*(_QWORD *)(a1 + 280));
  *(_QWORD *)(a1 + 280) = 0;
  raw_spin_lock_bh(a1 + 240);
  if ( *(_DWORD *)(a1 + 244) )
  {
    v2 = 0;
    do
      fq_flow_reset(a1 + 208, *(_QWORD *)(a1 + 208) + 56LL * (int)v2++);
    while ( v2 < *(_DWORD *)(a1 + 244) );
  }
  kvfree(*(_QWORD *)(a1 + 208));
  v3 = *(_QWORD *)(a1 + 216);
  *(_QWORD *)(a1 + 208) = 0;
  bitmap_free(v3);
  *(_QWORD *)(a1 + 216) = 0;
  return raw_spin_unlock_bh(a1 + 240);
}
