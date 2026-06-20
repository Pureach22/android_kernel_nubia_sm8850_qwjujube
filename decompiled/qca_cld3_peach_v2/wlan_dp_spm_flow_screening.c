__int64 __fastcall wlan_dp_spm_flow_screening(__int64 hash_net, __int64 a2)
{
  __int64 v2; // x21
  int v4; // w2
  int v6; // w9
  unsigned int v8; // w9
  __int64 result; // x0
  __int64 v10; // x0
  unsigned __int64 v15; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v19; // x9

  v2 = *(_QWORD *)(hash_net + 3736);
  if ( (*(_BYTE *)(a2 + 130) & 6) == 0 )
    hash_net = _skb_get_hash_net(0, a2);
  v4 = *(_DWORD *)(a2 + 152);
  _X19 = v2 + 528 + 24LL * (unsigned __int8)v4;
  if ( (*(_QWORD *)_X19 & 1) != 0 )
    return 0;
  v6 = *(_DWORD *)(_X19 + 8);
  if ( v6 )
    _ZF = v6 == v4;
  else
    _ZF = 0;
  if ( !_ZF )
  {
    wlan_dp_spm_s_tbl_check_n_add_flow(v2 + 528, _X19);
    return 0;
  }
  v8 = *(_DWORD *)(_X19 + 12) + 1;
  *(_DWORD *)(_X19 + 12) = v8;
  if ( v8 < 0xA )
    return 0;
  __asm { PRFM            #0x11, [X19] }
  do
    v15 = __ldxr((unsigned __int64 *)_X19);
  while ( __stlxr(v15 | 1, (unsigned __int64 *)_X19) );
  __dmb(0xBu);
  if ( (v15 & 1) != 0 )
    return 0;
  v10 = sched_clock(hash_net, a2);
  if ( (unsigned __int64)(v10 - *(_QWORD *)(_X19 + 16)) > 0x3B9ACA00 )
  {
    *(_QWORD *)(_X19 + 16) = v10;
    *(_DWORD *)(_X19 + 12) = 1;
    __asm { PRFM            #0x11, [X19] }
    do
      v19 = __ldxr((unsigned __int64 *)_X19);
    while ( __stxr(v19 & 0xFFFFFFFFFFFFFFFELL, (unsigned __int64 *)_X19) );
    return 0;
  }
  --*(_DWORD *)(v2 + 6672);
  qdf_mem_set((void *)(_X19 + 8), 0, 0);
  result = 1;
  __asm { PRFM            #0x11, [X19] }
  do
    v17 = __ldxr((unsigned __int64 *)_X19);
  while ( __stxr(v17 & 0xFFFFFFFFFFFFFFFELL, (unsigned __int64 *)_X19) );
  return result;
}
