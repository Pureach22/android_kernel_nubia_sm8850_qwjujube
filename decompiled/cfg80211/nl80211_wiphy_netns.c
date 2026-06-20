unsigned __int64 __fastcall nl80211_wiphy_netns(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v4; // x9
  unsigned __int64 result; // x0
  __int64 v6; // x8
  unsigned __int64 v7; // x19
  unsigned int v8; // w8
  unsigned int v10; // w20
  int v16; // w9

  v2 = *(_QWORD *)(a2 + 32);
  v3 = *(_QWORD *)(a2 + 48);
  v4 = *(_QWORD *)(v2 + 656);
  if ( v4 )
  {
    result = get_net_ns_by_pid(*(unsigned int *)(v4 + 4));
  }
  else
  {
    v6 = *(_QWORD *)(v2 + 1752);
    if ( !v6 )
      return 4294967274LL;
    result = get_net_ns_by_fd(*(unsigned int *)(v6 + 4));
  }
  v7 = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)result;
  if ( *(_QWORD *)(v3 + 2344) == result )
    v8 = 0;
  else
    v8 = cfg80211_switch_netns(v3, result);
  _X0 = (unsigned int *)(v7 + 140);
  __asm { PRFM            #0x11, [X0] }
  do
    v16 = __ldxr(_X0);
  while ( __stlxr(v16 - 1, _X0) );
  v10 = v8;
  if ( v16 == 1 )
  {
    __dmb(9u);
    _put_net(v7);
  }
  else if ( v16 <= 0 )
  {
    refcount_warn_saturate();
  }
  return v10;
}
