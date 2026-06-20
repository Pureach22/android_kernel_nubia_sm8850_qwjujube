__int64 __fastcall wlan_cfg80211_inform_bss_frame(__int64 a1, __int64 a2)
{
  __int64 *v2; // x8
  __int64 v3; // x21
  __int64 v5; // x0
  __int64 v6; // x20
  int v7; // w22
  char v8; // w23
  __int64 channel_khz; // x0
  __int64 v10; // x0
  __int64 result; // x0
  __int64 v12; // x24
  __int64 v13; // x22
  int v14; // w4
  int v15; // w5
  int v16; // w6
  int v17; // w7
  int v18; // w4
  int v19; // w5
  int v20; // w6
  int v21; // w7
  unsigned __int8 *v22; // x0
  __int64 v23; // [xsp+18h] [xbp-38h] BYREF
  unsigned __int8 *v24; // [xsp+20h] [xbp-30h]
  __int64 entry_frame_len; // [xsp+28h] [xbp-28h]
  __int64 v26; // [xsp+30h] [xbp-20h]
  __int64 v27; // [xsp+38h] [xbp-18h]
  _QWORD v28[2]; // [xsp+40h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 **)(a1 + 24);
  v27 = 0;
  v28[0] = 0;
  v26 = 0;
  if ( v2 )
  {
    v3 = *v2;
    entry_frame_len = (unsigned int)ucfg_scan_get_entry_frame_len(a2);
    v5 = qdf_mem_malloc_atomic_fl();
    v24 = (unsigned __int8 *)v5;
    if ( v5 )
    {
      v6 = v5;
      qdf_mem_copy(v5, *(_QWORD *)(a2 + 1896), *(unsigned int *)(a2 + 1888));
      *(_QWORD *)(v6 + 24) = ktime_get_with_offset(1) / 1000;
      v7 = *(_DWORD *)(a2 + 1192);
      v8 = *(_BYTE *)(a2 + 60);
      channel_khz = ieee80211_get_channel_khz(v3, (unsigned int)(1000 * v7));
      if ( channel_khz )
      {
        v23 = channel_khz;
        v27 = *(_QWORD *)(a2 + 1296);
        LODWORD(v26) = 100 * (v8 & (v8 >> 31));
        qdf_mem_copy((int)v28, a2 + 1288, 4u);
        v10 = wlan_cfg80211_inform_bss_frame_data(v3, &v23);
        if ( v10 )
        {
          cfg80211_put_bss(v3, v10);
        }
        else
        {
          if ( v24 == (unsigned __int8 *)-16LL )
          {
            v20 = 0;
            v18 = 0;
            v19 = 0;
            v21 = 0;
          }
          else
          {
            v18 = v24[16];
            v19 = v24[17];
            v20 = v24[18];
            v21 = v24[21];
          }
          qdf_trace_msg(
            72,
            2,
            "%s: failed to inform bss %02x:%02x:%02x:**:**:%02x seq %d",
            "wlan_cfg80211_inform_bss_frame",
            v18,
            v19,
            v20,
            v21,
            *(unsigned __int16 *)(a2 + 48));
        }
        v22 = v24;
      }
      else
      {
        v12 = jiffies;
        if ( wlan_get_ieee80211_channel___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(72, 2, "%s: chan is NULL, freq: %d", "wlan_get_ieee80211_channel", v7);
          wlan_get_ieee80211_channel___last_ticks = v12;
        }
        v13 = jiffies;
        if ( wlan_cfg80211_inform_bss_frame___last_ticks - jiffies + 125 < 0 )
        {
          if ( v6 == -16 )
          {
            v16 = 0;
            v14 = 0;
            v15 = 0;
            v17 = 0;
          }
          else
          {
            v14 = *(unsigned __int8 *)(v6 + 16);
            v15 = *(unsigned __int8 *)(v6 + 17);
            v16 = *(unsigned __int8 *)(v6 + 18);
            v17 = *(unsigned __int8 *)(v6 + 21);
          }
          qdf_trace_msg(
            72,
            2,
            "%s: Channel not found for bss %02x:%02x:%02x:**:**:%02x seq %d chan_freq %d",
            "wlan_cfg80211_inform_bss_frame",
            v14,
            v15,
            v16,
            v17,
            *(unsigned __int16 *)(a2 + 48),
            *(_DWORD *)(a2 + 1192));
          wlan_cfg80211_inform_bss_frame___last_ticks = v13;
        }
        v22 = (unsigned __int8 *)v6;
      }
      result = _qdf_mem_free(v22);
    }
    else
    {
      result = qdf_trace_msg(
                 72,
                 2,
                 "%s: bss mem alloc failed for seq %d",
                 "wlan_cfg80211_inform_bss_frame",
                 *(unsigned __int16 *)(a2 + 48));
    }
  }
  else
  {
    result = qdf_trace_msg(72, 2, "%s: os_priv is NULL", "wlan_cfg80211_inform_bss_frame");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
