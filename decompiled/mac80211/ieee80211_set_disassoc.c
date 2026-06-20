__int64 __fastcall ieee80211_set_disassoc(__int64 result, unsigned int a2, unsigned int a3, char a4, __int64 a5)
{
  __int64 v8; // x19
  unsigned int v10; // w8
  __int64 v11; // x20
  unsigned int v12; // w9
  unsigned int v13; // w8
  __int64 v14; // x9
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x0
  __int64 v18; // x8
  int v19; // w9
  __int64 v20; // x22
  int v21; // w8
  int v22; // w9
  __int64 v23; // x1
  __int64 *v24; // x0
  __int64 *v25; // x0
  __int64 *v26; // x0
  __int64 *v27; // x0
  __int64 *v28; // x0
  __int64 *v29; // x0
  __int64 *v30; // x0
  __int64 *v31; // x0
  __int64 *v32; // x0
  __int64 *v33; // x0
  __int64 *v34; // x0
  __int64 *v35; // x0
  __int64 *v36; // x0
  __int64 *v37; // x0
  __int64 *v38; // x0
  __int64 v39; // x8
  __int64 v40; // x8
  __int64 v41; // x8
  _WORD v42[2]; // [xsp+Ch] [xbp-14h] BYREF
  char v43; // [xsp+10h] [xbp-10h]
  __int16 v44; // [xsp+11h] [xbp-Fh]
  char v45; // [xsp+13h] [xbp-Dh]
  unsigned int v46; // [xsp+14h] [xbp-Ch]
  __int64 v47; // [xsp+18h] [xbp-8h]

  v8 = result;
  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int16 *)(result + 5802);
  v11 = *(_QWORD *)(result + 1616);
  v42[0] = 0;
  v42[1] = a2;
  v43 = 2;
  v44 = 0;
  v12 = __clz(__rbit32(v10));
  v45 = 0;
  if ( v10 )
    v13 = v12 + 1;
  else
    v13 = 0;
  v46 = v13 - 1;
  if ( !a5 && (a4 & 1) != 0 || (*(_BYTE *)(result + 2477) & 8) == 0 )
  {
    __break(0x800u);
    goto LABEL_57;
  }
  *(_DWORD *)(result + 2500) &= ~2u;
  ieee80211_run_deferred_scan(v11);
  v14 = *(_QWORD *)(v8 + 4560);
  *(_BYTE *)(v8 + 2477) &= ~8u;
  *(_QWORD *)(v14 + 8) = 0;
  v15 = *(_QWORD *)(v8 + 1608);
  *(_DWORD *)(v8 + 4060) = 1;
  netif_carrier_off(v15);
  if ( (*(_DWORD *)v11 & 2) != 0 )
  {
    *(_DWORD *)v11 &= ~2u;
    ieee80211_hw_config(v11, 16);
  }
  *(_QWORD *)(v11 + 5008) = 0;
  v17 = ieee80211_recalc_ps_vif(v8, v16);
  synchronize_net(v17);
  if ( (a4 & 1) != 0 )
  {
    ieee80211_flush_queues(v11, v8, 1);
    goto LABEL_12;
  }
  if ( a5 )
  {
LABEL_12:
    drv_mgd_prepare_tx(*(_QWORD *)(v8 + 1616), v8, v42);
    ieee80211_send_deauth_disassoc(v8, v8 + 4802, v8 + 4802, a2, a3, a4 & 1, a5);
    if ( (a4 & 1) != 0 )
      ieee80211_flush_queues(v11, v8, 0);
  }
  drv_mgd_complete_tx(*(_QWORD *)(v8 + 1616), v8, v42);
  *(_WORD *)(v8 + 4156) = 0;
  *(_DWORD *)(v8 + 4152) = 0;
  *(_DWORD *)(v8 + 4802) = 0;
  *(_WORD *)(v8 + 4806) = 0;
  *(_QWORD *)(v8 + 4792) = 0;
  _sta_info_flush(v8, 0, 0xFFFFFFFFLL);
  if ( *(_WORD *)(v8 + 5800) )
    v18 = 1;
  else
    v18 = ieee80211_reset_erp_info(v8) | 1;
  *(_BYTE *)(v8 + 4728) = 0;
  *(_WORD *)(v8 + 4176) = -1;
  *(_QWORD *)(v8 + 5044) = 0;
  *(_QWORD *)(v8 + 5052) = 0;
  *(_QWORD *)(v8 + 5060) = 0;
  *(_QWORD *)(v8 + 5068) = 0;
  *(_QWORD *)(v8 + 5076) = 0;
  *(_QWORD *)(v8 + 5084) = 0;
  *(_QWORD *)(v8 + 5090) = 0;
  *(_QWORD *)(v8 + 2562) = 0;
  *(_QWORD *)(v8 + 2570) = 0;
  *(_QWORD *)(v8 + 2578) = 0;
  *(_QWORD *)(v8 + 2588) = 0;
  v19 = *(unsigned __int16 *)(v8 + 5800);
  *(_QWORD *)(v8 + 2536) = 0;
  *(_QWORD *)(v8 + 2544) = 0;
  if ( v19 )
    v20 = v18;
  else
    v20 = v18 | 0x800000;
  *(_QWORD *)(v8 + 2552) = 0;
  *(_WORD *)(v8 + 2560) = 0;
  *(_WORD *)(v8 + 2586) = 0;
  *(_DWORD *)(v8 + 2596) = 0;
  *(_DWORD *)(v8 + 2608) = 0;
  *(_QWORD *)(v8 + 2600) = 0;
  *(_QWORD *)(v8 + 5008) = 0;
  *(_QWORD *)(v8 + 5016) = 0;
  *(_QWORD *)(v8 + 5024) = 0;
  *(_BYTE *)(v8 + 5639) = 0;
  *(_DWORD *)(v8 + 4068) = 0x80000000;
  timer_delete_sync(v11 + 5064);
  wiphy_work_cancel(*(_QWORD *)(v11 + 72), v11 + 5016);
  v21 = *(_DWORD *)(v8 + 4756);
  v22 = *(unsigned __int16 *)(v8 + 5800);
  *(_BYTE *)(v8 + 5032) = 0;
  if ( v21 )
    v23 = v20 | 0x1000;
  else
    v23 = v20;
  if ( v22 )
    ieee80211_vif_cfg_change_notify(v8, v23);
  else
    ieee80211_bss_info_change_notify(v8, v23 | 0x2090);
  ieee80211_set_wmm_default(v8 + 3616, 0, 0);
  timer_delete_sync(v8 + 2304);
  timer_delete_sync(v8 + 2344);
  timer_delete_sync(v8 + 2264);
  v24 = *(__int64 **)(v8 + 4568);
  *(_BYTE *)(v8 + 4857) = 0;
  *(_QWORD *)(v8 + 4888) = 0;
  *(_WORD *)(v8 + 4179) = 0;
  *(_BYTE *)(v8 + 4181) = 0;
  *(_DWORD *)(v8 + 2500) = 0;
  if ( v24 )
    ieee80211_link_release_channel(v24);
  v25 = *(__int64 **)(v8 + 4576);
  if ( v25 )
    ieee80211_link_release_channel(v25);
  v26 = *(__int64 **)(v8 + 4584);
  if ( v26 )
    ieee80211_link_release_channel(v26);
  v27 = *(__int64 **)(v8 + 4592);
  if ( v27 )
    ieee80211_link_release_channel(v27);
  v28 = *(__int64 **)(v8 + 4600);
  if ( v28 )
    ieee80211_link_release_channel(v28);
  v29 = *(__int64 **)(v8 + 4608);
  if ( v29 )
    ieee80211_link_release_channel(v29);
  v30 = *(__int64 **)(v8 + 4616);
  if ( v30 )
    ieee80211_link_release_channel(v30);
  v31 = *(__int64 **)(v8 + 4624);
  if ( v31 )
    ieee80211_link_release_channel(v31);
  v32 = *(__int64 **)(v8 + 4632);
  if ( v32 )
    ieee80211_link_release_channel(v32);
  v33 = *(__int64 **)(v8 + 4640);
  if ( v33 )
    ieee80211_link_release_channel(v33);
  v34 = *(__int64 **)(v8 + 4648);
  if ( v34 )
    ieee80211_link_release_channel(v34);
  v35 = *(__int64 **)(v8 + 4656);
  if ( v35 )
    ieee80211_link_release_channel(v35);
  v36 = *(__int64 **)(v8 + 4664);
  if ( v36 )
    ieee80211_link_release_channel(v36);
  v37 = *(__int64 **)(v8 + 4672);
  if ( v37 )
    ieee80211_link_release_channel(v37);
  v38 = *(__int64 **)(v8 + 4680);
  if ( v38 )
    ieee80211_link_release_channel(v38);
  *(_BYTE *)(v8 + 5638) = 0;
  *(_BYTE *)(v8 + 4402) = 0;
  *(_WORD *)(v8 + 4400) = 0;
  ieee80211_vif_unblock_queues_csa(v8);
  *(_QWORD *)(v8 + 2864) = 0;
  *(_QWORD *)(v8 + 2856) = 0;
  *(_QWORD *)(v8 + 2848) = 0;
  *(_QWORD *)(v8 + 2840) = 0;
  *(_QWORD *)(v8 + 2832) = 0;
  *(_QWORD *)(v8 + 2824) = 0;
  *(_QWORD *)(v8 + 2816) = 0;
  *(_QWORD *)(v8 + 2808) = 0;
  *(_QWORD *)(v8 + 2800) = 0;
  *(_QWORD *)(v8 + 2792) = 0;
  *(_QWORD *)(v8 + 2784) = 0;
  *(_QWORD *)(v8 + 2776) = 0;
  *(_QWORD *)(v8 + 2768) = 0;
  *(_QWORD *)(v8 + 2760) = 0;
  *(_QWORD *)(v8 + 2752) = 0;
  *(_QWORD *)(v8 + 2744) = 0;
  wiphy_delayed_work_cancel(*(_QWORD *)(v11 + 72), v8 + 2872);
  *(_DWORD *)(v8 + 5528) = 0;
  *(_BYTE *)(v8 + 5636) = 0;
  ieee80211_clear_tpe(v8 + 5532);
  *(_WORD *)(v8 + 4738) = 0;
  *(_DWORD *)(v8 + 4734) = 0;
  v39 = *(_QWORD *)(v8 + 1616);
  *(_QWORD *)(v8 + 3112) = 0;
  *(_DWORD *)(v8 + 3120) = 0;
  wiphy_delayed_work_cancel(*(_QWORD *)(v39 + 72), v8 + 3040);
  v40 = *(_QWORD *)(v8 + 1616);
  *(_WORD *)(v8 + 5840) = 0;
  *(_QWORD *)(v8 + 5832) = 0;
  *(_QWORD *)(v8 + 5824) = 0;
  *(_QWORD *)(v8 + 5816) = 0;
  *(_QWORD *)(v8 + 5808) = 0;
  wiphy_delayed_work_cancel(*(_QWORD *)(v40 + 72), v8 + 3160);
  v41 = *(_QWORD *)(v8 + 1616);
  *(_WORD *)(v8 + 3032) = 0;
  wiphy_delayed_work_cancel(*(_QWORD *)(v41 + 72), v8 + 2960);
  wiphy_work_cancel(*(_QWORD *)(*(_QWORD *)(v8 + 1616) + 72LL), v8 + 3128);
  result = ieee80211_vif_set_links((unsigned __int16 *)v8, 0, 0);
  *(_WORD *)(v8 + 2504) = 4096;
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return result;
}
