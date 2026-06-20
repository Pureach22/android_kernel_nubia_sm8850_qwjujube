__int64 __fastcall ieee80211_del_tx_ts(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 v5; // x8
  __int64 v6; // x21

  if ( a1 )
  {
    if ( *(_DWORD *)(a2 + 5440) && *(unsigned __int8 *)(a2 + 5444) == a3 )
    {
      v5 = 5432;
LABEL_14:
      v6 = a2 + v5;
      *(_BYTE *)(a2 + v5 + 13) = -1;
      synchronize_net(a1);
      ieee80211_flush_queues(a1 + 1536, a2 + 2688, 0);
      *(_BYTE *)(v6 + 24) = 0;
      *(_DWORD *)(v6 + 20) = 2;
      ieee80211_sta_handle_tspec_ac_params(a2 + 2688);
      *(_QWORD *)(v6 + 16) = 0;
      *(_QWORD *)(v6 + 24) = 0;
      *(_QWORD *)v6 = 0;
      *(_QWORD *)(v6 + 8) = 0;
      return 0;
    }
    if ( *(_DWORD *)(a2 + 5472) && *(unsigned __int8 *)(a2 + 5476) == a3 )
    {
      v5 = 5464;
      goto LABEL_14;
    }
    if ( *(_DWORD *)(a2 + 5504) && *(unsigned __int8 *)(a2 + 5508) == a3 )
    {
      v5 = 5496;
      goto LABEL_14;
    }
    if ( *(_DWORD *)(a2 + 5536) && *(unsigned __int8 *)(a2 + 5540) == a3 )
    {
      v5 = 5528;
      goto LABEL_14;
    }
    return 4294967294LL;
  }
  else
  {
    __break(0x800u);
    if ( a2 )
      JUMPOUT(0x1026DC);
    return ieee80211_start_nan();
  }
}
