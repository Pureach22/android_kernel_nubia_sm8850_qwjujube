__int64 __fastcall osif_get_chan_bss_from_kernel(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  __int64 v6; // x23
  __int64 channel_khz; // x0
  __int64 v8; // x24
  __int64 result; // x0
  int v10; // w8
  int v11; // w9
  int v12; // w10
  int v13; // w11

  v6 = ***(_QWORD ***)(a1 + 680);
  channel_khz = ieee80211_get_channel_khz(v6, 1000 * (unsigned int)*((unsigned __int16 *)a2 + 5));
  if ( !channel_khz )
  {
    qdf_trace_msg(
      72,
      2,
      "%s: Invalid partner channel %d",
      "osif_get_chan_bss_from_kernel",
      *((unsigned __int16 *)a2 + 5));
    return 0;
  }
  v8 = channel_khz;
  result = wlan_cfg80211_get_bss(v6, channel_khz, a2, a3 + 15, *(unsigned __int8 *)(a3 + 14));
  if ( !result )
  {
    result = wlan_cfg80211_get_bss(v6, v8, a2, 0, 0);
    if ( !result )
    {
      if ( a2 )
      {
        v10 = *a2;
        v11 = a2[1];
        v12 = a2[2];
        v13 = a2[5];
      }
      else
      {
        v12 = 0;
        v10 = 0;
        v11 = 0;
        v13 = 0;
      }
      qdf_trace_msg(
        72,
        2,
        "%s: Vdev %d: Bss not found, link %d freq %d ssid:%.*s and MAC %02x:%02x:%02x:**:**:%02x",
        "osif_get_chan_bss_from_kernel",
        *(unsigned __int8 *)(a1 + 168),
        a2[6],
        *((unsigned __int16 *)a2 + 5),
        *(unsigned __int8 *)(a3 + 14),
        (const char *)(a3 + 15),
        v10,
        v11,
        v12,
        v13);
      return 0;
    }
  }
  return result;
}
