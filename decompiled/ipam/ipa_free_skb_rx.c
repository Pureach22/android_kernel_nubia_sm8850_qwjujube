__int64 __fastcall ipa_free_skb_rx(__int64 a1)
{
  return dev_kfree_skb_any_reason(a1, 2);
}
