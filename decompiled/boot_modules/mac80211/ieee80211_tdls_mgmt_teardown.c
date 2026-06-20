__int64 __fastcall ieee80211_tdls_mgmt_teardown(
        __int64 a1,
        const void *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v9; // x19
  unsigned int vif_queues; // w0
  __int64 v19; // x0
  __int64 v20; // x1
  __int64 v21; // x3
  unsigned __int64 v22; // x0
  unsigned int v23; // w0
  unsigned __int64 v31; // x10

  v9 = *(_QWORD *)(a1 + 4304);
  vif_queues = ieee80211_get_vif_queues(v9, a1 + 2688);
  ieee80211_stop_queues_by_reason(v9, vif_queues, 8, 1);
  ieee80211_flush_queues(v9, a1 + 2688, 0);
  v19 = ieee80211_tdls_prep_mgmt_packet(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (v19 & 0x80000000) != 0 )
    v19 = printk(&unk_B98F6, a1 + 4328, (unsigned int)v19, v21);
  _rcu_read_lock(v19, v20);
  v22 = sta_info_get(a1 + 2688, a2);
  if ( v22 )
  {
    _X8 = (unsigned __int64 *)(v22 + 216);
    __asm { PRFM            #0x11, [X8] }
    do
      v31 = __ldxr(_X8);
    while ( __stxr(v31 & 0xFFFFFFFFFFFFEFFFLL, _X8) );
  }
  _rcu_read_unlock(v22);
  v23 = ieee80211_get_vif_queues(v9, a1 + 2688);
  return ieee80211_wake_queues_by_reason(v9, v23, 8, 1);
}
