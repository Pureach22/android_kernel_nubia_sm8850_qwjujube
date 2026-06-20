__int64 __fastcall ieee80211_stop_ap(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x9
  _QWORD *v6; // x21
  __int64 v7; // x27
  __int64 v8; // x22
  __int64 v9; // x28
  __int64 v10; // x26
  __int64 v11; // x25
  __int64 v12; // x8
  _QWORD *i; // x20
  __int64 v14; // x0
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x23
  void (__fastcall *v18)(__int64, __int64, __int64); // x8
  __int64 result; // x0
  __int64 v20; // x9
  __int64 v21; // x1
  unsigned __int64 v28; // x10
  __int64 v31; // [xsp+10h] [xbp-40h]
  _QWORD v32[2]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v33; // [xsp+28h] [xbp-28h] BYREF
  __int64 v34; // [xsp+30h] [xbp-20h]
  __int64 v35; // [xsp+38h] [xbp-18h]
  __int64 v36; // [xsp+40h] [xbp-10h]
  __int64 v37; // [xsp+48h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 4304);
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  if ( a3 >= 0xF )
    __break(0x5512u);
  v6 = *(_QWORD **)(a2 + 8LL * a3 + 7256);
  v32[0] = v32;
  v32[1] = v32;
  v7 = v6[67];
  v8 = v6[118];
  if ( v7 )
  {
    v9 = v6[68];
    v10 = v6[69];
    v11 = v6[70];
    v31 = v3;
    *(_BYTE *)(v8 + 830) = 0;
    *(_BYTE *)(v8 + 840) = 0;
    ieee80211_vif_unblock_queues_csa(a2 + 2688);
    v12 = v6[71];
    if ( v12 )
    {
      kfree(*(_QWORD *)(v12 + 72));
      kfree(*(_QWORD *)(v6[71] + 80LL));
      kfree(v6[71]);
      v6[71] = 0;
    }
    for ( i = *(_QWORD **)(a2 + 4952); i != (_QWORD *)(a2 + 4952); i = (_QWORD *)*i )
      netif_carrier_off(*(i - 82));
    if ( (unsigned __int8)ieee80211_num_beaconing_links(a2 + 2688) <= 1u )
    {
      netif_carrier_off(a2);
      *(_BYTE *)(a2 + 5269) = 0;
    }
    v6[67] = 0;
    v6[68] = 0;
    v6[69] = 0;
    v6[70] = 0;
    kvfree_call_rcu(v7 + 56, v7);
    if ( v9 )
      kvfree_call_rcu(v9, v9);
    if ( v10 )
      kvfree_call_rcu(v10, v10);
    if ( v11 )
      kvfree_call_rcu(v11, v11);
    kfree(*(_QWORD *)(v8 + 296));
    *(_QWORD *)(v8 + 296) = 0;
    *(_QWORD *)(a2 + 8576) = 0;
    *(_WORD *)(v8 + 311) = 0;
    *(_BYTE *)(v8 + 304) = 0;
    *(_BYTE *)(v8 + 313) = 0;
    _sta_info_flush(a2 + 2688, 1, a3);
    v14 = ieee80211_remove_link_keys(v6, v32);
    if ( (_QWORD *)v32[0] != v32 )
    {
      synchronize_net(v14);
      ieee80211_free_key_list(v31, v32);
    }
    *(_BYTE *)(v8 + 48) = 0;
    *(_BYTE *)(a2 + 4944) = 0;
    *(_QWORD *)(a2 + 7480) = 0;
    _X8 = (unsigned __int64 *)(a2 + 4320);
    __asm { PRFM            #0x11, [X8] }
    do
      v28 = __ldxr(_X8);
    while ( __stxr(v28 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    ieee80211_link_info_change_notify(a2 + 2688, v6, 512);
    if ( *(_BYTE *)(a2 + 72LL * a3 + 3144) == 1 )
    {
      v15 = *(_QWORD *)(v8 + 144);
      v33 = *(_QWORD *)(v8 + 136);
      v34 = v15;
      v16 = *(_QWORD *)(v8 + 160);
      v35 = *(_QWORD *)(v8 + 152);
      v36 = v16;
      wiphy_delayed_work_cancel(a1, v6 + 58);
      cfg80211_cac_event(*(_QWORD *)(a2 + 4296), &v33, 2, 3264, a3);
    }
    v17 = *(_QWORD *)(a2 + 4304);
    if ( (*(_BYTE *)(v17 + 1471) & 1) == 0
      && (*(_DWORD *)(a2 + 4312) & 0x20) == 0
      && (drv_stop_ap___already_done & 1) == 0 )
    {
      v20 = *(_QWORD *)(a2 + 4296);
      drv_stop_ap___already_done = 1;
      if ( v20 )
        v21 = v20 + 296;
      else
        v21 = a2 + 4328;
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v21);
      __break(0x800u);
    }
    if ( (*(_BYTE *)(a2 + 4312) & 0x20) != 0 )
    {
      v18 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v17 + 464) + 112LL);
      if ( v18 )
      {
        if ( *((_DWORD *)v18 - 1) != -224849985 )
          __break(0x8228u);
        v18(v17, a2 + 7408, v8);
      }
    }
    *(_DWORD *)(v31 + 5000) -= *(_DWORD *)(a2 + 5240);
    ieee80211_purge_tx_queue(v31, a2 + 5224);
    ieee80211_link_copy_chanctx_to_vlans(v6, 1);
    ieee80211_link_release_channel(v6);
    result = 0;
  }
  else
  {
    result = 4294967294LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
