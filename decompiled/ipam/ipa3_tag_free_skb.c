__int64 __fastcall ipa3_tag_free_skb(__int64 a1)
{
  return dev_kfree_skb_any_reason(a1, 2);
}
