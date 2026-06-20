__int64 __fastcall wlan_ipa_nbuf_cb(__int64 a1)
{
  return dev_kfree_skb_any_reason(a1, 1);
}
