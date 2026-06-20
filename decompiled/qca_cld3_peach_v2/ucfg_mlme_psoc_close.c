__int64 __fastcall ucfg_mlme_psoc_close(__int64 a1)
{
  return wlan_mlme_psoc_flush_peer_trans_history(a1);
}
