__int64 __fastcall ieee80211_sta_abort_chanswitch(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x20
  int v4; // w2
  int v5; // w8
  __int64 (*v6)(void); // x8
  __int64 v7; // x9
  __int64 v8; // x21
  const char *v9; // x1

  v1 = *(_QWORD *)result;
  if ( !*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)result + 1616LL) + 464LL) + 680LL) )
    return result;
  v2 = result;
  ieee80211_link_unreserve_chanctx((__int64 *)result);
  ieee80211_vif_unblock_queues_csa(v1);
  *(_BYTE *)(*(_QWORD *)(v2 + 944) + 830LL) = 0;
  v3 = *(_QWORD *)v2;
  *(_BYTE *)(v2 + 786) = 0;
  result = *(_QWORD *)(v3 + 1616);
  if ( (*(_BYTE *)(result + 1471) & 1) != 0
    || (v4 = *(_DWORD *)(v3 + 1624), (v4 & 0x20) != 0)
    || (drv_abort_channel_switch___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(v3 + 1624) & 0x20) == 0 )
      return result;
  }
  else
  {
    v7 = *(_QWORD *)(v3 + 1608);
    drv_abort_channel_switch___already_done = 1;
    v8 = result;
    if ( v7 )
      v9 = (const char *)(v7 + 296);
    else
      v9 = (const char *)(v3 + 1640);
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v9, v4);
    result = v8;
    __break(0x800u);
    if ( (*(_BYTE *)(v3 + 1624) & 0x20) == 0 )
      return result;
  }
  v5 = *(_DWORD *)(v2 + 8);
  if ( *(_WORD *)(v3 + 5800) )
  {
    if ( (((unsigned __int64)*(unsigned __int16 *)(v3 + 5802) >> v5) & 1) == 0 )
      return result;
  }
  else if ( v5 )
  {
    return result;
  }
  v6 = *(__int64 (**)(void))(*(_QWORD *)(result + 464) + 680LL);
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != -224849985 )
      __break(0x8228u);
    return v6();
  }
  return result;
}
