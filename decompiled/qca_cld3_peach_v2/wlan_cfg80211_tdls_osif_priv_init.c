__int64 __fastcall wlan_cfg80211_tdls_osif_priv_init(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  _DWORD *v10; // x0
  _DWORD *v11; // x22

  v9 = *(_QWORD *)(a1 + 680);
  if ( v9 )
  {
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: initialize tdls os if layer private structure",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_cfg80211_tdls_osif_priv_init");
    v10 = (_DWORD *)_qdf_mem_malloc(0xF8u, "wlan_cfg80211_tdls_osif_priv_init", 72);
    if ( v10 )
    {
      *v10 = 0;
      v11 = v10;
      _init_swait_queue_head(v10 + 2, "&x->wait", &init_completion___key_3);
      v11[8] = 0;
      _init_swait_queue_head(v11 + 10, "&x->wait", &init_completion___key_3);
      v11[16] = 0;
      _init_swait_queue_head(v11 + 18, "&x->wait", &init_completion___key_3);
      v11[24] = 0;
      _init_swait_queue_head(v11 + 26, "&x->wait", &init_completion___key_3);
      v11[32] = 0;
      _init_swait_queue_head(v11 + 34, "&x->wait", &init_completion___key_3);
      v11[40] = 0;
      _init_swait_queue_head(v11 + 42, "&x->wait", &init_completion___key_3);
      v11[48] = 0;
      _init_swait_queue_head(v11 + 50, "&x->wait", &init_completion___key_3);
      *(_QWORD *)(v9 + 16) = v11;
      return 0;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: osif_priv is NULL!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_cfg80211_tdls_osif_priv_init");
    return 5;
  }
}
