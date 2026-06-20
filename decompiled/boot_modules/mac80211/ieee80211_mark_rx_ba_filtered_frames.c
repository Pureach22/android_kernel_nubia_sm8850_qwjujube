__int64 __fastcall ieee80211_mark_rx_ba_filtered_frames(
        __int64 result,
        unsigned __int8 a2,
        int a3,
        unsigned __int64 a4,
        unsigned __int16 a5)
{
  __int64 v5; // x24
  __int64 v10; // x23
  __int64 v11; // x25
  __int64 v12; // x8
  __int64 v13; // x1
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 lock; // x0
  __int64 v17; // x21
  __int16 v18; // w22
  unsigned int v19; // w11
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x10
  unsigned __int16 v22; // w12
  __int64 v23; // x11
  unsigned __int64 v24; // x9
  char v25; // w14
  unsigned __int64 v26; // x15
  __int64 v27; // x14
  __int64 v28; // x16
  _QWORD v29[2]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v30; // [xsp+18h] [xbp-68h]
  __int64 v31; // [xsp+20h] [xbp-60h]
  __int64 v32; // [xsp+28h] [xbp-58h]
  __int64 v33; // [xsp+30h] [xbp-50h]
  __int64 v34; // [xsp+38h] [xbp-48h]
  __int64 v35; // [xsp+40h] [xbp-40h]
  int v36; // [xsp+48h] [xbp-38h]
  int v37; // [xsp+4Ch] [xbp-34h]
  int v38; // [xsp+50h] [xbp-30h]
  int v39; // [xsp+54h] [xbp-2Ch]
  __int64 v40; // [xsp+58h] [xbp-28h]
  __int64 *v41[2]; // [xsp+60h] [xbp-20h] BYREF
  __int64 v42; // [xsp+70h] [xbp-10h]
  __int64 v43; // [xsp+78h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v36 = 0;
  v39 = 0;
  v40 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v29[0] = 0;
  v29[1] = 0;
  v37 = a2;
  v38 = a2;
  if ( result && a2 < 0x10u )
  {
    v5 = result - 2608;
    v10 = result;
    v11 = result - 2688;
    v12 = *(_QWORD *)(*(_QWORD *)(result - 2608) + 1616LL);
    v41[0] = (__int64 *)v41;
    v41[1] = (__int64 *)v41;
    LODWORD(v42) = 0;
    v13 = *(unsigned __int16 *)(v12 + 136);
    if ( (unsigned int)v13 >= 0x41 && (ieee80211_mark_rx_ba_filtered_frames___already_done & 1) == 0 )
    {
      ieee80211_mark_rx_ba_filtered_frames___already_done = 1;
      result = _warn_printk("RX BA marker can't support max_rx_aggregation_subframes %u > 64\n", v13);
      __break(0x800u);
    }
    v33 = v11;
    v39 = -1;
    if ( v11 )
    {
      v14 = *(_QWORD *)v5;
      v30 = *(_QWORD *)(*(_QWORD *)v5 + 1616LL);
      v31 = v14;
      v15 = v10 - 1048;
    }
    else
    {
      v14 = 0;
      v15 = 0;
    }
    v34 = v15;
    v32 = v14 + 3616;
    lock = _rcu_read_lock(result, v13);
    v17 = *(_QWORD *)(v10 + 8LL * a2 - 1992);
    if ( v17 )
    {
      raw_spin_lock_bh(v17 + 16);
      if ( a5 < 0x800u )
      {
        v19 = (*(unsigned __int16 *)(v17 + 144) - a3) & 0xFFF;
        if ( v19 >= 0x801 )
        {
          do
          {
            ieee80211_release_reorder_frame(v17);
            v19 = (*(unsigned __int16 *)(v17 + 144) - (unsigned __int16)a3) & 0xFFF;
          }
          while ( v19 > 0x800 );
        }
      }
      else
      {
        if ( (-*(_WORD *)(v17 + 150) & 0xFFFu) >= 0x801 )
        {
          v18 = *(_WORD *)(v17 + 150) + *(_WORD *)(v17 + 144);
          do
            ieee80211_release_reorder_frame(v17);
          while ( ((*(_WORD *)(v17 + 144) - v18) & 0xFFFu) > 0x800 );
        }
        v19 = 0;
        *(_WORD *)(v17 + 144) = a3;
      }
      v20 = *(unsigned __int16 *)(v17 + 150);
      if ( v19 >= (unsigned int)v20 )
      {
        *(_QWORD *)(v17 + 24) = 0;
      }
      else
      {
        if ( *(_WORD *)(v17 + 150) )
        {
          v21 = a4 >> v19;
          v22 = v19 + a3;
          v23 = *(_QWORD *)(v17 + 24);
          v24 = 0;
          do
          {
            v25 = (v22 + (unsigned int)v24) % (unsigned int)v20;
            v26 = v21 >> v24++;
            v27 = 1LL << v25;
            v28 = v23 & ~v27;
            v23 |= v27;
            if ( (v26 & 1) == 0 )
              v23 = v28;
          }
          while ( v24 < v20 );
          *(_QWORD *)(v17 + 24) = v23;
        }
        ieee80211_sta_reorder_release(v17);
      }
      raw_spin_unlock_bh(v17 + 16);
      lock = ieee80211_rx_handlers((__int64)v29, v41);
    }
    result = _rcu_read_unlock(lock);
  }
  else
  {
    __break(0x800u);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
