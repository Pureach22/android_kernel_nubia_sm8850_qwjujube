__int64 __fastcall ieee80211_chswitch_post_beacon(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x22
  __int64 v6; // x21
  __int64 (__fastcall *v7)(__int64, __int64, __int64); // x8
  __int64 v8; // x2
  int v9; // w0
  __int64 v11; // x9
  __int64 v12; // x1
  __int64 v13; // x8

  v1 = *(_QWORD *)a1;
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 944) + 830LL) & 1) == 0 )
    __break(0x800u);
  ieee80211_vif_unblock_queues_csa(v1);
  *(_BYTE *)(*(_QWORD *)(a1 + 944) + 830LL) = 0;
  v5 = *(_QWORD *)a1;
  *(_BYTE *)(a1 + 786) = 0;
  *(_BYTE *)(a1 + 784) = 0;
  v6 = *(_QWORD *)(v5 + 1616);
  if ( (*(_BYTE *)(v6 + 1471) & 1) != 0
    || (v3 = *(unsigned int *)(v5 + 1624), (v3 & 0x20) != 0)
    || (drv_post_channel_switch___already_done_0 & 1) != 0 )
  {
    if ( (*(_BYTE *)(v5 + 1624) & 0x20) == 0 )
      goto LABEL_24;
  }
  else
  {
    v11 = *(_QWORD *)(v5 + 1608);
    drv_post_channel_switch___already_done_0 = 1;
    if ( v11 )
      v12 = v11 + 296;
    else
      v12 = v5 + 1640;
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v12);
    __break(0x800u);
    if ( (*(_BYTE *)(v5 + 1624) & 0x20) == 0 )
      goto LABEL_24;
  }
  v3 = *(unsigned int *)(a1 + 8);
  if ( *(_WORD *)(v5 + 5800) )
  {
    if ( (((unsigned __int64)*(unsigned __int16 *)(v5 + 5802) >> v3) & 1) == 0 )
      return cfg80211_ch_switch_notify(*(_QWORD *)(v1 + 1608), *(_QWORD *)(a1 + 944) + 136LL, v3);
  }
  else if ( (_DWORD)v3 )
  {
    return cfg80211_ch_switch_notify(*(_QWORD *)(v1 + 1608), *(_QWORD *)(a1 + 944) + 136LL, v3);
  }
  v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v6 + 464) + 672LL);
  if ( v7 )
  {
    v8 = *(_QWORD *)(a1 + 944);
    if ( *((_DWORD *)v7 - 1) != 2048840867 )
      __break(0x8228u);
    v9 = v7(v6, v5 + 4720, v8);
  }
  else
  {
    v9 = 0;
  }
  if ( !v9 )
  {
    v3 = *(unsigned int *)(a1 + 8);
    return cfg80211_ch_switch_notify(*(_QWORD *)(v1 + 1608), *(_QWORD *)(a1 + 944) + 136LL, v3);
  }
LABEL_24:
  v13 = *(_QWORD *)a1;
  if ( *(_WORD *)(*(_QWORD *)a1 + 5800LL) )
    printk(&unk_BB637, v13 + 1640, *(unsigned int *)(a1 + 8), v4);
  else
    printk(&unk_BB1D9, v13 + 1640, v3, v4);
  return wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v1 + 1616) + 72LL), v1 + 2432);
}
