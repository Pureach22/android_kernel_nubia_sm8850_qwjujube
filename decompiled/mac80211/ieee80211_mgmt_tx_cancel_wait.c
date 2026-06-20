__int64 __fastcall ieee80211_mgmt_tx_cancel_wait(__int64 a1, __int64 a2, __int64 a3)
{
  if ( a1 )
    return ieee80211_cancel_roc(a1 + 1536, a3, 1);
  __break(0x800u);
  return ieee80211_roc_setup(0);
}
