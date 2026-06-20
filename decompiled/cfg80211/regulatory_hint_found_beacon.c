void __fastcall regulatory_hint_found_beacon(__int64 a1, __int64 a2, int a3)
{
  int v5; // w21
  _DWORD *v6; // x8
  __int64 v7; // x8
  __int64 v8; // x20
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 *v13; // x1

  if ( (*(_BYTE *)(a2 + 28) & 1) == 0 && (*(_BYTE *)(a2 + 12) & 8) == 0 )
  {
    if ( *(_DWORD *)a2
      || (v5 = *(_DWORD *)(a2 + 4), (unsigned int)ieee80211_channel_to_freq_khz(12, 0) / 0x3E8 == v5)
      || (unsigned int)ieee80211_channel_to_freq_khz(13, 0) / 0x3E8 == v5
      || (unsigned int)ieee80211_channel_to_freq_khz(14, 0) / 0x3E8 == v5 )
    {
      raw_spin_lock_bh(&reg_pending_beacons_lock);
      v6 = reg_pending_beacons;
      if ( reg_pending_beacons == (_UNKNOWN *)&reg_pending_beacons )
      {
LABEL_13:
        raw_spin_unlock_bh(&reg_pending_beacons_lock);
        v7 = 1;
        if ( (a3 & 0x10) == 0 )
          v7 = 2;
        if ( (a3 & 0x400010) == 0 )
          v7 = 0;
        v8 = _kmalloc_cache_noprof(kmalloc_caches[14 * v7 + 1], a3 | 0x100u, 80);
        if ( v8 )
        {
          v9 = *(_QWORD *)(a2 + 40);
          *(_QWORD *)(v8 + 48) = *(_QWORD *)(a2 + 32);
          *(_QWORD *)(v8 + 56) = v9;
          v10 = *(_QWORD *)(a2 + 56);
          *(_QWORD *)(v8 + 64) = *(_QWORD *)(a2 + 48);
          *(_QWORD *)(v8 + 72) = v10;
          v11 = *(_QWORD *)(a2 + 8);
          *(_QWORD *)(v8 + 16) = *(_QWORD *)a2;
          *(_QWORD *)(v8 + 24) = v11;
          v12 = *(_QWORD *)(a2 + 24);
          *(_QWORD *)(v8 + 32) = *(_QWORD *)(a2 + 16);
          *(_QWORD *)(v8 + 40) = v12;
          raw_spin_lock_bh(&reg_pending_beacons_lock);
          v13 = (__int64 *)off_4DF8[0];
          if ( off_4DF8[0] == (_UNKNOWN **)v8 || *(_UNKNOWN ***)off_4DF8[0] != &reg_pending_beacons )
          {
            _list_add_valid_or_report(v8, off_4DF8[0]);
          }
          else
          {
            off_4DF8[0] = (_UNKNOWN **)v8;
            *(_QWORD *)v8 = &reg_pending_beacons;
            *(_QWORD *)(v8 + 8) = v13;
            *v13 = v8;
          }
          raw_spin_unlock_bh(&reg_pending_beacons_lock);
          queue_work_on(32, system_wq, &reg_work);
        }
      }
      else
      {
        while ( *(_DWORD *)(a2 + 4) != v6[5] || *(unsigned __int16 *)(a2 + 8) != *((unsigned __int16 *)v6 + 12) )
        {
          v6 = *(_DWORD **)v6;
          if ( v6 == (_DWORD *)&reg_pending_beacons )
            goto LABEL_13;
        }
        raw_spin_unlock_bh(&reg_pending_beacons_lock);
      }
    }
  }
}
